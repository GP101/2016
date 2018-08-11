#include "CWinApp.h"
#include "CView.h"

IMPLEMENT_DYNCREATE(CView)

BEGIN_MESSAGE_MAP(CView)
    { WM_PAINT,       &CView::OnDraw },
    { WM_DESTROY,     &CView::OnDestroy },
    { WM_LBUTTONDOWN, &CView::OnLButtonDown },
END_MESSAGE_MAP()

CWinApp app;

//CView Event handler------------------------------------------------
void CView::OnDraw()
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

void CView::OnDestroy()
{
    PostQuitMessage(0);
}//CView::OnDestroy()

void CView::OnLButtonDown()
{
    HDC hdc;

    hdc = GetDC( GetSafeHwnd() );
    Ellipse( hdc, 0, 0, 300, 300 );
    ReleaseDC( GetSafeHwnd(), hdc );
}//CView::OnLButtonDown()
