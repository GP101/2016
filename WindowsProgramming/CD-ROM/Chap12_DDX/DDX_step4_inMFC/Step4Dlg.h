#if !defined(AFX_STEP4DLG_H__66F39CB5_60DC_11D4_A6B4_DDBEB76F6A27__INCLUDED_)
#define AFX_STEP4DLG_H__66F39CB5_60DC_11D4_A6B4_DDBEB76F6A27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Step4Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStep4Dlg dialog

class CStep4Dlg : public CDialog
{
// Construction
public:
    CStep4Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CStep4Dlg)
    enum { IDD = IDD_DIALOG1 };
    CString m_strEdit1;
    //}}AFX_DATA


// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CStep4Dlg)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    // Generated message map functions
    //{{AFX_MSG(CStep4Dlg)
        // NOTE: the ClassWizard will add member functions here
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STEP4DLG_H__66F39CB5_60DC_11D4_A6B4_DDBEB76F6A27__INCLUDED_)
