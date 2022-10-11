#include "StdAfx.h"
#include "Game_Garou_A.h"

uint32_t CGame_Garou_A::GetKnownCRC32DatasetsForGame(const sCRC32ValueSet** ppKnownROMSet /* = nullptr */, bool* pfNeedToValidateCRCs /*= nullptr*/)
{
    static sCRC32ValueSet knownROMs[] =
    {
        { L"Garou: MotW (Neo-Geo)", L"kf.neo-sma", 0x98bc93dc, 0 },
        { L"Garou: MotW (Steam)", L"p1.bin", 0xeb2d1ea5, 0xc0000 },
        { L"Garou: MotW (Neo-Geo Prototype)", L"proto_253-p1.p1", 0xc72f0c16, 0xc0000 },
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

BOOL CGame_Garou_A::UpdatePalImg(int Node01, int Node02, int Node03, int Node04)
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
    if (NodeGet->uUnitId != m_nCurrentExtraUnitId)
    {
        const sGame_PaletteDataset* paletteDataSet = GetSpecificPalette(NodeGet->uUnitId, NodeGet->uPalId);

        if (paletteDataSet)
        {
            nImgUnitId = paletteDataSet->indexImgToUse;
            nTargetImgId = paletteDataSet->indexOffsetToUse;

            const sDescTreeNode* pCurrentNode = GetNodeFromPaletteId(NodeGet->uUnitId, NodeGet->uPalId, false);

            if (pCurrentNode)
            {
                sDescTreeNode* charUnit = GetMainTree()->GetDescTree(Node01, -1);

                if (wcscmp(charUnit->szDesc, k_garouNameKey_Portraits) == 0)
                {
                    // These nodes are variable sizes, so do a little math to figure it out
                    nSrcAmt = 4;
                    pButtonLabelSet = DEF_BUTTONLABEL_NEOGEO;
                    nNodeIncrement = 1;
                    uint32_t nCollectionCount = GetCollectionCountForUnit(NodeGet->uUnitId);
                    nSrcStart = 0;

                    for (uint32_t nCurrentCollection = 0; nCurrentCollection < nCollectionCount; nCurrentCollection++)
                    {
                        uint32_t nNextChunk = GetNodeCountForCollection(NodeGet->uUnitId, nCurrentCollection);

                        if (NodeGet->uPalId < (nSrcStart + nNextChunk))
                        {
                            // Make an allowance for the paired portraits that are using one shared asset
                            if (nNextChunk != nSrcAmt)
                            {
                                nSrcAmt = 1;
                                pButtonLabelSet = DEF_NOBUTTONS;
                            }
                            break;
                        }

                        nSrcStart += nNextChunk;
                    }
                }
                else
                {
                    pButtonLabelSet = DEF_BUTTONLABEL_NEOGEO_FIVE;
                    bool fIsCorePalette = false;

                    for (uint32_t nOptionsToTest = 0; nOptionsToTest < pButtonLabelSet.size(); nOptionsToTest++)
                    {
                        if (wcscmp(pCurrentNode->szDesc, pButtonLabelSet[nOptionsToTest]) == 0)
                        {
                            fIsCorePalette = true;
                            break;
                        }
                    }

                    if (fIsCorePalette)
                    {
                        nSrcAmt = 5;
                        nNodeIncrement = pCurrentNode->uChildAmt;

                        while (nSrcStart >= nNodeIncrement)
                        {
                            // The starting point is the absolute first palette for the sprite in question which is found in P1
                            nSrcStart -= nNodeIncrement;
                        }
                    }
                }
            }

            if (paletteDataSet->pPalettePairingInfo)
            {
                int8_t nPeerPaletteDistance = paletteDataSet->pPalettePairingInfo->nNodeIncrementToPartner;

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
    
    if (!fShouldUseAlternateLoadLogic)
    {
        //Create the default palette
        ClearSetImgTicket(CreateImgTicket(nImgUnitId, nTargetImgId));

        CreateDefPal(NodeGet, 0);

        SetSourcePal(0, NodeGet->uUnitId, nSrcStart, nSrcAmt, nNodeIncrement);
    }

    return TRUE;
}
