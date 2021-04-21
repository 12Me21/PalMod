#pragma once

// To add characters or palette lists:
// * Update the DumpPaletteHeaders code
// * Uncomment the call to it
// * Run PalMod and copy the debug output into the header
// That should be it.  Good luck.

const UINT16 KOF96_A_IMG_UNITS[] =
{
    indexKOF94Sprites_Kyo,
    indexKOF94Sprites_Benimaru,
    indexKOFSprites_98Daimon,
    indexKOF94Sprites_Terry,
    indexKOF97Sprites_Andy,
    indexKOF94Sprites_Joe,
    indexKOF94Sprites_Ryo,
    indexKOF94Sprites_Robert,
    indexKOF94Sprites_Yuri,
    indexKOFSprites_98Leona,
    indexKOF94Sprites_Ralf,
    indexKOF94Sprites_Clark,
    indexKOF94Sprites_Athena,
    indexKOF94Sprites_Kensou,
    indexKOF94Sprites_Chin,
    indexKOFSprites_00Kasumi,
    indexKOF94Sprites_Mai,
    indexKOFSprites_98King,
    indexKOFSprites_98Kim,
    indexKOFSprites_98Chang,
    indexKOFSprites_98Choi,
    indexKOFSprites_98Iori,
    indexKOFSprites_98Mature,
    indexKOFSprites_98Vice,
    indexKOFSprites_02Geese,
    indexRBFFSSprites_Krauser,
    indexAoF1Sprites_MrBig,
    indexKOFSprites_98Chizuru,
    indexKOFSprites_02Goenitz,
};

const sGame_PaletteDataset KOF96_A_KYO_A_PALETTES[] =
{
    { L"Kyo", 0x102002, 0x102022, indexKOF94Sprites_Kyo, 0x00 },
    { L"Extra 1", 0x102022, 0x102042 },
    { L"Super Trail 1", 0x102042, 0x102062, indexKOF94Sprites_Kyo, 0x00 },
    { L"Super Trail 2", 0x102062, 0x102082 },
    { L"MAX Mode", 0x102082, 0x1020a2, indexKOF94Sprites_Kyo, 0x00 },
    { L"Extra 1", 0x1020a2, 0x1020c2 },
    { L"Electric Palette?", 0x1020c2, 0x1020e2, indexKOF94Sprites_Kyo, 0x00 },
    { L"Extra 3", 0x1020e2, 0x102102 },
    { L"Extra 5", 0x102122, 0x102142 },
    { L"Extra 6", 0x102142, 0x102162 },
    { L"Extra 7", 0x102162, 0x102182 },
    { L"Extra 8", 0x102182, 0x1021a2 },
    { L"Monochrome Palette", 0x1021a2, 0x1021c2, indexKOF94Sprites_Kyo, 0x00 },
    { L"Extra 9", 0x1021c2, 0x1021e2 },
    { L"Lifebar Portrait", 0x1021e2, 0x102202, indexKOF94Sprites_Kyo, 0x20 },
};

const sGame_PaletteDataset KOF96_A_KYO_D_PALETTES[] =
{
    { L"Kyo", 0x102202, 0x102222, indexKOF94Sprites_Kyo, 0x00 },
    { L"Extra 1", 0x102222, 0x102242 },
    { L"Super Trail 1", 0x102242, 0x102262, indexKOF94Sprites_Kyo, 0x00 },
    { L"Super Trail 2", 0x102262, 0x102282 },
    { L"MAX Mode", 0x102282, 0x1022a2, indexKOF94Sprites_Kyo, 0x00 },
    { L"Extra 1", 0x1022a2, 0x1022c2 },
    { L"Electric Palette?", 0x1022c2, 0x1022e2, indexKOF94Sprites_Kyo, 0x00 },
    { L"Extra 3", 0x1022e2, 0x102302 },
    { L"Extra 5", 0x102322, 0x102342 },
    { L"Extra 6", 0x102342, 0x102362 },
    { L"Extra 7", 0x102362, 0x102382 },
    { L"Extra 8", 0x102382, 0x1023a2 },
    { L"Monochrome Palette", 0x1023a2, 0x1023c2, indexKOF94Sprites_Kyo, 0x00 },
    { L"Extra 9", 0x1023c2, 0x1023e2 },
    { L"Lifebar Portrait", 0x1023e2, 0x102402, indexKOF94Sprites_Kyo, 0x20 },
};

const sGame_PaletteDataset KOF96_A_BENIMARU_A_PALETTES[] =
{
    { L"Benimaru", 0x102402, 0x102422, indexKOF94Sprites_Benimaru, 0x00 },
    { L"Extra 1", 0x102422, 0x102442 },
    { L"Super Trail 1", 0x102442, 0x102462, indexKOF94Sprites_Benimaru, 0x00 },
    { L"Super Trail 2", 0x102462, 0x102482 },
    { L"MAX Mode", 0x102482, 0x1024a2, indexKOF94Sprites_Benimaru, 0x00 },
    { L"Extra 1", 0x1024a2, 0x1024c2 },
    { L"Electric Palette?", 0x1024c2, 0x1024e2, indexKOF94Sprites_Benimaru, 0x00 },
    { L"Extra 3", 0x1024e2, 0x102502 },
    { L"Extra 5", 0x102522, 0x102542 },
    { L"Extra 6", 0x102542, 0x102562 },
    { L"Extra 7", 0x102562, 0x102582 },
    { L"Extra 8", 0x102582, 0x1025a2 },
    { L"Monochrome Palette", 0x1025a2, 0x1025c2, indexKOF94Sprites_Benimaru, 0x00 },
    { L"Extra 9", 0x1025c2, 0x1025e2 },
    { L"Lifebar Portrait", 0x1025e2, 0x102602, indexKOF94Sprites_Benimaru, 0x20 },
};

const sGame_PaletteDataset KOF96_A_BENIMARU_D_PALETTES[] =
{
    { L"Benimaru", 0x102602, 0x102622, indexKOF94Sprites_Benimaru, 0x00 },
    { L"Extra 1", 0x102622, 0x102642 },
    { L"Super Trail 1", 0x102642, 0x102662, indexKOF94Sprites_Benimaru, 0x00 },
    { L"Super Trail 2", 0x102662, 0x102682 },
    { L"MAX Mode", 0x102682, 0x1026a2, indexKOF94Sprites_Benimaru, 0x00 },
    { L"Extra 1", 0x1026a2, 0x1026c2 },
    { L"Electric Palette?", 0x1026c2, 0x1026e2, indexKOF94Sprites_Benimaru, 0x00 },
    { L"Extra 3", 0x1026e2, 0x102702 },
    { L"Extra 5", 0x102722, 0x102742 },
    { L"Extra 6", 0x102742, 0x102762 },
    { L"Extra 7", 0x102762, 0x102782 },
    { L"Extra 8", 0x102782, 0x1027a2 },
    { L"Monochrome Palette", 0x1027a2, 0x1027c2, indexKOF94Sprites_Benimaru, 0x00 },
    { L"Extra 9", 0x1027c2, 0x1027e2 },
    { L"Lifebar Portrait", 0x1027e2, 0x102802, indexKOF94Sprites_Benimaru, 0x20 },
};

const sGame_PaletteDataset KOF96_A_DAIMON_A_PALETTES[] =
{
    { L"Daimon", 0x102802, 0x102822, indexKOFSprites_98Daimon, 0x00 },
    { L"Extra 1", 0x102822, 0x102842 },
    { L"Super Trail 1", 0x102842, 0x102862, indexKOFSprites_98Daimon, 0x00 },
    { L"Super Trail 2", 0x102862, 0x102882 },
    { L"MAX Mode", 0x102882, 0x1028a2, indexKOFSprites_98Daimon, 0x00 },
    { L"Extra 1", 0x1028a2, 0x1028c2 },
    { L"Electric Palette?", 0x1028c2, 0x1028e2, indexKOFSprites_98Daimon, 0x00 },
    { L"Extra 3", 0x1028e2, 0x102902 },
    { L"Extra 5", 0x102922, 0x102942 },
    { L"Extra 6", 0x102942, 0x102962 },
    { L"Extra 7", 0x102962, 0x102982 },
    { L"Extra 8", 0x102982, 0x1029a2 },
    { L"Monochrome Palette", 0x1029a2, 0x1029c2, indexKOFSprites_98Daimon, 0x00 },
    { L"Extra 9", 0x1029c2, 0x1029e2 },
    { L"Lifebar Portrait", 0x1029e2, 0x102a02, indexKOFSprites_98Daimon, 0x20 },
};

const sGame_PaletteDataset KOF96_A_DAIMON_D_PALETTES[] =
{
    { L"Daimon", 0x102a02, 0x102a22, indexKOFSprites_98Daimon, 0x00 },
    { L"Extra 1", 0x102a22, 0x102a42 },
    { L"Super Trail 1", 0x102a42, 0x102a62, indexKOFSprites_98Daimon, 0x00 },
    { L"Super Trail 2", 0x102a62, 0x102a82 },
    { L"MAX Mode", 0x102a82, 0x102aa2, indexKOFSprites_98Daimon, 0x00 },
    { L"Extra 1", 0x102aa2, 0x102ac2 },
    { L"Electric Palette?", 0x102ac2, 0x102ae2, indexKOFSprites_98Daimon, 0x00 },
    { L"Extra 3", 0x102ae2, 0x102b02 },
    { L"Extra 5", 0x102b22, 0x102b42 },
    { L"Extra 6", 0x102b42, 0x102b62 },
    { L"Extra 7", 0x102b62, 0x102b82 },
    { L"Extra 8", 0x102b82, 0x102ba2 },
    { L"Monochrome Palette", 0x102ba2, 0x102bc2, indexKOFSprites_98Daimon, 0x00 },
    { L"Extra 9", 0x102bc2, 0x102be2 },
    { L"Lifebar Portrait", 0x102be2, 0x102c02, indexKOFSprites_98Daimon, 0x20 },
};

const sGame_PaletteDataset KOF96_A_TERRY_A_PALETTES[] =
{
    { L"Terry", 0x102c02, 0x102c22, indexKOF94Sprites_Terry, 0x00 },
    { L"Extra 1", 0x102c22, 0x102c42 },
    { L"Super Trail 1", 0x102c42, 0x102c62, indexKOF94Sprites_Terry, 0x00 },
    { L"Super Trail 2", 0x102c62, 0x102c82 },
    { L"MAX Mode", 0x102c82, 0x102ca2, indexKOF94Sprites_Terry, 0x00 },
    { L"Extra 1", 0x102ca2, 0x102cc2 },
    { L"Electric Palette?", 0x102cc2, 0x102ce2, indexKOF94Sprites_Terry, 0x00 },
    { L"Extra 3", 0x102ce2, 0x102d02 },
    { L"Extra 5", 0x102d22, 0x102d42 },
    { L"Extra 6", 0x102d42, 0x102d62 },
    { L"Extra 7", 0x102d62, 0x102d82 },
    { L"Extra 8", 0x102d82, 0x102da2 },
    { L"Monochrome Palette", 0x102da2, 0x102dc2, indexKOF94Sprites_Terry, 0x00 },
    { L"Extra 9", 0x102dc2, 0x102de2 },
    { L"Lifebar Portrait", 0x102de2, 0x102e02, indexKOF94Sprites_Terry, 0x20 },
};

const sGame_PaletteDataset KOF96_A_TERRY_D_PALETTES[] =
{
    { L"Terry", 0x102e02, 0x102e22, indexKOF94Sprites_Terry, 0x00 },
    { L"Extra 1", 0x102e22, 0x102e42 },
    { L"Super Trail 1", 0x102e42, 0x102e62, indexKOF94Sprites_Terry, 0x00 },
    { L"Super Trail 2", 0x102e62, 0x102e82 },
    { L"MAX Mode", 0x102e82, 0x102ea2, indexKOF94Sprites_Terry, 0x00 },
    { L"Extra 1", 0x102ea2, 0x102ec2 },
    { L"Electric Palette?", 0x102ec2, 0x102ee2, indexKOF94Sprites_Terry, 0x00 },
    { L"Extra 3", 0x102ee2, 0x102f02 },
    { L"Extra 5", 0x102f22, 0x102f42 },
    { L"Extra 6", 0x102f42, 0x102f62 },
    { L"Extra 7", 0x102f62, 0x102f82 },
    { L"Extra 8", 0x102f82, 0x102fa2 },
    { L"Monochrome Palette", 0x102fa2, 0x102fc2, indexKOF94Sprites_Terry, 0x00 },
    { L"Extra 9", 0x102fc2, 0x102fe2 },
    { L"Lifebar Portrait", 0x102fe2, 0x103002, indexKOF94Sprites_Terry, 0x20 },
};

const sGame_PaletteDataset KOF96_A_ANDY_A_PALETTES[] =
{
    { L"Andy", 0x103002, 0x103022, indexKOF97Sprites_Andy, 0x00 },
    { L"Extra 1", 0x103022, 0x103042 },
    { L"Super Trail 1", 0x103042, 0x103062, indexKOF97Sprites_Andy, 0x00 },
    { L"Super Trail 2", 0x103062, 0x103082 },
    { L"MAX Mode", 0x103082, 0x1030a2, indexKOF97Sprites_Andy, 0x00 },
    { L"Extra 1", 0x1030a2, 0x1030c2 },
    { L"Electric Palette?", 0x1030c2, 0x1030e2, indexKOF97Sprites_Andy, 0x00 },
    { L"Extra 3", 0x1030e2, 0x103102 },
    { L"Extra 5", 0x103122, 0x103142 },
    { L"Extra 6", 0x103142, 0x103162 },
    { L"Extra 7", 0x103162, 0x103182 },
    { L"Extra 8", 0x103182, 0x1031a2 },
    { L"Monochrome Palette", 0x1031a2, 0x1031c2, indexKOF97Sprites_Andy, 0x00 },
    { L"Extra 9", 0x1031c2, 0x1031e2 },
    { L"Lifebar Portrait", 0x1031e2, 0x103202, indexKOF97Sprites_Andy, 0x20 },
};

const sGame_PaletteDataset KOF96_A_ANDY_D_PALETTES[] =
{
    { L"Andy", 0x103202, 0x103222, indexKOF97Sprites_Andy, 0x00 },
    { L"Extra 1", 0x103222, 0x103242 },
    { L"Super Trail 1", 0x103242, 0x103262, indexKOF97Sprites_Andy, 0x00 },
    { L"Super Trail 2", 0x103262, 0x103282 },
    { L"MAX Mode", 0x103282, 0x1032a2, indexKOF97Sprites_Andy, 0x00 },
    { L"Extra 1", 0x1032a2, 0x1032c2 },
    { L"Electric Palette?", 0x1032c2, 0x1032e2, indexKOF97Sprites_Andy, 0x00 },
    { L"Extra 3", 0x1032e2, 0x103302 },
    { L"Extra 5", 0x103322, 0x103342 },
    { L"Extra 6", 0x103342, 0x103362 },
    { L"Extra 7", 0x103362, 0x103382 },
    { L"Extra 8", 0x103382, 0x1033a2 },
    { L"Monochrome Palette", 0x1033a2, 0x1033c2, indexKOF97Sprites_Andy, 0x00 },
    { L"Extra 9", 0x1033c2, 0x1033e2 },
    { L"Lifebar Portrait", 0x1033e2, 0x103402, indexKOF97Sprites_Andy, 0x20 },
};

const sGame_PaletteDataset KOF96_A_JOE_A_PALETTES[] =
{
    { L"Joe", 0x103402, 0x103422, indexKOF94Sprites_Joe, 0x00 },
    { L"Extra 1", 0x103422, 0x103442 },
    { L"Super Trail 1", 0x103442, 0x103462, indexKOF94Sprites_Joe, 0x00 },
    { L"Super Trail 2", 0x103462, 0x103482 },
    { L"MAX Mode", 0x103482, 0x1034a2, indexKOF94Sprites_Joe, 0x00 },
    { L"Extra 1", 0x1034a2, 0x1034c2 },
    { L"Electric Palette?", 0x1034c2, 0x1034e2, indexKOF94Sprites_Joe, 0x00 },
    { L"Extra 3", 0x1034e2, 0x103502 },
    { L"Extra 5", 0x103522, 0x103542 },
    { L"Extra 6", 0x103542, 0x103562 },
    { L"Extra 7", 0x103562, 0x103582 },
    { L"Extra 8", 0x103582, 0x1035a2 },
    { L"Monochrome Palette", 0x1035a2, 0x1035c2, indexKOF94Sprites_Joe, 0x00 },
    { L"Extra 9", 0x1035c2, 0x1035e2 },
    { L"Lifebar Portrait", 0x1035e2, 0x103602, indexKOF94Sprites_Joe, 0x20 },
};

const sGame_PaletteDataset KOF96_A_JOE_D_PALETTES[] =
{
    { L"Joe", 0x103602, 0x103622, indexKOF94Sprites_Joe, 0x00 },
    { L"Extra 1", 0x103622, 0x103642 },
    { L"Super Trail 1", 0x103642, 0x103662, indexKOF94Sprites_Joe, 0x00 },
    { L"Super Trail 2", 0x103662, 0x103682 },
    { L"MAX Mode", 0x103682, 0x1036a2, indexKOF94Sprites_Joe, 0x00 },
    { L"Extra 1", 0x1036a2, 0x1036c2 },
    { L"Electric Palette?", 0x1036c2, 0x1036e2, indexKOF94Sprites_Joe, 0x00 },
    { L"Extra 3", 0x1036e2, 0x103702 },
    { L"Extra 5", 0x103722, 0x103742 },
    { L"Extra 6", 0x103742, 0x103762 },
    { L"Extra 7", 0x103762, 0x103782 },
    { L"Extra 8", 0x103782, 0x1037a2 },
    { L"Monochrome Palette", 0x1037a2, 0x1037c2, indexKOF94Sprites_Joe, 0x00 },
    { L"Extra 9", 0x1037c2, 0x1037e2 },
    { L"Lifebar Portrait", 0x1037e2, 0x103802, indexKOF94Sprites_Joe, 0x20 },
};

const sGame_PaletteDataset KOF96_A_RYO_A_PALETTES[] =
{
    { L"Ryo", 0x103802, 0x103822, indexKOF94Sprites_Ryo, 0x00 },
    { L"Extra 1", 0x103822, 0x103842 },
    { L"Super Trail 1", 0x103842, 0x103862, indexKOF94Sprites_Ryo, 0x00 },
    { L"Super Trail 2", 0x103862, 0x103882 },
    { L"MAX Mode", 0x103882, 0x1038a2, indexKOF94Sprites_Ryo, 0x00 },
    { L"Extra 1", 0x1038a2, 0x1038c2 },
    { L"Electric Palette?", 0x1038c2, 0x1038e2, indexKOF94Sprites_Ryo, 0x00 },
    { L"Extra 3", 0x1038e2, 0x103902 },
    { L"Extra 5", 0x103922, 0x103942 },
    { L"Extra 6", 0x103942, 0x103962 },
    { L"Extra 7", 0x103962, 0x103982 },
    { L"Extra 8", 0x103982, 0x1039a2 },
    { L"Monochrome Palette", 0x1039a2, 0x1039c2, indexKOF94Sprites_Ryo, 0x00 },
    { L"Extra 9", 0x1039c2, 0x1039e2 },
    { L"Lifebar Portrait", 0x1039e2, 0x103a02, indexKOF94Sprites_Ryo, 0x20 },
};

const sGame_PaletteDataset KOF96_A_RYO_D_PALETTES[] =
{
    { L"Ryo", 0x103a02, 0x103a22, indexKOF94Sprites_Ryo, 0x00 },
    { L"Extra 1", 0x103a22, 0x103a42 },
    { L"Super Trail 1", 0x103a42, 0x103a62, indexKOF94Sprites_Ryo, 0x00 },
    { L"Super Trail 2", 0x103a62, 0x103a82 },
    { L"MAX Mode", 0x103a82, 0x103aa2, indexKOF94Sprites_Ryo, 0x00 },
    { L"Extra 1", 0x103aa2, 0x103ac2 },
    { L"Electric Palette?", 0x103ac2, 0x103ae2, indexKOF94Sprites_Ryo, 0x00 },
    { L"Extra 3", 0x103ae2, 0x103b02 },
    { L"Extra 5", 0x103b22, 0x103b42 },
    { L"Extra 6", 0x103b42, 0x103b62 },
    { L"Extra 7", 0x103b62, 0x103b82 },
    { L"Extra 8", 0x103b82, 0x103ba2 },
    { L"Monochrome Palette", 0x103ba2, 0x103bc2, indexKOF94Sprites_Ryo, 0x00 },
    { L"Extra 9", 0x103bc2, 0x103be2 },
    { L"Lifebar Portrait", 0x103be2, 0x103c02, indexKOF94Sprites_Ryo, 0x20 },
};

const sGame_PaletteDataset KOF96_A_ROBERT_A_PALETTES[] =
{
    { L"Robert", 0x103c02, 0x103c22, indexKOF94Sprites_Robert, 0x00 },
    { L"Extra 1", 0x103c22, 0x103c42 },
    { L"Super Trail 1", 0x103c42, 0x103c62, indexKOF94Sprites_Robert, 0x00 },
    { L"Super Trail 2", 0x103c62, 0x103c82 },
    { L"MAX Mode", 0x103c82, 0x103ca2, indexKOF94Sprites_Robert, 0x00 },
    { L"Extra 1", 0x103ca2, 0x103cc2 },
    { L"Electric Palette?", 0x103cc2, 0x103ce2, indexKOF94Sprites_Robert, 0x00 },
    { L"Extra 3", 0x103ce2, 0x103d02 },
    { L"Extra 5", 0x103d22, 0x103d42 },
    { L"Extra 6", 0x103d42, 0x103d62 },
    { L"Extra 7", 0x103d62, 0x103d82 },
    { L"Extra 8", 0x103d82, 0x103da2 },
    { L"Monochrome Palette", 0x103da2, 0x103dc2, indexKOF94Sprites_Robert, 0x00 },
    { L"Extra 9", 0x103dc2, 0x103de2 },
    { L"Lifebar Portrait", 0x103de2, 0x103e02, indexKOF94Sprites_Robert, 0x20 },
};

const sGame_PaletteDataset KOF96_A_ROBERT_D_PALETTES[] =
{
    { L"Robert", 0x103e02, 0x103e22, indexKOF94Sprites_Robert, 0x00 },
    { L"Extra 1", 0x103e22, 0x103e42 },
    { L"Super Trail 1", 0x103e42, 0x103e62, indexKOF94Sprites_Robert, 0x00 },
    { L"Super Trail 2", 0x103e62, 0x103e82 },
    { L"MAX Mode", 0x103e82, 0x103ea2, indexKOF94Sprites_Robert, 0x00 },
    { L"Extra 1", 0x103ea2, 0x103ec2 },
    { L"Electric Palette?", 0x103ec2, 0x103ee2, indexKOF94Sprites_Robert, 0x00 },
    { L"Extra 3", 0x103ee2, 0x103f02 },
    { L"Extra 5", 0x103f22, 0x103f42 },
    { L"Extra 6", 0x103f42, 0x103f62 },
    { L"Extra 7", 0x103f62, 0x103f82 },
    { L"Extra 8", 0x103f82, 0x103fa2 },
    { L"Monochrome Palette", 0x103fa2, 0x103fc2, indexKOF94Sprites_Robert, 0x00 },
    { L"Extra 9", 0x103fc2, 0x103fe2 },
    { L"Lifebar Portrait", 0x103fe2, 0x104002, indexKOF94Sprites_Robert, 0x20 },
};

const sGame_PaletteDataset KOF96_A_YURI_A_PALETTES[] =
{
    { L"Yuri", 0x104002, 0x104022, indexKOF94Sprites_Yuri, 0x00 },
    { L"Extra 1", 0x104022, 0x104042 },
    { L"Super Trail 1", 0x104042, 0x104062, indexKOF94Sprites_Yuri, 0x00 },
    { L"Super Trail 2", 0x104062, 0x104082 },
    { L"MAX Mode", 0x104082, 0x1040a2, indexKOF94Sprites_Yuri, 0x00 },
    { L"Extra 1", 0x1040a2, 0x1040c2 },
    { L"Electric Palette?", 0x1040c2, 0x1040e2, indexKOF94Sprites_Yuri, 0x00 },
    { L"Extra 3", 0x1040e2, 0x104102 },
    { L"Extra 5", 0x104122, 0x104142 },
    { L"Extra 6", 0x104142, 0x104162 },
    { L"Extra 7", 0x104162, 0x104182 },
    { L"Extra 8", 0x104182, 0x1041a2 },
    { L"Monochrome Palette", 0x1041a2, 0x1041c2, indexKOF94Sprites_Yuri, 0x00 },
    { L"Extra 9", 0x1041c2, 0x1041e2 },
    { L"Lifebar Portrait", 0x1041e2, 0x104202, indexKOF94Sprites_Yuri, 0x20 },
};

const sGame_PaletteDataset KOF96_A_YURI_D_PALETTES[] =
{
    { L"Yuri", 0x104202, 0x104222, indexKOF94Sprites_Yuri, 0x00 },
    { L"Extra 1", 0x104222, 0x104242 },
    { L"Super Trail 1", 0x104242, 0x104262, indexKOF94Sprites_Yuri, 0x00 },
    { L"Super Trail 2", 0x104262, 0x104282 },
    { L"MAX Mode", 0x104282, 0x1042a2, indexKOF94Sprites_Yuri, 0x00 },
    { L"Extra 1", 0x1042a2, 0x1042c2 },
    { L"Electric Palette?", 0x1042c2, 0x1042e2, indexKOF94Sprites_Yuri, 0x00 },
    { L"Extra 3", 0x1042e2, 0x104302 },
    { L"Extra 5", 0x104322, 0x104342 },
    { L"Extra 6", 0x104342, 0x104362 },
    { L"Extra 7", 0x104362, 0x104382 },
    { L"Extra 8", 0x104382, 0x1043a2 },
    { L"Monochrome Palette", 0x1043a2, 0x1043c2, indexKOF94Sprites_Yuri, 0x00 },
    { L"Extra 9", 0x1043c2, 0x1043e2 },
    { L"Lifebar Portrait", 0x1043e2, 0x104402, indexKOF94Sprites_Yuri, 0x20 },
};

const sGame_PaletteDataset KOF96_A_LEONA_A_PALETTES[] =
{
    { L"Leona", 0x104402, 0x104422, indexKOFSprites_98Leona, 0x00 },
    { L"Extra 1", 0x104422, 0x104442 },
    { L"Super Trail 1", 0x104442, 0x104462, indexKOFSprites_98Leona, 0x00 },
    { L"Super Trail 2", 0x104462, 0x104482 },
    { L"MAX Mode", 0x104482, 0x1044a2, indexKOFSprites_98Leona, 0x00 },
    { L"Extra 1", 0x1044a2, 0x1044c2 },
    { L"Electric Palette?", 0x1044c2, 0x1044e2, indexKOFSprites_98Leona, 0x00 },
    { L"Extra 3", 0x1044e2, 0x104502 },
    { L"Extra 5", 0x104522, 0x104542 },
    { L"Extra 6", 0x104542, 0x104562 },
    { L"Extra 7", 0x104562, 0x104582 },
    { L"Extra 8", 0x104582, 0x1045a2 },
    { L"Monochrome Palette", 0x1045a2, 0x1045c2, indexKOFSprites_98Leona, 0x00 },
    { L"Extra 9", 0x1045c2, 0x1045e2 },
    { L"Lifebar Portrait", 0x1045e2, 0x104602, indexKOFSprites_98Leona, 0x20 },
};

const sGame_PaletteDataset KOF96_A_LEONA_D_PALETTES[] =
{
    { L"Leona", 0x104602, 0x104622, indexKOFSprites_98Leona, 0x00 },
    { L"Extra 1", 0x104622, 0x104642 },
    { L"Super Trail 1", 0x104642, 0x104662, indexKOFSprites_98Leona, 0x00 },
    { L"Super Trail 2", 0x104662, 0x104682 },
    { L"MAX Mode", 0x104682, 0x1046a2, indexKOFSprites_98Leona, 0x00 },
    { L"Extra 1", 0x1046a2, 0x1046c2 },
    { L"Electric Palette?", 0x1046c2, 0x1046e2, indexKOFSprites_98Leona, 0x00 },
    { L"Extra 3", 0x1046e2, 0x104702 },
    { L"Extra 5", 0x104722, 0x104742 },
    { L"Extra 6", 0x104742, 0x104762 },
    { L"Extra 7", 0x104762, 0x104782 },
    { L"Extra 8", 0x104782, 0x1047a2 },
    { L"Monochrome Palette", 0x1047a2, 0x1047c2, indexKOFSprites_98Leona, 0x00 },
    { L"Extra 9", 0x1047c2, 0x1047e2 },
    { L"Lifebar Portrait", 0x1047e2, 0x104802, indexKOFSprites_98Leona, 0x20 },
};

const sGame_PaletteDataset KOF96_A_RALF_A_PALETTES[] =
{
    { L"Ralf", 0x104802, 0x104822, indexKOF94Sprites_Ralf, 0x00, &pairNext },
    { L"Extra 1", 0x104822, 0x104842, indexKOF94Sprites_Ralf, 0x01 },
    { L"Super Trail 1", 0x104842, 0x104862, indexKOF94Sprites_Ralf, 0x00, &pairNext },
    { L"Super Trail 2", 0x104862, 0x104882, indexKOF94Sprites_Ralf, 0x01 },
    { L"MAX Mode", 0x104882, 0x1048a2, indexKOF94Sprites_Ralf, 0x00, &pairNext },
    { L"MAX Mode Extra", 0x1048a2, 0x1048c2, indexKOF94Sprites_Ralf, 0x01 },
    { L"Electric Palette?", 0x1048c2, 0x1048e2, indexKOF94Sprites_Ralf, 0x00, &pairNext },
    { L"Electric Palette Extra", 0x1048e2, 0x104902, indexKOF94Sprites_Ralf, 0x01 },
    { L"Extra 5", 0x104922, 0x104942 },
    { L"Extra 6", 0x104942, 0x104962 },
    { L"Extra 7", 0x104962, 0x104982 },
    { L"Extra 8", 0x104982, 0x1049a2 },
    { L"Monochrome Palette", 0x1049a2, 0x1049c2, indexKOF94Sprites_Ralf, 0x00 },
    { L"Extra 9", 0x1049c2, 0x1049e2 },
    { L"Lifebar Portrait", 0x1049e2, 0x104a02, indexKOF94Sprites_Ralf, 0x20 },
};

const sGame_PaletteDataset KOF96_A_RALF_D_PALETTES[] =
{
    { L"Ralf", 0x104a02, 0x104a22, indexKOF94Sprites_Ralf, 0x00, &pairNext },
    { L"Extra 1", 0x104a22, 0x104a42, indexKOF94Sprites_Ralf, 0x01 },
    { L"Super Trail 1", 0x104a42, 0x104a62, indexKOF94Sprites_Ralf, 0x00, &pairNext },
    { L"Super Trail 2", 0x104a62, 0x104a82, indexKOF94Sprites_Ralf, 0x01 },
    { L"MAX Mode", 0x104a82, 0x104aa2, indexKOF94Sprites_Ralf, 0x00, &pairNext },
    { L"MAX Mode Extra", 0x104aa2, 0x104ac2, indexKOF94Sprites_Ralf, 0x01 },
    { L"Electric Palette?", 0x104ac2, 0x104ae2, indexKOF94Sprites_Ralf, 0x00, &pairNext },
    { L"Electric Palette Extra", 0x104ae2, 0x104b02, indexKOF94Sprites_Ralf, 0x01 },
    { L"Extra 5", 0x104b22, 0x104b42 },
    { L"Extra 6", 0x104b42, 0x104b62 },
    { L"Extra 7", 0x104b62, 0x104b82 },
    { L"Extra 8", 0x104b82, 0x104ba2 },
    { L"Monochrome Palette", 0x104ba2, 0x104bc2, indexKOF94Sprites_Ralf, 0x00 },
    { L"Extra 9", 0x104bc2, 0x104be2 },
    { L"Lifebar Portrait", 0x104be2, 0x104c02, indexKOF94Sprites_Ralf, 0x20 },
};

const sGame_PaletteDataset KOF96_A_CLARK_A_PALETTES[] =
{
    { L"Clark", 0x104c02, 0x104c22, indexKOF94Sprites_Clark, 0x00, &pairNext },
    { L"Extra 1", 0x104c22, 0x104c42, indexKOF94Sprites_Clark, 0x01 },
    { L"Super Trail 1", 0x104c42, 0x104c62, indexKOF94Sprites_Clark, 0x00, &pairNext },
    { L"Super Trail 2", 0x104c62, 0x104c82, indexKOF94Sprites_Clark, 0x01 },
    { L"MAX Mode", 0x104c82, 0x104ca2, indexKOF94Sprites_Clark, 0x00, &pairNext },
    { L"MAX Mode Extra", 0x104ca2, 0x104cc2, indexKOF94Sprites_Clark, 0x01 },
    { L"Electric Palette?", 0x104cc2, 0x104ce2, indexKOF94Sprites_Clark, 0x00, &pairNext },
    { L"Electric Palette Extra", 0x104ce2, 0x104d02, indexKOF94Sprites_Clark, 0x01 },
    { L"Extra 5", 0x104d22, 0x104d42 },
    { L"Extra 6", 0x104d42, 0x104d62 },
    { L"Extra 7", 0x104d62, 0x104d82 },
    { L"Extra 8", 0x104d82, 0x104da2 },
    { L"Monochrome Palette", 0x104da2, 0x104dc2, indexKOF94Sprites_Clark, 0x00 },
    { L"Extra 9", 0x104dc2, 0x104de2 },
    { L"Lifebar Portrait", 0x104de2, 0x104e02, indexKOF94Sprites_Clark, 0x20 },
};

const sGame_PaletteDataset KOF96_A_CLARK_D_PALETTES[] =
{
    { L"Clark", 0x104e02, 0x104e22, indexKOF94Sprites_Clark, 0x00, &pairNext },
    { L"Extra 1", 0x104e22, 0x104e42, indexKOF94Sprites_Clark, 0x01 },
    { L"Super Trail 1", 0x104e42, 0x104e62, indexKOF94Sprites_Clark, 0x00, &pairNext },
    { L"Super Trail 2", 0x104e62, 0x104e82, indexKOF94Sprites_Clark, 0x01 },
    { L"MAX Mode", 0x104e82, 0x104ea2, indexKOF94Sprites_Clark, 0x00, &pairNext },
    { L"MAX Mode Extra", 0x104ea2, 0x104ec2, indexKOF94Sprites_Clark, 0x01 },
    { L"Electric Palette?", 0x104ec2, 0x104ee2, indexKOF94Sprites_Clark, 0x00, &pairNext },
    { L"Electric Palette Extra", 0x104ee2, 0x104f02, indexKOF94Sprites_Clark, 0x01 },
    { L"Extra 5", 0x104f22, 0x104f42 },
    { L"Extra 6", 0x104f42, 0x104f62 },
    { L"Extra 7", 0x104f62, 0x104f82 },
    { L"Extra 8", 0x104f82, 0x104fa2 },
    { L"Monochrome Palette", 0x104fa2, 0x104fc2, indexKOF94Sprites_Clark, 0x00 },
    { L"Extra 9", 0x104fc2, 0x104fe2 },
    { L"Lifebar Portrait", 0x104fe2, 0x105002, indexKOF94Sprites_Clark, 0x20 },
};

const sGame_PaletteDataset KOF96_A_ATHENA_A_PALETTES[] =
{
    { L"Athena", 0x105002, 0x105022, indexKOF94Sprites_Athena, 0x00 },
    { L"Extra 1", 0x105022, 0x105042 },
    { L"Super Trail 1", 0x105042, 0x105062, indexKOF94Sprites_Athena, 0x00 },
    { L"Super Trail 2", 0x105062, 0x105082 },
    { L"MAX Mode", 0x105082, 0x1050a2, indexKOF94Sprites_Athena, 0x00 },
    { L"Extra 1", 0x1050a2, 0x1050c2 },
    { L"Electric Palette?", 0x1050c2, 0x1050e2, indexKOF94Sprites_Athena, 0x00 },
    { L"Extra 3", 0x1050e2, 0x105102 },
    { L"Extra 5", 0x105122, 0x105142 },
    { L"Extra 6", 0x105142, 0x105162 },
    { L"Extra 7", 0x105162, 0x105182 },
    { L"Extra 8", 0x105182, 0x1051a2 },
    { L"Monochrome Palette", 0x1051a2, 0x1051c2, indexKOF94Sprites_Athena, 0x00 },
    { L"Extra 9", 0x1051c2, 0x1051e2 },
    { L"Lifebar Portrait", 0x1051e2, 0x105202, indexKOF94Sprites_Athena, 0x20 },
};

const sGame_PaletteDataset KOF96_A_ATHENA_D_PALETTES[] =
{
    { L"Athena", 0x105202, 0x105222, indexKOF94Sprites_Athena, 0x00 },
    { L"Extra 1", 0x105222, 0x105242 },
    { L"Super Trail 1", 0x105242, 0x105262, indexKOF94Sprites_Athena, 0x00 },
    { L"Super Trail 2", 0x105262, 0x105282 },
    { L"MAX Mode", 0x105282, 0x1052a2, indexKOF94Sprites_Athena, 0x00 },
    { L"Extra 1", 0x1052a2, 0x1052c2 },
    { L"Electric Palette?", 0x1052c2, 0x1052e2, indexKOF94Sprites_Athena, 0x00 },
    { L"Extra 3", 0x1052e2, 0x105302 },
    { L"Extra 5", 0x105322, 0x105342 },
    { L"Extra 6", 0x105342, 0x105362 },
    { L"Extra 7", 0x105362, 0x105382 },
    { L"Extra 8", 0x105382, 0x1053a2 },
    { L"Monochrome Palette", 0x1053a2, 0x1053c2, indexKOF94Sprites_Athena, 0x00 },
    { L"Extra 9", 0x1053c2, 0x1053e2 },
    { L"Lifebar Portrait", 0x1053e2, 0x105402, indexKOF94Sprites_Athena, 0x20 },
};

const sGame_PaletteDataset KOF96_A_KENSOU_A_PALETTES[] =
{
    { L"Kensou", 0x105402, 0x105422, indexKOF94Sprites_Kensou, 0x00 },
    { L"Extra 1", 0x105422, 0x105442 },
    { L"Super Trail 1", 0x105442, 0x105462, indexKOF94Sprites_Kensou, 0x00 },
    { L"Super Trail 2", 0x105462, 0x105482 },
    { L"MAX Mode", 0x105482, 0x1054a2, indexKOF94Sprites_Kensou, 0x00 },
    { L"Extra 1", 0x1054a2, 0x1054c2 },
    { L"Electric Palette?", 0x1054c2, 0x1054e2, indexKOF94Sprites_Kensou, 0x00 },
    { L"Extra 3", 0x1054e2, 0x105502 },
    { L"Extra 5", 0x105522, 0x105542 },
    { L"Extra 6", 0x105542, 0x105562 },
    { L"Extra 7", 0x105562, 0x105582 },
    { L"Extra 8", 0x105582, 0x1055a2 },
    { L"Monochrome Palette", 0x1055a2, 0x1055c2, indexKOF94Sprites_Kensou, 0x00 },
    { L"Extra 9", 0x1055c2, 0x1055e2 },
    { L"Lifebar Portrait", 0x1055e2, 0x105602, indexKOF94Sprites_Kensou, 0x20 },
};

const sGame_PaletteDataset KOF96_A_KENSOU_D_PALETTES[] =
{
    { L"Kensou", 0x105602, 0x105622, indexKOF94Sprites_Kensou, 0x00 },
    { L"Extra 1", 0x105622, 0x105642 },
    { L"Super Trail 1", 0x105642, 0x105662, indexKOF94Sprites_Kensou, 0x00 },
    { L"Super Trail 2", 0x105662, 0x105682 },
    { L"MAX Mode", 0x105682, 0x1056a2, indexKOF94Sprites_Kensou, 0x00 },
    { L"Extra 1", 0x1056a2, 0x1056c2 },
    { L"Electric Palette?", 0x1056c2, 0x1056e2, indexKOF94Sprites_Kensou, 0x00 },
    { L"Extra 3", 0x1056e2, 0x105702 },
    { L"Extra 5", 0x105722, 0x105742 },
    { L"Extra 6", 0x105742, 0x105762 },
    { L"Extra 7", 0x105762, 0x105782 },
    { L"Extra 8", 0x105782, 0x1057a2 },
    { L"Monochrome Palette", 0x1057a2, 0x1057c2, indexKOF94Sprites_Kensou, 0x00 },
    { L"Extra 9", 0x1057c2, 0x1057e2 },
    { L"Lifebar Portrait", 0x1057e2, 0x105802, indexKOF94Sprites_Kensou, 0x20 },
};

const sGame_PaletteDataset KOF96_A_CHIN_A_PALETTES[] =
{
    { L"Chin", 0x105802, 0x105822, indexKOF94Sprites_Chin, 0x00 },
    { L"Extra 1", 0x105822, 0x105842 },
    { L"Super Trail 1", 0x105842, 0x105862, indexKOF94Sprites_Chin, 0x00 },
    { L"Super Trail 2", 0x105862, 0x105882 },
    { L"MAX Mode", 0x105882, 0x1058a2, indexKOF94Sprites_Chin, 0x00 },
    { L"Extra 1", 0x1058a2, 0x1058c2 },
    { L"Electric Palette?", 0x1058c2, 0x1058e2, indexKOF94Sprites_Chin, 0x00 },
    { L"Extra 3", 0x1058e2, 0x105902 },
    { L"Extra 5", 0x105922, 0x105942 },
    { L"Extra 6", 0x105942, 0x105962 },
    { L"Extra 7", 0x105962, 0x105982 },
    { L"Extra 8", 0x105982, 0x1059a2 },
    { L"Monochrome Palette", 0x1059a2, 0x1059c2, indexKOF94Sprites_Chin, 0x00 },
    { L"Extra 9", 0x1059c2, 0x1059e2 },
    { L"Lifebar Portrait", 0x1059e2, 0x105a02, indexKOF94Sprites_Chin, 0x20 },
};

const sGame_PaletteDataset KOF96_A_CHIN_D_PALETTES[] =
{
    { L"Chin", 0x105a02, 0x105a22, indexKOF94Sprites_Chin, 0x00 },
    { L"Extra 1", 0x105a22, 0x105a42 },
    { L"Super Trail 1", 0x105a42, 0x105a62, indexKOF94Sprites_Chin, 0x00 },
    { L"Super Trail 2", 0x105a62, 0x105a82 },
    { L"MAX Mode", 0x105a82, 0x105aa2, indexKOF94Sprites_Chin, 0x00 },
    { L"Extra 1", 0x105aa2, 0x105ac2 },
    { L"Electric Palette?", 0x105ac2, 0x105ae2, indexKOF94Sprites_Chin, 0x00 },
    { L"Extra 3", 0x105ae2, 0x105b02 },
    { L"Extra 5", 0x105b22, 0x105b42 },
    { L"Extra 6", 0x105b42, 0x105b62 },
    { L"Extra 7", 0x105b62, 0x105b82 },
    { L"Extra 8", 0x105b82, 0x105ba2 },
    { L"Monochrome Palette", 0x105ba2, 0x105bc2, indexKOF94Sprites_Chin, 0x00 },
    { L"Extra 9", 0x105bc2, 0x105be2 },
    { L"Lifebar Portrait", 0x105be2, 0x105c02, indexKOF94Sprites_Chin, 0x20 },
};

const sGame_PaletteDataset KOF96_A_KASUMI_A_PALETTES[] =
{
    { L"Kasumi", 0x105c02, 0x105c22, indexKOFSprites_00Kasumi, 0x00 },
    { L"Extra 1", 0x105c22, 0x105c42 },
    { L"Super Trail 1", 0x105c42, 0x105c62, indexKOFSprites_00Kasumi, 0x00 },
    { L"Super Trail 2", 0x105c62, 0x105c82 },
    { L"MAX Mode", 0x105c82, 0x105ca2, indexKOFSprites_00Kasumi, 0x00 },
    { L"Extra 1", 0x105ca2, 0x105cc2 },
    { L"Electric Palette?", 0x105cc2, 0x105ce2, indexKOFSprites_00Kasumi, 0x00 },
    { L"Extra 3", 0x105ce2, 0x105d02 },
    { L"Extra 5", 0x105d22, 0x105d42 },
    { L"Extra 6", 0x105d42, 0x105d62 },
    { L"Extra 7", 0x105d62, 0x105d82 },
    { L"Extra 8", 0x105d82, 0x105da2 },
    { L"Monochrome Palette", 0x105da2, 0x105dc2, indexKOFSprites_00Kasumi, 0x00 },
    { L"Extra 9", 0x105dc2, 0x105de2 },
    { L"Lifebar Portrait", 0x105de2, 0x105e02, indexKOFSprites_00Kasumi, 0x20 },
};

const sGame_PaletteDataset KOF96_A_KASUMI_D_PALETTES[] =
{
    { L"Kasumi", 0x105e02, 0x105e22, indexKOFSprites_00Kasumi, 0x00 },
    { L"Extra 1", 0x105e22, 0x105e42 },
    { L"Super Trail 1", 0x105e42, 0x105e62, indexKOFSprites_00Kasumi, 0x00 },
    { L"Super Trail 2", 0x105e62, 0x105e82 },
    { L"MAX Mode", 0x105e82, 0x105ea2, indexKOFSprites_00Kasumi, 0x00 },
    { L"Extra 1", 0x105ea2, 0x105ec2 },
    { L"Electric Palette?", 0x105ec2, 0x105ee2, indexKOFSprites_00Kasumi, 0x00 },
    { L"Extra 3", 0x105ee2, 0x105f02 },
    { L"Extra 5", 0x105f22, 0x105f42 },
    { L"Extra 6", 0x105f42, 0x105f62 },
    { L"Extra 7", 0x105f62, 0x105f82 },
    { L"Extra 8", 0x105f82, 0x105fa2 },
    { L"Monochrome Palette", 0x105fa2, 0x105fc2, indexKOFSprites_00Kasumi, 0x00 },
    { L"Extra 9", 0x105fc2, 0x105fe2 },
    { L"Lifebar Portrait", 0x105fe2, 0x106002, indexKOFSprites_00Kasumi, 0x20 },
};

const sGame_PaletteDataset KOF96_A_MAI_A_PALETTES[] =
{
    { L"Mai", 0x106002, 0x106022, indexKOF94Sprites_Mai, 0x00 },
    { L"Extra 1", 0x106022, 0x106042 },
    { L"Super Trail 1", 0x106042, 0x106062, indexKOF94Sprites_Mai, 0x00 },
    { L"Super Trail 2", 0x106062, 0x106082 },
    { L"MAX Mode", 0x106082, 0x1060a2, indexKOF94Sprites_Mai, 0x00 },
    { L"Extra 1", 0x1060a2, 0x1060c2 },
    { L"Electric Palette?", 0x1060c2, 0x1060e2, indexKOF94Sprites_Mai, 0x00 },
    { L"Extra 3", 0x1060e2, 0x106102 },
    { L"Extra 5", 0x106122, 0x106142 },
    { L"Extra 6", 0x106142, 0x106162 },
    { L"Extra 7", 0x106162, 0x106182 },
    { L"Extra 8", 0x106182, 0x1061a2 },
    { L"Monochrome Palette", 0x1061a2, 0x1061c2, indexKOF94Sprites_Mai, 0x00 },
    { L"Extra 9", 0x1061c2, 0x1061e2 },
    { L"Lifebar Portrait", 0x1061e2, 0x106202, indexKOF94Sprites_Mai, 0x20 },
};

const sGame_PaletteDataset KOF96_A_MAI_D_PALETTES[] =
{
    { L"Mai", 0x106202, 0x106222, indexKOF94Sprites_Mai, 0x00 },
    { L"Extra 1", 0x106222, 0x106242 },
    { L"Super Trail 1", 0x106242, 0x106262, indexKOF94Sprites_Mai, 0x00 },
    { L"Super Trail 2", 0x106262, 0x106282 },
    { L"MAX Mode", 0x106282, 0x1062a2, indexKOF94Sprites_Mai, 0x00 },
    { L"Extra 1", 0x1062a2, 0x1062c2 },
    { L"Electric Palette?", 0x1062c2, 0x1062e2, indexKOF94Sprites_Mai, 0x00 },
    { L"Extra 3", 0x1062e2, 0x106302 },
    { L"Extra 5", 0x106322, 0x106342 },
    { L"Extra 6", 0x106342, 0x106362 },
    { L"Extra 7", 0x106362, 0x106382 },
    { L"Extra 8", 0x106382, 0x1063a2 },
    { L"Monochrome Palette", 0x1063a2, 0x1063c2, indexKOF94Sprites_Mai, 0x00 },
    { L"Extra 9", 0x1063c2, 0x1063e2 },
    { L"Lifebar Portrait", 0x1063e2, 0x106402, indexKOF94Sprites_Mai, 0x20 },
};

const sGame_PaletteDataset KOF96_A_KING_A_PALETTES[] =
{
    { L"King", 0x106402, 0x106422, indexKOFSprites_98King, 0x00 },
    { L"Extra 1", 0x106422, 0x106442 },
    { L"Super Trail 1", 0x106442, 0x106462, indexKOFSprites_98King, 0x00 },
    { L"Super Trail 2", 0x106462, 0x106482 },
    { L"MAX Mode", 0x106482, 0x1064a2, indexKOFSprites_98King, 0x00 },
    { L"Extra 1", 0x1064a2, 0x1064c2 },
    { L"Electric Palette?", 0x1064c2, 0x1064e2, indexKOFSprites_98King, 0x00 },
    { L"Extra 3", 0x1064e2, 0x106502 },
    { L"Extra 5", 0x106522, 0x106542 },
    { L"Extra 6", 0x106542, 0x106562 },
    { L"Extra 7", 0x106562, 0x106582 },
    { L"Extra 8", 0x106582, 0x1065a2 },
    { L"Monochrome Palette", 0x1065a2, 0x1065c2, indexKOFSprites_98King, 0x00 },
    { L"Extra 9", 0x1065c2, 0x1065e2 },
    { L"Lifebar Portrait", 0x1065e2, 0x106602, indexKOFSprites_98King, 0x20 },
};

const sGame_PaletteDataset KOF96_A_KING_D_PALETTES[] =
{
    { L"King", 0x106602, 0x106622, indexKOFSprites_98King, 0x00 },
    { L"Extra 1", 0x106622, 0x106642 },
    { L"Super Trail 1", 0x106642, 0x106662, indexKOFSprites_98King, 0x00 },
    { L"Super Trail 2", 0x106662, 0x106682 },
    { L"MAX Mode", 0x106682, 0x1066a2, indexKOFSprites_98King, 0x00 },
    { L"Extra 1", 0x1066a2, 0x1066c2 },
    { L"Electric Palette?", 0x1066c2, 0x1066e2, indexKOFSprites_98King, 0x00 },
    { L"Extra 3", 0x1066e2, 0x106702 },
    { L"Extra 5", 0x106722, 0x106742 },
    { L"Extra 6", 0x106742, 0x106762 },
    { L"Extra 7", 0x106762, 0x106782 },
    { L"Extra 8", 0x106782, 0x1067a2 },
    { L"Monochrome Palette", 0x1067a2, 0x1067c2, indexKOFSprites_98King, 0x00 },
    { L"Extra 9", 0x1067c2, 0x1067e2 },
    { L"Lifebar Portrait", 0x1067e2, 0x106802, indexKOFSprites_98King, 0x20 },
};

const sGame_PaletteDataset KOF96_A_KIM_A_PALETTES[] =
{
    { L"Kim", 0x106802, 0x106822, indexKOFSprites_98Kim, 0x00 },
    { L"Extra 1", 0x106822, 0x106842 },
    { L"Super Trail 1", 0x106842, 0x106862, indexKOFSprites_98Kim, 0x00 },
    { L"Super Trail 2", 0x106862, 0x106882 },
    { L"MAX Mode", 0x106882, 0x1068a2, indexKOFSprites_98Kim, 0x00 },
    { L"Extra 1", 0x1068a2, 0x1068c2 },
    { L"Electric Palette?", 0x1068c2, 0x1068e2, indexKOFSprites_98Kim, 0x00 },
    { L"Extra 3", 0x1068e2, 0x106902 },
    { L"Extra 5", 0x106922, 0x106942 },
    { L"Extra 6", 0x106942, 0x106962 },
    { L"Extra 7", 0x106962, 0x106982 },
    { L"Extra 8", 0x106982, 0x1069a2 },
    { L"Monochrome Palette", 0x1069a2, 0x1069c2, indexKOFSprites_98Kim, 0x00 },
    { L"Extra 9", 0x1069c2, 0x1069e2 },
    { L"Lifebar Portrait", 0x1069e2, 0x106a02, indexKOFSprites_98Kim, 0x20 },
};

const sGame_PaletteDataset KOF96_A_KIM_D_PALETTES[] =
{
    { L"Kim", 0x106a02, 0x106a22, indexKOFSprites_98Kim, 0x00 },
    { L"Extra 1", 0x106a22, 0x106a42 },
    { L"Super Trail 1", 0x106a42, 0x106a62, indexKOFSprites_98Kim, 0x00 },
    { L"Super Trail 2", 0x106a62, 0x106a82 },
    { L"MAX Mode", 0x106a82, 0x106aa2, indexKOFSprites_98Kim, 0x00 },
    { L"Extra 1", 0x106aa2, 0x106ac2 },
    { L"Electric Palette?", 0x106ac2, 0x106ae2, indexKOFSprites_98Kim, 0x00 },
    { L"Extra 3", 0x106ae2, 0x106b02 },
    { L"Extra 5", 0x106b22, 0x106b42 },
    { L"Extra 6", 0x106b42, 0x106b62 },
    { L"Extra 7", 0x106b62, 0x106b82 },
    { L"Extra 8", 0x106b82, 0x106ba2 },
    { L"Monochrome Palette", 0x106ba2, 0x106bc2, indexKOFSprites_98Kim, 0x00 },
    { L"Extra 9", 0x106bc2, 0x106be2 },
    { L"Lifebar Portrait", 0x106be2, 0x106c02, indexKOFSprites_98Kim, 0x20 },
};

const sGame_PaletteDataset KOF96_A_CHANG_A_PALETTES[] =
{
    { L"Chang", 0x106c02, 0x106c22, indexKOFSprites_98Chang, 0x00, &pairNext },
    { L"Extra 1", 0x106c22, 0x106c42, indexKOFSprites_98Chang, 0x01 },
    { L"Super Trail 1", 0x106c42, 0x106c62, indexKOFSprites_98Chang, 0x00, &pairNext },
    { L"Super Trail 2", 0x106c62, 0x106c82, indexKOFSprites_98Chang, 0x01 },
    { L"MAX Mode", 0x106c82, 0x106ca2, indexKOFSprites_98Chang, 0x00, &pairNext },
    { L"MAX Mode Extra", 0x106ca2, 0x106cc2, indexKOFSprites_98Chang, 0x01 },
    { L"Electric Palette?", 0x106cc2, 0x106ce2, indexKOFSprites_98Chang, 0x00, &pairNext },
    { L"Electric Palette Extra", 0x106ce2, 0x106d02, indexKOFSprites_98Chang, 0x01 },
    { L"Extra 5", 0x106d22, 0x106d42 },
    { L"Extra 6", 0x106d42, 0x106d62 },
    { L"Extra 7", 0x106d62, 0x106d82 },
    { L"Extra 8", 0x106d82, 0x106da2 },
    { L"Monochrome Palette", 0x106da2, 0x106dc2, indexKOFSprites_98Chang, 0x00 },
    { L"Extra 9", 0x106dc2, 0x106de2 },
    { L"Lifebar Portrait", 0x106de2, 0x106e02, indexKOFSprites_98Chang, 0x20 },
};

const sGame_PaletteDataset KOF96_A_CHANG_D_PALETTES[] =
{
    { L"Chang", 0x106e02, 0x106e22, indexKOFSprites_98Chang, 0x00, &pairNext },
    { L"Extra 1", 0x106e22, 0x106e42, indexKOFSprites_98Chang, 0x01 },
    { L"Super Trail 1", 0x106e42, 0x106e62, indexKOFSprites_98Chang, 0x00, &pairNext },
    { L"Super Trail 2", 0x106e62, 0x106e82, indexKOFSprites_98Chang, 0x01 },
    { L"MAX Mode", 0x106e82, 0x106ea2, indexKOFSprites_98Chang, 0x00, &pairNext },
    { L"MAX Mode Extra", 0x106ea2, 0x106ec2, indexKOFSprites_98Chang, 0x01 },
    { L"Electric Palette?", 0x106ec2, 0x106ee2, indexKOFSprites_98Chang, 0x00, &pairNext },
    { L"Electric Palette Extra", 0x106ee2, 0x106f02, indexKOFSprites_98Chang, 0x01 },
    { L"Extra 5", 0x106f22, 0x106f42 },
    { L"Extra 6", 0x106f42, 0x106f62 },
    { L"Extra 7", 0x106f62, 0x106f82 },
    { L"Extra 8", 0x106f82, 0x106fa2 },
    { L"Monochrome Palette", 0x106fa2, 0x106fc2, indexKOFSprites_98Chang, 0x00 },
    { L"Extra 9", 0x106fc2, 0x106fe2 },
    { L"Lifebar Portrait", 0x106fe2, 0x107002, indexKOFSprites_98Chang, 0x20 },
};

const sGame_PaletteDataset KOF96_A_CHOI_A_PALETTES[] =
{
    { L"Choi", 0x107002, 0x107022, indexKOFSprites_98Choi, 0x00 },
    { L"Extra 1", 0x107022, 0x107042 },
    { L"Super Trail 1", 0x107042, 0x107062, indexKOFSprites_98Choi, 0x00 },
    { L"Super Trail 2", 0x107062, 0x107082 },
    { L"MAX Mode", 0x107082, 0x1070a2, indexKOFSprites_98Choi, 0x00 },
    { L"Extra 1", 0x1070a2, 0x1070c2 },
    { L"Electric Palette?", 0x1070c2, 0x1070e2, indexKOFSprites_98Choi, 0x00 },
    { L"Extra 3", 0x1070e2, 0x107102 },
    { L"Extra 5", 0x107122, 0x107142 },
    { L"Extra 6", 0x107142, 0x107162 },
    { L"Extra 7", 0x107162, 0x107182 },
    { L"Extra 8", 0x107182, 0x1071a2 },
    { L"Monochrome Palette", 0x1071a2, 0x1071c2, indexKOFSprites_98Choi, 0x00 },
    { L"Extra 9", 0x1071c2, 0x1071e2 },
    { L"Lifebar Portrait", 0x1071e2, 0x107202, indexKOFSprites_98Choi, 0x20 },
};

const sGame_PaletteDataset KOF96_A_CHOI_D_PALETTES[] =
{
    { L"Choi", 0x107202, 0x107222, indexKOFSprites_98Choi, 0x00 },
    { L"Extra 1", 0x107222, 0x107242 },
    { L"Super Trail 1", 0x107242, 0x107262, indexKOFSprites_98Choi, 0x00 },
    { L"Super Trail 2", 0x107262, 0x107282 },
    { L"MAX Mode", 0x107282, 0x1072a2, indexKOFSprites_98Choi, 0x00 },
    { L"Extra 1", 0x1072a2, 0x1072c2 },
    { L"Electric Palette?", 0x1072c2, 0x1072e2, indexKOFSprites_98Choi, 0x00 },
    { L"Extra 3", 0x1072e2, 0x107302 },
    { L"Extra 5", 0x107322, 0x107342 },
    { L"Extra 6", 0x107342, 0x107362 },
    { L"Extra 7", 0x107362, 0x107382 },
    { L"Extra 8", 0x107382, 0x1073a2 },
    { L"Monochrome Palette", 0x1073a2, 0x1073c2, indexKOFSprites_98Choi, 0x00 },
    { L"Extra 9", 0x1073c2, 0x1073e2 },
    { L"Lifebar Portrait", 0x1073e2, 0x107402, indexKOFSprites_98Choi, 0x20 },
};

const sGame_PaletteDataset KOF96_A_IORI_A_PALETTES[] =
{
    { L"Iori", 0x107402, 0x107422, indexKOFSprites_98Iori, 0x00 },
    { L"Extra 1", 0x107422, 0x107442 },
    { L"Super Trail 1", 0x107442, 0x107462, indexKOFSprites_98Iori, 0x00 },
    { L"Super Trail 2", 0x107462, 0x107482 },
    { L"MAX Mode", 0x107482, 0x1074a2, indexKOFSprites_98Iori, 0x00 },
    { L"Extra 1", 0x1074a2, 0x1074c2 },
    { L"Electric Palette?", 0x1074c2, 0x1074e2, indexKOFSprites_98Iori, 0x00 },
    { L"Extra 3", 0x1074e2, 0x107502 },
    { L"Extra 5", 0x107522, 0x107542 },
    { L"Extra 6", 0x107542, 0x107562 },
    { L"Extra 7", 0x107562, 0x107582 },
    { L"Extra 8", 0x107582, 0x1075a2 },
    { L"Monochrome Palette", 0x1075a2, 0x1075c2, indexKOFSprites_98Iori, 0x00 },
    { L"Extra 9", 0x1075c2, 0x1075e2 },
    { L"Lifebar Portrait", 0x1075e2, 0x107602, indexKOFSprites_98Iori, 0x20 },
};

const sGame_PaletteDataset KOF96_A_IORI_D_PALETTES[] =
{
    { L"Iori", 0x107602, 0x107622, indexKOFSprites_98Iori, 0x00 },
    { L"Extra 1", 0x107622, 0x107642 },
    { L"Super Trail 1", 0x107642, 0x107662, indexKOFSprites_98Iori, 0x00 },
    { L"Super Trail 2", 0x107662, 0x107682 },
    { L"MAX Mode", 0x107682, 0x1076a2, indexKOFSprites_98Iori, 0x00 },
    { L"Extra 1", 0x1076a2, 0x1076c2 },
    { L"Electric Palette?", 0x1076c2, 0x1076e2, indexKOFSprites_98Iori, 0x00 },
    { L"Extra 3", 0x1076e2, 0x107702 },
    { L"Extra 5", 0x107722, 0x107742 },
    { L"Extra 6", 0x107742, 0x107762 },
    { L"Extra 7", 0x107762, 0x107782 },
    { L"Extra 8", 0x107782, 0x1077a2 },
    { L"Monochrome Palette", 0x1077a2, 0x1077c2, indexKOFSprites_98Iori, 0x00 },
    { L"Extra 9", 0x1077c2, 0x1077e2 },
    { L"Lifebar Portrait", 0x1077e2, 0x107802, indexKOFSprites_98Iori, 0x20 },
};

const sGame_PaletteDataset KOF96_A_MATURE_A_PALETTES[] =
{
    { L"Mature", 0x107802, 0x107822, indexKOFSprites_98Mature, 0x00 },
    { L"Extra 1", 0x107822, 0x107842 },
    { L"Super Trail 1", 0x107842, 0x107862, indexKOFSprites_98Mature, 0x00 },
    { L"Super Trail 2", 0x107862, 0x107882 },
    { L"MAX Mode", 0x107882, 0x1078a2, indexKOFSprites_98Mature, 0x00 },
    { L"Extra 1", 0x1078a2, 0x1078c2 },
    { L"Electric Palette?", 0x1078c2, 0x1078e2, indexKOFSprites_98Mature, 0x00 },
    { L"Extra 3", 0x1078e2, 0x107902 },
    { L"Extra 5", 0x107922, 0x107942 },
    { L"Extra 6", 0x107942, 0x107962 },
    { L"Extra 7", 0x107962, 0x107982 },
    { L"Extra 8", 0x107982, 0x1079a2 },
    { L"Monochrome Palette", 0x1079a2, 0x1079c2, indexKOFSprites_98Mature, 0x00 },
    { L"Extra 9", 0x1079c2, 0x1079e2 },
    { L"Lifebar Portrait", 0x1079e2, 0x107a02, indexKOFSprites_98Mature, 0x20 },
};

const sGame_PaletteDataset KOF96_A_MATURE_D_PALETTES[] =
{
    { L"Mature", 0x107a02, 0x107a22, indexKOFSprites_98Mature, 0x00 },
    { L"Extra 1", 0x107a22, 0x107a42 },
    { L"Super Trail 1", 0x107a42, 0x107a62, indexKOFSprites_98Mature, 0x00 },
    { L"Super Trail 2", 0x107a62, 0x107a82 },
    { L"MAX Mode", 0x107a82, 0x107aa2, indexKOFSprites_98Mature, 0x00 },
    { L"Extra 1", 0x107aa2, 0x107ac2 },
    { L"Electric Palette?", 0x107ac2, 0x107ae2, indexKOFSprites_98Mature, 0x00 },
    { L"Extra 3", 0x107ae2, 0x107b02 },
    { L"Extra 5", 0x107b22, 0x107b42 },
    { L"Extra 6", 0x107b42, 0x107b62 },
    { L"Extra 7", 0x107b62, 0x107b82 },
    { L"Extra 8", 0x107b82, 0x107ba2 },
    { L"Monochrome Palette", 0x107ba2, 0x107bc2, indexKOFSprites_98Mature, 0x00 },
    { L"Extra 9", 0x107bc2, 0x107be2 },
    { L"Lifebar Portrait", 0x107be2, 0x107c02, indexKOFSprites_98Mature, 0x20 },
};

const sGame_PaletteDataset KOF96_A_VICE_A_PALETTES[] =
{
    { L"Vice", 0x107c02, 0x107c22, indexKOFSprites_98Vice, 0x00 },
    { L"Extra 1", 0x107c22, 0x107c42 },
    { L"Super Trail 1", 0x107c42, 0x107c62, indexKOFSprites_98Vice, 0x00 },
    { L"Super Trail 2", 0x107c62, 0x107c82 },
    { L"MAX Mode", 0x107c82, 0x107ca2, indexKOFSprites_98Vice, 0x00 },
    { L"Extra 1", 0x107ca2, 0x107cc2 },
    { L"Electric Palette?", 0x107cc2, 0x107ce2, indexKOFSprites_98Vice, 0x00 },
    { L"Extra 3", 0x107ce2, 0x107d02 },
    { L"Extra 5", 0x107d22, 0x107d42 },
    { L"Extra 6", 0x107d42, 0x107d62 },
    { L"Extra 7", 0x107d62, 0x107d82 },
    { L"Extra 8", 0x107d82, 0x107da2 },
    { L"Monochrome Palette", 0x107da2, 0x107dc2, indexKOFSprites_98Vice, 0x00 },
    { L"Extra 9", 0x107dc2, 0x107de2 },
    { L"Lifebar Portrait", 0x107de2, 0x107e02, indexKOFSprites_98Vice, 0x20 },
};

const sGame_PaletteDataset KOF96_A_VICE_D_PALETTES[] =
{
    { L"Vice", 0x107e02, 0x107e22, indexKOFSprites_98Vice, 0x00 },
    { L"Extra 1", 0x107e22, 0x107e42 },
    { L"Super Trail 1", 0x107e42, 0x107e62, indexKOFSprites_98Vice, 0x00 },
    { L"Super Trail 2", 0x107e62, 0x107e82 },
    { L"MAX Mode", 0x107e82, 0x107ea2, indexKOFSprites_98Vice, 0x00 },
    { L"Extra 1", 0x107ea2, 0x107ec2 },
    { L"Electric Palette?", 0x107ec2, 0x107ee2, indexKOFSprites_98Vice, 0x00 },
    { L"Extra 3", 0x107ee2, 0x107f02 },
    { L"Extra 5", 0x107f22, 0x107f42 },
    { L"Extra 6", 0x107f42, 0x107f62 },
    { L"Extra 7", 0x107f62, 0x107f82 },
    { L"Extra 8", 0x107f82, 0x107fa2 },
    { L"Monochrome Palette", 0x107fa2, 0x107fc2, indexKOFSprites_98Vice, 0x00 },
    { L"Extra 9", 0x107fc2, 0x107fe2 },
    { L"Lifebar Portrait", 0x107fe2, 0x108002, indexKOFSprites_98Vice, 0x20 },
};

const sGame_PaletteDataset KOF96_A_GEESE_A_PALETTES[] =
{
    { L"Geese", 0x108002, 0x108022, indexKOFSprites_02Geese, 0x00 },
    { L"Extra 1", 0x108022, 0x108042 },
    { L"Super Trail 1", 0x108042, 0x108062, indexKOFSprites_02Geese, 0x00 },
    { L"Super Trail 2", 0x108062, 0x108082 },
    { L"MAX Mode", 0x108082, 0x1080a2, indexKOFSprites_02Geese, 0x00 },
    { L"Extra 1", 0x1080a2, 0x1080c2 },
    { L"Electric Palette?", 0x1080c2, 0x1080e2, indexKOFSprites_02Geese, 0x00 },
    { L"Extra 3", 0x1080e2, 0x108102 },
    { L"Extra 5", 0x108122, 0x108142 },
    { L"Extra 6", 0x108142, 0x108162 },
    { L"Extra 7", 0x108162, 0x108182 },
    { L"Extra 8", 0x108182, 0x1081a2 },
    { L"Monochrome Palette", 0x1081a2, 0x1081c2, indexKOFSprites_02Geese, 0x00 },
    { L"Extra 9", 0x1081c2, 0x1081e2 },
    { L"Lifebar Portrait", 0x1081e2, 0x108202, indexKOFSprites_02Geese, 0x20 },
};

const sGame_PaletteDataset KOF96_A_GEESE_D_PALETTES[] =
{
    { L"Geese", 0x108202, 0x108222, indexKOFSprites_02Geese, 0x00 },
    { L"Extra 1", 0x108222, 0x108242 },
    { L"Super Trail 1", 0x108242, 0x108262, indexKOFSprites_02Geese, 0x00 },
    { L"Super Trail 2", 0x108262, 0x108282 },
    { L"MAX Mode", 0x108282, 0x1082a2, indexKOFSprites_02Geese, 0x00 },
    { L"Extra 1", 0x1082a2, 0x1082c2 },
    { L"Electric Palette?", 0x1082c2, 0x1082e2, indexKOFSprites_02Geese, 0x00 },
    { L"Extra 3", 0x1082e2, 0x108302 },
    { L"Extra 5", 0x108322, 0x108342 },
    { L"Extra 6", 0x108342, 0x108362 },
    { L"Extra 7", 0x108362, 0x108382 },
    { L"Extra 8", 0x108382, 0x1083a2 },
    { L"Monochrome Palette", 0x1083a2, 0x1083c2, indexKOFSprites_02Geese, 0x00 },
    { L"Extra 9", 0x1083c2, 0x1083e2 },
    { L"Lifebar Portrait", 0x1083e2, 0x108402, indexKOFSprites_02Geese, 0x20 },
};

const sGame_PaletteDataset KOF96_A_KRAUSER_A_PALETTES[] =
{
    { L"Krauser", 0x108402, 0x108422, INVALID_UNIT_VALUE, 0x00 },
    { L"Extra 1", 0x108422, 0x108442 },
    { L"Super Trail 1", 0x108442, 0x108462, INVALID_UNIT_VALUE, 0x00 },
    { L"Super Trail 2", 0x108462, 0x108482 },
    { L"MAX Mode", 0x108482, 0x1084a2, INVALID_UNIT_VALUE, 0x00 },
    { L"Extra 1", 0x1084a2, 0x1084c2 },
    { L"Electric Palette?", 0x1084c2, 0x1084e2, INVALID_UNIT_VALUE, 0x00 },
    { L"Extra 3", 0x1084e2, 0x108502 },
    { L"Extra 5", 0x108522, 0x108542 },
    { L"Extra 6", 0x108542, 0x108562 },
    { L"Extra 7", 0x108562, 0x108582 },
    { L"Extra 8", 0x108582, 0x1085a2 },
    { L"Monochrome Palette", 0x1085a2, 0x1085c2, INVALID_UNIT_VALUE, 0x00 },
    { L"Extra 9", 0x1085c2, 0x1085e2 },
    { L"Lifebar Portrait", 0x1085e2, 0x108602, INVALID_UNIT_VALUE, 0x20 },
};

const sGame_PaletteDataset KOF96_A_KRAUSER_D_PALETTES[] =
{
    { L"Krauser", 0x108602, 0x108622, INVALID_UNIT_VALUE, 0x00 },
    { L"Extra 1", 0x108622, 0x108642 },
    { L"Super Trail 1", 0x108642, 0x108662, INVALID_UNIT_VALUE, 0x00 },
    { L"Super Trail 2", 0x108662, 0x108682 },
    { L"MAX Mode", 0x108682, 0x1086a2, INVALID_UNIT_VALUE, 0x00 },
    { L"Extra 1", 0x1086a2, 0x1086c2 },
    { L"Electric Palette?", 0x1086c2, 0x1086e2, INVALID_UNIT_VALUE, 0x00 },
    { L"Extra 3", 0x1086e2, 0x108702 },
    { L"Extra 5", 0x108722, 0x108742 },
    { L"Extra 6", 0x108742, 0x108762 },
    { L"Extra 7", 0x108762, 0x108782 },
    { L"Extra 8", 0x108782, 0x1087a2 },
    { L"Monochrome Palette", 0x1087a2, 0x1087c2, INVALID_UNIT_VALUE, 0x00 },
    { L"Extra 9", 0x1087c2, 0x1087e2 },
    { L"Lifebar Portrait", 0x1087e2, 0x108802, INVALID_UNIT_VALUE, 0x20 },
};

const sGame_PaletteDataset KOF96_A_MRBIG_A_PALETTES[] =
{
    { L"Mr. Big", 0x108802, 0x108822, INVALID_UNIT_VALUE, 0x00 },
    { L"Extra 1", 0x108822, 0x108842 },
    { L"Super Trail 1", 0x108842, 0x108862, INVALID_UNIT_VALUE, 0x00 },
    { L"Super Trail 2", 0x108862, 0x108882 },
    { L"MAX Mode", 0x108882, 0x1088a2, INVALID_UNIT_VALUE, 0x00 },
    { L"Extra 1", 0x1088a2, 0x1088c2 },
    { L"Electric Palette?", 0x1088c2, 0x1088e2, INVALID_UNIT_VALUE, 0x00 },
    { L"Extra 3", 0x1088e2, 0x108902 },
    { L"Extra 5", 0x108922, 0x108942 },
    { L"Extra 6", 0x108942, 0x108962 },
    { L"Extra 7", 0x108962, 0x108982 },
    { L"Extra 8", 0x108982, 0x1089a2 },
    { L"Monochrome Palette", 0x1089a2, 0x1089c2, INVALID_UNIT_VALUE, 0x00 },
    { L"Extra 9", 0x1089c2, 0x1089e2 },
    { L"Lifebar Portrait", 0x1089e2, 0x108a02, INVALID_UNIT_VALUE, 0x20 },
};

const sGame_PaletteDataset KOF96_A_MRBIG_D_PALETTES[] =
{
    { L"Mr. Big", 0x108a02, 0x108a22, INVALID_UNIT_VALUE, 0x00 },
    { L"Extra 1", 0x108a22, 0x108a42 },
    { L"Super Trail 1", 0x108a42, 0x108a62, INVALID_UNIT_VALUE, 0x00 },
    { L"Super Trail 2", 0x108a62, 0x108a82 },
    { L"MAX Mode", 0x108a82, 0x108aa2, INVALID_UNIT_VALUE, 0x00 },
    { L"Extra 1", 0x108aa2, 0x108ac2 },
    { L"Electric Palette?", 0x108ac2, 0x108ae2, INVALID_UNIT_VALUE, 0x00 },
    { L"Extra 3", 0x108ae2, 0x108b02 },
    { L"Extra 5", 0x108b22, 0x108b42 },
    { L"Extra 6", 0x108b42, 0x108b62 },
    { L"Extra 7", 0x108b62, 0x108b82 },
    { L"Extra 8", 0x108b82, 0x108ba2 },
    { L"Monochrome Palette", 0x108ba2, 0x108bc2, INVALID_UNIT_VALUE, 0x00 },
    { L"Extra 9", 0x108bc2, 0x108be2 },
    { L"Lifebar Portrait", 0x108be2, 0x108c02, INVALID_UNIT_VALUE, 0x20 },
};

const sGame_PaletteDataset KOF96_A_CHIZURU_A_PALETTES[] =
{
    { L"Chizuru", 0x108c02, 0x108c22, indexKOFSprites_98Chizuru, 0x00 },
    { L"Extra 1", 0x108c22, 0x108c42 },
    { L"Super Trail 1", 0x108c42, 0x108c62, indexKOFSprites_98Chizuru, 0x00 },
    { L"Super Trail 2", 0x108c62, 0x108c82 },
    { L"MAX Mode", 0x108c82, 0x108ca2, indexKOFSprites_98Chizuru, 0x00 },
    { L"Extra 1", 0x108ca2, 0x108cc2 },
    { L"Electric Palette?", 0x108cc2, 0x108ce2, indexKOFSprites_98Chizuru, 0x00 },
    { L"Extra 3", 0x108ce2, 0x108d02 },
    { L"Extra 5", 0x108d22, 0x108d42 },
    { L"Extra 6", 0x108d42, 0x108d62 },
    { L"Extra 7", 0x108d62, 0x108d82 },
    { L"Extra 8", 0x108d82, 0x108da2 },
    { L"Monochrome Palette", 0x108da2, 0x108dc2, indexKOFSprites_98Chizuru, 0x00 },
    { L"Extra 9", 0x108dc2, 0x108de2 },
    { L"Lifebar Portrait", 0x108de2, 0x108e02, indexKOFSprites_98Chizuru, 0x20 },
};

const sGame_PaletteDataset KOF96_A_CHIZURU_D_PALETTES[] =
{
    { L"Chizuru", 0x108e02, 0x108e22, indexKOFSprites_98Chizuru, 0x00 },
    { L"Extra 1", 0x108e22, 0x108e42 },
    { L"Super Trail 1", 0x108e42, 0x108e62, indexKOFSprites_98Chizuru, 0x00 },
    { L"Super Trail 2", 0x108e62, 0x108e82 },
    { L"MAX Mode", 0x108e82, 0x108ea2, indexKOFSprites_98Chizuru, 0x00 },
    { L"Extra 1", 0x108ea2, 0x108ec2 },
    { L"Electric Palette?", 0x108ec2, 0x108ee2, indexKOFSprites_98Chizuru, 0x00 },
    { L"Extra 3", 0x108ee2, 0x108f02 },
    { L"Extra 5", 0x108f22, 0x108f42 },
    { L"Extra 6", 0x108f42, 0x108f62 },
    { L"Extra 7", 0x108f62, 0x108f82 },
    { L"Extra 8", 0x108f82, 0x108fa2 },
    { L"Monochrome Palette", 0x108fa2, 0x108fc2, indexKOFSprites_98Chizuru, 0x00 },
    { L"Extra 9", 0x108fc2, 0x108fe2 },
    { L"Lifebar Portrait", 0x108fe2, 0x109002, indexKOFSprites_98Chizuru, 0x20 },
};

const sGame_PaletteDataset KOF96_A_GOENITZ_A_PALETTES[] =
{
    { L"Goenitz", 0x109002, 0x109022, indexKOFSprites_02Goenitz, 0x00 },
    { L"Extra 1", 0x109022, 0x109042 },
    { L"Super Trail 1", 0x109042, 0x109062, indexKOFSprites_02Goenitz, 0x00 },
    { L"Super Trail 2", 0x109062, 0x109082 },
    { L"MAX Mode", 0x109082, 0x1090a2, indexKOFSprites_02Goenitz, 0x00 },
    { L"Extra 1", 0x1090a2, 0x1090c2 },
    { L"Electric Palette?", 0x1090c2, 0x1090e2, indexKOFSprites_02Goenitz, 0x00 },
    { L"Extra 3", 0x1090e2, 0x109102 },
    { L"Extra 5", 0x109122, 0x109142 },
    { L"Extra 6", 0x109142, 0x109162 },
    { L"Extra 7", 0x109162, 0x109182 },
    { L"Extra 8", 0x109182, 0x1091a2 },
    { L"Monochrome Palette", 0x1091a2, 0x1091c2, indexKOFSprites_02Goenitz, 0x00 },
    { L"Extra 9", 0x1091c2, 0x1091e2 },
    { L"Lifebar Portrait", 0x1091e2, 0x109202, indexKOFSprites_02Goenitz, 0x20 },
};

const sGame_PaletteDataset KOF96_A_GOENITZ_D_PALETTES[] =
{
    { L"Goenitz", 0x109202, 0x109222, indexKOFSprites_02Goenitz, 0x00 },
    { L"Extra 1", 0x109222, 0x109242 },
    { L"Super Trail 1", 0x109242, 0x109262, indexKOFSprites_02Goenitz, 0x00 },
    { L"Super Trail 2", 0x109262, 0x109282 },
    { L"MAX Mode", 0x109282, 0x1092a2, indexKOFSprites_02Goenitz, 0x00 },
    { L"Extra 1", 0x1092a2, 0x1092c2 },
    { L"Electric Palette?", 0x1092c2, 0x1092e2, indexKOFSprites_02Goenitz, 0x00 },
    { L"Extra 3", 0x1092e2, 0x109302 },
    { L"Extra 5", 0x109322, 0x109342 },
    { L"Extra 6", 0x109342, 0x109362 },
    { L"Extra 7", 0x109362, 0x109382 },
    { L"Extra 8", 0x109382, 0x1093a2 },
    { L"Monochrome Palette", 0x1093a2, 0x1093c2, indexKOFSprites_02Goenitz, 0x00 },
    { L"Extra 9", 0x1093c2, 0x1093e2 },
    { L"Lifebar Portrait", 0x1093e2, 0x109402, indexKOFSprites_02Goenitz, 0x20 },
};

const sDescTreeNode KOF96_A_KYO_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_KYO_A_PALETTES, ARRAYSIZE(KOF96_A_KYO_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_KYO_D_PALETTES, ARRAYSIZE(KOF96_A_KYO_D_PALETTES) },
};

const sDescTreeNode KOF96_A_BENIMARU_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_BENIMARU_A_PALETTES, ARRAYSIZE(KOF96_A_BENIMARU_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_BENIMARU_D_PALETTES, ARRAYSIZE(KOF96_A_BENIMARU_D_PALETTES) },
};

const sDescTreeNode KOF96_A_DAIMON_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_DAIMON_A_PALETTES, ARRAYSIZE(KOF96_A_DAIMON_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_DAIMON_D_PALETTES, ARRAYSIZE(KOF96_A_DAIMON_D_PALETTES) },
};

const sDescTreeNode KOF96_A_TERRY_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_TERRY_A_PALETTES, ARRAYSIZE(KOF96_A_TERRY_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_TERRY_D_PALETTES, ARRAYSIZE(KOF96_A_TERRY_D_PALETTES) },
};

const sDescTreeNode KOF96_A_ANDY_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_ANDY_A_PALETTES, ARRAYSIZE(KOF96_A_ANDY_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_ANDY_D_PALETTES, ARRAYSIZE(KOF96_A_ANDY_D_PALETTES) },
};

const sDescTreeNode KOF96_A_JOE_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_JOE_A_PALETTES, ARRAYSIZE(KOF96_A_JOE_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_JOE_D_PALETTES, ARRAYSIZE(KOF96_A_JOE_D_PALETTES) },
};

const sDescTreeNode KOF96_A_RYO_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_RYO_A_PALETTES, ARRAYSIZE(KOF96_A_RYO_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_RYO_D_PALETTES, ARRAYSIZE(KOF96_A_RYO_D_PALETTES) },
};

const sDescTreeNode KOF96_A_ROBERT_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_ROBERT_A_PALETTES, ARRAYSIZE(KOF96_A_ROBERT_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_ROBERT_D_PALETTES, ARRAYSIZE(KOF96_A_ROBERT_D_PALETTES) },
};

const sDescTreeNode KOF96_A_YURI_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_YURI_A_PALETTES, ARRAYSIZE(KOF96_A_YURI_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_YURI_D_PALETTES, ARRAYSIZE(KOF96_A_YURI_D_PALETTES) },
};

const sDescTreeNode KOF96_A_LEONA_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_LEONA_A_PALETTES, ARRAYSIZE(KOF96_A_LEONA_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_LEONA_D_PALETTES, ARRAYSIZE(KOF96_A_LEONA_D_PALETTES) },
};

const sDescTreeNode KOF96_A_RALF_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_RALF_A_PALETTES, ARRAYSIZE(KOF96_A_RALF_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_RALF_D_PALETTES, ARRAYSIZE(KOF96_A_RALF_D_PALETTES) },
};

const sDescTreeNode KOF96_A_CLARK_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_CLARK_A_PALETTES, ARRAYSIZE(KOF96_A_CLARK_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_CLARK_D_PALETTES, ARRAYSIZE(KOF96_A_CLARK_D_PALETTES) },
};

const sDescTreeNode KOF96_A_ATHENA_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_ATHENA_A_PALETTES, ARRAYSIZE(KOF96_A_ATHENA_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_ATHENA_D_PALETTES, ARRAYSIZE(KOF96_A_ATHENA_D_PALETTES) },
};

const sDescTreeNode KOF96_A_KENSOU_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_KENSOU_A_PALETTES, ARRAYSIZE(KOF96_A_KENSOU_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_KENSOU_D_PALETTES, ARRAYSIZE(KOF96_A_KENSOU_D_PALETTES) },
};

const sDescTreeNode KOF96_A_CHIN_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_CHIN_A_PALETTES, ARRAYSIZE(KOF96_A_CHIN_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_CHIN_D_PALETTES, ARRAYSIZE(KOF96_A_CHIN_D_PALETTES) },
};

const sDescTreeNode KOF96_A_KASUMI_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_KASUMI_A_PALETTES, ARRAYSIZE(KOF96_A_KASUMI_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_KASUMI_D_PALETTES, ARRAYSIZE(KOF96_A_KASUMI_D_PALETTES) },
};

const sDescTreeNode KOF96_A_MAI_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_MAI_A_PALETTES, ARRAYSIZE(KOF96_A_MAI_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_MAI_D_PALETTES, ARRAYSIZE(KOF96_A_MAI_D_PALETTES) },
};

const sDescTreeNode KOF96_A_KING_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_KING_A_PALETTES, ARRAYSIZE(KOF96_A_KING_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_KING_D_PALETTES, ARRAYSIZE(KOF96_A_KING_D_PALETTES) },
};

const sDescTreeNode KOF96_A_KIM_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_KIM_A_PALETTES, ARRAYSIZE(KOF96_A_KIM_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_KIM_D_PALETTES, ARRAYSIZE(KOF96_A_KIM_D_PALETTES) },
};

const sDescTreeNode KOF96_A_CHANG_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_CHANG_A_PALETTES, ARRAYSIZE(KOF96_A_CHANG_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_CHANG_D_PALETTES, ARRAYSIZE(KOF96_A_CHANG_D_PALETTES) },
};

const sDescTreeNode KOF96_A_CHOI_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_CHOI_A_PALETTES, ARRAYSIZE(KOF96_A_CHOI_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_CHOI_D_PALETTES, ARRAYSIZE(KOF96_A_CHOI_D_PALETTES) },
};

const sDescTreeNode KOF96_A_IORI_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_IORI_A_PALETTES, ARRAYSIZE(KOF96_A_IORI_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_IORI_D_PALETTES, ARRAYSIZE(KOF96_A_IORI_D_PALETTES) },
};

const sDescTreeNode KOF96_A_MATURE_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_MATURE_A_PALETTES, ARRAYSIZE(KOF96_A_MATURE_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_MATURE_D_PALETTES, ARRAYSIZE(KOF96_A_MATURE_D_PALETTES) },
};

const sDescTreeNode KOF96_A_VICE_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_VICE_A_PALETTES, ARRAYSIZE(KOF96_A_VICE_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_VICE_D_PALETTES, ARRAYSIZE(KOF96_A_VICE_D_PALETTES) },
};

const sDescTreeNode KOF96_A_GEESE_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_GEESE_A_PALETTES, ARRAYSIZE(KOF96_A_GEESE_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_GEESE_D_PALETTES, ARRAYSIZE(KOF96_A_GEESE_D_PALETTES) },
};

const sDescTreeNode KOF96_A_KRAUSER_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_KRAUSER_A_PALETTES, ARRAYSIZE(KOF96_A_KRAUSER_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_KRAUSER_D_PALETTES, ARRAYSIZE(KOF96_A_KRAUSER_D_PALETTES) },
};

const sDescTreeNode KOF96_A_MRBIG_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_MRBIG_A_PALETTES, ARRAYSIZE(KOF96_A_MRBIG_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_MRBIG_D_PALETTES, ARRAYSIZE(KOF96_A_MRBIG_D_PALETTES) },
};

const sDescTreeNode KOF96_A_CHIZURU_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_CHIZURU_A_PALETTES, ARRAYSIZE(KOF96_A_CHIZURU_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_CHIZURU_D_PALETTES, ARRAYSIZE(KOF96_A_CHIZURU_D_PALETTES) },
};

const sDescTreeNode KOF96_A_GOENITZ_COLLECTION[] =
{
    { L"A", DESC_NODETYPE_TREE, (void*)KOF96_A_GOENITZ_A_PALETTES, ARRAYSIZE(KOF96_A_GOENITZ_A_PALETTES) },
    { L"D", DESC_NODETYPE_TREE, (void*)KOF96_A_GOENITZ_D_PALETTES, ARRAYSIZE(KOF96_A_GOENITZ_D_PALETTES) },
};

const sDescTreeNode KOF96_A_UNITS[] =
{
    { L"Kyo", DESC_NODETYPE_TREE, (void*)KOF96_A_KYO_COLLECTION, ARRAYSIZE(KOF96_A_KYO_COLLECTION) },
    { L"Benimaru", DESC_NODETYPE_TREE, (void*)KOF96_A_BENIMARU_COLLECTION, ARRAYSIZE(KOF96_A_BENIMARU_COLLECTION) },
    { L"Daimon", DESC_NODETYPE_TREE, (void*)KOF96_A_DAIMON_COLLECTION, ARRAYSIZE(KOF96_A_DAIMON_COLLECTION) },
    { L"Terry", DESC_NODETYPE_TREE, (void*)KOF96_A_TERRY_COLLECTION, ARRAYSIZE(KOF96_A_TERRY_COLLECTION) },
    { L"Andy", DESC_NODETYPE_TREE, (void*)KOF96_A_ANDY_COLLECTION, ARRAYSIZE(KOF96_A_ANDY_COLLECTION) },
    { L"Joe", DESC_NODETYPE_TREE, (void*)KOF96_A_JOE_COLLECTION, ARRAYSIZE(KOF96_A_JOE_COLLECTION) },
    { L"Ryo", DESC_NODETYPE_TREE, (void*)KOF96_A_RYO_COLLECTION, ARRAYSIZE(KOF96_A_RYO_COLLECTION) },
    { L"Robert", DESC_NODETYPE_TREE, (void*)KOF96_A_ROBERT_COLLECTION, ARRAYSIZE(KOF96_A_ROBERT_COLLECTION) },
    { L"Yuri", DESC_NODETYPE_TREE, (void*)KOF96_A_YURI_COLLECTION, ARRAYSIZE(KOF96_A_YURI_COLLECTION) },
    { L"Leona", DESC_NODETYPE_TREE, (void*)KOF96_A_LEONA_COLLECTION, ARRAYSIZE(KOF96_A_LEONA_COLLECTION) },
    { L"Ralf", DESC_NODETYPE_TREE, (void*)KOF96_A_RALF_COLLECTION, ARRAYSIZE(KOF96_A_RALF_COLLECTION) },
    { L"Clark", DESC_NODETYPE_TREE, (void*)KOF96_A_CLARK_COLLECTION, ARRAYSIZE(KOF96_A_CLARK_COLLECTION) },
    { L"Athena", DESC_NODETYPE_TREE, (void*)KOF96_A_ATHENA_COLLECTION, ARRAYSIZE(KOF96_A_ATHENA_COLLECTION) },
    { L"Kensou", DESC_NODETYPE_TREE, (void*)KOF96_A_KENSOU_COLLECTION, ARRAYSIZE(KOF96_A_KENSOU_COLLECTION) },
    { L"Chin", DESC_NODETYPE_TREE, (void*)KOF96_A_CHIN_COLLECTION, ARRAYSIZE(KOF96_A_CHIN_COLLECTION) },
    { L"Kasumi", DESC_NODETYPE_TREE, (void*)KOF96_A_KASUMI_COLLECTION, ARRAYSIZE(KOF96_A_KASUMI_COLLECTION) },
    { L"Mai", DESC_NODETYPE_TREE, (void*)KOF96_A_MAI_COLLECTION, ARRAYSIZE(KOF96_A_MAI_COLLECTION) },
    { L"King", DESC_NODETYPE_TREE, (void*)KOF96_A_KING_COLLECTION, ARRAYSIZE(KOF96_A_KING_COLLECTION) },
    { L"Kim", DESC_NODETYPE_TREE, (void*)KOF96_A_KIM_COLLECTION, ARRAYSIZE(KOF96_A_KIM_COLLECTION) },
    { L"Chang", DESC_NODETYPE_TREE, (void*)KOF96_A_CHANG_COLLECTION, ARRAYSIZE(KOF96_A_CHANG_COLLECTION) },
    { L"Choi", DESC_NODETYPE_TREE, (void*)KOF96_A_CHOI_COLLECTION, ARRAYSIZE(KOF96_A_CHOI_COLLECTION) },
    { L"Iori", DESC_NODETYPE_TREE, (void*)KOF96_A_IORI_COLLECTION, ARRAYSIZE(KOF96_A_IORI_COLLECTION) },
    { L"Mature", DESC_NODETYPE_TREE, (void*)KOF96_A_MATURE_COLLECTION, ARRAYSIZE(KOF96_A_MATURE_COLLECTION) },
    { L"Vice", DESC_NODETYPE_TREE, (void*)KOF96_A_VICE_COLLECTION, ARRAYSIZE(KOF96_A_VICE_COLLECTION) },
    { L"Geese", DESC_NODETYPE_TREE, (void*)KOF96_A_GEESE_COLLECTION, ARRAYSIZE(KOF96_A_GEESE_COLLECTION) },
    { L"Krauser", DESC_NODETYPE_TREE, (void*)KOF96_A_KRAUSER_COLLECTION, ARRAYSIZE(KOF96_A_KRAUSER_COLLECTION) },
    { L"Mr. Big", DESC_NODETYPE_TREE, (void*)KOF96_A_MRBIG_COLLECTION, ARRAYSIZE(KOF96_A_MRBIG_COLLECTION) },
    { L"Chizuru", DESC_NODETYPE_TREE, (void*)KOF96_A_CHIZURU_COLLECTION, ARRAYSIZE(KOF96_A_CHIZURU_COLLECTION) },
    { L"Goenitz", DESC_NODETYPE_TREE, (void*)KOF96_A_GOENITZ_COLLECTION, ARRAYSIZE(KOF96_A_GOENITZ_COLLECTION) },
};

constexpr auto KOF96_A_NUMUNIT = ARRAYSIZE(KOF96_A_UNITS);

#define KOF96_A_EXTRALOC KOF96_A_NUMUNIT

// We extend this array with data groveled from the extras file, if any.
const stExtraDef KOF96_A_EXTRA[] =
{
    // Start
    { UNIT_START_VALUE },

    { INVALID_UNIT_VALUE }
};
