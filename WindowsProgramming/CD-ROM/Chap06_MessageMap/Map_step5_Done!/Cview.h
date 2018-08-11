#include <windows.h>
#include "stdafx.h"
#include "CObject.h"

#ifndef _CView_
#define _CView_

// message map structure -----------------------------------------
class CView;

typedef LRESULT (CView::*CViewFunPointer)(WPARAM,LPARAM);

typedef struct tagMessageMap {
    UINT iMsg;
    CViewFunPointer fp;
} MessageMap;

static CViewFunPointer fpCViewGlobal;//pointer to a member function

// class CView ---------------------------------------------------
class CView : public CObject {
public:
    //{{AFX_MESSAGE
    LRESULT OnCreate(WPARAM,LPARAM);
    LRESULT OnDraw(WPARAM,LPARAM);
    LRESULT OnDestroy(WPARAM,LPARAM);
    LRESULT OnLButtonDown(WPARAM,LPARAM);
    //}}AFX_MESSAGE

    DECLARE_MESSAGE_MAP()
};//class CView

#endif