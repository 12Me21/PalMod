#include "StdAfx.h"
#include "Game_MVC_A.h"
#include "GameDef.h"

stExtraDef* CGame_MVC_A::MVC_A_EXTRA_CUSTOM = NULL;

CDescTree CGame_MVC_A::MainDescTree = CGame_MVC_A::InitDescTree();

int CGame_MVC_A::GetExtraCt(int nUnitId, BOOL bVisible)
{
	static int rgExtraCtDef[MVC_A_NUMUNIT + 1] = { -1 };
	static int rgExtraCtAlt[MVC_A_NUMUNIT + 1] = { -1 }; //Fix later

	int* rgExtraCt = bVisible ? (int*)rgExtraCtAlt : (int*)rgExtraCtDef;

	if (rgExtraCt[0] == -1)
	{
		int nDefCtr = 0;
		memset(rgExtraCt, 0, (MVC_A_NUMUNIT + 1) * sizeof(int));

		stExtraDef* pCurrDef = GetExtraDefForMVC(0);

		while (pCurrDef->uUnitN != 0xFF)
		{
			if (pCurrDef->bInvisible != 1 || !bVisible)
			{
				rgExtraCt[pCurrDef->uUnitN]++;
			}

			nDefCtr++;
			pCurrDef = GetExtraDefForMVC(nDefCtr);
		}
	}

	if (bVisible)
	{
		return rgExtraCtAlt[nUnitId];
	}
	else
	{
		return rgExtraCtDef[nUnitId];
	}
}

int CGame_MVC_A::GetExtraLoc(int nUnitId)
{
	static int rgExtraLoc[MVC_A_NUMUNIT + 1] = { -1 };

	if (rgExtraLoc[0] == -1)
	{
		int nDefCtr = 0;
		int nCurrUnit = 0x80;
		memset(rgExtraLoc, 0, (MVC_A_NUMUNIT + 1) * sizeof(int));

		stExtraDef* pCurrDef = GetExtraDefForMVC(0);

		while (pCurrDef->uUnitN != 0xFF)
		{
			if (pCurrDef->uUnitN != nCurrUnit)
			{
				rgExtraLoc[pCurrDef->uUnitN] = nDefCtr;
				nCurrUnit = pCurrDef->uUnitN;
			}

			nDefCtr++;
			pCurrDef = GetExtraDefForMVC(nDefCtr);
		}
	}

	return rgExtraLoc[nUnitId];
}

int CGame_MVC_A::GetBasicAmt(int nUnitId)
{
	return 1;
}

CGame_MVC_A::CGame_MVC_A(void)
{
	//We need the proper unit amt before we init the main buffer
	nUnitAmt = MVC_A_NUMUNIT + (GetExtraCt(MVC_A_EXTRALOC) ? 1 : 0);

	InitDataBuffer();

	//Set color mode
	SetColMode(COLMODE_12A);

	//Set palette conversion mode
	BasePalGroup.SetMode(PALTYPE_17);

	//Set game information
	nGameFlag = MVC_A;
	nImgGameFlag = IMG4;
	nImgUnitAmt = nUnitAmt;
	
	nDisplayW = 8;
	nFileAmt = 1;

	//Set the image out display type
	DisplayType = DISP_DEF;
	pButtonLabel = const_cast<CHAR *>((CHAR *)DEF_BUTTONLABEL6);

	//Create the redirect buffer
	rgUnitRedir = new UINT8[nUnitAmt + 1];
	memset(rgUnitRedir, NULL, sizeof(UINT8) * nUnitAmt);

	//Create the file changed flag
	bFileChanged = new UINT8;

	nRIndexAmt = 15;
	nGIndexAmt = 15;
	nBIndexAmt = 15;
	nAIndexAmt = 0;

	nRIndexMul = 17.0f;
	nGIndexMul = 17.0f;
	nBIndexMul = 17.0f;
	nAIndexMul = 0.0f;
}

CGame_MVC_A::~CGame_MVC_A(void)
{ 
	//Get rid of the file changed flag
	if (bFileChanged)
	{
		delete bFileChanged;
	}
}

CDescTree * CGame_MVC_A::GetMainTree()
{
	return &CGame_MVC_A::MainDescTree;
}

CDescTree CGame_MVC_A::InitDescTree()
{
	//Load extra file if we're using it
	LoadExtraFile();

	int nUnitCt = MVC_A_NUMUNIT + (GetExtraCt(MVC_A_EXTRALOC) ? 1 : 0);

	sDescTreeNode * NewDescTree = new sDescTreeNode;

	sDescTreeNode * UnitNode;
	sDescTreeNode * ButtonNode;
	sDescNode * ChildNode;

	//Create the main character tree
	NewDescTree->ChildNodes = new sDescTreeNode[nUnitCt];
	NewDescTree->uChildAmt = nUnitCt;
	//All units have tree children
	NewDescTree->uChildType = DESC_NODETYPE_TREE;

	//Go through each character
	for(int iUnitCtr = 0; iUnitCtr < nUnitCt; iUnitCtr++)
	{
		//Use this for Extra support
		int nSuppAmt = 0;

		int nExtraCt = GetExtraCt(iUnitCtr, TRUE);
		BOOL bUseExtra = (GetExtraLoc(iUnitCtr) ? 1 : 0);

		int nButtonAmt = GetBasicAmt(iUnitCtr);
		int nMainChildAmt = nButtonAmt + 1 + bUseExtra;

		UnitNode = &((sDescTreeNode *)NewDescTree->ChildNodes)[iUnitCtr];

		if (iUnitCtr < MVC_A_EXTRALOC)
		{
			//Set each description
			sprintf(UnitNode->szDesc, "%s", MVC_A_UNITDESC[iUnitCtr]);

			//Init each character to have all 6 basic buttons + extra
			UnitNode->ChildNodes = new sDescTreeNode[1];

			//All children have button trees
			UnitNode->uChildType = DESC_NODETYPE_TREE;
			UnitNode->uChildAmt = 1;

			for (int iButtonCtr = 0; iButtonCtr < 1; iButtonCtr++)
			{
				int nCurrChildAmt = GetPalCt(iUnitCtr); // 1 for each button for now

				ButtonNode = &((sDescTreeNode*)UnitNode->ChildNodes)[iButtonCtr];

				//Set each button data
				sprintf(ButtonNode->szDesc, "Palettes");

				//Button children have nodes
				ButtonNode->uChildType = DESC_NODETYPE_NODE;
				ButtonNode->uChildAmt = nCurrChildAmt;

				ButtonNode->ChildNodes = (sDescTreeNode*)new sDescNode[nCurrChildAmt];

				for (int nChildCtr = 0; nChildCtr < nCurrChildAmt; nChildCtr++)
				{
					//Set each button's node
					///////////////////////////////////////////////////////////////////////

					ChildNode = &((sDescNode*)ButtonNode->ChildNodes)[nChildCtr]; //We only have 1

					// Update this if you need new characters/palette lists
					if (iUnitCtr == indexRyu)
					{
						sprintf(ChildNode->szDesc, MVC_A_RYU_PALETTES[nChildCtr].szPaletteName);
					}
					else if (iUnitCtr == indexGief)
					{
						sprintf(ChildNode->szDesc, MVC_A_GIEF_PALETTES[nChildCtr].szPaletteName);
					}
					else if (iUnitCtr == indexMegaman)
					{
						sprintf(ChildNode->szDesc, MVC_A_MEGAMAN_PALETTES[nChildCtr].szPaletteName);
					}
					else if (iUnitCtr == indexShadowLady)
					{
						sprintf(ChildNode->szDesc, MVC_A_SHADOWLADY_PALETTES[nChildCtr].szPaletteName);
					}
					else if (iUnitCtr == indexAssists)
					{
						sprintf(ChildNode->szDesc, MVC_A_ASSIST_PALETTES[nChildCtr].szPaletteName);
					}
					else if (nChildCtr < ARRAYSIZE(MVC_A_IMGDESC)) // For the first 6 palettes we have a stock list of text to display.
					{
						sprintf(ChildNode->szDesc, MVC_A_IMGDESC[nChildCtr]);
					}
					else
					{
						sprintf(ChildNode->szDesc, "Palette %02X", nChildCtr);
					}

					ChildNode->uUnitId = iUnitCtr;
					ChildNode->uPalId = nChildCtr;
				}
			}
		}
		else
		{
			//Set each description
			sprintf(UnitNode->szDesc, "Extra Palettes");
			UnitNode->ChildNodes = new sDescTreeNode[1]; //Only 1 for now, "Extra"
			//All children have button trees
			UnitNode->uChildType = DESC_NODETYPE_TREE;
			UnitNode->uChildAmt = 1; //Only 1 for now, "Extra"
		}

		//Set up extra nodes
		if (bUseExtra)
		{
			int nExtraPos = GetExtraLoc(iUnitCtr);
			int nCurrExtra = 0; nExtraPos;

			stExtraDef* pCurrDef;

			ButtonNode = &((sDescTreeNode*)UnitNode->ChildNodes)[MVC_A_EXTRALOC > iUnitCtr ? (nMainChildAmt - 1) : 0]; //Extra node
			sprintf(ButtonNode->szDesc, "Extra");

			ButtonNode->ChildNodes = new sDescTreeNode[nExtraCt];

			ButtonNode->uChildType = DESC_NODETYPE_NODE;
			ButtonNode->uChildAmt = nExtraCt; //EX + Extra

			for (int nExtraCtr = 0; nExtraCtr < nExtraCt; nExtraCtr++)
			{

				ChildNode = &((sDescNode*)ButtonNode->ChildNodes)[nExtraCtr];

				pCurrDef = GetExtraDefForMVC(nExtraPos + nCurrExtra);

				while (pCurrDef->bInvisible == 1)
				{
					nCurrExtra++;

					pCurrDef = GetExtraDefForMVC(nExtraPos + nCurrExtra);
				}

				sprintf(ChildNode->szDesc, pCurrDef->szDesc);

				ChildNode->uUnitId = iUnitCtr;
				ChildNode->uPalId = (((MVC_A_EXTRALOC > iUnitCtr ? 1 : 0)* nButtonAmt * 2) + nSuppAmt) + nCurrExtra;

				nCurrExtra++;
			}
		}
	}

	return CDescTree(NewDescTree);
}

sFileRule CGame_MVC_A::GetRule(int nUnitId)
{	
	sFileRule NewFileRule;

	sprintf_s(NewFileRule.szFileName, MAX_FILENAME, "mvc.06");

	NewFileRule.uUnitId = 0;
	NewFileRule.uVerifyVar = 0x80000;

	return NewFileRule;
}

int CGame_MVC_A::GetPalCt(int nUnitId)
{
	if (nUnitId == MVC_A_EXTRALOC)
	{
		return GetExtraCt(nUnitId);
	}
	else
	{
		return MVC_A_PALAMT[nUnitId];
	}
}

void CGame_MVC_A::InitDataBuffer()
{
	pppDataBuffer = new UINT16 **[nUnitAmt];
	memset(pppDataBuffer, NULL, sizeof(UINT16 **) * nUnitAmt);
}

void CGame_MVC_A::ClearDataBuffer()
{
	if (pppDataBuffer)
	{
		for (int nUnitCtr = 0; nUnitCtr < nUnitAmt; nUnitCtr++)
		{
			if (pppDataBuffer[nUnitCtr])
			{
				int nPalAmt = GetPalCt(nUnitCtr);

				for (int nPalCtr = 0; nPalCtr < nPalAmt; nPalCtr++)
				{
					if (pppDataBuffer[nUnitCtr][nPalCtr])
					{
						delete[] pppDataBuffer[nUnitCtr][nPalCtr];
					}
				}

				delete[] pppDataBuffer[nUnitCtr];
			}
		}

		delete[] pppDataBuffer;
	}
}

void CGame_MVC_A::GetPalOffsSz(int nUnitId, int nPalId)
{
	if (nUnitId == MVC_A_NUMUNIT)
	{
		// This is where we handle all the palettes added in via Extra.
		int nBasicPos = GetBasicAmt(nUnitId);
		int nPortPos = nBasicPos * 2;
		int nExPos = 2 + nPortPos;
		int nExtraPos = 8 + nExPos;

		int nOffset, nPalSz;

		BOOL bUseExtra = FALSE;	
		
		nExtraPos = 0;
		bUseExtra = TRUE;

		stExtraDef* pCurrDef = GetExtraDefForMVC(GetExtraLoc(nUnitId) + (nPalId - nExtraPos));

		nOffset = pCurrDef->uOffset;
		nPalSz = pCurrDef->uPalSz;

		nCurrPalOffs = nOffset;
		nCurrPalSz = nPalSz / 2;
	}
	else
	{
		// Update this if you need new characters/palette lists
		switch (nUnitId)
		{
			case indexRyu:
			{
				nCurrPalOffs = MVC_A_RYU_PALETTES[nPalId].nPaletteOffset;
				break;
			}
			case indexGief:
			{
				nCurrPalOffs = MVC_A_GIEF_PALETTES[nPalId].nPaletteOffset;
				break;
			}
			case indexMegaman:
			{
				nCurrPalOffs = MVC_A_MEGAMAN_PALETTES[nPalId].nPaletteOffset;
				break;
			}
			case indexShadowLady:
			{
				nCurrPalOffs = MVC_A_SHADOWLADY_PALETTES[nPalId].nPaletteOffset;
				break;
			}
			case indexAssists: // Assists
			{
				nCurrPalOffs = MVC_A_ASSIST_PALETTES[nPalId].nPaletteOffset;
				break;
			}
			default:
			{
				// This is all the base palettes.
				nCurrPalOffs = MVC_A_UNITLOC[nUnitId] + (nPalId * 0x20);
				break;
			}
		};
		nCurrPalSz = 16;
	}
}

BOOL CGame_MVC_A::LoadFile(CFile * LoadedFile, int nUnitId)
{
	int nPalAmt;

	for(int nUnitCtr = 0; nUnitCtr < nUnitAmt; nUnitCtr++)
	{
		nPalAmt = GetPalCt(nUnitCtr);

		pppDataBuffer[nUnitCtr] = new UINT16 *[nPalAmt];

		rgUnitRedir[nUnitCtr] = MVC_A_UNITSORT[nUnitCtr]; //Fix later for unit sort

		for(int nPalCtr = 0; nPalCtr < nPalAmt; nPalCtr++)
		{
			GetPalOffsSz(nUnitCtr, nPalCtr);

			pppDataBuffer[nUnitCtr][nPalCtr] = new UINT16 [nCurrPalSz];
			
			LoadedFile->Seek(nCurrPalOffs, CFile::begin);
			
			LoadedFile->Read(pppDataBuffer[nUnitCtr][nPalCtr], nCurrPalSz*2);
		}
	}

	rgUnitRedir[nUnitAmt] = 0xFF;

	return TRUE;
}

BOOL CGame_MVC_A::SaveFile(CFile * SaveFile, int nUnitId)
{
	for(int nUnitCtr = 0; nUnitCtr < nUnitAmt; nUnitCtr++)
	{
		int nPalAmt = GetPalCt(nUnitCtr);

		for(int nPalCtr = 0; nPalCtr < nPalAmt; nPalCtr++)
		{
			GetPalOffsSz(nUnitCtr, nPalCtr);
			
			SaveFile->Seek(nCurrPalOffs, CFile::begin);
			
			SaveFile->Write(pppDataBuffer[nUnitCtr][nPalCtr], nCurrPalSz*2);
		}
	}

	return TRUE;
}

void CGame_MVC_A::CreateDefPal(sDescNode * srcNode, int nSepId)
{
	int nUnitId = srcNode->uUnitId;
	int nPalId = srcNode->uPalId;

	GetPalOffsSz(nUnitId, nPalId);

	BasePalGroup.AddPal(CreatePal(nUnitId, nPalId), nCurrPalSz, nUnitId, nPalId);
	BasePalGroup.AddSep(nSepId, srcNode->szDesc, 0, nCurrPalSz);
}

BOOL CGame_MVC_A::UpdatePalImg(int Node01, int Node02, int Node03, int Node04)
{
	//Reset palette sources
	ClearSrcPal();

	if(Node01 == -1)
	{
		return FALSE;
	}

	UINT8 uUnitId;
	UINT16 uPalId;

	sDescNode * NodeGet = MainDescTree.GetDescNode(Node01, Node02, Node03, Node04);

	if(NodeGet == NULL)
	{
		return FALSE;
	}

	uUnitId = NodeGet->uUnitId;
	uPalId = NodeGet->uPalId;

	//Change the image id if we need to
	nTargetImgId = 0;
	int nImgUnitId = (uUnitId == MVC_A_EXTRALOC ) ? 0xFF : MVC_A_IMGREDIR[uUnitId];

	int nSrcStart = 0;
	int nSrcAmt = 1;//GetBasicAmt(uUnitId);

	//Get rid of any palettes if there are any
	BasePalGroup.FlushPalAll();	
	
	//Create the default palette
	ClearSetImgTicket(CreateImgTicket(nImgUnitId, nTargetImgId));

	CreateDefPal(NodeGet, 0);

	SetSourcePal(0, uUnitId, nSrcStart, nSrcAmt, 1);

	return TRUE;
}

COLORREF * CGame_MVC_A::CreatePal(int nUnitId, int nPalId)
{
	GetPalOffsSz(nUnitId, nPalId);

	COLORREF * NewPal = new COLORREF[nCurrPalSz];

	for(int i = 0; i < nCurrPalSz-1; i++)
	{
		NewPal[i+1] = ConvPal(pppDataBuffer[nUnitId][nPalId][i]) | 0xFF000000;
	}

	NewPal[0] = 0xFF000000;

	return NewPal;
}

void CGame_MVC_A::UpdatePalData()
{
	for(int nPalCtr = 0; nPalCtr < MAX_PAL; nPalCtr++)
	{
		sPalDef * srcDef = BasePalGroup.GetPalDef(nPalCtr);

		if(srcDef->bAvail )
		{
			int nIndexStart = 1;

			COLORREF * crSrc = srcDef->pPal;
			UINT16 uAmt = srcDef->uPalSz;

			for(int nPICtr = nIndexStart; nPICtr < uAmt; nPICtr++)
			{
				pppDataBuffer[srcDef->uUnitId][srcDef->uPalId][nPICtr - nIndexStart] = (ConvCol(crSrc[nPICtr]) & 0x0FFF);
			}

			srcDef->bChanged = FALSE;
			bFileChanged[0] = TRUE;
		}
	}
}