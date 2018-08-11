// DC.h: interface for the CDC class.
//
//////////////////////////////////////////////////////////////////////

#include "CView.h"

#if !defined(AFX_DC_H__C1A907E9_AA33_11D2_BC14_02608C6CA09B__INCLUDED_)
#define AFX_DC_H__C1A907E9_AA33_11D2_BC14_02608C6CA09B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CDC  
{
private:
    CView* pView;
    PAINTSTRUCT ps;
    HDC hdc;

public:
	CDC(CView* pView);
	virtual ~CDC();
    BOOL MoveToEx(int, int, LPPOINT);
    BOOL LineTo(int, int);
    BOOL Polyline (CONST POINT*, int);
    //{{seojt
    BOOL DrawIcon(int, int, HICON);
    //}}seojt
};

#endif // !defined(AFX_DC_H__C1A907E9_AA33_11D2_BC14_02608C6CA09B__INCLUDED_)
