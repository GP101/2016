#include "stdafx.h"
#include "CObject.h"
#include "CView.h"

#ifndef _CWinApp_
#define _CWinApp_

//Class CWinApp----------------------------------------------------------
class CWinApp : public CObject
{
protected:
    static char     szAppName[];
    HINSTANCE       m_hInstance;

public:
    CWnd*           m_pMainWnd;

public:
    virtual ~CWinApp();
    void AddDocTemplate(CRuntimeClass* pRuntimeClass);
    void InitInstance(HINSTANCE hInstance, PSTR szCmdLine,
                      int iCmdShow);
    void Run();
    WPARAM ExitInstance();

    // virtual function
    virtual int OnIdle(); // Note: OnIdle() is virtual

    HINSTANCE GetInstanceHandle() { return m_hInstance; }
};//class CWinApp

#endif // #ifndef _CWinApp_
