#include <windows.h>
#include "stdafx.h"
#include "CObject.h"

void CObject::InitInstance(HINSTANCE hInstance,PSTR szCmdLine,
						int iCmdShow) {
    hInst=hInstance;

    wndclass.cbSize         =sizeof(wndclass);
    wndclass.style          =CS_HREDRAW|CS_VREDRAW;
    wndclass.lpfnWndProc    =WndProc;
    wndclass.cbClsExtra     =0;
    wndclass.cbWndExtra     =0;
    wndclass.hInstance      =hInstance;
    wndclass.hIcon          =LoadIcon(hInstance,"resourc1");
    wndclass.hCursor        =LoadCursor(hInstance,"resourc1");
    wndclass.hbrBackground  =(HBRUSH)GetStockObject(WHITE_BRUSH);
    //{{seojt
    wndclass.lpszMenuName   ="MenuDemo";
    //}}seojt
    wndclass.lpszClassName  =szAppName;
    wndclass.hIconSm        =LoadIcon(hInstance,"resourc1");

    RegisterClassEx(&wndclass);

    hwnd=CreateWindow(szAppName,    //window class name
        "Res step2: Menu",          //window caption
        WS_OVERLAPPEDWINDOW,        //window style
        CW_USEDEFAULT,              //initial x position
        CW_USEDEFAULT,              //initial y position
        CW_USEDEFAULT,              //initial x size
        CW_USEDEFAULT,              //initial y size
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