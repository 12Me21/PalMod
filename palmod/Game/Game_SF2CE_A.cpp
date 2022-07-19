#include "StdAfx.h"
#include "Game_SF2CE_A.h"
#include "GameDef.h"
#include "..\ExtraFile.h"
#include "..\PalMod.h"
#include "..\regproc.h"

#define SF2CE_A_DEBUG DEFAULT_GAME_DEBUG_STATE

stExtraDef* CGame_SF2CE_A::SF2CE_A_21_EXTRA_CUSTOM = NULL;
stExtraDef* CGame_SF2CE_A::SF2CE_A_22_EXTRA_CUSTOM = NULL;
stExtraDef* CGame_SF2CE_A::SF2CE_A_23_EXTRA_CUSTOM = NULL;

uint32_t CGame_SF2CE_A::rgExtraCountAll_21[SF2CE_A_21_NUMUNIT + 1] = { (uint32_t)-1 };
uint32_t CGame_SF2CE_A::rgExtraCountAll_22[SF2CE_A_22_NUMUNIT + 1] = { (uint32_t)-1 };
uint32_t CGame_SF2CE_A::rgExtraCountAll_23[SF2CE_A_23_NUMUNIT + 1] = { (uint32_t)-1 };
uint32_t CGame_SF2CE_A::rgExtraCountVisibleOnly_21[SF2CE_A_21_NUMUNIT + 1] = { (uint32_t)-1 };
uint32_t CGame_SF2CE_A::rgExtraCountVisibleOnly_22[SF2CE_A_22_NUMUNIT + 1] = { (uint32_t)-1 };
uint32_t CGame_SF2CE_A::rgExtraCountVisibleOnly_23[SF2CE_A_23_NUMUNIT + 1] = { (uint32_t)-1 };
uint32_t CGame_SF2CE_A::rgExtraLoc_21[SF2CE_A_21_NUMUNIT + 1] = { (uint32_t)-1 };
uint32_t CGame_SF2CE_A::rgExtraLoc_22[SF2CE_A_22_NUMUNIT + 1] = { (uint32_t)-1 };
uint32_t CGame_SF2CE_A::rgExtraLoc_23[SF2CE_A_23_NUMUNIT + 1] = { (uint32_t)-1 };

CDescTree CGame_SF2CE_A::MainDescTree_21 = nullptr;
CDescTree CGame_SF2CE_A::MainDescTree_22 = nullptr;
CDescTree CGame_SF2CE_A::MainDescTree_23 = nullptr;
uint32_t CGame_SF2CE_A::m_nConfirmedROMSize = -1;

uint32_t CGame_SF2CE_A::m_nSelectedRom = 22;
uint32_t CGame_SF2CE_A::m_nTotalPaletteCountForSF2CE_21 = 0;
uint32_t CGame_SF2CE_A::m_nTotalPaletteCountForSF2CE_22 = 0;
uint32_t CGame_SF2CE_A::m_nTotalPaletteCountForSF2CE_23 = 0;

void CGame_SF2CE_A::InitializeStatics()
{
    safe_delete_array(CGame_SF2CE_A::SF2CE_A_21_EXTRA_CUSTOM);
    safe_delete_array(CGame_SF2CE_A::SF2CE_A_22_EXTRA_CUSTOM);
    safe_delete_array(CGame_SF2CE_A::SF2CE_A_23_EXTRA_CUSTOM);

    memset(rgExtraCountAll_21, -1, sizeof(rgExtraCountAll_21));
    memset(rgExtraCountAll_22, -1, sizeof(rgExtraCountAll_22));
    memset(rgExtraCountAll_23, -1, sizeof(rgExtraCountAll_23));
    memset(rgExtraCountVisibleOnly_21, -1, sizeof(rgExtraCountVisibleOnly_21));
    memset(rgExtraCountVisibleOnly_22, -1, sizeof(rgExtraCountVisibleOnly_22));
    memset(rgExtraCountVisibleOnly_23, -1, sizeof(rgExtraCountVisibleOnly_23));
    memset(rgExtraLoc_21, -1, sizeof(rgExtraLoc_21));
    memset(rgExtraLoc_22, -1, sizeof(rgExtraLoc_22));
    memset(rgExtraLoc_23, -1, sizeof(rgExtraLoc_23));

    MainDescTree_21.SetRootTree(CGame_SF2CE_A::InitDescTree(21));
    MainDescTree_22.SetRootTree(CGame_SF2CE_A::InitDescTree(22));
    MainDescTree_23.SetRootTree(CGame_SF2CE_A::InitDescTree(23));
}

CGame_SF2CE_A::CGame_SF2CE_A(uint32_t nConfirmedROMSize, int nSF2CEROMToLoad)
{
    createPalOptions = { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_MAX };
    SetAlphaMode(AlphaMode::GameDoesNotUseAlpha);
    SetColorMode(ColMode::COLMODE_RGB444_BE);

    // We need this set before we initialize so that corrupt Extras truncate correctly.
    // Otherwise the new user inadvertently corrupts their ROM.
    m_nConfirmedROMSize = nConfirmedROMSize;

    InitializeStatics();

    m_nSelectedRom = nSF2CEROMToLoad;

    switch (m_nSelectedRom)
    {
    case 21:
        m_pszExtraFilename = EXTRA_FILENAME_SF2CE_21;
        m_nTotalInternalUnits = SF2CE_A_21_NUMUNIT;
        m_nExtraUnit = SF2CE_A_21_EXTRALOC;

        nUnitAmt = m_nTotalInternalUnits + (GetExtraCt(m_nExtraUnit) ? 1 : 0);

        m_nSafeCountForThisRom = GetExtraCt(m_nExtraUnit) + 39;
        m_nTotalPaletteCount = m_nTotalPaletteCountForSF2CE_21;
        m_nLowestKnownPaletteRomLocation = 0x93fe;
        break;
    case 22:
    default:
        m_pszExtraFilename = EXTRA_FILENAME_SF2CE_22;

        //We need the proper unit amt before we init the main buffer
        m_nTotalInternalUnits = SF2CE_A_22_NUMUNIT;
        m_nExtraUnit = SF2CE_A_22_EXTRALOC;

        nUnitAmt = m_nTotalInternalUnits + (GetExtraCt(m_nExtraUnit) ? 1 : 0);

        m_nSafeCountForThisRom = GetExtraCt(m_nExtraUnit) + 24;
        m_nTotalPaletteCount = m_nTotalPaletteCountForSF2CE_22;
        m_nLowestKnownPaletteRomLocation = 0x16834;
        break;
    case 23:
        m_pszExtraFilename = EXTRA_FILENAME_SF2CE_23;
        m_nTotalInternalUnits = SF2CE_A_23_NUMUNIT;
        m_nExtraUnit = SF2CE_A_23_EXTRALOC;

        nUnitAmt = m_nTotalInternalUnits + (GetExtraCt(m_nExtraUnit) ? 1 : 0);

        m_nSafeCountForThisRom = GetExtraCt(m_nExtraUnit) + 16;
        m_nTotalPaletteCount = m_nTotalPaletteCountForSF2CE_23;
        m_nLowestKnownPaletteRomLocation = 0x01dff8;
        break;
    };

    CString strInfo;
    strInfo.Format(L"CGame_SF2CE_A::CGame_SF2CE_A: Loaded SF2CE_A with %u Extras\n", GetExtraCt(m_nExtraUnit));
    OutputDebugString(strInfo);

    InitDataBuffer();

    //Set game information
    nGameFlag = SF2CE_A;
    nImgGameFlag = IMGDAT_SECTION_SF2;
    m_prgGameImageSet = SF2HF_A_IMGIDS_USED;

    nFileAmt = 1;

    //Set the image out display type
    DisplayType = eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT;
    pButtonLabelSet = DEF_BUTTONLABEL_2;

    //Create the redirect buffer
    rgUnitRedir = new uint32_t[nUnitAmt + 1];
    memset(rgUnitRedir, NULL, sizeof(uint32_t) * nUnitAmt);

    //Create the file changed flag
    PrepChangeTrackingArray();
}

CGame_SF2CE_A::~CGame_SF2CE_A()
{
    safe_delete_array(CGame_SF2CE_A::SF2CE_A_21_EXTRA_CUSTOM);
    safe_delete_array(CGame_SF2CE_A::SF2CE_A_22_EXTRA_CUSTOM);
    safe_delete_array(CGame_SF2CE_A::SF2CE_A_23_EXTRA_CUSTOM);
    //Get rid of the file changed flag
    ClearDataBuffer();
    FlushChangeTrackingArray();
}

uint32_t CGame_SF2CE_A::GetKnownCRC32DatasetsForGame(const sCRC32ValueSet** ppKnownROMSet, bool* pfNeedToValidateCRCs)
{
    static const sCRC32ValueSet knownROMs[] =
    {
        // 21 is the same across all versions
        { L"Street Fighter II' - Champion Edition", L"s92_21a.6f", 0x925a7877, 0 },
        { L"Street Fighter II' - Champion Edition (Japan 920308)", L"s92j_21a.6f", 0x925a7877, 0 },

        // 22 shifts consistently across revisions
        { L"Street Fighter II' - Champion Edition (920313)", L"s92_22a.7f", 0x99f1cca4, -0xc },
        { L"Street Fighter II' - Champion Edition (920513)", L"s92_22b.7f", 0x2bbe15ed, 0 },
        { L"Street Fighter II' - Champion Edition (920803)", L"s92_22c.7f", 0x5fd8630b, 0x8 },

        // second shift for boxer and P2 colors at least
        { L"Street Fighter II' - Champion Edition (Japan 920313)", k_SF2CE_JapanROMName_RevA, 0xc4f64bcd, 0x1BDE },
        { L"Street Fighter II' - Champion Edition (Japan 920513)", k_SF2CE_JapanROMName_RevB, 0x2fbb3bfe, 0x1BF0 },
        { L"Street Fighter II' - Champion Edition (Japan 920803)", k_SF2CE_JapanROMName_RevC, 0x8c0b2ed6, 0x1BF8 },

        // 23
        { L"Street Fighter II' - Champion Edition (World 920313)", L"s92e_23b.8f", 0x0aaa1a3a, 0 }, // ce - core
        { L"Street Fighter II' - Champion Edition (World 920513)", L"s92e_23a.8f", 0x3f846b74, 0 }, // ceea

        { L"Street Fighter II' - Champion Edition (USA 920313)", L"s92u_23a.8f", 0xac44415b, 0 }, // ceua
        { L"Street Fighter II' - Champion Edition (USA 920513)", L"s92u_23b.8f", 0x996a3015, 0 }, // ceub
        { L"Street Fighter II' - Champion Edition (USA 920803)", L"s92u_23c.8f", 0x0a8b6aa2, 0 }, // ceuc

        { L"Street Fighter II' - Champion Edition (Taiwan 920313)", L"s92t_23a.8f", 0xd7c28ade, 0 }, // cet
        { L"Street Fighter II' - Champion Edition (Japan 920322)", L"s92j_23a.8f", 0x4f42bb5a, 0xA14 }, // ceja
        { L"Street Fighter II' - Champion Edition (Japan 920513)", L"s92j_23b.8f", 0x140876c5, 0xA14 }, // cejb
        { L"Street Fighter II' - Champion Edition (Japan 920803)", L"s92j_23c.8f", 0xf0120635, 0xA14 }, // cejc
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

#ifdef MAME_INFO
        ROM_START(sf2ce)    // 13/05/1992 (c) 1992 (World)
        ROM_REGION(CODE_SIZE, "maincpu", 0)      /* 68000 code */
        ROM_LOAD16_WORD_SWAP("s92e_23b.8f", 0x000000, 0x80000, CRC(0aaa1a3a) SHA1(774a2b52f7c1876c0e10d8d57a0850ad2d016cf6))
        ROM_LOAD16_WORD_SWAP("s92_22b.7f", 0x080000, 0x80000, CRC(2bbe15ed) SHA1(a8e2edef62fa99c5ef701b28bfb6bc42f3af183d))
        ROM_LOAD16_WORD_SWAP("s92_21a.6f", 0x100000, 0x80000, CRC(925a7877) SHA1(1960dca35f0ca6f2b399a9fccfbc0132ac6425d1))

        ROM_START(sf2ceea)  // 13/03/1992 (c) 1992 (World)
        ROM_REGION(CODE_SIZE, "maincpu", 0)      /* 68000 code */
        ROM_LOAD16_WORD_SWAP("s92e_23a.8f", 0x000000, 0x80000, CRC(3f846b74) SHA1(c8d7a01b626771870123f1663a01a81f9c8fe582))
        ROM_LOAD16_WORD_SWAP("s92_22a.7f", 0x080000, 0x80000, CRC(99f1cca4) SHA1(64111eba81d743fc3fd51d7a89cd0b2eefcc900d))
        ROM_LOAD16_WORD_SWAP("s92_21a.6f", 0x100000, 0x80000, CRC(925a7877) SHA1(1960dca35f0ca6f2b399a9fccfbc0132ac6425d1))

        ROM_START(sf2ceua) // 13/03/1992 (c) 1992 (USA)
        ROM_REGION(CODE_SIZE, "maincpu", 0)      /* 68000 code */
        ROM_LOAD16_WORD_SWAP("s92u_23a.8f", 0x000000, 0x80000, CRC(ac44415b) SHA1(218f8b1886eb72b8547127042b5ae47600e18944))
        ROM_LOAD16_WORD_SWAP("s92_22a.7f", 0x080000, 0x80000, CRC(99f1cca4) SHA1(64111eba81d743fc3fd51d7a89cd0b2eefcc900d))
        ROM_LOAD16_WORD_SWAP("s92_21a.6f", 0x100000, 0x80000, CRC(925a7877) SHA1(1960dca35f0ca6f2b399a9fccfbc0132ac6425d1))

        ROM_START(sf2ceub) // 13/05/1992 (c) 1992 (USA)
        ROM_REGION(CODE_SIZE, "maincpu", 0)      /* 68000 code */
        ROM_LOAD16_WORD_SWAP("s92u_23b.8f", 0x000000, 0x80000, CRC(996a3015) SHA1(fdf45da54b1c14478a60f2b86e37ffe32a98b135))
        ROM_LOAD16_WORD_SWAP("s92_22b.7f", 0x080000, 0x80000, CRC(2bbe15ed) SHA1(a8e2edef62fa99c5ef701b28bfb6bc42f3af183d))
        ROM_LOAD16_WORD_SWAP("s92_21a.6f", 0x100000, 0x80000, CRC(925a7877) SHA1(1960dca35f0ca6f2b399a9fccfbc0132ac6425d1))

        ROM_START(sf2ceuc) // 03/08/1992 (c) 1992 (USA)
        ROM_REGION(CODE_SIZE, "maincpu", 0)      /* 68000 code */
        ROM_LOAD16_WORD_SWAP("s92u_23c.8f", 0x000000, 0x80000, CRC(0a8b6aa2) SHA1(a19871271172119e1cf1ff47700bb1917b08514b))
        ROM_LOAD16_WORD_SWAP("s92_22c.7f", 0x080000, 0x80000, CRC(5fd8630b) SHA1(f0ef9c5ab91a4b421fb4b1747eef99c964c15de3))
        ROM_LOAD16_WORD_SWAP("s92_21a.6f", 0x100000, 0x80000, CRC(925a7877) SHA1(1960dca35f0ca6f2b399a9fccfbc0132ac6425d1))

        ROM_START(sf2cet) // 13/03/1992 (c) 1992 (Taiwan)
        ROM_REGION(CODE_SIZE, "maincpu", 0)      /* 68000 code */
        ROM_LOAD16_WORD_SWAP("s92t_23a.8f", 0x000000, 0x80000, CRC(d7c28ade) SHA1(4fe8201d8861f9ea9c62fd97b7396bc180a9f3ce))
        ROM_LOAD16_WORD_SWAP("s92_22a.7f", 0x080000, 0x80000, CRC(99f1cca4) SHA1(64111eba81d743fc3fd51d7a89cd0b2eefcc900d))
        ROM_LOAD16_WORD_SWAP("s92_21a.6f", 0x100000, 0x80000, CRC(925a7877) SHA1(1960dca35f0ca6f2b399a9fccfbc0132ac6425d1))

        ROM_START(sf2ceja) // 22/03/1992 (c) 1992 (Japan)
        ROM_REGION(CODE_SIZE, "maincpu", 0)      /* 68000 code */
        ROM_LOAD16_WORD_SWAP("s92j_23a.8f", 0x000000, 0x80000, CRC(4f42bb5a) SHA1(59d0587c554e06ea45d4092ea4299ff086509d4b))
        ROM_LOAD16_WORD_SWAP("s92j_22a.7f", 0x080000, 0x80000, CRC(c4f64bcd) SHA1(262c0419bf727da80c2ac52b877a19276d9aac3c))
        ROM_LOAD16_WORD_SWAP("s92_21a.6f", 0x100000, 0x80000, CRC(925a7877) SHA1(1960dca35f0ca6f2b399a9fccfbc0132ac6425d1))

        ROM_START(sf2cejb) // 13/05/1992 (c) 1992 (Japan)
        ROM_REGION(CODE_SIZE, "maincpu", 0)      /* 68000 code */
        ROM_LOAD16_WORD_SWAP("s92j_23b.8f", 0x000000, 0x80000, CRC(140876c5) SHA1(304630e6d8bae9f8d29090e05f7e013c7dafe9cc))
        ROM_LOAD16_WORD_SWAP("s92j_22b.7f", 0x080000, 0x80000, CRC(2fbb3bfe) SHA1(e364564a12022730c2c0d0e8fd435e2c30ef9410))
        ROM_LOAD16_WORD_SWAP("s92_21a.6f", 0x100000, 0x80000, CRC(925a7877) SHA1(1960dca35f0ca6f2b399a9fccfbc0132ac6425d1))  // could be s92j_21a.6f

        ROM_START(sf2cejc) // 03/08/1992 (c) 1992 (Japan)
        ROM_REGION(CODE_SIZE, "maincpu", 0)      /* 68000 code */
        ROM_LOAD16_WORD_SWAP("s92j_23c.8f", 0x000000, 0x80000, CRC(f0120635) SHA1(5e4a9a4b0f65c6139e76ee4ffa02b9db245b1858))
        ROM_LOAD16_WORD_SWAP("s92j_22c.7f", 0x080000, 0x80000, CRC(8c0b2ed6) SHA1(408db039b4dad72b41458723575ed5352b71e10b))
        ROM_LOAD16_WORD_SWAP("s92j_21a.6f", 0x100000, 0x80000, CRC(925a7877) SHA1(1960dca35f0ca6f2b399a9fccfbc0132ac6425d1))  // == s92_21a.6f
#endif

    return ARRAYSIZE(knownROMs);
}

uint32_t CGame_SF2CE_A::GetExtraCt(uint32_t nUnitId, BOOL fCountVisibleOnly)
{
    switch (m_nSelectedRom)
    {
    case 21:
    {
        return _GetExtraCount(fCountVisibleOnly ? rgExtraCountVisibleOnly_21 : rgExtraCountAll_21, SF2CE_A_21_NUMUNIT, nUnitId, SF2CE_A_21_EXTRA_CUSTOM);
    }
    case 22:
    default:
    {
        return _GetExtraCount(fCountVisibleOnly ? rgExtraCountVisibleOnly_22 : rgExtraCountAll_22, SF2CE_A_22_NUMUNIT, nUnitId, SF2CE_A_22_EXTRA_CUSTOM);
    }
    case 23:
    {
        return _GetExtraCount(fCountVisibleOnly ? rgExtraCountVisibleOnly_23 : rgExtraCountAll_23, SF2CE_A_23_NUMUNIT, nUnitId, SF2CE_A_23_EXTRA_CUSTOM);
    }
    };
}

uint32_t CGame_SF2CE_A::GetExtraLoc(uint32_t nUnitId)
{
    switch (m_nSelectedRom)
    {
    case 21:
    {
        return _GetExtraLocation(rgExtraLoc_21, SF2CE_A_21_NUMUNIT, nUnitId, SF2CE_A_21_EXTRA_CUSTOM);
    }
    case 22:
    default:
    {
        return _GetExtraLocation(rgExtraLoc_22, SF2CE_A_22_NUMUNIT, nUnitId, SF2CE_A_22_EXTRA_CUSTOM);
    }
    case 23:
    {
        return _GetExtraLocation(rgExtraLoc_23, SF2CE_A_23_NUMUNIT, nUnitId, SF2CE_A_23_EXTRA_CUSTOM);
    }
    };
}

const sDescTreeNode* CGame_SF2CE_A::GetCurrentUnitSet()
{
    switch (m_nSelectedRom)
    {
    case 21:
        return SF2CE_A_21_UNITS;
    case 22:
    default:
        return SF2CE_A_22_UNITS;
    case 23:
        return SF2CE_A_23_UNITS;
    };
}

uint32_t CGame_SF2CE_A::GetCurrentExtraLoc()
{
    switch (m_nSelectedRom)
    {
    case 21:
        return SF2CE_A_21_EXTRALOC;
    case 22:
    default:
        return SF2CE_A_22_EXTRALOC;
    case 23:
        return SF2CE_A_23_EXTRALOC;
    };
}

CDescTree* CGame_SF2CE_A::GetMainTree()
{
    switch (m_nSelectedRom)
    {
    case 21:
        return &CGame_SF2CE_A::MainDescTree_21;
    case 22:
    default:
        return &CGame_SF2CE_A::MainDescTree_22;
    case 23:
        return &CGame_SF2CE_A::MainDescTree_23;
    };
}

stExtraDef* CGame_SF2CE_A::GetCurrentExtraDef(int nDefCtr)
{
    switch (m_nSelectedRom)
    {
    case 21:
        return (stExtraDef*)&SF2CE_A_21_EXTRA_CUSTOM[nDefCtr];
    case 22:
    default:
        return (stExtraDef*)&SF2CE_A_22_EXTRA_CUSTOM[nDefCtr];
    case 23:
        return (stExtraDef*)&SF2CE_A_23_EXTRA_CUSTOM[nDefCtr];
    };
}

sDescTreeNode* CGame_SF2CE_A::InitDescTree(int nROMPaletteSetToUse)
{
    uint32_t nTotalPaletteCount = 0;
    m_nSelectedRom = nROMPaletteSetToUse;

    bool fHaveExtras;
    uint16_t nUnitCt;
    uint8_t nExtraUnitLocation;

    switch (m_nSelectedRom)
    {
    case 21:
    {
        nExtraUnitLocation = SF2CE_A_21_EXTRALOC;
        LoadExtraFileForGame(EXTRA_FILENAME_SF2CE_21, &SF2CE_A_21_EXTRA_CUSTOM, nExtraUnitLocation, m_nConfirmedROMSize);
        fHaveExtras = (GetExtraCt(nExtraUnitLocation) > 0);
        nUnitCt = SF2CE_A_21_NUMUNIT + (fHaveExtras ? 1 : 0);
        break;
    }
    case 22:
    default:
    {
        nExtraUnitLocation = SF2CE_A_22_EXTRALOC;
        //Load extra file if we're using it
        LoadExtraFileForGame(EXTRA_FILENAME_SF2CE_22, &SF2CE_A_22_EXTRA_CUSTOM, nExtraUnitLocation, m_nConfirmedROMSize);
        fHaveExtras = (GetExtraCt(nExtraUnitLocation) > 0);
        nUnitCt = SF2CE_A_22_NUMUNIT + (fHaveExtras ? 1 : 0);
        break;
    }
    case 23:
    {
        nExtraUnitLocation = SF2CE_A_23_EXTRALOC;
        //Load extra file if we're using it
        LoadExtraFileForGame(EXTRA_FILENAME_SF2CE_23, &SF2CE_A_23_EXTRA_CUSTOM, nExtraUnitLocation, m_nConfirmedROMSize);
        fHaveExtras = (GetExtraCt(nExtraUnitLocation) > 0);
        nUnitCt = SF2CE_A_23_NUMUNIT + (fHaveExtras ? 1 : 0);
        break;
    }
    };

    sDescTreeNode* NewDescTree = new sDescTreeNode;

    //Create the main character tree
    _snwprintf_s(NewDescTree->szDesc, ARRAYSIZE(NewDescTree->szDesc), _TRUNCATE, L"%s", g_GameFriendlyName[SF2CE_A]);
    NewDescTree->ChildNodes = new sDescTreeNode[nUnitCt];
    NewDescTree->uChildAmt = nUnitCt;
    //All units have tree children
    NewDescTree->uChildType = DESC_NODETYPE_TREE;

    switch (m_nSelectedRom)
    {
    case 21:
        m_nTotalPaletteCountForSF2CE_21 = _InitDescTree(NewDescTree,
            SF2CE_A_21_UNITS,
            SF2CE_A_21_EXTRALOC,
            SF2CE_A_21_NUMUNIT,
            rgExtraCountAll_21,
            rgExtraLoc_21,
            SF2CE_A_21_EXTRA_CUSTOM
        );
        break;
    case 22:
    default:
        m_nTotalPaletteCountForSF2CE_22 = _InitDescTree(NewDescTree,
            SF2CE_A_22_UNITS,
            SF2CE_A_22_EXTRALOC,
            SF2CE_A_22_NUMUNIT,
            rgExtraCountAll_22,
            rgExtraLoc_22,
            SF2CE_A_22_EXTRA_CUSTOM
        );
        break;
    case 23:
        m_nTotalPaletteCountForSF2CE_23 = _InitDescTree(NewDescTree,
            SF2CE_A_23_UNITS,
            SF2CE_A_23_EXTRALOC,
            SF2CE_A_23_NUMUNIT,
            rgExtraCountAll_23,
            rgExtraLoc_23,
            SF2CE_A_23_EXTRA_CUSTOM
        );
        break;
    };

    return NewDescTree;
}

sFileRule CGame_SF2CE_A::GetRule(uint32_t nUnitId)
{
    sFileRule NewFileRule;

    _snwprintf_s(NewFileRule.szFileName, ARRAYSIZE(NewFileRule.szFileName), _TRUNCATE, L"s92_22b.7f");

    NewFileRule.uUnitId = 0;
    NewFileRule.uVerifyVar = m_nExpectedGameROMSize;

    return NewFileRule;
}

uint32_t CGame_SF2CE_A::GetCollectionCountForUnit(uint32_t nUnitId)
{
    if (nUnitId == GetCurrentExtraLoc())
    {
        return GetExtraCt(nUnitId);
    }
    else
    {
        return GetCurrentUnitSet()[nUnitId].uChildAmt;
    }
}

uint32_t CGame_SF2CE_A::GetNodeCountForCollection(uint32_t nUnitId, uint32_t nCollectionId)
{
    if (nUnitId == GetCurrentExtraLoc())
    {
        return GetExtraCt(nUnitId);
    }
    else
    {
        const sDescTreeNode* pCollectionNode = (const sDescTreeNode*)(GetCurrentUnitSet()[nUnitId].ChildNodes);
        return pCollectionNode[nCollectionId].uChildAmt;
    }
}

LPCWSTR CGame_SF2CE_A::GetDescriptionForCollection(uint32_t nUnitId, uint32_t nCollectionId)
{
    if (nUnitId == GetCurrentExtraLoc())
    {
        return L"Extra Palettes";
    }
    else
    {
        const sDescTreeNode* pCollection = (const sDescTreeNode*)GetCurrentUnitSet()[nUnitId].ChildNodes;
        return pCollection[nCollectionId].szDesc;
    }
}

uint32_t CGame_SF2CE_A::GetPaletteCountForUnit(uint32_t nUnitId)
{
    if (nUnitId == GetCurrentExtraLoc())
    {
        return GetExtraCt(nUnitId);
    }
    else
    {
        uint32_t nCompleteCount = 0;
        uint32_t nCollectionCount = GetCurrentUnitSet()[nUnitId].uChildAmt;
        const sDescTreeNode* pCurrentCollection = (const sDescTreeNode*)(GetCurrentUnitSet()[nUnitId].ChildNodes);

        for (uint32_t nCollectionIndex = 0; nCollectionIndex < nCollectionCount; nCollectionIndex++)
        {
            nCompleteCount += pCurrentCollection[nCollectionIndex].uChildAmt;
        }

#if SF2CE_A_DEBUG_EXTRA
        CString strMsg;
        strMsg.Format(L"CGame_SF2CE_A::GetPaletteCountForUnit: %u palettes for unit %u which has %u collections.\n", nCompleteCount, nUnitId, nCollectionCount);
        OutputDebugString(strMsg);
#endif

        return nCompleteCount;
    }
}

const sGame_PaletteDataset* CGame_SF2CE_A::GetPaletteSet(uint32_t nUnitId, uint32_t nCollectionId)
{
    // Don't use this for Extra palettes.
    const sDescTreeNode* pCurrentSet = (const sDescTreeNode*)GetCurrentUnitSet()[nUnitId].ChildNodes;
    return ((sGame_PaletteDataset*)(pCurrentSet[nCollectionId].ChildNodes));
}

const sGame_PaletteDataset* CGame_SF2CE_A::GetSpecificPalette(uint32_t nUnitId, uint32_t nPaletteId)
{
    // Don't use this for Extra palettes.
    uint32_t nTotalCollections = GetCollectionCountForUnit(nUnitId);
    const sGame_PaletteDataset* paletteToUse = nullptr;
    uint32_t nDistanceFromZero = nPaletteId;

    for (uint16_t nCollectionIndex = 0; nCollectionIndex < nTotalCollections; nCollectionIndex++)
    {
        const sGame_PaletteDataset* paletteSetToUse = GetPaletteSet(nUnitId, nCollectionIndex);
        uint32_t nNodeCount = GetNodeCountForCollection(nUnitId, nCollectionIndex);

        if (nDistanceFromZero < nNodeCount)
        {
            paletteToUse = &paletteSetToUse[nDistanceFromZero];
            break;
        }

        nDistanceFromZero -= nNodeCount;
    }

    return paletteToUse;
}

uint32_t CGame_SF2CE_A::GetNodeSizeFromPaletteId(uint32_t nUnitId, uint32_t nPaletteId)
{
    // Don't use this for Extra palettes.
    uint32_t nNodeSize = 0;
    uint32_t nTotalCollections = GetCollectionCountForUnit(nUnitId);
    const sGame_PaletteDataset* paletteSetToUse = nullptr;
    uint32_t nDistanceFromZero = nPaletteId;

    for (uint16_t nCollectionIndex = 0; nCollectionIndex < nTotalCollections; nCollectionIndex++)
    {
        const sGame_PaletteDataset* paletteSetToCheck = GetPaletteSet(nUnitId, nCollectionIndex);
        uint32_t nNodeCount = GetNodeCountForCollection(nUnitId, nCollectionIndex);

        if (nDistanceFromZero < nNodeCount)
        {
            nNodeSize = nNodeCount;
            break;
        }

        nDistanceFromZero -= nNodeCount;
    }

    return nNodeSize;
}

const sDescTreeNode* CGame_SF2CE_A::GetNodeFromPaletteId(uint32_t nUnitId, uint32_t nPaletteId, bool fReturnBasicNodesOnly)
{
    // Don't use this for Extra palettes.
    const sDescTreeNode* pCollectionNode = nullptr;
    uint32_t nTotalCollections = GetCollectionCountForUnit(nUnitId);
    const sGame_PaletteDataset* paletteSetToUse = nullptr;
    uint32_t nDistanceFromZero = nPaletteId;

    for (uint16_t nCollectionIndex = 0; nCollectionIndex < nTotalCollections; nCollectionIndex++)
    {
        const sGame_PaletteDataset* paletteSetToCheck = GetPaletteSet(nUnitId, nCollectionIndex);
        uint32_t nNodeCount;

        if (nUnitId == GetCurrentExtraLoc())
        {
            nNodeCount = GetExtraCt(nUnitId);

            if (nDistanceFromZero < nNodeCount)
            {
                pCollectionNode = nullptr;
                break;
            }
        }
        else
        {
            const sDescTreeNode* pCollectionNodeToCheck = (const sDescTreeNode*)(GetCurrentUnitSet()[nUnitId].ChildNodes);

            nNodeCount = pCollectionNodeToCheck[nCollectionIndex].uChildAmt;

            if (nDistanceFromZero < nNodeCount)
            {
                // We know it's within this group.  Now: is it basic?
                if (!fReturnBasicNodesOnly || (nCollectionIndex < pButtonLabelSet.size()))
                {
                    pCollectionNode = &(pCollectionNodeToCheck[nCollectionIndex]);
                }
                else
                {
                    pCollectionNode = nullptr;
                }

                break;
            }
        }

        nDistanceFromZero -= nNodeCount;
    }

    return pCollectionNode;
}

void CGame_SF2CE_A::InitDataBuffer()
{
    m_nBufferSelectedRom = m_nSelectedRom;
    m_pppDataBuffer = new uint16_t * *[nUnitAmt];
    memset(m_pppDataBuffer, NULL, sizeof(uint16_t**) * nUnitAmt);
}

void CGame_SF2CE_A::ClearDataBuffer()
{
    int nCurrentROMMode = m_nSelectedRom;

    m_nSelectedRom = m_nBufferSelectedRom;

    if (m_pppDataBuffer)
    {
        for (uint32_t nUnitCtr = 0; nUnitCtr < nUnitAmt; nUnitCtr++)
        {
            if (m_pppDataBuffer[nUnitCtr])
            {
                uint32_t nPalAmt = GetPaletteCountForUnit(nUnitCtr);

                for (uint32_t nPalCtr = 0; nPalCtr < nPalAmt; nPalCtr++)
                {
                    safe_delete_array(m_pppDataBuffer[nUnitCtr][nPalCtr]);
                }

                safe_delete_array(m_pppDataBuffer[nUnitCtr]);
            }
        }

        safe_delete_array(m_pppDataBuffer);
    }

    m_nSelectedRom = nCurrentROMMode;
}

void CGame_SF2CE_A::LoadSpecificPaletteData(uint32_t nUnitId, uint32_t nPalId)
{
    if (nUnitId != GetCurrentExtraLoc())
    {
        int cbPaletteSizeOnDisc = 0;
        const sGame_PaletteDataset* paletteData = GetSpecificPalette(nUnitId, nPalId);

        cbPaletteSizeOnDisc = (int)max(0, (paletteData->nPaletteOffsetEnd - paletteData->nPaletteOffset));

        m_nCurrentPaletteROMLocation = paletteData->nPaletteOffset;

        m_nCurrentPaletteSizeInColors = cbPaletteSizeOnDisc / m_nSizeOfColorsInBytes;
        m_pszCurrentPaletteName = paletteData->szPaletteName;

        // Adjust for ROM-specific variant locations
        if (m_pCRC32SpecificData)
        {
            // There's a different shift in Japanese 22 ROMs above this location.
            bool isLocationLow = (m_nCurrentPaletteROMLocation < 0x19000);
            if (isLocationLow && (wcscmp(m_pCRC32SpecificData->szROMFileName, k_SF2CE_JapanROMName_RevA) == 0))
            {
                m_nCurrentPaletteROMLocation += 0x1b3c;
            }
            else if (isLocationLow && (wcscmp(m_pCRC32SpecificData->szROMFileName, k_SF2CE_JapanROMName_RevB) == 0))
            {
                m_nCurrentPaletteROMLocation += 0x1b4e;
            }
            else if (isLocationLow && (wcscmp(m_pCRC32SpecificData->szROMFileName, k_SF2CE_JapanROMName_RevC) == 0))
            {
                m_nCurrentPaletteROMLocation += 0x1b56;
            }
            else
            {
                m_nCurrentPaletteROMLocation += m_pCRC32SpecificData->nROMSpecificOffset;
            }
        }
    }
    else // SF2CE_A_EXTRALOC
    {
        // This is where we handle all the palettes added in via Extra.
        stExtraDef* pCurrDef = GetCurrentExtraDef(GetExtraLoc(nUnitId) + nPalId);

        m_nCurrentPaletteROMLocation = pCurrDef->uOffset;
        m_nCurrentPaletteSizeInColors = (pCurrDef->cbPaletteSize / m_nSizeOfColorsInBytes);
        m_pszCurrentPaletteName = pCurrDef->szDesc;
    }
}

BOOL CGame_SF2CE_A::UpdatePalImg(int Node01, int Node02, int Node03, int Node04)
{
    switch (m_nSelectedRom)
    {
    case 21:
        return _UpdatePalImg(SF2CE_A_21_UNITS, rgExtraCountAll_21, SF2CE_A_21_NUMUNIT, SF2CE_A_21_EXTRALOC, SF2CE_A_21_EXTRA_CUSTOM, Node01, Node02, Node03, Node03);
    case 22:
    default:
        return _UpdatePalImg(SF2CE_A_22_UNITS, rgExtraCountAll_22, SF2CE_A_22_NUMUNIT, SF2CE_A_22_EXTRALOC, SF2CE_A_22_EXTRA_CUSTOM, Node01, Node02, Node03, Node03);
    case 23:
        return _UpdatePalImg(SF2CE_A_23_UNITS, rgExtraCountAll_23, SF2CE_A_23_NUMUNIT, SF2CE_A_23_EXTRALOC, SF2CE_A_23_EXTRA_CUSTOM, Node01, Node02, Node03, Node03);
    }
}
