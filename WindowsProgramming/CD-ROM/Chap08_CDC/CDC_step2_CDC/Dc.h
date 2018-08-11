// DC.h: interface for the CDC class.
//
//////////////////////////////////////////////////////////////////////

#include "CView.h"

#if !defined(_CDC_DEFINED_)
#define _CDC_DEFINED_

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
};//class CDC

#endif // !defined(_CDC_DEFINED_)
