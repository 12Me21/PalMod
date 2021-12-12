#include "StdAfx.h"
#include "GameDef.h"
#include "Game_MVC2_A.h"
#include "Game_MVC2_D.h"
#include "mvc2_descs.h"
#include "mvc2_supp.h"
#include "..\PalMod.h"
#include "..\RegProc.h"

#define MVC2_A_DEBUG DEFAULT_GAME_DEBUG_STATE

stExtraDef* CGame_MVC2_A::MVC2_A_EXTRA_CUSTOM = nullptr;

CDescTree CGame_MVC2_A::MainDescTree = nullptr;

size_t CGame_MVC2_A::rgExtraCountAll[MVC2_A_NUMUNIT + 1];
size_t CGame_MVC2_A::rgExtraLoc[MVC2_A_NUMUNIT + 1];

UINT32 CGame_MVC2_A::m_nTotalPaletteCountForMVC2 = 0;
UINT32 CGame_MVC2_A::m_nExpectedGameROMSize = 0x889B600; // 143,242,752 bytes
UINT32 CGame_MVC2_A::m_nConfirmedROMSize = -1;

void CGame_MVC2_A::InitializeStatics()
{
    safe_delete_array(CGame_MVC2_A::MVC2_A_EXTRA_CUSTOM);

    memset(rgExtraCountAll, -1, sizeof(rgExtraCountAll));
    memset(rgExtraLoc, -1, sizeof(rgExtraLoc));

    MainDescTree.SetRootTree(CGame_MVC2_A::InitDescTree());
}

CGame_MVC2_A::CGame_MVC2_A(UINT32 nConfirmedROMSize)
{
    OutputDebugString(L"CGame_MVC2_A::CGame_MVC2_A: Loading ROM...\n");

    //Set color mode
    createPalOptions = { NO_SPECIAL_OPTIONS, WRITE_MAX };
    SetAlphaMode(AlphaMode::GameUsesVariableAlpha);
    SetColorMode(ColMode::COLMODE_RGB444_BE);

    // We need this set before we initialize so that corrupt Extras truncate correctly.
    // Otherwise the new user inadvertently corrupts their ROM.
    m_nConfirmedROMSize = nConfirmedROMSize;
    InitializeStatics();

    m_nTotalInternalUnits = MVC2_A_NUMUNIT;
    m_nExtraUnit = MVC2_A_EXTRALOC;

    m_nSafeCountForThisRom = GetExtraCt(m_nExtraUnit) + 6370;
    m_pszExtraFilename = EXTRA_FILENAME_MVC2_A;
    m_nTotalPaletteCount = m_nTotalPaletteCountForMVC2;
    // This magic number is used to warn users if their Extra file is trying to write somewhere potentially unusual
    m_nLowestKnownPaletteRomLocation = 0x260a9c0;

    nUnitAmt = m_nTotalInternalUnits + (GetExtraCt(m_nExtraUnit) ? 1 : 0);

    InitDataBuffer();

    //Set game information
    nGameFlag = MVC2_A;
    nImgGameFlag = IMGDAT_SECTION_CPS2;
    m_prgGameImageSet = MVC2_IMGIDS_USED;

    m_fGameUsesAlphaValue = true;

    nFileAmt = 1;

    //Set the image out display type
    DisplayType = eImageOutputSpriteDisplay::DISPLAY_SPRITES_TOPTOBOTTOM;
    pButtonLabelSet = DEF_BUTTONLABEL6_MVC2;

    //Set the MVC2 supp game
    CurrMVC2 = (CGame_MVC2_D*)this;
    CurrMVC2_Arcade = this;
    //Prepare it
    prep_supp(false);

    //Create the redirect buffer
    rgUnitRedir = new size_t[nUnitAmt + 1];
    memset(rgUnitRedir, NULL, sizeof(size_t) * nUnitAmt);

    //Create the file changed flag
    PrepChangeTrackingArray();
}

CGame_MVC2_A::~CGame_MVC2_A(void)
{
    safe_delete_array(CGame_MVC2_A::MVC2_A_EXTRA_CUSTOM);
    ClearDataBuffer();
    //Get rid of the file changed flag
    FlushChangeTrackingArray();

    CurrMVC2 = nullptr;
    CurrMVC2_Arcade = nullptr;
}

CDescTree* CGame_MVC2_A::GetMainTree()
{
    return &CGame_MVC2_A::MainDescTree;
}

size_t CGame_MVC2_A::GetExtraCt(size_t nUnitId, BOOL bCountVisibleOnly)
{
    return _GetExtraCount(rgExtraCountAll, MVC2_A_NUMUNIT, nUnitId, MVC2_A_EXTRA_CUSTOM);
}

size_t CGame_MVC2_A::GetExtraLoc(size_t nUnitId)
{
    return _GetExtraLocation(rgExtraLoc, MVC2_A_NUMUNIT, nUnitId, MVC2_A_EXTRA_CUSTOM);
}

struct sMVC2A_CharacterData
{
    WCHAR szImageRefName[MAX_DESCRIPTION_LENGTH] = L"uninit";
    UINT16 nCharacterIndex = 0;
    WCHAR szDesc[MAX_DESCRIPTION_LENGTH] = L"uninit";
    WCHAR szCodeDesc[MAX_DESCRIPTION_LENGTH] = L"UNINIT";
    UINT32 nStartingPosition = 0;
    UINT16 nExtraStart = 0;
    UINT16 nExtraEnd = 0;
    LPCWSTR pszPalettePairName = nullptr;
};

sMVC2A_CharacterData MVC2ArcadeCharacterArray[] =
{
    { L"indexCPS2Sprites_Ryu", 0x00, L"Ryu", L"RYU", 0x260a9c2, 0, 0 },
    { L"indexCPS2Sprites_Zangief", 0x01, L"Zangief", L"ZANGIEF", 0x26E2242, 0x11, 0x3a},
    { L"indexCPS2Sprites_Guile", 0x02, L"Guile", L"GUILE", 0x2775162, 0, 0 },
    { L"indexCPS2Sprites_Morrigan", 0x03, L"Morrigan", L"MORRIGAN", 0x283a362, 0x3a, 0x86 },
    { L"indexCPS2Sprites_Anakaris", 0x04, L"Anakaris", L"ANAKARIS", 0x2954602, 0, 0 },
    { L"indexCPS2Sprites_Strider", 0x05, L"Strider Hiryu", L"STRIDER", 0x2A2c5E2, 0, 0},
    { L"indexCPS2Sprites_Cyclops", 0x06, L"Cyclops", L"CYCLOPS", 0x2B13442, 0x19, 0x64},
    // don't forget to join the claws!
    { L"indexCPS2Sprites_Wolverine", 0x07, L"Wolverine", L"WOLVERINE", 0x2C0eba2, 0x11, 0x11, L"pairNext" },
    { L"indexCPS2Sprites_Psylocke", 0x08, L"Psylocke", L"PSYLOCKE", 0x2D104E2, 0, 0 },
    { L"indexCPS2Sprites_Iceman", 0x09, L"Iceman", L"ICEMAN", 0x2DFB5C2, 0x9, 0x4a},
    { L"indexCPS2Sprites_Rogue", 0x0A, L"Rogue", L"ROGUE", 0x2EE2142 , 0x1d, 0x22},
    { L"indexCPS2Sprites_CapAm", 0x0B, L"Captain America", L"CAPTAINAMERICA", 0x2FD03E2, 0, 0, L"pairNext" },
    { L"indexCPS2Sprites_Spidey", 0x0C, L"Spider-Man", L"SPIDERMAN", 0x30Ae9C2, 0x9, 0x64},
    { L"indexCPS2Sprites_Hulk", 0x0D, L"Hulk,", L"HULK", 0x31C9402, 0xa, 0xa },
    { L"indexCPS2Sprites_Venom", 0x0E, L"Venom", L"VENOM", 0x32Ed122 , 0, 0},
    { L"indexCPS2Sprites_DrDoom", 0x0F, L"Dr. Doom", L"DRDOOM", 0x33ffa42 , 0x9, 0x98 },
    { L"indexCPS2Sprites_Tron", 0x10, L"Tron Bonne", L"TRON", 0x35175c2 , 0x11, 0x15, L"pairNext" },
    { L"indexCPS2Sprites_Jill", 0x11, L"Jill Valentine", L"JILL", 0x35f3162 , 0x9, 0xb },
    { L"indexCPS2Sprites_Hayato", 0x12, L"Hayato", L"HAYATO", 0x36f0742, 0x14, 0x17, L"pairHayatoSword" },
    { L"indexCPS2Sprites_Ruby", 0x13, L"Ruby Heart", L"RUBY", 0x37f9ce2 , 0xb, 0x10 },
    { L"indexCPS2Sprites_SonSon", 0x14, L"SonSon", L"SONSON", 0x39136C2 , 0xb, 0x28 },
    { L"indexCPS2Sprites_Amingo", 0x15, L"Amingo", L"AMINGO", 0x3A2c762 , 0x9, 0xb },
    { L"indexCPS2Sprites_Marrow", 0x16, L"Marrow", L"MARROW", 0x3B214a2 , 0, 0 },
    { L"indexCPS2Sprites_Cable", 0x17, L"Cable", L"CABLE", 0x3c2d5a2, 0, 0 },
    { L"indexCPS2Sprites_Abyss1", 0x18, L"Abyss (Form 1)", L"ABYSS1", 0x3D19482, 0, 0 },
    { L"indexCPS2Sprites_Abyss2", 0x19, L"Abyss (Form 2)", L"ABYSS2", 0x3Da68e2, 0, 0 },
    { L"indexCPS2Sprites_Abyss3", 0x1A, L"Abyss (Form 3)", L"ABYSS3", 0x3E80562, 0, 0 },
    { L"indexCPS2Sprites_ChunLi", 0x1B, L"Chun-Li", L"CHUNLI", 0x3F00962, 0, 0 },
    { L"indexCPS2Sprites_Megaman", 0x1C, L"Megaman", L"MEGAMAN", 0x3F93962, 0x9, 0x211 },
    { L"indexCPS2Sprites_Roll", 0x1D, L"Roll", L"ROLL", 0x4007742, 0x9, 0x211 },
    { L"indexCPS2Sprites_Akuma", 0x1E, L"Gouki", L"GOUKI", 0x4090ce2, 0, 0 },
    { L"indexCPS2Sprites_BBHood", 0x1F, L"B.B. Hood", L"BBHOOD", 0x41Aae62, 0xc, 0x14 },
    { L"indexCPS2Sprites_Felicia", 0x20, L"Felicia", L"FELICIA", 0x42D2082, 0, 0 },
    { L"indexCPS2Sprites_Charlie", 0x21, L"Charlie", L"CHARLIE", 0x433f102, 0, 0 },
    { L"indexCPS2Sprites_Sakura", 0x22, L"Sakura", L"SAKURA", 0x4405b62, 0xb, 0x22 },
    { L"indexCPS2Sprites_Dan", 0x23, L"Dan", L"DAN", 0x44540C2, 0, 0 },
    { L"indexCPS2Sprites_Cammy", 0x24, L"Cammy", L"CAMMY", 0x44f3b82, 0x9, 0x3e},
    { L"indexCPS2Sprites_Dhalsim", 0x25, L"Dhalsim", L"DHALSIM", 0x45AA822, 0x9, 0x26 },
    { L"indexCPS2Sprites_Bison", 0x26, L"M.Bison", L"MBISON", 0x462f342, 0x9, 0x14 },
    { L"indexCPS2Sprites_Ken", 0x27, L"Ken", L"KEN", 0x46B5662, 0, 0 },
    { L"indexCPS2Sprites_Gambit", 0x28, L"Gambit", L"GAMBIT", 0x479ec82, 0x9, 0x26 },
    { L"indexCPS2Sprites_Juggy", 0x29, L"Juggernaut", L"JUGGERNAUT", 0x48Cb762, 0x9, 0x44 },
    { L"indexCPS2Sprites_Storm", 0x2A, L"Storm", L"STORM", 0x49d9e82, 0x9, 0x2a },
    { L"indexCPS2Sprites_Sabretooth", 0x2B, L"Sabretooth", L"SABRETOOTH", 0x4ADb362, 0, 0 },
    { L"indexCPS2Sprites_Magneto", 0x2C, L"Magneto", L"MAGNETO", 0x4BF21c2, 0xa, 0xa },
    // This is actually a joint palette but it's incorrectly ripped.  We do need the
    // two step effects palettes but all the character joins can be ignored or excised.
    { L"indexCPS2Sprites_Shuma", 0x2D, L"Shuma-Gorath", L"SHUMA", 0x4CDa622, 0x11, 0x130, L"pairUnhandled" },
    { L"indexCPS2Sprites_WarMachine", 0x2E, L"War Machine", L"WARMACHINE", 0x4Ddab82, 0, 0 },
    { L"indexCPS2Sprites_SilverSamurai", 0x2F, L"Silver Samurai", L"SILVERSAMURAI", 0x4EF6122, 0x9, 0x37},
    { L"indexCPS2Sprites_OmegaRed", 0x30, L"Omega Red", L"OMEGARED", 0x4ff4942, 0x9, 0x20 },
    { L"indexCPS2Sprites_Spiral", 0x31, L"Spiral", L"SPIRAL", 0x5109fa2, 0x9, 0xd2},
    { L"indexCPS2Sprites_Colossus", 0x32, L"Colossus", L"COLOSSUS", 0x5235a62, 0x9, 0xc8},
    { L"indexCPS2Sprites_IronMan", 0x33, L"Iron Man", L"IRONMAN", 0x53384c2, 0, 0 },
    { L"indexCPS2Sprites_Sentinel", 0x34, L"Sentinel", L"SENTINEL", 0x545E422, 0x12, 0x13, L"pairHandledInCode" },
    { L"indexCPS2Sprites_Blackheart", 0x35, L"Blackheart", L"BLACKHEART", 0x5585402, 0x9, 0x1b },
    { L"indexCPS2Sprites_Thanos", 0x36, L"Thanos", L"THANOS", 0x5673e42, 0x9, 0x1f },
    { L"indexCPS2Sprites_Jin", 0x37, L"Jin", L"JIN", 0x5758482, 0x9, 0x86 },
    { L"indexCPS2Sprites_CapCom", 0x38, L"Captain Commando", L"CAPTAINCOMMANDO", 0x5847ec2 , 0x9, 0x19},
    { L"indexCPS2Sprites_Bonerine", 0x39, L"Bonerine", L"BONERINE", 0x59472a2, 0, 0, L"pairNext" },
    { L"indexCPS2Sprites_Kobun", 0x3A, L"Kobun", L"KOBUN", 0x59acdc2, 0x9, 0x26 },
};

void CGame_MVC2_A::DumpAllCharacters()
{
    //Go through each character
    for (UINT16 iUnitCtr = 0; iUnitCtr < ARRAYSIZE(MVC2ArcadeCharacterArray); iUnitCtr++)
    {
        if (MVC2ArcadeCharacterArray[iUnitCtr].nStartingPosition != 0)
        {
            const sMoveDescription* sCurrentMoveDescriptors = MVC2_6COLOR_MOVE_DESCRIPTIONS[iUnitCtr].data();
            const UINT32 nMoveDescriptorCount = MVC2_6COLOR_MOVE_DESCRIPTIONS[iUnitCtr].size();

            UINT32 nCurrentCharacterOffset = MVC2ArcadeCharacterArray[iUnitCtr].nStartingPosition;
            UINT16 nPaletteCount = 0;
            CString strOutput;

            for (UINT16 iButtonIndex = 0; iButtonIndex < pButtonLabelSet.size(); iButtonIndex++)
            {
                strOutput.Format(L"const sGame_PaletteDataset MVC2_A_%s_PALETTES_%s[] =\r\n{\r\n", MVC2ArcadeCharacterArray[iUnitCtr].szCodeDesc, (LPCWSTR)pButtonLabelSet[iButtonIndex]);
                OutputDebugString(strOutput);

                if (MVC2ArcadeCharacterArray[iUnitCtr].pszPalettePairName) 
                {
                    strOutput.Format(L"    { \"%s %s\", 0x%07x, 0x%7x, %s, 0, &%s },\r\n", sCurrentMoveDescriptors[0].szMoveName, pButtonLabelSet[iButtonIndex],
                                                                                        nCurrentCharacterOffset, nCurrentCharacterOffset + 0x20,
                                                                                        MVC2ArcadeCharacterArray[iUnitCtr].szImageRefName, MVC2ArcadeCharacterArray[iUnitCtr].pszPalettePairName);
                }
                else
                {
                    strOutput.Format(L"    { \"%s %s\", 0x%07x, 0x%7x, %s, 0 },\r\n", sCurrentMoveDescriptors[0].szMoveName, pButtonLabelSet[iButtonIndex],
                                                                                    nCurrentCharacterOffset, nCurrentCharacterOffset + 0x20,
                                                                                    MVC2ArcadeCharacterArray[iUnitCtr].szImageRefName );
                }
                OutputDebugString(strOutput);
                nCurrentCharacterOffset += 0x20;
                nPaletteCount++;

                for (UINT16 iCurrentExtra = 1; iCurrentExtra < 8; iCurrentExtra++)
                {
                    if (sCurrentMoveDescriptors[iCurrentExtra].nImageIndex != 0xFF)
                    {
                        if ((sCurrentMoveDescriptors[iCurrentExtra].pszPairedPaletteName != nullptr) && (sCurrentMoveDescriptors[iCurrentExtra].pszImageUnitOverride != nullptr))
                        {
                            strOutput.Format(L"    { \"%s\", 0x%07x, 0x%7x, %s, %u, %s },\r\n", sCurrentMoveDescriptors[iCurrentExtra].szMoveName, nCurrentCharacterOffset, nCurrentCharacterOffset + 0x20, sCurrentMoveDescriptors[iCurrentExtra].pszImageUnitOverride, 
                                                                                                   sCurrentMoveDescriptors[iCurrentExtra].nImageIndex, sCurrentMoveDescriptors[iCurrentExtra].pszPairedPaletteName);
                        }
                        else if (sCurrentMoveDescriptors[iCurrentExtra].pszImageUnitOverride != nullptr)
                        {
                            strOutput.Format(L"    { \"%s\", 0x%07x, 0x%7x, %s, %u },\r\n", sCurrentMoveDescriptors[iCurrentExtra].szMoveName, nCurrentCharacterOffset, nCurrentCharacterOffset + 0x20, sCurrentMoveDescriptors[iCurrentExtra].pszImageUnitOverride, sCurrentMoveDescriptors[iCurrentExtra].nImageIndex);
                        }
                        else
                        {
                            strOutput.Format(L"    { \"%s\", 0x%07x, 0x%7x, %s, %u },\r\n", sCurrentMoveDescriptors[iCurrentExtra].szMoveName, nCurrentCharacterOffset, nCurrentCharacterOffset + 0x20, MVC2ArcadeCharacterArray[iUnitCtr].szImageRefName, sCurrentMoveDescriptors[iCurrentExtra].nImageIndex);
                        }
                    }
                    else
                    {
                        //strOutput.Format(L"    { \"%02u %s (Extra - %02x)\", 0x%07x, 0x%7x, %s, %u },\r\n", iCurrentExtra + 1, pButtonLabel[iButtonIndex], nPaletteCount, nCurrentCharacterOffset, nCurrentCharacterOffset + 0x20, MVC2ArcadeCharacterArray[iUnitCtr].szImageRefName, iCurrentExtra + 1 );
                        strOutput.Format(L"    { \"%s\", 0x%07x, 0x%7x, %s, %u },\r\n", sCurrentMoveDescriptors[iCurrentExtra].szMoveName, nCurrentCharacterOffset, nCurrentCharacterOffset + 0x20, MVC2ArcadeCharacterArray[iUnitCtr].szImageRefName, iCurrentExtra);
                    }
                    OutputDebugString(strOutput);
                    nCurrentCharacterOffset += 0x20;
                    nPaletteCount++;
                }

                OutputDebugString(L"};\r\n\r\n");
            }

            // Status effects...
            strOutput.Format(L"const sGame_PaletteDataset MVC2_A_%s_PALETTES_SHARED[] =\r\n{\r\n", MVC2ArcadeCharacterArray[iUnitCtr].szCodeDesc);
            OutputDebugString(strOutput);

            const WCHAR* StatusDescriptions[8] =
            {
                L"Burning Dark", L"Burning Light", L"Shocked Dark", L"Shocked Light", L"Dark Burning Dark", L"Dark Burning Light", L"Kinetic Charge Dark", L"Kinetic Charge Light"
            };

            for (UINT16 iStatusEffect = 0; iStatusEffect < 8; iStatusEffect++)
            {
                // Use this for people with two body pieces
                if (MVC2ArcadeCharacterArray[iUnitCtr].pszPalettePairName)
                {
                    strOutput.Format(L"    { \"%s\", 0x%07x, 0x%7x, %s, %u, &%s },\r\n", StatusDescriptions[iStatusEffect], nCurrentCharacterOffset, nCurrentCharacterOffset + 0x20, MVC2ArcadeCharacterArray[iUnitCtr].szImageRefName, 0,
                                                                                        MVC2ArcadeCharacterArray[iUnitCtr].pszPalettePairName);
                    OutputDebugString(strOutput);
                    nCurrentCharacterOffset += 0x20;
                    strOutput.Format(L"    { \"%s 2\", 0x%07x, 0x%7x, %s, %u },\r\n", StatusDescriptions[iStatusEffect], nCurrentCharacterOffset, nCurrentCharacterOffset + 0x20, MVC2ArcadeCharacterArray[iUnitCtr].szImageRefName, 1);
                    OutputDebugString(strOutput);
                    nCurrentCharacterOffset += 0x20;
                }
                else
                {
                    strOutput.Format(L"    { \"%s\", 0x%07x, 0x%7x, %s, %u },\r\n", StatusDescriptions[iStatusEffect], nCurrentCharacterOffset, nCurrentCharacterOffset + 0x20, MVC2ArcadeCharacterArray[iUnitCtr].szImageRefName, 0);
                    OutputDebugString(strOutput);
                    nCurrentCharacterOffset += 0x20;
                }
            }

            OutputDebugString(L"};\r\n\r\n");

            // Dump the extras if we have any...
            if (MVC2ArcadeCharacterArray[iUnitCtr].nExtraStart != 0)
            {
                strOutput.Format(L"const sGame_PaletteDataset MVC2_A_%s_PALETTES_EXTRAS[] =\r\n{\r\n", MVC2ArcadeCharacterArray[iUnitCtr].szCodeDesc);
                OutputDebugString(strOutput);
                const UINT16 nExtraStart = MVC2ArcadeCharacterArray[iUnitCtr].pszPalettePairName ? (8 + 0x9) : 0x9;

                for (UINT16 iExtraPosition = nExtraStart; iExtraPosition <= MVC2ArcadeCharacterArray[iUnitCtr].nExtraEnd; iExtraPosition++)
                {
                    const sMoveDescription* sExtraDescription = nullptr;

                    for (UINT32 iDescriptionIndex = 8; iDescriptionIndex < nMoveDescriptorCount; iDescriptionIndex++)
                    {
                        if (sCurrentMoveDescriptors[iDescriptionIndex].nCharacterIndex == iExtraPosition)
                        {
                            sExtraDescription = &sCurrentMoveDescriptors[iDescriptionIndex];
                            break;
                        }
                        else if (sCurrentMoveDescriptors[iDescriptionIndex].nCharacterIndex > iExtraPosition)
                        {
                            // We've passed beyond the range of interest
                            break;
                        }
                    }

                    strOutput.Format(L"    { \"%02x: ", iExtraPosition);
                    OutputDebugString(strOutput);

                    if (sExtraDescription)
                    {
                        if (sExtraDescription->nImageIndex != 0xFF)
                        {
                            if ((sExtraDescription->pszPairedPaletteName != nullptr) && (sExtraDescription->pszImageUnitOverride != nullptr))
                            {
                                strOutput.Format(L"%s\", 0x%07x, 0x%7x, %s, %u, %s },\r\n", sExtraDescription->szMoveName, nCurrentCharacterOffset, nCurrentCharacterOffset + 0x20, sExtraDescription->pszImageUnitOverride,
                                                                                                       sExtraDescription->nImageIndex, sExtraDescription->pszPairedPaletteName);
                            }
                            else if (sExtraDescription->pszImageUnitOverride != nullptr)
                            {
                                strOutput.Format(L"%s\", 0x%07x, 0x%7x, %s, %u },\r\n", sExtraDescription->szMoveName, nCurrentCharacterOffset, nCurrentCharacterOffset + 0x20, sExtraDescription->pszImageUnitOverride, sExtraDescription->nImageIndex);
                            }
                            else
                            {
                                strOutput.Format(L"%s\", 0x%07x, 0x%7x, %s, %u },\r\n", sExtraDescription->szMoveName, nCurrentCharacterOffset, nCurrentCharacterOffset + 0x20, MVC2ArcadeCharacterArray[iUnitCtr].szImageRefName, sExtraDescription->nImageIndex);
                            }
                            OutputDebugString(strOutput);
                        }
                        else
                        {
                            // Note that this adds "Not Used" values because we need everything for Extras math.
                            strOutput.Format(L"%s\", 0x%07x, 0x%7x },\r\n", sExtraDescription->szMoveName, nCurrentCharacterOffset, nCurrentCharacterOffset + 0x20);
                            OutputDebugString(strOutput);
                        }
                    }
                    else
                    {
                        // We need everything in the layout for Extras math to work.
                        strOutput.Format(L"Unused Extra\", 0x%07x, 0x%7x },\r\n", nCurrentCharacterOffset, nCurrentCharacterOffset + 0x20 );
                        OutputDebugString(strOutput);
                    }

                    nCurrentCharacterOffset += 0x20;
                }

                OutputDebugString(L"};\r\n\r\n");
            }

            // Now create the collection...
            strOutput.Format(L"const sDescTreeNode MVC2_A_%s_COLLECTION[] =\r\n{\r\n", MVC2ArcadeCharacterArray[iUnitCtr].szCodeDesc);
            OutputDebugString(strOutput);

            for (UINT16 iButtonIndex = 0; iButtonIndex < pButtonLabelSet.size(); iButtonIndex++)
            {
                strOutput.Format(L"    { \"%s\", DESC_NODETYPE_TREE, (void*)MVC2_A_%s_PALETTES_%s, ARRAYSIZE(MVC2_A_%s_PALETTES_%s) },\r\n", pButtonLabelSet[iButtonIndex], MVC2ArcadeCharacterArray[iUnitCtr].szCodeDesc, DEF_BUTTONLABEL6_MVC2[iButtonIndex],
                                            MVC2ArcadeCharacterArray[iUnitCtr].szCodeDesc, pButtonLabelSet[iButtonIndex] );
                OutputDebugString(strOutput);
            }

            // These are the 7th set in the ROM layout, so either leave these here or adjust the Extra offsets.
            strOutput.Format(L"    { \"Status Effects\", DESC_NODETYPE_TREE, (void*)MVC2_A_%s_PALETTES_SHARED, ARRAYSIZE(MVC2_A_%s_PALETTES_SHARED) },\r\n", MVC2ArcadeCharacterArray[iUnitCtr].szCodeDesc, MVC2ArcadeCharacterArray[iUnitCtr].szCodeDesc);
            OutputDebugString(strOutput);

            if (MVC2ArcadeCharacterArray[iUnitCtr].nExtraStart != 0)
            {
                strOutput.Format(L"    { \"Extras\", DESC_NODETYPE_TREE, (void*)MVC2_A_%s_PALETTES_EXTRAS, ARRAYSIZE(MVC2_A_%s_PALETTES_EXTRAS) },\r\n", MVC2ArcadeCharacterArray[iUnitCtr].szCodeDesc, MVC2ArcadeCharacterArray[iUnitCtr].szCodeDesc);
                OutputDebugString(strOutput);
            }

            OutputDebugString(L"};\r\n\r\n");
        }
    }
}

sDescTreeNode* CGame_MVC2_A::InitDescTree()
{
    UINT32 nTotalPaletteCount = 0;

    //Load extra file if we're using it
    LoadExtraFileForGame(EXTRA_FILENAME_MVC2_A, MVC2_A_EXTRA, &MVC2_A_EXTRA_CUSTOM, MVC2_A_EXTRALOC, m_nConfirmedROMSize);

    UINT16 nUnitCt = MVC2_A_NUMUNIT + (GetExtraCt(MVC2_A_EXTRALOC) ? 1 : 0);
    
    sDescTreeNode* NewDescTree = new sDescTreeNode;

    //Create the main character tree
    _snwprintf_s(NewDescTree->szDesc, ARRAYSIZE(NewDescTree->szDesc), _TRUNCATE, L"%s", g_GameFriendlyName[MVC2_A]);
    NewDescTree->ChildNodes = new sDescTreeNode[nUnitCt];
    NewDescTree->uChildAmt = nUnitCt;
    //All units have tree children
    NewDescTree->uChildType = DESC_NODETYPE_TREE;

    m_nTotalPaletteCountForMVC2 = _InitDescTree(NewDescTree,
        MVC2_A_UNITS,
        MVC2_A_EXTRALOC,
        MVC2_A_NUMUNIT,
        rgExtraCountAll,
        rgExtraLoc,
        MVC2_A_EXTRA_CUSTOM
    );;

    // For development use to speed things up
    //DumpAllCharacters();

    return NewDescTree;
}

sFileRule CGame_MVC2_A::GetRule(size_t nUnitId)
{
    sFileRule NewFileRule;

    // This value is only used for directory-based games
    _snwprintf_s(NewFileRule.szFileName, ARRAYSIZE(NewFileRule.szFileName), _TRUNCATE, L"Marvel vs. Capcom 2.dat");

    NewFileRule.uUnitId = 0;
    NewFileRule.uVerifyVar = m_nExpectedGameROMSize;

    return NewFileRule;
}

size_t CGame_MVC2_A::GetCollectionCountForUnit(size_t nUnitId)
{
    if (nUnitId == MVC2_A_EXTRALOC)
    {
        return GetExtraCt(nUnitId);
    }
    else
    {
        return MVC2_A_UNITS[nUnitId].uChildAmt;
    }
}

size_t CGame_MVC2_A::GetNodeCountForCollection(size_t nUnitId, size_t nCollectionId)
{
    return _GetNodeCountForCollection(MVC2_A_UNITS, rgExtraCountAll, MVC2_A_NUMUNIT, MVC2_A_EXTRALOC, nUnitId, nCollectionId, MVC2_A_EXTRA_CUSTOM);
}

LPCWSTR CGame_MVC2_A::GetDescriptionForCollection(size_t nUnitId, size_t nCollectionId)
{
    return _GetDescriptionForCollection(MVC2_A_UNITS, MVC2_A_EXTRALOC, nUnitId, nCollectionId);
}

size_t CGame_MVC2_A::GetPaletteCountForUnit(size_t nUnitId)
{
    return _GetPaletteCountForUnit(MVC2_A_UNITS, rgExtraCountAll, MVC2_A_NUMUNIT, MVC2_A_EXTRALOC, nUnitId, MVC2_A_EXTRA_CUSTOM);
}

const sGame_PaletteDataset* CGame_MVC2_A::GetPaletteSet(size_t nUnitId, size_t nCollectionId)
{
    return _GetPaletteSet(MVC2_A_UNITS, nUnitId, nCollectionId);
}

size_t CGame_MVC2_A::GetNodeSizeFromPaletteId(size_t nUnitId, size_t nPaletteId)
{
    // Don't use this for Extra palettes.
    size_t nNodeSize = 0;
    size_t nTotalCollections = GetCollectionCountForUnit(nUnitId);
    const sGame_PaletteDataset* paletteSetToUse = nullptr;
    size_t nDistanceFromZero = nPaletteId;

    for (size_t nCollectionIndex = 0; nCollectionIndex < nTotalCollections; nCollectionIndex++)
    {
        const sGame_PaletteDataset* paletteSetToCheck = GetPaletteSet(nUnitId, nCollectionIndex);
        size_t nNodeCount = GetNodeCountForCollection(nUnitId, nCollectionIndex);

        if (nDistanceFromZero < nNodeCount)
        {
            nNodeSize = nNodeCount;
            break;
        }

        nDistanceFromZero -= nNodeCount;
    }

    return nNodeSize;
}

const sDescTreeNode* CGame_MVC2_A::GetNodeFromPaletteId(size_t nUnitId, size_t nPaletteId, bool fReturnBasicNodesOnly)
{
    return _GetNodeFromPaletteId(MVC2_A_UNITS, rgExtraCountAll, MVC2_A_NUMUNIT, MVC2_A_EXTRALOC, nUnitId, nPaletteId, MVC2_A_EXTRA_CUSTOM, fReturnBasicNodesOnly);
}

const sGame_PaletteDataset* CGame_MVC2_A::GetSpecificPalette(size_t nUnitId, size_t nPaletteId)
{
    return _GetSpecificPalette(MVC2_A_UNITS, rgExtraCountAll, MVC2_A_NUMUNIT, MVC2_A_EXTRALOC, nUnitId, nPaletteId, MVC2_A_EXTRA_CUSTOM);
}

void CGame_MVC2_A::LoadSpecificPaletteData(size_t nUnitId, size_t nPalId)
{
     if (nUnitId != MVC2_A_EXTRALOC)
    {
        int cbPaletteSizeOnDisc = 0;
        const sGame_PaletteDataset* paletteData = GetSpecificPalette(nUnitId, nPalId);

        if (paletteData)
        {
            cbPaletteSizeOnDisc = (int)max(0, (paletteData->nPaletteOffsetEnd - paletteData->nPaletteOffset));

            m_nCurrentPaletteROMLocation = paletteData->nPaletteOffset;
            m_nCurrentPaletteSizeInColors = cbPaletteSizeOnDisc / m_nSizeOfColorsInBytes;
            m_pszCurrentPaletteName = paletteData->szPaletteName;
        }
        else
        {
            // A bogus palette was requested: this is unrecoverable.
            DebugBreak();
        }
    }
    else // MVC2_A_EXTRALOC
    {
        // This is where we handle all the palettes added in via Extra.
        stExtraDef* pCurrDef = GetExtraDefForMVC2(GetExtraLoc(nUnitId) + nPalId);

        m_nCurrentPaletteROMLocation = pCurrDef->uOffset;
        m_nCurrentPaletteSizeInColors = (pCurrDef->cbPaletteSize / m_nSizeOfColorsInBytes);
        m_pszCurrentPaletteName = pCurrDef->szDesc;
    }
}

BOOL CGame_MVC2_A::LoadFile(CFile* LoadedFile, size_t nUnitId)
{
    for (size_t nUnitCtr = 0; nUnitCtr < nUnitAmt; nUnitCtr++)
    {
        size_t nPalAmt = GetPaletteCountForUnit(nUnitCtr);

        m_pppDataBuffer[nUnitCtr] = new UINT16 * [nPalAmt];

        // Use a sorted layout
        rgUnitRedir[nUnitCtr] = MVC2_A_UNITSORT[nUnitCtr];

        for (size_t nPalCtr = 0; nPalCtr < nPalAmt; nPalCtr++)
        {
            LoadSpecificPaletteData(nUnitCtr, nPalCtr);

            m_pppDataBuffer[nUnitCtr][nPalCtr] = new UINT16[m_nCurrentPaletteSizeInColors];

            if (nUnitCtr == indexMVC2ATeamView)
            {
                // This is a virtual group.
                // We just need to be indexed in the rgUnitRedir
                ZeroMemory(m_pppDataBuffer[nUnitCtr][nPalCtr], m_nCurrentPaletteSizeInColors);
                continue;
            }
            else
            {
                LoadedFile->Seek(m_nCurrentPaletteROMLocation, CFile::begin);

                LoadedFile->Read(m_pppDataBuffer[nUnitCtr][nPalCtr], m_nCurrentPaletteSizeInColors * 2);
            }
        }
    }

    rgUnitRedir[nUnitAmt] = INVALID_UNIT_VALUE;
    
    CheckForErrorsInTables();

    return TRUE;
}

BOOL CGame_MVC2_A::SaveFile(CFile* SaveFile, size_t nUnitId)
{
    UINT32 nTotalPalettesSaved = 0;

    for (size_t nUnitCtr = 0; nUnitCtr < nUnitAmt; nUnitCtr++)
    {
        if (nUnitCtr == indexMVC2ATeamView)
        {
            // This is a virtual group.
            continue;
        }

        size_t nPalAmt = GetPaletteCountForUnit(nUnitCtr);

        for (size_t nPalCtr = 0; nPalCtr < nPalAmt; nPalCtr++)
        {
            // We don't mark proc_supp palettes dirty: only use this check if we change that behavior
            //if (IsPaletteDirty(nUnitCtr, nPalCtr))
            {
                LoadSpecificPaletteData(nUnitCtr, nPalCtr);

                SaveFile->Seek(m_nCurrentPaletteROMLocation, CFile::begin);
                SaveFile->Write(m_pppDataBuffer[nUnitCtr][nPalCtr], m_nCurrentPaletteSizeInColors * 2);
                nTotalPalettesSaved++;
            }
        }
    }

    CString strMsg;
    strMsg.Format(L"CGame_MVC2_A::SaveFile: Saved 0x%x palettes to disk for %u units\n", nTotalPalettesSaved, nUnitAmt);
    OutputDebugString(strMsg);

    return TRUE;
}

BOOL CGame_MVC2_A::UpdatePalImg(int Node01, int Node02, int Node03, int Node04)
{
    //Reset palette sources
    ClearSrcPal();

    if (Node01 == -1)
    {
        return FALSE;
    }

    sDescNode* NodeGet = GetMainTree()->GetDescNode(Node01, Node02, Node03, Node04);

    if (NodeGet == nullptr)
    {
        return FALSE;
    }

    // Default values for multisprite image display for Export
    int nSrcStart = (int)NodeGet->uPalId;
    size_t nSrcAmt = 1;
    int nNodeIncrement = 1;

    //Get rid of any palettes if there are any
    BasePalGroup.FlushPalAll();

    // Make sure to reset the image id
    nTargetImgId = 0;
    size_t nImgUnitId = INVALID_UNIT_VALUE;

    bool fShouldUseAlternateLoadLogic = false;

    // Only load images for internal units, since we don't currently have a methodology for associating
    // external loads to internal sprites.
    if (NodeGet->uUnitId != MVC2_A_EXTRALOC)
    {
        const sGame_PaletteDataset* paletteDataSet = GetSpecificPalette(NodeGet->uUnitId, NodeGet->uPalId);

        if (paletteDataSet)
        {
            nImgUnitId = paletteDataSet->indexImgToUse;
            nTargetImgId = paletteDataSet->indexOffsetToUse;

            const sDescTreeNode* pCurrentNode = GetNodeFromPaletteId(NodeGet->uUnitId, NodeGet->uPalId, false);

            if (pCurrentNode) // For Basic nodes, we can allow multisprite view in the Export dialog
            {
                if (NodeGet->uUnitId == indexMVC2ATeamView)
                {
                    UINT16 nJoinedUnit1 = indexMVC2AMagneto;
                    UINT16 nJoinedUnit2 = indexMVC2AStorm;
                    UINT16 nJoinedUnit3 = indexMVC2APsylocke;
                    bool fTeamFound = false;

                    for (UINT16 nTeamIndex = 0; nTeamIndex < ARRAYSIZE(mvc2TeamList); nTeamIndex++)
                    {
                        if (_wcsicmp(mvc2TeamList[nTeamIndex].pszTeamName, pCurrentNode->szDesc) == 0)
                        {
                            nJoinedUnit1 = mvc2TeamList[nTeamIndex].nCharacterOne;
                            nJoinedUnit2 = mvc2TeamList[nTeamIndex].nCharacterTwo;
                            nJoinedUnit3 = mvc2TeamList[nTeamIndex].nCharacterThree;
                            fTeamFound = true;
                            break;
                        }
                    }

                    if (!fTeamFound)
                    {
                        OutputDebugString(L"WARNING: MVC2 Team lookup failed. Please fix.  Will use MSP for now.\n");
                    }

                    // Fudge some visual offsets here so fatter sprites don't collide.
                    int nXOffsetForSecond = 100;
                    int nYOffsetForSecond = 0;
                    int nXOffsetForThird = nXOffsetForSecond + 80;
                    int nYOffsetForThird = 0;

                    if ((nJoinedUnit2 == indexMVC2AStorm) && (nJoinedUnit3 == indexMVC2APsylocke))
                    {
                        nXOffsetForThird += 20;
                    }
                    else if ((nJoinedUnit1 == indexMVC2AStorm) && (nJoinedUnit2 == indexMVC2ASentinel) && (nJoinedUnit3 == indexMVC2ACaptainCommando))
                    {
                        // Santhrax
                        nXOffsetForSecond += 40;
                        nXOffsetForThird += 90;
                    }
                    else if ((nJoinedUnit1 == indexMVC2ACable) && (nJoinedUnit2 == indexMVC2ASentinel) && (nJoinedUnit3 == indexMVC2ACaptainCommando))
                    {
                        // scrub
                        nXOffsetForSecond += 40;
                        nXOffsetForThird += 90;
                    }
                    else if ((nJoinedUnit1 == indexMVC2AMagneto) && (nJoinedUnit2 == indexMVC2ACable) && (nJoinedUnit3 == indexMVC2ASentinel))
                    {
                        // rowtron
                        nXOffsetForThird += 40;
                    }
                    else if ((nJoinedUnit1 == indexMVC2AStorm) && (nJoinedUnit2 == indexMVC2ASentinel) && (nJoinedUnit3 == indexMVC2ACyclops))
                    {
                        // matrix
                        nXOffsetForSecond += 40;
                        nXOffsetForThird += 70;
                    }
                    else if ((nJoinedUnit1 == indexMVC2ASpiral) && (nJoinedUnit2 == indexMVC2ACable) && (nJoinedUnit3 == indexMVC2ASentinel))
                    {
                        // duc
                        nXOffsetForThird += 60;
                    }
                    else if ((nJoinedUnit1 == indexMVC2ASentinel) && (nJoinedUnit2 == indexMVC2AStrider) && (nJoinedUnit3 == indexMVC2ADrDoom))
                    {
                        // clockw0rk
                        nXOffsetForSecond += 30;
                        nXOffsetForThird += 100;
                    }
                    else if ((nJoinedUnit1 == indexMVC2AMagneto) && (nJoinedUnit2 == indexMVC2AIronMan) && (nJoinedUnit3 == indexMVC2ASentinel))
                    {
                        // combofiend
                        nXOffsetForThird += 60;
                    }
                    else if ((nJoinedUnit1 == indexMVC2ARogue) && (nJoinedUnit2 == indexMVC2AColossus) && (nJoinedUnit3 == indexMVC2AKen))
                    {
                        // vdo
                        nXOffsetForSecond += 20;
                        nXOffsetForThird += 40;
                    }
                    else
                    {
                        if (nJoinedUnit2 == indexMVC2ASentinel)
                        {
                            nXOffsetForSecond += 40;
                            nXOffsetForThird += 40;
                        }
                        else if (nJoinedUnit2 == indexMVC2AStrider)
                        {
                            nXOffsetForSecond += 280;
                            nXOffsetForThird += 40;
                        }
                        else if (nJoinedUnit2 == indexMVC2ADrDoom)
                        {
                            nXOffsetForSecond += 80;
                            nXOffsetForThird += 80;
                        }
                        else if (nJoinedUnit2 == indexMVC2AColossus)
                        {
                            nXOffsetForThird += 40;
                        }

                        if (nJoinedUnit3 == indexMVC2ASentinel)
                        {
                            nXOffsetForThird += 40;
                        }
                        else if (nJoinedUnit3 == indexMVC2ACaptainCommando)
                        {
                            nXOffsetForThird += 50;
                        }
                        else if (nJoinedUnit3 == indexMVC2AAkuma)
                        {
                            nXOffsetForThird += 20;
                        }
                    }

                    UINT16 nNodeIndex = (NodeGet->uPalId % 6);
                    // there are 8 palettes per main character button/color section
                    UINT16 nPaletteIndex = nNodeIndex * 8;
                    const sGame_PaletteDataset* palette1ToJoin = GetSpecificPalette(nJoinedUnit1, nPaletteIndex);
                    const sGame_PaletteDataset* palette2ToJoin = GetSpecificPalette(nJoinedUnit2, nPaletteIndex);
                    const sGame_PaletteDataset* palette3ToJoin = GetSpecificPalette(nJoinedUnit3, nPaletteIndex);

                    fShouldUseAlternateLoadLogic = true;

                    ClearSetImgTicket(
                        CreateImgTicket(palette1ToJoin->indexImgToUse, k_nSpecialTeamSpriteImageIndex,
                            CreateImgTicket(palette2ToJoin->indexImgToUse, k_nSpecialTeamSpriteImageIndex,
                                CreateImgTicket(palette3ToJoin->indexImgToUse, k_nSpecialTeamSpriteImageIndex, nullptr, nXOffsetForThird, nYOffsetForThird),
                                nXOffsetForSecond, nYOffsetForSecond)
                        )
                    );

                    //Set each palette
                    sDescNode* JoinedNode[3] = {
                        GetMainTree()->GetDescNode(nJoinedUnit1, nNodeIndex, 0, -1),
                        GetMainTree()->GetDescNode(nJoinedUnit2, nNodeIndex, 0, -1),
                        GetMainTree()->GetDescNode(nJoinedUnit3, nNodeIndex, 0, -1)
                    };

                    //Set each palette
                    CreateDefPal(JoinedNode[0], 0);
                    CreateDefPal(JoinedNode[1], 1);
                    CreateDefPal(JoinedNode[2], 2);

                    nSrcAmt = 6; // 6 button colors
                    nNodeIncrement = 8; // 8 palettes per main character color set
                    SetSourcePal(0, nJoinedUnit1, 0, nSrcAmt, nNodeIncrement);
                    SetSourcePal(1, nJoinedUnit2, 0, nSrcAmt, nNodeIncrement);
                    SetSourcePal(2, nJoinedUnit3, 0, nSrcAmt, nNodeIncrement);
                }
                else  if ((_wcsicmp(pCurrentNode->szDesc, L"LP") == 0) || (_wcsicmp(pCurrentNode->szDesc, L"LK") == 0) ||
                          (_wcsicmp(pCurrentNode->szDesc, L"HP") == 0) || (_wcsicmp(pCurrentNode->szDesc, L"HK") == 0) ||
                          (_wcsicmp(pCurrentNode->szDesc, L"A1") == 0) || (_wcsicmp(pCurrentNode->szDesc, L"A2") == 0))
                {
                    // We show 6 sprites (LP...A2) for export for all normal MVC2 sprites
                    nSrcAmt = pButtonLabelSet.size();
                    nNodeIncrement = pCurrentNode->uChildAmt;
                    // Need to reset because we have a status effect label set as well.
                    pButtonLabelSet = DEF_BUTTONLABEL6_MVC2;

                    while (nSrcStart >= nNodeIncrement)
                    {
                        // The starting point is the absolute first palette for the sprite in question which is found in P1
                        nSrcStart -= nNodeIncrement;
                    }
                }
                else if (_wcsicmp(pCurrentNode->szDesc, L"Status Effects") == 0)
                {
                    // Status Effects follow main buttons but are before Extras, if any
                    nSrcStart = 0;

                    for (UINT16 iCollectionIndex = 0; iCollectionIndex < DEF_BUTTONLABEL6_MVC2.size(); iCollectionIndex++)
                    {
                        nSrcStart += GetNodeCountForCollection(NodeGet->uUnitId, iCollectionIndex);
                    }

                    // There are 8 status effects
                    nSrcAmt = 8;
                    nNodeIncrement = paletteDataSet->pPalettePairingInfo ? 2 : 1;
                    pButtonLabelSet = DEF_LABEL_STATUS_EFFECTS;
                }
            }

            if (paletteDataSet->pPalettePairingInfo)
            {
                if (NodeGet->uUnitId == indexMVC2AShuma)
                {
                    OutputDebugString(L"Sadness: this sprite is wrong.  Should be reripped as paired.\n");
                }
                else
                {
                    if (((NodeGet->uUnitId == indexMVC2ASentinel) && (paletteDataSet->pPalettePairingInfo == &pairHandledInCode)) ||
                        ((NodeGet->uUnitId == indexMVC2ATron) && (paletteDataSet->pPalettePairingInfo == &pairHandledInCode)))
                    {
                        INT8 nPeerPaletteDistance1 = 1;
                        INT8 nPeerPaletteDistance2 = 3;
                        const sGame_PaletteDataset* paletteDataSetToJoin1 = GetSpecificPalette(NodeGet->uUnitId, NodeGet->uPalId + nPeerPaletteDistance1);
                        const sGame_PaletteDataset* paletteDataSetToJoin2 = GetSpecificPalette(NodeGet->uUnitId, NodeGet->uPalId + nPeerPaletteDistance2);
                        fShouldUseAlternateLoadLogic = true;

                        ClearSetImgTicket(
                            CreateImgTicket(paletteDataSet->indexImgToUse, paletteDataSet->indexOffsetToUse,
                                CreateImgTicket(paletteDataSetToJoin1->indexImgToUse, paletteDataSetToJoin1->indexOffsetToUse,
                                    CreateImgTicket(paletteDataSetToJoin2->indexImgToUse, paletteDataSetToJoin2->indexOffsetToUse)
                                    ))
                        );

                        //Set each palette
                        sDescNode* JoinedNode[] = {
                            GetMainTree()->GetDescNode(Node01, Node02, Node03, -1),
                            GetMainTree()->GetDescNode(Node01, Node02, Node03 + nPeerPaletteDistance1, -1),
                            GetMainTree()->GetDescNode(Node01, Node02, Node03 + nPeerPaletteDistance2, -1)
                        };

                        //Set each palette
                        CreateDefPal(JoinedNode[0], 0);
                        CreateDefPal(JoinedNode[1], 1);
                        CreateDefPal(JoinedNode[2], 2);

                        SetSourcePal(0, NodeGet->uUnitId, nSrcStart, nSrcAmt, nNodeIncrement);
                        SetSourcePal(1, NodeGet->uUnitId, nSrcStart + nPeerPaletteDistance1, nSrcAmt, nNodeIncrement);
                        SetSourcePal(2, NodeGet->uUnitId, nSrcStart + nPeerPaletteDistance2, nSrcAmt, nNodeIncrement);
                    }
                    else if (paletteDataSet->pPalettePairingInfo == &pairFullyLinkedNode)
                    {
                        const size_t nStageCount = GetNodeSizeFromPaletteId(NodeGet->uUnitId, NodeGet->uPalId);

                        fShouldUseAlternateLoadLogic = true;
                        sImgTicket* pImgArray = nullptr;

                        for (size_t nStageIndex = 0; nStageIndex < nStageCount; nStageIndex++)
                        {
                            // The palettes get added forward, but the image tickets need to be generated in reverse order
                            const sGame_PaletteDataset* paletteDataSetToJoin = GetSpecificPalette(NodeGet->uUnitId, NodeGet->uPalId + (nStageCount - 1 - nStageIndex));
                            if (paletteDataSetToJoin)
                            {
                                pImgArray = CreateImgTicket(paletteDataSetToJoin->indexImgToUse, paletteDataSetToJoin->indexOffsetToUse, pImgArray);

                                //Set each palette
                                sDescNode* JoinedNode = GetMainTree()->GetDescNode(Node01, Node02, Node03 + nStageIndex, -1);
                                CreateDefPal(JoinedNode, nStageIndex);
                                SetSourcePal(nStageIndex, NodeGet->uUnitId, nSrcStart + nStageIndex, nSrcAmt, nNodeIncrement);
                            }
                        }

                        ClearSetImgTicket(pImgArray);
                    }
                    else
                    {
                        UINT32 nDeltaToSecondElement = paletteDataSet->pPalettePairingInfo->nNodeIncrementToPartner;
                        int nXOffs = paletteDataSet->pPalettePairingInfo->nXOffs;
                        int nYOffs = paletteDataSet->pPalettePairingInfo->nYOffs;

                        const sGame_PaletteDataset* paletteDataSetToJoin = GetSpecificPalette(NodeGet->uUnitId, NodeGet->uPalId + nDeltaToSecondElement);
                        if (paletteDataSetToJoin)
                        {
                            fShouldUseAlternateLoadLogic = true;

                            ClearSetImgTicket(
                                CreateImgTicket(paletteDataSet->indexImgToUse, paletteDataSet->indexOffsetToUse,
                                    CreateImgTicket(paletteDataSetToJoin->indexImgToUse, paletteDataSetToJoin->indexOffsetToUse, nullptr, nXOffs, nYOffs)
                                )
                            );

                            //Set each palette
                            sDescNode* JoinedNode[2] = {
                                GetMainTree()->GetDescNode(Node01, Node02, Node03, -1),
                                GetMainTree()->GetDescNode(Node01, Node02, Node03 + nDeltaToSecondElement, -1)
                            };

                            //Set each palette
                            CreateDefPal(JoinedNode[0], 0);
                            CreateDefPal(JoinedNode[1], 1);

                            SetSourcePal(0, NodeGet->uUnitId, nSrcStart, nSrcAmt, nNodeIncrement);
                            SetSourcePal(1, NodeGet->uUnitId, nSrcStart + nDeltaToSecondElement, nSrcAmt, nNodeIncrement);
                        }
                    }
                }
            }
        }
    }
    
    if (!fShouldUseAlternateLoadLogic)
    {
        //Create the default palette
        ClearSetImgTicket(CreateImgTicket(nImgUnitId, nTargetImgId));

        CreateDefPal(NodeGet, 0);

        SetSourcePal(0, NodeGet->uUnitId, nSrcStart, nSrcAmt, nNodeIncrement);
    }

    return TRUE;
}

size_t CGame_MVC2_A::GetBasicOffset(size_t nPalId)
{
    // Each character by default gets 6 buttons worth of 8 palettes.  
    if (nPalId >= (size_t)(8 * k_mvc2_character_coloroption_count))
    {
        // This palette is in the Extra group for this character
        return -1;
    }
    else
    {
        // This is a stock palette entry for this character: return the MOD so we know the 
        // particular offset within this button group.
        return (nPalId % 8);
    }
}

void CGame_MVC2_A::PostSetPal(size_t nUnitId, size_t nPalId)
{
    size_t nBasicOffset = GetBasicOffset(nPalId);

    CString strMessage;
    strMessage.Format(L"CGame_MVC2_A::GetBasicOffset : Palette %u updated.  This palette is %s.\n", nPalId, (nBasicOffset != -1) ? L"basic" : L"Extra");
    OutputDebugString(strMessage);

    proc_supp(nUnitId, nPalId);
}
