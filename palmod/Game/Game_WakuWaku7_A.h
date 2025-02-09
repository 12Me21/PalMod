#pragma once
#include "GameClassByDir.h"
#include "WakuWaku7_A_DEF.h"

class CGame_WakuWaku7_A : public CGameClassByDir
{
private:
    static inline const sDirectoryLoadingData m_sFileLoadingData =
    {
        {
            { L"225-p1.p1", 0x100000 },
        },
        FileReadType::Sequential,
    };

    const sCoreGameData m_sCoreGameData
    {
        L"Waku Waku 7 (Neo-Geo)",
        WakuWaku7_A,
        IMGDAT_SECTION_WAKUWAKU7,
        WAKUWAKU7_A_IMGIDS_USED,
        { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_MAX },
        eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT,
        DEF_BUTTONLABEL_WAKUWAKU7_FIVE,
        AlphaMode::GameDoesNotUseAlpha,
        ColMode::COLMODE_RGB666_NEOGEO,
        m_sFileLoadingData,
        WakuWaku7_A_UNITS,
        ARRAYSIZE(WakuWaku7_A_UNITS),
        L"WakuWaku7E.txt",             // Extra filename
        543,                           // Count of palettes listed in the header
        0xc8d8,                        // Lowest known location used for palettes
    };

public:
    CGame_WakuWaku7_A(uint32_t nConfirmedROMSize) { InitializeGame(nConfirmedROMSize, m_sCoreGameData); };

    BOOL UpdatePalImg(int Node01 = -1, int Node02 = -1, int Node03 = -1, int Node04 = -1);

    uint32_t GetKnownCRC32DatasetsForGame(const sCRC32ValueSet** ppKnownROMSet = nullptr, bool* pfNeedToValidateCRCs = nullptr) override;

    static sFileRule GetRule(uint32_t nRuleId) { return CGameClassByDir::GetRule(nRuleId, m_sFileLoadingData); };
};
