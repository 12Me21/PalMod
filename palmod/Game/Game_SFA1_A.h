#pragma once
#include "GameClassByDir.h"
#include "SFA1_A_DEF.h"

class CGame_SFA1_A : public CGameClassByDir
{
private:
    static inline const sDirectoryLoadingData m_sFileLoadingData =
    {
        {
            { L"sfz.06", 0x80000 },
        },
        FileReadType::Sequential,
    };

    const sCoreGameData m_sCoreGameData
    {
        L"SFA1 (CPS2)",
        SFA1_A,
        IMGDAT_SECTION_CPS2,
        SFA1_A_IMGIDS_USED,
        { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_16 },
        eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT,
        DEF_BUTTONLABEL_2_PK,
        AlphaMode::GameDoesNotUseAlpha,
        ColMode::COLMODE_RGB444_BE,
        m_sFileLoadingData,
        SFA1_A_UNITS,
        ARRAYSIZE(SFA1_A_UNITS),
        L"SFA1e.txt",             // Extra filename
        245,                        // Count of palettes listed in the header
        0x6795e,                   // Lowest known location used for palettes
    };

    static void DumpHeaderPalettes();

public:
    CGame_SFA1_A(uint32_t nConfirmedROMSize) { InitializeGame(nConfirmedROMSize, m_sCoreGameData); };

    uint32_t GetKnownCRC32DatasetsForGame(const sCRC32ValueSet** ppKnownROMSet = nullptr, bool* pfNeedToValidateCRCs = nullptr) override;

    BOOL UpdatePalImg(int Node01, int Node02, int Node03, int Node04);

    static sFileRule GetRule(uint32_t nRuleId) { return CGameClassByDir::GetRule(nRuleId, m_sFileLoadingData); };
};
