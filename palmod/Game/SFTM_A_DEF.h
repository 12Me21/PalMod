#pragma once

// To add characters or palette lists:
// * Update the SupportedPaletteListIndex with the new index name.
// * Add an array below along the lines of SFTM_A_RYU_PALETTE_P1. 
// * Update every array using SFTM_A_NUMUNIT below
// That should be it.  Good luck.

const std::vector<uint16_t> SFTM_A_IMGIDS_USED =
{
};

// these two are in flipped order on the rom
const sGame_PaletteDataset SFTM_A_SAGAT_PALETTE_P2[] =
{
    { L"Sagat", 0xff1c, 0x1021c },
};

const sGame_PaletteDataset SFTM_A_SAGAT_PALETTE_P1[] =
{
    { L"Sagat", 0x1021c, 0x1051c },
};

const sGame_PaletteDataset SFTM_A_RYU_PALETTE_P1[] =
{
    { L"Ryu", 0x1051c, 0x1081c },
};

const sGame_PaletteDataset SFTM_A_RYU_PALETTE_P2[] =
{
    { L"Ryu", 0x1081c, 0x10b1c },
};

const sGame_PaletteDataset SFTM_A_VEGA_PALETTE_P1[] =
{
    { L"Vega", 0x10b1c, 0x10e1c },
};

const sGame_PaletteDataset SFTM_A_VEGA_PALETTE_P2[] =
{
    { L"Vega", 0x10e1c, 0x1111c },
};

const sGame_PaletteDataset SFTM_A_HONDA_PALETTE_P1[] =
{
    { L"Honda", 0x1111c, 0x1141c },
};

const sGame_PaletteDataset SFTM_A_HONDA_PALETTE_P2[] =
{
    { L"Honda", 0x1141c, 0x1171c },
};

const sGame_PaletteDataset SFTM_A_ZANGIEF_PALETTE_P1[] =
{
    { L"Zangief", 0x1171c, 0x11a1c },
};

const sGame_PaletteDataset SFTM_A_ZANGIEF_PALETTE_P2[] =
{
    { L"Zangief", 0x11a1c, 0x11d1c },
};

const sGame_PaletteDataset SFTM_A_BISON_PALETTE_P1[] =
{
    { L"M. Bison", 0x11d1c, 0x1201c },
};

const sGame_PaletteDataset SFTM_A_BISON_PALETTE_P2[] =
{
    { L"M. Bison", 0x1201c, 0x1231c },
};

const sGame_PaletteDataset SFTM_A_BISON_PALETTE_SUPER[] =
{
    { L"Super Bison", 0x1231c, 0x1261c },
};

const sGame_PaletteDataset SFTM_A_CAMMY_PALETTE_P1[] =
{
    { L"Cammy", 0x1261c, 0x1291c },
};

const sGame_PaletteDataset SFTM_A_CAMMY_PALETTE_P2[] =
{
    { L"Cammy", 0x1291c, 0x12c1c },
};

const sGame_PaletteDataset SFTM_A_BALROG_PALETTE_P1[] =
{
    { L"Balrog", 0x12c1c, 0x12f1c },
};

const sGame_PaletteDataset SFTM_A_BALROG_PALETTE_P2[] =
{
    { L"Balrog", 0x12f1c, 0x1321c },
};

const sGame_PaletteDataset SFTM_A_GUILE_PALETTE_P1[] =
{
    { L"Guile", 0x1321c, 0x1351c },
};

const sGame_PaletteDataset SFTM_A_GUILE_PALETTE_P2[] =
{
    { L"Guile", 0x1351c, 0x1381c },
};

const sGame_PaletteDataset SFTM_A_AKUMA_PALETTE_P1[] =
{
    { L"Akuma", 0x1381c, 0x13b1c },
};

const sGame_PaletteDataset SFTM_A_AKUMA_PALETTE_P2[] =
{
    { L"Akuma", 0x13b1c, 0x13e1c },
};

// These two are backwards on the ROM
const sGame_PaletteDataset SFTM_A_KEN_PALETTE_P2[] =
{
    { L"Ken", 0x13e1c, 0x1411c },
};

const sGame_PaletteDataset SFTM_A_KEN_PALETTE_P1[] =
{
    { L"Ken", 0x1411c, 0x1441c },
};

const sGame_PaletteDataset SFTM_A_CHUNLI_PALETTE_P1[] =
{
    { L"Chun-Li", 0x1441c, 0x1471c },
};

const sGame_PaletteDataset SFTM_A_CHUNLI_PALETTE_P2[] =
{
    { L"Chun-Li", 0x1471c, 0x14a1c },
};

const sGame_PaletteDataset SFTM_A_BLADE_PALETTE_P1[] =
{
    { L"Blade", 0x14a1c, 0x14d1c },
};

const sGame_PaletteDataset SFTM_A_BLADE_PALETTE_P2[] =
{
    { L"Blade", 0x14d1c, 0x1501c },
};

const sGame_PaletteDataset SFTM_A_KHYBER_PALETTE_P1[] =
{
    { L"Khyber", 0x1501c, 0x1531c },
};

const sGame_PaletteDataset SFTM_A_KHYBER_PALETTE_P2[] =
{
    { L"Khyber", 0x1531c, 0x1561c },
};

const sGame_PaletteDataset SFTM_A_ARKANE_PALETTE_P1[] =
{
    { L"Arkane", 0x1561c, 0x1591c },
};

const sGame_PaletteDataset SFTM_A_ARKANE_PALETTE_P2[] =
{
    { L"Arkane", 0x1591c, 0x15c1c },
};

const sGame_PaletteDataset SFTM_A_F7_PALETTE_P1[] =
{
    { L"F7", 0x15c1c, 0x15f1c },
};

const sGame_PaletteDataset SFTM_A_F7_PALETTE_P2[] =
{
    { L"F7", 0x15f1c, 0x1621c },
};

const sGame_PaletteDataset SFTM_A_SAWADA_PALETTE_P1[] =
{
    { L"Sawada", 0x1621c, 0x1651c },
};

const sGame_PaletteDataset SFTM_A_SAWADA_PALETTE_P2[] =
{
    { L"Sawada", 0x1651c, 0x1681c },
};

const sGame_PaletteDataset SFTM_A_VEGA_PALETTE_MASK[] =
{
    { L"Mask", 0x1771c, 0x17a1c },
};

const sDescTreeNode SFTM_A_RYU_COLLECTION[] =
{
    { L"P1", DESC_NODETYPE_TREE, (void*)SFTM_A_RYU_PALETTE_P1, ARRAYSIZE(SFTM_A_RYU_PALETTE_P1) },
    { L"P2", DESC_NODETYPE_TREE, (void*)SFTM_A_RYU_PALETTE_P2, ARRAYSIZE(SFTM_A_RYU_PALETTE_P2) },
};

const sDescTreeNode SFTM_A_VEGA_COLLECTION[] =
{
    { L"P1", DESC_NODETYPE_TREE, (void*)SFTM_A_VEGA_PALETTE_P1, ARRAYSIZE(SFTM_A_VEGA_PALETTE_P1) },
    { L"P2", DESC_NODETYPE_TREE, (void*)SFTM_A_VEGA_PALETTE_P2, ARRAYSIZE(SFTM_A_VEGA_PALETTE_P2) },
    { L"Extras", DESC_NODETYPE_TREE, (void*)SFTM_A_VEGA_PALETTE_MASK, ARRAYSIZE(SFTM_A_VEGA_PALETTE_MASK) },
};

const sDescTreeNode SFTM_A_HONDA_COLLECTION[] =
{
    { L"P1", DESC_NODETYPE_TREE, (void*)SFTM_A_HONDA_PALETTE_P1, ARRAYSIZE(SFTM_A_HONDA_PALETTE_P1) },
    { L"P2", DESC_NODETYPE_TREE, (void*)SFTM_A_HONDA_PALETTE_P2, ARRAYSIZE(SFTM_A_HONDA_PALETTE_P2) },
};

const sDescTreeNode SFTM_A_ZANGIEF_COLLECTION[] =
{
    { L"P1", DESC_NODETYPE_TREE, (void*)SFTM_A_ZANGIEF_PALETTE_P1, ARRAYSIZE(SFTM_A_ZANGIEF_PALETTE_P1) },
    { L"P2", DESC_NODETYPE_TREE, (void*)SFTM_A_ZANGIEF_PALETTE_P2, ARRAYSIZE(SFTM_A_ZANGIEF_PALETTE_P2) },
};

const sDescTreeNode SFTM_A_BISON_COLLECTION[] =
{
    { L"P1", DESC_NODETYPE_TREE, (void*)SFTM_A_BISON_PALETTE_P1, ARRAYSIZE(SFTM_A_BISON_PALETTE_P1) },
    { L"P2", DESC_NODETYPE_TREE, (void*)SFTM_A_BISON_PALETTE_P2, ARRAYSIZE(SFTM_A_BISON_PALETTE_P2) },
    { L"Super", DESC_NODETYPE_TREE, (void*)SFTM_A_BISON_PALETTE_SUPER, ARRAYSIZE(SFTM_A_BISON_PALETTE_SUPER) },
};

const sDescTreeNode SFTM_A_CAMMY_COLLECTION[] =
{
    { L"P1", DESC_NODETYPE_TREE, (void*)SFTM_A_CAMMY_PALETTE_P1, ARRAYSIZE(SFTM_A_CAMMY_PALETTE_P1) },
    { L"P2", DESC_NODETYPE_TREE, (void*)SFTM_A_CAMMY_PALETTE_P2, ARRAYSIZE(SFTM_A_CAMMY_PALETTE_P2) },
};

const sDescTreeNode SFTM_A_BALROG_COLLECTION[] =
{
    { L"P1", DESC_NODETYPE_TREE, (void*)SFTM_A_BALROG_PALETTE_P1, ARRAYSIZE(SFTM_A_BALROG_PALETTE_P1) },
    { L"P2", DESC_NODETYPE_TREE, (void*)SFTM_A_BALROG_PALETTE_P2, ARRAYSIZE(SFTM_A_BALROG_PALETTE_P2) },
};

const sDescTreeNode SFTM_A_GUILE_COLLECTION[] =
{
    { L"P1", DESC_NODETYPE_TREE, (void*)SFTM_A_GUILE_PALETTE_P1, ARRAYSIZE(SFTM_A_GUILE_PALETTE_P1) },
    { L"P2", DESC_NODETYPE_TREE, (void*)SFTM_A_GUILE_PALETTE_P2, ARRAYSIZE(SFTM_A_GUILE_PALETTE_P2) },
};

const sDescTreeNode SFTM_A_AKUMA_COLLECTION[] =
{
    { L"P1", DESC_NODETYPE_TREE, (void*)SFTM_A_AKUMA_PALETTE_P1, ARRAYSIZE(SFTM_A_AKUMA_PALETTE_P1) },
    { L"P2", DESC_NODETYPE_TREE, (void*)SFTM_A_AKUMA_PALETTE_P2, ARRAYSIZE(SFTM_A_AKUMA_PALETTE_P2) },
};

const sDescTreeNode SFTM_A_KEN_COLLECTION[] =
{
    { L"P1", DESC_NODETYPE_TREE, (void*)SFTM_A_KEN_PALETTE_P1, ARRAYSIZE(SFTM_A_KEN_PALETTE_P1) },
    { L"P2", DESC_NODETYPE_TREE, (void*)SFTM_A_KEN_PALETTE_P2, ARRAYSIZE(SFTM_A_KEN_PALETTE_P2) },
};

const sDescTreeNode SFTM_A_CHUNLI_COLLECTION[] =
{
    { L"P1", DESC_NODETYPE_TREE, (void*)SFTM_A_CHUNLI_PALETTE_P1, ARRAYSIZE(SFTM_A_CHUNLI_PALETTE_P1) },
    { L"P2", DESC_NODETYPE_TREE, (void*)SFTM_A_CHUNLI_PALETTE_P2, ARRAYSIZE(SFTM_A_CHUNLI_PALETTE_P2) },
};

const sDescTreeNode SFTM_A_BLADE_COLLECTION[] =
{
    { L"P1", DESC_NODETYPE_TREE, (void*)SFTM_A_BLADE_PALETTE_P1, ARRAYSIZE(SFTM_A_BLADE_PALETTE_P1) },
    { L"P2", DESC_NODETYPE_TREE, (void*)SFTM_A_BLADE_PALETTE_P2, ARRAYSIZE(SFTM_A_BLADE_PALETTE_P2) },
};

const sDescTreeNode SFTM_A_KHYBER_COLLECTION[] =
{
    { L"P1", DESC_NODETYPE_TREE, (void*)SFTM_A_KHYBER_PALETTE_P1, ARRAYSIZE(SFTM_A_KHYBER_PALETTE_P1) },
    { L"P2", DESC_NODETYPE_TREE, (void*)SFTM_A_KHYBER_PALETTE_P2, ARRAYSIZE(SFTM_A_KHYBER_PALETTE_P2) },
};

const sDescTreeNode SFTM_A_ARKANE_COLLECTION[] =
{
    { L"P1", DESC_NODETYPE_TREE, (void*)SFTM_A_ARKANE_PALETTE_P1, ARRAYSIZE(SFTM_A_ARKANE_PALETTE_P1) },
    { L"P2", DESC_NODETYPE_TREE, (void*)SFTM_A_ARKANE_PALETTE_P2, ARRAYSIZE(SFTM_A_ARKANE_PALETTE_P2) },
};

const sDescTreeNode SFTM_A_F7_COLLECTION[] =
{
    { L"P1", DESC_NODETYPE_TREE, (void*)SFTM_A_F7_PALETTE_P1, ARRAYSIZE(SFTM_A_F7_PALETTE_P1) },
    { L"P2", DESC_NODETYPE_TREE, (void*)SFTM_A_F7_PALETTE_P2, ARRAYSIZE(SFTM_A_F7_PALETTE_P2) },
};

const sDescTreeNode SFTM_A_SAWADA_COLLECTION[] =
{
    { L"P1", DESC_NODETYPE_TREE, (void*)SFTM_A_SAWADA_PALETTE_P1, ARRAYSIZE(SFTM_A_SAWADA_PALETTE_P1) },
    { L"P2", DESC_NODETYPE_TREE, (void*)SFTM_A_SAWADA_PALETTE_P2, ARRAYSIZE(SFTM_A_SAWADA_PALETTE_P2) },
};

const sDescTreeNode SFTM_A_SAGAT_COLLECTION[] =
{
    { L"P1", DESC_NODETYPE_TREE, (void*)SFTM_A_SAGAT_PALETTE_P1, ARRAYSIZE(SFTM_A_SAGAT_PALETTE_P1) },
    { L"P2", DESC_NODETYPE_TREE, (void*)SFTM_A_SAGAT_PALETTE_P2, ARRAYSIZE(SFTM_A_SAGAT_PALETTE_P2) },
};

const sDescTreeNode SFTM_A_UNITS[] =
{
    { L"Sagat", DESC_NODETYPE_TREE, (void*)SFTM_A_SAGAT_COLLECTION, ARRAYSIZE(SFTM_A_SAGAT_COLLECTION) },
    { L"Ryu", DESC_NODETYPE_TREE, (void*)SFTM_A_RYU_COLLECTION, ARRAYSIZE(SFTM_A_RYU_COLLECTION) },
    { L"Vega", DESC_NODETYPE_TREE, (void*)SFTM_A_VEGA_COLLECTION, ARRAYSIZE(SFTM_A_VEGA_COLLECTION) },
    { L"E. Honda", DESC_NODETYPE_TREE, (void*)SFTM_A_HONDA_COLLECTION, ARRAYSIZE(SFTM_A_HONDA_COLLECTION) },
    { L"Zangief", DESC_NODETYPE_TREE, (void*)SFTM_A_ZANGIEF_COLLECTION, ARRAYSIZE(SFTM_A_ZANGIEF_COLLECTION) },
    { L"M. Bison", DESC_NODETYPE_TREE, (void*)SFTM_A_BISON_COLLECTION, ARRAYSIZE(SFTM_A_BISON_COLLECTION) },
    { L"Cammy", DESC_NODETYPE_TREE, (void*)SFTM_A_CAMMY_COLLECTION, ARRAYSIZE(SFTM_A_CAMMY_COLLECTION) },
    { L"Balrog", DESC_NODETYPE_TREE, (void*)SFTM_A_BALROG_COLLECTION, ARRAYSIZE(SFTM_A_BALROG_COLLECTION) },
    { L"Guile", DESC_NODETYPE_TREE, (void*)SFTM_A_GUILE_COLLECTION, ARRAYSIZE(SFTM_A_GUILE_COLLECTION) },
    { L"Akuma", DESC_NODETYPE_TREE, (void*)SFTM_A_AKUMA_COLLECTION, ARRAYSIZE(SFTM_A_AKUMA_COLLECTION) },
    { L"Ken", DESC_NODETYPE_TREE, (void*)SFTM_A_KEN_COLLECTION, ARRAYSIZE(SFTM_A_KEN_COLLECTION) },
    { L"Chun-Li", DESC_NODETYPE_TREE, (void*)SFTM_A_CHUNLI_COLLECTION, ARRAYSIZE(SFTM_A_CHUNLI_COLLECTION) },
    { L"Blade", DESC_NODETYPE_TREE, (void*)SFTM_A_BLADE_COLLECTION, ARRAYSIZE(SFTM_A_BLADE_COLLECTION) },
    { L"Khyber", DESC_NODETYPE_TREE, (void*)SFTM_A_KHYBER_COLLECTION, ARRAYSIZE(SFTM_A_KHYBER_COLLECTION) },
    { L"Arkane", DESC_NODETYPE_TREE, (void*)SFTM_A_ARKANE_COLLECTION, ARRAYSIZE(SFTM_A_ARKANE_COLLECTION) },
    { L"F7", DESC_NODETYPE_TREE, (void*)SFTM_A_F7_COLLECTION, ARRAYSIZE(SFTM_A_F7_COLLECTION) },
    { L"Sawada", DESC_NODETYPE_TREE, (void*)SFTM_A_SAWADA_COLLECTION, ARRAYSIZE(SFTM_A_SAWADA_COLLECTION) },
};
