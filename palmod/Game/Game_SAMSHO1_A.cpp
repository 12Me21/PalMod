#include "StdAfx.h"
#include "Game_SAMSHO1_A.h"

CGame_SAMSHO1_A::SamSho1LoadingKey CGame_SAMSHO1_A::m_eROMToLoad = SamSho1LoadingKey::NeoGeo;

void CGame_SAMSHO1_A::SetSpecialRuleForFileName(std::wstring strFileName)
{
    const std::map<std::wstring, SamSho1LoadingKey> m_rgFileNameToVersion =
    {
        // these should be all lower case
        { L"045-p1.p1", SamSho1LoadingKey::NeoGeo },
        { L"045-p1.bin", SamSho1LoadingKey::NeoGeo },
        { L"045-p2.rom", SamSho1LoadingKey::NeoStation },
    };

    CString strFileNameLowerCase = strFileName.c_str();
    strFileNameLowerCase.MakeLower();

    auto result = m_rgFileNameToVersion.find(strFileNameLowerCase.GetString());

    if (result != m_rgFileNameToVersion.end())
    {
        m_eROMToLoad = result->second;
    }
    else
    {
        m_eROMToLoad = SamSho1LoadingKey::NeoGeo;
    }

    return;
}

sFileRule CGame_SAMSHO1_A::GetRule(uint32_t nRuleId)
{
    switch (m_eROMToLoad)
    {
    case SamSho1LoadingKey::NeoGeo:
        return CGameClassByDir::GetRule(nRuleId, m_sFileLoadingData_NeoGeo);
    case SamSho1LoadingKey::NeoStation:
    default:
        return CGameClassByDir::GetRule(nRuleId, m_sFileLoadingData_NeoStation);
    }
}

CGame_SAMSHO1_A::CGame_SAMSHO1_A(uint32_t nConfirmedROMSize)
{
    switch (m_eROMToLoad)
    {
    case SamSho1LoadingKey::NeoGeo:
        InitializeGame(nConfirmedROMSize, m_sCoreGameData_NeoGeo);
        break;
    case SamSho1LoadingKey::NeoStation:
    default:
        InitializeGame(nConfirmedROMSize, m_sCoreGameData_NeoStation);
        break;
    }
}

uint32_t CGame_SAMSHO1_A::GetKnownCRC32DatasetsForGame(const sCRC32ValueSet** ppKnownROMSet, bool* pfNeedToValidateCRCs)
{
    static sCRC32ValueSet knownROMs[] =
    {
        { L"Samurai Shodown (Neo-Geo)", L"045-p1.p1", 0xdfe51bf0, 0 },
        { L"Samurai Shodown (Neo-Geo Station)", L"045-p2.rom", 0x71768728, -0x80000 },
    };

    if (ppKnownROMSet != nullptr)
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
