#include "StdAfx.h"
#include "Game_MWarr_A_DIR.h"
#include "GameDef.h"

const sDirectoryLoadingData MWarrFileLoadingData =
{
    {
        L"prg_ev",
        L"prg_od"
    },
    FileReadType::Interleaved,
    0x80000
};

sFileRule CGame_MWarr_A_DIR::GetRule(uint32_t nUnitId)
{
    sFileRule NewFileRule;

    _snwprintf_s(NewFileRule.szFileName, ARRAYSIZE(NewFileRule.szFileName), _TRUNCATE, L"%s", MWarrFileLoadingData.rgstrFileList.at(nUnitId & 0xFF).c_str());
    NewFileRule.uUnitId = nUnitId;
    NewFileRule.uVerifyVar = (short int)-1;

    return NewFileRule;
}

sFileRule CGame_MWarr_A_DIR::GetNextRule()
{
    sFileRule NewFileRule = GetRule(uRuleCtr++);

    if (uRuleCtr >= MWarrFileLoadingData.rgstrFileList.size())
    {
        uRuleCtr = INVALID_UNIT_VALUE;
    }

    return NewFileRule;
}

CGame_MWarr_A_DIR::CGame_MWarr_A_DIR(uint32_t nConfirmedROMSize)
{
    //Set game-game specific information before loading the game's known palette locations
    m_snCurrentGameFlag = nGameFlag = MWARR_A;
    nImgGameFlag = IMGDAT_SECTION_OTHER;
    m_prgGameImageSet = MWarr_A_IMGIDS_USED;
    createPalOptions = { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_MAX };
    //Set the image out display type
    DisplayType = eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT;
    pButtonLabelSet = DEF_NOBUTTONS;
    SetAlphaMode(AlphaMode::GameDoesNotUseAlpha);
    SetColorMode(ColMode::COLMODE_BGR555_BE);

    // Load the game's layout for palmod
    InitializeStatics(MWarrFileLoadingData, MWarr_A_UNITS, ARRAYSIZE(MWarr_A_UNITS), m_strExtraFileName);

    // xoxoxoxxoxoxoxoxoxxoxoxoxoxoxoxoxxoxoxoxxoxoxoxoxoxxoxoxoxoxoxoxox
    // Everything after this is boilerplate and doesn't need to be changed.
    // xoxoxoxxoxoxoxoxoxxoxoxoxoxoxoxoxxoxoxoxxoxoxoxoxoxxoxoxoxoxoxoxox

    // We need this set before we initialize so that corrupt Extras truncate correctly.
    // Otherwise the new user inadvertently corrupts their ROM.
    m_pszExtraFilename = m_strCurrentExtraFilename.c_str();

    //We need the proper unit amt before we init the main buffer
    m_nTotalInternalUnits = m_rgCurrentGameUnits.size();
    m_nExtraUnit = m_nCurrentExtraUnitId = static_cast<uint16_t>(m_rgCurrentGameUnits.size());
    // Tack on an extra unit if we're loading extras
    nUnitAmt = m_nTotalInternalUnits + (GetExtraCt(m_nExtraUnit) ? 1 : 0);

    // Game-specific safety checks: if these match what we find at runtime we skip our check for duplicated palettes
    m_nSafeCountForThisRom = GetExtraCt(m_nExtraUnit) + m_nPaletteCountInHeaders;
    m_nLowestKnownPaletteRomLocation = m_nLowestROMLocationUsedInHeaders;

    // Stub in the palette buffer that we will LoadFile into
    InitDataBuffer();

    // This lets LoadGame and SaveGame know how many files it needs to interact with
    nFileAmt = m_psCurrentFileLoadingData->rgstrFileList.size();

    //Create the redirect buffer
    rgUnitRedir = new uint32_t[nUnitAmt + 1];
    memset(rgUnitRedir, 0, sizeof(uint32_t) * nUnitAmt);

    //Create the file changed flag
    PrepChangeTrackingArray();
}

CGame_MWarr_A_DIR::~CGame_MWarr_A_DIR()
{
    //Get rid of the file changed flag
    ClearDataBuffer();
    FlushChangeTrackingArray();

    safe_delete_array(m_prgCurrentExtrasLoaded);
}
