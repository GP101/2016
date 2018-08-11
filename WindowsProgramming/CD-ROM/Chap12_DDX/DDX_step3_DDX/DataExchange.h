#if !defined(_CDATAEXCHANGE_DEFINED_)
#define _CDATAEXCHANGE_DEFINED_

#include "CWnd.h"

class CDataExchange
{
// Attributes
public:
    BOOL m_bSaveAndValidate;   // TRUE => save and validate data
    CWnd* m_pDlgWnd;           // container usually a dialog

    /*
// Operations (for implementors of DDX and DDV procs)
    HWND PrepareCtrl(int nIDC);     // return HWND of control
    HWND PrepareEditCtrl(int nIDC); // return HWND of control
    void Fail();                    // will throw exception

#ifndef _AFX_NO_OCC_SUPPORT
    CWnd* PrepareOleCtrl(int nIDC); // for OLE controls in dialog
#endif
    */
// Implementation
    CDataExchange(CWnd* pDlgWnd, BOOL bSaveAndValidate);
    /*
    HWND m_hWndLastControl;    // last control used (for validation)
    BOOL m_bEditLastControl;   // last control was an edit item
    */
};//class CDataExchange

#endif // !defined(_CDATAEXCHANGE_DEFINED_)
