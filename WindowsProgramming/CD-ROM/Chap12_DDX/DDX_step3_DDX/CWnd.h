#include "stdafx.h"
#include "CCmdTarget.h"

#ifndef _CWnd_
#define _CWnd_

class CWnd : public CCmdTarget
{
public:
    DECLARE_DYNCREATE(CWnd)
    static CWnd* GetWndFromHandle(HWND hwnd);

    HWND m_hwnd;

public:
    HWND GetSafeHwnd();
    BOOL ShowWindow(int nCmdShow);
    BOOL UpdateWindow();

    //{{AFX_VIRTUAL
    virtual void PreCreateWindow(CREATESTRUCT& cs);
    //}}AFX_VIRTUAL

    DECLARE_MESSAGE_MAP()
};//class CWnd

#endif // #ifndef _CWnd_
