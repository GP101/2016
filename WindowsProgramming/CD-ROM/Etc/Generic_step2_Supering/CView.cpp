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
    {WM_KEYDOWN,&CView::OnKeyDown},
    {WM_COMMAND,&CView::OnCommand},
    {WM_WINDOWPOSCHANGING,&CView::OnWindowPosChanging},
END_MESSAGE_MAP()

CWinApp app;

CView::CView() {
    bSuper=bF11=FALSE;
}//CView::CView

//CView Event handler------------------------------------------------
void CView::OnCreate(WORD wParam,LONG lParam) {
}//CView::OnCreate

void CView::OnDraw(WORD wParam,LONG lParam) {
    HDC         hdc;
    PAINTSTRUCT ps;
    RECT        rect;
    HWND        hwnd;

    hwnd=GetSafeHwnd();
    hdc=BeginPaint(hwnd,&ps);
    GetClientRect(hwnd,&rect);
    DrawText(hdc,"Why don't you press F11?   "
        "Press Alt+F to activate main menu.   "
        "CWinApp::InitInstance() is modified.   "
        "Generic Application by seojt@kogstudios.com",
        -1,&rect,
        DT_WORDBREAK|DT_CENTER|DT_VCENTER);
    EndPaint(hwnd,&ps);
}//CView::OnDraw

void CView::OnDestroy(WORD wParam,LONG lParam) {
    PostQuitMessage(0);
}//CView::OnDestroy

void CView::OnLButtonDown(WORD wParam,LONG lParam) {
    HDC         hdc;
    HWND        hwnd;

    hwnd=GetSafeHwnd();
    hdc=GetDC(hwnd);//GetDC(0) return handle to desktop window
    Ellipse(hdc,0,0,300,300);
    ReleaseDC(hwnd,hdc);
}//CView::OnDestroy

void CView::OnKeyDown(WORD wParam,LONG lParam) {
    int nVirtKey = (int)wParam;
    HWND hwnd=GetSafeHwnd();

    if (nVirtKey==VK_F11) {
        bSuper=!bSuper;
        bF11=TRUE;
        if (bSuper==TRUE) {
            GetWindowRect(hwnd,&rectWindow);
            SetWindowPos(hwnd,HWND_TOP,-6,-46,0,0,SWP_SHOWWINDOW);
              //                       ^heuristic
        } else {
            SetWindowPos(hwnd,HWND_TOP,
                rectWindow.left,rectWindow.top,0,0,SWP_SHOWWINDOW);
        }//if.. else..
    }//if
}//CView::OnKeyDown

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

void CView::OnWindowPosChanging(WORD wParam,LONG lParam) {
    LPWINDOWPOS lpwp = (LPWINDOWPOS)lParam;

    if (bSuper && bF11) {
        lpwp->cx=GetSystemMetrics(SM_CXSCREEN)+12;
        lpwp->cy=GetSystemMetrics(SM_CYSCREEN)+52;
        bF11=FALSE;
    } else if (bF11) {
        lpwp->cx=rectWindow.right-rectWindow.left;
        lpwp->cy=rectWindow.bottom-rectWindow.top;
        bF11=FALSE;
    }//if.. else..
}//CView::OnWindowPosChanging