#include "CWinApp.h"
#include "CView.h"
#include "resource.h"

IMPLEMENT_DYNCREATE(CView)

BEGIN_MESSAGE_MAP(CView)
    { WM_PAINT,       &CView::OnDraw },
    { WM_DESTROY,     &CView::OnDestroy },
    { WM_LBUTTONDOWN, &CView::OnLButtonDown },
    { WM_COMMAND,     &CView::OnCommand },
END_MESSAGE_MAP()

CWinApp app;

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
    switch(wParam)
    {
    case IDM_DOIT:
        MessageBox(GetSafeHwnd(),"I can do it!","WM_COMMAND",
            MB_OKCANCEL|MB_ICONINFORMATION);
        break;

    case IDM_EXIT:
        DestroyWindow(GetSafeHwnd());
        break;
    }//switch
}//CView::OnCommand()
