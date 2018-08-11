#include <windows.h>
#include "CObject.h"

#ifndef _CView_
#define _CView_

class CView : public CObject {
public:
    DECLARE_DYNAMIC(CView)
    DECLARE_DYNCREATE(CView)
    virtual CRuntimeClass* GetRuntimeClass() const { return &classCView; }

public:
    int bSuper,bF11;
    RECT rectWindow;

public:
    CView();

    //{{AFX_MESSAGE_MAP
    void OnCreate(WORD wParam,LONG lParam);
    void OnDraw(WORD wParam,LONG lParam);
    void OnDestroy(WORD wParam,LONG lParam);
    void OnLButtonDown(WORD wParam,LONG lParam);
    void OnKeyDown(WORD wParam,LONG lParam);
    void OnCommand(WORD wParam,LONG lParam);
    void OnWindowPosChanging(WORD wParam,LONG lParam);
    //}}AFX_MESSAGE_MAP

    DECLARE_MESSAGE_MAP()
};//class CView

#endif