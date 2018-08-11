#include <windows.h>
#include "stdafx.h"
#include "CObject.h"
#include "CView.h"

#ifndef _CWinApp_
#define _CWinApp_

static CMainFrameFunPointer fpCMainFrameGlobal;//pointer to a member function
static CClientViewFunPointer fpCClientViewGlobal;//pointer to a member function

//Class CWinApp----------------------------------------------------------
class CWinApp : public CObject {
protected:
	static char szAppName[];
    MSG         msg;
    WNDCLASSEX  wndclass;
    CREATESTRUCT cs;

public:
    CRuntimeClass* m_pRuntimeClass;
    CObject* m_pMainFrame;
    CObject* m_pView;

public:
    virtual ~CWinApp();
    void AddDocTemplate(CRuntimeClass* pMainFrame,CRuntimeClass* pView);
	void InitInstance(HINSTANCE hInstance,PSTR szCmdLine,
   				      int iCmdShow);
	void Run();
    WPARAM ExitInstance();
};//class CWinApp

#endif