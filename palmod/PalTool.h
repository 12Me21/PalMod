#pragma once

#include "afxwin.h"
#include "Junk.h"

#define PALTOOL_CLASSNAME    _T("CPalTool")  // Window class name

#define MAX_PALETTE        16

#define PAL_TXT_SPACE    5

#define ID_PALTOOLSPIN    0xFF00
#define PT_PAGECHANGE    WM_USER - 100

struct sPalEntry
{
    CJunk* PaletteCtrl = nullptr;
    CHAR* szPalStr = nullptr;
    UCHAR bAvail;
};

class CPalTool : public CWnd
{
private:
    sPalEntry pPalEntry[MAX_PALETTE];
    CSize PalSize[MAX_PALETTE];

    BOOL bFirstPaint;
    BOOL bSpinInit;

    CFont BaseFont;
    bool m_fFontisBold = true;
    int nFontHeight;

    int nNotifyCtrlIndex;

    CSpinButtonCtrl m_PgSpin;

    CRect rClient;

    int nCurrPage;
    int nPageAmt;
    int nCurrPalAmt;
    int nPrevPalAmt;

    int nPalViewH;
    UINT16 rgPalRedir[MAX_PALETTE + 1];

    void Init();

    void ClearBG(CPaintDC* PaintDC);
    void DrawText();

    void OnPalSelChange(int nCtrlId, BOOL bCurrPage = TRUE);

    void SendPalMsg(int nCtrlId, int nType);
    void SetFontToBold(bool beBold);

public:
    CPalTool(void);
    ~CPalTool(void);

    void CleanUp();

    void BeginSetPal();
    void EndSetPal();
    void SetPal(int nIndex, int nAmt, COLORREF* rgNewCol, CHAR* szNewPalStr);
    int GetNotifyIndex() { return nNotifyCtrlIndex; };
    CJunk* GetNotifyPal() { return pPalEntry[nNotifyCtrlIndex].PaletteCtrl; };
    CJunk* GetPalCtrl(int nIndex) { return pPalEntry[nIndex].bAvail ? pPalEntry[nIndex].PaletteCtrl : NULL; };

    void ResetNotifyIndex() { nNotifyCtrlIndex = 0; };

    BOOL CurrPalAvail() { return pPalEntry[nNotifyCtrlIndex].bAvail; };
    void ShowAvailPal();
    void UpdateCtrl();

    //void ResetNotifyPal(int nIndex){OnPalSelChange(0);SendPalMsg(nNotifyCtrlIndex);};

    BOOL RegisterWindowClass();

    DECLARE_MESSAGE_MAP()
    afx_msg void OnPaint();
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg void OnDeltaposSpin(NMHDR* pNMHDR, LRESULT* pResult);
    void SetNotifyFunc(int (*ExtPalSelChange)(int), int (*ExtPalHLChange)(int), int (*ExtPalMHL)(int));

public:
    void UpdateEveryIndex();
    void UpdateEveryCtrl();

protected:
    virtual void PreSubclassWindow();

public:
    virtual BOOL PreTranslateMessage(MSG* pMsg);
};
