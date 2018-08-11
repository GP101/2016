#include "resource.h"
#include "CWinApp.h"
#include "CView.h"

IMPLEMENT_DYNAMIC(CView)
IMPLEMENT_DYNCREATE(CView)

BEGIN_MESSAGE_MAP(CView)
    {WM_CREATE,&CView::OnCreate},
    {WM_PAINT,&CView::OnDraw},
    {WM_DESTROY,&CView::OnDestroy},
    {WM_LBUTTONDOWN,&CView::OnLButtonDown},
    {WM_COMMAND,&CView::OnCommand},
END_MESSAGE_MAP()

CWinApp app;

//CView Event handler------------------------------------------------
void CView::OnCreate(WORD wParam,LONG lParam) {
}//CView::OnCreate

void CView::OnDraw(WORD wParam,LONG lParam) {
    HDC         hdc;
    PAINTSTRUCT ps;
    RECT        rect;
    HWND        hwnd;

    //{{seojt
    hwnd=GetSafeHwnd();//Now, Although there are more than
                       // one instance, It's always safe!
    //}}seojt
    hdc=BeginPaint(hwnd,&ps);
    GetClientRect(hwnd,&rect);
    DrawText(hdc,"Generic Application by seojt@kogstudios.com",-1,&rect,
        DT_SINGLELINE|DT_CENTER|DT_VCENTER);
    EndPaint(hwnd,&ps);
}//CView::OnDraw

void CView::OnDestroy(WORD wParam,LONG lParam) {
    PostQuitMessage(0);
}//CView::OnDestroy

void CView::OnLButtonDown(WORD wParam,LONG lParam) {
    HDC         hdc;
    HWND        hwnd;

    //{{seojt
    hwnd=GetSafeHwnd();
    //}}seojt
    hdc=::GetDC(hwnd);//GetDC(0) return handle to desktop window
    Ellipse(hdc,0,0,300,300);
    ::ReleaseDC(hwnd,hdc);
}//CView::OnDestroy

void CView::OnCommand(WORD wParam,LONG lParam) {
    switch(wParam) {
    case IDM_DOIT:
        MessageBox(GetSafeHwnd(),"I can do it!","WM_COMMAND",
            MB_OKCANCEL|MB_ICONINFORMATION);
        break;
    case IDM_EXIT:
        DestroyWindow(GetSafeHwnd());
        break;
    }//switch
}//CView::OnCommand