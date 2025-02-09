#pragma once
#include "GameClassByDir.h"
#include "SF2HF_A_DEF.h"

class CGame_SF2HF_A : public CGameClassByDir
{
private:
    enum class SF2HFLoadingKey
    {
        ROM21,
        ROM22,
        ROM23,
        SF30th,
    };

    static SF2HFLoadingKey m_eVersionToLoad;

    static inline const sDirectoryLoadingData m_sFileLoadingData_ROM21 =
    {
        {
            { L"s2tu_21.6f", 0x80000 },
        },
        FileReadType::Sequential,
    };

    static inline const sDirectoryLoadingData m_sFileLoadingData_ROM22 =
    {
        {
            { L"s2tu_22.7f", 0x80000 },
        },
        FileReadType::Sequential,
    };

    static inline const sDirectoryLoadingData m_sFileLoadingData_ROM23 =
    {
        {
            { L"s2tu_23.8f", 0x80000 },
        },
        FileReadType::Sequential,
    };

    static inline const sDirectoryLoadingData m_sFileLoadingData_SF30th =
    {
        {
            { L"bundleStreetFighterII_HF.mbundle", 0x7d191f },
        },
        FileReadType::Sequential,
    };

    const sCoreGameData m_sCoreGameData_ROM21
    {
        L"Street Fighter II' - Hyper Fighting",
        SF2HF_A,
        IMGDAT_SECTION_SF2,
        SF2HF_A_IMGIDS_USED,
        { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_16 },
        eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT,
        DEF_BUTTONLABEL_2_NORMAL_START,
        AlphaMode::GameDoesNotUseAlpha,
        ColMode::COLMODE_RGB444_BE,
        m_sFileLoadingData_ROM21,
        SF2HF_A_21_UNITS,
        ARRAYSIZE(SF2HF_A_21_UNITS),
        L"SF2HF-21e.txt",        // Extra filename
        43,                      // Count of palettes listed in the header
        0x93fe,                  // Lowest known location used for palettes
    };

    const sCoreGameData m_sCoreGameData_ROM22
    {
        L"Street Fighter II' - Hyper Fighting",
        SF2HF_A,
        IMGDAT_SECTION_SF2,
        SF2HF_A_IMGIDS_USED,
        { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_16 },
        eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT,
        DEF_BUTTONLABEL_2_NORMAL_START,
        AlphaMode::GameDoesNotUseAlpha,
        ColMode::COLMODE_RGB444_BE,
        m_sFileLoadingData_ROM22,
        SF2HF_A_22_UNITS,
        ARRAYSIZE(SF2HF_A_22_UNITS),
        L"SF2HF-22e.txt",        // Extra filename
        24,                      // Count of palettes listed in the header
        0x1e6a6,                 // Lowest known location used for palettes
    };

    const sCoreGameData m_sCoreGameData_ROM23
    {
        L"Street Fighter II' - Hyper Fighting",
        SF2HF_A,
        IMGDAT_SECTION_SF2,
        SF2HF_A_IMGIDS_USED,
        { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_16 },
        eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT,
        DEF_BUTTONLABEL_2_NORMAL_START,
        AlphaMode::GameDoesNotUseAlpha,
        ColMode::COLMODE_RGB444_BE,
        m_sFileLoadingData_ROM23,
        SF2HF_A_23_UNITS,
        ARRAYSIZE(SF2HF_A_23_UNITS),
        L"SF2HF-23e.txt",        // Extra filename
        17,                      // Count of palettes listed in the header
        0x2e748,                 // Lowest known location used for palettes
    };

    const sCoreGameData m_sCoreGameData_SF30th
    {
        L"Street Fighter II' - Hyper Fighting (30th Anniversary)",
        SF2HF_A,
        IMGDAT_SECTION_SF2,
        SF2HF_A_IMGIDS_USED,
        { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_16 },
        eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT,
        DEF_BUTTONLABEL_2_NORMAL_START,
        AlphaMode::GameDoesNotUseAlpha,
        ColMode::COLMODE_RGB444_LE,
        m_sFileLoadingData_SF30th,
        SF2HF_A_22_UNITS,
        ARRAYSIZE(SF2HF_A_22_UNITS),
        L"SF2HF-22e.txt",        // Extra filename
        24,                      // Count of palettes listed in the header
        0x1e6a6,                 // Lowest known location used for palettes
    };

public:
    CGame_SF2HF_A(uint32_t nConfirmedROMSize);

    static void SetSpecialRuleForFileName(std::wstring strFileName);

    uint32_t GetKnownCRC32DatasetsForGame(const sCRC32ValueSet** ppKnownROMSet = nullptr, bool* pfNeedToValidateCRCs = nullptr) override;

    static sFileRule GetRule(uint32_t nRuleId);
};
