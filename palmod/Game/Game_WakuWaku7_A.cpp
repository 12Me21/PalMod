#include "StdAfx.h"
#include "GameDef.h"
#include "Game_WakuWaku7_A.h"
#include "..\RegProc.h"

stExtraDef* CGame_WakuWaku7_A::WakuWaku7_A_EXTRA_CUSTOM = nullptr;

CDescTree CGame_WakuWaku7_A::MainDescTree = nullptr;

uint32_t CGame_WakuWaku7_A::rgExtraCountAll[WakuWaku7_A_NUMUNIT + 1];
uint32_t CGame_WakuWaku7_A::rgExtraLoc[WakuWaku7_A_NUMUNIT + 1];

uint32_t CGame_WakuWaku7_A::m_nTotalPaletteCountForWakuWaku7 = 0;
const uint32_t CGame_WakuWaku7_A::m_nExpectedGameROMSize = 0x100000;  // 4194304 bytes
uint32_t CGame_WakuWaku7_A::m_nConfirmedROMSize = -1;

void CGame_WakuWaku7_A::InitializeStatics()
{
    safe_delete_array(CGame_WakuWaku7_A::WakuWaku7_A_EXTRA_CUSTOM);

    memset(rgExtraCountAll, -1, sizeof(rgExtraCountAll));
    memset(rgExtraLoc, -1, sizeof(rgExtraLoc));

    MainDescTree.SetRootTree(CGame_WakuWaku7_A::InitDescTree());
}

CGame_WakuWaku7_A::CGame_WakuWaku7_A(uint32_t nConfirmedROMSize)
{
    OutputDebugString(L"CGame_WakuWaku7_A::CGame_WakuWaku7_A: Loading ROM...\n");

    createPalOptions = { NO_SPECIAL_OPTIONS, PALWriteOutputOptions::WRITE_MAX };
    SetAlphaMode(AlphaMode::GameDoesNotUseAlpha);
    SetColorMode(ColMode::COLMODE_RGB666_NEOGEO);

    // We need this set before we initialize so that corrupt Extras truncate correctly.
    // Otherwise the new user inadvertently corrupts their ROM.
    m_nConfirmedROMSize = nConfirmedROMSize;
    InitializeStatics();

    m_nTotalInternalUnits = WakuWaku7_A_NUMUNIT;
    m_nExtraUnit = WakuWaku7_A_EXTRALOC;

    m_nSafeCountForThisRom = GetExtraCt(m_nExtraUnit) + 170;
    m_pszExtraFilename = EXTRA_FILENAME_WakuWaku7_A;
    m_nTotalPaletteCount = m_nTotalPaletteCountForWakuWaku7;
    // This magic number is used to warn users if their Extra file is trying to write somewhere potentially unusual
    m_nLowestKnownPaletteRomLocation = 0xc8d8;

    nUnitAmt = m_nTotalInternalUnits + (GetExtraCt(m_nExtraUnit) ? 1 : 0);

    InitDataBuffer();

    //Set game information
    nGameFlag = WakuWaku7_A;
    nImgGameFlag = IMGDAT_SECTION_WAKUWAKU7;
    m_prgGameImageSet = WAKUWAKU7_A_IMGIDS_USED;

    nFileAmt = 1;

    //Set the image out display type
    DisplayType = eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT;
    // Button labels are used for the Export Image dialog
    pButtonLabelSet = DEF_BUTTONLABEL_WAKUWAKU7_FIVE;

    //Create the redirect buffer
    rgUnitRedir = new uint32_t[nUnitAmt + 1];
    memset(rgUnitRedir, NULL, sizeof(uint32_t) * nUnitAmt);

    //Create the file changed flag
    PrepChangeTrackingArray();
}

CGame_WakuWaku7_A::~CGame_WakuWaku7_A()
{
    safe_delete_array(CGame_WakuWaku7_A::WakuWaku7_A_EXTRA_CUSTOM);
    ClearDataBuffer();
    //Get rid of the file changed flag
    FlushChangeTrackingArray();
}

CDescTree* CGame_WakuWaku7_A::GetMainTree()
{
    return &CGame_WakuWaku7_A::MainDescTree;
}

uint32_t CGame_WakuWaku7_A::GetExtraCt(uint32_t nUnitId, BOOL fCountVisibleOnly)
{
    return _GetExtraCount(rgExtraCountAll, WakuWaku7_A_NUMUNIT, nUnitId, WakuWaku7_A_EXTRA_CUSTOM);
}

uint32_t CGame_WakuWaku7_A::GetExtraLoc(uint32_t nUnitId)
{
    return _GetExtraLocation(rgExtraLoc, WakuWaku7_A_NUMUNIT, nUnitId, WakuWaku7_A_EXTRA_CUSTOM);
}

sDescTreeNode* CGame_WakuWaku7_A::InitDescTree()
{
    uint32_t nTotalPaletteCount = 0;

    //Load extra file if we're using it
    LoadExtraFileForGame(EXTRA_FILENAME_WakuWaku7_A, &WakuWaku7_A_EXTRA_CUSTOM, WakuWaku7_A_EXTRALOC, m_nConfirmedROMSize);

    uint16_t nUnitCt = WakuWaku7_A_NUMUNIT + (GetExtraCt(WakuWaku7_A_EXTRALOC) ? 1 : 0);
    
    sDescTreeNode* NewDescTree = new sDescTreeNode;

    //Create the main character tree
    _snwprintf_s(NewDescTree->szDesc, ARRAYSIZE(NewDescTree->szDesc), _TRUNCATE, L"%s", g_GameFriendlyName[WakuWaku7_A]);
    NewDescTree->ChildNodes = new sDescTreeNode[nUnitCt];
    NewDescTree->uChildAmt = nUnitCt;
    //All units have tree children
    NewDescTree->uChildType = DESC_NODETYPE_TREE;

    m_nTotalPaletteCountForWakuWaku7 = _InitDescTree(NewDescTree,
        WakuWaku7_A_UNITS,
        WakuWaku7_A_EXTRALOC,
        WakuWaku7_A_NUMUNIT,
        rgExtraCountAll,
        rgExtraLoc,
        WakuWaku7_A_EXTRA_CUSTOM
    );

    return NewDescTree;
}

sFileRule CGame_WakuWaku7_A::GetRule(uint32_t nUnitId)
{
    sFileRule NewFileRule;

    // This value is only used for directory-based games
    _snwprintf_s(NewFileRule.szFileName, ARRAYSIZE(NewFileRule.szFileName), _TRUNCATE, L"225-p1.p1");

    NewFileRule.uUnitId = 0;
    NewFileRule.uVerifyVar = m_nExpectedGameROMSize;

    return NewFileRule;
}

uint32_t CGame_WakuWaku7_A::GetKnownCRC32DatasetsForGame(const sCRC32ValueSet** ppKnownROMSet, bool* pfNeedToValidateCRCs)
{
    static const sCRC32ValueSet knownROMs[] =
    {
        // Waku Waku 7 variants...
        { L"Waku Waku 7 (Neo-Geo)", L"225-p1.p1", 0xb14da766, 0 },
        { L"Waku Waku 7 (Neo-Geo Boss Hack)", L"225-p1bh.p1", 0x0b7a3776, 0 },
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

uint32_t CGame_WakuWaku7_A::GetCollectionCountForUnit(uint32_t nUnitId)
{
    return _GetCollectionCountForUnit(WakuWaku7_A_UNITS, rgExtraCountAll, WakuWaku7_A_NUMUNIT, WakuWaku7_A_EXTRALOC, nUnitId, WakuWaku7_A_EXTRA_CUSTOM);
}

uint32_t CGame_WakuWaku7_A::GetNodeCountForCollection(uint32_t nUnitId, uint32_t nCollectionId)
{
    return _GetNodeCountForCollection(WakuWaku7_A_UNITS, rgExtraCountAll, WakuWaku7_A_NUMUNIT, WakuWaku7_A_EXTRALOC, nUnitId, nCollectionId, WakuWaku7_A_EXTRA_CUSTOM);
}

LPCWSTR CGame_WakuWaku7_A::GetDescriptionForCollection(uint32_t nUnitId, uint32_t nCollectionId)
{
    return _GetDescriptionForCollection(WakuWaku7_A_UNITS, WakuWaku7_A_EXTRALOC, nUnitId, nCollectionId);
}

uint32_t CGame_WakuWaku7_A::GetPaletteCountForUnit(uint32_t nUnitId)
{
    return _GetPaletteCountForUnit(WakuWaku7_A_UNITS, rgExtraCountAll, WakuWaku7_A_NUMUNIT, WakuWaku7_A_EXTRALOC, nUnitId, WakuWaku7_A_EXTRA_CUSTOM);
}

const sGame_PaletteDataset* CGame_WakuWaku7_A::GetPaletteSet(uint32_t nUnitId, uint32_t nCollectionId)
{
    return _GetPaletteSet(WakuWaku7_A_UNITS, nUnitId, nCollectionId);
}

const sDescTreeNode* CGame_WakuWaku7_A::GetNodeFromPaletteId(uint32_t nUnitId, uint32_t nPaletteId, bool fReturnBasicNodesOnly)
{
    return _GetNodeFromPaletteId(WakuWaku7_A_UNITS, rgExtraCountAll, WakuWaku7_A_NUMUNIT, WakuWaku7_A_EXTRALOC, nUnitId, nPaletteId, WakuWaku7_A_EXTRA_CUSTOM, fReturnBasicNodesOnly);
}

const sGame_PaletteDataset* CGame_WakuWaku7_A::GetSpecificPalette(uint32_t nUnitId, uint32_t nPaletteId)
{
    return _GetSpecificPalette(WakuWaku7_A_UNITS, rgExtraCountAll, WakuWaku7_A_NUMUNIT, WakuWaku7_A_EXTRALOC, nUnitId, nPaletteId, WakuWaku7_A_EXTRA_CUSTOM);
}

void CGame_WakuWaku7_A::LoadSpecificPaletteData(uint32_t nUnitId, uint32_t nPalId)
{
     if (nUnitId != m_nExtraUnit)
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
    else // m_nExtraUnit
    {
        // This is where we handle all the palettes added in via Extra.
        stExtraDef* pCurrDef = GetExtraDefForWakuWaku7(GetExtraLoc(nUnitId) + nPalId);

        m_nCurrentPaletteROMLocation = pCurrDef->uOffset;
        m_nCurrentPaletteSizeInColors = (pCurrDef->cbPaletteSize / m_nSizeOfColorsInBytes);
        m_pszCurrentPaletteName = pCurrDef->szDesc;
    }
}

BOOL CGame_WakuWaku7_A::UpdatePalImg(int Node01, int Node02, int Node03, int Node04)
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
    if (NodeGet->uUnitId != WakuWaku7_A_EXTRALOC)
    {
        const sGame_PaletteDataset* paletteDataSet = GetSpecificPalette(NodeGet->uUnitId, NodeGet->uPalId);

        if (paletteDataSet)
        {
            nImgUnitId = paletteDataSet->indexImgToUse;
            nTargetImgId = paletteDataSet->indexOffsetToUse;

            const sDescTreeNode* pCurrentNode = GetNodeFromPaletteId(NodeGet->uUnitId, NodeGet->uPalId, false);

            if (pCurrentNode)
            {
                switch (GetCollectionCountForUnit(NodeGet->uUnitId))
                {
                case 4:
                    nSrcAmt = 4;
                    pButtonLabelSet = DEF_BUTTONLABEL_NEOGEO;
                    break;
                case 5:
                    nSrcAmt = 5;
                    pButtonLabelSet = DEF_BUTTONLABEL_WAKUWAKU7_FIVE;
                    break;
                default:
                    break;
                }

                if (nSrcAmt != 1)
                {
                    nNodeIncrement = pCurrentNode->uChildAmt;

                    while (nSrcStart >= nNodeIncrement)
                    {
                        // The starting point is the absolute first palette for the sprite in question which is found in A
                        nSrcStart -= nNodeIncrement;
                    }
                }

                if (paletteDataSet->pPalettePairingInfo)
                {
                    const int8_t nPeerPaletteDistance = paletteDataSet->pPalettePairingInfo->nNodeIncrementToPartner;

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
