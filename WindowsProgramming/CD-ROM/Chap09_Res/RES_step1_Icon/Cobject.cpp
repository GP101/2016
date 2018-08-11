#include <windows.h>
#include "stdafx.h"
#include "CObject.h"

void CObject::InitInstance(HINSTANCE hInstance,PSTR szCmdLine,
						int iCmdShow) {
    //{{seojt
    hInst=hInstance;
    //}}seojt
    wndclass.cbSize         =sizeof(wndclass);
    wndclass.style          =CS_HREDRAW|CS_VREDRAW;
    wndclass.lpfnWndProc    =WndProc;
    wndclass.cbClsExtra     =0;
    wndclass.cbWndExtra     =0;
    wndclass.hInstance      =hInstance;
    //{{seojt
    wndclass.hIcon          =LoadIcon(hInstance,"resourc1");
    wndclass.hCursor        =LoadCursor(hInstance,"resourc1");
    //}}seojt
    wndclass.hbrBackground  =(HBRUSH)GetStockObject(WHITE_BRUSH);
    //wndclass.hbrBackground  =(HBRUSH)GetStockObject(NULL_BRUSH);
    wndclass.lpszMenuName   =NULL;
    wndclass.lpszClassName  =szAppName;
    //{{seojt
    wndclass.hIconSm        =LoadIcon(hInstance,"resourc1");
    //}}seojt

    RegisterClassEx(&wndclass);

    hwnd=CreateWindow(szAppName,    //window class name
        "Res step1: Icon",        //window caption
        //WS_POPUP,        //window style
        WS_OVERLAPPEDWINDOW,        //window style
        CW_USEDEFAULT,              //initial x position
        CW_USEDEFAULT,              //initial y position
        CW_USEDEFAULT,              //initial x size
        CW_USEDEFAULT,              //initial y size
        //300,300,
        NULL,                       //parent window handle
        NULL,                       //window menu handle
        hInstance,                  //program instance handle
        NULL);                      //creation parameters

    ShowWindow(hwnd,iCmdShow);
    UpdateWindow(hwnd);
}//CObject::InitInstance

void CObject::Run() {
	while (GetMessage(&msg,NULL,0,0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }//while
}//CObject::Run

WPARAM CObject::ExitInstance() {
    return msg.wParam;
}//CObject::ExitInstance

char CObject::szAppName[]="HelloWin";