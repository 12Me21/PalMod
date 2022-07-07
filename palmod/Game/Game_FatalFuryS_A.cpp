#include "StdAfx.h"
#include "GameDef.h"
#include "Game_FatalFuryS_A.h"
#include "..\PalMod.h"
#include "..\RegProc.h"

stExtraDef* CGame_FatalFuryS_A::FatalFuryS_A_EXTRA_CUSTOM = nullptr;

CDescTree CGame_FatalFuryS_A::MainDescTree = nullptr;

uint32_t CGame_FatalFuryS_A::rgExtraCountAll[FatalFuryS_A_NUMUNIT + 1];
uint32_t CGame_FatalFuryS_A::rgExtraLoc[FatalFuryS_A_NUMUNIT + 1];

uint32_t CGame_FatalFuryS_A::m_nTotalPaletteCountForFatalFuryS = 0;
uint32_t CGame_FatalFuryS_A::m_nExpectedGameROMSize = 0x100000;
uint32_t CGame_FatalFuryS_A::m_nConfirmedROMSize = -1;

void CGame_FatalFuryS_A::InitializeStatics()
{
    safe_delete_array(CGame_FatalFuryS_A::FatalFuryS_A_EXTRA_CUSTOM);

    memset(rgExtraCountAll, -1, sizeof(rgExtraCountAll));
    memset(rgExtraLoc, -1, sizeof(rgExtraLoc));

    MainDescTree.SetRootTree(CGame_FatalFuryS_A::InitDescTree());
}

CGame_FatalFuryS_A::CGame_FatalFuryS_A(uint32_t nConfirmedROMSize)
{
    OutputDebugString(L"CGame_FatalFuryS_A::CGame_FatalFuryS_A: Loading ROM...\n");

    //Set color mode: see the definitions in GameClass.h
    createPalOptions = { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_16 };
    SetAlphaMode(AlphaMode::GameDoesNotUseAlpha);
    SetColorMode(ColMode::COLMODE_RGB666_NEOGEO);

    // We need this set before we initialize so that we can truncate bad Extras correctly.
    // Otherwise the new user could inadvertently corrupt their ROM.
    m_nConfirmedROMSize = nConfirmedROMSize;
    InitializeStatics();

    m_nTotalInternalUnits = FatalFuryS_A_NUMUNIT;
    m_nExtraUnit = FatalFuryS_A_EXTRALOC;

    m_nSafeCountForThisRom = GetExtraCt(m_nExtraUnit) + 147;
    m_pszExtraFilename = EXTRA_FILENAME_FatalFuryS_A;
    m_nTotalPaletteCount = m_nTotalPaletteCountForFatalFuryS;
    // This magic number is used to warn users if their Extra file is trying to write somewhere potentially unusual
    m_nLowestKnownPaletteRomLocation = 0x40000;

    nUnitAmt = m_nTotalInternalUnits + (GetExtraCt(m_nExtraUnit) ? 1 : 0);

    InitDataBuffer();

    nGameFlag = FatalFuryS_A;
    nImgGameFlag = IMGDAT_SECTION_KOF;
    m_prgGameImageSet = FFS_A_IMGIDS_USED;

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

CGame_FatalFuryS_A::~CGame_FatalFuryS_A(void)
{
    safe_delete_array(CGame_FatalFuryS_A::FatalFuryS_A_EXTRA_CUSTOM);
    ClearDataBuffer();
    //Get rid of the file changed flag
    FlushChangeTrackingArray();
}

sFileRule CGame_FatalFuryS_A::GetRule(uint32_t nUnitId)
{
    sFileRule NewFileRule;

    // This value is only used for directory-based games
    _snwprintf_s(NewFileRule.szFileName, ARRAYSIZE(NewFileRule.szFileName), _TRUNCATE, L"058-p1.p1"); // Update with the primary expected ROM name here.

    NewFileRule.uUnitId = 0;
    NewFileRule.uVerifyVar = m_nExpectedGameROMSize;

    return NewFileRule;
}

uint32_t CGame_FatalFuryS_A::GetKnownCRC32DatasetsForGame(const sCRC32ValueSet** ppKnownROMSet, bool* pfNeedToValidateCRCs)
{
    static sCRC32ValueSet knownROMs[] =
    {
        { L"Fatal Fury Special (Neo-Geo)", L"058-p1.p1", 0x2f585ba2, 0 },
        { L"Fatal Fury Special (Neo-Geo)", L"058-p1.bin", 0x2f585ba2, 0 },
    };

    if (ppKnownROMSet)
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

CDescTree* CGame_FatalFuryS_A::GetMainTree()
{
    return &CGame_FatalFuryS_A::MainDescTree;
}

uint32_t CGame_FatalFuryS_A::GetExtraCt(uint32_t nUnitId, BOOL fCountVisibleOnly)
{
    return _GetExtraCount(rgExtraCountAll, FatalFuryS_A_NUMUNIT, nUnitId, FatalFuryS_A_EXTRA_CUSTOM);
}

uint32_t CGame_FatalFuryS_A::GetExtraLoc(uint32_t nUnitId)
{
    return _GetExtraLocation(rgExtraLoc, FatalFuryS_A_NUMUNIT, nUnitId, FatalFuryS_A_EXTRA_CUSTOM);
}

sDescTreeNode* CGame_FatalFuryS_A::InitDescTree()
{
    //Load extra file if we're using it
    LoadExtraFileForGame(EXTRA_FILENAME_FatalFuryS_A, &FatalFuryS_A_EXTRA_CUSTOM, FatalFuryS_A_EXTRALOC, m_nConfirmedROMSize);

    uint16_t nUnitCt = FatalFuryS_A_NUMUNIT + (GetExtraCt(FatalFuryS_A_EXTRALOC) ? 1 : 0);

    sDescTreeNode* NewDescTree = new sDescTreeNode;

    //Create the main character tree
    _snwprintf_s(NewDescTree->szDesc, ARRAYSIZE(NewDescTree->szDesc), _TRUNCATE, L"%s", g_GameFriendlyName[FatalFuryS_A]);
    NewDescTree->ChildNodes = new sDescTreeNode[nUnitCt];
    NewDescTree->uChildAmt = nUnitCt;
    //All units have tree children
    NewDescTree->uChildType = DESC_NODETYPE_TREE;

    m_nTotalPaletteCountForFatalFuryS = _InitDescTree(NewDescTree,
        FatalFuryS_A_UNITS,
        FatalFuryS_A_EXTRALOC,
        FatalFuryS_A_NUMUNIT,
        rgExtraCountAll,
        rgExtraLoc,
        FatalFuryS_A_EXTRA_CUSTOM
    );

    return NewDescTree;
}

uint32_t CGame_FatalFuryS_A::GetCollectionCountForUnit(uint32_t nUnitId)
{
    return _GetCollectionCountForUnit(FatalFuryS_A_UNITS, rgExtraCountAll, FatalFuryS_A_NUMUNIT, FatalFuryS_A_EXTRALOC, nUnitId, FatalFuryS_A_EXTRA_CUSTOM);
}

uint32_t CGame_FatalFuryS_A::GetNodeCountForCollection(uint32_t nUnitId, uint32_t nCollectionId)
{
    return _GetNodeCountForCollection(FatalFuryS_A_UNITS, rgExtraCountAll, FatalFuryS_A_NUMUNIT, FatalFuryS_A_EXTRALOC, nUnitId, nCollectionId, FatalFuryS_A_EXTRA_CUSTOM);
}

LPCWSTR CGame_FatalFuryS_A::GetDescriptionForCollection(uint32_t nUnitId, uint32_t nCollectionId)
{
    return _GetDescriptionForCollection(FatalFuryS_A_UNITS, FatalFuryS_A_EXTRALOC, nUnitId, nCollectionId);
}

uint32_t CGame_FatalFuryS_A::GetPaletteCountForUnit(uint32_t nUnitId)
{
    return _GetPaletteCountForUnit(FatalFuryS_A_UNITS, rgExtraCountAll, FatalFuryS_A_NUMUNIT, FatalFuryS_A_EXTRALOC, nUnitId, FatalFuryS_A_EXTRA_CUSTOM);
}

const sGame_PaletteDataset* CGame_FatalFuryS_A::GetPaletteSet(uint32_t nUnitId, uint32_t nCollectionId)
{
    return _GetPaletteSet(FatalFuryS_A_UNITS, nUnitId, nCollectionId);
}

const sDescTreeNode* CGame_FatalFuryS_A::GetNodeFromPaletteId(uint32_t nUnitId, uint32_t nPaletteId, bool fReturnBasicNodesOnly)
{
    return _GetNodeFromPaletteId(FatalFuryS_A_UNITS, rgExtraCountAll, FatalFuryS_A_NUMUNIT, FatalFuryS_A_EXTRALOC, nUnitId, nPaletteId, FatalFuryS_A_EXTRA_CUSTOM, fReturnBasicNodesOnly);
}

const sGame_PaletteDataset* CGame_FatalFuryS_A::GetSpecificPalette(uint32_t nUnitId, uint32_t nPaletteId)
{
    return _GetSpecificPalette(FatalFuryS_A_UNITS, rgExtraCountAll, FatalFuryS_A_NUMUNIT, FatalFuryS_A_EXTRALOC, nUnitId, nPaletteId, FatalFuryS_A_EXTRA_CUSTOM);
}

void CGame_FatalFuryS_A::LoadSpecificPaletteData(uint32_t nUnitId, uint32_t nPalId)
{
    if (nUnitId != FatalFuryS_A_EXTRALOC)
    {
        int cbPaletteSizeOnDisc = 0;
        const sGame_PaletteDataset* paletteData = GetSpecificPalette(nUnitId, nPalId);

        if (paletteData)
        {
            cbPaletteSizeOnDisc = (int)max(0, (paletteData->nPaletteOffsetEnd - paletteData->nPaletteOffset));

            m_nCurrentPaletteROMLocation = paletteData->nPaletteOffset;
            m_nCurrentPaletteSizeInColors = cbPaletteSizeOnDisc / m_nSizeOfColorsInBytes;
            m_pszCurrentPaletteName = paletteData->szPaletteName;

            // Adjust for ROM-specific variant locations
            if (m_pCRC32SpecificData)
            {
                m_nCurrentPaletteROMLocation += m_pCRC32SpecificData->nROMSpecificOffset;
            }
        }
        else
        {
            // A bogus palette was requested: this is unrecoverable.
            DebugBreak();
        }
    }
    else // FatalFuryS_A_EXTRALOC
    {
        // This is where we handle all the palettes added in via Extra.
        stExtraDef* pCurrDef = GetExtraDefForFatalFuryS_A(GetExtraLoc(nUnitId) + nPalId);

        m_nCurrentPaletteROMLocation = pCurrDef->uOffset;
        m_nCurrentPaletteSizeInColors = (pCurrDef->cbPaletteSize / m_nSizeOfColorsInBytes);
        m_pszCurrentPaletteName = pCurrDef->szDesc;
    }
}

BOOL CGame_FatalFuryS_A::UpdatePalImg(int Node01, int Node02, int Node03, int Node04)
{
    return _UpdatePalImg(FatalFuryS_A_UNITS, rgExtraCountAll, FatalFuryS_A_NUMUNIT, FatalFuryS_A_EXTRALOC, FatalFuryS_A_EXTRA_CUSTOM, Node01, Node02, Node03, Node03);
}
