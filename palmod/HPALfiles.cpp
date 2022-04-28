#include "stdafx.h"
#include "PalMod.h"
#include "PalModDlg.h"
#include "Game\BlazBlueCF_S_DEF.h"

// CFPL and HPAL are BBCF color palette files.
// HPAL is for one 256 color BGRA palette.
// CFPL is a collection of eight 256 color BGRA palettes: exactly enough for one full character

bool CPalModDlg::LoadPaletteFromCFPL(LPCWSTR pszFileName)
{
    bool fSuccess = false;

    CFile CFPLFile;
    if (CFPLFile.Open(pszFileName, CFile::modeRead | CFile::typeBinary))
    {
        // CFPLs are 8344 bytes (0x2098 bytes) long.
        // There is a 32 byte header followed by a text section (32b per section) followed by
        // 8 sets of 256 ARGB colors.
        // Header:
            // 0x00-0x08 IMPLCF signature
            // 0x08-0x0c header length
            // 0x0c-0x10 data length
            // 0x10-0x14 character ID
            // 0x14-0x34 customized palette name
            // 0x34-0x54 optional creator name 
            // 0x54-0x94 optional description
            // 0x94      "has bloom"
        const size_t k_nRequiredFileSize = 0x2098;
        const uint8_t k_nCFPLSignatureLength = 0x10;
        const uint8_t k_nCFPLHeaderLength = 0x95;

        bool fFileIsValidCFPL = false;

        // Read data from the CFPL...
        if (CFPLFile.GetLength() == k_nRequiredFileSize)
        {
            const std::array<uint8_t, k_nCFPLSignatureLength> k_rgCFPLSignature =
            {
                0x49, 0x4d, 0x50, 0x4c, 0x43, 0x46, 0x00, 0x00, // I M P L C F
                0x14, 0x00, 0x00, 0x00, 0x81, 0x20, 0x00, 0x00, // header size, data size: we're going to lock to 0x2098 files for now.
            };

            std::array<uint8_t, k_nCFPLSignatureLength> rgHeaderBytes = {};

            CFPLFile.Seek(0, CFile::begin);
            CFPLFile.Read(&rgHeaderBytes, k_nCFPLSignatureLength);
            uint8_t nMatchCount = 0;

            for (size_t nPos = 0; nPos < k_nCFPLSignatureLength; nPos++)
            {
                if (rgHeaderBytes[nPos] == k_rgCFPLSignature[nPos])
                {
                    nMatchCount++;
                }
                else
                {
                    break;
                }
            }

            if (nMatchCount == k_nCFPLSignatureLength)
            {
                fFileIsValidCFPL = true;
            }
        }

        uint16_t nCollectionIndex = 0;
        bool fFoundCharacter = false;

        if (fFileIsValidCFPL)
        {
            uint8_t nCharacterToApplyTo = 0;
            CFPLFile.Read(&nCharacterToApplyTo, 1);

            for (; nCollectionIndex < BlazBlueCF_S_CharacterData.size(); nCollectionIndex++)
            {
                if (BlazBlueCF_S_CharacterData[nCollectionIndex].nBBCFIMId == nCharacterToApplyTo)
                {
                    fFoundCharacter = true;
                    break;
                }
            }
        }

        uint8_t nColorPositionToWriteTo = -1;

        if (fFoundCharacter)
        {
            if (m_nPrevUnitSel == nCollectionIndex) // This character is being displayed
            {
                nColorPositionToWriteTo = m_nPrevChildSel1;
            }
            else
            {
                nColorPositionToWriteTo = 0;
            }
        }

        if (nColorPositionToWriteTo < BlazBlueCF_S_CharacterData[nCollectionIndex].ppszCollectionList.size())
        {
            const uint16_t k_nColorsPerPalette = 256; // An CFPL has 8 sets of 256 (1024 bytes / 4 bytes per color) colors.
            const uint8_t k_nBytesPerColor = 4;
            const size_t k_nColorDataSize = k_nColorsPerPalette * k_nBytesPerColor;
            const uint8_t k_nPalettesPerFile = 8;
            const uint16_t k_nStartingPaletteAdjustment = k_nPalettesPerFile * nColorPositionToWriteTo;

            std::array<uint8_t, k_nColorDataSize> rgCFPL = {};

            CFPLFile.Seek(k_nCFPLHeaderLength, CFile::begin);

            for (uint8_t nPaletteId = 0; nPaletteId < k_nPalettesPerFile; nPaletteId++)
            {
                uint8_t rgConvertedPalette[k_nColorDataSize] = {};

                CFPLFile.Read(&rgCFPL, rgCFPL.size());

                for (size_t nPaletteIndex = 0; nPaletteIndex < k_nColorsPerPalette; nPaletteIndex++)
                {
                    // incoming is BGRA, so flip to be RBGA
                    rgConvertedPalette[(nPaletteIndex * 4) + 2] = GetHost()->GetCurrGame()->GetNearestLegal8BitColorValue_RGB(rgCFPL[(nPaletteIndex * k_nBytesPerColor)]);
                    rgConvertedPalette[(nPaletteIndex * 4) + 1] = GetHost()->GetCurrGame()->GetNearestLegal8BitColorValue_RGB(rgCFPL[(nPaletteIndex * k_nBytesPerColor) + 1]);
                    rgConvertedPalette[(nPaletteIndex * 4)] = GetHost()->GetCurrGame()->GetNearestLegal8BitColorValue_RGB(rgCFPL[(nPaletteIndex * k_nBytesPerColor) + 2]);
                    rgConvertedPalette[(nPaletteIndex * 4) + 3] = GetHost()->GetCurrGame()->GetNearestLegal8BitColorValue_A(rgCFPL[(nPaletteIndex * k_nBytesPerColor) + 3]);
                }

                GetHost()->GetCurrGame()->WritePal(nCollectionIndex, nPaletteId + k_nStartingPaletteAdjustment, (COLORREF *)&rgConvertedPalette, k_nColorsPerPalette);
                GetHost()->GetCurrGame()->MarkPaletteDirty(nCollectionIndex, nPaletteId + k_nStartingPaletteAdjustment);
            }

            CFPLFile.Close();

            if ((m_nPrevUnitSel == nCollectionIndex) &&
                (m_nPrevChildSel1 == nColorPositionToWriteTo))
            {
                // They're currently displaying this palette: reload
                UpdateCombo(true);
            }            

            // Mark the file load dirty.  We don't mark the palettes dirty-to-user as we don't have an Undo here.
            m_fFileChanged = TRUE;

            fSuccess = true;
            CString strStatus;
            strStatus.Format(IDS_CFPL_LOADED, BlazBlueCF_S_CharacterData[nCollectionIndex].pszCharacter, BlazBlueCF_S_CharacterData[nCollectionIndex].ppszCollectionList[nColorPositionToWriteTo]);
            SetStatusText(strStatus);
        }
    }

    if (!fSuccess)
    {
        CString strError;
        if (strError.LoadString(IDS_ERROR_LOADING_PALETTE_FILE))
        {
            MessageBox(strError, GetHost()->GetAppName(), MB_ICONERROR);
        }
        SetStatusText(IDS_CFPL_LOADFAILURE);
    }

    return fSuccess;
}

bool CPalModDlg::LoadPaletteFromHPAL(LPCWSTR pszFileName)
{
    bool fSuccess = false;

    CFile HPALFile;
    if (HPALFile.Open(pszFileName, CFile::modeRead | CFile::typeBinary))
    {
        ProcChange();

        // HPALs are 1056 bytes (0x420 bytes) long.
        // There is a 40 byte header followed by 256 BGRA colors.
        const size_t k_nRequiredFileSize = 0x420;
        const uint8_t k_nHPALHeaderLength = 32;

        bool fFileIsValidHPAL = false;

        // Read data from the HPAL...
        if (HPALFile.GetLength() == k_nRequiredFileSize)
        {
            const std::array<uint8_t, k_nHPALHeaderLength> k_rgHPALHeader =
            {
                0x48, 0x50, 0x41, 0x4c, // H P A L
                                        0x25, 0x01, 0x00, 0x00,
                0x20, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00,
            };

            std::array<uint8_t, k_nHPALHeaderLength> rgHeaderBytes = {};

            HPALFile.Seek(0, CFile::begin);
            HPALFile.Read(&rgHeaderBytes, k_nHPALHeaderLength);
            uint8_t nMatchCount = 0;

            for (size_t nPos = 0; nPos < k_nHPALHeaderLength; nPos++)
            {
                if (rgHeaderBytes[nPos] == k_rgHPALHeader[nPos])
                {
                    nMatchCount++;
                }
                else
                {
                    break;
                }
            }

            if (nMatchCount == k_nHPALHeaderLength)
            {
                fFileIsValidHPAL = true;
            }
        }

        if (fFileIsValidHPAL)
        {
            const uint16_t k_nHPALColorCount = 256; // An HPAL by default has 256 (1024 bytes / 4 bytes per color) colors.
            const uint8_t k_nBytesPerColor = 4;
            const size_t k_nColorDataSize = k_nHPALColorCount * k_nBytesPerColor;

            std::array<uint8_t, k_nColorDataSize> rgHPAL = {};

            HPALFile.Seek(k_nHPALHeaderLength, CFile::begin);
            HPALFile.Read(&rgHPAL, rgHPAL.size());
            HPALFile.Close();

            // Now consume those colors...
            const uint8_t nTotalPaletteCount = MainPalGroup->GetPalAmt();
            size_t nTotalNumberOfCurrentColors = 0;

            for (size_t nPalette = 0; nPalette < nTotalPaletteCount; nPalette++)
            {
                nTotalNumberOfCurrentColors += MainPalGroup->GetPalDef(nPalette)->uPalSz;
            }

            uint16_t iHPALIndex = 0;
            uint16_t nCurrentPalette = 0;
            uint16_t nTotalColorsUsed = 0;
            bool fHaveLooped = false;
            uint16_t iCurrentIndexInPalette = 0;
            uint8_t* pPal = (uint8_t*)MainPalGroup->GetPalDef(nCurrentPalette)->pPal;

            bool fHaveMultiplePalettes = (nTotalPaletteCount != 1);
            bool* rgfHPALHasColorsForThisPalette = new bool[nTotalPaletteCount];
            memset(rgfHPALHasColorsForThisPalette, false, sizeof(bool) * nTotalPaletteCount);

            if (fHaveMultiplePalettes)
            {
                // we have multiple palettes: ensure that we only use useful data from the HPAL
                uint16_t nOffsetThisPass = 0;
                for (uint8_t iPalette = 0; iPalette < nTotalPaletteCount; iPalette++)
                {
                    for (iHPALIndex = nOffsetThisPass; (iHPALIndex < k_nHPALColorCount) && ((iHPALIndex - nOffsetThisPass) < MainPalGroup->GetPalDef(iPalette)->uPalSz); iHPALIndex++)
                    {
                        uint16_t iIndexToUse = iHPALIndex;
                        if ((rgHPAL[(iIndexToUse * k_nBytesPerColor)] != 0) ||
                            (rgHPAL[(iIndexToUse * k_nBytesPerColor) + 1] != 0) ||
                            (rgHPAL[(iIndexToUse * k_nBytesPerColor) + 2] != 0) ||
                            (rgHPAL[(iIndexToUse * k_nBytesPerColor) + 3] != 0))
                        {
                            rgfHPALHasColorsForThisPalette[iPalette] = true;
                            break;
                        }
                    }

                    nOffsetThisPass += MainPalGroup->GetPalDef(iPalette)->uPalSz;
                }
            }

            iHPALIndex = 0;

            for (size_t iAbsolutePaletteIndex = 0; iAbsolutePaletteIndex < nTotalNumberOfCurrentColors; iAbsolutePaletteIndex++, nTotalColorsUsed++)
            {
                // incoming is BGRA, so flip to be RBGA
                pPal[(iCurrentIndexInPalette * 4) + 2] = GetHost()->GetCurrGame()->GetNearestLegal8BitColorValue_RGB(rgHPAL[(iHPALIndex * k_nBytesPerColor)]);
                pPal[(iCurrentIndexInPalette * 4) + 1] = GetHost()->GetCurrGame()->GetNearestLegal8BitColorValue_RGB(rgHPAL[(iHPALIndex * k_nBytesPerColor) + 1]);
                pPal[(iCurrentIndexInPalette * 4)] = GetHost()->GetCurrGame()->GetNearestLegal8BitColorValue_RGB(rgHPAL[(iHPALIndex * k_nBytesPerColor) + 2]);
                pPal[(iCurrentIndexInPalette * 4) + 3] = GetHost()->GetCurrGame()->GetNearestLegal8BitColorValue_A(rgHPAL[(iHPALIndex * k_nBytesPerColor) + 3]);

                if (++iHPALIndex >= k_nHPALColorCount)
                {
                    // If the palette is larger than our HPAL, loop it.
                    iHPALIndex = 0;
                    fHaveLooped = true;
                }

                iCurrentIndexInPalette++;
                if (((nCurrentPalette + 1) < nTotalPaletteCount) && (iCurrentIndexInPalette == MainPalGroup->GetPalDef(nCurrentPalette)->uPalSz))
                {
                    if (fHaveLooped)
                    {
                        // Applying a looping palette to a secondary palette will be generally illogical, so don't
                        nTotalColorsUsed++;
                        break;
                    }
                    else
                    {
                        // advance to the next palette
                        nCurrentPalette++;

                        if (rgfHPALHasColorsForThisPalette[nCurrentPalette])
                        {
                            iCurrentIndexInPalette = 0;
                            pPal = (uint8_t*)MainPalGroup->GetPalDef(nCurrentPalette)->pPal;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }

            safe_delete_array(rgfHPALHasColorsForThisPalette);

            ImgDispCtrl->UpdateCtrl();
            m_PalHost.UpdateAllPalCtrls();

            UpdateMultiEdit(TRUE);
            UpdateSliderSel();

            fSuccess = true;
            CString strStatus;
            strStatus.Format(IDS_HPAL_LOADED, nTotalColorsUsed, k_nHPALColorCount);
            SetStatusText(strStatus);
        }
    }

    if (!fSuccess)
    {
        CString strError;
        if (strError.LoadString(IDS_ERROR_LOADING_PALETTE_FILE))
        {
            MessageBox(strError, GetHost()->GetAppName(), MB_ICONERROR);
        }
        SetStatusText(IDS_HPAL_LOADFAILURE);
    }

    return fSuccess;
}
