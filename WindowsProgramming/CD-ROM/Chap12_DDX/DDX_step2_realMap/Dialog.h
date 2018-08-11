#if !defined(_CDIALOG_DEFINED_)
#define _CDIALOG_DEFINED_

#include "CObject.h"
#include "DataExchange.h"
#include "CWnd.h"

class CDialog : public CWnd
{
public:
    static HWND     m_hDlg;       // dialog window handle
    static CDialog* m_pDlgObject; // real dialog object pointer
    static CDialog* GetDialogFromHandle(HWND hDlg);

    CDialog(CDialog* pDlgObject);
    virtual ~CDialog();

    int UpdateData(int bSaveAndValidate = 1);
    int DoModal();

protected:
    //virtual function
    virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV support
};//class CDialog

#endif // !defined(_CDIALOG_DEFINED_)
