#include "stdafx.h"
#include "Dialog.h"
#include "CWinApp.h"

extern CWinApp app;

// Dialog Procedure --------------------------------------
int CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

CDialog* CDialog::m_pDlgObject = NULL; // dialog object pointer

/*static*/ CDialog* CDialog::GetDialogFromHandle(HWND hDlg)
{
    m_pDlgObject->m_hwnd = hDlg;
    return m_pDlgObject;
}//CDialog::GetDialogFromHandle()

CDialog::CDialog(CDialog* pDlgObject)
{
    m_pDlgObject = pDlgObject;     // pointer to a dialog object
}//CDialog::CDialog()

CDialog::~CDialog()
{
}//CDialog::~CDialog()

/*virtual*/ void CDialog::DoDataExchange(CDataExchange* pDX)
{
}//CDialog::DoDataExchange()

int CDialog::UpdateData(int bSaveAndValidate /*= 1*/)
{
    CDataExchange dx(this, bSaveAndValidate);
    
    DoDataExchange(&dx);
    return 1;
}//CDialog::UpdateData()

int CDialog::DoModal()
{
    return DialogBox(
        app.GetInstanceHandle(),        // application instance handle
        "AboutBox",                     // actually IDD will be used
        app.GetMainWnd()->GetSafeHwnd(),// parent window handle
        DlgProc );                      // dialog procedure
}//CDialog::DoModal()

//{{ seojt: 2003-11-12 ¿ÀÀü 11:01:39
void DDX_Text(CDataExchange* pDX, UINT id, char* str)
{
    if ( pDX->m_bSaveAndValidate )
    {
        GetDlgItemText(pDX->m_pDlgWnd->GetSafeHwnd(), id, str, 19);
    }
    else
    {
        SetDlgItemText(pDX->m_pDlgWnd->GetSafeHwnd(), id, str);
    }//if.. else..
}//DDX_Text()
//}} seojt

//Dialog Window procedure-----------------------------------------
int CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam) 
{
    int                     i = 0;
    CCmdTarget*             pDialogWnd;
    const MessageMap*       pMessageMap;

    pDialogWnd  = CDialog::GetDialogFromHandle(hDlg);
    pMessageMap = pDialogWnd->GetMessageMap();

    while ( 0 != pMessageMap[i].iMsg )
    {
        if ( LOWORD(iMsg) == pMessageMap[i].iMsg )
        {
            (pDialogWnd->*pMessageMap[i].fp)(wParam, lParam);
            return TRUE;
        }//if
        ++i;
    }//while

    return FALSE;
}//DlgProc()
