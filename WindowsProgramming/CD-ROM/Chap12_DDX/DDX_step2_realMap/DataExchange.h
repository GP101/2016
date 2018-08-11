#if !defined(_CDATAEXCHANGE_DEFINED_)
#define _CDATAEXCHANGE_DEFINED_

class CDataExchange  
{
public:
    int m_bSaveAndValidate; // TRUE => save and validate data

    CDataExchange(int bSave = 1);

    /* ----------------------------------------------------------
    // additional members of actual CDataExchange in 'afxwin.h'

    // Operations (for implementors of DDX and DDV procs)
    HWND PrepareCtrl(int nIDC);     // return HWND of control
    HWND PrepareEditCtrl(int nIDC); // return HWND of control
    void Fail();                    // will throw exception

    HWND m_hWndLastControl;    // last control used (for validation)
    BOOL m_bEditLastControl;   // last control was an edit item 
    ------------------------------------------------------------ */
};//class CDataExchange

#endif // !defined(_CDATAEXCHANGE_DEFINED_)
