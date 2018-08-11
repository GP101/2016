#include "CWnd.h"
#include "CWinApp.h"

extern CWinApp app;

IMPLEMENT_DYNCREATE(CWnd)
BEGIN_MESSAGE_MAP(CWnd)
    // Default message map here
END_MESSAGE_MAP()

/*static*/ CWnd* CWnd::GetWndFromHandle(HWND hwnd)
{
    return app.GetMainWnd();
}//CWnd::GetWndFromHandle()

HWND CWnd::GetSafeHwnd()
{
    return this == NULL ? NULL : m_hwnd;
}//CWnd::GetSafeHwnd()

BOOL CWnd::ShowWindow(int nCmdShow)
{
    return ::ShowWindow( GetSafeHwnd(), nCmdShow );
}//CWnd::ShowWindow(int nCmdShow)

BOOL CWnd::UpdateWindow()
{
    return ::UpdateWindow( GetSafeHwnd() );
}//CWnd::UpdateWindow()

/*virtual*/ void CWnd::PreCreateWindow(CREATESTRUCT& cs)
{
}//CWnd::PreCreateWindow(CREATESTRUCT& cs)
