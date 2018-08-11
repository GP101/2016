#include <windows.h>
#include "stdafx.h"
#include "CObject.h"
#include "CView.h"
#include "CWinApp.h"

CWinApp::~CWinApp()
{
    if (m_pObject != NULL)
        delete m_pObject;
}//CWinApp::~CWinApp()

void CWinApp::AddDocTemplate(CRuntimeClass* pRuntimeClass) {
    m_pRuntimeClass = pRuntimeClass;
    m_pObject       = m_pRuntimeClass->CreateObject();
}//CWinApp::AddDocTemplate()

void CWinApp::InitInstance(HINSTANCE hInstance,PSTR szCmdLine,
						int iCmdShow) {
    wndclass.cbSize         =sizeof(wndclass);
    wndclass.style          =CS_HREDRAW|CS_VREDRAW;
    wndclass.lpfnWndProc    =WndProc;
    wndclass.cbClsExtra     =0;
    wndclass.cbWndExtra     =0;
    wndclass.hInstance      =hInstance;
    wndclass.hIcon          =LoadIcon(hInstance,szAppName);//Attach Icon
    wndclass.hCursor        =LoadCursor(NULL,IDC_ARROW);
    wndclass.hbrBackground  =(HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName   =szAppName;//Attach Menu
    wndclass.lpszClassName  =szAppName;
    wndclass.hIconSm        =LoadIcon(hInstance,szAppName);//Attach Icon

    ::RegisterClassEx(&wndclass);

    PreCreateWindow(cs);
    
    HWND hwnd;
    
    hwnd=::CreateWindowEx(
        //             ^New in GENERIC2
        //{{SEOJT
        WS_EX_CLIENTEDGE,//3D client, New in GENERIC2
        //}}SEOJT
        szAppName,    //window class name
        "Generic2 Application by seojt@kogstudios.com", //window caption
        WS_OVERLAPPEDWINDOW,        //window style
        CW_USEDEFAULT,              //initial x position
        CW_USEDEFAULT,              //initial y position
        CW_USEDEFAULT,              //initial x size
        CW_USEDEFAULT,              //initial y size
        NULL,                       //parent window handle
        NULL,                       //window menu handle
        hInstance,                  //program instance handle
        NULL);                      //creation parameters
    
    AddDocTemplate(RUNTIME_CLASS(CView));
    ::ShowWindow(hwnd,iCmdShow);
    ::UpdateWindow(hwnd);
}//CWinApp::InitInstance

void CWinApp::Run() {
	while (GetMessage(&msg,NULL,0,0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }//while
}//CWinApp::Run

WPARAM CWinApp::ExitInstance() {
    return msg.wParam;
}//CWinApp::ExitInstance

char CWinApp::szAppName[]="generic";

//Global object------------------------------------------------------
extern CWinApp app;

//Window procedure---------------------------------------------------
LRESULT CALLBACK WndProc(HWND hwnd,UINT iMsg,WPARAM wParam,
                         LPARAM lParam) {
    int i=0;
    CView* p;

    while (CView::messageMap[i].iMsg!=0) {
        if (iMsg==CView::messageMap[i].iMsg) {
            fpCViewGlobal=CView::messageMap[i].fp;
            p=static_cast<CView*>(app.m_pObject);
            (p->*fpCViewGlobal)(wParam,lParam);
            return 0;
        }//if
        ++i;
    }//while
    return DefWindowProc(hwnd,iMsg,wParam,lParam);
}//WndProc

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,
                   PSTR szCmdLine,int iCmdShow) {
	app.InitInstance(hInstance,szCmdLine,iCmdShow);
	app.Run();
    return app.ExitInstance();
}//WinMain