#include "stdafx.h"
#include "CObject.h"

CRuntimeClass CObject::classCObject={
    "CObject",sizeof(CObject),NULL
};

void CObject::PreCreateWindow(CREATESTRUCT& cs) {
}

HWND CObject::GetSafeHwnd() {
    return ::GetActiveWindow();//return safe handle!
}

HINSTANCE CObject::GetInstanceHandle() {
    return (HINSTANCE)GetWindowLong(GetSafeHwnd(),GWL_HINSTANCE);
}