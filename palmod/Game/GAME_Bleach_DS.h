#pragma once
#include "GameClassByDir.h"
#include "Bleach_DS_DEF.h"

class CGame_BLEACH_DS : public CGameClassByDir
{
private:
    static inline const sDirectoryLoadingData m_sFileLoadingData =
    {
        {
            { L"047-p1.bin", 0x8000000 },
        },
        FileReadType::Sequential,
    };

    const sCoreGameData m_sCoreGameData
    {
        L"Bleach DS (Europe - Nintendo DS)",
        BLEACH_DS,
        IMGDAT_SECTION_DS,
        BLEACH_DS_IMGIDS_USED,
        { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_16 },
        eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT,
        DEF_BUTTONLABEL_BLEACH,
        AlphaMode::GameDoesNotUseAlpha,
        ColMode::COLMODE_BGR555_LE,
        m_sFileLoadingData,
        BLEACH_DS_UNITS,
        ARRAYSIZE(BLEACH_DS_UNITS),
        L"BleachDSE.txt",               // Extra filename
        988,                            // Count of palettes listed in the header
        0x1fd2fa0,                      // Lowest known location used for palettes
    };

public:
    CGame_BLEACH_DS(uint32_t nConfirmedROMSize) { InitializeGame(nConfirmedROMSize, m_sCoreGameData); };

    uint32_t GetKnownCRC32DatasetsForGame(const sCRC32ValueSet** ppKnownROMSet = nullptr, bool* fNeedToValidateCRCs = nullptr) override;

    static sFileRule GetRule(uint32_t nRuleId) { return CGameClassByDir::GetRule(nRuleId, m_sFileLoadingData); };
};
