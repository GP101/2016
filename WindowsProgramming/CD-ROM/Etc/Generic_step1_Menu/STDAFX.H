#include <windows.h>

#ifndef _stdafx_defined_
#define _stdafx_defined_

//{{MessageMap macros-----------------------------------------------------
#define DECLARE_MESSAGE_MAP()          static MessageMap messageMap[];
#define BEGIN_MESSAGE_MAP(class_name)  MessageMap class_name::messageMap[]={
#define END_MESSAGE_MAP()              {0,NULL}};

//{{RTTI macros-----------------------------------------------------------
#define RUNTIME_CLASS(class_name) (&class_name::class##class_name)
#define DECLARE_DYNAMIC(class_name) static CRuntimeClass class##class_name;
#define IMPLEMENT_DYNAMIC(class_name) CRuntimeClass\
                    class_name::class##class_name = {\
                        (#class_name),\
                        sizeof(class_name),\
                    class_name::CreateObject };
#define DECLARE_DYNCREATE(class_name) static CObject* CreateObject();
#define IMPLEMENT_DYNCREATE(class_name) CObject* class_name::CreateObject() {\
                    return new class_name; }

//Forward declaration------------------------------------------------
LRESULT CALLBACK WndProc(HWND hwnd,UINT iMsg,WPARAM wParam,LPARAM lParam);
class CObject;

//{{struct CRuntimeClass-------------------------------------------------
struct CRuntimeClass {
    char m_lpszClassName[21];
    int m_nObjectSize;
    CObject* (*pfnCreateObject)();//function pointer

    CObject* CreateObject();
};//struct CRunTimeClass

//Forward declaration------------------------------------------------
class CView;

//{{struct MessageMap------------------------------------------------
typedef void (CView::*CViewFunPointer)(WORD,LONG);
typedef struct tagMessageMap {
    UINT iMsg;
    CViewFunPointer fp;
} MessageMap;

#endif