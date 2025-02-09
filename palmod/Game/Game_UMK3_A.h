#pragma once
#include "GameClassByDir.h"
#include "UMK3_A_DEF.h"

class CGame_UMK3_A : public CGameClassByDir
{
private:
    enum class UMK3ALoadingKey
    {
        V10,
        V11,
        V12Normal,
        V12Alt,
        V12Plus,
        V12PlusBeta,
        V12TE,
        V12UC,
        V12UK,
    };

    static UMK3ALoadingKey m_eVersionToLoad;

    static inline const sDirectoryLoadingData m_sFileLoadingData_V10 =
    {
        {
            { L"l1.0_mortal_kombat_3_u54_ultimate.u54", 0x80000 },
            { L"l1.0_mortal_kombat_3_u63_ultimate.u63", 0x80000 },
        },
        FileReadType::Interleaved_2FileSets,
    };

    static inline const sDirectoryLoadingData m_sFileLoadingData_V11 =
    {
        {
            { L"l1.1_mortal_kombat_3_u54_ultimate.u54", 0x80000 },
            { L"l1.1_mortal_kombat_3_u63_ultimate.u63", 0x80000 },
        },
        FileReadType::Interleaved_2FileSets,
    };

    static inline const sDirectoryLoadingData m_sFileLoadingData_V12Normal =
    {
        {
            { L"l1.2_mortal_kombat_3_u54_ultimate.u54", 0x80000 },
            { L"l1.2_mortal_kombat_3_u63_ultimate.u63", 0x80000 },
        },
        FileReadType::Interleaved_2FileSets,
    };

    static inline const sDirectoryLoadingData m_sFileLoadingData_V12Alt =
    {
        {
            { L"um312u54.bin", 0x80000 },
            { L"um312u63.bin", 0x80000 },
        },
        FileReadType::Interleaved_2FileSets,
    };

    static inline const sDirectoryLoadingData m_sFileLoadingData_V12Plus =
    {
        {
            { L"um312u54.bin", 0x80000 },
            { L"u63_umk3plus.u63", 0x80000 },
        },
        FileReadType::Interleaved_2FileSets,
    };

    static inline const sDirectoryLoadingData m_sFileLoadingData_V12PlusBeta =
    {
        {
            { L"um312u54.bin", 0x80000 },
            { L"umk3plus_beta1.u63", 0x80000 },
        },
        FileReadType::Interleaved_2FileSets,
    };

    static inline const sDirectoryLoadingData m_sFileLoadingData_V12TE =
    {
        {
            { L"um312u54.bin", 0x80000 },
            { L"umk3te.u63", 0x80000 },
        },
        FileReadType::Interleaved_2FileSets,
    };

    static inline const sDirectoryLoadingData m_sFileLoadingData_V12UC =
    {
        {
            { L"um312u54.bin", 0x80000 },
            { L"umk3uc-u63.bin", 0x80000 },
        },
        FileReadType::Interleaved_2FileSets,
    };

    static inline const sDirectoryLoadingData m_sFileLoadingData_V12UK =
    {
        {
            { L"um312u54.bin", 0x80000 },
            { L"umk3uk-u63.bin", 0x80000 },
        },
        FileReadType::Interleaved_2FileSets,
    };

    const sCoreGameData m_sCoreGameData_V10
    {
        L"Ultimate Mortal Kombat 3 (rev 1.0)",
        UMK3_A,
        IMGDAT_SECTION_OTHER,
        UMK3_A_IMGIDS_USED,
        { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_MAX },
        eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT,
        DEF_BUTTONLABEL_2,
        AlphaMode::GameDoesNotUseAlpha,
        ColMode::COLMODE_RGB555_BE,
        m_sFileLoadingData_V10,
        UMK3_A_UNITS,
        ARRAYSIZE(UMK3_A_UNITS),
        L"UMK3_A_E.txt",             // Extra filename
        49,                         // Count of palettes listed in the header
        0x60b3c,                    // Lowest known location used for palettes
    };

    const sCoreGameData m_sCoreGameData_V11
    {
        L"Ultimate Mortal Kombat 3 (rev 1.1)",
        UMK3_A,
        IMGDAT_SECTION_OTHER,
        UMK3_A_IMGIDS_USED,
        { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_MAX },
        eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT,
        DEF_BUTTONLABEL_2,
        AlphaMode::GameDoesNotUseAlpha,
        ColMode::COLMODE_RGB555_BE,
        m_sFileLoadingData_V11,
        UMK3_A_UNITS,
        ARRAYSIZE(UMK3_A_UNITS),
        L"UMK3_A_E.txt",             // Extra filename
        49,                         // Count of palettes listed in the header
        0x60b3c,                    // Lowest known location used for palettes
    };

    const sCoreGameData m_sCoreGameData_V12Normal
    {
        L"Ultimate Mortal Kombat 3 (rev 1.2)",
        UMK3_A,
        IMGDAT_SECTION_OTHER,
        UMK3_A_IMGIDS_USED,
        { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_MAX },
        eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT,
        DEF_BUTTONLABEL_2,
        AlphaMode::GameDoesNotUseAlpha,
        ColMode::COLMODE_RGB555_BE,
        m_sFileLoadingData_V12Normal,
        UMK3_A_UNITS,
        ARRAYSIZE(UMK3_A_UNITS),
        L"UMK3_A_E.txt",             // Extra filename
        49,                         // Count of palettes listed in the header
        0x60b3c,                    // Lowest known location used for palettes
    };

    const sCoreGameData m_sCoreGameData_V12Alt
    {
        L"Ultimate Mortal Kombat 3 (rev 1.2)",
        UMK3_A,
        IMGDAT_SECTION_OTHER,
        UMK3_A_IMGIDS_USED,
        { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_MAX },
        eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT,
        DEF_BUTTONLABEL_2,
        AlphaMode::GameDoesNotUseAlpha,
        ColMode::COLMODE_RGB555_BE,
        m_sFileLoadingData_V12Alt,
        UMK3_A_UNITS,
        ARRAYSIZE(UMK3_A_UNITS),
        L"UMK3_A_E.txt",             // Extra filename
        49,                         // Count of palettes listed in the header
        0x60b3c,                    // Lowest known location used for palettes
    };

    const sCoreGameData m_sCoreGameData_V12Plus
    {
        L"Ultimate Mortal Kombat 3 Plus (Hack, Beta 2)",
        UMK3_A,
        IMGDAT_SECTION_OTHER,
        UMK3_A_IMGIDS_USED,
        { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_MAX },
        eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT,
        DEF_BUTTONLABEL_2,
        AlphaMode::GameDoesNotUseAlpha,
        ColMode::COLMODE_RGB555_BE,
        m_sFileLoadingData_V12Plus,
        UMK3_A_UNITS,
        ARRAYSIZE(UMK3_A_UNITS),
        L"UMK3_A_E.txt",             // Extra filename
        49,                         // Count of palettes listed in the header
        0x60b3c,                    // Lowest known location used for palettes
    };

    const sCoreGameData m_sCoreGameData_V12PlusBeta
    {
        L"Ultimate Mortal Kombat 3 Plus (Hack, Beta 1)",
        UMK3_A,
        IMGDAT_SECTION_OTHER,
        UMK3_A_IMGIDS_USED,
        { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_MAX },
        eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT,
        DEF_BUTTONLABEL_2,
        AlphaMode::GameDoesNotUseAlpha,
        ColMode::COLMODE_RGB555_BE,
        m_sFileLoadingData_V12PlusBeta,
        UMK3_A_UNITS,
        ARRAYSIZE(UMK3_A_UNITS),
        L"UMK3_A_E.txt",             // Extra filename
        49,                         // Count of palettes listed in the header
        0x60b3c,                    // Lowest known location used for palettes
    };

    const sCoreGameData m_sCoreGameData_V12TE
    {
        L"Ultimate Mortal Kombat 3 Tournament Edition (hack)",
        UMK3_A,
        IMGDAT_SECTION_OTHER,
        UMK3_A_IMGIDS_USED,
        { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_MAX },
        eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT,
        DEF_BUTTONLABEL_2,
        AlphaMode::GameDoesNotUseAlpha,
        ColMode::COLMODE_RGB555_BE,
        m_sFileLoadingData_V12TE,
        UMK3_A_UNITS,
        ARRAYSIZE(UMK3_A_UNITS),
        L"UMK3_A_E.txt",             // Extra filename
        49,                         // Count of palettes listed in the header
        0x60b3c,                    // Lowest known location used for palettes
    };

    const sCoreGameData m_sCoreGameData_V12UC
    {
        L"Ultimate Mortal Kombat 3 Ultimate Cup Edition (hack)",
        UMK3_A,
        IMGDAT_SECTION_OTHER,
        UMK3_A_IMGIDS_USED,
        { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_MAX },
        eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT,
        DEF_BUTTONLABEL_2,
        AlphaMode::GameDoesNotUseAlpha,
        ColMode::COLMODE_RGB555_BE,
        m_sFileLoadingData_V12UC,
        UMK3_A_UNITS,
        ARRAYSIZE(UMK3_A_UNITS),
        L"UMK3_A_E.txt",             // Extra filename
        49,                         // Count of palettes listed in the header
        0x60b3c,                    // Lowest known location used for palettes
    };

    const sCoreGameData m_sCoreGameData_V12UK
    {
        L"Ultimate Mortal Kombat 3 UK (rev 1.2)",
        UMK3_A,
        IMGDAT_SECTION_OTHER,
        UMK3_A_IMGIDS_USED,
        { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_MAX },
        eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT,
        DEF_BUTTONLABEL_2,
        AlphaMode::GameDoesNotUseAlpha,
        ColMode::COLMODE_RGB555_BE,
        m_sFileLoadingData_V12UK,
        UMK3_A_UNITS,
        ARRAYSIZE(UMK3_A_UNITS),
        L"UMK3_A_E.txt",             // Extra filename
        49,                         // Count of palettes listed in the header
        0x60b3c,                    // Lowest known location used for palettes
    };

public:
    CGame_UMK3_A(uint32_t nConfirmedROMSize);

    static void SetSpecialRuleForFileName(std::wstring strFileName);

    uint32_t GetKnownCRC32DatasetsForGame(const sCRC32ValueSet** ppKnownROMSet = nullptr, bool* pfNeedToValidateCRCs = nullptr) override;

    static sFileRule GetRule(uint32_t nRuleId);
};
