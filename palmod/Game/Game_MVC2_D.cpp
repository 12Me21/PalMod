#include "StdAfx.h"
#include "Gamedef.h"
#include "Game_MVC2_D.h"
#include "MVC2_A_DEF.h"
#include "mvc2_validate.h"
#include "MVC2_SUPP.h"
#include "mvc2_descs.h"
#include "..\PalMod.h"

#define MV2C_D_DEBUG DEFAULT_GAME_DEBUG_STATE

// TODO: Clean up this / use of statics once the code gets more fleshed out/finished
uint8_t k_mvc2_character_coloroption_count = 6;

// ID_MOD is 47: (button_colors * palettes_per_button) - 1 (zero-based)
uint16_t ID_MOD = ((k_mvc2_character_coloroption_count * 8) - 1); // Index mod - this is also EXTRA_OMNI for MvC2 only
// Extras for a character are located at an zero-based offset of (6 colors * 8 base palettes)
uint32_t EXTRA_OMNI = ID_MOD; //  (8 * 6) - 1;

uint8_t CGame_MVC2_D::_nCurrentTotalColorOptions = 6;

std::vector<LPCWSTR> CGame_MVC2_D::pCurrentButtonLabelSet = DEF_BUTTONLABEL6_MVC2;
std::vector<std::vector<sMoveDescription>>  CGame_MVC2_D::pCurrentMoveDescriptions = MVC2_6COLOR_MOVE_DESCRIPTIONS;
std::vector<uint16_t> CGame_MVC2_D::pCurrentExtrasLayout = MVC2_D_6COLORS_EXTRADEF;

//Initialize the selection tree
CDescTree CGame_MVC2_D::MainDescTree = nullptr;

uint32_t CGame_MVC2_D::uRuleCtr = 0;

uint32_t CGame_MVC2_D::rgExtraChrLoc[MVC2_D_NUMUNIT_WITH_TEAMVIEW];

void CGame_MVC2_D::InitializeStatics()
{
    MainDescTree.SetRootTree(CGame_MVC2_D::InitDescTree());
}

void CGame_MVC2_D::SetNumberOfColorOptions(uint8_t nColorOptions)
{
    switch (nColorOptions)
    {
    default:
    case 6:
        _nCurrentTotalColorOptions = 6;
        k_mvc2_character_coloroption_count = 6;
        pCurrentButtonLabelSet = pButtonLabelSet = DEF_BUTTONLABEL6_MVC2;
        pCurrentMoveDescriptions = MVC2_6COLOR_MOVE_DESCRIPTIONS;
        pCurrentExtrasLayout = MVC2_D_6COLORS_EXTRADEF;
        break;

    case 16:
        _nCurrentTotalColorOptions = 16;
        k_mvc2_character_coloroption_count = 16;
        pCurrentButtonLabelSet = pButtonLabelSet = DEF_BUTTONLABEL16_MVC2;
        pCurrentMoveDescriptions = MVC2_16COLOR_MOVE_DESCRIPTIONS;
        pCurrentExtrasLayout = MVC2_D_16COLORS_EXTRADEF;
        break;
    }

    // Reset these, as they need to be (button_colors * palettes_per_button) - 1 (zero-based)
    ID_MOD = ((k_mvc2_character_coloroption_count * 8) - 1);
    EXTRA_OMNI = ID_MOD;
}

CGame_MVC2_D::CGame_MVC2_D(uint32_t nConfirmedROMSize)
{
    //Set color mode
    createPalOptions = { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_MAX };
    SetAlphaMode(AlphaMode::GameUsesVariableAlpha);
    SetColorMode(ColMode::COLMODE_RGB444_BE);

    //Set the image out display type
    DisplayType = eImageOutputSpriteDisplay::DISPLAY_SPRITES_TOPTOBOTTOM;

    {
        sFileRule FirstRuleOfMVC2Club = GetRule(0);
        if (nConfirmedROMSize == FirstRuleOfMVC2Club.uAltVerifyVar)
        {
            SetNumberOfColorOptions(16);
            nGameFlag = MVC2_D_16;
        }
        else
        {
            SetNumberOfColorOptions(6);
            nGameFlag = MVC2_D;
        }
    }
   
    InitializeStatics();

    // InitDataBuffer uses this value so make sure to set first
    nUnitAmt = MVC2_D_NUMUNIT_WITH_TEAMVIEW;

    InitDataBuffer();

    //Set game information
    nImgGameFlag = IMGDAT_SECTION_CPS2;
    m_prgGameImageSet = MVC2_IMGIDS_USED;

    m_fGameUsesAlphaValue = true;

    nFileAmt = MVC2_D_NUMUNIT_WITH_TEAMVIEW;

    //Prepare the file list
    PrepChangeTrackingArray();
    // the DC and PS2 games use one file per character/unit: we can handle those slightly differently
    m_fGameUnitsMapToIndividualFiles = TRUE;

    //Set the MVC2 supp game
    MVC2_SupplementProcessing::CurrMVC2 = this;
    MVC2_SupplementProcessing::CurrMVC2_Arcade = nullptr;
    //Prepare it
    MVC2_SupplementProcessing::prep_supp();

    //Create the redirect buffer
    m_rgUnitRedir.resize(nUnitAmt, 0);
}

CGame_MVC2_D::~CGame_MVC2_D()
{
    FlushChangeTrackingArray();
    ClearDataBuffer();

    MVC2_SupplementProcessing::CurrMVC2 = nullptr;
}

CDescTree* CGame_MVC2_D::GetMainTree()
{
    return &CGame_MVC2_D::MainDescTree;
}

sDescTreeNode* CGame_MVC2_D::InitDescTree()
{
    //Initialize extra range
    InitExtraRg();

    sDescTreeNode* NewDescTree = new sDescTreeNode;

    //Create the main character tree
    _snwprintf_s(NewDescTree->szDesc, ARRAYSIZE(NewDescTree->szDesc), _TRUNCATE, L"%s", g_GameFriendlyName[MVC2_D]);
    NewDescTree->ChildNodes = new sDescTreeNode[MVC2_D_NUMUNIT_WITH_TEAMVIEW];
    NewDescTree->uChildAmt = MVC2_D_NUMUNIT_WITH_TEAMVIEW;
    //All units have tree children
    NewDescTree->uChildType = DESC_NODETYPE_TREE;

    CString strMsg;
    strMsg.Format(L"CGame_MVC2_D::InitDescTree: Building desc tree for MVC2_D...\n");
    OutputDebugString(strMsg);

    //Go through each character
    for (int iUnitCtr = 0; iUnitCtr < MVC2_D_NUMUNIT; iUnitCtr++)
    {
        //Omni extra count
        int nNumSharedExtras = CountExtraRg(iUnitCtr, TRUE);

        sDescTreeNode* UnitNode = nullptr;
        sDescTreeNode* ButtonNode = nullptr;
        sDescNode* ChildNode = nullptr;

        UnitNode = &((sDescTreeNode*)NewDescTree->ChildNodes)[iUnitCtr];
        //Set each description
        _snwprintf_s(UnitNode->szDesc, ARRAYSIZE(UnitNode->szDesc), _TRUNCATE, L"%s", MVC2_D_UNITDESC[iUnitCtr]);

        //Init each character to have all 6 basic buttons + extra
        UnitNode->ChildNodes = new sDescTreeNode[pCurrentButtonLabelSet.size() + (nNumSharedExtras ? 1 : 0)];

        //All children have button trees
        UnitNode->uChildType = DESC_NODETYPE_TREE;
        UnitNode->uChildAmt = static_cast<uint32_t>(pCurrentButtonLabelSet.size()) + (nNumSharedExtras ? 1 : 0);

        //Set each button data
        const int nButtonExtraCt = CountExtraRg(iUnitCtr, FALSE) + 1;

#if MV2C_D_DEBUG
        strMsg.Format(L"Unit: \"%s\", %u of %u, %u total children\n", UnitNode->szDesc, iUnitCtr + 1, MVC2_D_NUMUNIT_WITH_TEAMVIEW, UnitNode->uChildAmt);
        OutputDebugString(strMsg);
#endif

        for (uint32_t iButtonCtr = 0; iButtonCtr < pCurrentButtonLabelSet.size(); iButtonCtr++)
        {
            int nExtraPos = 0;

            ButtonNode = &((sDescTreeNode*)UnitNode->ChildNodes)[iButtonCtr];

            //Set each button data
            _snwprintf_s(ButtonNode->szDesc, ARRAYSIZE(ButtonNode->szDesc), _TRUNCATE, L"%s", pCurrentButtonLabelSet[iButtonCtr]);

            //Button children have nodes
            ButtonNode->uChildType = DESC_NODETYPE_NODE;
            ButtonNode->uChildAmt = nButtonExtraCt;

            ButtonNode->ChildNodes = (sDescTreeNode*)new sDescNode[nButtonExtraCt];

            //Start of the basic extra node in the current character
            int nBasicStart = 0;

            if (rgExtraChrLoc[iUnitCtr])
            {
                nBasicStart = rgExtraChrLoc[iUnitCtr] + 1;
            }

            const int nButtonExtraTotal = 8;

#if MV2C_D_DEBUG
            strMsg.Format(L"\t\"%s\" Collection: \"%s\", %u of %u, %u children\n", UnitNode->szDesc, ButtonNode->szDesc, iButtonCtr + 1, UnitNode->uChildAmt, nButtonExtraTotal);
            OutputDebugString(strMsg);
#endif

            std::vector<sMoveDescription> CurrentMoveDescriptionSet = pCurrentMoveDescriptions[iUnitCtr];

            //Set each button's extra nodes
            for (uint32_t nButtonExtra = 0; nButtonExtra < nButtonExtraTotal; nButtonExtra++)
            {
                BOOL fSetInfo = false;
                ChildNode = &((sDescNode*)ButtonNode->ChildNodes)[nExtraPos];

                for (uint32_t nDescriptionLookup = 0; nDescriptionLookup < CurrentMoveDescriptionSet.size(); nDescriptionLookup++)
                {
                    if (CurrentMoveDescriptionSet[nDescriptionLookup].nCharacterIndex == nButtonExtra)
                    {
                        //_snwprintf(ChildNode->szDesc, ARRAYSIZE(ChildNode->szDesc), L"%s %s", pCurrentButtonLabelSet[iButtonCtr], CurrentMoveDescriptionSet.pMoveDescriptions[nDescriptionLookup].szMoveName);
                        // We can skip the button label since the second combo box already has that information
                        _snwprintf(ChildNode->szDesc, ARRAYSIZE(ChildNode->szDesc), L"%s", CurrentMoveDescriptionSet[nDescriptionLookup].szMoveName);
                        ChildNode->szDesc[ARRAYSIZE(ChildNode->szDesc) - 1] = 0;
                        fSetInfo = true;
                        break;
                    }
                }

                if (!fSetInfo)
                {
                    if (nButtonExtra == 0)
                    {
                        _snwprintf_s(ChildNode->szDesc, ARRAYSIZE(ChildNode->szDesc), _TRUNCATE, L"%s Main", pCurrentButtonLabelSet[iButtonCtr]);
                        fSetInfo = true;
                    }
                    else if (!nBasicStart || 1)//MVC2_D_6COLORS_EXTRADEF[nBasicStart + (nButtonExtra - 1)])
                    {
                        _snwprintf_s(ChildNode->szDesc, ARRAYSIZE(ChildNode->szDesc), _TRUNCATE, L"%02X %s (Extra - %02X)", nExtraPos, pCurrentButtonLabelSet[iButtonCtr],
                            (iButtonCtr * nButtonExtraTotal) + nExtraPos + 1);

                        fSetInfo = true;
                    }
                }

                if (fSetInfo)
                {
                    ChildNode->uUnitId = iUnitCtr;
                    ChildNode->uPalId = (iButtonCtr * 8) + nExtraPos;

                    nExtraPos++;
                }

#if MV2C_D_DEBUG
                strMsg.Format(L"\t\tPalette: \"%s\", %u of %u\n", ChildNode->szDesc, nButtonExtra + 1, nButtonExtraTotal);
                OutputDebugString(strMsg);
#endif
            }
        }

        //Set extra data
        if (nNumSharedExtras)
        {
            const int nExtraNodeIndex = _nCurrentTotalColorOptions;
            ButtonNode = &((sDescTreeNode*)UnitNode->ChildNodes)[nExtraNodeIndex]; //Extra data node
            wcscpy(ButtonNode->szDesc, L"Extras");
            ButtonNode->uChildAmt = nNumSharedExtras;
            ButtonNode->uChildType = DESC_NODETYPE_NODE;

            ButtonNode->ChildNodes = (sDescTreeNode*)(new sDescTreeNode[nNumSharedExtras]);

#if MV2C_D_DEBUG
            strMsg.Format(L"\t\"%s\" Extra Data Collection: \"%s\", %u of %u, %u children\n", UnitNode->szDesc, ButtonNode->szDesc, nExtraNodeIndex, UnitNode->uChildAmt, nNumExtra);
            OutputDebugString(strMsg);
#endif

            bool fNoDescriptionAvailable;

            if (_nCurrentTotalColorOptions == 6)
            {
                fNoDescriptionAvailable = (nNumSharedExtras == (MVC2_D_PALDATASIZE_6COLORS[iUnitCtr] - (8 * k_mvc2_character_coloroption_count * 32)) / 32);
            }
            else
            {
                fNoDescriptionAvailable = (nNumSharedExtras == (MVC2_D_PALDATASIZE_16COLORS[iUnitCtr] - (8 * k_mvc2_character_coloroption_count * 32)) / 32);
            }

            if (fNoDescriptionAvailable)
            {
                // This path is used for Akuma/Gouki and War Machine only.
                // We don't have extended descriptions for these: instead of using MVC2_MOVE_DESCRIPTIONS just use the old defaults
                for (int nExtraCtr = 0; nExtraCtr < nNumSharedExtras; nExtraCtr++)
                {
                    ChildNode = &((sDescNode*)ButtonNode->ChildNodes)[nExtraCtr];

                    _snwprintf_s(ChildNode->szDesc, ARRAYSIZE(ChildNode->szDesc), _TRUNCATE, L"(%02X Extra)", nExtraCtr + 1);

                    ChildNode->uUnitId = iUnitCtr;
                    ChildNode->uPalId = (8 * k_mvc2_character_coloroption_count) + nExtraCtr;

#if MV2C_D_DEBUG
                    strMsg.Format(L"\t\tPalette: \"%s\", %u of %u\n", ChildNode->szDesc, nExtraCtr + 1, nNumExtra);
                    OutputDebugString(strMsg);
#endif
                }
            }
            else
            {
                int nExtraIndex = rgExtraChrLoc[iUnitCtr] + 1 + 7;
                int nExtraCtr = 0;
                int nRangeAmt = 0;

                uint16_t* pCurrVal = const_cast<uint16_t*>(&pCurrentExtrasLayout[nExtraIndex]);
                std::vector<sMoveDescription> CurrentMoveDescriptionSet = pCurrentMoveDescriptions[iUnitCtr];

                while ((pCurrVal[0] & 0x0F00) != EXTRA_START)
                {
                    nRangeAmt = (pCurrVal[1] + 1) - pCurrVal[0];

                    for (int nRangeCtr = 0; nRangeCtr < nRangeAmt; nRangeCtr++)
                    {
                        bool fSetInfo = false;
                        const uint16_t nCurrentExtraValue = pCurrVal[0] + nRangeCtr;

                        ChildNode = &((sDescNode*)ButtonNode->ChildNodes)[nExtraCtr];

                        for (uint32_t nDescriptionLookup = 0; nDescriptionLookup < CurrentMoveDescriptionSet.size(); nDescriptionLookup++)
                        {
                            if (CurrentMoveDescriptionSet[nDescriptionLookup].nCharacterIndex == nCurrentExtraValue)
                            {
                                _snwprintf(ChildNode->szDesc, ARRAYSIZE(ChildNode->szDesc), L"%02X: %s", nCurrentExtraValue, CurrentMoveDescriptionSet[nDescriptionLookup].szMoveName);
                                ChildNode->szDesc[ARRAYSIZE(ChildNode->szDesc) - 1] = 0;
                                fSetInfo = true;
                                break;
                            }
                        }

                        if (!fSetInfo)
                        {
                            _snwprintf_s(ChildNode->szDesc, ARRAYSIZE(ChildNode->szDesc), _TRUNCATE, L"(%02X Extra)", nCurrentExtraValue);
                        }

                        ChildNode->uUnitId = iUnitCtr;
                        ChildNode->uPalId = (8 * k_mvc2_character_coloroption_count) + nCurrentExtraValue - 1;

                        nExtraCtr++;

#if MV2C_D_DEBUG
                        strMsg.Format(L"\t\tPalette: \"%s\", %u of %u\n", ChildNode->szDesc, nExtraCtr, nNumExtra);
                        OutputDebugString(strMsg);
#endif

                    }

                    nExtraIndex += 2;

                    pCurrVal = const_cast<uint16_t*>(&pCurrentExtrasLayout[nExtraIndex]);
                }
            }
        }
    }

    // Now add team view...
    {
        sDescTreeNode* UnitNode = nullptr;
        sDescTreeNode* TeamNode = nullptr;
        sDescNode* ChildNode = nullptr;
        const uint32_t iUnitCtr = MVC2_D_TEAMVIEW_LOCATION; // Team view location

        UnitNode = &((sDescTreeNode*)NewDescTree->ChildNodes)[iUnitCtr];

        //Set each description
        _snwprintf_s(UnitNode->szDesc, ARRAYSIZE(UnitNode->szDesc), _TRUNCATE, L"%s", MVC2_D_UNITDESC[iUnitCtr]);

        const uint32_t nTeamCount = ARRAYSIZE(mvc2TeamList);
        const uint32_t nColorOptionCount = static_cast<uint32_t>(pCurrentButtonLabelSet.size());
        UnitNode->ChildNodes = new sDescTreeNode[nTeamCount];
        UnitNode->uChildType = DESC_NODETYPE_TREE;
        UnitNode->uChildAmt = nTeamCount;

#if MV2C_D_DEBUG
        strMsg.Format(L"Unit: \"%s\", %u of %u, %u total children\n", UnitNode->szDesc, iUnitCtr + 1, MVC2_D_NUMUNIT_WITH_TEAMVIEW, UnitNode->uChildAmt);
        OutputDebugString(strMsg);
#endif

        for (uint32_t iTeamIndex = 0; iTeamIndex < nTeamCount; iTeamIndex++)
        {
            TeamNode = &((sDescTreeNode*)UnitNode->ChildNodes)[iTeamIndex];

            // Define each team's data
            TeamNode->uChildType = DESC_NODETYPE_NODE;
            TeamNode->uChildAmt = nColorOptionCount;
            TeamNode->ChildNodes = (sDescTreeNode*)new sDescNode[nColorOptionCount];
            _snwprintf_s(TeamNode->szDesc, ARRAYSIZE(TeamNode->szDesc), _TRUNCATE, L"%s", mvc2TeamList[iTeamIndex].pszTeamName);

#if MV2C_D_DEBUG
            strMsg.Format(L"\t\"%s\" Collection: \"%s\", %u of %u, %u children\n", UnitNode->szDesc, TeamNode->szDesc, iTeamIndex + 1, UnitNode->uChildAmt, nColorOptionCount);
            OutputDebugString(strMsg);
#endif

            //Set each team's button options
            for (uint32_t iColorOption = 0; iColorOption < nColorOptionCount; iColorOption++)
            {
                ChildNode = &((sDescNode*)TeamNode->ChildNodes)[iColorOption];
                ChildNode->uUnitId = iUnitCtr;
                ChildNode->uPalId = (iTeamIndex * nColorOptionCount) + iColorOption;
                _snwprintf(ChildNode->szDesc, ARRAYSIZE(ChildNode->szDesc), L"%s", pCurrentButtonLabelSet[iColorOption]);

#if MV2C_D_DEBUG
                strMsg.Format(L"\t\tPalette: \"%s\", %u of %u\n", ChildNode->szDesc, iColorOption + 1, nColorOptionCount);
                OutputDebugString(strMsg);
#endif
            }
        }
    }

    return NewDescTree;
}

// This updates rgExtraChrLoc so that each character entry points to the corresponding point within the extra layout array
// TODO: Rip this out and just give each character their own array to start with.
void CGame_MVC2_D::InitExtraRg()
{
    int i = 0;

    //Clear the extra buffer
    memset(CGame_MVC2_D::rgExtraChrLoc, 0, sizeof(uint32_t) * MVC2_D_NUMUNIT_WITH_TEAMVIEW);

    // Set up the 
    while (pCurrentExtrasLayout[i] != EXTRA_END)
    {
        if ((pCurrentExtrasLayout[i] & EXTRA_START) == EXTRA_START)
        {
            // This is associating each character's starting point in the EXTRADEF table to the corresponding index in rgExtraChrLoc.
            // So 0x0 is set to Ryu offset 0x0, then Ryu has eight extra slots available, then 0x1 is set to 0xa for 0x1 Gief,
            // 0x2 is set to 0x14 for 0x2 Guile, and so forth.  Look at MVC2_D_6COLORS_EXTRADEF and this should be easy to follow.
            rgExtraChrLoc[(pCurrentExtrasLayout[i] & 0x00FF)] = i;
            i += 8;
        }
        else
        {
            i++;
        }
    }
}

// Returns a count of the extra sprites available for a given unit/character
uint32_t CGame_MVC2_D::CountExtraRg(uint32_t nUnitId, BOOL fCountIsOfSharedExtras)
{
    //(MVC2_D_PALDATASZ[nUnitId] - (8 * k_mvc2_character_coloroption_count * 32)) / 32;
    if (!rgExtraChrLoc[nUnitId])
    {
        if (_nCurrentTotalColorOptions == 6)
        {
            return (fCountIsOfSharedExtras ? ((MVC2_D_PALDATASIZE_6COLORS[nUnitId] - (8 * k_mvc2_character_coloroption_count * 32)) / 32) : 7);
        }
        else
        {
            return (fCountIsOfSharedExtras ? ((MVC2_D_PALDATASIZE_16COLORS[nUnitId] - (8 * k_mvc2_character_coloroption_count * 32)) / 32) : 7);
        }
    }
    else
    {
        if (fCountIsOfSharedExtras)
        {
            int nStart = rgExtraChrLoc[nUnitId] + 1 + 7;  // Walk past the start token + the seven core extra palettes per button
            int nRetVal = 0;
            int i = 0;

            uint16_t* pCurrVal = const_cast<uint16_t*>(&pCurrentExtrasLayout[nStart]);

            if (pCurrVal[0] == 0x00)
            {
                return 0;
            }
            else
            {
                // We now walk the extra visibility sets until we hit EXTRA_START for the next character.
                // Each visibility setting is a two integer long set of "start, end"
                while ((pCurrVal[0] & EXTRA_START) != EXTRA_START)
                {
                    nRetVal += (pCurrVal[1] + 1) - pCurrVal[0];

                    i += 2;
                    pCurrVal = const_cast<uint16_t*>(&pCurrentExtrasLayout[nStart + i]);
                }

                if (!nRetVal)
                {
                    if (_nCurrentTotalColorOptions == 6)
                    {
                        return ((MVC2_D_PALDATASIZE_6COLORS[nUnitId] - (8 * k_mvc2_character_coloroption_count * 32)) / 32);
                    }
                    else
                    {
                        return ((MVC2_D_PALDATASIZE_16COLORS[nUnitId] - (8 * k_mvc2_character_coloroption_count * 32)) / 32);
                    }
                }

                return nRetVal;
            }
        }
        else
        {
            // There are seven extras for all core button colors
            return 7;
        }
    }

    return 0;
}

sFileRule CGame_MVC2_D::GetRule(uint32_t nMaskedUnsortedRuleId)
{
    sFileRule NewFileRule;

    const uint32_t nTrueUnsortedRuleId = (nMaskedUnsortedRuleId & RULE_COUNTER_DEMASK);

    if (nTrueUnsortedRuleId < MVC2_D_NUMUNIT_WITH_TEAMVIEW)
    {
        const uint32_t nRuleIdToUse = (nMaskedUnsortedRuleId & RULE_COUNTER_MASK) == RULE_COUNTER_MASK ? (nTrueUnsortedRuleId) : MVC2_D_UNITSORT[nTrueUnsortedRuleId];
        _snwprintf_s(NewFileRule.szFileName, ARRAYSIZE(NewFileRule.szFileName), _TRUNCATE, L"PL%02X_DAT.BIN", nRuleIdToUse);

        NewFileRule.uUnitId = nRuleIdToUse;
        NewFileRule.uVerifyVar = MVC2_D_FILESIZES_6COLORS[nRuleIdToUse];

        // Allow for the 16 color variant
        NewFileRule.fHasAltName = true;
        _snwprintf_s(NewFileRule.szAltFileName, ARRAYSIZE(NewFileRule.szAltFileName), _TRUNCATE, NewFileRule.szFileName);
        NewFileRule.uAltVerifyVar = MVC2_D_FILESIZES_16COLORS[nRuleIdToUse];
    }
    else
    {
        _snwprintf_s(NewFileRule.szFileName, ARRAYSIZE(NewFileRule.szFileName), _TRUNCATE, L"TeamViewIsNotReal-%02X", nMaskedUnsortedRuleId);

        NewFileRule.uUnitId = nMaskedUnsortedRuleId;
        NewFileRule.uVerifyVar = -1;
    }

    return NewFileRule;
}

sFileRule CGame_MVC2_D::GetNextRule()
{
    sFileRule NewFileRule = GetRule(uRuleCtr);

    uRuleCtr++;

    if (uRuleCtr >= MVC2_D_NUMUNIT_WITH_TEAMVIEW)
    {
        uRuleCtr = INVALID_UNIT_VALUE;
    }

    return NewFileRule;
}

void CGame_MVC2_D::InitDataBuffer()
{
    ppDataBuffer = new uint16_t * [nUnitAmt];
    memset(ppDataBuffer, NULL, sizeof(uint16_t*) * nUnitAmt);
}

void CGame_MVC2_D::ClearDataBuffer()
{
    if (ppDataBuffer)
    {
        for (uint32_t i = 0; i < nUnitAmt; i++)
        {
            safe_delete_array(ppDataBuffer[i]);
        }

        safe_delete_array(ppDataBuffer);
    }
}

uint32_t CGame_MVC2_D::GetBasicOffset(uint32_t nPalId)
{
    // Each character by default gets 6 buttons worth of 8 palettes.  
    if (nPalId >= (uint32_t)(8 * k_mvc2_character_coloroption_count))
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

BOOL CGame_MVC2_D::LoadFile(CFile* LoadedFile, uint32_t nUnitId)
{
    if (ppDataBuffer[nUnitId])
    {
        //Palette memory should always be NULL at this point
        return FALSE;
    }
    else
    {
        // Team view is a generated view not associated with a file: no need to load for it.
        if (nUnitId != MVC2_D_TEAMVIEW_LOCATION)
        {
            uint32_t nStart, nEnd;

            LoadedFile->Seek(0x08, CFile::begin);

            // These two location values represent the start of the palette data and the end of the palette data for the original PALs
            // For the 16 color variant, just ignore the second pointer: the palette data goes until the end of the file.
            LoadedFile->Read(&nStart, 0x04);
            LoadedFile->Read(&nEnd, 0x04);

            // 16color and 6color PAL files have different meanings for the second value, so fork our usage
            int nDataSz = 0;
            int nExpectedSize = 0;
            
            if (_nCurrentTotalColorOptions == 6)
            {
                nDataSz = (nEnd - nStart);
                nExpectedSize = MVC2_D_PALDATASIZE_6COLORS[nUnitId];
            }
            else
            {
                nDataSz = (int)(LoadedFile->GetLength() - nStart);
                nExpectedSize = MVC2_D_PALDATASIZE_16COLORS[nUnitId];
            }
            
            if (nDataSz != nExpectedSize)
            {
                CString strError;
                strError.Format(L"CGame_MVC2_D::LoadFile: Palette data size 0x%08x does not match with expected palette data size 0x%08x.  Failing file load for file ID 0x%02x.\n", nDataSz, nExpectedSize, nUnitId);
                OutputDebugString(strError);
                return FALSE;
            }

            ppDataBuffer[nUnitId] = new uint16_t[nDataSz / 2];

            LoadedFile->Seek(nStart, CFile::begin);

            LoadedFile->Read(ppDataBuffer[nUnitId], nDataSz);
        }

        //Set the redirect: this is sorted at runtime
        m_rgUnitRedir.at(nUnitId) = MVC2_D_UNITSORT[nUnitId];

        return TRUE;
    }
}

BOOL CGame_MVC2_D::SaveFile(CFile* SaveFile, uint32_t nUnitId)
{
    if (ppDataBuffer[nUnitId])
    {
        if (nUnitId != MVC2_D_TEAMVIEW_LOCATION)
        {
            uint32_t nStart, nEnd;

            SaveFile->Seek(0x08, CFile::begin);
            // These two location values represent the start of the palette data and the end of the palette data for the original PALs
            // For the 16 color variant, the second number represents the start of the palette data
            SaveFile->Read(&nStart, 0x04);
            SaveFile->Read(&nEnd, 0x04);

            // 16color and 6color PAL files have different meanings for the second value, so fork our usage
            int nDataSz = 0;

            if (_nCurrentTotalColorOptions == 6)
            {
                nDataSz = (nEnd - nStart);
            }
            else
            {
                nDataSz = (int)(SaveFile->GetLength() - nStart);
            }

            if (nStart > SaveFile->GetLength())
            {
                return FALSE;
            }

            SaveFile->Seek(nStart, CFile::begin);
            SaveFile->Write(ppDataBuffer[nUnitId], nDataSz);
        }

        return TRUE;
    }

    return FALSE;
}

COLORREF* CGame_MVC2_D::CreatePal(uint32_t nUnitId, uint32_t nPalId)
{
    //Create a new palette
    COLORREF* NewPal = new COLORREF[MVC2_D_PALSZ];

    for (uint16_t i = 0; i < MVC2_D_PALSZ; i++)
    {
        NewPal[i] = ConvPal16(ppDataBuffer[nUnitId][(nPalId * 16) + i]);
    }

    return NewPal;
}

void CGame_MVC2_D::CreateDefPal(sDescNode* srcNode, uint32_t nSepId)
{
    uint32_t nUnitId = srcNode->uUnitId;
    uint32_t nPalId = srcNode->uPalId;

    BasePalGroup.AddPal(CreatePal(nUnitId, nPalId), MVC2_D_PALSZ, nUnitId, nPalId);
    BasePalGroup.AddSep(nSepId, srcNode->szDesc, 0, MVC2_D_PALSZ);
}

void CGame_MVC2_D::UpdatePalData()
{
    for (uint16_t nPalCtr = 0; nPalCtr < MAX_PALETTES_DISPLAYABLE; nPalCtr++)
    {
        sPalDef* srcDef = BasePalGroup.GetPalDef(nPalCtr);
        if (srcDef->fPalAvailable)
        {
            COLORREF* crSrc = srcDef->pPal;
            uint16_t uAmt = srcDef->uPalSz;

            for (uint16_t nPICtr = 0; nPICtr < uAmt; nPICtr++)
            {
                if (m_fAllowTransparencyEdits)
                {
                    ppDataBuffer[srcDef->uUnitId][(srcDef->uPalId * 16) + nPICtr] = ConvCol16(crSrc[nPICtr]);
                }
                else
                {
                    // Force opaque
                    ppDataBuffer[srcDef->uUnitId][(srcDef->uPalId * 16) + nPICtr] = ((ConvCol16(crSrc[nPICtr]) & 0x0FFF) | 0xF000);
                }
            }

            //0 out the 1st index alpha flag
            ppDataBuffer[srcDef->uUnitId][(srcDef->uPalId * 16)] &= 0x0FFF;

            GetHost()->GetPalModDlg()->SetStatusText(L"Updated.");
            MarkPaletteDirty(srcDef->uUnitId, srcDef->uPalId);
            srcDef->fIsChanged = false;
            m_rgFileChanged.at(srcDef->uUnitId) = true;

            //Process supplement palettes
            if (m_ShouldUsePostSetPalProc)
            {
                PostSetPal(srcDef->uUnitId, srcDef->uPalId);
            }
        }
    }
}

void CGame_MVC2_D::ValidateMixExtraColors(BOOL& fChangesWereMade)
{
    ValidateAllPalettes(fChangesWereMade, m_rgFileChanged);
}

void CGame_MVC2_D::ResetChangeFlag(uint32_t nUnitId)
{
    m_rgFileChanged.at(nUnitId) = false;
}

int CGame_MVC2_D::PostSetPal(uint32_t nUnitId, uint32_t nPalId)
{
    uint32_t nBasicOffset = GetBasicOffset(nPalId);

    CString strMessage;
    strMessage.Format(L"CGame_MVC2_D::GetBasicOffset : Palette 0x%x was updated.  This palette is %s.  Checking for secondary palettes...\n", nPalId, (nBasicOffset != -1) ? L"basic" : L"Extra");
    OutputDebugString(strMessage);

    return MVC2_SupplementProcessing::proc_supp(nUnitId, nPalId);
}

LPCWSTR CGame_MVC2_D::GetGameName()
{
    if (k_mvc2_character_coloroption_count == 6)
    {
        return L"MvC2 (Dreamcast)";

    }
    else
    {
        return L"MvC2 (Dreamcast Palette Expansion)";
    }
}
