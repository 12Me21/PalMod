#include "StdAfx.h"
#include "GameDef.h"
#include "Game_RBFFS_A.h"
#include "..\PalMod.h"
#include "..\RegProc.h"

stExtraDef* CGame_RBFFS_A::RBFFS_A_EXTRA_CUSTOM = nullptr;

CDescTree CGame_RBFFS_A::MainDescTree = nullptr;

uint32_t CGame_RBFFS_A::rgExtraCountAll[RBFFS_A_NUMUNIT + 1];
uint32_t CGame_RBFFS_A::rgExtraLoc[RBFFS_A_NUMUNIT + 1];

uint32_t CGame_RBFFS_A::m_nTotalPaletteCountForRBFFS = 0;
uint32_t CGame_RBFFS_A::m_nExpectedGameROMSize = 0x100000;
uint32_t CGame_RBFFS_A::m_nConfirmedROMSize = -1;

void CGame_RBFFS_A::InitializeStatics()
{
    safe_delete_array(CGame_RBFFS_A::RBFFS_A_EXTRA_CUSTOM);

    memset(rgExtraCountAll, -1, sizeof(rgExtraCountAll));
    memset(rgExtraLoc, -1, sizeof(rgExtraLoc));

    MainDescTree.SetRootTree(CGame_RBFFS_A::InitDescTree());
}

CGame_RBFFS_A::CGame_RBFFS_A(uint32_t nConfirmedROMSize)
{
    OutputDebugString(L"CGame_RBFFS_A::CGame_RBFFS_A: Loading ROM...\n");

    createPalOptions = { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_16 };
    SetAlphaMode(AlphaMode::GameDoesNotUseAlpha);
    SetColorMode(ColMode::COLMODE_RGB666_NEOGEO);

    // We need this set before we initialize so that corrupt Extras truncate correctly.
    // Otherwise the new user inadvertently corrupts their ROM.
    m_nConfirmedROMSize = nConfirmedROMSize;
    InitializeStatics();

    m_nTotalInternalUnits = RBFFS_A_NUMUNIT;
    m_nExtraUnit = RBFFS_A_EXTRALOC;

    m_nSafeCountForThisRom = GetExtraCt(m_nExtraUnit) + 808;
    m_pszExtraFilename = EXTRA_FILENAME_RBFFS_A;
    m_nTotalPaletteCount = m_nTotalPaletteCountForRBFFS;
    // This magic number is used to warn users if their Extra file is trying to write somewhere potentially unusual
    m_nLowestKnownPaletteRomLocation = 0xd2000;

    nUnitAmt = m_nTotalInternalUnits + (GetExtraCt(m_nExtraUnit) ? 1 : 0);

    InitDataBuffer();

    //Set game information
    nGameFlag = RBFFS_A;
    nImgGameFlag = IMGDAT_SECTION_KOF;
    m_prgGameImageSet = RBFFS_A_IMGIDS_USED;

    nFileAmt = 1;

    //Set the image out display type
    DisplayType = eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT;
    // Button labels are used for the Export Image dialog
    pButtonLabelSet = DEF_BUTTONLABEL_2;

    //Create the redirect buffer
    rgUnitRedir = new uint32_t[nUnitAmt + 1];
    memset(rgUnitRedir, NULL, sizeof(uint32_t) * nUnitAmt);

    //Create the file changed flag
    PrepChangeTrackingArray();
}

CGame_RBFFS_A::~CGame_RBFFS_A()
{
    safe_delete_array(CGame_RBFFS_A::RBFFS_A_EXTRA_CUSTOM);
    ClearDataBuffer();
    //Get rid of the file changed flag
    FlushChangeTrackingArray();
}

CDescTree* CGame_RBFFS_A::GetMainTree()
{
    return &CGame_RBFFS_A::MainDescTree;
}

uint32_t CGame_RBFFS_A::GetKnownCRC32DatasetsForGame(const sCRC32ValueSet** ppKnownROMSet, bool* pfNeedToValidateCRCs)
{
    static sCRC32ValueSet knownROMs[] =
    {
        { L"Real Bout Fatal Fury Special (Neo-Geo)", L"223-p1.p1", 0xf84a2d1d, 0 },
        { L"Real Bout Fatal Fury Special (Neo-Geo Korea)", L"223-p1k.p1", 0xb78c8391, 0 },
    };

    if (ppKnownROMSet != nullptr)
    {
        *ppKnownROMSet = knownROMs;
    }

    if (pfNeedToValidateCRCs)
    {
        // Each filename is associated with a single CRC
        *pfNeedToValidateCRCs = false;
    }

    return ARRAYSIZE(knownROMs);
}

uint32_t CGame_RBFFS_A::GetExtraCt(uint32_t nUnitId, BOOL fCountVisibleOnly)
{
    return _GetExtraCount(rgExtraCountAll, RBFFS_A_NUMUNIT, nUnitId, RBFFS_A_EXTRA_CUSTOM);
}

uint32_t CGame_RBFFS_A::GetExtraLoc(uint32_t nUnitId)
{
    return _GetExtraLocation(rgExtraLoc, RBFFS_A_NUMUNIT, nUnitId, RBFFS_A_EXTRA_CUSTOM);
}

sDescTreeNode* CGame_RBFFS_A::InitDescTree()
{
    //Load extra file if we're using it
    LoadExtraFileForGame(EXTRA_FILENAME_RBFFS_A, &RBFFS_A_EXTRA_CUSTOM, RBFFS_A_EXTRALOC, m_nConfirmedROMSize);

    uint16_t nUnitCt = RBFFS_A_NUMUNIT + (GetExtraCt(RBFFS_A_EXTRALOC) ? 1 : 0);
    
    sDescTreeNode* NewDescTree = new sDescTreeNode;

    //Create the main character tree
    _snwprintf_s(NewDescTree->szDesc, ARRAYSIZE(NewDescTree->szDesc), _TRUNCATE, L"%s", g_GameFriendlyName[RBFFS_A]);
    NewDescTree->ChildNodes = new sDescTreeNode[nUnitCt];
    NewDescTree->uChildAmt = nUnitCt;
    //All units have tree children
    NewDescTree->uChildType = DESC_NODETYPE_TREE;

    m_nTotalPaletteCountForRBFFS = _InitDescTree(NewDescTree,
        RBFFS_A_UNITS,
        RBFFS_A_EXTRALOC,
        RBFFS_A_NUMUNIT,
        rgExtraCountAll,
        rgExtraLoc,
        RBFFS_A_EXTRA_CUSTOM
    );

    // debug
    //DumpPaletteHeaders();

    return NewDescTree;
}

void CGame_RBFFS_A::DumpPaletteHeaders()
{
    CString strOutput;
    const uint32_t RBFFS_PALETTE_LENGTH = 0x20;

    LPCWSTR rgCharacters[] = {
                                L"Terry",
                                L"Andy",
                                L"Joe",
                                L"Mai",
                                L"Franco",
                                L"Hon Fu",
                                L"Bob",
                                L"Blue Mary",
                                L"Sokaku",
                                L"Geese",
                                L"Yamazaki",
                                L"Chonrei",
                                L"Chonshu",
                                L"Duck King",
                                L"Kim",
                                L"Billy",
                                L"Cheng",
                                L"Tung",
                                L"Laurence",
                                L"Krauser"
    };

    const uint32_t k_nBasePalette = 0xd2000;
    uint32_t nCurrentPalettePosition = k_nBasePalette;

    for (uint16_t nCharIndex = 0; nCharIndex < ARRAYSIZE(rgCharacters); nCharIndex++)
    {
        wchar_t szCodeDesc[MAX_DESCRIPTION_LENGTH];
        StruprRemoveNonASCII(szCodeDesc, ARRAYSIZE(szCodeDesc), rgCharacters[nCharIndex]);

        // Status effects
        for (uint16_t nStatusIndex = 0; nStatusIndex < 32; nStatusIndex++)
        {
            CString strPaletteName;

            if ((nStatusIndex == 0) || (nStatusIndex == 16))
            {
                strOutput.Format(L"const sGame_PaletteDataset RBFFS_A_%s_PALETTES_%s[] = \r\n{\r\n", szCodeDesc, (nStatusIndex < 10) ? L"P1" : L"P2");
                OutputDebugString(strOutput);
            }

            uint32_t nAdjustedIndex = (nStatusIndex > 15) ? (nStatusIndex - 16) : nStatusIndex;

            switch (nAdjustedIndex)
            {
            case 0:
                strPaletteName = L"Main Palette";
                break;
            case 1:
                strPaletteName = L"Background Palette";
                break;
            case 12:
                strPaletteName = L"Burn Palette";
                break;
            case 13:
                strPaletteName = L"Blue Burn Palette";
                break;
            case 14:
                strPaletteName = L"Electricity Palette";
                break;
            default:
                strPaletteName.Format(L"Extra Palette %u", nAdjustedIndex);
                break;
            }

            strOutput.Format(L"    { L\"%s\", 0x%x, 0x%x },\r\n", strPaletteName.GetString(), nCurrentPalettePosition, nCurrentPalettePosition + RBFFS_PALETTE_LENGTH);
            OutputDebugString(strOutput);
            nCurrentPalettePosition += RBFFS_PALETTE_LENGTH;

            if ((nStatusIndex == 15) || (nStatusIndex == 31))
            {
                strOutput.Format(L"};\r\n\r\n");
                OutputDebugString(strOutput);
            }
        }
    }

    for (uint16_t nCharIndex = 0; nCharIndex < ARRAYSIZE(rgCharacters); nCharIndex++)
    {
        wchar_t szCodeDesc[MAX_DESCRIPTION_LENGTH];
        StruprRemoveNonASCII(szCodeDesc, ARRAYSIZE(szCodeDesc), rgCharacters[nCharIndex]);

        strOutput.Format(L"const sDescTreeNode RBFFS_A_%s_COLLECTION[] = \r\n{\r\n", szCodeDesc);
        OutputDebugString(strOutput);
        strOutput.Format(L"    { L\"P1\", DESC_NODETYPE_TREE, (void*)RBFFS_A_%s_PALETTES_P1, ARRAYSIZE(RBFFS_A_%s_PALETTES_P1) },\r\n", szCodeDesc, szCodeDesc);
        OutputDebugString(strOutput);
        strOutput.Format(L"    { L\"P2\", DESC_NODETYPE_TREE, (void*)RBFFS_A_%s_PALETTES_P2, ARRAYSIZE(RBFFS_A_%s_PALETTES_P2) },\r\n", szCodeDesc, szCodeDesc);
        OutputDebugString(strOutput);
        strOutput.Format(L"    { L\"Lifebar Portraits\", DESC_NODETYPE_TREE, (void*)RBFFS_A_%s_PALETTES_LIFEBAR, ARRAYSIZE(RBFFS_A_%s_PALETTES_LIFEBAR) },\r\n", szCodeDesc, szCodeDesc);
        OutputDebugString(strOutput);
        strOutput.Format(L"};\r\n\r\n");
        OutputDebugString(strOutput);
    }

    strOutput.Format(L"const sDescTreeNode RBFFS_A_UNITS[] = \r\n{\r\n");
    OutputDebugString(strOutput);

    for (uint16_t nCharIndex = 0; nCharIndex < ARRAYSIZE(rgCharacters); nCharIndex++)
    {
        wchar_t szCodeDesc[MAX_DESCRIPTION_LENGTH];
        StruprRemoveNonASCII(szCodeDesc, ARRAYSIZE(szCodeDesc), rgCharacters[nCharIndex]);

        strOutput.Format(L"    { L\"%s\", DESC_NODETYPE_TREE, (void*)RBFFS_A_%s_COLLECTION, ARRAYSIZE(RBFFS_A_%s_COLLECTION) },\r\n", rgCharacters[nCharIndex], szCodeDesc, szCodeDesc);
        OutputDebugString(strOutput);
    }

    strOutput.Format(L"};\r\n\r\n");
    OutputDebugString(strOutput);
}

sFileRule CGame_RBFFS_A::GetRule(uint32_t nUnitId)
{
    sFileRule NewFileRule;

    // This value is only used for directory-based games
    _snwprintf_s(NewFileRule.szFileName, ARRAYSIZE(NewFileRule.szFileName), _TRUNCATE, L"223-p1.p1");

    NewFileRule.uUnitId = 0;
    NewFileRule.uVerifyVar = m_nExpectedGameROMSize;

    return NewFileRule;
}

uint32_t CGame_RBFFS_A::GetCollectionCountForUnit(uint32_t nUnitId)
{
    return _GetCollectionCountForUnit(RBFFS_A_UNITS, rgExtraCountAll, RBFFS_A_NUMUNIT, RBFFS_A_EXTRALOC, nUnitId, RBFFS_A_EXTRA_CUSTOM);
}

uint32_t CGame_RBFFS_A::GetNodeCountForCollection(uint32_t nUnitId, uint32_t nCollectionId)
{
    return _GetNodeCountForCollection(RBFFS_A_UNITS, rgExtraCountAll, RBFFS_A_NUMUNIT, RBFFS_A_EXTRALOC, nUnitId, nCollectionId, RBFFS_A_EXTRA_CUSTOM);
}

LPCWSTR CGame_RBFFS_A::GetDescriptionForCollection(uint32_t nUnitId, uint32_t nCollectionId)
{
    return _GetDescriptionForCollection(RBFFS_A_UNITS, RBFFS_A_EXTRALOC, nUnitId, nCollectionId);
}

uint32_t CGame_RBFFS_A::GetPaletteCountForUnit(uint32_t nUnitId)
{
    return _GetPaletteCountForUnit(RBFFS_A_UNITS, rgExtraCountAll, RBFFS_A_NUMUNIT, RBFFS_A_EXTRALOC, nUnitId, RBFFS_A_EXTRA_CUSTOM);
}

const sGame_PaletteDataset* CGame_RBFFS_A::GetPaletteSet(uint32_t nUnitId, uint32_t nCollectionId)
{
    return _GetPaletteSet(RBFFS_A_UNITS, nUnitId, nCollectionId);
}

const sDescTreeNode* CGame_RBFFS_A::GetNodeFromPaletteId(uint32_t nUnitId, uint32_t nPaletteId, bool fReturnBasicNodesOnly)
{
    return _GetNodeFromPaletteId(RBFFS_A_UNITS, rgExtraCountAll, RBFFS_A_NUMUNIT, RBFFS_A_EXTRALOC, nUnitId, nPaletteId, RBFFS_A_EXTRA_CUSTOM, fReturnBasicNodesOnly);
}

const sGame_PaletteDataset* CGame_RBFFS_A::GetSpecificPalette(uint32_t nUnitId, uint32_t nPaletteId)
{
    return _GetSpecificPalette(RBFFS_A_UNITS, rgExtraCountAll, RBFFS_A_NUMUNIT, RBFFS_A_EXTRALOC, nUnitId, nPaletteId, RBFFS_A_EXTRA_CUSTOM);
}

void CGame_RBFFS_A::LoadSpecificPaletteData(uint32_t nUnitId, uint32_t nPalId)
{
     if (nUnitId != RBFFS_A_EXTRALOC)
    {
        int cbPaletteSizeOnDisc = 0;
        const sGame_PaletteDataset* paletteData = GetSpecificPalette(nUnitId, nPalId);

        if (paletteData)
        {
            cbPaletteSizeOnDisc = (int)max(0, (paletteData->nPaletteOffsetEnd - paletteData->nPaletteOffset));

            m_nCurrentPaletteROMLocation = paletteData->nPaletteOffset;
            m_nCurrentPaletteSizeInColors = cbPaletteSizeOnDisc / m_nSizeOfColorsInBytes;
            m_pszCurrentPaletteName = paletteData->szPaletteName;
        }
        else
        {
            // A bogus palette was requested: this is unrecoverable.
            DebugBreak();
        }
    }
    else // RBFFS_A_EXTRALOC
    {
        // This is where we handle all the palettes added in via Extra.
        stExtraDef* pCurrDef = GetExtraDefForRBFFS(GetExtraLoc(nUnitId) + nPalId);

        m_nCurrentPaletteROMLocation = pCurrDef->uOffset;
        m_nCurrentPaletteSizeInColors = (pCurrDef->cbPaletteSize / m_nSizeOfColorsInBytes);
        m_pszCurrentPaletteName = pCurrDef->szDesc;
    }
}

BOOL CGame_RBFFS_A::UpdatePalImg(int Node01, int Node02, int Node03, int Node04)
{
    return _UpdatePalImg(RBFFS_A_UNITS, rgExtraCountAll, RBFFS_A_NUMUNIT, RBFFS_A_EXTRALOC, RBFFS_A_EXTRA_CUSTOM, Node01, Node02, Node03, Node03);
}
