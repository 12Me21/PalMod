#include "StdAfx.h"
#include "GameDef.h"
#include "Game_SAMSHO4_A.h"
#include "..\PalMod.h"
#include "..\RegProc.h"

stExtraDef* CGame_SAMSHO4_A::SAMSHO4_A_EXTRA_CUSTOM = nullptr;

CDescTree CGame_SAMSHO4_A::MainDescTree = nullptr;

uint32_t CGame_SAMSHO4_A::rgExtraCountAll[SAMSHO4_A_NUMUNIT + 1];
uint32_t CGame_SAMSHO4_A::rgExtraLoc[SAMSHO4_A_NUMUNIT + 1];

uint32_t CGame_SAMSHO4_A::m_nTotalPaletteCountForSAMSHO4 = 0;
uint32_t CGame_SAMSHO4_A::m_nExpectedGameROMSize = 0x100000;  // 1,048,576 bytes
uint32_t CGame_SAMSHO4_A::m_nConfirmedROMSize = -1;

void CGame_SAMSHO4_A::InitializeStatics()
{
    safe_delete_array(CGame_SAMSHO4_A::SAMSHO4_A_EXTRA_CUSTOM);

    memset(rgExtraCountAll, -1, sizeof(rgExtraCountAll));
    memset(rgExtraLoc, -1, sizeof(rgExtraLoc));

    MainDescTree.SetRootTree(CGame_SAMSHO4_A::InitDescTree());
}

CGame_SAMSHO4_A::CGame_SAMSHO4_A(uint32_t nConfirmedROMSize)
{
    OutputDebugString(L"CGame_SAMSHO4_A::CGame_SAMSHO4_A: Loading ROM...\n");

    createPalOptions = { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_16 };
    SetAlphaMode(AlphaMode::GameDoesNotUseAlpha);
    SetColorMode(ColMode::COLMODE_RGB666_NEOGEO);

    // We need this set before we initialize so that corrupt Extras truncate correctly.
    // Otherwise the new user inadvertently corrupts their ROM.
    m_nConfirmedROMSize = nConfirmedROMSize;
    InitializeStatics();

    m_nTotalInternalUnits = SAMSHO4_A_NUMUNIT;
    m_nExtraUnit = SAMSHO4_A_EXTRALOC;

    m_nSafeCountForThisRom = GetExtraCt(m_nExtraUnit) + 596;
    m_pszExtraFilename = EXTRA_FILENAME_SAMSHO4_A;
    m_nTotalPaletteCount = m_nTotalPaletteCountForSAMSHO4;
    // This magic number is used to warn users if their Extra file is trying to write somewhere potentially unusual
    m_nLowestKnownPaletteRomLocation = 0xc09e0;

    nUnitAmt = m_nTotalInternalUnits + (GetExtraCt(m_nExtraUnit) ? 1 : 0);

    InitDataBuffer();

    //Set game information
    nGameFlag = SAMSHO4_A;
    nImgGameFlag = IMGDAT_SECTION_SAMSHO;
    m_prgGameImageSet = SAMSHO4_A_IMGIDS_USED;

    nFileAmt = 1;

    //Set the image out display type
    DisplayType = eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT;
    // Button labels are used for the Export Image dialog
    pButtonLabelSet = DEF_BUTTONLABEL_SAMSHO3;

    //Create the redirect buffer
    rgUnitRedir = new uint32_t[nUnitAmt + 1];
    memset(rgUnitRedir, NULL, sizeof(uint32_t) * nUnitAmt);

    //Create the file changed flag
    PrepChangeTrackingArray();
}

CGame_SAMSHO4_A::~CGame_SAMSHO4_A(void)
{
    safe_delete_array(CGame_SAMSHO4_A::SAMSHO4_A_EXTRA_CUSTOM);
    ClearDataBuffer();
    //Get rid of the file changed flag
    FlushChangeTrackingArray();
}

CDescTree* CGame_SAMSHO4_A::GetMainTree()
{
    return &CGame_SAMSHO4_A::MainDescTree;
}

uint32_t CGame_SAMSHO4_A::GetExtraCt(uint32_t nUnitId, BOOL fCountVisibleOnly)
{
    return _GetExtraCount(rgExtraCountAll, SAMSHO4_A_NUMUNIT, nUnitId, SAMSHO4_A_EXTRA_CUSTOM);
}

uint32_t CGame_SAMSHO4_A::GetExtraLoc(uint32_t nUnitId)
{
    return _GetExtraLocation(rgExtraLoc, SAMSHO4_A_NUMUNIT, nUnitId, SAMSHO4_A_EXTRA_CUSTOM);
}

void CGame_SAMSHO4_A::DumpAllPalettes()
{
    // I wanted to quickly generate the special palettes we didn't have listed yet.
    CString strInfo;

    for (uint32_t nUnit = 0; nUnit < ARRAYSIZE(SAMSHO4_A_UNITS); nUnit++)
    {
        for (uint32_t nNode = 0; nNode < SAMSHO4_A_UNITS[nUnit].uChildAmt; nNode++)
        {
            sDescTreeNode* pThisNode = (sDescTreeNode *)SAMSHO4_A_UNITS[nUnit].ChildNodes;
            sGame_PaletteDataset* pThisCharacter = (sGame_PaletteDataset *)pThisNode[nNode].ChildNodes;

            struct sSpecialInfo
            {
                LPCWSTR szSpecialName = nullptr;
                int nOffsetFromBase = 0;
            };

            const sSpecialInfo sSamShoIVInfo[] =
            {
                { L"Burning", 0xc0 },
                { L"Shocked", 0x100 },
                { L"Frozen/Wet", 0x140 },
                { L"Ki", 0x180 },
                { L"Issen Trail", 0x200 },
                //{ L"SON?", 0x240 },  SON is SamShoV/SP only.  Unclear what these/the other extras are
            };

            LPCWSTR ppszImgIdText[] =
            {
                L"indexSamSho5Sprites_Amakusa",
                L"indexSamSho5Sprites_Basara",                            // 1
                L"indexSamSho5Sprites_Charlotte",                         // 2
                L"indexSamSho5Sprites_Enja",                              // 3
                L"indexSamSho5Sprites_Gaira",                             // 4
                L"indexSamSho5Sprites_Galford",                           // 5
                L"indexSamSho5Sprites_Gaoh",                              // 6
                L"indexSamSho5Sprites_Genjuro",                           // 7
                L"indexSamSho5Sprites_Hanzo",                             // 8
                L"indexSamSho5Sprites_Haohmaru",                          // 9
                L"indexSamSho5Sprites_Jubei",                             // a
                L"indexSamSho5Sprites_Kazuki",                            // b
                L"indexSamSho5Sprites_Kusaregedo",                        // c
                L"indexSamSho5Sprites_Kyoshiro",                          // d
                L"indexSamSho5Sprites_Mina",                              // e
                L"indexSamSho5Sprites_Mizuki",                            // f
                L"indexSamSho5Sprites_Nakoruru",                          // 10
                L"indexSamSho5Sprites_Rasetsumaru",                        // 11
                L"indexSamSho5Sprites_Rera",                              // 12
                L"indexSamSho5Sprites_Rimururu",                          // 13
                L"indexSamSho5Sprites_Shizumaru",                         // 14
                L"indexSamSho5Sprites_Sogetsu",                           // 15
                L"indexSamSho5Sprites_Suija",                             // 16
                L"indexSamSho5Sprites_TamTam",                            // 17
                L"indexSamSho5Sprites_Ukyo",                              // 18
                L"indexSamSho5Sprites_Yoshitora",                         // 19
                L"indexSamSho5Sprites_Yunfei",                            // 1a
                L"indexSamSho5Sprites_Zankuro",                           // 1b
            };

            for (uint32_t nSpecial = 0; nSpecial < ARRAYSIZE(sSamShoIVInfo); nSpecial++)
            {
                    strInfo.Format(L"    { L\"%s (%s)\", 0x%x, 0x%x, %s, 0x%02x },\r\n",
                        pThisCharacter[0].szPaletteName,
                        sSamShoIVInfo[nSpecial].szSpecialName,
                        pThisCharacter[0].nPaletteOffset + sSamShoIVInfo[nSpecial].nOffsetFromBase,
                        pThisCharacter[0].nPaletteOffsetEnd + sSamShoIVInfo[nSpecial].nOffsetFromBase,
                        (pThisCharacter[0].indexImgToUse < ARRAYSIZE(ppszImgIdText)) ? ppszImgIdText[pThisCharacter[0].indexImgToUse] : L"-1",
                        pThisCharacter[0].indexOffsetToUse
                    );
                    OutputDebugString(strInfo);
            }
        }
    }
}

sDescTreeNode* CGame_SAMSHO4_A::InitDescTree()
{
    //Load extra file if we're using it
    LoadExtraFileForGame(EXTRA_FILENAME_SAMSHO4_A, &SAMSHO4_A_EXTRA_CUSTOM, SAMSHO4_A_EXTRALOC, m_nConfirmedROMSize);

    uint16_t nUnitCt = SAMSHO4_A_NUMUNIT + (GetExtraCt(SAMSHO4_A_EXTRALOC) ? 1 : 0);
    
    sDescTreeNode* NewDescTree = new sDescTreeNode;

    //Create the main character tree
    _snwprintf_s(NewDescTree->szDesc, ARRAYSIZE(NewDescTree->szDesc), _TRUNCATE, L"%s", g_GameFriendlyName[SAMSHO4_A]);
    NewDescTree->ChildNodes = new sDescTreeNode[nUnitCt];
    NewDescTree->uChildAmt = nUnitCt;
    //All units have tree children
    NewDescTree->uChildType = DESC_NODETYPE_TREE;

    m_nTotalPaletteCountForSAMSHO4 = _InitDescTree(NewDescTree,
        SAMSHO4_A_UNITS,
        SAMSHO4_A_EXTRALOC,
        SAMSHO4_A_NUMUNIT,
        rgExtraCountAll,
        rgExtraLoc,
        SAMSHO4_A_EXTRA_CUSTOM
    );

    // For development purposes
    // The initial work here was just for adding in the special palettes.
    // We can't currently regenerate the header set, but it's usually not necessary.
    //DumpAllPalettes();

    return NewDescTree;
}

sFileRule CGame_SAMSHO4_A::GetRule(uint32_t nUnitId)
{
    sFileRule NewFileRule;

    // This value is only used for directory-based games
    _snwprintf_s(NewFileRule.szFileName, ARRAYSIZE(NewFileRule.szFileName), _TRUNCATE, L"sams4_p1.rom");
    NewFileRule.uUnitId = 0;
    NewFileRule.uVerifyVar = m_nExpectedGameROMSize;

    return NewFileRule;
}

uint32_t CGame_SAMSHO4_A::GetCollectionCountForUnit(uint32_t nUnitId)
{
    return _GetCollectionCountForUnit(SAMSHO4_A_UNITS, rgExtraCountAll, SAMSHO4_A_NUMUNIT, SAMSHO4_A_EXTRALOC, nUnitId, SAMSHO4_A_EXTRA_CUSTOM);
}

uint32_t CGame_SAMSHO4_A::GetNodeCountForCollection(uint32_t nUnitId, uint32_t nCollectionId)
{
    return _GetNodeCountForCollection(SAMSHO4_A_UNITS, rgExtraCountAll, SAMSHO4_A_NUMUNIT, SAMSHO4_A_EXTRALOC, nUnitId, nCollectionId, SAMSHO4_A_EXTRA_CUSTOM);
}

LPCWSTR CGame_SAMSHO4_A::GetDescriptionForCollection(uint32_t nUnitId, uint32_t nCollectionId)
{
    return _GetDescriptionForCollection(SAMSHO4_A_UNITS, SAMSHO4_A_EXTRALOC, nUnitId, nCollectionId);
}

uint32_t CGame_SAMSHO4_A::GetPaletteCountForUnit(uint32_t nUnitId)
{
    return _GetPaletteCountForUnit(SAMSHO4_A_UNITS, rgExtraCountAll, SAMSHO4_A_NUMUNIT, SAMSHO4_A_EXTRALOC, nUnitId, SAMSHO4_A_EXTRA_CUSTOM);
}

const sGame_PaletteDataset* CGame_SAMSHO4_A::GetPaletteSet(uint32_t nUnitId, uint32_t nCollectionId)
{
    return _GetPaletteSet(SAMSHO4_A_UNITS, nUnitId, nCollectionId);
}

uint32_t CGame_SAMSHO4_A::GetNodeSizeFromPaletteId(uint32_t nUnitId, uint32_t nPaletteId)
{
    return _GetNodeSizeFromPaletteId(SAMSHO4_A_UNITS, rgExtraCountAll, SAMSHO4_A_NUMUNIT, SAMSHO4_A_EXTRALOC, nUnitId, nPaletteId, SAMSHO4_A_EXTRA_CUSTOM);
}

const sDescTreeNode* CGame_SAMSHO4_A::GetNodeFromPaletteId(uint32_t nUnitId, uint32_t nPaletteId, bool fReturnBasicNodesOnly)
{
    return _GetNodeFromPaletteId(SAMSHO4_A_UNITS, rgExtraCountAll, SAMSHO4_A_NUMUNIT, SAMSHO4_A_EXTRALOC, nUnitId, nPaletteId, SAMSHO4_A_EXTRA_CUSTOM, fReturnBasicNodesOnly);
}

const sGame_PaletteDataset* CGame_SAMSHO4_A::GetSpecificPalette(uint32_t nUnitId, uint32_t nPaletteId)
{
    return _GetSpecificPalette(SAMSHO4_A_UNITS, rgExtraCountAll, SAMSHO4_A_NUMUNIT, SAMSHO4_A_EXTRALOC, nUnitId, nPaletteId, SAMSHO4_A_EXTRA_CUSTOM);
}

void CGame_SAMSHO4_A::LoadSpecificPaletteData(uint32_t nUnitId, uint32_t nPalId)
{
     if (nUnitId != SAMSHO4_A_EXTRALOC)
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
    else // SAMSHO4_A_EXTRALOC
    {
        // This is where we handle all the palettes added in via Extra.
        stExtraDef* pCurrDef = GetExtraDefForSAMSHO4(GetExtraLoc(nUnitId) + nPalId);

        m_nCurrentPaletteROMLocation = pCurrDef->uOffset;
        m_nCurrentPaletteSizeInColors = (pCurrDef->cbPaletteSize / m_nSizeOfColorsInBytes);
        m_pszCurrentPaletteName = pCurrDef->szDesc;
    }
}

BOOL CGame_SAMSHO4_A::UpdatePalImg(int Node01, int Node02, int Node03, int Node04)
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
    uint32_t nSrcStart = NodeGet->uPalId;
    uint32_t nSrcAmt = 1;
    uint32_t nNodeIncrement = 1;

    //Get rid of any palettes if there are any
    BasePalGroup.FlushPalAll();

    // Make sure to reset the image id
    int nTargetImgId = 0;
    uint32_t nImgUnitId = INVALID_UNIT_VALUE;

    bool fShouldUseAlternateLoadLogic = false;

    // Only load images for internal units, since we don't currently have a methodology for associating
    // external loads to internal sprites.
    if (NodeGet->uUnitId != SAMSHO4_A_EXTRALOC)
    {
        const sGame_PaletteDataset* paletteDataSet = GetSpecificPalette(NodeGet->uUnitId, NodeGet->uPalId);

        if (paletteDataSet)
        {
            nImgUnitId = paletteDataSet->indexImgToUse;
            nTargetImgId = paletteDataSet->indexOffsetToUse;

            const sDescTreeNode* pCurrentNode = GetNodeFromPaletteId(NodeGet->uUnitId, NodeGet->uPalId, false);

            if (pCurrentNode)
            {
                if ((_wcsicmp(pCurrentNode->szDesc, L"Slash 1") == 0) || (_wcsicmp(pCurrentNode->szDesc, L"Slash 2") == 0) ||
                    (_wcsicmp(pCurrentNode->szDesc, L"Bust 1") == 0) || (_wcsicmp(pCurrentNode->szDesc, L"Bust 2") == 0))
                {
                    sDescTreeNode* charUnit = GetMainTree()->GetDescTree(Node01, -1);

                    if ((wcscmp(charUnit->szDesc, L"Galford") == 0) ||
                        (wcscmp(charUnit->szDesc, L"Kyoshiro") == 0))
                    {
                        // These two have different trees between S and B
                        nSrcAmt = 2;
                        nNodeIncrement = pCurrentNode->uChildAmt;

                        if (((nSrcStart >= nNodeIncrement) && (nSrcStart < (nNodeIncrement * 2))) ||
                            ((nSrcStart >= (nNodeIncrement * 3)) && (nSrcStart < (nNodeIncrement * 4))))
                        {
                            nSrcStart -= nNodeIncrement;
                        }
                    }
                    else
                    {
                        nSrcAmt = 4;
                        nNodeIncrement = pCurrentNode->uChildAmt;

                        while (nSrcStart >= nNodeIncrement)
                        {
                            // The starting point is the absolute first palette for the sprite in question which is found in Slash 1
                            nSrcStart -= nNodeIncrement;
                        }
                    }
                }
            }

            if (paletteDataSet->pPalettePairingInfo)
            {
                if (paletteDataSet->pPalettePairingInfo == &pairFullyLinkedNode)
                {
                    const uint32_t nStageCount = GetNodeSizeFromPaletteId(NodeGet->uUnitId, NodeGet->uPalId);

                    fShouldUseAlternateLoadLogic = true;
                    sImgTicket* pImgArray = nullptr;

                    for (uint32_t nStageIndex = 0; nStageIndex < nStageCount; nStageIndex++)
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
                    INT8 nPeerPaletteDistance = paletteDataSet->pPalettePairingInfo->nNodeIncrementToPartner;

                    const sGame_PaletteDataset* paletteDataSetToJoin = GetSpecificPalette(NodeGet->uUnitId, NodeGet->uPalId + nPeerPaletteDistance);

                    if (paletteDataSetToJoin)
                    {
                        fShouldUseAlternateLoadLogic = true;

                        ClearSetImgTicket(
                            CreateImgTicket(paletteDataSet->indexImgToUse, paletteDataSet->indexOffsetToUse,
                                CreateImgTicket(paletteDataSetToJoin->indexImgToUse, paletteDataSetToJoin->indexOffsetToUse)
                            )
                        );

                        //Set each palette
                        std::vector<sDescNode*> JoinedNode = {
                            GetMainTree()->GetDescNode(Node01, Node02, Node03, -1),
                            GetMainTree()->GetDescNode(Node01, Node02, Node03 + nPeerPaletteDistance, -1)
                        };

                        //Set each palette
                        CreateDefPal(JoinedNode[0], 0);
                        CreateDefPal(JoinedNode[1], 1);

                        SetSourcePal(0, NodeGet->uUnitId, nSrcStart, nSrcAmt, nNodeIncrement);
                        SetSourcePal(1, NodeGet->uUnitId, nSrcStart + nPeerPaletteDistance, nSrcAmt, nNodeIncrement);
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
