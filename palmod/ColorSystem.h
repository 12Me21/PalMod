#pragma once

#define GetAValue(rgb)      (LOBYTE((rgb)>>24))

double LimitHLS(double a);
double SubHLS(double a);
UINT8 LimitRGB(int Val);

enum class AlphaMode
{
    GameDoesNotUseAlpha,    // No alpha value data present in colors
    GameUsesFixedAlpha,     // Alpha value is set and immutable
    Unknown,
    GameUsesVariableAlpha,  // Modifiable, as in the case of MvC2.
    GameUsesChaoticAlpha,   // Yes, this is odd.  ST-GBA appears to not have alpha consistently set.
};

enum class ColMode
{
    // If you add new color modes that users would want to use, you need to update CGame_NEOGEO_A::SetAlphaAndColorModeInternal
    // Don't change the order of this list: we emit copy strings that rely upon the ordering
    COLMODE_BGR555_LE,      // BGR555 little endian (GBA)
    COLMODE_RGB444_BE,      // RGB444 big endian (CPS1/2)
    COLMODE_RGB444_LE,      // RGB444 little endian (SF 30th steam)
    COLMODE_RGB555_LE,      // RGB555 little endian (CPS3)
    COLMODE_RGB555_BE,      // RGB555 big endian 
    COLMODE_RGB666_NEOGEO,  // RGB666 using the NeoGeo color table
    COLMODE_RGB333,         // RGB333 for Sega Genesis/MegaDrive
    COLMODE_RGBA8887,       // 32bit color half alpha (guilty gear)
    COLMODE_RGB555_SHARP,   // RGB555 using the sharp x68000 color table
    COLMODE_RGBA8881,       // 32bit color 1 bit alpha
    COLMODE_RGBA8888,       // 32bit color (uniclr. and modern computing)
    COLMODE_RGB888,         // 24bit
    COLMODE_BGR888,         // 24bit
    COLMODE_RGBA8881_32STEPS, // MBAACC: 32 bit color, except only 32 steps
    COLMODE_GRB555_LE,      // GRB555 little endian
    COLMODE_BGRA8888,       // 32bit color (arcana blood)
    COLMODE_BGR555_BE,      // BGR555 big endian: Motorola 68000 games
    COLMODE_GRB888,         // 24bit

    // This section added for development purposes: not needed for any games yet
    COLMODE_BGR333,         
    COLMODE_RBG333,
    COLMODE_BGR444,
    COLMODE_BRG444,
    COLMODE_RBG444,
    COLMODE_BRG888,

    COLMODE_LAST,
};

enum class ColFlag
{
    COL_RGB,
    COL_A,
};

ColMode DecodeColorFlag(UINT8 uPossibleColorFlag);
UINT8 GetCbForColMode(ColMode colorMode);
UINT8 GetCbForColorForGameFlag(UINT8 uGameFlag, UINT8 uPossibleColorFlag);

class CColorSystem
{
private:
    // These are the multipliers that can be used for color formats
    // so long as they don't use color lookup tables (CLUTs)
    static const double k_nRGBPlaneMulForRGB111;
    static const double k_nRGBPlaneMulForRGB333;
    static const double k_nRGBPlaneMulForRGB444;
    static const double k_nRGBPlaneMulForRGB555;
    static const double k_nRGBPlaneMulForRGB777;
    static const double k_nRGBPlaneMulForRGB888;

public:
    // These are the number of colors available for each color format
    static const int k_nRGBPlaneAmtForRGB111 = 1;
    static const int k_nRGBPlaneAmtForRGB333 = 7;
    static const int k_nRGBPlaneAmtForRGB444 = 15;
    static const int k_nRGBPlaneAmtForRGB555 = 31;
    // The 64 color NeoGeo color table is split bright/dark, but we only use bright
    static const int k_nRGBPlaneAmtForNeoGeo = 31;
    static const int k_nRGBPlaneAmtForHalfAlpha = 0x80;
    static const int k_nRGBPlaneAmtForRGB888 = 255;

    // 16-bit
    static UINT16 CONV_32_BGR333(UINT32 inCol);
    static UINT32 CONV_BGR333_32(UINT16 inCol);
    static UINT16 CONV_32_RBG333(UINT32 inCol);
    static UINT32 CONV_RBG333_32(UINT16 inCol);
    static UINT16 CONV_32_RGB333(UINT32 inCol);
    static UINT32 CONV_RGB333_32(UINT16 inCol);

    static UINT16 CONV_32_BGR444(UINT32 inCol);
    static UINT32 CONV_BGR444_32(UINT16 inCol);
    static UINT16 CONV_32_BRG444(UINT32 inCol);
    static UINT32 CONV_BRG444_32(UINT16 inCol);
    static UINT16 CONV_32_RBG444(UINT32 inCol);
    static UINT32 CONV_RBG444_32(UINT16 inCol);
    static UINT16 CONV_32_RGB444BE(UINT32 inCol);
    static UINT32 CONV_RGB444BE_32(UINT16 inCol);
    static UINT16 CONV_32_RGB444LE(UINT32 inCol);
    static UINT32 CONV_RGB444LE_32(UINT16 inCol);

    static UINT16 CONV_32_BGR555LE(UINT32 inCol);
    static UINT32 CONV_BGR555LE_32(UINT16 inCol);
    static UINT16 CONV_32_BGR555BE(UINT32 inCol);
    static UINT32 CONV_BGR555BE_32(UINT16 inCol);
    static UINT16 CONV_32_RGB555LE(UINT32 inCol);
    static UINT32 CONV_RGB555LE_32(UINT16 inCol);
    static UINT16 CONV_32_RGB555BE(UINT32 inCol);
    static UINT32 CONV_RGB555BE_32(UINT16 inCol);
    static UINT16 CONV_32_GRB555LE(UINT32 inCol);
    static UINT32 CONV_GRB555LE_32(UINT16 inCol);

    // Lookup tables
    static UINT16 CONV_32_RGB666NeoGeo(UINT32 inCol);
    static UINT32 CONV_RGB666NeoGeo_32(UINT16 inCol);
    static UINT16 CONV_32_RGB555Sharp(UINT32 inCol);
    static UINT32 CONV_RGB555Sharp_32(UINT16 inCol);

    // 24-bit
    static UINT32 CONV_32_BGR888(UINT32 inCol);
    static UINT32 CONV_BGR888_32(UINT32 inCol);
    static UINT32 CONV_32_BRG888(UINT32 inCol);
    static UINT32 CONV_BRG888_32(UINT32 inCol);
    static UINT32 CONV_32_GRB888(UINT32 inCol);
    static UINT32 CONV_GRB888_32(UINT32 inCol);
    static UINT32 CONV_32_RGB888(UINT32 inCol);
    static UINT32 CONV_RGB888_32(UINT32 inCol);

    // 32-bit
    static UINT32 CONV_32_RGBA8881(UINT32 inCol);
    static UINT32 CONV_RGBA8881_32(UINT32 inCol);
    static UINT32 CONV_32_RGBA8887(UINT32 inCol);
    static UINT32 CONV_RGBA8887_32(UINT32 inCol);
    static UINT32 CONV_32_RGBA8888(UINT32 inCol);
    static UINT32 CONV_RGBA8888_32(UINT32 inCol);
    static UINT32 CONV_32_BGRA8888(UINT32 inCol);
    static UINT32 CONV_BGRA8888_32(UINT32 inCol);

    static int GetColorStepFor8BitValue_1Step(int nColorValue);
    static int Get8BitValueForColorStep_1Step(int nColorStep);
    static int GetColorStepFor8BitValue_8Steps(int nColorValue);
    static int Get8BitValueForColorStep_8Steps(int nColorStep);
    static int GetColorStepFor8BitValue_16Steps(int nColorValue);
    static int Get8BitValueForColorStep_16Steps(int nColorStep);
    static int GetColorStepFor8BitValue_32Steps(int nColorValue);
    static int Get8BitValueForColorStep_32Steps(int nColorStep);
    static int GetColorStepFor8BitValue_32Steps_SharpCLUT(int nColorValue);
    static int Get8BitValueForColorStep_32Steps_SharpCLUT(int nColorStep);
    static int GetColorStepFor8BitValue_NeoGeoCLUT(int nColorValue);
    static int Get8BitValueForColorStep_NeoGeoCLUT(int nColorStep);
    static int GetColorStepFor8BitValue_HalfAlpha(int nColorValue);
    static int Get8BitValueForColorStep_HalfAlpha(int nColorStep);
    static int GetColorStepFor8BitValue_256Steps(int nColorValue) { return nColorValue; };
    static int Get8BitValueForColorStep_256Steps(int nColorStep) { return nColorStep; };

    static int GetNearestLegalColorValue_RGB111(int nColorValue);
    static int GetNearestLegalColorValue_RGB333(int nColorValue);
    static int GetNearestLegalColorValue_RGB444(int nColorValue);
    static int GetNearestLegalColorValue_RGB555(int nColorValue);
    static int GetNearestLegalColorValue_SharpCLUT(int nColorValue);
    static int GetNearestLegalColorValue_NeoGeoCLUT(int nColorValue);
    static int GetNearestLegalColorValue_ARGB7888(int nColorValue);
    static int GetNearestLegalColorValue_RGB888(int nColorValue) { return nColorValue; };

    static int ValidateColorStep_RGB333(int nColorStep);
    static int ValidateColorStep_RGB444(int nColorStep);
    static int ValidateColorStep_RGB555(int nColorStep);
    static int ValidateColorStep_RGB888(int nColorStep);

    static int ROUND_1(int rVal) { return rVal; };
    static int ROUND_8(int rVal);
    static int ROUND_17(int rVal);
    static int ROUND_32(int rVal);

    static UINT16 SWAP_16(UINT16 palv);

    static AlphaMode CurrAlphaMode;

    static AlphaMode GetAlphaMode() { return CurrAlphaMode; };
    static void SetAlphaMode(AlphaMode NewMode) { CurrAlphaMode = NewMode; };
};
