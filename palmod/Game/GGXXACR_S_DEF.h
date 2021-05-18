#pragma once

#include "GGXXACR_Common.h"

const sGame_PaletteDataset GGXXACR_S_AB_EFFECTS[] =
{
    //General
    { L"Moroha Eyes",               0x5213b0, 0x5213f0, indexGGXXSprites_ACR_ABA, 0x04, &pairNext },
    { L"Moroha Eyes (Trails)",      0x521340, 0x521380, indexGGXXSprites_ACR_ABA, 0x03 },
    { L"Goku Moroha Eyes",          0x521630, 0x521670, indexGGXXSprites_ACR_ABA, 0x04, &pairNext },
    { L"Goku Moroha Eyes (Trails)", 0x5214f0, 0x521530, indexGGXXSprites_ACR_ABA, 0x03 },

    //Normals

    //Specials
    { L"Ketsugou (1/3)",    0x4dc0f0, 0x4dc130, indexGGXXSprites_ACR_ABA, 0x0a, &pairNextAndNext },
    { L"Ketsugou (2/3)",    0x4e03a0, 0x4e03e0, indexGGXXSprites_ACR_ABA, 0x0b },
    { L"Ketsugou (3/3)",    0x4e6aa0, 0x4e6ae0, indexGGXXSprites_ACR_ABA, 0x0c },

    { L"Shoukyaku",         0x4ad7f0, 0x4ad830, indexGGXXSprites_ACR_ABA, 0x12 },
    { L"Kihi",              0x4ae050, 0x4ae090, indexGGXXSprites_ACR_ABA, 0x0d },
    { L"Shousei",           0x51b240, 0x51b280, indexGGXXSprites_ACR_ABA, 0x13 },

    //Moroha Normals
    { L"(Moroha) 6H",       0x492d80, 0x492dc0, indexGGXXSprites_ACR_ABA, 0x10 },

    //Moroha Specials
    { L"Masshou",       0x499b40, 0x499b80, indexGGXXSprites_ACR_ABA, 0x0f },
    { L"Fukumetsu",     0x49dcd0, 0x49dd10, indexGGXXSprites_ACR_ABA, 0x05  },
    { L"Dangoku (1/2)", 0x4a0820, 0x4a0860, indexGGXXSprites_ACR_ABA, 0x01 },
    { L"Dangoku (2/2)", 0x4aa220, 0x4aa260, indexGGXXSprites_ACR_ABA, 0x01 },

    { L"Danzai (1/2)",  0x4b4670, 0x4b46b0, indexGGXXSprites_ACR_ABA, 0x02 },
    { L"Danzai (2/2)",  0x4be190, 0x4be1d0, indexGGXXSprites_ACR_ABA, 0x02 },

    { L"Kashitsu",      0x4c8e30, 0x4c8e70, indexGGXXSprites_ACR_ABA, 0x09 },

    { L"Konzetsu (1/2)", 0x4d09a0, 0x4d09e0, indexGGXXSprites_ACR_ABA, 0x0e },
    { L"Konzetsu (2/2)", 0x4d67b0, 0x4d67f0, indexGGXXSprites_ACR_ABA, 0x0e },

    //Forcebreaks

    //Overdrives
    { L"Shouko: Intoku (1/3)", 0x4ed940, 0x4ed980, indexGGXXSprites_ACR_ABA, 0x08 },
    { L"Shouko: Intoku (2/3)", 0x4fce70, 0x4fceb0, indexGGXXSprites_ACR_ABA, 0x08 },
    { L"Shouko: Intoku (3/3)", 0x5089e0, 0x508a20, indexGGXXSprites_ACR_ABA, 0x08 },

    { L"Shouko: Inmetsu",      0x4e8210, 0x4e8250, indexGGXXSprites_ACR_ABA, 0x07 },

    { L"Henshitsu",            0x516640, 0x516680, indexGGXXSprites_ACR_ABA, 0x06 },

    //Instant Kill
    { L"Muchi no Yami (1/2)",  0x50bc20, 0x50bc60, indexGGXXSprites_ACR_ABA, 0x11 },
    { L"Muchi no Yami (2/2)",  0x513030, 0x513070, indexGGXXSprites_ACR_ABA, 0x11 },
};

const sGame_PaletteDataset GGXXACR_S_BK_EFFECTS[] =
{
    //General
    { L"Flower Petals",                 0x34bc70, 0x34bcb0, indexGGXXSprites_ACR_Baiken, 0x09 },
    { L"Pipe (Tossed)",                 0x34b3a0, 0x34b3e0, indexGGXXSprites_ACR_Baiken, 0x0c },
    { L"Smoke",                         0x34bf70, 0x34bfb0, indexGGXXSprites_ACR_Baiken, 0x0e },
    { L"Intro Leaf",                    0x31cd50, 0x31cd90, indexGGXXSprites_ACR_Baiken, 0x0a },
    //Normals
    { L"5D",                            0x314bc0, 0x314c00, indexGGXXSprites_ACR_Baiken, 0x01 },

    { L"j.D Effect (1/2)",              0x316b70, 0x316bb0, indexGGXXSprites_ACR_Baiken, 0x0b },
    { L"j.D Effect (2/2)",              0x3183e0, 0x318420, indexGGXXSprites_ACR_Baiken, 0x0b },
    //Specials
    { L"Tatami Gaeshi (1/2)",           0x3100a0, 0x3100e0, indexGGXXSprites_ACR_Baiken, 0x0f },
    { L"Tatami Gaeshi (2/2)",           0x313930, 0x313970, indexGGXXSprites_ACR_Baiken, 0x0f },

    { L"Zakuro",                        0x31ad10, 0x31ad50, indexGGXXSprites_ACR_Baiken, 0x13 },
    { L"Sakura",                        0x30ecf0, 0x30ed30, indexGGXXSprites_ACR_Baiken, 0x0d },
    //Forcebreaks
    { L"Baku",                          0x31e7c0, 0x31e800, indexGGXXSprites_ACR_Baiken, 0x02 },
    { L"Baku:XXX Card Back/Icons",      0x31f700, 0x31f740, indexGGXXSprites_ACR_Baiken, 0x03 },
    { L"Baku:XXX Card Front",           0x320440, 0x320480, indexGGXXSprites_ACR_Baiken, 0x04 },
    { L"Baku:XXX Punch",                0x34c5a0, 0x34c5e0, indexGGXXSprites_ACR_Baiken, 0x07 },
    { L"Baku:XXX Kick",                 0x34ff50, 0x34ff90, indexGGXXSprites_ACR_Baiken, 0x06 },
    { L"Baku:XXX Slash",                0x34df50, 0x34df90, indexGGXXSprites_ACR_Baiken, 0x08 },
    { L"Baku:XXX Card Front (Sliced)",  0x324670, 0x3246b0, indexGGXXSprites_ACR_Baiken, 0x05 },
    //Overdrives
    { L"Tsurane Sanzu Watashi (1/3)",   0x31ced0, 0x31cf10, indexGGXXSprites_ACR_Baiken, 0x10 },
    { L"Tsurane Sanzu Watashi (2/3)",   0x31d600, 0x31d640, indexGGXXSprites_ACR_Baiken, 0x11 },
    { L"Tsurane Sanzu Watashi (3/3)",   0x31e1a0, 0x31e1e0, indexGGXXSprites_ACR_Baiken, 0x12 },
    //Instant Kill
    { L"Garyou Tensei (1/10)",          0x328da0, 0x3291a0 },
    { L"Garyou Tensei (2/10)",          0x334f60, 0x335360 },
    { L"Garyou Tensei (3/10)",          0x338550, 0x338950 },
    { L"Garyou Tensei (4/10)",          0x339600, 0x339a00 },
    { L"Garyou Tensei (5/10)",          0x33a650, 0x33aa50 },
    { L"Garyou Tensei (6/10)",          0x33b590, 0x33b990 },
    { L"Garyou Tensei (7/10)",          0x33c500, 0x33c900 },
    { L"Garyou Tensei (8/10)",          0x33d4c0, 0x33d8c0 },
    { L"Garyou Tensei (9/10)",          0x340d30, 0x341130 },
    { L"Garyou Tensei (10/10)",         0x349550, 0x349950 },
    { L"Garyou Tensei - Light (1/3)",   0x33d980, 0x33d9c0 },
    { L"Garyou Tensei - Light (2/3)",   0x33ec70, 0x33ecb0 },
    { L"Garyou Tensei - Light (3/3)",   0x33fdc0, 0x33fe00 },
};

const sGame_PaletteDataset GGXXACR_S_IN_EFFECTS[] =
{
    //General
    { L"Dashing Effects", 0x43d120, 0x43d160 },
    //Normals
    { L"f.S (1/6)", 0x3ff5e0, 0x3ff620 },
    { L"f.S (2/6)", 0x400d00, 0x400d40 },
    { L"f.S (3/6)", 0x4026b0, 0x4026f0 },
    { L"f.S (4/6)", 0x403c60, 0x403ca0 },
    { L"f.S (5/6)", 0x404300, 0x404340 },
    { L"f.S (6/6)", 0x4048e0, 0x404920 },

    { L"5H/2H - Slam", 0x44a170, 0x44a1b0 },
    { L"5H/2H - Notes", 0x43a5c0, 0x43a600 },

    { L"5D (1/3)", 0x44be20, 0x44be60 },
    { L"5D (2/3)", 0x44df80, 0x44dfc0 },
    { L"5D (3/3)", 0x4500c0, 0x450100 },

    { L"2P", 0x404c50, 0x404c90 },
    //Specials
    { L"Stroke the Big Tree (1/3)", 0x450bc0, 0x450c00 },
    { L"Stroke the Big Tree (2/3)", 0x455200, 0x455240 },
    { L"Stroke the Big Tree (3/3)", 0x455e40, 0x455e80 },

    { L"Antidepressant Scale (1/2)", 0x3ee580, 0x3ee5c0 },
    { L"Antidepressant Scale (2/2)", 0x3efab0, 0x3efaf0 },

    { L"Sultry Performance (1/2)", 0x456790, 0x4567d0 },
    { L"Sultry Performance (2/2)", 0x45ea20, 0x45ea60 },

    { L"Chemical Love (1/3)", 0x3f0b80, 0x3f0bc0 },
    { L"Chemical Love (2/3)", 0x3f48e0, 0x3f4920 },
    { L"Chemical Love (3/3)", 0x3f8ea0, 0x3f8ee0 },
    { L"Chemical Love Effects", 0x3fcab0, 0x3fcaf0 },
    //Force Breaks

    //Overdrives
    { L"Ultimate Fortissimo - Rotating Ring", 0x4054b0, 0x4054f0 },
    { L"Ultimate Fortissimo - Main Effects (1/9)", 0x438600, 0x438640 },
    { L"Ultimate Fortissimo - Main Effects (2/9)", 0x419680, 0x4196c0 },
    { L"Ultimate Fortissimo - Main Effects (3/9)", 0x41b210, 0x41b250 },
    { L"Ultimate Fortissimo - Main Effects (4/9)", 0x41c6d0, 0x41c710 },
    { L"Ultimate Fortissimo - Main Effects (5/9)", 0x422410, 0x422450 },
    { L"Ultimate Fortissimo - Main Effects (6/9)", 0x428f40, 0x428f80 },
    { L"Ultimate Fortissimo - Main Effects (7/9)", 0x42f320, 0x42f360 },
    { L"Ultimate Fortissimo - Main Effects (8/9)", 0x434730, 0x434770 },
    { L"Ultimate Fortissimo - Main Effects (9/9)", 0x438600, 0x438640 },
    { L"Ultimate Fortissimo - Rings (1/5)", 0x4069f0, 0x406a30 },
    { L"Ultimate Fortissimo - Rings (2/5)", 0x409770, 0x4097b0 },
    { L"Ultimate Fortissimo - Rings (3/5)", 0x40d430, 0x40d470 },
    { L"Ultimate Fortissimo - Rings (4/5)", 0x411350, 0x411390 },
    { L"Ultimate Fortissimo - Rings (5/5)", 0x4158c0, 0x415900 },

    { L"Longing Desperation (1/3)", 0x43df10, 0x43df50 },
    { L"Longing Desperation (2/3)", 0x441b90, 0x441bd0 },
    { L"Longing Desperation (3/3)", 0x444a40, 0x444a80 },
    //Instant Kill
    { L"Last Will and Testament - Speakers (1/28)", 0x487540, 0x487940 },
    { L"Last Will and Testament - Speakers (2/28)", 0x48e2d0, 0x48e6d0 },
    { L"Last Will and Testament - Speakers (3/28)", 0x494eb0, 0x4952b0 },
    { L"Last Will and Testament - Speakers (4/28)", 0x49b9c0, 0x49bdc0 },
    { L"Last Will and Testament - Speakers (5/28)", 0x4a2240, 0x4a2640 },
    { L"Last Will and Testament - Speakers (6/28)", 0x4a88d0, 0x4a8cd0 },
    { L"Last Will and Testament - Speakers (7/28)", 0x4af500, 0x4af900 },
    { L"Last Will and Testament - Speakers (8/28)", 0x4b64e0, 0x4b68e0 },
    { L"Last Will and Testament - Speakers (9/28)", 0x4bd420, 0x4bd820 },
    { L"Last Will and Testament - Speakers (10/28)", 0x4c4210, 0x4c4610 },
    { L"Last Will and Testament - Speakers (11/28)", 0x4cac00, 0x4cb000 },
    { L"Last Will and Testament - Speakers (12/28)", 0x4cc3f0, 0x4cc7f0 },
    { L"Last Will and Testament - Speakers (13/28)", 0x4cdb20, 0x4cdf20 },
    { L"Last Will and Testament - Speakers (14/28)", 0x4cf220, 0x4cf620 },
    { L"Last Will and Testament - Speakers (15/28)", 0x4d0920, 0x4d0d20 },
    { L"Last Will and Testament - Speakers (16/28)", 0x4d1f60, 0x4d2360 },
    { L"Last Will and Testament - Speakers (17/28)", 0x4d3680, 0x4d3a80 },
    { L"Last Will and Testament - Speakers (18/28)", 0x4d4dd0, 0x4d51d0 },
    { L"Last Will and Testament - Speakers (19/28)", 0x4d64a0, 0x4d68a0 },
    { L"Last Will and Testament - Speakers (20/28)", 0x4d7bb0, 0x4d7fb0 },
    { L"Last Will and Testament - Speakers (21/28)", 0x4d9340, 0x4d9740 },
    { L"Last Will and Testament - Speakers (22/28)", 0x4dc1d0, 0x4dc5d0 },
    { L"Last Will and Testament - Speakers (23/28)", 0x4dfad0, 0x4dfed0 },
    { L"Last Will and Testament - Speakers (24/28)", 0x4e5ab0, 0x4e5eb0 },
    { L"Last Will and Testament - Speakers (25/28)", 0x4ebb10, 0x4ebf10 },
    { L"Last Will and Testament - Speakers (26/28)", 0x4f1f40, 0x4f2340 },
    { L"Last Will and Testament - Speakers (27/28)", 0x4f35f0, 0x4f39f0 },
    { L"Last Will and Testament - Speakers (28/28)", 0x4f4c70, 0x4f5070 },
    { L"Last Will and Testament - Speaker Effects (1/8)", 0x466140, 0x466180 },
    { L"Last Will and Testament - Speaker Effects (2/8)", 0x4683d0, 0x468410 },
    { L"Last Will and Testament - Speaker Effects (3/8)", 0x4697f0, 0x469830 },
    { L"Last Will and Testament - Speaker Effects (4/8)", 0x46acb0, 0x46acf0 },
    { L"Last Will and Testament - Speaker Effects (5/8)", 0x46bfe0, 0x46c020 },
    { L"Last Will and Testament - Speaker Effects (6/8)", 0x46d170, 0x46d1b0 },
    { L"Last Will and Testament - Speaker Effects (7/8)", 0x46e250, 0x46e290 },
    { L"Last Will and Testament - Speaker Effects (8/8)", 0x46e7e0, 0x46e820 },
    { L"Last Will and Testament - Light", 0x4824b0, 0x4828b0 },
    { L"Last Will and Testament - Lights (1/2)", 0x471e80, 0x472280 },
    { L"Last Will and Testament - Lights (2/2)", 0x47a840, 0x47ac40 },
    { L"Last Will and Testament - Stage", 0x46eba0, 0x46efa0 },
    //Boss Ino effects
    { L"Megalomania effect (1/18)", 0x4f6260, 0x4f62a0 },
    { L"Megalomania effect (2/18)", 0x4f6810, 0x4f6850 },
    { L"Megalomania effect (3/18)", 0x4f70d0, 0x4f7110 },
    { L"Megalomania effect (4/18)", 0x4f7f30, 0x4f7f70 },
    { L"Megalomania effect (5/18)", 0x4f9070, 0x4f90b0 },
    { L"Megalomania effect (6/18)", 0x4f9fb0, 0x4f9ff0 },
    { L"Megalomania effect (7/18)", 0x4fab60, 0x4faba0 },
    { L"Megalomania effect (8/18)", 0x4fb520, 0x4fb560 },
    { L"Megalomania effect (9/18)", 0x4fbd30, 0x4fbd70 },
    { L"Megalomania effect (10/18)", 0x4fc320, 0x4fc360 },
    { L"Megalomania effect (11/18)", 0x4fcd00, 0x4fcd40 },
    { L"Megalomania effect (12/18)", 0x4fd9a0, 0x4fd9e0 },
    { L"Megalomania effect (13/18)", 0x4fe4b0, 0x4fe4f0 },
    { L"Megalomania effect (14/18)", 0x4feed0, 0x4fef10 },
    { L"Megalomania effect (15/18)", 0x4ff410, 0x4ff450 },
    { L"Megalomania effect (16/18)", 0x4ffee0, 0x4fff20 },
    { L"Megalomania effect (17/18)", 0x502a50, 0x502a90 },
    { L"Megalomania effect (18/18)", 0x505440, 0x505480 },
    { L"Megalomania orbs (1/3)", 0x507980, 0x5079c0 },
    { L"Megalomania orbs (2/3)", 0x507b50, 0x507b90 },
    { L"Megalomania orbs (3/3)", 0x507df0, 0x507e30 },
    { L"Caution!", 0x509820, 0x509860 },
    { L"Warning!", 0x50a0a0, 0x50a0e0 },
    { L"Danger!", 0x50a950, 0x50a990 },
};


const sGame_PaletteDataset GGXXACR_S_JY_EFFECTS[] =
{
    //General
    { L"Intro rose (Tossed)", 0x3d02b0, 0x3d02f0 },
    //Normals
    { L"5P (1/2)", 0x3d0430, 0x3d0470 },
    { L"5P (2/2)", 0x3d0520, 0x3d0560 },

    { L"5H (Extra dust)", 0x3d0620, 0x3d0660 },
    { L"6H (1/2)", 0x3d5eb0, 0x3d5ef0 },
    { L"6H (2/2)", 0x3d76c0, 0x3d7700 },

    { L"2H (1/2)", 0x3da900, 0x3da940 },
    { L"2H (2/2)", 0x3dc770, 0x3dc7b0 },
    //Specials
    { L"Mist Finer Stance (1/8)", 0x3d8820, 0x3d8860 },
    { L"Mist Finer Stance (2/8)", 0x3da420, 0x3da460 },
    { L"Mist Finer Stance (3/8)", 0x3d8e20, 0x3d8e60 },
    { L"Mist Finer Stance (4/8)", 0x3d9310, 0x3d9350 },
    { L"Mist Finer Stance (5/8)", 0x3d9740, 0x3d9780 },
    { L"Mist Finer Stance (6/8)", 0x3d9b50, 0x3d9b90 },
    { L"Mist Finer Stance (7/8)", 0x3d9eb0, 0x3d9ef0 },
    { L"Mist Finer Stance (8/8)", 0x3da420, 0x3da460 },
    { L"Mist Finer Slash", 0x3d21e0, 0x3d2220 },

    { L"Coins", 0x3f0f60, 0x3f0fa0 },
    { L"Mist", 0x3bfe40, 0x3bfe80 },

    { L"Ensenga (1/3)", 0x3dd2e0, 0x3dd320 },
    { L"Ensenga (2/3)", 0x3de4a0, 0x3de4e0 },
    { L"Ensenga (3/3)", 0x3e3220, 0x3e3260 },

    { L"Divine Blade", 0x3b9bb0, 0x3b9bf0 },
    { L"Killer Joker", 0x3ebf30, 0x3ebf70 },
    //Forcebreaks
    { L"Jackhound", 0x3e9bf0, 0x3e9c30 },
    //Overdrives
    { L"Thats my name (1/3)", 0x3c6560, 0x3c65a0 },
    { L"Thats my name (2/3)", 0x3c7b00, 0x3c7b40 },
    { L"Thats my name (3/3)", 0x3cf120, 0x3cf160 },

    { L"Uncho's Iai", 0x3eeef0, 0x3eef30 },

    //Instant Kill
    { L"Joker Trick (Thrown card)", 0x3d0180, 0x3d01c0 },
    { L"Joker Trick (Back of card)", 0x3b5fd0, 0x3b6010 },
};

const sGame_PaletteDataset GGXXACR_S_KY_EFFECTS[] =
{
    //General
    { L"Idle Stance / Projectile Trails", 0x3f44a0, 0x3f44e0 },
    //Normals
    { L"5H (1/2)", 0x424820, 0x424860 },
    { L"5H (2/2)", 0x428f60, 0x428fa0 },
    { L"6H (1/2)", 0x3fb3c0, 0x3fb400 },
    { L"6H (2/2)", 0x400700, 0x400740 },
    { L"3H (1/2)", 0x3f7c40, 0x3f7c80 },
    { L"3H (2/2)", 0x3f8050, 0x3f8090 },
    { L"j.S", 0x3f8b30, 0x3f8b70 },
    { L"j.D", 0x41d550, 0x41d590 },
    //Specials
    { L"Stun Edge (1/2)", 0x39bd40, 0x39bd80 },
    { L"Stun Edge (2/2)", 0x39d6f0, 0x39d730 },
    { L"Air Stun Edge", 0x3a7000, 0x3a7040 },
    { L"Charged Stun Edge Startup (1/2)", 0x39a3d0, 0x39a410 },
    { L"Charged Stun Edge Startup (2/2)", 0x39b120, 0x39b160 },
    { L"Charged Stun Edge", 0x3a19a0, 0x3a19e0 },
    { L"Stun Edge Impacts/Rings", 0x39fa30, 0x39fa70 },

    { L"Vapor Thrust", 0x394ea0, 0x394ee0 },
    { L"Vapor Thrust Ground Effects", 0x3942d0, 0x394310 },
    { L"Lightning Javolin", 0x42d770, 0x42d7b0 },

    { L"Stun Dipper", 0x3ad2d0, 0x3ad310 },

    { L"Greed Sever Startup", 0x3b06a0, 0x3b06e0 },
    { L"Greed Sever (1/2)", 0x3b29e0, 0x3b2be0 },
    { L"Greed Sever (2/2)", 0x3b56b0, 0x3b58b0 },
    { L"Greed Sever Shine", 0x3b7760, 0x3b77a0 },
    { L"Greed Sever Ground Slam (FB)", 0x435c00, 0x435c40 },

    { L"Lightning Strike", 0x4360d0, 0x436110 },
    //Force Breaks
    { L"Lightning Sphere", 0x41a610, 0x41a650 },
    { L"Charge Drive (1/4)", 0x404fa0, 0x404fe0 },
    { L"Charge Drive (2/4)", 0x40b460, 0x40b4a0 },
    { L"Charge Drive (3/4)", 0x4119b0, 0x4119f0 },
    { L"Charge Drive (4/4)", 0x417b40, 0x417b80 },

    { L"Stun Rays Flash (1/2)", 0x42a3a0, 0x42a3e0 },
    { L"Stun Rays Flash (2/2)", 0x42bc20, 0x42bc60 },
    //Overdrives
    { L"Ride the Lightning (1/2)", 0x3dfd50, 0x3dfd90 },
    { L"Ride the Lightning (2/2)", 0x3e8430, 0x3e8470 },

    { L"Sacred Edge Projectile (1/4)", 0x3b9980, 0x3b99c0 },
    { L"Sacred Edge Projectile (2/4)", 0x3bfae0, 0x3bfb20 },
    { L"Sacred Edge Projectile (3/4)", 0x3d6200, 0x3d6240 },
    { L"Sacred Edge Projectile (4/4)", 0x3db780, 0x3db7c0 },
    { L"Sacred Edge Circle (1/17)", 0x3c6a20, 0x3c6a60 },
    { L"Sacred Edge Circle (2/17)", 0x3c6cd0, 0x3c6d10 },
    { L"Sacred Edge Circle (3/17)", 0x3c7070, 0x3c70b0 },
    { L"Sacred Edge Circle (4/17)", 0x3c73c0, 0x3c7400 },
    { L"Sacred Edge Circle (5/17)", 0x3c7930, 0x3c7970 },
    { L"Sacred Edge Circle (6/17)", 0x3c8110, 0x3c8150 },
    { L"Sacred Edge Circle (7/17)", 0x3c8bf0, 0x3c8c30 },
    { L"Sacred Edge Circle (8/17)", 0x3c97b0, 0x3c97f0 },
    { L"Sacred Edge Circle (9/17)", 0x3ca6b0, 0x3ca6f0 },
    { L"Sacred Edge Circle (10/17)", 0x3cb800, 0x3cb840 },
    { L"Sacred Edge Circle (11/17)", 0x3cca80, 0x3ccac0 },
    { L"Sacred Edge Circle (12/17)", 0x3cdfd0, 0x3ce010 },
    { L"Sacred Edge Circle (13/17)", 0x3cf7c0, 0x3cf800 },
    { L"Sacred Edge Circle (14/17)", 0x3d0ec0, 0x3d0f00 },
    { L"Sacred Edge Circle (15/17)", 0x3d2910, 0x3d2950 },
    { L"Sacred Edge Circle (16/17)", 0x3d3e80, 0x3d3ec0 },
    { L"Sacred Edge Circle (17/17)", 0x3d5080, 0x3d50c0 },
    //Instant Kill
    { L"Rising Force (1/2)", 0x3ea5d0, 0x3ea610 },
    { L"Rising Force (2/2)", 0x3ee900, 0x3ee940 },

    //{ L"Unsure 15", 0x3f4e60, 0x3f4ea0 }, 
    //{ L"Unsure 16", 0x3f6f30, 0x3f6f70 }, 
};

const sGame_PaletteDataset GGXXACR_S_PO_EFFECTS[] =
{
    //Specials
    { L"Slide Head/Whiffed HK (1/2)", 0x49e4b0, 0x49e4f0 },
    { L"Slide Head/Whiffed HK (2/2)", 0x4a0210, 0x4a0250 },

    { L"F.D.B. Projectile (1/3)", 0x4b69a0, 0x4b69e0 },
    { L"F.D.B. Projectile (2/3)", 0x4be9d0, 0x4bea10 },
    { L"F.D.B. Projectile (3/3)", 0x4c05a0, 0x4c05e0 },

    { L"Potemkin Buster (1/2)", 0x4996e0, 0x499720 },
    { L"Potemkin Buster (2/2)", 0x49bf90, 0x49bfd0 },

    { L"Heat Knuckle (1/5)", 0x4d23c0, 0x4d2400 },
    { L"Heat Knuckle (2/5)", 0x4dba50, 0x4dba90 },
    { L"Heat Knuckle (3/5)", 0x4dc490, 0x4dc4d0 },
    { L"Heat Knuckle (4/5)", 0x4d9ac0, 0x4d9b00 },
    { L"Heat Knuckle (5/5)", 0x4de390, 0x4de3d0 },
    { L"Heat Extend - Bullets", 0x4d22f0, 0x4d2330 },
    { L"Heat Extend - Hearts (1/2)", 0x4a0500, 0x4a0540 },
    { L"Heat Extend - Hearts (2/2)", 0x4a10c0, 0x4a1100 },

    //Overdrives
    { L"Giganter (1/2)", 0x4a2700, 0x4a2740 },
    { L"Giganter (2/2)", 0x4a66b0, 0x4a66f0 },
    { L"Gigantic Bullet Close Fist (1/2)", 0x4ace00, 0x4ace40 },
    { L"Gigantic Bullet Close Fist (2/2)", 0x4af6b0, 0x4af6f0 },
    { L"Gigantic Bullet Far Fist (1/2)", 0x4b1bd0, 0x4b1c10 },
    { L"Gigantic Bullet Far Fist (2/2)", 0x4b4480, 0x4b44c0 },

    //Instant Kill
    { L"Magnum Opera (1/2)", 0x4c23e0, 0x4c2420 },
    { L"Magnum Opera (2/2)", 0x4cc8c0, 0x4cc900 },
    { L"Magnum Opera - Heart (1/2)", 0x4c1bd0, 0x4c1c10 },
    { L"Magnum Opera - Heart (2/2)", 0x4c2110, 0x4c2150 },
};

const sGame_PaletteDataset GGXXACR_S_SL_EFFECTS[] =
{
    // General
    { L"General Sparks / Riot Stamp", 0x3fc2b0, 0x3fc2f0 },
    //Specials
    { L"Gunflame (1/3)", 0x3540b0, 0x3540f0, indexGGXXSprites_ACR_Sol, 0x07 },
    { L"Gunflame (2/3)", 0x3579b0, 0x3579f0, indexGGXXSprites_ACR_Sol, 0x07 },
    { L"Gunflame (3/3)", 0x35a740, 0x35a780, indexGGXXSprites_ACR_Sol, 0x07 },
    { L"Gunflame - Dragon Install (1/4)", 0x41b270, 0x41b2b0, indexGGXXSprites_ACR_Sol, 0x02 },
    { L"Gunflame - Dragon Install (2/4)", 0x422910, 0x422950, indexGGXXSprites_ACR_Sol, 0x02 },
    { L"Gunflame - Dragon Install (3/4)", 0x4262c0, 0x426300, indexGGXXSprites_ACR_Sol, 0x02 },
    { L"Gunflame - Dragon Install (4/4)", 0x429a60, 0x429aa0, indexGGXXSprites_ACR_Sol, 0x02 },
    { L"Volcanic Viper (1/2)", 0x3485f0, 0x348630, indexGGXXSprites_ACR_Sol, 0x09 },
    { L"Volcanic Viper (2/2)", 0x34f3f0, 0x34f430, indexGGXXSprites_ACR_Sol, 0x09 },
    { L"Volcanic Viper - Dragon Install", 0x38aaa0, 0x38aae0 },
    { L"Grand Viper", 0x342a40, 0x342a80, indexGGXXSprites_ACR_Sol, 0x06 },
    { L"Bandit Revolver - DI (1/3)", 0x405890, 0x4058d0 },
    { L"Bandit Revolver - DI (2/3)", 0x410a10, 0x410a50 },
    { L"Bandit Revolver - DI (3/3)", 0x4177e0, 0x417820 },
    { L"Bandit Bringer (1/12)", 0x35c3d0, 0x35c410, indexGGXXSprites_ACR_Sol, 0x01 },
    { L"Bandit Bringer (2/12)", 0x35da10, 0x35da50, indexGGXXSprites_ACR_Sol, 0x01 },
    { L"Bandit Bringer (3/12)", 0x3600b0, 0x3600f0, indexGGXXSprites_ACR_Sol, 0x01 },
    { L"Bandit Bringer (4/12)", 0x361f80, 0x361fc0, indexGGXXSprites_ACR_Sol, 0x01 },
    { L"Bandit Bringer (5/12)", 0x364520, 0x364560, indexGGXXSprites_ACR_Sol, 0x01 },
    { L"Bandit Bringer (6/12)", 0x366df0, 0x366e30, indexGGXXSprites_ACR_Sol, 0x01 },
    { L"Bandit Bringer (7/12)", 0x368de0, 0x368e20, indexGGXXSprites_ACR_Sol, 0x01 },
    { L"Bandit Bringer (8/12)", 0x369e60, 0x369ea0, indexGGXXSprites_ACR_Sol, 0x01 },
    { L"Bandit Bringer (9/12)", 0x36aab0, 0x36aaf0, indexGGXXSprites_ACR_Sol, 0x01 },
    { L"Bandit Bringer (10/12)", 0x36b450, 0x36b490, indexGGXXSprites_ACR_Sol, 0x01 },
    { L"Bandit Bringer (11/12)", 0x36bde0, 0x36be20, indexGGXXSprites_ACR_Sol, 0x01 },
    { L"Bandit Bringer (12/12)", 0x36c770, 0x36c7b0, indexGGXXSprites_ACR_Sol, 0x01 },
    { L"Bandit Bringer Trails (1/3)", 0x36d0a0, 0x36d0e0 },
    { L"Bandit Bringer Trails (2/3)", 0x36dce0, 0x36dd20 },
    { L"Bandit Bringer Trails (3/3)", 0x36e860, 0x36e8a0 },
    { L"Sidewinder", 0x437380, 0x4373c0, indexGGXXSprites_ACR_Sol, 0x08 },
    { L"Fafnir (1/7)", 0x42fb50, 0x42fb90, indexGGXXSprites_ACR_Sol, 0x04 },
    { L"Fafnir (2/7)", 0x430970, 0x4309b0, indexGGXXSprites_ACR_Sol, 0x04 },
    { L"Fafnir (3/7)", 0x431a50, 0x431a90, indexGGXXSprites_ACR_Sol, 0x04 },
    { L"Fafnir (4/7)", 0x432d20, 0x432d60, indexGGXXSprites_ACR_Sol, 0x04 },
    { L"Fafnir (5/7)", 0x434b00, 0x434b40, indexGGXXSprites_ACR_Sol, 0x04 },
    { L"Fafnir (6/7)", 0x436330, 0x436370, indexGGXXSprites_ACR_Sol, 0x04 },
    { L"Fafnir (7/7)", 0x436fb0, 0x436ff0, indexGGXXSprites_ACR_Sol, 0x04 },
    { L"Slam - Dragon Install", 0x3fcf60, 0x3fcfa0 },
    // Overdrives
    { L"Tyrant Rave", 0x378990, 0x3789d0, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (1/24)", 0x3F6610, 0x3F6650, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (2/24)", 0x3F68C0, 0x3F6900, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (3/24)", 0x3F7510, 0x3F7550, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (4/24)", 0x3F85B0, 0x3F85F0, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (5/24)", 0x3F94B0, 0x3F94F0, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (6/24)", 0x3FA340, 0x3FA380, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (7/24)", 0x3FAF50, 0x3FAF90, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (8/24)", 0x3FB7E0, 0x3FB820, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (9/24)", 0x3FBDA0, 0x3FBDE0, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (10/24)", 0x3C0F40, 0x3C0F80, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (11/24)", 0x3C2DC0, 0x3C2E00, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (12/24)", 0x3C9210, 0x3C9250, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (13/24)", 0x3D0F60, 0x3D0FA0, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (14/24)", 0x3D8E50, 0x3D8E90, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (15/24)", 0x3DFB20, 0x3DFB60, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (16/24)", 0x3EA370, 0x3EA3B0, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (17/24)", 0x3E5AE0, 0x3E5B20, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (18/24)", 0x3ED820, 0x3ED860, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (19/24)", 0x3F0050, 0x3F0090, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (20/24)", 0x3F1CB0, 0x3F1CF0, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (21/24)", 0x3F3190, 0x3F31D0, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (22/24)", 0x3F4190, 0x3F41D0, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (23/24)", 0x3F50C0, 0x3F5100, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Tyrant Rave Beta (24/24)", 0x3F5C50, 0x3F5C90, indexGGXXSprites_ACR_Sol, 0x05 },
    { L"Dragon Install Fire (1/7)", 0x3870c0, 0x387100, indexGGXXSprites_ACR_Sol, 0x03 },
    { L"Dragon Install Fire (2/7)", 0x3879f0, 0x387a30, indexGGXXSprites_ACR_Sol, 0x03 },
    { L"Dragon Install Fire (3/7)", 0x387f90, 0x387fd0, indexGGXXSprites_ACR_Sol, 0x03 },
    { L"Dragon Install Fire (4/7)", 0x388870, 0x3888b0, indexGGXXSprites_ACR_Sol, 0x03 },
    { L"Dragon Install Fire (5/7)", 0x389300, 0x389340, indexGGXXSprites_ACR_Sol, 0x03 },
    { L"Dragon Install Fire (6/7)", 0x389c80, 0x389cc0, indexGGXXSprites_ACR_Sol, 0x03 },
    { L"Dragon Install Fire (7/7)", 0x38a5e0, 0x38a620, indexGGXXSprites_ACR_Sol, 0x03 },
    // Instant Kill
    { L"Napalm Death (1/9)", 0x3911a0, 0x3911e0 },
    { L"Napalm Death (2/9)", 0x39c6b0, 0x39c6f0 },
    { L"Napalm Death (3/9)", 0x3a58a0, 0x3a58e0 },
    { L"Napalm Death (4/9)", 0x3af100, 0x3af140 },
    { L"Napalm Death (5/9)", 0x3b5a30, 0x3b5a70 },
    { L"Napalm Death (6/9)", 0x3b88f0, 0x3b8930 },
    { L"Napalm Death (7/9)", 0x3bb020, 0x3bb060 },
    { L"Napalm Death (8/9)", 0x3bcf70, 0x3bcfb0 },
    { L"Napalm Death (9/9)", 0x3bf310, 0x3bf350 },
};

const sGame_PaletteDataset GGXXACR_S_SY_EFFECTS[] =
{
    //General
    { L"Coffin Portal Intro", 0x43ec30, 0x43ec70 },
    { L"Sharon Intro Corpse", 0x46bf50, 0x46bf90 },
    { L"Sharon Intro Blood (1/5)", 0x465a60, 0x465aa0 },
    { L"Sharon Intro Blood (2/5)", 0x465c60, 0x465ca0 },
    { L"Sharon Intro Blood (3/5)", 0x465e80, 0x465ec0 },
    { L"Sharon Intro Blood (4/5)", 0x466060, 0x4660a0 },
    { L"Sharon Intro Blood (5/5)", 0x4661f0, 0x466230 },

    { L"Forwards Jump (1/2)", 0x3c5970, 0x3c59b0 },
    { L"Forwards Jump (2/2)", 0x3c7260, 0x3c72a0 },
    { L"Backwards Jump (1/2)", 0x3c8570, 0x3c85b0 },
    { L"Backwards Jump (2/2)", 0x3c9d30, 0x3c9d70 },
    //Normals
    { L"2H (1/27)", 0x3a53d0, 0x3a5410 },
    { L"2H (2/27)", 0x3a5990, 0x3a59d0 },
    { L"2H (3/27)", 0x3a63b0, 0x3a63f0 },
    { L"2H (4/27)", 0x3a6e40, 0x3a6e80 },
    { L"2H (5/27)", 0x3a8890, 0x3a88d0 },
    { L"2H (6/27)", 0x3a9c80, 0x3a9cc0 },
    { L"2H (7/27)", 0x3aaf90, 0x3aafd0 },
    { L"2H (8/27)", 0x3ac5a0, 0x3ac5e0 },
    { L"2H (9/27)", 0x3ada90, 0x3adad0 },
    { L"2H (10/27)", 0x3af030, 0x3af070 },
    { L"2H (11/27)", 0x3b0310, 0x3b0350 },
    { L"2H (12/27)", 0x3b1690, 0x3b16d0 },
    { L"2H (13/27)", 0x3b2a50, 0x3b2a90 },
    { L"2H (14/27)", 0x3b3be0, 0x3b3c20 },
    { L"2H (15/27)", 0x3b4cb0, 0x3b4cf0 },
    { L"2H (16/27)", 0x3b5b90, 0x3b5bd0 },
    { L"2H (17/27)", 0x3b6b70, 0x3b6bb0 },
    { L"2H (18/27)", 0x3b7bb0, 0x3b7bf0 },
    { L"2H (19/27)", 0x3b85d0, 0x3b8610 },
    { L"2H (20/27)", 0x3b9180, 0x3b91c0 },
    { L"2H (21/27)", 0x3b9d90, 0x3b9dd0 },
    { L"2H (22/27)", 0x3bac30, 0x3bac70 },
    { L"2H (23/27)", 0x3bb8f0, 0x3bb930 },
    { L"2H (24/27)", 0x3bc330, 0x3bc370 },
    { L"2H (25/27)", 0x3bcaa0, 0x3bcae0 },
    { L"2H (26/27)", 0x3bd280, 0x3bd2c0 },
    { L"2H (27/27)", 0x3bd680, 0x3bd6c0 },

    { L"j.D (1/3)", 0x3d5a00, 0x3d5a40 },
    { L"j.D (2/3)", 0x3d6c40, 0x3d6c80 },
    { L"j.D (3/3)", 0x3d7fd0, 0x3d8010 },
    //Specials
    { L"Mappa Hunch/Big Bang Upper (1/3)", 0x3d8720, 0x3d8760 },
    { L"Mappa Hunch/Big Bang Upper (2/3)", 0x3db0d0, 0x3db110 },
    { L"Mappa Hunch/Big Bang Upper (3/3)", 0x3dc3f0, 0x3dc430 },
    { L"Mappa Hunch Particles (1/4)", 0x3dcaf0, 0x3dcb30 },
    { L"Mappa Hunch Particles (2/4)", 0x3dcc70, 0x3dccb0 },
    { L"Mappa Hunch Particles (3/4)", 0x3dcdf0, 0x3dce30 },
    { L"Mappa Hunch Particles (4/4)", 0x3dcff0, 0x3dd030 },

    { L"Pilebunker (1/9)", 0x3cb1a0, 0x3cb1e0 },
    { L"Pilebunker (2/9)", 0x3cb490, 0x3cb4d0 },
    { L"Pilebunker (3/9)", 0x3cc2a0, 0x3cc2e0 },
    { L"Pilebunker (4/9)", 0x3cd450, 0x3cd490 },
    { L"Pilebunker (5/9)", 0x3cecc0, 0x3ced00 },
    { L"Pilebunker (6/9)", 0x3d0c80, 0x3d0cc0 },
    { L"Pilebunker (7/9)", 0x3d2860, 0x3d28a0 },
    { L"Pilebunker (8/9)", 0x3d3d80, 0x3d3dc0 },
    { L"Pilebunker (9/9)", 0x3d4de0, 0x3d4e20 },

    { L"Crosswise Heel (1/2)", 0x3bda60, 0x3bdaa0 },
    { L"Crosswise Heel (2/2)", 0x3c2cb0, 0x3c2cf0 },

    { L"Under Pressure (1/2)", 0x3dd620, 0x3dd660 },
    { L"Under Pressure (2/2)", 0x3dece0, 0x3ded20 },

    { L"It's Late (1/2)", 0x3e00a0, 0x3e00e0 },
    { L"It's Late (2/2)", 0x3e64c0, 0x3e6500 },

    { L"Undertow (1/5)", 0x42f620, 0x42f660 },
    { L"Undertow (2/5)", 0x4120a0, 0x4120e0 },
    { L"Undertow (3/5)", 0x419010, 0x419050 },
    { L"Undertow (4/5)", 0x425110, 0x425150 },
    { L"Undertow (5/5)", 0x42b900, 0x42b940 },
    //Force Breaks

    //Overdrives
    { L"Dead On Time (1/9)", 0x3e8320, 0x3e8360 },
    { L"Dead On Time (2/9)", 0x3e8510, 0x3e8550 },
    { L"Dead On Time (3/9)", 0x3e8970, 0x3e89b0 },
    { L"Dead On Time (4/9)", 0x3ec550, 0x3ec590 },
    { L"Dead On Time (5/9)", 0x3f07e0, 0x3f0820 },
    { L"Dead On Time (6/9)", 0x3f3c20, 0x3f3c60 },
    { L"Dead On Time (7/9)", 0x3f7520, 0x3f7560 },
    { L"Dead On Time (8/9)", 0x3f7af0, 0x3f7b30 },
    { L"Dead On Time (9/9)", 0x3f7f60, 0x3f7fa0 },

    { L"Eternal Wings (1/6)", 0x3f8130, 0x3f8170 },
    { L"Eternal Wings (2/6)", 0x3f8a90, 0x3f8ad0 },
    { L"Eternal Wings (3/6)", 0x3fa1d0, 0x3fa210 },
    { L"Eternal Wings (4/6)", 0x3fffe0, 0x400020 },
    { L"Eternal Wings (5/6)", 0x4068e0, 0x406920 },
    { L"Eternal Wings (6/6)", 0x40b0f0, 0x40b130 },
    { L"Eternal Wings Rings (1/5)", 0x40c850, 0x40c890 },
    { L"Eternal Wings Rings (2/5)", 0x40caa0, 0x40cae0 },
    { L"Eternal Wings Rings (3/5)", 0x40d740, 0x40d780 },
    { L"Eternal Wings Rings (4/5)", 0x40f3e0, 0x40f420 },
    { L"Eternal Wings Rings (5/5)", 0x411460, 0x4114a0 },

    { L"Up and Close Dandy (1/7)", 0x433790, 0x4337d0 },
    { L"Up and Close Dandy (2/7)", 0x435190, 0x4351d0 },
    { L"Up and Close Dandy (3/7)", 0x438020, 0x438060 },
    { L"Up and Close Dandy (4/7)", 0x43a4f0, 0x43a530 },
    { L"Up and Close Dandy (5/7)", 0x43c3a0, 0x43c3e0 },
    { L"Up and Close Dandy (6/7)", 0x43dd50, 0x43dd90 },
    { L"Up and Close Dandy (7/7)", 0x43e6d0, 0x43e710 },
    //Instant Kill
    { L"All Dead -  Background", 0x43f320, 0x43f720 },
    { L"All Dead -  Shine (1/6)", 0x4636e0, 0x463720 },
    { L"All Dead -  Shine (2/6)", 0x463820, 0x463860 },
    { L"All Dead -  Shine (3/6)", 0x463b90, 0x463bd0 },
    { L"All Dead -  Shine (4/6)", 0x464550, 0x464590 },
    { L"All Dead -  Shine (5/6)", 0x464fd0, 0x465010 },
    { L"All Dead -  Shine (6/6)", 0x465840, 0x465880 },
    { L"All Dead -  Haiku (1/18)", 0x471100, 0x471140 },
    { L"All Dead -  Haiku (2/18)", 0x472830, 0x472870 },
    { L"All Dead -  Haiku (3/18)", 0x474020, 0x474060 },
    { L"All Dead -  Haiku (4/18)", 0x475780, 0x4757c0 },
    { L"All Dead -  Haiku (5/18)", 0x4770d0, 0x477110 },
    { L"All Dead -  Haiku (6/18)", 0x478a80, 0x478ac0 },
    { L"All Dead -  Haiku (7/18)", 0x479540, 0x479580 },
    { L"All Dead -  Haiku (8/18)", 0x47b320, 0x47b360 },
    { L"All Dead -  Haiku (9/18)", 0x47d0c0, 0x47d100 },
    { L"All Dead -  Haiku (10/18)", 0x47ed90, 0x47edd0 },
    { L"All Dead -  Haiku (11/18)", 0x480c50, 0x480c90 },
    { L"All Dead -  Haiku (12/18)", 0x482c00, 0x482c40 },
    { L"All Dead -  Haiku (13/18)", 0x483780, 0x4837c0 },
    { L"All Dead -  Haiku (14/18)", 0x484de0, 0x484e20 },
    { L"All Dead -  Haiku (15/18)", 0x486830, 0x486870 },
    { L"All Dead -  Haiku (16/18)", 0x488030, 0x488070 },
    { L"All Dead -  Haiku (17/18)", 0x4898a0, 0x4898e0 },
    { L"All Dead -  Haiku (18/18)", 0x48b1f0, 0x48b230 },
};

const sGame_PaletteDataset GGXXACR_S_VE_EFFECTS[] =
{
    //General
    { L"Ball Glow", 0x26d330, 0x26d370 },

    { L"Charge/Lightning Ball (1/3)", 0x26f610, 0x26f650 },
    { L"Charge/Lightning Ball (2/3)", 0x270f70, 0x270fb0 },
    { L"Charge/Lightning Ball (3/3)", 0x273580, 0x2735c0 },

    { L"Grab (1/3)", 0x294d50, 0x294d90 },
    { L"Grab (2/3)", 0x294170, 0x2941b0 },
    { L"Grab (3/3)", 0x293840, 0x293880 },
    //Specials
    { L"Stinger Aim Impacts", 0x26b0d0, 0x26b110 },
    { L"Carcass Ride Impacts", 0x26c180, 0x26c1c0 },

    { L"Dubious Curve - Slam", 0x28a3d0, 0x28a410 },
    { L"Dubious Curve - Swipe", 0x290220, 0x290260 },

    { L"Mad Struggle (1/4)", 0x267640, 0x267a40 },
    { L"Mad Struggle (2/4)", 0x268040, 0x268440 },
    { L"Mad Struggle (3/4)", 0x268ea0, 0x2692a0 },
    { L"Mad Struggle (4/4)", 0x269b90, 0x269f90 },
    //Overdrives
    { L"Dark Angel", 0x277b40, 0x277b80 },
    { L"Dark Angel Effects (1/2)", 0x280bf0, 0x280c30 },
    { L"Dark Angel Effects (2/2)", 0x282420, 0x282460 },
    //Instant Kill
    { L"Dimmu Borgir (1, 4, 5, 7)", 0x289450, 0x289510 },
    { L"Dimmu Borgir (6, 2, 8, 3)", 0x289c10, 0x289cd0 },
    { L"Dimmu Borgir - Explosion (1/6)", 0x282b90, 0x282bd0 },
    { L"Dimmu Borgir - Explosion (2/6)", 0x283560, 0x2835a0 },
    { L"Dimmu Borgir - Explosion (3/6)", 0x284ad0, 0x284b10 },
    { L"Dimmu Borgir - Explosion (4/6)", 0x286720, 0x286760 },
    { L"Dimmu Borgir - Explosion (5/6)", 0x287c50, 0x287c90 },
    { L"Dimmu Borgir - Explosion (6/6)", 0x288cf0, 0x288d30 },

    //{ L"Unused 1?", 0x26e1e0, 0x26e220 }, 
    //{ L"Unused 2?", 0x26e2f0, 0x26e330 },     
};

const sGame_PaletteDataset GGXXACR_S_Sidebar_Portraits[] =
{
    { L"Type A Background (Left)",  0x110, 0x510, indexGGXXSprites_ACR_Bonus, 0x00 },
    { L"Type A Background (Right)", 0x162E0, 0x166E0, indexGGXXSprites_ACR_Bonus, 0x01 },
    // Type B
        { L"Type B Background (Left)",  0x2D850, 0x2DC50, indexGGXXSprites_ACR_Bonus, 0x02 },
        { L"Type B Background (Right)", 0x43C20, 0x44020, indexGGXXSprites_ACR_Bonus, 0x03 },
        // Type C Portraits
            { L"Type C A.B.A",              0x773D0, 0x777D0, indexGGXXSprites_ACR_ABA, 0x40 },
            { L"Type C Anji",               0x7B8D0, 0x7BcD0, indexGGXXSprites_ACR_Anji, 0x40 },
            { L"Type C Axl",                0x7F4B0, 0x7F8B0, indexGGXXSprites_ACR_Axl, 0x40 },
            { L"Type C Baiken",             0x82d10, 0x83110, indexGGXXSprites_ACR_Baiken, 0x40 },
            { L"Type C Bridget",            0x865f0, 0x869f0, indexGGXXSprites_ACR_Bridget, 0x40 },
            { L"Type C Chipp",              0x8A6A0, 0x8AAA0, indexGGXXSprites_ACR_Chipp, 0x40 },
            { L"Type C Dizzy",              0x91C50, 0x92050, indexGGXXSprites_ACR_Dizzy, 0x40 },
            { L"Type C Eddie",              0xd0f40, 0xd1340, indexGGXXSprites_ACR_Eddie, 0x40 },
            { L"Type C Faust",              0x96120, 0x96520, indexGGXXSprites_ACR_Faust, 0x40 },
            { L"Type C I-no",               0x99A50, 0x99E50, indexGGXXSprites_ACR_Ino, 0x40 },
            { L"Type C Jam",                0x9D2b0, 0x9D6b0, indexGGXXSprites_ACR_Jam, 0x40 },
            { L"Type C Johnny",             0xA0C60, 0xA1060, indexGGXXSprites_ACR_Johnny, 0x40 },
            { L"Type C Justice",            0xA4890, 0xA4c90, indexGGXXSprites_ACR_Justice, 0x40 },
            { L"Type C Kliff",              0x8DBC0, 0x8DFC0, indexGGXXSprites_ACR_Kliff, 0x40 },
            { L"Type C Ky",                 0xA9070, 0xA9470, indexGGXXSprites_ACR_Ky, 0x40 },
            { L"Type C May",                0xAC7f0, 0xACBf0, indexGGXXSprites_ACR_May, 0x40 },
            { L"Type C Millia",             0xB0600, 0xB0A00, indexGGXXSprites_ACR_Millia, 0x40 },
            { L"Type C Order-Sol",          0xB4350, 0xB4750, indexGGXXSprites_ACR_OrderSol, 0x40 },
            { L"Type C Potemkin",           0xB83F0, 0xB87F0, indexGGXXSprites_ACR_Potemkin, 0x40 },
            { L"Type C Robo-Ky",            0xBBA20, 0xBBE20, indexGGXXSprites_ACR_RoboKy, 0x40 },
            { L"Type C Slayer",             0xBF2f0, 0xBF6f0, indexGGXXSprites_ACR_Slayer, 0x40 },
            { L"Type C Sol",                0xC2550, 0xC2950, indexGGXXSprites_ACR_Sol, 0x40 },
            { L"Type C Testament",          0xC5AC0, 0xC5EC0, indexGGXXSprites_ACR_Testament, 0x40 },
            { L"Type C Venom",              0xC9AD0, 0xC9ED0, indexGGXXSprites_ACR_Venom, 0x40 },
            { L"Type C Zappa",              0xCCE20, 0xCD220, indexGGXXSprites_ACR_Zappa, 0x40 },
            { L"Type C Background (Left)",  0x599D0, 0x59DD0, indexGGXXSprites_ACR_Bonus, 0x04 },
            { L"Type C Background (Right)", 0x686D0, 0x68AD0, indexGGXXSprites_ACR_Bonus, 0x04 },
            // Type D Portraits
                { L"Type D A.B.A",              0x2522a0, 0x2526A0, indexGGXXSprites_ACR_ABA, 0x41 },
                { L"Type D Anji",               0x1b05c0, 0x1B09C0, indexGGXXSprites_ACR_Anji, 0x41 },
                { L"Type D Axl",                0x11edb0, 0x11F1B0, indexGGXXSprites_ACR_Axl, 0x41 },
                { L"Type D Baiken",             0x167e80, 0x168280, indexGGXXSprites_ACR_Baiken, 0x41 },
                { L"Type D Bridget",            0x22dba0, 0x22DFA0, indexGGXXSprites_ACR_Bridget, 0x41 },
                { L"Type D Chipp",              0x1427e0, 0x142BE0, indexGGXXSprites_ACR_Chipp, 0x41 },
                { L"Type D Dizzy",              0x1e7c40, 0x1E8040, indexGGXXSprites_ACR_Dizzy, 0x41 },
                { L"Type D Eddie",              0x1559f0, 0x155DF0, indexGGXXSprites_ACR_Eddie, 0x41 },
                { L"Type D Faust",              0x178a50, 0x178E50, indexGGXXSprites_ACR_Faust, 0x41 },
                { L"Type D I-No",               0x20af00, 0x20B300, indexGGXXSprites_ACR_Ino, 0x41 },
                { L"Type D Jam",                0x19cb60, 0x19CF60, indexGGXXSprites_ACR_Jam, 0x41 },
                { L"Type D Johnny",             0x1c2c50, 0x1C3050, indexGGXXSprites_ACR_Johnny, 0x41 },
                { L"Type D Justice",            0x28b810, 0x28BC10, indexGGXXSprites_ACR_Justice, 0x41 },
                { L"Type D Kliff",              0x2773b0, 0x2777B0, indexGGXXSprites_ACR_Kliff, 0x41 },
                { L"Type D Ky",                 0xe7620, 0xe7A20, indexGGXXSprites_ACR_Ky, 0x41 },
                { L"Type D May",                0xf9ac0, 0xf9Ec0, indexGGXXSprites_ACR_May, 0x41 },
                { L"Type D Millia",             0x10cee0, 0x10D2E0, indexGGXXSprites_ACR_Millia, 0x41 },
                { L"Type D Order-Sol",          0x2656c0, 0x265AC0, indexGGXXSprites_ACR_OrderSol, 0x41 },
                { L"Type D Potemkin",           0x131090, 0x131490, indexGGXXSprites_ACR_Potemkin, 0x41 },
                { L"Type D Robo-Ky",            0x2401A0, 0x2405A0, indexGGXXSprites_ACR_RoboKy, 0x41 },
                { L"Type D Slayer",             0x1f9e80, 0x1FA280, indexGGXXSprites_ACR_Slayer, 0x41 },
                { L"Type D Sol",                0xd4cf0, 0xd50f0, indexGGXXSprites_ACR_Sol, 0x41 },
                { L"Type D Testament",          0x189dc0, 0x18A1C0, indexGGXXSprites_ACR_Testament, 0x41 },
                { L"Type D Venom",              0x1d4a40, 0x1D4E40, indexGGXXSprites_ACR_Venom, 0x41 },
                { L"Type D Zappa",              0x21CCC0, 0x21D0C0, indexGGXXSprites_ACR_Zappa, 0x41 },
                { L"Type D Background",         0x29c220, 0x29C620, indexGGXXSprites_ACR_Bonus, 0x05 },
};

const sGame_PaletteDataset GGXXACR_S_HUDMenu[] =
{
    //Will expand to include more menu palettes at a later date
    //Missing RISC meter, Tension meter, gauge for stagger, Character HUD Portraits, and Character specific meters (some might be in their own .bin files) for HUD

    { L"Main HUD",                      0x9640, 0x9680 },

    { L"Health",                        0x8580, 0x85c0 },  //Full health palette (green) is done by taking the normal heatlh value and ignoring the R and B values, not its own palette 
    { L"Health Glow",                   0x8330, 0x8370 },
    { L"Health Shine",                  0x1840, 0x1880 },

    { L"Timer Background",              0x7bc0, 0x7c00 },
    { L"Timer Numbers",                 0x9260, 0x92a0 },
    { L"Timer Numbers (Infinite time)", 0x7ed0, 0x7f10 },   //Training mode and possibly somewhere else? unsure so leaving as Infinte for now

    { L"Round Counters",                0x1ee650, 0x1ee690 },
    { L"Round Counters (Win)",          0x1ee770, 0x1ee7b0 },

    { L"Burst",                         0x60b0, 0x60f0 },
    { L"Burst Denied",                  0x7840, 0x7880 },
    { L"Burst Refilling",               0x6bf0, 0x6c30 },
    { L"Burst Glow",                    0x71d0, 0x7210 },

    { L"Tension (P1)",                  0x8a30, 0x8a70 },
    { L"Tension Background (P1)",       0x8970, 0x89b0 },
    { L"Tension (P2)",                  0xbb80, 0xbbc0 },
    { L"Tension Background (P2)",       0xb670, 0xb6b0 },

    { L"Combo Counter",                 0x2d00, 0x2d40 },
    { L"Character names",               0x2e0, 0x320 },
    { L"Text (1/3)",                    0x7bcf0, 0x7bd30 },
    { L"Text (2/3)",                    0x7c1f0, 0x7c230 },
    { L"Text (3/3)",                    0x7c7d0, 0x7c810 },

    { L"Stagger joystick (1/3)",        0x1edf50, 0x1edf90 },
    { L"Stagger joystick (2/3)",        0x1ee180, 0x1ee1c0 },
    { L"Stagger joystick (3/3)",        0x1ee3e0, 0x1ee420 },
    { L"Dizzy Angels",                  0x1e7de0, 0x1e7e20 },

    { L"Instant Kill Border",           0x1a860, 0x1a8a0 },
    { L"Instant Kill Letters (D)",      0x13890, 0x138d0 },
    { L"Instant Kill Letters (E)",      0x14460, 0x144a0 },
    { L"Instant Kill Letters (S)",      0x14d90, 0x14dd0 },
    { L"Instant Kill Letters (T)",      0x154c0, 0x15500 },
    { L"Instant Kill Letters (R)",      0x15a90, 0x15ad0 },
    { L"Instant Kill Letters (O)",      0x16110, 0x16150 },
    { L"Instant Kill Letters (Y)",      0x167d0, 0x16810 },
    { L"Instant Kill Letters (E)",      0x16e70, 0x16eb0 },
    { L"Instant Kill Letters (D)",      0x17720, 0x17760 },

    //May and Zappa have their own Instant Kill screens, D and E letters are reused for both
    { L"May Instant Kill Dolphin (1/3)",    0x563b0, 0x563f0 },
    { L"May Instant Kill Dolphin (2/3)",    0x56a60, 0x56aa0 },
    { L"May Instant Kill Dolphin (3/3)",    0x570f0, 0x57130 },
    { L"May Instant Kill Stars",            0x56290, 0x562d0 },
    { L"May Instant Kill Letters (D)",      0x53690, 0x536d0 },
    { L"May Instant Kill Letters (E)",      0x53dc0, 0x53e00 },
    { L"May Instant Kill Letters (S)",      0x54390, 0x543d0 },
    { L"May Instant Kill Letters (T)",      0x54a30, 0x54a70 },
    { L"May Instant Kill Letters (R)",      0x54ec0, 0x54f00 },
    { L"May Instant Kill Letters (O)",      0x555d0, 0x55610 },
    { L"May Instant Kill Letters (Y)",      0x55d30, 0x55d70 },

    { L"Zappa Instant Kill Eye",                        0x71c10, 0x71c50 },
    { L"Zappa Instant Kill Scanlines",                  0x70300, 0x70340 },
    { L"Zappa Instant Kill Static",                     0x70380, 0x703c0 },
    { L"Zappa Instant Kill Screen Edge (Top/Bottom)",   0x700c0, 0x70100 },
    { L"Zappa Instant Kill Screen Edge (Left/Right)",   0x701f0, 0x70230 },
    { L"Zappa Instant Kill Screen Edge (Corners)",      0x70280, 0x702c0 },
    { L"Zappa Instant Kill Letters (D)",                0x6e740, 0x6e780 },
    { L"Zappa Instant Kill Letters (E)",                0x6eb00, 0x6eb40 },
    { L"Zappa Instant Kill Letters (S)",                0x6eef0, 0x6ef30 },
    { L"Zappa Instant Kill Letters (T)",                0x6f2c0, 0x6f300 },
    { L"Zappa Instant Kill Letters (R)",                0x6f610, 0x6f650 },
    { L"Zappa Instant Kill Letters (O)",                0x6fa10, 0x6fa50 },
    { L"Zappa Instant Kill Letters (Y)",                0x6fdb0, 0x6fdf0 },
};

const sGame_PaletteDataset GGXXACR_S_Effects_JPF[] =
{
    //Leaving out hitsparks for now since theres so many, but they are in the archive_jpf.bin file

    { L"Roman Cancel",       0x1c9680, 0x1c96c0 },
    { L"Force Roman Cancel", 0x1c9880, 0x1c98c0 },
    //Missing Yellow RC and Chaos RC

    { L"Burst (1/12)",  0x1806f0, 0x180af0 },
    { L"Burst (2/12)",  0x185ea0, 0x1862a0 },
    { L"Burst (3/12)",  0x189fe0, 0x18a3e0 },
    { L"Burst (4/12)",  0x18c7e0, 0x18cbe0 },
    { L"Burst (5/12)",  0x18dc40, 0x18e040 },
    { L"Burst (6/12)",  0x1902b0, 0x1906b0 },
    { L"Burst (7/12)",  0x192fb0, 0x1933b0 },
    { L"Burst (8/12)",  0x195fd0, 0x1963d0 },
    { L"Burst (9/12)",  0x198930, 0x198d30 },
    { L"Burst (10/12)", 0x19afa0, 0x19b3a0 },
    { L"Burst (11/12)", 0x19d1e0, 0x19d5e0 },
    { L"Burst (12/12)", 0x19f010, 0x19f410 },
    { L"Gold Burst (1/12)",  0x160570, 0x160970 },
    { L"Gold Burst (2/12)",  0x165d20, 0x166120 },
    { L"Gold Burst (3/12)",  0x169e60, 0x16a260 },
    { L"Gold Burst (4/12)",  0x16c660, 0x16ca60 },
    { L"Gold Burst (5/12)",  0x16dac0, 0x16dec0 },
    { L"Gold Burst (6/12)",  0x170130, 0x170530 },
    { L"Gold Burst (7/12)",  0x172e30, 0x173230 },
    { L"Gold Burst (8/12)",  0x175e50, 0x176250 },
    { L"Gold Burst (9/12)",  0x1787b0, 0x178bb0 },
    { L"Gold Burst (10/12)", 0x17ae20, 0x17b220 },
    { L"Gold Burst (11/12)", 0x17d060, 0x17d460 },
    { L"Gold Burst (12/12)", 0x17ee90, 0x17f290 },

    //I may be missing some palettes here
    { L"Overdrive Actvation Rings",      0x1c74c0, 0x1c7500 },
    { L"Overdrive Background",           0x1f4290, 0x1f42d0 },
    { L"Overdrive Background (Layer 2)", 0x203360, 0x2033a0 },

    //Dust effects for movement, certain stages swap these out for stage specific effects that can be found in the stages file
    //eg. Grove uses water effects, which palettes are stored in bg_dz.cmp, and not with these otherwise universal effects
    { L"Jumping Dust Effects (1/8)", 0x1d45a0, 0x1d45e0 },
    { L"Jumping Dust Effects (2/8)", 0x1d5d00, 0x1d5d40 },
    { L"Jumping Dust Effects (3/8)", 0x1d6be0, 0x1d6c20 },
    { L"Jumping Dust Effects (4/8)", 0x1d85f0, 0x1d8630 },
    { L"Jumping Dust Effects (5/8)", 0x1d9d10, 0x1d9d50 },
    { L"Jumping Dust Effects (6/8)", 0x1db130, 0x1db170 },
    { L"Jumping Dust Effects (7/8)", 0x1dc410, 0x1dc450 },
    { L"Jumping Dust Effects (8/8)", 0x1dd3b0, 0x1dd3f0 },
    { L"Landing Dust Effects",       0x1dfaf0, 0x1dfb30 },
    { L"Running Dust Effects (1/3)", 0x1de1f0, 0x1de230 },
    { L"Running Dust Effects (2/3)", 0x1de9a0, 0x1de9e0 },
    { L"Running Dust Effects (3/3)", 0x1df380, 0x1df3c0 },

    //May uses her own dust palettes for tons of attacks, these also change based on the stage
    { L"May Dust Effects (1/7)", 0x1e1860, 0x1e18a0 },
    { L"May Dust Effects (2/7)", 0x1e2610, 0x1e2650 },
    { L"May Dust Effects (3/7)", 0x1e2e50, 0x1e2e90 },
    { L"May Dust Effects (4/7)", 0x1e3d60, 0x1e3da0 },
    { L"May Dust Effects (5/7)", 0x1e4990, 0x1e49d0 },
    { L"May Dust Effects (6/7)", 0x1e5500, 0x1e5540 },
    { L"May Dust Effects (7/7)", 0x1e6490, 0x1e64d0 },
};

//unsure if theres a better way to add this palette, works for now
const sGame_PaletteDataset GGXXACR_S_Title[] =
{
    { L"Title Screen", 0x7AC70, 0x7B070 },
};

GGXXACRFileData GGXXACR_S_CharacterData[] =
{
    { L"ab.bin",    L"A.B.A.",          5715300,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x48ab50, indexGGXXSprites_ACR_ABA, GGXXACR_S_AB_EFFECTS, ARRAYSIZE(GGXXACR_S_AB_EFFECTS) },
    { L"an.bin",    L"Anji",            4518932,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x3ea460, indexGGXXSprites_ACR_Anji },
    { L"ax.bin",    L"Axl Low" ,        4225716,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x35ebe0, indexGGXXSprites_ACR_Axl },
    { L"bk.bin",    L"Baiken",          3573668,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x308c20, indexGGXXSprites_ACR_Baiken, GGXXACR_S_BK_EFFECTS, ARRAYSIZE(GGXXACR_S_BK_EFFECTS) },
    { L"ch.bin",    L"Chipp Zanuff",    3113988,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x293560, indexGGXXSprites_ACR_Chipp },
    { L"dz.bin",    L"Dizzy",           5352324,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x45d720, indexGGXXSprites_ACR_Dizzy },
    { L"fa.bin",    L"Faust",           4773284,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x3fe9a0, indexGGXXSprites_ACR_Faust },
    { L"fr.bin",    L"Order Sol",       5772356,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x4377e0, indexGGXXSprites_ACR_OrderSol },
    { L"in.bin",    L"I-No",            5609060,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x3e5370, indexGGXXSprites_ACR_Ino, GGXXACR_S_IN_EFFECTS, ARRAYSIZE(GGXXACR_S_IN_EFFECTS) },
    { L"jm.bin",    L"Jam",             3827044,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x2c4e80, indexGGXXSprites_ACR_Jam },
    { L"js.bin",    L"Justice",         4556788,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x3789b0, indexGGXXSprites_ACR_Justice },
    { L"jy.bin",    L"Johnny",          4205892,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x3b0620, indexGGXXSprites_ACR_Johnny, GGXXACR_S_JY_EFFECTS, ARRAYSIZE(GGXXACR_S_JY_EFFECTS) },
    { L"kr.bin",    L"Kliff Undersn",   3114036,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x28abf0, indexGGXXSprites_ACR_Kliff },
    { L"ky.bin",    L"Ky",              4571540,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x38bbc0, indexGGXXSprites_ACR_Ky, GGXXACR_S_KY_EFFECTS, ARRAYSIZE(GGXXACR_S_KY_EFFECTS) },
    { L"ml.bin",    L"Millia",          3034084,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x2a4950, indexGGXXSprites_ACR_Millia },
    { L"my.bin",    L"May",             4311684,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x363d50, indexGGXXSprites_ACR_May },
    { L"po.bin",    L"Potemkin",        5277348,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x489c70, indexGGXXSprites_ACR_Potemkin, GGXXACR_S_PO_EFFECTS, ARRAYSIZE(GGXXACR_S_PO_EFFECTS) },
    { L"rk.bin",    L"Robo-Ky",         4489668,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x3a7450, indexGGXXSprites_ACR_RoboKy },
    { L"sl.bin",    L"Sol Badguy",      4613188,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x339b60, indexGGXXSprites_ACR_Sol, GGXXACR_S_SL_EFFECTS, ARRAYSIZE(GGXXACR_S_SL_EFFECTS) },
    { L"sy.bin",    L"Slayer",          6215652,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x39c960, indexGGXXSprites_ACR_Slayer, GGXXACR_S_SY_EFFECTS, ARRAYSIZE(GGXXACR_S_SY_EFFECTS) },
    { L"ts.bin",    L"Testament",       4817508,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x3ee950, indexGGXXSprites_ACR_Testament },
    { L"ve.bin",    L"Venom",           2787412,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x261c10, indexGGXXSprites_ACR_Venom, GGXXACR_S_VE_EFFECTS, ARRAYSIZE(GGXXACR_S_VE_EFFECTS) },
    { L"yy.bin",    L"Bridget",         4127716,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x34b210, indexGGXXSprites_ACR_Bridget },
    { L"zp.bin",    L"Zappa",           6019988,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x2a54f0, indexGGXXSprites_ACR_Zappa },
    { L"zt.bin",    L"Eddie",           3289156,    GGXXACRPaletteNamesNormal,    ARRAYSIZE(GGXXACRPaletteNamesNormal), 0x24e560, indexGGXXSprites_ACR_Eddie },
    { L"eab.bin",   L"EX A.B.A.",       5912564,    GGXXACRPaletteNamesEx,        ARRAYSIZE(GGXXACRPaletteNamesEx),     0x4b3ca0, indexGGXXSprites_ACR_ABA },
    { L"ean.bin",   L"EX Anji",         4520900,    GGXXACRPaletteNamesEx,        ARRAYSIZE(GGXXACRPaletteNamesEx),     0x3eb460, indexGGXXSprites_ACR_Anji },
    { L"eax.bin",   L"EX Axl Low",      4217220,    GGXXACRPaletteNamesEx,        ARRAYSIZE(GGXXACRPaletteNamesEx),     0x35edf0, indexGGXXSprites_ACR_Axl },
    { L"ebk.bin",   L"EX Baiken",       3601604,    GGXXACRPaletteNamesEx,        ARRAYSIZE(GGXXACRPaletteNamesEx),     0x309920, indexGGXXSprites_ACR_Baiken },
    { L"ech.bin",   L"EX Chipp Zanuff", 3162804,    GGXXACRPaletteNamesEx,        ARRAYSIZE(GGXXACRPaletteNamesEx),     0x29f630, indexGGXXSprites_ACR_Chipp },
    { L"edz.bin",   L"EX Dizzy",        5594900,    GGXXACRPaletteNamesEx,        ARRAYSIZE(GGXXACRPaletteNamesEx),     0x49a2c0, indexGGXXSprites_ACR_Dizzy },
    { L"efa.bin",   L"EX Faust",        4784260,    GGXXACRPaletteNamesEx,        ARRAYSIZE(GGXXACRPaletteNamesEx),     0x3fe9f0, indexGGXXSprites_ACR_Faust },
    { L"efr.bin",   L"EX Order-Sol",    5965396,    GGXXACRPaletteNamesEx,        ARRAYSIZE(GGXXACRPaletteNamesEx),     0x45d9d0, indexGGXXSprites_ACR_OrderSol },
    { L"ein.bin",   L"EX I-No",         5762996,    GGXXACRPaletteNamesEx,        ARRAYSIZE(GGXXACRPaletteNamesEx),     0x3f9060, indexGGXXSprites_ACR_Ino },
    { L"ejm.bin",   L"EX Jam",          3812100,    GGXXACRPaletteNamesEx,        ARRAYSIZE(GGXXACRPaletteNamesEx),     0x2c46d0, indexGGXXSprites_ACR_Jam },
    { L"ejy.bin",   L"EX Johnny",       4210036,    GGXXACRPaletteNamesEx,        ARRAYSIZE(GGXXACRPaletteNamesEx),     0x3b2250, indexGGXXSprites_ACR_Johnny },
    { L"eky.bin",   L"EX Ky",           4859572,    GGXXACRPaletteNamesEx,        ARRAYSIZE(GGXXACRPaletteNamesEx),     0x3cafd0, indexGGXXSprites_ACR_Ky },
    { L"eml.bin",   L"EX Millia",       3003428,    GGXXACRPaletteNamesEx,        ARRAYSIZE(GGXXACRPaletteNamesEx),     0x29d9c0, indexGGXXSprites_ACR_Millia },
    { L"emy.bin",   L"EX May",          4675812,    GGXXACRPaletteNamesEx,        ARRAYSIZE(GGXXACRPaletteNamesEx),     0x399780, indexGGXXSprites_ACR_May },
    { L"epo.bin",   L"EX Potemkin",     5313412,    GGXXACRPaletteNamesEx,        ARRAYSIZE(GGXXACRPaletteNamesEx),     0x494170, indexGGXXSprites_ACR_Potemkin },
    { L"erk.bin",   L"EX Robo-Ky",      4599332,    GGXXACRPaletteNamesEx,        ARRAYSIZE(GGXXACRPaletteNamesEx),     0x3cfc80, indexGGXXSprites_ACR_RoboKy },
    { L"esl.bin",   L"EX Sol Badguy",   4679684,    GGXXACRPaletteNamesEx,        ARRAYSIZE(GGXXACRPaletteNamesEx),     0x33b380, indexGGXXSprites_ACR_Sol },
    { L"esy.bin",   L"EX Slayer",       6221972,    GGXXACRPaletteNamesEx,        ARRAYSIZE(GGXXACRPaletteNamesEx),     0x39ea30, indexGGXXSprites_ACR_Slayer },
    { L"ets.bin",   L"EX Testament",    4775796,    GGXXACRPaletteNamesEx,        ARRAYSIZE(GGXXACRPaletteNamesEx),     0x3f4780, indexGGXXSprites_ACR_Testament },
    { L"eve.bin",   L"EX Venom",        2848292,    GGXXACRPaletteNamesEx,        ARRAYSIZE(GGXXACRPaletteNamesEx),     0x271200, indexGGXXSprites_ACR_Venom },
    { L"eyy.bin",   L"EX Bridget",      4206820,    GGXXACRPaletteNamesEx,        ARRAYSIZE(GGXXACRPaletteNamesEx),     0x35d790, indexGGXXSprites_ACR_Bridget },
    { L"ezp.bin",   L"EX Zappa",        6044292,    GGXXACRPaletteNamesEx,        ARRAYSIZE(GGXXACRPaletteNamesEx),     0x2a2e90, indexGGXXSprites_ACR_Zappa },
    { L"ezt.bin",   L"EX Eddie",        3185140,    GGXXACRPaletteNamesEx,        ARRAYSIZE(GGXXACRPaletteNamesEx),     0x275d30, indexGGXXSprites_ACR_Eddie },
    { L"..\\..\\..\\demo\\side_belt.bin",   L"Sidebar Portraits",   2794128, nullptr,                                0,        0x110,                           -1, GGXXACR_S_Sidebar_Portraits, ARRAYSIZE(GGXXACR_S_Sidebar_Portraits) },
    { L"..\\demo\\archive_jpf.bin",         L"HUD/Menu",            3040848, nullptr,                                0,        0x2e0,                           -1, GGXXACR_S_HUDMenu, ARRAYSIZE(GGXXACR_S_HUDMenu) },
    { L"..\\demo\\archive_jpf.bin",         L"Effects",             3040848, nullptr,                                0,        0x1806f0,                        -1, GGXXACR_S_Effects_JPF, ARRAYSIZE(GGXXACR_S_Effects_JPF) },
    { L"..\\demo\\titleall.bin",            L"Title Screen",        5281296, nullptr,                                0,        0x7AC70,                         -1, GGXXACR_S_Title, ARRAYSIZE(GGXXACR_S_Title) },
};
