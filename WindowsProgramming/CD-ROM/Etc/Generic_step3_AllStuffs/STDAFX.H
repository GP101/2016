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
LRESULT CALLBACK ClientWndProc (HWND, UINT, WPARAM, LPARAM) ;//GENERIC 3
class CObject;

//{{struct CRuntimeClass-------------------------------------------------
struct CRuntimeClass {
    char m_lpszClassName[21];
    int m_nObjectSize;
    CObject* (*pfnCreateObject)();//function pointer

    CObject* CreateObject();
};//struct CRunTimeClass

//Forward declaration------------------------------------------------
class CMainFrame;
class CClientView;

//{{struct MessageMap------------------------------------------------
typedef void (CObject::*CObjectFunPointer)(WORD,LONG);
typedef void (CMainFrame::*CMainFrameFunPointer)(WORD,LONG);
typedef void (CClientView::*CClientViewFunPointer)(WORD,LONG);
typedef struct tagMessageMap {
    UINT iMsg;
    CObjectFunPointer fp;
} MessageMap;

//{{GENERIC 3
void MenuCheckMark (HMENU hmenu, int id, BOOL bCheck);
//}}GENERIC 3

//You must add your own macros 
#define ON_WM_COMMAND(class_name)       {WM_COMMAND,static_cast<CObjectFunPointer>(class_name::OnCommand)},
#define ON_WM_CREATE(class_name)        {WM_CREATE,static_cast<CObjectFunPointer>(class_name::OnCreate)},
#define ON_WM_DESTROY(class_name)       {WM_DESTROY,static_cast<CObjectFunPointer>(class_name::OnDestroy)},
#define ON_WM_INITMENU(class_name)      {WM_INITMENU,static_cast<CObjectFunPointer>(class_name::OnInitMenu)},
#define ON_WM_KEYDOWN(class_name)       {WM_KEYDOWN,static_cast<CObjectFunPointer>(class_name::OnKeyDown)},
#define ON_WM_LBUTTONDOWN(class_name)   {WM_LBUTTONDOWN,static_cast<CObjectFunPointer>(class_name::OnLButtonDown)},
#define ON_WM_MENUSELECT(class_name)    {WM_MENUSELECT,static_cast<CObjectFunPointer>(class_name::OnMenuSelect)},
#define ON_WM_NOTIFY(class_name)        {WM_NOTIFY,static_cast<CObjectFunPointer>(class_name::OnNotify)},
#define ON_WM_PAINT(class_name)         {WM_PAINT,static_cast<CObjectFunPointer>(class_name::OnPaint)},
#define ON_WM_SIZE(class_name)          {WM_SIZE,static_cast<CObjectFunPointer>(class_name::OnSize)},
#define ON_WM_WINDOWPOSCHANGING(class_name) {WM_WINDOWPOSCHANGING,static_cast<CObjectFunPointer>(class_name::OnWindowPosChanging)},

#endif
