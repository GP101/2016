#include "stdafx.h"
#include "CObject.h"

CRuntimeClass CObject::classCObject={
    "CObject",sizeof(CObject),NULL
};

void CObject::PreCreateWindow(CREATESTRUCT& cs) {
}

HWND CObject::GetSafeHwnd() {
    return GetActiveWindow();//return safe handle!
      //I don't know about that how MFC really does it.
}

HINSTANCE CObject::GetInstanceHandle() {
    return (HINSTANCE)GetWindowLong(GetSafeHwnd(),GWL_HINSTANCE);
      //I don't know about that how MFC really does it.
}