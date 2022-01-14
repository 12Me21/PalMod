#include "StdAfx.h"
#include "GameDef.h"
#include "Game_RANMACRH_SNES.h"
#include "..\PalMod.h"
#include "..\RegProc.h"

UINT32 CGame_RANMACRH_SNES::m_nExpectedGameROMSize = 0x280000;

CGame_RANMACRH_SNES::CGame_RANMACRH_SNES(UINT32 nConfirmedROMSize)
{
    OutputDebugString(L"CGame_RANMACRH_SNES::CGame_RANMACRH_SNES: Loading ROM...\n");

    createPalOptions = { NO_SPECIAL_OPTIONS, WRITE_16 };

    SetAlphaMode(AlphaMode::GameDoesNotUseAlpha);
    SetColorMode(ColMode::COLMODE_BGR555_LE);

    // The value passed in to us was the confirmed ROM size we have.
    // We keep track of this before we initialize so that we can truncate bad Extras correctly on load.
    // Otherwise the new user could inadvertently corrupt their ROM.
    m_nConfirmedROMSize = nConfirmedROMSize;
    InitializeStatics();

    m_nTotalInternalUnits = RANMACRH_SNES_NUMUNIT;
    m_nExtraUnit = RANMACRH_SNES_EXTRALOC;

    m_nSafeCountForThisRom = GetExtraCt(m_nExtraUnit) + 52;
    m_pszExtraFilename = EXTRA_FILENAME_RANMACRH_SNES;
    m_nTotalPaletteCount = m_nTotalPaletteCountForRANMACRH;

    m_nLowestKnownPaletteRomLocation = 0x62be2;

    nUnitAmt = m_nTotalInternalUnits + (GetExtraCt(m_nExtraUnit) ? 1 : 0);

    InitDataBuffer();

    nGameFlag = RANMACRH_SNES;

    nImgGameFlag = IMGDAT_SECTION_SNES;
    m_prgGameImageSet = RANMACRH_SNES_IMGIDS_USED;

    nFileAmt = 1;

    //Set the image out display type
    DisplayType = eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT;
    // Button labels are used for the Export Image dialog
    pButtonLabelSet = DEF_BUTTONLABEL_4P; // Check out the available options in buttondef.h

    //Create the redirect buffer
    rgUnitRedir = new size_t[nUnitAmt + 1];
    memset(rgUnitRedir, NULL, sizeof(size_t) * nUnitAmt);

    //Create the file changed flag
    PrepChangeTrackingArray();
}

//
//  ***************************************************************************************************************************************
//  You don't need to make any further changes to the rest of this file, other than updating RANMACRH to your game's short name.
//  ***************************************************************************************************************************************
//

stExtraDef* CGame_RANMACRH_SNES::RANMACRH_SNES_EXTRA_CUSTOM = nullptr;
CDescTree CGame_RANMACRH_SNES::MainDescTree = nullptr;
size_t CGame_RANMACRH_SNES::rgExtraCountAll[RANMACRH_SNES_NUMUNIT + 1];
size_t CGame_RANMACRH_SNES::rgExtraLoc[RANMACRH_SNES_NUMUNIT + 1];
UINT32 CGame_RANMACRH_SNES::m_nTotalPaletteCountForRANMACRH = 0;
UINT32 CGame_RANMACRH_SNES::m_nConfirmedROMSize = -1;

void CGame_RANMACRH_SNES::InitializeStatics()
{
    safe_delete_array(CGame_RANMACRH_SNES::RANMACRH_SNES_EXTRA_CUSTOM);

    memset(rgExtraCountAll, -1, sizeof(rgExtraCountAll));
    memset(rgExtraLoc, -1, sizeof(rgExtraLoc));

    MainDescTree.SetRootTree(CGame_RANMACRH_SNES::InitDescTree());
}

CGame_RANMACRH_SNES::~CGame_RANMACRH_SNES(void)
{
    safe_delete_array(CGame_RANMACRH_SNES::RANMACRH_SNES_EXTRA_CUSTOM);
    ClearDataBuffer();
    //Get rid of the file changed flag
    FlushChangeTrackingArray();
}

CDescTree* CGame_RANMACRH_SNES::GetMainTree()
{
    return &CGame_RANMACRH_SNES::MainDescTree;
}

size_t CGame_RANMACRH_SNES::GetExtraCt(size_t nUnitId, BOOL bCountVisibleOnly)
{
    return _GetExtraCount(rgExtraCountAll, RANMACRH_SNES_NUMUNIT, nUnitId, RANMACRH_SNES_EXTRA_CUSTOM);
}

size_t CGame_RANMACRH_SNES::GetExtraLoc(size_t nUnitId)
{
    return _GetExtraLocation(rgExtraLoc, RANMACRH_SNES_NUMUNIT, nUnitId, RANMACRH_SNES_EXTRA_CUSTOM);
}

sDescTreeNode* CGame_RANMACRH_SNES::InitDescTree()
{
    //Load extra file if we're using it
    LoadExtraFileForGame(EXTRA_FILENAME_RANMACRH_SNES, &RANMACRH_SNES_EXTRA_CUSTOM, RANMACRH_SNES_EXTRALOC, m_nConfirmedROMSize);

    UINT16 nUnitCt = RANMACRH_SNES_NUMUNIT + (GetExtraCt(RANMACRH_SNES_EXTRALOC) ? 1 : 0);
    
    sDescTreeNode* NewDescTree = new sDescTreeNode;

    //Create the main character tree
    _snwprintf_s(NewDescTree->szDesc, ARRAYSIZE(NewDescTree->szDesc), _TRUNCATE, L"%s", g_GameFriendlyName[RANMACRH_SNES]);
    NewDescTree->ChildNodes = new sDescTreeNode[nUnitCt];
    NewDescTree->uChildAmt = nUnitCt;
    //All units have tree children
    NewDescTree->uChildType = DESC_NODETYPE_TREE;

    m_nTotalPaletteCountForRANMACRH = _InitDescTree(NewDescTree,
        RANMACRH_SNES_UNITS,
        RANMACRH_SNES_EXTRALOC,
        RANMACRH_SNES_NUMUNIT,
        rgExtraCountAll,
        rgExtraLoc,
        RANMACRH_SNES_EXTRA_CUSTOM
    );

    return NewDescTree;
}

sFileRule CGame_RANMACRH_SNES::GetRule(size_t nUnitId)
{
    sFileRule NewFileRule;

    // This value is only used for directory-based games
    _snwprintf_s(NewFileRule.szFileName, ARRAYSIZE(NewFileRule.szFileName), _TRUNCATE, RANMACRH_SNES_PRIMARY_ROMNAME);

    NewFileRule.uUnitId = 0;
    NewFileRule.uVerifyVar = m_nExpectedGameROMSize;

    return NewFileRule;
}

size_t CGame_RANMACRH_SNES::GetCollectionCountForUnit(size_t nUnitId)
{
    return _GetCollectionCountForUnit(RANMACRH_SNES_UNITS, rgExtraCountAll, RANMACRH_SNES_NUMUNIT, RANMACRH_SNES_EXTRALOC, nUnitId, RANMACRH_SNES_EXTRA_CUSTOM);
}

size_t CGame_RANMACRH_SNES::GetNodeCountForCollection(size_t nUnitId, size_t nCollectionId)
{
    return _GetNodeCountForCollection(RANMACRH_SNES_UNITS, rgExtraCountAll, RANMACRH_SNES_NUMUNIT, RANMACRH_SNES_EXTRALOC, nUnitId, nCollectionId, RANMACRH_SNES_EXTRA_CUSTOM);
}

LPCWSTR CGame_RANMACRH_SNES::GetDescriptionForCollection(size_t nUnitId, size_t nCollectionId)
{
    return _GetDescriptionForCollection(RANMACRH_SNES_UNITS, RANMACRH_SNES_EXTRALOC, nUnitId, nCollectionId);
}

size_t CGame_RANMACRH_SNES::GetPaletteCountForUnit(size_t nUnitId)
{
    return _GetPaletteCountForUnit(RANMACRH_SNES_UNITS, rgExtraCountAll, RANMACRH_SNES_NUMUNIT, RANMACRH_SNES_EXTRALOC, nUnitId, RANMACRH_SNES_EXTRA_CUSTOM);
}

const sGame_PaletteDataset* CGame_RANMACRH_SNES::GetPaletteSet(size_t nUnitId, size_t nCollectionId)
{
    return _GetPaletteSet(RANMACRH_SNES_UNITS, nUnitId, nCollectionId);
}

const sDescTreeNode* CGame_RANMACRH_SNES::GetNodeFromPaletteId(size_t nUnitId, size_t nPaletteId, bool fReturnBasicNodesOnly)
{
    return _GetNodeFromPaletteId(RANMACRH_SNES_UNITS, rgExtraCountAll, RANMACRH_SNES_NUMUNIT, RANMACRH_SNES_EXTRALOC, nUnitId, nPaletteId, RANMACRH_SNES_EXTRA_CUSTOM, fReturnBasicNodesOnly);
}

const sGame_PaletteDataset* CGame_RANMACRH_SNES::GetSpecificPalette(size_t nUnitId, size_t nPaletteId)
{
    return _GetSpecificPalette(RANMACRH_SNES_UNITS, rgExtraCountAll, RANMACRH_SNES_NUMUNIT, RANMACRH_SNES_EXTRALOC, nUnitId, nPaletteId, RANMACRH_SNES_EXTRA_CUSTOM);
}

void CGame_RANMACRH_SNES::LoadSpecificPaletteData(size_t nUnitId, size_t nPalId)
{
     if (nUnitId != RANMACRH_SNES_EXTRALOC)
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
    else // RANMACRH_SNES_EXTRALOC
    {
        // This is where we handle all the palettes added in via Extra.
        stExtraDef* pCurrDef = (stExtraDef*)&RANMACRH_SNES_EXTRA_CUSTOM[GetExtraLoc(nUnitId) + nPalId];

        m_nCurrentPaletteROMLocation = pCurrDef->uOffset;
        m_nCurrentPaletteSizeInColors = (pCurrDef->cbPaletteSize / m_nSizeOfColorsInBytes);
        m_pszCurrentPaletteName = pCurrDef->szDesc;
    }
}

BOOL CGame_RANMACRH_SNES::UpdatePalImg(int Node01, int Node02, int Node03, int Node04)
{
    return _UpdatePalImg(RANMACRH_SNES_UNITS, rgExtraCountAll, RANMACRH_SNES_NUMUNIT, RANMACRH_SNES_EXTRALOC, RANMACRH_SNES_EXTRA_CUSTOM, Node01, Node02, Node03, Node03);
}
