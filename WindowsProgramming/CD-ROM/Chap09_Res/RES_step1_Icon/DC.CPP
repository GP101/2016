// DC.cpp: implementation of the CDC class.
//
//////////////////////////////////////////////////////////////////////

#include "DC.h"
#include "CView.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDC::CDC(CView* p)
{
    pView=p;
    hdc = GetDC(pView->hwnd);
}

CDC::~CDC()
{
    ReleaseDC(pView->hwnd,hdc);
}

BOOL CDC::MoveToEx(int x, int y, LPPOINT lpPoint) {
    return ::MoveToEx(hdc,x,y,lpPoint);
}

BOOL CDC::LineTo(int x, int y) {
    return ::LineTo(hdc,x,y);
}

BOOL CDC::Polyline (CONST POINT* lppt, int cPoints) {
    return ::Polyline(hdc,lppt,cPoints);
}

//{{seojt
BOOL CDC::DrawIcon(int x, int y, HICON hIcon) {
    return ::DrawIcon(hdc,x,y,hIcon);
}
//}}seojt