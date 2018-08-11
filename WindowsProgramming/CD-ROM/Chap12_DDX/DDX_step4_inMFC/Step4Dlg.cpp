// Step4Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "DDX_step4.h"
#include "Step4Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStep4Dlg dialog


CStep4Dlg::CStep4Dlg(CWnd* pParent /*=NULL*/)
    : CDialog(CStep4Dlg::IDD, pParent)
{
    //{{AFX_DATA_INIT(CStep4Dlg)
    m_strEdit1 = _T("");
    //}}AFX_DATA_INIT
}


void CStep4Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CStep4Dlg)
    DDX_Text(pDX, IDC_EDIT1, m_strEdit1);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStep4Dlg, CDialog)
    //{{AFX_MSG_MAP(CStep4Dlg)
        // NOTE: the ClassWizard will add message map macros here
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStep4Dlg message handlers
