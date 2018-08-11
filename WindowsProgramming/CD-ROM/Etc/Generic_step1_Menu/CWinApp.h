#include <windows.h>
#include "stdafx.h"
#include "CObject.h"
#include "CView.h"

#ifndef _CWinApp_
#define _CWinApp_

static CViewFunPointer fpCViewGlobal;//pointer to a member function

//Class CWinApp----------------------------------------------------------
class CWinApp : public CObject {
protected:
	static char szAppName[];
    MSG         msg;
    WNDCLASSEX  wndclass;
    CREATESTRUCT cs;

public:
    CRuntimeClass* m_pRuntimeClass;
    CObject* m_pObject;

public:
    virtual ~CWinApp();
    void AddDocTemplate(CRuntimeClass* pRuntimeClass);
	void InitInstance(HINSTANCE hInstance,PSTR szCmdLine,
   				      int iCmdShow);
	void Run();
    WPARAM ExitInstance();
};//class CWinApp

#endif