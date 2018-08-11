#include "stdafx.h"
#include <string.h>
#include "Step2Dlg.h"

#pragma warning(disable: 4355)
  // 'this' used in base member initialization list

BEGIN_MESSAGE_MAP(CStep2Dlg)
    { WM_INITDIALOG, (CCmdTargetFunPointer)&CStep2Dlg::OnInitDialog },
    { WM_COMMAND,    (CCmdTargetFunPointer)&CStep2Dlg::OnCommand },
END_MESSAGE_MAP()

CStep2Dlg::CStep2Dlg(CObject* pParent /*= NULL*/) : CDialog(this)
{
    //{{AFX_DATA_INIT(CStep4Dlg)
    strcpy(m_strEdit1, "");
    //}}AFX_DATA_INIT
}//CStep2Dlg::CStep2Dlg()

CStep2Dlg::~CStep2Dlg()
{
}//CStep2Dlg::~CStep2Dlg()

void CStep2Dlg::DoDataExchange(CDataExchange* pDX)
{
    //CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CStep2Dlg)
    //DDX_Text(pDX, IDC_EDIT1, m_strEdit1);
    //}}AFX_DATA_MAP
}//void CStep2Dlg::DoDataExchange()

//----------------------------------------------------------------
// Name: OnInitDialog()
// Desc: this function may be virtual in MFC. Why?
void CStep2Dlg::OnInitDialog(WPARAM wParam, LPARAM lParam)
{
    //hEdit1 = GetDlgItem(hDlg, IDC_EDIT1);
    //SetFocus( hEdit1 );
    
    SetDlgItemText(m_hDlg, IDC_EDIT1, m_strEdit1);
}//CStep2Dlg::OnInitDialog()

void CStep2Dlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
    switch ( LOWORD(wParam) )
    {
    case IDOK:
        GetDlgItemText(m_hDlg, IDC_EDIT1, m_strEdit1, 19);
        EndDialog(m_hDlg, IDOK);
        break;
        
    case IDCANCEL:
        EndDialog(m_hDlg, IDCANCEL) ;
        break;
    }//switch
}//CStep2Dlg::OnCommand()
