#include "CWinApp.h"
#include "CView.h"
#include "resource.h"
#include "Step2Dlg.h"

IMPLEMENT_DYNCREATE(CView)

BEGIN_MESSAGE_MAP(CView)
    { WM_PAINT,       (CCmdTargetFunPointer)&CView::OnDraw },
    { WM_DESTROY,     (CCmdTargetFunPointer)&CView::OnDestroy },
    { WM_LBUTTONDOWN, (CCmdTargetFunPointer)&CView::OnLButtonDown },
    { WM_COMMAND,     (CCmdTargetFunPointer)&CView::OnCommand },
END_MESSAGE_MAP()

CWinApp app;

CView::CView()
{
    strcpy( m_str, "hello" );
}//CView::CView()

//CView Event handler------------------------------------------------
void CView::OnDraw(WPARAM, LPARAM)
{
    HDC             hdc;
    PAINTSTRUCT     ps;
    RECT            rect;

    hdc = BeginPaint( GetSafeHwnd(), &ps );
    GetClientRect( GetSafeHwnd(), &rect );
    DrawText( hdc, "Hello, Windows!", -1, &rect,
        DT_SINGLELINE|DT_CENTER|DT_VCENTER );
    EndPaint( GetSafeHwnd(), &ps );
}//CView::OnDraw()

void CView::OnDestroy(WPARAM, LPARAM)
{
    PostQuitMessage(0);
}//CView::OnDestroy()

void CView::OnLButtonDown(WPARAM, LPARAM)
{
    HDC hdc;

    hdc = GetDC( GetSafeHwnd() );
    Ellipse( hdc, 0, 0, 300, 300 );
    ReleaseDC( GetSafeHwnd(), hdc );
}//CView::OnLButtonDown()

void CView::OnCommand(WPARAM wParam, LPARAM lParam) 
{
    int         iRet = 0;
    CStep2Dlg   dlg;

    switch( LOWORD(wParam) )
    {
    case IDM_DOIT:
        strcpy(dlg.m_strEdit1, m_str);
        iRet = dlg.DoModal();

        if (iRet == IDOK)
        {
            strcpy(m_str, dlg.m_strEdit1);
        }//if
        break;

    case IDM_EXIT:
        DestroyWindow(GetSafeHwnd());
        break;
    }//switch
}//CView::OnCommand()
