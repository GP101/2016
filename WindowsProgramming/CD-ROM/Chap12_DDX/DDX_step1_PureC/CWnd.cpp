#include "CWnd.h"

IMPLEMENT_DYNCREATE(CWnd)

HWND CWnd::GetSafeHwnd()
{
    return this == NULL ? NULL : m_hwnd;
}//CWnd::GetSafeHwnd()

//HINSTANCE CWnd::GetInstanceHandle() 
//{
//    return (HINSTANCE)GetWindowLong( GetSafeHwnd(), GWL_HINSTANCE );
//}

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
