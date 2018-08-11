#include <windows.h>
#include <math.h>
#include "stdafx.h"
#include "CView.h"
#include "DC.h"

CView app;

BEGIN_MESSAGE_MAP(CView)
    {WM_CREATE,&CView::OnCreate},
    {WM_PAINT,&CView::OnDraw},
    {WM_DESTROY,&CView::OnDestroy},
    {WM_SIZE,&CView::OnSize},
    {WM_LBUTTONDOWN,&CView::OnLButtonDown},
END_MESSAGE_MAP()

LRESULT CView::OnCreate(WPARAM wParam,LPARAM lParam) {
    //{{seojt
    hIcon=::LoadIcon(hInst,"resourc1");//Is :: really necessary?
    cxIcon=::GetSystemMetrics(SM_CXICON);
    cyIcon=::GetSystemMetrics(SM_CYICON);
    //}}seojt
    return 0L;
}//CView::OnCreate

LRESULT CView::OnDraw(WPARAM wParam,LPARAM lParam) {
    HDC         hdc;
    PAINTSTRUCT ps;
    RECT        rect;

    hdc=BeginPaint(hwnd,&ps);
    GetClientRect(hwnd,&rect);
    DrawText(hdc,"Hello, Windows!",-1,&rect,
        DT_SINGLELINE|DT_CENTER|DT_VCENTER);
    EndPaint(hwnd,&ps);
    return 0L;
}//CView::OnDraw

LRESULT CView::OnDestroy(WPARAM wParam,LPARAM lParam) {
    PostQuitMessage(0);//How it works?(Hint:WM_QUIT)
    return 0L;
}//CView::OnDestroy

LRESULT CView::OnLButtonDown(WPARAM wParam,LPARAM lParam) {
    CDC dc(this);
    //{{seojt
    int x,y;

    for (y = cyIcon ; y < cyClient ; y += 2 * cyIcon)
        for (x = cxIcon ; x < cxClient ; x += 2 * cxIcon)
            dc.DrawIcon (x, y, hIcon) ;
              //BOOL DrawIcon(HDC, int, int, HICON);
    //}}seojt
    
    return 0L;
}//CView::OnLButtonDown

LRESULT CView::OnSize(WPARAM wParam,LPARAM lParam) {
    cxClient=LOWORD(lParam);
    cyClient=HIWORD(lParam);
    return 0L;
}//CView::OnSize