#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include "stdafx.h"
#include "resource.h"
#include "CWinApp.h"
#include "CView.h"
#include "comcthlp.h"
#include "gadgets.h"

HINSTANCE hInst;//program instance handle
HWND hwnd;//handle to the MainFrame
HWND hwndClient = NULL ;//handle to the ClientView
HWND hwndToolBar = NULL ;
HWND hwndStatusBar = NULL ;

extern DWORD dwToolBarStyles ;
extern BOOL bStrings ;
extern BOOL bLargeIcons ;
extern BOOL bComboBox ;
extern DWORD dwStatusBarStyles ;
extern int cyToolBar ;

////////////////////////////////////////////////////////////////
// CMainFrame
IMPLEMENT_DYNAMIC(CMainFrame)
IMPLEMENT_DYNCREATE(CMainFrame)

BEGIN_MESSAGE_MAP(CMainFrame)
	//{{AFX_MSG_MAP
    ON_WM_CREATE(&CMainFrame)
    ON_WM_DESTROY(&CMainFrame)
    ON_WM_KEYDOWN(&CMainFrame)
    ON_WM_COMMAND(&CMainFrame)
    ON_WM_WINDOWPOSCHANGING(&CMainFrame)
    ON_WM_INITMENU(&CMainFrame)
    ON_WM_MENUSELECT(&CMainFrame)
    ON_WM_NOTIFY(&CMainFrame)
    ON_WM_SIZE(&CMainFrame)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

////////////////////////////////////////////////////////////////
// The Only global object
CWinApp app;

CMainFrame::CMainFrame() {
    bSuper=bF11=FALSE;
}//CMainFrame::CMainFrame

//CMainFrame Event handler------------------------------------------------
void CMainFrame::OnCreate(WORD wParam,LONG lParam) {
    // Create toolbar (source resides in toolbar.c).
    hwndToolBar = InitToolBar (hwnd) ;
    // Create status bar (source resides in statbar.c).
    hwndStatusBar = InitStatusBar (hwnd) ;
    //Create the window for CClientView
    hwndClient = CreateWindowEx(WS_EX_CLIENTEDGE,
        "ClientWndProc", NULL,
        WS_CHILD | WS_VISIBLE, 0, 0, 0, 0,
        hwnd, (HMENU) 4, hInst, NULL) ;
}//CMainFrame::OnCreate

void CMainFrame::OnDestroy(WORD wParam,LONG lParam) {
    PostQuitMessage(0);
}//CMainFrame::OnDestroy

void CMainFrame::OnKeyDown(WORD wParam,LONG lParam) {
    int nVirtKey = (int)wParam;
    //HWND hwnd=GetSafeHwnd();

    if (nVirtKey==VK_F11) {//supering operations
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
}//CMainFrame::OnKeyDown

void CMainFrame::OnCommand(WORD wParam,LONG lParam) {
    // Toolbar button commands.
    if (LOWORD (wParam) < 300) {
    //You must add your command here!
        char ach[80] ;
        wsprintf (ach, "Got Command (%d)", wParam) ;
        MessageBox (hwnd, ach, "WM_COMMAND", MB_OK) ;
        return;
    }//if

    RECT r ;
    // Menu item commands
    switch (LOWORD(wParam)) {
    // Toolbar settings
    case IDM_STRINGS :
    case IDM_LARGEICONS :
    case IDM_SMALLICONS :
    case IDM_NODIVIDER :
    case IDM_WRAPABLE :
    case IDM_TOP :
    case IDM_BOTTOM :
    case IDM_NOMOVEY :
    case IDM_NOPARENTALIGN :
    case IDM_NORESIZE :
    case IDM_ADJUSTABLE :
    case IDM_ALTDRAG :
    case IDM_TOOLTIPS :
    case IDM_COMBOBOX :
        DestroyWindow (hwndToolBar) ;
        hwndToolBar = RebuildToolBar (hwnd,LOWORD(wParam));
        break ;

    // Toolbar messages
    case IDM_TB_CHECK :
    case IDM_TB_ENABLE :
    case IDM_TB_HIDE :
    case IDM_TB_INDETERMINATE :
    case IDM_TB_PRESS :
    case IDM_TB_BUTTONCOUNT :
    case IDM_TB_GETROWS :
    case IDM_TB_CUSTOMIZE :
        ToolBarMessage (hwndToolBar, LOWORD (wParam)) ;
        break ;

    // Toggle display of toolbar
    case IDM_VIEW_TOOLBAR :
        if (hwndToolBar && IsWindowVisible (hwndToolBar)) {
            ShowWindow (hwndToolBar, SW_HIDE) ;
        } else {
            ShowWindow (hwndToolBar, SW_SHOW) ;
        }//if.. else..

        // Resize other windows.
        GetClientRect (hwnd, &r) ;
        PostMessage (hwnd, WM_SIZE, 0, 
            MAKELPARAM (r.right, r.bottom)) ;
        break;

    // Toggle display of status bar
    case IDM_VIEW_STATUS :
        if (hwndStatusBar && IsWindowVisible (hwndStatusBar)) {
            ShowWindow (hwndStatusBar, SW_HIDE) ;
        } else {
            ShowWindow (hwndStatusBar, SW_SHOW) ;
        }//if.. else..

        // Resize other windows.
        GetClientRect (hwnd, &r) ;
        PostMessage (hwnd, WM_SIZE, 0, 
            MAKELPARAM (r.right, r.bottom)) ;
        break;
    }//switch
}//CMainFrame::OnCommand

void CMainFrame::OnWindowPosChanging(WORD wParam,LONG lParam) {
    LPWINDOWPOS lpwp = (LPWINDOWPOS)lParam;

    if (bSuper && bF11) {//supering operations
        lpwp->cx=GetSystemMetrics(SM_CXSCREEN)+12;
        lpwp->cy=GetSystemMetrics(SM_CYSCREEN)+52;
        bF11=FALSE;
    } else if (bF11) {
        lpwp->cx=rectWindow.right-rectWindow.left;
        lpwp->cy=rectWindow.bottom-rectWindow.top;
        bF11=FALSE;
    }//if.. else..
}//CMainFrame::OnWindowPosChanging

void CMainFrame::OnInitMenu(WORD wParam,LONG lParam) {
    BOOL bCheck ;
    HMENU hmenu = (HMENU) wParam ;

    // Toolbar menu items.
    MenuCheckMark (hmenu, IDM_STRINGS, bStrings) ;
    MenuCheckMark (hmenu, IDM_LARGEICONS, bLargeIcons) ;
    MenuCheckMark (hmenu, IDM_SMALLICONS, !bLargeIcons) ;
    MenuCheckMark (hmenu, IDM_COMBOBOX, bComboBox) ;

    bCheck = (dwToolBarStyles & CCS_NODIVIDER) ;
    MenuCheckMark (hmenu, IDM_NODIVIDER, bCheck) ;

    bCheck = (dwToolBarStyles & TBSTYLE_WRAPABLE) ;
    MenuCheckMark(hmenu, IDM_WRAPABLE, bCheck) ;

    bCheck = ((dwToolBarStyles & 3) == CCS_TOP) ;
    MenuCheckMark(hmenu, IDM_TOP, bCheck) ;

    bCheck = ((dwToolBarStyles & 3) == CCS_BOTTOM) ;
    MenuCheckMark (hmenu, IDM_BOTTOM, bCheck) ;

    bCheck = ((dwToolBarStyles & 3) == CCS_NOMOVEY) ;
    MenuCheckMark (hmenu, IDM_NOMOVEY, bCheck) ;

    bCheck = (dwToolBarStyles & CCS_NOPARENTALIGN) ;
    MenuCheckMark (hmenu, IDM_NOPARENTALIGN, bCheck) ;

    bCheck = (dwToolBarStyles & CCS_NORESIZE) ;
    MenuCheckMark (hmenu, IDM_NORESIZE, bCheck) ;

    bCheck = (dwToolBarStyles & CCS_ADJUSTABLE) ;
    MenuCheckMark (hmenu, IDM_ADJUSTABLE, bCheck) ;

    bCheck = (dwToolBarStyles & TBSTYLE_ALTDRAG) ;
    MenuCheckMark (hmenu, IDM_ALTDRAG, bCheck) ;

    bCheck = (dwToolBarStyles & TBSTYLE_TOOLTIPS) ;
    MenuCheckMark (hmenu, IDM_TOOLTIPS, bCheck) ;

    // View menu items.
    bCheck = IsWindowVisible (hwndToolBar) ;
    MenuCheckMark (hmenu, IDM_VIEW_TOOLBAR, bCheck) ;
            
    bCheck = IsWindowVisible (hwndStatusBar) ;
    MenuCheckMark (hmenu, IDM_VIEW_STATUS, bCheck) ;
}//CMainFrame::OnInitMenu

void CMainFrame::OnMenuSelect(WORD wParam,LONG lParam) {
    Statusbar_MenuSelect (hwnd, wParam, lParam);
}//CMainFrame::OnMenuSelect

void CMainFrame::OnNotify(WORD wParam,LONG lParam) {
    LPNMHDR pnmh = (LPNMHDR) lParam ;
    int idCtrl = (int) wParam ;

    // Toolbar notifications
    if ((pnmh->code >= TBN_LAST) && (pnmh->code <= TBN_FIRST)) {
        ToolBarNotify (hwnd, wParam, lParam) ;
        return;
    }//if
            
    // Fetch tooltip text
    if (pnmh->code == TTN_NEEDTEXT) {
        LPTOOLTIPTEXT lpttt = (LPTOOLTIPTEXT) lParam ;
        CopyToolTipText (lpttt) ;
    }//if
}//CMainFrame::OnNotify

void CMainFrame::OnSize(WORD wParam,LONG lParam) {
    int cx = LOWORD (lParam) ;
    int cy = HIWORD (lParam) ;
    int cyStatus ;
    int cyTB ;
    int x, y ;
    DWORD dwStyle ;
    RECT rWindow ;

    // Adjust toolbar size.
    if (IsWindowVisible (hwndToolBar)) {
        dwStyle = GetWindowLong (hwndToolBar, GWL_STYLE) ;
        if (dwStyle & CCS_NORESIZE) {
            MoveWindow (hwndToolBar, 0, 0, cx, cyToolBar, FALSE) ;
        } else {
            ToolBar_AutoSize (hwndToolBar) ;
        }//if.. else..
        InvalidateRect (hwndToolBar, NULL, TRUE) ;
        GetWindowRect (hwndToolBar, &rWindow) ;
        ScreenToClient (hwnd, (LPPOINT) &rWindow.left) ;
        ScreenToClient (hwnd, (LPPOINT) &rWindow.right) ;
        cyTB = rWindow.bottom - rWindow.top ;
    } else {
        cyTB = 0 ;
    }//if.. else..

    // Adjust status bar size.
    if (IsWindowVisible (hwndStatusBar)) {
        GetWindowRect (hwndStatusBar, &rWindow) ;
        cyStatus = rWindow.bottom - rWindow.top ;
        MoveWindow (hwndStatusBar, 0, cy - cyStatus, cx, cyStatus, TRUE) ;
    } else {
        cyStatus = 0 ;
    }//if.. else..

    // Adjust client window size.
    x = 0 ;
    y = cyTB ;
    cy = cy - (cyStatus + cyTB) ;
    MoveWindow (hwndClient, x, y, cx, cy, TRUE) ;
}//CMainFrame::OnSize

////////////////////////////////////////////////////////////////
// CClientView
IMPLEMENT_DYNAMIC(CClientView)
IMPLEMENT_DYNCREATE(CClientView)

BEGIN_MESSAGE_MAP(CClientView)
	//{{AFX_MSG_MAP
    ON_WM_CREATE(&CClientView)
    ON_WM_PAINT(&CClientView)
    ON_WM_DESTROY(&CClientView)
    ON_WM_SIZE(&CClientView)
    ON_WM_LBUTTONDOWN(&CClientView)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

CClientView::CClientView() {
}//CClientView::CClientView()

void CClientView::OnCreate(WORD wParam,LONG lParam) {
}//CClientView::OnCreate()

void CClientView::OnPaint(WORD wParam,LONG lParam) {
    HDC         hdc;
    PAINTSTRUCT ps;
    RECT        rect;

    hwnd=hwndClient;
    hdc=BeginPaint(hwnd,&ps);
    GetClientRect(hwnd,&rect);
    DrawText(hdc,"Generic 3 Application by seojt@kogstudios.com",
        -1,&rect,DT_CENTER|DT_VCENTER);
    EndPaint(hwnd,&ps);
}//CClientView::OnPaint()

void CClientView::OnDestroy(WORD wParam,LONG lParam) {
}//CClientView::OnDestroy()

void CClientView::OnSize(WORD wParam,LONG lParam) {
}//CClientView::OnSize()

void CClientView::OnLButtonDown(WORD wParam,LONG lParam) {
    HDC         hdc;

    hdc=GetDC(hwndClient);//GetDC(0) return handle to desktop window
    Ellipse(hdc,0,0,300,300);
    ReleaseDC(hwndClient,hdc);
}//CClientView::OnLButtonDown()
