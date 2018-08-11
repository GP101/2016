#if !defined(_CSTEP2DLG_DEFINED_)
#define _CSTEP2DLG_DEFINED_

#include "CObject.h"
#include "DataExchange.h"
#include "Dialog.h"
#include "Resource.h"

class CStep2Dlg : public CDialog
{
public:
    //{{AFX_DATA
    char m_strEdit1[20];
    //}}AFX_DATA

public:
    CStep2Dlg(CObject* pParent = NULL);
    virtual ~CStep2Dlg();

    //{{AFX_VIRTUAL
    // virtual member functions
    protected:
    virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV support
    //}}AFX_VIRTUAL

public:
    //{{AFX_MESSAGE_MAP
    void OnInitDialog(WPARAM wParam, LPARAM lParam);
    void OnCommand(WPARAM wParam, LPARAM lParam);
    //}}AFX_MESSAGE_MAP

    DECLARE_MESSAGE_MAP()
};//class CStep2Dlg

#endif // !defined(_CSTEP2DLG_DEFINED_)
