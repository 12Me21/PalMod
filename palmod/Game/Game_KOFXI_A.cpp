#include "StdAfx.h"
#include "GameDef.h"
#include "Game_KOFXI_A.h"
#include "..\PalMod.h"
#include "..\RegProc.h"

stExtraDef* CGame_KOFXI_A::KOFXI_A_EXTRA_CUSTOM = nullptr;

CDescTree CGame_KOFXI_A::MainDescTree = nullptr;

uint32_t CGame_KOFXI_A::rgExtraCountAll[KOFXI_A_NUMUNIT + 1];
uint32_t CGame_KOFXI_A::rgExtraLoc[KOFXI_A_NUMUNIT + 1];

uint32_t CGame_KOFXI_A::m_nTotalPaletteCountForKOFXI = 0;
uint32_t CGame_KOFXI_A::m_nConfirmedROMSize = -1;

void CGame_KOFXI_A::InitializeStatics()
{
    safe_delete_array(CGame_KOFXI_A::KOFXI_A_EXTRA_CUSTOM);

    memset(rgExtraCountAll, -1, sizeof(rgExtraCountAll));
    memset(rgExtraLoc, -1, sizeof(rgExtraLoc));

    MainDescTree.SetRootTree(CGame_KOFXI_A::InitDescTree());
}

CGame_KOFXI_A::CGame_KOFXI_A(uint32_t nConfirmedROMSize)
{
    OutputDebugString(L"CGame_KOFXI_A::CGame_KOFXI_A: Loading ROM...\n");

    createPalOptions = { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_MAX };
    SetAlphaMode(AlphaMode::GameUsesFixedAlpha);
    SetColorMode(ColMode::COLMODE_RGB555_BE);

    // We need this set before we initialize so that corrupt Extras truncate correctly.
    // Otherwise the new user inadvertently corrupts their ROM.
    m_nConfirmedROMSize = nConfirmedROMSize;
    InitializeStatics();

    m_nTotalInternalUnits = KOFXI_A_NUMUNIT;
    m_nExtraUnit = KOFXI_A_EXTRALOC;

    m_nSafeCountForThisRom = GetExtraCt(m_nExtraUnit) + 7680;
    m_pszExtraFilename = EXTRA_FILENAME_KOFXI_A;
    m_nTotalPaletteCount = m_nTotalPaletteCountForKOFXI;
    // This magic number is used to warn users if their Extra file is trying to write somewhere potentially unusual
    m_nLowestKnownPaletteRomLocation = 0x1011000;

    nUnitAmt = m_nTotalInternalUnits + (GetExtraCt(m_nExtraUnit) ? 1 : 0);

    InitDataBuffer();

    //Set game information
    nGameFlag = KOFXI_A;
    nImgGameFlag = IMGDAT_SECTION_KOF;
    m_prgGameImageSet = KOFXI_A_IMGIDS_USED;

    nFileAmt = 1;

    //Set the image out display type
    DisplayType = eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT;
    // Button labels are used for the Export Image dialog
    pButtonLabelSet = DEF_BUTTONLABEL_KOFXI;

    //Create the redirect buffer
    rgUnitRedir = new uint32_t[nUnitAmt + 1];
    memset(rgUnitRedir, NULL, sizeof(uint32_t) * nUnitAmt);

    //Create the file changed flag
    PrepChangeTrackingArray();
}

CGame_KOFXI_A::~CGame_KOFXI_A()
{
    safe_delete_array(CGame_KOFXI_A::KOFXI_A_EXTRA_CUSTOM);
    ClearDataBuffer();
    //Get rid of the file changed flag
    FlushChangeTrackingArray();
}

CDescTree* CGame_KOFXI_A::GetMainTree()
{
    return &CGame_KOFXI_A::MainDescTree;
}

uint32_t CGame_KOFXI_A::GetExtraCt(uint32_t nUnitId, BOOL fCountVisibleOnly)
{
    return _GetExtraCount(rgExtraCountAll, KOFXI_A_NUMUNIT, nUnitId, KOFXI_A_EXTRA_CUSTOM);
}

uint32_t CGame_KOFXI_A::GetExtraLoc(uint32_t nUnitId)
{
    return _GetExtraLocation(rgExtraLoc, KOFXI_A_NUMUNIT, nUnitId, KOFXI_A_EXTRA_CUSTOM);
}

struct sKOFXI_CharacterDump
{
    LPCWSTR pszCharacterName = nullptr;
    uint32_t baseLocation = 0;
    LPCWSTR pszImageRefName = nullptr;
};

sKOFXI_CharacterDump kofXICharacterList[] =
{
    { L"Ash",       0x1011000, L"indexKOFXISprites_Ash" }, // 0x1012800
    { L"Oswald",    0x11e2800, L"indexKOFXISprites_Oswald" }, // 0x11e4000
    { L"Shen",      0x13ab000, L"indexKOFXISprites_Shen" }, // 0x13ac800
    { L"Elizabeth", 0x1522800, L"indexKOFXISprites_Elizabeth" }, // 0x1524000
    { L"Duo Lon",   0x16bf000, L"indexKOFXISprites_Duo" }, // 0x16c0800
    { L"Benimaru",  0x1861800, L"indexKOFXISprites_Benimaru" }, // 0x1863000
    { L"Terry",     0x19b8000, L"indexKOFXISprites_Terry" }, // 0x19b9800
    { L"Kim",       0x1b58000, L"indexKOFXISprites_Kim" }, // 0x1b59800
    { L"Duck King", 0x1c8f800, L"indexKOFXISprites_DuckKing" }, // 0x1c91000
    { L"Ryo",       0x1df4000, L"indexKOFXISprites_Ryo" }, // 0x1df5800
    { L"Yuri",      0x1f5f000, L"indexKOFXISprites_Yuri" }, // 0x1f60800
    { L"King",      0x20ba800, L"indexKOFXISprites_King" }, // 0x20bc000
    { L"B. Jenet",  0x21c5800, L"indexKOFXISprites_BJenet" }, // 0x21c7000
    { L"Gato",      0x2381000, L"indexKOFXISprites_Gato" }, // 0x2382800
    { L"Tizoc/The Griffon", 0x24e1000, L"indexKOFXISprites_Tizoc" }, // 0x24e2800
    { L"Ralf",      0x2680000, L"indexKOFXISprites_Ralf" }, // 0x2681800
    { L"Clark",     0x27c1000, L"indexKOFXISprites_Clark" }, // 0x27c2800
    { L"Whip",      0x28ed000, L"indexKOFXISprites_Whip" }, // 0x28ee800
    { L"Athena",    0x2a9d800, L"indexKOFXISprites_Athena" }, // 0x2a9f000
    { L"Kensou",    0x2c52800, L"indexKOFXISprites_Kensou" }, // 0x2c54000
    { L"Momoko",    0x2dd9000, L"indexKOFXISprites_Momoko" }, // 0x2dda800
    { L"Vanessa",   0x2f98000, L"indexKOFXISprites_Vanessa" }, // 0x2f99800
    { L"Blue Mary", 0x30ef000, L"indexKOFXISprites_BlueMary" }, // 0x30f0800
    { L"Ramon",     0x3257000, L"indexKOFXISprites_Ramon" }, // 0x3258800
    { L"Malin",     0x33b3800, L"indexKOFXISprites_Malin" }, // 0x33b5000
    { L"Kasumi",    0x34e4800, L"indexKOFXISprites_Kasumi" }, // 0x34e6000
    { L"Eiji",      0x3609800, L"indexKOFXISprites_Eiji" }, // 0x360b000
    { L"K'",        0x3763800, L"indexKOFXISprites_K" }, // 0x3765000
    { L"Kula",      0x3901800, L"indexKOFXISprites_Kula" }, // 0x3903000
    { L"Maxima",    0x3ab6800, L"indexKOFXISprites_Maxima" }, // 0x3ab8000
    { L"Kyo",       0x3c57800, L"indexKOFXISprites_Kyo" }, // 0x3c59000
    { L"Iori",      0x3df6000, L"indexKOFXISprites_Iori" }, // 0x3df7800
    { L"Shingo",    0x3fc5800, L"indexKOFXISprites_Shingo" }, // 0x3fc7000
    { L"Gai",       0x40d3000, L"indexKOFXISprites_Gai" }, // 0x40d4800
    { L"Sho",       0x420f800, L"indexKOFXISprites_Sho" }, // 0x4211000
    { L"Adelheid",  0x4366800, L"indexKOFXISprites_Adelheid" }, // 0x4368000
    { L"Silber",    0x44b1000, L"indexKOFXISprites_Silber" }, // 0x44b2800
    { L"Jyazu",     0x45fa800, L"indexKOFXISprites_Jyazu" }, // 0x45fc000
    { L"Shion",     0x47cb800, L"indexKOFXISprites_Shion" }, // 0x47cd000
    { L"Magaki",    0x499a000, L"indexKOFXISprites_Magaki" }, // 0x499b600
};

const std::vector<LPCWSTR >DEF_BUTTONLABEL_KOFXI_FOR_UI =
{
    L"A", L"B", L"C", L"D", L"E + A", L"E + B", L"E + C", L"E + D", L"Start + A", L"Start + B", L"Start + C", L"Start + D"
};

void CGame_KOFXI_A::DumpAllCharacters()
{
    const LPCWSTR DEF_BUTTONLABEL_KOFXI_FOR_CODE[] =
    {
        L"A", L"B", L"C", L"D", L"EA", L"EB", L"EC", L"ED", L"SA", L"SB", L"SC", L"SD"
    };

    //Go through each character
    for (uint16_t iUnitCtr = 0; iUnitCtr < ARRAYSIZE(kofXICharacterList); iUnitCtr++)
    {
        uint32_t nCurrentCharacterOffset = 0;
        uint16_t nPaletteCount = 0;
        CString strOutput;
        wchar_t szCodeDesc[MAX_DESCRIPTION_LENGTH];

        StruprRemoveNonASCII(szCodeDesc, ARRAYSIZE(szCodeDesc), kofXICharacterList[iUnitCtr].pszCharacterName);

        for (uint16_t iButtonIndex = 0; iButtonIndex < DEF_BUTTONLABEL_KOFXI.size(); iButtonIndex++)
        {
            nCurrentCharacterOffset = kofXICharacterList[iUnitCtr].baseLocation + (0x200 * iButtonIndex);

            strOutput.Format(L"const sGame_PaletteDataset KOFXI_A_%s_PALETTES_%s[] =\r\n{\r\n", szCodeDesc, DEF_BUTTONLABEL_KOFXI_FOR_CODE[iButtonIndex]);
            OutputDebugString(strOutput);

            if (kofXICharacterList[iUnitCtr].pszImageRefName)
            {
                strOutput.Format(L"    { L\"%s %s\", 0x%07x, 0x%07x, %s },\r\n", kofXICharacterList[iUnitCtr].pszCharacterName, DEF_BUTTONLABEL_KOFXI_FOR_CODE[iButtonIndex],
                    nCurrentCharacterOffset, nCurrentCharacterOffset + 0x20,
                    kofXICharacterList[iUnitCtr].pszImageRefName);
            }
            else
            {
                strOutput.Format(L"    { L\"%s %s\", 0x%07x, 0x%07x },\r\n", kofXICharacterList[iUnitCtr].pszCharacterName, DEF_BUTTONLABEL_KOFXI_FOR_CODE[iButtonIndex],
                    nCurrentCharacterOffset, nCurrentCharacterOffset + 0x20);
            }

            OutputDebugString(strOutput);
            nCurrentCharacterOffset += 0x20;
            nPaletteCount++;

            struct MoveWithImage
            {
                LPCWSTR pszMoveName = L"";
                uint32_t nCurrentImageToUse = 0x00;
            };

            const MoveWithImage rgMoveInfo[] =
            {
                { L"Super Stuff 1", 0x20 },
                { L"Electric Palette", 0x41 },
                { L"Darker Palette", 0x40 },
                { L"Super Stuff 2", 0x21 },
                { L"Character Extra 1", 0x30 },
                { L"Character Extra 2", 0x31 },
                { L"Character Extra 3", 0x32 },
                { L"Extra Move 1", 0x10 },
                { L"Extra Move 2", 0x11 },
                { L"Extra Move 3", 0x12 },
                { L"Extra Move 4", 0x13 },
                { L"Extra Move 5", 0x14 },
                { L"Extra Move 6", 0x15 },
                { L"Extra Move 7", 0x16 },
                { L"Extra Move 8", 0x17 },
            };

            for (uint16_t iCurrentExtra = 0; iCurrentExtra < ARRAYSIZE(rgMoveInfo); iCurrentExtra++)
            {
                LPCWSTR pszCurrentMoveName = rgMoveInfo[iCurrentExtra].pszMoveName;
                uint32_t nCurrentImageToUse = rgMoveInfo[iCurrentExtra].nCurrentImageToUse;

                if (kofXICharacterList[iUnitCtr].pszImageRefName)
                {
                    strOutput.Format(L"    { L\"%s - %s\", 0x%07x, 0x%07x, %s, 0x%02x },\r\n", DEF_BUTTONLABEL_KOFXI[iButtonIndex], pszCurrentMoveName,
                        nCurrentCharacterOffset, nCurrentCharacterOffset + 0x20,
                        kofXICharacterList[iUnitCtr].pszImageRefName, nCurrentImageToUse);
                }
                else
                {
                    strOutput.Format(L"    { L\"%s - %s\", 0x%07x, 0x%07x },\r\n", DEF_BUTTONLABEL_KOFXI[iButtonIndex], pszCurrentMoveName,
                        nCurrentCharacterOffset, nCurrentCharacterOffset + 0x20);
                }

                OutputDebugString(strOutput);
                nCurrentCharacterOffset += 0x20;
                nPaletteCount++;
            }

            OutputDebugString(L"};\r\n\r\n");
        }
    }

    // Now create the collections...
    for (uint16_t iUnitCtr = 0; iUnitCtr < ARRAYSIZE(kofXICharacterList); iUnitCtr++)
    {
        CString strOutput;
        wchar_t szCodeDesc[MAX_DESCRIPTION_LENGTH];

        StruprRemoveNonASCII(szCodeDesc, ARRAYSIZE(szCodeDesc), kofXICharacterList[iUnitCtr].pszCharacterName);

        strOutput.Format(L"const sDescTreeNode KOFXI_A_%s_COLLECTION[] =\r\n{\r\n", szCodeDesc);
        OutputDebugString(strOutput);

        for (uint16_t nButtonNameIndex = 0; nButtonNameIndex < DEF_BUTTONLABEL_KOFXI_FOR_UI.size(); nButtonNameIndex++)
        {
            strOutput.Format(L"    { L\"%s\", DESC_NODETYPE_TREE, (void*)KOFXI_A_%s_PALETTES_%s, ARRAYSIZE(KOFXI_A_%s_PALETTES_%s) },\r\n", DEF_BUTTONLABEL_KOFXI_FOR_UI[nButtonNameIndex], szCodeDesc, DEF_BUTTONLABEL_KOFXI_FOR_CODE[nButtonNameIndex],
                                                                                                                                            szCodeDesc, DEF_BUTTONLABEL_KOFXI_FOR_CODE[nButtonNameIndex] );
            OutputDebugString(strOutput);
        }
        
        OutputDebugString(L"};\r\n\r\n");
    }

    for (uint16_t iUnitCtr = 0; iUnitCtr < ARRAYSIZE(kofXICharacterList); iUnitCtr++)
    {
        uint32_t nCurrentCharacterOffset = 0;
        uint16_t nPaletteCount = 0;
        CString strOutput;
        wchar_t szCodeDesc[MAX_DESCRIPTION_LENGTH];

        StruprRemoveNonASCII(szCodeDesc, ARRAYSIZE(szCodeDesc), kofXICharacterList[iUnitCtr].pszCharacterName);

        strOutput.Format(L"    { L\"%s\", DESC_NODETYPE_TREE, (void*)KOFXI_A_%s_COLLECTION, ARRAYSIZE(KOFXI_A_%s_COLLECTION) },\r\n", kofXICharacterList[iUnitCtr].pszCharacterName, szCodeDesc, szCodeDesc);
        OutputDebugString(strOutput);
    }
}

sDescTreeNode* CGame_KOFXI_A::InitDescTree()
{
    //Load extra file if we're using it
    LoadExtraFileForGame(EXTRA_FILENAME_KOFXI_A, &KOFXI_A_EXTRA_CUSTOM, KOFXI_A_EXTRALOC, m_nConfirmedROMSize);

    uint16_t nUnitCt = KOFXI_A_NUMUNIT + (GetExtraCt(KOFXI_A_EXTRALOC) ? 1 : 0);
    
    sDescTreeNode* NewDescTree = new sDescTreeNode;

    //Create the main character tree
    _snwprintf_s(NewDescTree->szDesc, ARRAYSIZE(NewDescTree->szDesc), _TRUNCATE, L"%s", g_GameFriendlyName[KOFXI_A]);
    NewDescTree->ChildNodes = new sDescTreeNode[nUnitCt];
    NewDescTree->uChildAmt = nUnitCt;
    //All units have tree children
    NewDescTree->uChildType = DESC_NODETYPE_TREE;

    m_nTotalPaletteCountForKOFXI = _InitDescTree(NewDescTree,
        KOFXI_A_UNITS,
        KOFXI_A_EXTRALOC,
        KOFXI_A_NUMUNIT,
        rgExtraCountAll,
        rgExtraLoc,
        KOFXI_A_EXTRA_CUSTOM
    );

    // This is used during development to produce the palette data for the header
    //DumpAllCharacters();

    return NewDescTree;
}

sFileRule CGame_KOFXI_A::GetRule(uint32_t nUnitId)
{
    sFileRule NewFileRule;

    // This value is only used for directory-based games
    _snwprintf_s(NewFileRule.szFileName, ARRAYSIZE(NewFileRule.szFileName), _TRUNCATE, L"gdrom_KOFXI_v5_AllFighters.bin");

    NewFileRule.uUnitId = 0;
    NewFileRule.uVerifyVar = m_nExpectedGameROMSize;

    return NewFileRule;
}

uint32_t CGame_KOFXI_A::GetCollectionCountForUnit(uint32_t nUnitId)
{
    return _GetCollectionCountForUnit(KOFXI_A_UNITS, rgExtraCountAll, KOFXI_A_NUMUNIT, KOFXI_A_EXTRALOC, nUnitId, KOFXI_A_EXTRA_CUSTOM);
}

uint32_t CGame_KOFXI_A::GetNodeCountForCollection(uint32_t nUnitId, uint32_t nCollectionId)
{
    return _GetNodeCountForCollection(KOFXI_A_UNITS, rgExtraCountAll, KOFXI_A_NUMUNIT, KOFXI_A_EXTRALOC, nUnitId, nCollectionId, KOFXI_A_EXTRA_CUSTOM);
}

LPCWSTR CGame_KOFXI_A::GetDescriptionForCollection(uint32_t nUnitId, uint32_t nCollectionId)
{
    return _GetDescriptionForCollection(KOFXI_A_UNITS, KOFXI_A_EXTRALOC, nUnitId, nCollectionId);
}

uint32_t CGame_KOFXI_A::GetPaletteCountForUnit(uint32_t nUnitId)
{
    return _GetPaletteCountForUnit(KOFXI_A_UNITS, rgExtraCountAll, KOFXI_A_NUMUNIT, KOFXI_A_EXTRALOC, nUnitId, KOFXI_A_EXTRA_CUSTOM);
}

const sGame_PaletteDataset* CGame_KOFXI_A::GetPaletteSet(uint32_t nUnitId, uint32_t nCollectionId)
{
    return _GetPaletteSet(KOFXI_A_UNITS, nUnitId, nCollectionId);
}

const sDescTreeNode* CGame_KOFXI_A::GetNodeFromPaletteId(uint32_t nUnitId, uint32_t nPaletteId, bool fReturnBasicNodesOnly)
{
    return _GetNodeFromPaletteId(KOFXI_A_UNITS, rgExtraCountAll, KOFXI_A_NUMUNIT, KOFXI_A_EXTRALOC, nUnitId, nPaletteId, KOFXI_A_EXTRA_CUSTOM, fReturnBasicNodesOnly);
}

const sGame_PaletteDataset* CGame_KOFXI_A::GetSpecificPalette(uint32_t nUnitId, uint32_t nPaletteId)
{
    return _GetSpecificPalette(KOFXI_A_UNITS, rgExtraCountAll, KOFXI_A_NUMUNIT, KOFXI_A_EXTRALOC, nUnitId, nPaletteId, KOFXI_A_EXTRA_CUSTOM);
}

void CGame_KOFXI_A::LoadSpecificPaletteData(uint32_t nUnitId, uint32_t nPalId)
{
     if (nUnitId != KOFXI_A_EXTRALOC)
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
    else // KOFXI_A_EXTRALOC
    {
        // This is where we handle all the palettes added in via Extra.
        stExtraDef* pCurrDef = &KOFXI_A_EXTRA_CUSTOM[GetExtraLoc(nUnitId) + nPalId];

        m_nCurrentPaletteROMLocation = pCurrDef->uOffset;
        m_nCurrentPaletteSizeInColors = (pCurrDef->cbPaletteSize / m_nSizeOfColorsInBytes);
        m_pszCurrentPaletteName = pCurrDef->szDesc;
    }
}

BOOL CGame_KOFXI_A::UpdatePalImg(int Node01, int Node02, int Node03, int Node04)
{
    return _UpdatePalImg(KOFXI_A_UNITS, rgExtraCountAll, KOFXI_A_NUMUNIT, KOFXI_A_EXTRALOC, KOFXI_A_EXTRA_CUSTOM, Node01, Node02, Node03, Node03);
}
