#include "stdafx.h"
#include "CWinApp.h"
#include "CView.h"

//{{GENERIC 3
extern HWND hwnd;
extern HWND hwndClient;
extern HINSTANCE hInst;
//}}GENERIC 3

CObject* CRuntimeClass::CreateObject() {
    return (*pfnCreateObject)();//함수 포인터를 이용하여
                                //간접적으로 함수를 호출한다.
}//CRuntimeClass::CreateObject()

//{{GENERIC 3
void MenuCheckMark(HMENU hmenu, int id, BOOL bCheck) {
     int iState ;
     iState = (bCheck) ? MF_CHECKED : MF_UNCHECKED ;
     CheckMenuItem (hmenu, id, iState) ;
}//MenuCheckMark
//}}GENERIC 3

//Global object------------------------------------------------------
extern CWinApp app;

//Window procedure---------------------------------------------------
LRESULT CALLBACK WndProc(HWND hwnd,UINT iMsg,WPARAM wParam,
                         LPARAM lParam) {
    int i=0;
    CMainFrame* p;

    ::hwnd=hwnd;
    while (CMainFrame::messageMap[i].iMsg!=0) {
        if (iMsg==CMainFrame::messageMap[i].iMsg) {
            fpCMainFrameGlobal=CMainFrame::messageMap[i].fp;
            p=static_cast<CMainFrame*>(app.m_pMainFrame);
            (p->*fpCMainFrameGlobal)(wParam,lParam);
            return 0;
        }//if
        ++i;
    }//while
    return DefWindowProc(hwnd,iMsg,wParam,lParam);
}//WndProc

LRESULT CALLBACK ClientWndProc(HWND hwnd,UINT iMsg,WPARAM wParam,
                         LPARAM lParam) {
    int i=0;
    CClientView* p;

    ::hwndClient=hwnd;
    while (CClientView::messageMap[i].iMsg!=0) {
        if (iMsg==CClientView::messageMap[i].iMsg) {
            fpCClientViewGlobal=CClientView::messageMap[i].fp;
            p=static_cast<CClientView*>(app.m_pView);
            (p->*fpCClientViewGlobal)(wParam,lParam);
            return 0;
        }//if
        ++i;
    }//while
    return DefWindowProc(hwnd,iMsg,wParam,lParam);
}//ClientWndProc

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,
                   PSTR szCmdLine,int iCmdShow) {
    ::hInst=hInstance;//GENERIC 3
	app.InitInstance(hInstance,szCmdLine,iCmdShow);
	app.Run();
    return app.ExitInstance();
}//WinMain
