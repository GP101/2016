#include <windows.h>
#include "CObject.h"

#ifndef _CView_
#define _CView_

class CMainFrame : public CObject {
public:
    DECLARE_DYNAMIC(CMainFrame)
    DECLARE_DYNCREATE(CMainFrame)
    virtual CRuntimeClass* GetRuntimeClass() const { return &classCMainFrame; }

public:
    int bSuper,bF11;//GENERIC 2: for window supering state
    RECT rectWindow;//GENERIC 3: rectangle before supering

public:
    CMainFrame();

    //{{AFX_MESSAGE_MAP(CMainFrame)
    void OnCreate(WORD wParam,LONG lParam);
    void OnDestroy(WORD wParam,LONG lParam);
    void OnKeyDown(WORD wParam,LONG lParam);
    void OnCommand(WORD wParam,LONG lParam);
    void OnWindowPosChanging(WORD wParam,LONG lParam);
    void OnInitMenu(WORD wParam,LONG lParam);
    void OnMenuSelect(WORD wParam,LONG lParam);
    void OnNotify(WORD wParam,LONG lParam);
    void OnSize(WORD wParam,LONG lParam);
    //}}AFX_MESSAGE_MAP(CMainFrame)

    DECLARE_MESSAGE_MAP()
};//class CMainFrame

class CClientView : public CObject {
public:
    DECLARE_DYNAMIC(CClientView)
    DECLARE_DYNCREATE(CClientView)
    virtual CRuntimeClass* GetRuntimeClass() const { return &classCClientView; }

public:
    CClientView();

    //{{AFX_MESSAGE_MAP(CView)
    void OnCreate(WORD wParam,LONG lParam);
    void OnPaint(WORD wParam,LONG lParam);
    void OnDestroy(WORD wParam,LONG lParam);
    void OnSize(WORD wParam,LONG lParam);
    void OnLButtonDown(WORD wParam,LONG lParam);
    //}}GENERIC 3
    //}}AFX_MESSAGE_MAP(CView)

    DECLARE_MESSAGE_MAP()
};//class CClientView
#endif