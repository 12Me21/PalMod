#pragma once

#include <iterator>
#include <iostream>
#include <algorithm>

enum PersonaSpriteList
{
    indexP4AUSprites_Aigis,         // 0x00
    indexP4AUSprites_Akihiko,       // 0x01
    indexP4AUSprites_Chie,          // 0x02
    indexP4AUSprites_Elizabeth,     // 0x03
    indexP4AUSprites_Junpei,        // 0x04
    indexP4AUSprites_Kanji,         // 0x05
    indexP4AUSprites_Ken,           // 0x06
    indexP4AUSprites_Labrys,        // 0x07
    indexP4AUSprites_Margaret,      // 0x08
    indexP4AUSprites_Marie,         // 0x09
    indexP4AUSprites_Mitsuru,       // 0x0a
    indexP4AUSprites_Naoto,         // 0x0b
    indexP4AUSprites_Rise,          // 0x0c
    indexP4AUSprites_Shadow,        // 0x0d
    indexP4AUSprites_Sho,           // 0x0e
    indexP4AUSprites_Solo,          // 0x0f
    indexP4AUSprites_Teddie,        // 0x10
    indexP4AUSprites_Tohru,         // 0x11
    indexP4AUSprites_Yosuke,        // 0x12
    indexP4AUSprites_Yu,            // 0x13
    indexP4AUSprites_Yukari,        // 0x14
    indexP4AUSprites_Yukiko,        // 0x15
    indexP4AUSprites_Bonus,         // 0x16
};

const std::vector<UINT16> P4AU_S_IMGIDS_USED =
{
    indexP4AUSprites_Aigis,         // 0x00
    indexP4AUSprites_Akihiko,       // 0x01
    indexP4AUSprites_Chie,          // 0x02
    indexP4AUSprites_Elizabeth,     // 0x03
    indexP4AUSprites_Junpei,        // 0x04
    indexP4AUSprites_Kanji,         // 0x05
    indexP4AUSprites_Ken,           // 0x06
    indexP4AUSprites_Labrys,        // 0x07
    indexP4AUSprites_Margaret,      // 0x08
    indexP4AUSprites_Marie,         // 0x09
    indexP4AUSprites_Mitsuru,       // 0x0a
    indexP4AUSprites_Naoto,         // 0x0b
    indexP4AUSprites_Rise,          // 0x0c
    indexP4AUSprites_Shadow,        // 0x0d
    indexP4AUSprites_Sho,           // 0x0e
    indexP4AUSprites_Solo,          // 0x0f
    indexP4AUSprites_Teddie,        // 0x10
    indexP4AUSprites_Tohru,         // 0x11
    indexP4AUSprites_Yosuke,        // 0x12
    indexP4AUSprites_Yu,            // 0x13
    indexP4AUSprites_Yukari,        // 0x14
    indexP4AUSprites_Yukiko,        // 0x15
    indexP4AUSprites_Bonus,         // 0x16
};

const std::vector<LPCWSTR> PersonaPaletteNodes =
{
    L"Color 1",
    L"Color 2",
    L"Color 3",
    L"Color 4",
    L"Color 5",
    L"Color 6",
    L"Color 7",
    L"Color 8",
    L"Color 9",
    L"Color 10",
    L"Color 11",
    L"Color 12",
    L"Color 13",
    L"Color 14",
    L"Color 15",
    L"Color 16",
    L"Color 17",
    L"Color 18",
    L"Color 19",
    L"Color 20",
    L"Color 21",
    L"Color 22",
    L"Color 23",
    L"Color 24",
    L"Color 25",
    L"Color 26",
    L"Color 27",
    L"Color 28",
    L"Color 29 (Unused)",
    L"Color 30",
    L"Color 31",
    L"Color 32 (Shadow NPC)",
};

struct Persona4PaletteData
{
    std::wstring strName;
    int16_t nImageSet = -1;
    int16_t nImageIndex = -1;
};

const std::vector<Persona4PaletteData> Persona4PalettesDefault =
{ {
    { L"Main" },
    { L"Persona" },
    { L"Extra 1" },
    { L"Extra 2" },
    { L"Extra 3" },
    { L"Extra 4" },
    { L"Extra 5" },
    { L"Extra 6" },
} };

const std::vector<Persona4PaletteData> Persona4PaletteCSEL =
{ {
    { L"Main" },
    { L"Persona" },
} };


const std::vector<Persona4PaletteData> Persona4PalettesAigis =
{ {
    { L"Main", indexP4AUSprites_Aigis, 0x00 },
    { L"Persona: Athena", indexP4AUSprites_Aigis, 0x20 },
    { L"Extra 1" },
    { L"Extra 2" },
    { L"Extra 3" },
    { L"Extra 4" },
    { L"Extra 5" },
    { L"Extra 6" },
} };

const std::vector<Persona4PaletteData> Persona4PalettesAkihiko =
{ {
    { L"Main", indexP4AUSprites_Akihiko, 0x00 },
    { L"Persona: Caesar", indexP4AUSprites_Akihiko, 0x20 },
    { L"Extra 1" },
    { L"Extra 2" },
    { L"Extra 3" },
    { L"Extra 4" },
    { L"Extra 5" },
    { L"Extra 6" },
} };

const std::vector<Persona4PaletteData> Persona4PalettesKen =
{ {
    { L"Main", indexP4AUSprites_Ken, 0x00 },
    { L"Persona: Kala-Nemi (Ken)", indexP4AUSprites_Ken, 0x40 },
    { L"Koromaru - Main", indexP4AUSprites_Ken, 0x20 },
    { L"Koromaru - Persona: Cerberus", indexP4AUSprites_Ken, 0x60 },
    { L"Extra 1" },
    { L"Extra 2" },
    { L"Extra 3" },
    { L"Extra 4" },
} };

const std::vector<Persona4PaletteData> Persona4PalettesChie =
{ {
    { L"Main", indexP4AUSprites_Chie, 0x00 },
    { L"Persona: Tomoe", indexP4AUSprites_Chie, 0x20 },
    { L"Extra 1" },
    { L"Extra 2" },
    { L"Extra 3" },
    { L"Extra 4" },
    { L"Extra 5" },
    { L"Extra 6" },
} };

const std::vector<Persona4PaletteData> Persona4PalettesElizabeth =
{ {
    { L"Main", indexP4AUSprites_Elizabeth, 0x00 },
    { L"Persona: Thanatos", indexP4AUSprites_Elizabeth, 0x20 },
    { L"Extra 1" },
    { L"Extra 2" },
    { L"Extra 3" },
    { L"Extra 4" },
    { L"Extra 5" },
    { L"Extra 6" },
} };

const std::vector<Persona4PaletteData> Persona4PalettesJunpei =
{ {
    { L"Main", indexP4AUSprites_Junpei, 0x00 },
    { L"Persona: Trismegistus", indexP4AUSprites_Junpei, 0x20 },
    { L"Extra 1" },
    { L"Extra 2" },
    { L"Extra 3" },
    { L"Extra 4" },
    { L"Extra 5" },
    { L"Extra 6" },
} };

const std::vector<Persona4PaletteData> Persona4PalettesKanji =
{ {
    { L"Main", indexP4AUSprites_Kanji, 0x00 },
    { L"Persona: Take-Mikazuchi", indexP4AUSprites_Kanji, 0x20 },
    { L"Extra 1" },
    { L"Extra 2" },
    { L"Extra 3" },
    { L"Extra 4" },
    { L"Extra 5" },
    { L"Extra 6" },
} };

const std::vector<Persona4PaletteData> Persona4PalettesLabrys =
{ {
    { L"Main", indexP4AUSprites_Labrys, 0x00 },
    { L"Persona: Ariadne", indexP4AUSprites_Labrys, 0x20 },
    { L"Extra 1" },
    { L"Extra 2" },
    { L"Extra 3" },
    { L"Extra 4" },
    { L"Extra 5" },
    { L"Extra 6" },
} };

const std::vector<Persona4PaletteData> Persona4PalettesMargaret =
{ {
    { L"Main", indexP4AUSprites_Margaret, 0x00 },
    { L"Persona: Ardha", indexP4AUSprites_Margaret, 0x20 },
    { L"Extra 1: Cu Chulainn", indexP4AUSprites_Margaret, 0x40 },
    { L"Extra 2: Yoshitsune", indexP4AUSprites_Margaret, 0x60 },
    { L"Extra 3" },
    { L"Extra 4" },
    { L"Extra 5" },
    { L"Extra 6" },
} };

const std::vector<Persona4PaletteData> Persona4PalettesMarie =
{ {
    { L"Main", indexP4AUSprites_Marie, 0x00 },
    { L"Persona: Kaguya", indexP4AUSprites_Marie, 0x20 },
    { L"Extra 1" },
    { L"Extra 2" },
    { L"Extra 3" },
    { L"Extra 4" },
    { L"Extra 5" },
    { L"Extra 6" },
} };

const std::vector<Persona4PaletteData> Persona4PalettesMitsuru =
{ {
    { L"Main", indexP4AUSprites_Mitsuru, 0x00 },
    { L"Persona: Artemisia", indexP4AUSprites_Mitsuru, 0x20 },
    { L"Extra 1" },
    { L"Extra 2" },
    { L"Extra 3" },
    { L"Extra 4" },
    { L"Extra 5" },
    { L"Extra 6" },
} };

const std::vector<Persona4PaletteData> Persona4PalettesNaoto =
{ {
    { L"Main", indexP4AUSprites_Naoto, 0x00 },
    { L"Persona: Sukuna-Hikona", indexP4AUSprites_Naoto, 0x20 },
    { L"Extra 1" },
    { L"Extra 2" },
    { L"Extra 3" },
    { L"Extra 4" },
    { L"Extra 5" },
    { L"Extra 6" },
} };

const std::vector<Persona4PaletteData> Persona4PalettesRise =
{ {
    { L"Main", indexP4AUSprites_Rise, 0x00 },
    { L"Persona: Himiko", indexP4AUSprites_Rise, 0x20 },
    { L"Extra 1" },
    { L"Extra 2" },
    { L"Extra 3" },
    { L"Extra 4" },
    { L"Extra 5" },
    { L"Extra 6" },
} };

const std::vector<Persona4PaletteData> Persona4PalettesShadow =
{ {
    { L"Main", indexP4AUSprites_Shadow, 0x00 },
    { L"Persona: Asterius", indexP4AUSprites_Shadow, 0x20 },
    { L"Extra 1" },
    { L"Extra 2" },
    { L"Extra 3" },
    { L"Extra 4" },
    { L"Extra 5" },
    { L"Extra 6" },
} };

const std::vector<Persona4PaletteData> Persona4PalettesSho =
{ {
    { L"Main", indexP4AUSprites_Sho, 0x00 },
    { L"Persona: Tsukiyomi", indexP4AUSprites_Sho, 0x20 },
    { L"Extra 1" },
    { L"Extra 2" },
    { L"Extra 3" },
    { L"Extra 4: Tsukiyomi IK", indexP4AUSprites_Sho, 0x40 },
    { L"Extra 5" },
    { L"Extra 6" },
} };

const std::vector<Persona4PaletteData> Persona4PalettesSolo =
{ {
    { L"Main", indexP4AUSprites_Solo, 0x00 },
    { L"Persona (None)" },
    { L"Extra 1" },
    { L"Extra 2" },
    { L"Extra 3" },
    { L"Extra 4" },
    { L"Extra 5" },
    { L"Extra 6" },
} };

const std::vector<Persona4PaletteData> Persona4PalettesTeddie =
{ {
    { L"Main", indexP4AUSprites_Teddie, 0x00 },
    { L"Persona: Kintoki-Douji", indexP4AUSprites_Teddie, 0x20 },
    { L"Extra 1" },
    { L"Extra 2" },
    { L"Extra 3" },
    { L"Extra 4" },
    { L"Extra 5" },
    { L"Extra 6" },
} };

const std::vector<Persona4PaletteData> Persona4PalettesTohru =
{ {
    { L"Main", indexP4AUSprites_Tohru, 0x00 },
    { L"Persona: Magatsu Izanagi", indexP4AUSprites_Tohru, 0x20 },
    { L"Extra 1" },
    { L"Extra 2" },
    { L"Extra 3" },
    { L"Extra 4" },
    { L"Extra 5" },
    { L"Extra 6" },
} };

const std::vector<Persona4PaletteData> Persona4PalettesYosuke =
{ {
    { L"Main", indexP4AUSprites_Yosuke, 0x00 },
    { L"Persona: Jiraiya", indexP4AUSprites_Yosuke, 0x20 },
    { L"Extra 1" },
    { L"Extra 2" },
    { L"Extra 3" },
    { L"Extra 4" },
    { L"Extra 5" },
    { L"Extra 6" },
} };

const std::vector<Persona4PaletteData> Persona4PalettesYu =
{ {
    { L"Main", indexP4AUSprites_Yu, 0x00 },
    { L"Persona: Izanagi", indexP4AUSprites_Yu, 0x20 },
    { L"Extra 1" },
    { L"Extra 2" },
    { L"Extra 3: Izanagi no Okami", indexP4AUSprites_Yu, 0x40 },
    { L"Extra 4" },
    { L"Extra 5" },
    { L"Extra 6" },
} };

const std::vector<Persona4PaletteData> Persona4PalettesYukari =
{ {
    { L"Main", indexP4AUSprites_Yukari, 0x00 },
    { L"Persona: Isis", indexP4AUSprites_Yukari, 0x20 },
    { L"Extra 1" },
    { L"Extra 2" },
    { L"Extra 3" },
    { L"Extra 4" },
    { L"Extra 5" },
    { L"Extra 6" },
} };

const std::vector<Persona4PaletteData> Persona4PalettesYukiko =
{ {
    { L"Main", indexP4AUSprites_Yukiko, 0x00 },
    { L"Persona: Konohana-Sakuya", indexP4AUSprites_Yukiko, 0x20 },
    { L"Extra 1" },
    { L"Extra 2" },
    { L"Extra 3" },
    { L"Extra 4" },
    { L"Extra 5" },
    { L"Extra 6" },
} };

const std::vector<Persona4PaletteData> Persona4PalettesAigisCSEL =
{ {
    { L"Main", indexP4AUSprites_Aigis, 0x00 },
    { L"Persona: Athena", indexP4AUSprites_Aigis, 0x20 },
} };

const std::vector<Persona4PaletteData> Persona4PalettesAkihikoCSEL =
{ {
    { L"Main", indexP4AUSprites_Akihiko, 0x00 },
    { L"Persona: Caesar", indexP4AUSprites_Akihiko, 0x20 },
} };

const std::vector<Persona4PaletteData> Persona4PalettesKenCSEL =
{ {
    { L"Main + Koromaru", indexP4AUSprites_Ken, 0x80 },
    { L"Personas: Kala-Nemi,Cerberus", indexP4AUSprites_Ken, 0x81 },
} };

const std::vector<Persona4PaletteData> Persona4PalettesChieCSEL =
{ {
    { L"Main", indexP4AUSprites_Chie, 0x00 },
    { L"Persona: Tomoe", indexP4AUSprites_Chie, 0x20 },
} };

const std::vector<Persona4PaletteData> Persona4PalettesElizabethCSEL =
{ {
    { L"Main", indexP4AUSprites_Elizabeth, 0x00 },
    { L"Persona: Thanatos", indexP4AUSprites_Elizabeth, 0x20 },
} };

const std::vector<Persona4PaletteData> Persona4PalettesJunpeiCSEL =
{ {
    { L"Main", indexP4AUSprites_Junpei, 0x00 },
    { L"Persona: Trismegistus", indexP4AUSprites_Junpei, 0x20 },
} };

const std::vector<Persona4PaletteData> Persona4PalettesKanjiCSEL =
{ {
    { L"Main", indexP4AUSprites_Kanji, 0x00 },
    { L"Persona: Take-Mikazuchi", indexP4AUSprites_Kanji, 0x20 },
} };

const std::vector<Persona4PaletteData> Persona4PalettesLabrysCSEL =
{ {
    { L"Main", indexP4AUSprites_Labrys, 0x00 },
    { L"Persona: Ariadne", indexP4AUSprites_Labrys, 0x20 },
} };

const std::vector<Persona4PaletteData> Persona4PalettesMargaretCSEL =
{ {
    { L"Main", indexP4AUSprites_Margaret, 0x00 },
    { L"Personas: Ardha,Cu Chulainn,Yoshitsune", indexP4AUSprites_Margaret, 0x81 },
} };

const std::vector<Persona4PaletteData> Persona4PalettesMarieCSEL =
{ {
    { L"Main", indexP4AUSprites_Marie, 0x00 },
    { L"Persona: Kaguya", indexP4AUSprites_Marie, 0x20 },
} };

const std::vector<Persona4PaletteData> Persona4PalettesMitsuruCSEL =
{ {
    { L"Main", indexP4AUSprites_Mitsuru, 0x00 },
    { L"Persona: Artemisia", indexP4AUSprites_Mitsuru, 0x20 },
} };

const std::vector<Persona4PaletteData> Persona4PalettesNaotoCSEL =
{ {
    { L"Main", indexP4AUSprites_Naoto, 0x00 },
    { L"Persona: Sukuna-Hikona", indexP4AUSprites_Naoto, 0x20 },
} };

const std::vector<Persona4PaletteData> Persona4PalettesRiseCSEL =
{ {
    { L"Main", indexP4AUSprites_Rise, 0x00 },
    { L"Persona: Himiko", indexP4AUSprites_Rise, 0x20 },
} };

const std::vector<Persona4PaletteData> Persona4PalettesShadowCSEL =
{ {
    { L"Main", indexP4AUSprites_Shadow, 0x00 },
    { L"Persona: Asterius", indexP4AUSprites_Shadow, 0x20 },
} };

const std::vector<Persona4PaletteData> Persona4PalettesShoCSEL =
{ {
    { L"Main", indexP4AUSprites_Sho, 0x00 },
    { L"Persona: Tsukiyomi", indexP4AUSprites_Sho, 0x20 },
} };

const std::vector<Persona4PaletteData> Persona4PalettesSoloCSEL =
{ {
    { L"Main", indexP4AUSprites_Solo, 0x00 },
    { L"Persona: Tsukiyomi (UNUSED)" },
} };

const std::vector<Persona4PaletteData> Persona4PalettesTeddieCSEL =
{ {
    { L"Main", indexP4AUSprites_Teddie, 0x00 },
    { L"Persona: Kintoki-Douji", indexP4AUSprites_Teddie, 0x20 },
} };

const std::vector<Persona4PaletteData> Persona4PalettesTohruCSEL =
{ {
    { L"Main", indexP4AUSprites_Tohru, 0x00 },
    { L"Persona: Magatsu Izanagi", indexP4AUSprites_Tohru, 0x20 },
} };

const std::vector<Persona4PaletteData> Persona4PalettesYosukeCSEL =
{ {
    { L"Main", indexP4AUSprites_Yosuke, 0x00 },
    { L"Persona: Jiraiya", indexP4AUSprites_Yosuke, 0x20 },
} };

const std::vector<Persona4PaletteData> Persona4PalettesYuCSEL =
{ {
    { L"Main", indexP4AUSprites_Yu, 0x00 },
    { L"Persona: Izanagi", indexP4AUSprites_Yu, 0x20 },
} };

const std::vector<Persona4PaletteData> Persona4PalettesYukariCSEL =
{ {
    { L"Main", indexP4AUSprites_Yukari, 0x00 },
    { L"Persona: Isis", indexP4AUSprites_Yukari, 0x20 },
} };

const std::vector<Persona4PaletteData> Persona4PalettesYukikoCSEL =
{ {
    { L"Main", indexP4AUSprites_Yukiko, 0x00 },
    { L"Persona: Konohana-Sakuya", indexP4AUSprites_Yukiko, 0x20 },
} };

struct PersonaFileData
{
    std::wstring pszFileName;
    std::wstring pszCharacter;
    uint32_t nExpectedFileSize = 0;
    const std::vector<Persona4PaletteData>* paletteInfo = nullptr;
    uint32_t nInitialLocation = 0;
    uint32_t nPaletteSetLength = 0;
};

const std::vector<PersonaFileData> PersonaCharacterData =
{ {
    //Alphabetical
      { L"data\\char\\char_ag_pal.pac",    L"Aigis",                          282672,    &Persona4PalettesAigis,      0x3040,      0x2100 },
      { L"data\\ETC\\CHSLDotV.pac",        L"Aigis (CharaSelect)",            19190960,  &Persona4PalettesAigisCSEL,  0x192860,    0x840 },
      { L"data\\char\\char_ak_pal.pac",    L"Akihiko Sanada",                 282672,    &Persona4PalettesAkihiko,    0x3040,      0x2100 },
      { L"data\\ETC\\CHSLDotV.pac",        L"Akihiko Sanada (CharaSelect)",   19190960,  &Persona4PalettesAkihikoCSEL,0x24D210,    0x840 },
      { L"data\\char\\char_ce_pal.pac",    L"Chie Satonaka",                  282672,    &Persona4PalettesChie,       0x3040,      0x2100 },
      { L"data\\ETC\\CHSLDotV.pac",        L"Chie Satonaka (CharaSelect)",    19190960,  &Persona4PalettesChieCSEL,   0x4148D0,    0x840 },
      { L"data\\char\\char_el_pal.pac",    L"Elizabeth",                      282672,    &Persona4PalettesElizabeth,  0x3040,      0x2100 },
      { L"data\\ETC\\CHSLDotV.pac",        L"Elizabeth (CharaSelect)",        19190960,  &Persona4PalettesElizabethCSEL,0x55A470,  0x840 },
      { L"data\\char\\char_ju_pal.pac",    L"Junpei Iori",                    282672,    &Persona4PalettesJunpei,     0x3040,      0x2100 },
      { L"data\\ETC\\CHSLDotV.pac",        L"Junpei Iori (CharaSelect)",      19190960,  &Persona4PalettesJunpeiCSEL, 0x6017A0,    0x840 },
      { L"data\\char\\char_ka_pal.pac",    L"Kanji Tatsumi",                  282672,    &Persona4PalettesKanji,      0x3040,      0x2100 },
      { L"data\\ETC\\CHSLDotV.pac",        L"Kanji Tatsumi (CharaSelect)",    19190960,  &Persona4PalettesKanjiCSEL,  0x74A2C0,    0x840 },
      { L"data\\char\\char_am_pal.pac",    L"Ken Amada & Koromaru",           282672,    &Persona4PalettesKen,        0x3040,      0x2100 },
      { L"data\\ETC\\CHSLDotV.pac",        L"Ken Amada & Koromaru (CharaSelect)",19190960, &Persona4PalettesKenCSEL, 0x2EB630,    0x840 },
      { L"data\\char\\char_la_pal.pac",    L"Labrys",                         282672,    &Persona4PalettesLabrys,     0x3040,      0x2100 },
      { L"data\\ETC\\CHSLDotV.pac",        L"Labrys (CharaSelect)",           19190960,  &Persona4PalettesLabrysCSEL, 0x912950,    0x840 },
      { L"data\\char\\char_nx_pal.pac",    L"Margaret",                       282672,    &Persona4PalettesMargaret,   0x3040,      0x2100 },
      { L"data\\ETC\\CHSLDotV.pac",        L"Margaret (CharaSelect)",         19190960,  &Persona4PalettesMargaretCSEL,0xF558E0,   0x840 },
      { L"data\\char\\char_mr_pal.pac",    L"Marie",                          282672,    &Persona4PalettesMarie,      0x3040,      0x2100 },
      { L"data\\ETC\\CHSLDotV.pac",        L"Marie (CharaSelect)",            19190960,  &Persona4PalettesMarieCSEL,  0xC8B140,    0x840 },
      { L"data\\char\\char_mi_pal.pac",    L"Mitsuru Kirijo",                 282672,    &Persona4PalettesMitsuru,    0x3040,      0x2100 },
      { L"data\\ETC\\CHSLDotV.pac",        L"Mitsuru Kirijo (CharaSelect)",   19190960,  &Persona4PalettesMitsuruCSEL,0xBAD4A0,    0x840 },
      { L"data\\char\\char_na_pal.pac",    L"Naoto Shirogane",                282672,    &Persona4PalettesNaoto,      0x3040,      0x2100 },
      { L"data\\ETC\\CHSLDotV.pac",        L"Naoto Shirogane (CharaSelect)",  19190960,  &Persona4PalettesNaotoCSEL,  0xD1DBF0,    0x840 },
      { L"data\\char\\char_ri_pal.pac",    L"Rise Kujikawa",                  282672,    &Persona4PalettesRise,       0x3040,      0x2100 },
      { L"data\\ETC\\CHSLDotV.pac",        L"Rise Kujikawa (CharaSelect)",    19190960,  &Persona4PalettesRiseCSEL,   0x102DB50,   0x840 },
      { L"data\\char\\char_ls_pal.pac",    L"Shadow Labrys",                  282672,    &Persona4PalettesShadow,     0x3040,      0x2100 },
      { L"data\\ETC\\CHSLDotV.pac",        L"Shadow Labrys (CharaSelect)",    19190960,  &Persona4PalettesShadowCSEL, 0xACA6A0,    0x840 },
      { L"data\\char\\char_no_pal.pac",    L"Sho (Solo)",                     282672,    &Persona4PalettesSolo,       0x3040,      0x2100 },
      { L"data\\ETC\\CHSLDotV.pac",        L"Sho (Solo) (CharaSelect)",       19190960,  &Persona4PalettesSoloCSEL,   0xEBA380,    0x840 },
      { L"data\\char\\char_nb_pal.pac",    L"Sho Minazuki",                   282672,    &Persona4PalettesSho,        0x3040,      0x2100 },
      { L"data\\ETC\\CHSLDotV.pac",        L"Sho Minazuki (CharaSelect)",     19190960,  &Persona4PalettesShoCSEL,    0xDFB8A0,    0x840 },
      { L"data\\char\\char_ku_pal.pac",    L"Teddie/Kuma",                    282672,    &Persona4PalettesTeddie,     0x3040,      0x2100 },
      { L"data\\ETC\\CHSLDotV.pac",        L"Teddie/Kuma (CharaSelect)",      19190960,  &Persona4PalettesTeddieCSEL, 0x7E58C0,    0x840 },
      { L"data\\char\\char_ad_pal.pac",    L"Tohru Adachi",                   282672,    &Persona4PalettesTohru,      0x3040,      0x2100 },
      { L"data\\ETC\\CHSLDotV.pac",        L"Tohru Adachi (CharaSelect)",     19190960,  &Persona4PalettesTohruCSEL,  0xA0FB0,    0x840 },
      { L"data\\char\\char_yo_pal.pac",    L"Yosuke Hanamura",                282672,    &Persona4PalettesYosuke,     0x3040,      0x2100 },
      { L"data\\ETC\\CHSLDotV.pac",        L"Yosuke Hanamura (CharaSelect)",  19190960,  &Persona4PalettesYosukeCSEL, 0x1136110,   0x840 },
      { L"data\\char\\char_bc_pal.pac",    L"Yu Narukami",                    282672,    &Persona4PalettesYu,         0x3040,      0x2100 },
      { L"data\\ETC\\CHSLDotV.pac",        L"Yu Narukami (CharaSelect)",      19190960,  &Persona4PalettesYuCSEL,     0x390BE0,    0x840 },
      { L"data\\char\\char_yk_pal.pac",    L"Yukari Takeba",                  282672,    &Persona4PalettesYukari,     0x3040,      0x2100 },
      { L"data\\ETC\\CHSLDotV.pac",        L"Yukari Takeba (CharaSelect)",    19190960,  &Persona4PalettesYukariCSEL, 0x10C4CD0,   0x840 },
      { L"data\\char\\char_yu_pal.pac",    L"Yukiko Amagi",                   282672,    &Persona4PalettesYukiko,     0x3040,      0x2100 },
      { L"data\\ETC\\CHSLDotV.pac",        L"Yukiko Amagi (CharaSelect)",     19190960,  &Persona4PalettesYukikoCSEL, 0x123CCC0,   0x840 },

    //Unknown, doesnt follow the same format as other characters
    //{ L"char_e0_pal.pac",    L"Unknown?",           13280,     Persona4Names,    ARRAYSIZE(Persona4Names), 0x280,  0x0 },
} };
