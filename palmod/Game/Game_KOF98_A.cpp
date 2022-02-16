#include "StdAfx.h"
#include "GameDef.h"
#include "Game_KOF98_A.h"
#include "..\PalMod.h"
#include "..\RegProc.h"

stExtraDef* CGame_KOF98_A::KOF98_A_EXTRA_CUSTOM = nullptr;

CDescTree CGame_KOF98_A::MainDescTree = nullptr;

uint32_t CGame_KOF98_A::rgExtraCountAll[KOF98_A_NUMUNIT + 1];
uint32_t CGame_KOF98_A::rgExtraLoc[KOF98_A_NUMUNIT + 1];

UINT32 CGame_KOF98_A::m_nTotalPaletteCountForKOF98 = 0;
UINT32 CGame_KOF98_A::m_nExpectedGameROMSize = 0x400000;  // 4194304 bytes
UINT32 CGame_KOF98_A::m_nConfirmedROMSize = -1;

void CGame_KOF98_A::InitializeStatics()
{
    safe_delete_array(CGame_KOF98_A::KOF98_A_EXTRA_CUSTOM);

    memset(rgExtraCountAll, -1, sizeof(rgExtraCountAll));
    memset(rgExtraLoc, -1, sizeof(rgExtraLoc));

    MainDescTree.SetRootTree(CGame_KOF98_A::InitDescTree());
}

CGame_KOF98_A::CGame_KOF98_A(UINT32 nConfirmedROMSize)
{
    OutputDebugString(L"CGame_KOF98_A::CGame_KOF98_A: Loading ROM...\n");

    createPalOptions = { NO_SPECIAL_OPTIONS, WRITE_16 };
    SetAlphaMode(AlphaMode::GameDoesNotUseAlpha);
    SetColorMode(ColMode::COLMODE_RGB666_NEOGEO);

    // We need this set before we initialize so that corrupt Extras truncate correctly.
    // Otherwise the new user inadvertently corrupts their ROM.
    m_nConfirmedROMSize = nConfirmedROMSize;
    InitializeStatics();

    m_nTotalInternalUnits = KOF98_A_NUMUNIT;
    m_nExtraUnit = KOF98_A_EXTRALOC;

    m_nSafeCountForThisRom = GetExtraCt(m_nExtraUnit) + 1974;
    m_pszExtraFilename = EXTRA_FILENAME_KOF98_A;
    m_nTotalPaletteCount = m_nTotalPaletteCountForKOF98;
    // This magic number is used to warn users if their Extra file is trying to write somewhere potentially unusual
    m_nLowestKnownPaletteRomLocation = 0x2d8210;

    nUnitAmt = m_nTotalInternalUnits + (GetExtraCt(m_nExtraUnit) ? 1 : 0);

    InitDataBuffer();

    //Set game information
    nGameFlag = KOF98_A;
    nImgGameFlag = IMGDAT_SECTION_KOF;
    m_prgGameImageSet = KOF98_A_IMGIDS_USED;

    nFileAmt = 1;

    //Set the image out display type
    DisplayType = eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT;
    // Button labels are used for the Export Image dialog
    pButtonLabelSet = DEF_BUTTONLABEL_NEOGEO;

    //Create the redirect buffer
    rgUnitRedir = new uint32_t[nUnitAmt + 1];
    memset(rgUnitRedir, NULL, sizeof(uint32_t) * nUnitAmt);

    //Create the file changed flag
    PrepChangeTrackingArray();
}

CGame_KOF98_A::~CGame_KOF98_A(void)
{
    safe_delete_array(CGame_KOF98_A::KOF98_A_EXTRA_CUSTOM);
    ClearDataBuffer();
    //Get rid of the file changed flag
    FlushChangeTrackingArray();
}

CDescTree* CGame_KOF98_A::GetMainTree()
{
    return &CGame_KOF98_A::MainDescTree;
}

UINT32 CGame_KOF98_A::GetKnownCRC32DatasetsForGame(const sCRC32ValueSet** ppKnownROMSet, bool* pfNeedToValidateCRCs)
{
    static sCRC32ValueSet knownROMs[] =
    {
        // There are three unique ROM sets, but the first two share the same palette file,
        // and the third one we don't care about.
        { L"King of Fighters '98 (Neo-Geo)", L"242-p2.sp2", 0x980aba4c, 0 },
        { L"King of Fighters '98 (Neo-Geo)", L"kof98_p2.rom", 0x980aba4c, 0 },
        { L"King of Fighters '98 (Neo-Geo Alt)", L"242-ep.ep2", 0x6e474841, 0 },
        { L"King of Fighters '98 Combo (Neo-Geo Hack)", L"242cb-p2.sp2", 0xd34a4d38, 0 },
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

#ifdef NOTES
    // These are the MAME values...
    <software name = "kof98">
        <description>The King of Fighters '98 - The Slugfest / King of Fighters '98 - Dream Match Never Ends(NGM - 2420) </description>
            <rom loadflag="load16_word_swap" name="242-p2.sp2" offset="0x200000" size="0x400000" crc="980aba4c" sha1="5e735929ec6c3ca5b2efae3c7de47bcbb8ade2c5" />  <!--TC5332205-->

	<software name="kof98k" cloneof="kof98">
		<description>The King of Fighters '98 - The Slugfest / King of Fighters '98 - Dream Match Never Ends (Korean board, set 1)</description>
			<rom loadflag="load16_word_swap" name="242-p2.sp2" offset="0x200000" size="0x400000" crc="980aba4c" sha1="5e735929ec6c3ca5b2efae3c7de47bcbb8ade2c5" />  <!-- TC5332205 -->

	<software name="kof98ka" cloneof="kof98">
		<description>The King of Fighters '98 - The Slugfest / King of Fighters '98 - Dream Match Never Ends (Korean board, set 2)</description>
			<rom loadflag="load16_word_swap" name="242-p2.sp2" offset="0x200000" size="0x400000" crc="980aba4c" sha1="5e735929ec6c3ca5b2efae3c7de47bcbb8ade2c5" />  <!-- TC5332205 -->

	<software name="kof98h" cloneof="kof98">
		<description>The King of Fighters '98 - The Slugfest / King of Fighters '98 - Dream Match Never Ends (NGH-2420)</description>
				<rom loadflag="load16_word_swap" name="242-p2.sp2" offset="0x100000" size="0x400000" crc="980aba4c" sha1="5e735929ec6c3ca5b2efae3c7de47bcbb8ade2c5" />  <!-- TC5332205 -->

	<software name="kof98a" cloneof="kof98">
		<description>The King of Fighters '98 - The Slugfest / King of Fighters '98 - Dream Match Never Ends (NGM-2420, alt board)</description>
				<rom loadflag="load16_word_swap" name="242-ep2.ep2" offset="0x400000" size="0x200000" crc="6e474841" sha1="0ce401277f9c53435ea00b930efe361c8d25a7d9" /> <!-- M27C160 -->
#endif
}

uint32_t CGame_KOF98_A::GetExtraCt(uint32_t nUnitId, BOOL fCountVisibleOnly)
{
    return _GetExtraCount(rgExtraCountAll, KOF98_A_NUMUNIT, nUnitId, KOF98_A_EXTRA_CUSTOM);
}

uint32_t CGame_KOF98_A::GetExtraLoc(uint32_t nUnitId)
{
    return _GetExtraLocation(rgExtraLoc, KOF98_A_NUMUNIT, nUnitId, KOF98_A_EXTRA_CUSTOM);
}

sDescTreeNode* CGame_KOF98_A::InitDescTree()
{
    //Load extra file if we're using it
    LoadExtraFileForGame(EXTRA_FILENAME_KOF98_A, &KOF98_A_EXTRA_CUSTOM, KOF98_A_EXTRALOC, m_nConfirmedROMSize);

    UINT16 nUnitCt = KOF98_A_NUMUNIT + (GetExtraCt(KOF98_A_EXTRALOC) ? 1 : 0);
    
    sDescTreeNode* NewDescTree = new sDescTreeNode;

    //Create the main character tree
    _snwprintf_s(NewDescTree->szDesc, ARRAYSIZE(NewDescTree->szDesc), _TRUNCATE, L"%s", g_GameFriendlyName[KOF98_A]);
    NewDescTree->ChildNodes = new sDescTreeNode[nUnitCt];
    NewDescTree->uChildAmt = nUnitCt;
    //All units have tree children
    NewDescTree->uChildType = DESC_NODETYPE_TREE;

    m_nTotalPaletteCountForKOF98 = _InitDescTree(NewDescTree,
        KOF98_A_UNITS,
        KOF98_A_EXTRALOC,
        KOF98_A_NUMUNIT,
        rgExtraCountAll,
        rgExtraLoc,
        KOF98_A_EXTRA_CUSTOM
    );

    // For development use to speed things up
    //DumpPaletteHeaders();

    return NewDescTree;
}

struct sKOF98_A_PaletteData
{
    LPCWSTR pszCharacterName;
    UINT32 nROMOffset = 0;
    LPCWSTR pszImageSet = L"indexKOF98Sprites_Kyo";
    bool rgIsEffectUsed[11];
};

sKOF98_A_PaletteData KOF98_A_CharacterEffectPalettes[] =
{
    // These effects use a random number of palettes per character.  The rgIsEffectUsed array keeps track of this for us.
    // Note that the Orochi characters share the same effects as the normal character.
    //                                                                            1  2  3  4  5  6  7  8  9  a  b
    { L"Kyo",        0x2ee7f0 + (0x200 *  0), L"indexKOF98Sprites_Kyo",        { 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0 } },
    { L"Benimaru",   0x2ee7f0 + (0x200 *  1), L"indexKOF98Sprites_Benimaru",   { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 } },
    { L"Daimon",     0x2ee7f0 + (0x200 *  2), L"indexKOF98Sprites_Daimon",     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { L"Terry",      0x2ee7f0 + (0x200 *  3), L"indexKOF98Sprites_Terry",      { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 } },
    { L"Andy",       0x2ee7f0 + (0x200 *  4), L"indexKOF98Sprites_Andy",       { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 } },
    { L"Joe",        0x2ee7f0 + (0x200 *  5), L"indexKOF98Sprites_Joe",        { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 } },
    { L"Ryo",        0x2ee7f0 + (0x200 *  6), L"indexKOF98Sprites_Ryo",        { 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 } },
    { L"Robert",     0x2ee7f0 + (0x200 *  7), L"indexKOF98Sprites_Robert",     { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 } },
    { L"Yuri",       0x2ee7f0 + (0x200 *  8), L"indexKOF98Sprites_Yuri",       { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 } },
    { L"Leona",      0x2ee7f0 + (0x200 *  9), L"indexKOF98Sprites_Leona",      { 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 } },
    { L"Ralf",       0x2ee7f0 + (0x200 * 10), L"indexKOF98Sprites_Ralf",       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { L"Clark",      0x2ee7f0 + (0x200 * 11), L"indexKOF98Sprites_Clark",      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { L"Athena",     0x2ee7f0 + (0x200 * 12), L"indexKOF98Sprites_Athena",     { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 } },
    { L"Kensou",     0x2ee7f0 + (0x200 * 13), L"indexKOF98Sprites_Kensou",     { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 } },
    { L"Chin",       0x2ee7f0 + (0x200 * 14), L"indexKOF98Sprites_Chin",       { 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 } },
    { L"Chizuru",    0x2ee7f0 + (0x200 * 15), L"indexKOF98Sprites_Chizuru",    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { L"Mai",        0x2ee7f0 + (0x200 * 16), L"indexKOF98Sprites_Mai",        { 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0 } },
    { L"King",       0x2ee7f0 + (0x200 * 17), L"indexKOF98Sprites_King",       { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { L"Kim",        0x2ee7f0 + (0x200 * 18), L"indexKOF98Sprites_Kim",        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { L"Chang",      0x2ee7f0 + (0x200 * 19), L"indexKOF98Sprites_Chang",      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { L"Choi",       0x2ee7f0 + (0x200 * 20), L"indexKOF98Sprites_Choi",       { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { L"Yashiro",    0x2ee7f0 + (0x200 * 21), L"indexKOF98Sprites_Yashiro",    { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 } },
    { L"Shermie",    0x2ee7f0 + (0x200 * 22), L"indexKOF98Sprites_Shermie",    { 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1 } },
    { L"Chris",      0x2ee7f0 + (0x200 * 23), L"indexKOF98Sprites_Chris",      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } },
    { L"Yamazaki",   0x2ee7f0 + (0x200 * 24), L"indexKOF98Sprites_Yamazaki",   { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 } },
    { L"Blue Mary",  0x2ee7f0 + (0x200 * 25), L"indexKOF98Sprites_BlueMary",   { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { L"Billy",      0x2ee7f0 + (0x200 * 26), L"indexKOF98Sprites_Billy",      { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1 } },
    { L"Iori",       0x2ee7f0 + (0x200 * 27), L"indexKOF98Sprites_Iori",       { 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0 } },
    { L"Mature",     0x2ee7f0 + (0x200 * 28), L"indexKOF98Sprites_Mature",     { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 } },
    { L"Vice",       0x2ee7f0 + (0x200 * 29), L"indexKOF98Sprites_Vice",       { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1 } },
    { L"Heidern",    0x2ee7f0 + (0x200 * 30), L"indexKOF98Sprites_Heidern",    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } },
    { L"Takuma",     0x2ee7f0 + (0x200 * 31), L"indexKOF98Sprites_Takuma",     { 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 } },
    { L"Saisyu",     0x2ee7f0 + (0x200 * 32), L"indexKOF98Sprites_Saisyu",     { 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0 } },
    { L"Heavy D!",   0x2ee7f0 + (0x200 * 33), L"indexKOF98Sprites_HeavyD",     { 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 } },
    { L"Lucky",      0x2ee7f0 + (0x200 * 34), L"indexKOF98Sprites_Lucky",      { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 } },
    { L"Brian",      0x2ee7f0 + (0x200 * 35), L"indexKOF98Sprites_Brian",      { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 } },
    { L"Rugal",      0x2ee7f0 + (0x200 * 36), L"indexKOF98Sprites_Rugal",      { 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0 } },
    { L"Shingo",     0x2ee7f0 + (0x200 * 37), L"indexKOF98Sprites_Shingo",     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { L"Omega Rugal", 0x2ee7f0 + (0x200* 38), L"indexKOF98Sprites_OmegaRugal", { 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1 } },
    //                                                                            1  2  3  4  5  6  7  8  9  a  b
};

void CGame_KOF98_A::DumpPaletteHeaders()
{
    CString strOutput;
    const UINT16 nColorOptionsPerCharacter = 4;
    constexpr UINT32 KOF98_PALETTE_LENGTH = 0x20;
    const UINT16 nCountStatusEffects = 16;

    for (UINT16 nCharIndex = 0; nCharIndex < ARRAYSIZE(KOF98_A_CharacterEffectPalettes); nCharIndex++)
    {
        WCHAR szCodeDesc[MAX_DESCRIPTION_LENGTH];
        StruprRemoveNonASCII(szCodeDesc, ARRAYSIZE(szCodeDesc), KOF98_A_CharacterEffectPalettes[nCharIndex].pszCharacterName);

        strOutput.Format(L"const sGame_PaletteDataset KOF98_A_%s_EFFECT_PALETTES[] = \r\n{\r\n", szCodeDesc);
        OutputDebugString(strOutput);

        // Status effects
        for (UINT16 nStatusIndex = 0; nStatusIndex < nCountStatusEffects; nStatusIndex++)
        {
            UINT32 nCurrentOffset = KOF98_A_CharacterEffectPalettes[nCharIndex].nROMOffset + (nStatusIndex * KOF98_PALETTE_LENGTH);
            switch (nStatusIndex)
            {
            default:
                if (KOF98_A_CharacterEffectPalettes[nCharIndex].rgIsEffectUsed[nStatusIndex])
                {
                    strOutput.Format(L"    { L\"Effect %u\", 0x%x, 0x%x },\r\n", nStatusIndex, nCurrentOffset, nCurrentOffset + KOF98_PALETTE_LENGTH);
                        OutputDebugString(strOutput);
                }
                break;
            case 11:
                strOutput.Format(L"    { L\"Zap Effect 1\", 0x%x, 0x%x, %s },\r\n", nCurrentOffset, nCurrentOffset + KOF98_PALETTE_LENGTH,
                    KOF98_A_CharacterEffectPalettes[nCharIndex].pszImageSet);
                OutputDebugString(strOutput);
                break;
            case 12:
                strOutput.Format(L"    { L\"Zap Effect 2\", 0x%x, 0x%x, %s },\r\n", nCurrentOffset, nCurrentOffset + KOF98_PALETTE_LENGTH,
                    KOF98_A_CharacterEffectPalettes[nCharIndex].pszImageSet);
                OutputDebugString(strOutput);
                break;
            case 13:
                strOutput.Format(L"    { L\"Super Trail 1\", 0x%x, 0x%x, %s },\r\n", nCurrentOffset, nCurrentOffset + KOF98_PALETTE_LENGTH,
                    KOF98_A_CharacterEffectPalettes[nCharIndex].pszImageSet);
                OutputDebugString(strOutput);
                break;
            case 14:
                strOutput.Format(L"    { L\"Super Trail 2\", 0x%x, 0x%x, %s },\r\n", nCurrentOffset, nCurrentOffset + KOF98_PALETTE_LENGTH,
                    KOF98_A_CharacterEffectPalettes[nCharIndex].pszImageSet);
                OutputDebugString(strOutput);
                break;
            case 15:
                strOutput.Format(L"    { L\"Super Trail 3\", 0x%x, 0x%x, %s },\r\n", nCurrentOffset, nCurrentOffset + KOF98_PALETTE_LENGTH,
                    KOF98_A_CharacterEffectPalettes[nCharIndex].pszImageSet);
                OutputDebugString(strOutput);
                break;
            };
        }

        OutputDebugString(L"};\r\n\r\n");
    }

    for (UINT16 nCharIndex = 0; nCharIndex < ARRAYSIZE(KOF98_A_CharacterEffectPalettes); nCharIndex++)
    {
        WCHAR szCodeDesc[MAX_DESCRIPTION_LENGTH];
        StruprRemoveNonASCII(szCodeDesc, ARRAYSIZE(szCodeDesc), KOF98_A_CharacterEffectPalettes[nCharIndex].pszCharacterName);

        strOutput.Format(L"const sDescTreeNode KOF98_A_%s_COLLECTION[] = \r\n{\r\n", szCodeDesc);
        OutputDebugString(strOutput);

        for (UINT16 nColorIndex = 0; nColorIndex < nColorOptionsPerCharacter; nColorIndex++)
        {
            WCHAR szColorOptionCodeDesc[MAX_DESCRIPTION_LENGTH];
            StruprRemoveNonASCII(szColorOptionCodeDesc, ARRAYSIZE(szColorOptionCodeDesc), DEF_BUTTONLABEL_NEOGEO[nColorIndex]);

            strOutput.Format(L"    { L\"%s\", DESC_NODETYPE_TREE, (void*)KOF98_A_%s_%s_PALETTES, ARRAYSIZE(KOF98_A_%s_%s_PALETTES) },\r\n", DEF_BUTTONLABEL_NEOGEO[nColorIndex], szCodeDesc, szColorOptionCodeDesc, szCodeDesc, szColorOptionCodeDesc);
            OutputDebugString(strOutput);
        }

        strOutput.Format(L"    { L\"Effects\", DESC_NODETYPE_TREE, (void*)KOF98_A_%s_EFFECT_PALETTES, ARRAYSIZE(KOF98_A_%s_EFFECT_PALETTES) },\r\n", szCodeDesc, szCodeDesc);
        OutputDebugString(strOutput);
        OutputDebugString(L"};\r\n\r\n");
    }
}

sFileRule CGame_KOF98_A::GetRule(uint32_t nUnitId)
{
    sFileRule NewFileRule;

    // This value is only used for directory-based games
    _snwprintf_s(NewFileRule.szFileName, ARRAYSIZE(NewFileRule.szFileName), _TRUNCATE, L"242-p2.sp2");

    NewFileRule.uUnitId = 0;
    NewFileRule.uVerifyVar = m_nExpectedGameROMSize;

    return NewFileRule;
}

uint32_t CGame_KOF98_A::GetCollectionCountForUnit(uint32_t nUnitId)
{
    return _GetCollectionCountForUnit(KOF98_A_UNITS, rgExtraCountAll, KOF98_A_NUMUNIT, KOF98_A_EXTRALOC, nUnitId, KOF98_A_EXTRA_CUSTOM);
}

uint32_t CGame_KOF98_A::GetNodeCountForCollection(uint32_t nUnitId, uint32_t nCollectionId)
{
    return _GetNodeCountForCollection(KOF98_A_UNITS, rgExtraCountAll, KOF98_A_NUMUNIT, KOF98_A_EXTRALOC, nUnitId, nCollectionId, KOF98_A_EXTRA_CUSTOM);
}

LPCWSTR CGame_KOF98_A::GetDescriptionForCollection(uint32_t nUnitId, uint32_t nCollectionId)
{
    return _GetDescriptionForCollection(KOF98_A_UNITS, KOF98_A_EXTRALOC, nUnitId, nCollectionId);
}

uint32_t CGame_KOF98_A::GetPaletteCountForUnit(uint32_t nUnitId)
{
    return _GetPaletteCountForUnit(KOF98_A_UNITS, rgExtraCountAll, KOF98_A_NUMUNIT, KOF98_A_EXTRALOC, nUnitId, KOF98_A_EXTRA_CUSTOM);
}

const sGame_PaletteDataset* CGame_KOF98_A::GetPaletteSet(uint32_t nUnitId, uint32_t nCollectionId)
{
    return _GetPaletteSet(KOF98_A_UNITS, nUnitId, nCollectionId);
}

const sDescTreeNode* CGame_KOF98_A::GetNodeFromPaletteId(uint32_t nUnitId, uint32_t nPaletteId, bool fReturnBasicNodesOnly)
{
    return _GetNodeFromPaletteId(KOF98_A_UNITS, rgExtraCountAll, KOF98_A_NUMUNIT, KOF98_A_EXTRALOC, nUnitId, nPaletteId, KOF98_A_EXTRA_CUSTOM, fReturnBasicNodesOnly);
}

const sGame_PaletteDataset* CGame_KOF98_A::GetSpecificPalette(uint32_t nUnitId, uint32_t nPaletteId)
{
    return _GetSpecificPalette(KOF98_A_UNITS, rgExtraCountAll, KOF98_A_NUMUNIT, KOF98_A_EXTRALOC, nUnitId, nPaletteId, KOF98_A_EXTRA_CUSTOM);
}

void CGame_KOF98_A::LoadSpecificPaletteData(uint32_t nUnitId, uint32_t nPalId)
{
     if (nUnitId != KOF98_A_EXTRALOC)
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
    else // KOF98_A_EXTRALOC
    {
        // This is where we handle all the palettes added in via Extra.
        stExtraDef* pCurrDef = GetExtraDefForKOF98(GetExtraLoc(nUnitId) + nPalId);

        m_nCurrentPaletteROMLocation = pCurrDef->uOffset;
        m_nCurrentPaletteSizeInColors = (pCurrDef->cbPaletteSize / m_nSizeOfColorsInBytes);
        m_pszCurrentPaletteName = pCurrDef->szDesc;
    }
}

BOOL CGame_KOF98_A::UpdatePalImg(int Node01, int Node02, int Node03, int Node04)
{
    return _UpdatePalImg(KOF98_A_UNITS, rgExtraCountAll, KOF98_A_NUMUNIT, KOF98_A_EXTRALOC, KOF98_A_EXTRA_CUSTOM, Node01, Node02, Node03, Node03);
}
