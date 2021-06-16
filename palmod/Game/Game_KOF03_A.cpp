#include "StdAfx.h"
#include "GameDef.h"
#include "Game_KOF03_A.h"
#include "..\PalMod.h"
#include "..\RegProc.h"

#define KOF03_A_DEBUG DEFAULT_GAME_DEBUG_STATE

stExtraDef* CGame_KOF03_A::KOF03_A_EXTRA_CUSTOM = nullptr;

CDescTree CGame_KOF03_A::MainDescTree = nullptr;

int CGame_KOF03_A::rgExtraCountAll[KOF03_A_NUMUNIT + 1];
int CGame_KOF03_A::rgExtraLoc[KOF03_A_NUMUNIT + 1];

UINT32 CGame_KOF03_A::m_nTotalPaletteCountForKOF03 = 0;
UINT32 CGame_KOF03_A::m_nExpectedGameROMSize = 0x800000;
UINT32 CGame_KOF03_A::m_nConfirmedROMSize = -1;

void CGame_KOF03_A::InitializeStatics()
{
    safe_delete_array(CGame_KOF03_A::KOF03_A_EXTRA_CUSTOM);

    memset(rgExtraCountAll, -1, sizeof(rgExtraCountAll));
    memset(rgExtraLoc, -1, sizeof(rgExtraLoc));

    MainDescTree.SetRootTree(CGame_KOF03_A::InitDescTree());
}

CGame_KOF03_A::CGame_KOF03_A(UINT32 nConfirmedROMSize)
{
    OutputDebugString(L"CGame_KOF03_A::CGame_KOF03_A: Loading ROM...\n");

    createPalOptions = { NO_SPECIAL_OPTIONS, WRITE_MAX };
    SetAlphaMode(AlphaMode::GameDoesNotUseAlpha);
    SetColorMode(ColMode::COLMODE_RGB666_NEOGEO);

    // We need this set before we initialize so that corrupt Extras truncate correctly.
    // Otherwise the new user inadvertently corrupts their ROM.
    m_nConfirmedROMSize = nConfirmedROMSize;
    InitializeStatics();

    m_nTotalInternalUnits = KOF03_A_NUMUNIT;
    m_nExtraUnit = KOF03_A_EXTRALOC;

    m_nSafeCountForThisRom = GetExtraCt(m_nExtraUnit) + 992;
    m_pszExtraFilename = EXTRA_FILENAME_KOF03_A;
    m_nTotalPaletteCount = m_nTotalPaletteCountForKOF03;
    // This magic number is used to warn users if their Extra file is trying to write somewhere potentially unusual
    m_nLowestKnownPaletteRomLocation = 0x002000;

    nUnitAmt = m_nTotalInternalUnits + (GetExtraCt(m_nExtraUnit) ? 1 : 0);

    InitDataBuffer();

    //Set game information
    nGameFlag = KOF03_A;
    nImgGameFlag = IMGDAT_SECTION_KOF;
    m_prgGameImageSet = KOF03_A_IMGIDS_USED;
    nImgUnitAmt = ARRAYSIZE(KOF03_A_IMGIDS_USED);

    nFileAmt = 1;

    //Set the image out display type
    DisplayType = eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT;
    // Button labels are used for the Export Image dialog
    pButtonLabelSet = DEF_BUTTONLABEL_NEOGEO;
    m_nNumberOfColorOptions = ARRAYSIZE(DEF_BUTTONLABEL_NEOGEO);

    //Create the redirect buffer
    rgUnitRedir = new UINT16[nUnitAmt + 1];
    memset(rgUnitRedir, NULL, sizeof(UINT16) * nUnitAmt);

    //Create the file changed flag
    PrepChangeTrackingArray();
}

CGame_KOF03_A::~CGame_KOF03_A(void)
{
    safe_delete_array(CGame_KOF03_A::KOF03_A_EXTRA_CUSTOM);
    ClearDataBuffer();
    //Get rid of the file changed flag
    FlushChangeTrackingArray();
}

CDescTree* CGame_KOF03_A::GetMainTree()
{
    return &CGame_KOF03_A::MainDescTree;
}

int CGame_KOF03_A::GetExtraCt(UINT16 nUnitId, BOOL bCountVisibleOnly)
{
    return _GetExtraCount(rgExtraCountAll, KOF03_A_NUMUNIT, nUnitId, KOF03_A_EXTRA_CUSTOM);
}

int CGame_KOF03_A::GetExtraLoc(UINT16 nUnitId)
{
    return _GetExtraLocation(rgExtraLoc, KOF03_A_NUMUNIT, nUnitId, KOF03_A_EXTRA_CUSTOM);
}

sDescTreeNode* CGame_KOF03_A::InitDescTree()
{
    UINT32 nTotalPaletteCount = 0;

    //Load extra file if we're using it
    LoadExtraFileForGame(EXTRA_FILENAME_KOF03_A, KOF03_A_EXTRA, &KOF03_A_EXTRA_CUSTOM, KOF03_A_EXTRALOC, m_nConfirmedROMSize);

    UINT16 nUnitCt = KOF03_A_NUMUNIT + (GetExtraCt(KOF03_A_EXTRALOC) ? 1 : 0);
    
    sDescTreeNode* NewDescTree = new sDescTreeNode;

    //Create the main character tree
    _snwprintf_s(NewDescTree->szDesc, ARRAYSIZE(NewDescTree->szDesc), _TRUNCATE, L"%s", g_GameFriendlyName[KOF03_A]);
    NewDescTree->ChildNodes = new sDescTreeNode[nUnitCt];
    NewDescTree->uChildAmt = nUnitCt;
    //All units have tree children
    NewDescTree->uChildType = DESC_NODETYPE_TREE;

    m_nTotalPaletteCountForKOF03 = _InitDescTree(NewDescTree,
        KOF03_A_UNITS,
        KOF03_A_EXTRALOC,
        KOF03_A_NUMUNIT,
        rgExtraCountAll,
        rgExtraLoc,
        KOF03_A_EXTRA_CUSTOM
    );

    return NewDescTree;
}

sFileRule CGame_KOF03_A::GetRule(UINT16 nUnitId)
{
    sFileRule NewFileRule;

    // This value is only used for directory-based games
    _snwprintf_s(NewFileRule.szFileName, ARRAYSIZE(NewFileRule.szFileName), _TRUNCATE, L"pal_a.bin");

    NewFileRule.uUnitId = 0;
    NewFileRule.uVerifyVar = m_nExpectedGameROMSize;

    return NewFileRule;
}

UINT16 CGame_KOF03_A::GetCollectionCountForUnit(UINT16 nUnitId)
{
    return _GetCollectionCountForUnit(KOF03_A_UNITS, rgExtraCountAll, KOF03_A_NUMUNIT, KOF03_A_EXTRALOC, nUnitId, KOF03_A_EXTRA_CUSTOM);
}

UINT16 CGame_KOF03_A::GetNodeCountForCollection(UINT16 nUnitId, UINT16 nCollectionId)
{
    return _GetNodeCountForCollection(KOF03_A_UNITS, rgExtraCountAll, KOF03_A_NUMUNIT, KOF03_A_EXTRALOC, nUnitId, nCollectionId, KOF03_A_EXTRA_CUSTOM);
}

LPCWSTR CGame_KOF03_A::GetDescriptionForCollection(UINT16 nUnitId, UINT16 nCollectionId)
{
    return _GetDescriptionForCollection(KOF03_A_UNITS, KOF03_A_EXTRALOC, nUnitId, nCollectionId);
}

UINT16 CGame_KOF03_A::GetPaletteCountForUnit(UINT16 nUnitId)
{
    return _GetPaletteCountForUnit(KOF03_A_UNITS, rgExtraCountAll, KOF03_A_NUMUNIT, KOF03_A_EXTRALOC, nUnitId, KOF03_A_EXTRA_CUSTOM);
}

const sGame_PaletteDataset* CGame_KOF03_A::GetPaletteSet(UINT16 nUnitId, UINT16 nCollectionId)
{
    return _GetPaletteSet(KOF03_A_UNITS, nUnitId, nCollectionId);
}

const sDescTreeNode* CGame_KOF03_A::GetNodeFromPaletteId(UINT16 nUnitId, UINT16 nPaletteId, bool fReturnBasicNodesOnly)
{
    return _GetNodeFromPaletteId(KOF03_A_UNITS, rgExtraCountAll, KOF03_A_NUMUNIT, KOF03_A_EXTRALOC, nUnitId, nPaletteId, KOF03_A_EXTRA_CUSTOM, fReturnBasicNodesOnly);
}

const sGame_PaletteDataset* CGame_KOF03_A::GetSpecificPalette(UINT16 nUnitId, UINT16 nPaletteId)
{
    return _GetSpecificPalette(KOF03_A_UNITS, rgExtraCountAll, KOF03_A_NUMUNIT, KOF03_A_EXTRALOC, nUnitId, nPaletteId, KOF03_A_EXTRA_CUSTOM);
}

void CGame_KOF03_A::LoadSpecificPaletteData(UINT16 nUnitId, UINT16 nPalId)
{
     if (nUnitId != KOF03_A_EXTRALOC)
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
    else // KOF03_A_EXTRALOC
    {
        // This is where we handle all the palettes added in via Extra.
        stExtraDef* pCurrDef = GetExtraDefForKOF03(GetExtraLoc(nUnitId) + nPalId);

        m_nCurrentPaletteROMLocation = pCurrDef->uOffset;
        m_nCurrentPaletteSizeInColors = (pCurrDef->cbPaletteSize / m_nSizeOfColorsInBytes);
        m_pszCurrentPaletteName = pCurrDef->szDesc;
    }
}

BOOL CGame_KOF03_A::UpdatePalImg(int Node01, int Node02, int Node03, int Node04)
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
    UINT16 nSrcStart = NodeGet->uPalId;
    UINT16 nSrcAmt = 1;
    UINT16 nNodeIncrement = 1;

    //Get rid of any palettes if there are any
    BasePalGroup.FlushPalAll();

    // Make sure to reset the image id
    nTargetImgId = 0;
    UINT16 nImgUnitId = INVALID_UNIT_VALUE;

    bool fShouldUseAlternateLoadLogic = false;

    // Only load images for internal units, since we don't currently have a methodology for associating
    // external loads to internal sprites.
    if (NodeGet->uUnitId != KOF03_A_EXTRALOC)
    {
        const sGame_PaletteDataset* paletteDataSet = GetSpecificPalette(NodeGet->uUnitId, NodeGet->uPalId);

        if (paletteDataSet)
        {
            nImgUnitId = paletteDataSet->indexImgToUse;
            nTargetImgId = paletteDataSet->indexOffsetToUse;

            const sDescTreeNode* pCurrentNode = GetNodeFromPaletteId(NodeGet->uUnitId, NodeGet->uPalId, false);

            if (pCurrentNode)
            {
                if ((_wcsicmp(pCurrentNode->szDesc, L"A") == 0) || (_wcsicmp(pCurrentNode->szDesc, L"B") == 0) ||
                    (_wcsicmp(pCurrentNode->szDesc, L"C") == 0) || (_wcsicmp(pCurrentNode->szDesc, L"D") == 0))
                {
                    nSrcAmt = 4;
                    nNodeIncrement = pCurrentNode->uChildAmt;

                    while (nSrcStart >= nNodeIncrement)
                    {
                        // The starting point is the absolute first palette for the sprite in question which is found in P1/A
                        nSrcStart -= nNodeIncrement;
                    }
                }
                else if (_wcsicmp(pCurrentNode->szDesc, L"Portraits") == 0) // Portraits is last
                {
                    nSrcAmt = 4;
                    nSrcStart = GetPaletteCountForUnit(NodeGet->uUnitId) - pCurrentNode->uChildAmt;
                    nNodeIncrement = 1;

                }
            }

            if (paletteDataSet->pPalettePairingInfo)
            {
                int nXOffs = paletteDataSet->pPalettePairingInfo->nXOffs;
                int nYOffs = paletteDataSet->pPalettePairingInfo->nYOffs;
                INT8 nPeerPaletteDistance = paletteDataSet->pPalettePairingInfo->nNodeIncrementToPartner;

                const sGame_PaletteDataset* paletteDataSetToJoin = GetSpecificPalette(NodeGet->uUnitId, NodeGet->uPalId + nPeerPaletteDistance);

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

    if (!fShouldUseAlternateLoadLogic)
    {
        //Create the default palette
        ClearSetImgTicket(CreateImgTicket(nImgUnitId, nTargetImgId));

        CreateDefPal(NodeGet, 0);

        SetSourcePal(0, NodeGet->uUnitId, nSrcStart, nSrcAmt, nNodeIncrement);
    }

    return TRUE;
}
