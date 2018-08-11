#if !defined(_CDIALOG_DEFINED_)
#define _CDIALOG_DEFINED_

#include "CObject.h"
#include "DataExchange.h"
#include "CWnd.h"

//{{ seojt: 2003-11-12 ¿ÀÀü 11:00:23
void DDX_Text(CDataExchange* pDX, UINT id, char* str);
//}} seojt

class CDialog : public CWnd
{
public:
    static CDialog* m_pDlgObject; // real dialog object pointer
    static CDialog* GetDialogFromHandle(HWND hDlg);

    CDialog(CDialog* pDlgObject);
    virtual ~CDialog();

    int UpdateData(int bSaveAndValidate = 1);
    int DoModal();

protected:
    virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV support
};//class CDialog

#endif // !defined(_CDIALOG_DEFINED_)
