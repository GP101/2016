#include <windows.h>
#include "stdafx.h"
#include "CObject.h"

#ifndef _CView_
#define _CView_

class CView;

typedef LRESULT (CView::*CViewFunPointer)(WPARAM,LPARAM);

typedef struct tagMessageMap {
    UINT iMsg;
    CViewFunPointer fp;
} MessageMap;

static CViewFunPointer fpCViewGlobal;//pointer to a member function

class CView : public CObject {
public:
    CObject::hwnd;
    DECLARE_MESSAGE_MAP()
public:
    HDC hdc;
	int cxClient,cyClient;
    int cxIcon,cyIcon;
    HICON hIcon;

    LRESULT OnCreate(WPARAM,LPARAM);
    LRESULT OnDraw(WPARAM,LPARAM);
    LRESULT OnDestroy(WPARAM,LPARAM);
    LRESULT OnSize(WPARAM wParam,LPARAM lParam);
    LRESULT OnLButtonDown(WPARAM wParam,LPARAM lParam);
    //{{seojt
    LRESULT OnCommand(WPARAM wParam,LPARAM lParam);
    //}}seojt
};//class CView

#endif