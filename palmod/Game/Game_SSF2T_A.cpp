#include "StdAfx.h"
#include "Game_SSF2T_A.h"

CGame_SSF2T_A::SSF2TLoadingKey CGame_SSF2T_A::m_eVersionToLoad = SSF2TLoadingKey::ROM03;

void CGame_SSF2T_A::SetSpecialRuleForFileName(std::wstring strFileName)
{
    const std::map<std::wstring, SSF2TLoadingKey> m_rgFileNameToVersion =
    {
        { L"sfxe.03c", SSF2TLoadingKey::ROM03 },
        { L"sfxe.04a", SSF2TLoadingKey::ROM04 },
        { L"sfxe.08", SSF2TLoadingKey::ROM08 },
        { L"sfxa.03c", SSF2TLoadingKey::ROM03 },
        { L"sfxa.04a", SSF2TLoadingKey::ROM04 },
        { L"sfxa.08", SSF2TLoadingKey::ROM08 },
        { L"sfxh.03c", SSF2TLoadingKey::ROM03 },
        { L"sfxh.04a", SSF2TLoadingKey::ROM04 },
        { L"sfxh.08", SSF2TLoadingKey::ROM08 },
        { L"sfxu.03e", SSF2TLoadingKey::ROM03 },
        { L"sfxu.03c", SSF2TLoadingKey::ROM03 },
        { L"sfxu.04a", SSF2TLoadingKey::ROM04 },
        { L"sfxu.08", SSF2TLoadingKey::ROM08 },
        { L"sfxj.03c", SSF2TLoadingKey::ROM03 },
        { L"sfxj.04a", SSF2TLoadingKey::ROM04 },
        { L"sfxj.08", SSF2TLoadingKey::ROM08 },
        { L"sfxad.03c", SSF2TLoadingKey::ROM03 },
        { L"sfxad.04a", SSF2TLoadingKey::ROM04 },
        { L"sfxad.08", SSF2TLoadingKey::ROM08 },
    };

    CString strFileNameLowerCase = strFileName.c_str();
    strFileNameLowerCase.MakeLower();

    auto result = m_rgFileNameToVersion.find(strFileNameLowerCase.GetString());

    if (result != m_rgFileNameToVersion.end())
    {
        m_eVersionToLoad = result->second;
    }
    else
    {
        m_eVersionToLoad = SSF2TLoadingKey::ROM03;
}

    return;
}

CGame_SSF2T_A::CGame_SSF2T_A(uint32_t nConfirmedROMSize)
{
    switch (m_eVersionToLoad)
    {
    case SSF2TLoadingKey::ROM03:
    default:
        InitializeGame(nConfirmedROMSize, m_sCoreGameData_ROM03);
        break;
    case SSF2TLoadingKey::ROM04:
        InitializeGame(nConfirmedROMSize, m_sCoreGameData_ROM04);
        break;
    case SSF2TLoadingKey::ROM08:
        InitializeGame(nConfirmedROMSize, m_sCoreGameData_ROM08);
        break;
    }
}

sFileRule CGame_SSF2T_A::GetRule(uint32_t nRuleId)
{
    switch (m_eVersionToLoad)
    {
    case SSF2TLoadingKey::ROM03:
    default:
        return CGameClassByDir::GetRule(nRuleId, m_sFileLoadingData_ROM03);
    case SSF2TLoadingKey::ROM04:
        return CGameClassByDir::GetRule(nRuleId, m_sFileLoadingData_ROM04);
    case SSF2TLoadingKey::ROM08:
        return CGameClassByDir::GetRule(nRuleId, m_sFileLoadingData_ROM08);
    }
}

uint32_t CGame_SSF2T_A::GetKnownCRC32DatasetsForGame(const sCRC32ValueSet** ppKnownROMSet, bool* pfNeedToValidateCRCs)
{
    static sCRC32ValueSet knownROMs[] =
    {
#ifdef MAME_NOTES
      we care about 03 and 04
GAME(1994, ssf2t,      0,        cps2, cps2_2p6b, cps2_state, init_cps2,     ROT0,   "Capcom", "Super Street Fighter II Turbo (World 940223)", MACHINE_SUPPORTS_SAVE)
    ROM_LOAD16_WORD_SWAP("sfxe.03c", 0x000000, 0x80000, CRC(2fa1f396) SHA1(2aa58309811f34901554b84396556630a22ce9bc))
    ROM_LOAD16_WORD_SWAP("sfxe.04a", 0x080000, 0x80000, CRC(d0bc29c6) SHA1(d9f89bcd79cba26db2100a00dd7bd8ee6ecb75f3))
    ROM_LOAD16_WORD_SWAP("sfxe.08",  0x280000, 0x80000, CRC(74c24062) SHA1(f3eca09e0544c6aa46b0c4bead2246ab1e9a97d9))
GAME(1994, ssf2ta,     ssf2t,    cps2, cps2_2p6b, cps2_state, init_cps2,     ROT0,   "Capcom", "Super Street Fighter II Turbo (Asia 940223)", MACHINE_SUPPORTS_SAVE)
    ROM_LOAD16_WORD_SWAP("sfxa.03c", 0x000000, 0x80000, CRC(04b9ff34) SHA1(69feb2c9c03634e6f964dae310d7b72b4c76140d))
    ROM_LOAD16_WORD_SWAP("sfxa.04a", 0x080000, 0x80000, CRC(16ea5f7a) SHA1(08404c6a79b9a36eceb06e0d3e1d747a21fac186))
    ROM_LOAD16_WORD_SWAP("sfxa.08",  0x280000, 0x80000, CRC(39be596c) SHA1(f7ab80e64cbb703535dd39b875273eefa57df489))
GAME(1994, ssf2th,     ssf2t,    cps2, cps2_2p6b, cps2_state, init_cps2,     ROT0,   "Capcom", "Super Street Fighter II Turbo (Hispanic 940223)", MACHINE_SUPPORTS_SAVE)
    ROM_LOAD16_WORD_SWAP("sfxh.03c", 0x000000, 0x80000, CRC(fbe80dfe) SHA1(b9c5f0a0f6ae7839e348c870ac87b16dbb665bd9))
    ROM_LOAD16_WORD_SWAP("sfxh.04a", 0x080000, 0x80000, CRC(ef9dd4b1) SHA1(3c5d76e6ae7db91f9287f341c32e3b7a75e256f6))
    ROM_LOAD16_WORD_SWAP("sfxh.08",  0x280000, 0x80000, CRC(c15f0424) SHA1(de9f7075f02653c4edef0e6f4a1210a9b2711d28))
GAME(1994, ssf2tu,     ssf2t,    cps2, cps2_2p6b, cps2_state, init_cps2,     ROT0,   "Capcom", "Super Street Fighter II Turbo (USA 940323)", MACHINE_SUPPORTS_SAVE)
    ROM_LOAD16_WORD_SWAP("sfxu.03e", 0x000000, 0x80000, CRC(d6ff689e) SHA1(bea1a8aafbbbe9cb0895561a57dead1579361a8e))
    ROM_LOAD16_WORD_SWAP("sfxu.04a", 0x080000, 0x80000, CRC(532b5ffd) SHA1(769a8a9d4e04e291ce7427b89e537bba2258ca82))
    ROM_LOAD16_WORD_SWAP("sfxu.08",  0x280000, 0x80000, CRC(b3c71810) SHA1(b51515f4f4aee5bbbfc8b79372d0bc6e0c140912))
GAME(1994, ssf2tur1,   ssf2t,    cps2, cps2_2p6b, cps2_state, init_cps2,     ROT0,   "Capcom", "Super Street Fighter II Turbo (USA 940223)", MACHINE_SUPPORTS_SAVE)
    ROM_LOAD16_WORD_SWAP("sfxu.03c", 0x000000, 0x80000, CRC(86e4a335) SHA1(04db3fd519973aeb7b32be62871e0fb4605946eb))
    ROM_LOAD16_WORD_SWAP("sfxu.04a", 0x080000, 0x80000, CRC(532b5ffd) SHA1(769a8a9d4e04e291ce7427b89e537bba2258ca82))
    ROM_LOAD16_WORD_SWAP("sfxu.08",  0x280000, 0x80000, CRC(b3c71810) SHA1(b51515f4f4aee5bbbfc8b79372d0bc6e0c140912))

GAME(1994, ssf2xj,     ssf2t,    cps2, cps2_2p6b, cps2_state, init_cps2,     ROT0,   "Capcom", "Super Street Fighter II X: Grand Master Challenge (Japan 940311)", MACHINE_SUPPORTS_SAVE)
    ROM_LOAD16_WORD_SWAP("sfxj.03d", 0x000000, 0x80000, CRC(50b52b37) SHA1(dc0330fcbffbc0077faa20d34a28d6a49b04639e))
    ROM_LOAD16_WORD_SWAP("sfxj.04a", 0x080000, 0x80000, CRC(af7767b4) SHA1(61e7364408bf07c01634913c112b6245acce48ab))
    ROM_LOAD16_WORD_SWAP("sfxj.08",  0x280000, 0x80000, CRC(2de76f10) SHA1(8cbe96dfeaa41306caa2819b82272ce3b0b9f926))
GAME(1994, ssf2xjr1,   ssf2t,    cps2, cps2_2p6b, cps2_state, init_cps2,     ROT0,   "Capcom", "Super Street Fighter II X: Grand Master Challenge (Japan 940223)", MACHINE_SUPPORTS_SAVE)
    ROM_LOAD16_WORD_SWAP("sfxj.03c", 0x000000, 0x80000, CRC(a7417b79) SHA1(189c3ed546bb2844e9fa9fe7e9aacef728bc8939))
    ROM_LOAD16_WORD_SWAP("sfxj.04a", 0x080000, 0x80000, CRC(af7767b4) SHA1(61e7364408bf07c01634913c112b6245acce48ab))
    ROM_LOAD16_WORD_SWAP("sfxj.08",  0x280000, 0x80000, CRC(2de76f10) SHA1(8cbe96dfeaa41306caa2819b82272ce3b0b9f926))
GAME(1994, ssf2xjr1r,  ssf2t,    cps2, cps2_2p6b, cps2_state, init_cps2,     ROT0,   "Capcom", "Super Street Fighter II X: Grand Master Challenge (Japan 940223 rent version)", MACHINE_SUPPORTS_SAVE)
    ROM_LOAD16_WORD_SWAP("sfxo.03c", 0x000000, 0x80000, CRC(2ba33dc6) SHA1(ab31046c1604eae30e55eb0e03804c98765d578e))
    ROM_LOAD16_WORD_SWAP("sfxo.04a", 0x080000, 0x80000, CRC(ba663dd7) SHA1(46baf0a48e4fd807098aa48e34625964b279a223))
    ROM_LOAD16_WORD_SWAP("sfxo.08",  0x280000, 0x80000, CRC(b60f4b58) SHA1(1db3876daef85713a22dbc42f76a26a47fa26079))

GAME(1994, ssf2tad,    ssf2t,    dead_cps2, cps2_2p6b, cps2_state, init_cps2,     ROT0,   "bootleg", "Super Street Fighter II Turbo (Asia 940223 Phoenix Edition) (bootleg)", MACHINE_SUPPORTS_SAVE)
    ROM_LOAD16_WORD_SWAP("sfxad.03c", 0x000000, 0x80000, CRC(e3c92ece) SHA1(8b0d6f632f51719c3e13add5d27701578b6ce0d6))
    ROM_LOAD16_WORD_SWAP("sfxad.04a", 0x080000, 0x80000, CRC(9bf3bb2e) SHA1(4bdc6fa585cc67d3b6695f390c95c518cba2bea6))
    ROM_LOAD16_WORD_SWAP("sfxad.08",  0x280000, 0x80000, CRC(d399c36c) SHA1(b4c4217843e5c3ef00ab04d58ca9368d2d734065))

#endif
        { L"SSF2T (CPS2 World 940223 03)", L"sfxe.03c", 0x2fa1f396, 0 },
        { L"SSF2T (CPS2 World 940223 04)", L"sfxe.04a", 0xd0bc29c6, 0 },
        { L"SSF2T (CPS2 World 940223 08)", L"sfxe.08", 0x74c24062, 0 },
        { L"SSF2T (CPS2 Asia 940223 03)", L"sfxa.03c", 0x04b9ff34, 0 },
        { L"SSF2T (CPS2 Asia 940223 04)", L"sfxa.04a", 0x16ea5f7a, 0 },
        { L"SSF2T (CPS2 Asia 940223 08)", L"sfxa.08", 0x39be596c, 0 },
        { L"SSF2T (CPS2 Hispanic 940223 03)", L"sfxh.03c", 0xfbe80dfe, 0 },
        { L"SSF2T (CPS2 Hispanic 940223 04)", L"sfxh.04a", 0xef9dd4b1, 0 },
        { L"SSF2T (CPS2 Hispanic 940223 08)", L"sfxh.08", 0xc15f0424, 0 },
        { L"SSF2T (CPS2 USA 940223 03)", L"sfxu.03e", 0xd6ff689e, 0 },
        { L"SSF2T (CPS2 USA 940223 03)", L"sfxu.03c", 0x86e4a335, 0 },
        { L"SSF2T (CPS2 USA 940223 04)", L"sfxu.04a", 0x532b5ffd, 0 },
        { L"SSF2T (CPS2 USA 940223 08)", L"sfxu.08", 0xb3c71810, 0 },

        { L"SSF2X:GMC (CPS2 Japan 03)", L"sfxj.03c", 0xa7417b79, 0 },
        { L"SSF2X:GMC (CPS2 Japan 04)", L"sfxj.04a", 0xaf7767b4, 0 },
        { L"SSF2X:GMC (CPS2 Japan 08)", L"sfxj.08", 0x2de76f10, 0 },

        { L"SSF2T (CPS2 Asia 940223 bootleg 03)", L"sfxad.03c", 0xe3c92ece, 0 },
        { L"SSF2T (CPS2 Asia 940223 bootleg 04)", L"sfxad.04a", 0x9bf3bb2e, 0 },
        { L"SSF2T (CPS2 Asia 940223 bootleg 08)", L"sfxad.08", 0xd399c36c, 0 },
    };

    if (ppKnownROMSet)
    {
        *ppKnownROMSet = knownROMs;
    }

    if (pfNeedToValidateCRCs)
    {
        // Each filename is associated with a single CRC
        *pfNeedToValidateCRCs = false;
    }

    return ARRAYSIZE(knownROMs);
}
