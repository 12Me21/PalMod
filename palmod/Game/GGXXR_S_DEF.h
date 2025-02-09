#pragma once

#include "GGXXACR_Common.h"

const std::vector<LPCWSTR> GGXXRPaletteNames_Text =
{
    { L"Punch" },
    { L"Kick", },
    { L"Slash" },
    { L"Heavy Slash" },
    { L"Start" },
    { L"Dust" },

    { L"SP Punch" },
    { L"SP Kick" },
    { L"SP Slash"},
    { L"SP Heavy Slash" },
    { L"SP Start" },
    { L"SP Dust" },
};

const std::vector<sGCBUPF_RelativePaletteData> GGXXRPaletteNamesNormal =
{
    { L"Punch" },
    { L"Kick", 0x10 },
    { L"Slash", 0x20 },
    { L"Heavy Slash", 0x30 },
    { L"Start", 0x40 },
    { L"Dust", 0x50 },

    { L"SP Punch", 0x60 },
    { L"SP Kick", 0x70 },
    { L"SP Slash", 0x80 },
    { L"SP Heavy Slash", 0x90 },
    { L"SP Start", 0xa0 },
    { L"SP Dust", 0xb0 },
};

const sGCBUPF_BasicNodeData GGXXR_S_NormalNode =
{
    { L"Core Palettes" }, 0x0, GGXXRPaletteNames_Text
};

const std::vector<sGCBUPF_BasicFileData> GGXXR_S_CharacterData =
{
    { L"cddata03.bin",    L"Anji Mito",         64798720,    GGXXR_S_NormalNode, GGXXRPaletteNamesNormal,    0x32051b0, indexGGXXSprites_ACR_Anji },
    { L"cddata03.bin",    L"Axl Low",           64798720,    GGXXR_S_NormalNode, GGXXRPaletteNamesNormal,    0x14cea30, indexGGXXSprites_ACR_Axl },
    { L"cddata03.bin",    L"Baiken",            64798720,    GGXXR_S_NormalNode, GGXXRPaletteNamesNormal,    0x2255cc0, indexGGXXSprites_ACR_Baiken },
    { L"cddata04.bin",    L"Bridget",           63557632,    GGXXR_S_NormalNode, GGXXRPaletteNamesNormal,    0x124e830, indexGGXXSprites_ACR_Bridget }, //Different sprites from ACR, but these work for now
    { L"cddata03.bin",    L"Chipp Zanuff",      64798720,    GGXXR_S_NormalNode, GGXXRPaletteNamesNormal,    0x1c56e80, indexGGXXSprites_ACR_Chipp },
    { L"cddata03.bin",    L"Dizzy",             64798720,    GGXXR_S_NormalNode, GGXXRPaletteNamesNormal,    0x3d19e80, indexGGXXSprites_ACR_Dizzy },
    { L"cddata03.bin",    L"Eddie",             64798720,    GGXXR_S_NormalNode, GGXXRPaletteNamesNormal,    0x1f19600, indexGGXXSprites_ACR_Eddie },
    { L"cddata03.bin",    L"Faust",             64798720,    GGXXR_S_NormalNode, GGXXRPaletteNamesNormal,    0x265d930, indexGGXXSprites_ACR_Faust },
    { L"cddata04.bin",    L"I-no",              63557632,    GGXXR_S_NormalNode, GGXXRPaletteNamesNormal,    0x895050,  indexGGXXSprites_ACR_Ino }, //Different sprites from ACR, but these work for now
    { L"cddata03.bin",    L"Jam Kuradoberi",    64798720,    GGXXR_S_NormalNode, GGXXRPaletteNamesNormal,    0x2da6940, indexGGXXSprites_ACR_Jam },
    { L"cddata03.bin",    L"Johnny",            64798720,    GGXXR_S_NormalNode, GGXXRPaletteNamesNormal,    0x35987c0, indexGGXXSprites_ACR_Johnny },
    { L"cddata04.bin",    L"Justice",           63557632,    GGXXR_S_NormalNode, GGXXRPaletteNamesNormal,    0x1cb87d0, indexGGXXSprites_ACR_Justice },
    { L"cddata04.bin",    L"Kliff Undersn",     63557632,    GGXXR_S_NormalNode, GGXXRPaletteNamesNormal,    0x1956c10, indexGGXXSprites_ACR_Kliff },
    { L"cddata03.bin",    L"Ky Kiske",          64798720,    GGXXR_S_NormalNode, GGXXRPaletteNamesNormal,    0xabc530,  indexGGXXSprites_ACR_Ky },
    { L"cddata03.bin",    L"May",               64798720,    GGXXR_S_NormalNode, GGXXRPaletteNamesNormal,    0xe85510,  indexGGXXSprites_ACR_May },
    { L"cddata03.bin",    L"Millia Rage",       64798720,    GGXXR_S_NormalNode, GGXXRPaletteNamesNormal,    0x11b5930, indexGGXXSprites_ACR_Millia },
    { L"cddata03.bin",    L"Potemkin",          64798720,    GGXXR_S_NormalNode, GGXXRPaletteNamesNormal,    0x1986470, indexGGXXSprites_ACR_Potemkin },
    { L"cddata04.bin",    L"Robo-Ky",           63557632,    GGXXR_S_NormalNode, GGXXRPaletteNamesNormal,    0x1691310, indexGGXXSprites_ACR_RoboKy }, //Different sprites from ACR, but these work for now
    { L"cddata04.bin",    L"Slayer",            63557632,    GGXXR_S_NormalNode, GGXXRPaletteNamesNormal,    0x35d820,  indexGGXXSprites_ACR_Slayer },
    { L"cddata03.bin",    L"Sol Badguy",        64798720,    GGXXR_S_NormalNode, GGXXRPaletteNamesNormal,    0x692d20,  indexGGXXSprites_ACR_Sol },
    { L"cddata03.bin",    L"Testament",         64798720,    GGXXR_S_NormalNode, GGXXRPaletteNamesNormal,    0x2a764f0  }, //Different sprites from ACR, our current ones wont work
    { L"cddata03.bin",    L"Venom",             64798720,    GGXXR_S_NormalNode, GGXXRPaletteNamesNormal,    0x3852ea0, indexGGXXSprites_ACR_Venom },
    { L"cddata04.bin",    L"Zappa",             63557632,    GGXXR_S_NormalNode, GGXXRPaletteNamesNormal,    0xc68530,  indexGGXXSprites_ACR_Zappa },
};
