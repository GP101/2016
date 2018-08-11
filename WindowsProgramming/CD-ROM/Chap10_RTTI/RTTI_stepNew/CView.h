#include "stdafx.h"
#include "CWnd.h"

#ifndef _CView_
#define _CView_

class CView : public CWnd
{
public:
    DECLARE_DYNCREATE(CView)

public:
    //{{AFX_VIRTUAL
    // you may override some virtual functions
    // you know, there are two types of message map
    //
    //virtual void PreCreateWindow(CREATESTRUCT& cs);
    //}}AFX_VIRTUAL

    //{{AFX_MESSAGE_MAP
    void OnDraw();
    void OnDestroy();
    void OnLButtonDown();
    //}}AFX_MESSAGE_MAP

    DECLARE_MESSAGE_MAP()
};//class CView

#endif // #ifndef _CView_
