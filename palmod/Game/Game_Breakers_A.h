#pragma once
#include "GameClassByDir.h"
#include "BREAKERS_A_DEF.h"

class CGame_BREAKERS_A : public CGameClassByDir
{
private:
    static inline const sDirectoryLoadingData m_sFileLoadingData =
    {
        {
            { L"245-p1.p1", 0x200000 },
        },
        FileReadType::Sequential,
    };

    const sCoreGameData m_sCoreGameData
    {
        L"Breakers Revenge (Neo-Geo)",
        BREAKERS_A,
        IMGDAT_SECTION_BREAKREV,
        BREAKERS_A_IMGIDS_USED,
        { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_16 },
        eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT,
        DEF_BUTTONLABEL_NEOGEO,
        AlphaMode::GameDoesNotUseAlpha,
        ColMode::COLMODE_RGB666_NEOGEO,
        m_sFileLoadingData,
        BREAKERS_A_UNITS,
        ARRAYSIZE(BREAKERS_A_UNITS),
        L"BreakersRevE.txt",             // Extra filename
        414,                            // Count of palettes listed in the header
        0x135e2a,                        // Lowest known location used for palettes
    };

    static void DumpAllCharacters();

public:
    CGame_BREAKERS_A(uint32_t nConfirmedROMSize) { InitializeGame(nConfirmedROMSize, m_sCoreGameData); };

    static sFileRule GetRule(uint32_t nRuleId) { return CGameClassByDir::GetRule(nRuleId, m_sFileLoadingData); };
};
