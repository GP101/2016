#include "stdafx.h"
#include "CObject.h"

#ifndef _CWnd_
#define _CWnd_

class CWnd : public CObject
{
public:
    DECLARE_DYNCREATE(CWnd)

    HWND m_hwnd;

public:
    HWND GetSafeHwnd();
    BOOL ShowWindow(int nCmdShow);
    BOOL UpdateWindow();

    //{{AFX_VIRTUAL
    virtual void PreCreateWindow(CREATESTRUCT& cs);
    //}}AFX_VIRTUAL
};//class CWnd

#endif // #ifndef _CWnd_
