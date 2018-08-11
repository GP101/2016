#include <windows.h>
#include "CObject.h"

#ifndef _CView_
#define _CView_

class CView : public CObject {
public:
    virtual CRuntimeClass* GetRuntimeClass() const { return &classCView; }
    DECLARE_DYNAMIC(CView)
    DECLARE_DYNCREATE(CView)

public:
    //{{AFX_MESSAGE_MAP
    void OnCreate(WORD wParam,LONG lParam);
    void OnDraw(WORD wParam,LONG lParam);
    void OnDestroy(WORD wParam,LONG lParam);
    void OnLButtonDown(WORD wParam,LONG lParam);
    void OnCommand(WORD wParam,LONG lParam);
    //}}AFX_MESSAGE_MAP

    DECLARE_MESSAGE_MAP()
};//class CView

#endif