#include "stdafx.h"

#ifndef _CObject_
#define _CObject_

class CObject {
    DECLARE_DYNAMIC(CObject)
    virtual CRuntimeClass* GetRuntimeClass() const { return NULL; }

public:
    virtual ~CObject(){}
    HWND GetSafeHwnd();
    HINSTANCE GetInstanceHandle();
    //{{AFX_VIRTUAL
    virtual void PreCreateWindow(CREATESTRUCT& cs);
    //}}AFX_VIRTUAL

protected:
    CObject(){}
};//class CObject

#endif