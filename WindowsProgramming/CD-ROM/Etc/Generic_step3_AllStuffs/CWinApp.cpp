#include <windows.h>
#include <commctrl.h>
#include "CObject.h"
#include "CView.h"
#include "CWinApp.h"

CWinApp::~CWinApp()
{
    if (m_pMainFrame != NULL)
        delete m_pMainFrame;
    if (m_pView != NULL)
        delete m_pView;
}//CWinApp::~CWinApp()

void CWinApp::AddDocTemplate(CRuntimeClass* pMainFrame,CRuntimeClass* pView) {
    //Create MainFrame
    m_pRuntimeClass=pMainFrame;
    m_pMainFrame=m_pRuntimeClass->CreateObject();
    //Create View
    m_pRuntimeClass=pView;
    m_pView=m_pRuntimeClass->CreateObject();
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
    //wndclass.hbrBackground  =(HBRUSH)GetStockObject(WHITE_BRUSH);
    //{{GENERIC 3
    wndclass.hbrBackground  =(HBRUSH)(COLOR_WINDOW+1);
    //}}GENERIC 3
    wndclass.lpszMenuName   =szAppName;//Attach Menu
    wndclass.lpszClassName  =szAppName;
    wndclass.hIconSm        =LoadIcon(hInstance,szAppName);//Attach Icon

    ::RegisterClassEx(&wndclass);

    //{{
     wndclass.lpszClassName = "ClientWndProc" ;
     wndclass.hInstance     = hInstance ;
     wndclass.lpfnWndProc   = ClientWndProc ;
     wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
     wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
     wndclass.lpszMenuName  = NULL ;
     wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
     wndclass.style         = 0 ;
     wndclass.cbClsExtra    = 0 ;
     wndclass.cbWndExtra    = 0 ;
	 wndclass.hIconSm       = LoadIcon (NULL, IDI_APPLICATION) ;

     RegisterClassEx (&wndclass) ;
    //}}
    PreCreateWindow(cs);

    HWND hwnd;
    
    hwnd=CreateWindowEx(
        0L,
        szAppName,    //window class name
        "Generic3 Application by seojt@kogstudios.com", //window caption
        WS_OVERLAPPEDWINDOW,        //window style
        CW_USEDEFAULT,              //initial x position
        CW_USEDEFAULT,              //initial y position
        CW_USEDEFAULT,              //initial x size
        CW_USEDEFAULT,              //initial y size
        NULL,                       //parent window handle
        NULL,                       //window menu handle
        hInstance,                  //program instance handle
        NULL);                      //creation parameters
    
    AddDocTemplate(RUNTIME_CLASS(CMainFrame),RUNTIME_CLASS(CClientView));
    ::ShowWindow(hwnd,iCmdShow);
    ::UpdateWindow(hwnd);
    //{{GENERIC 3
    InitCommonControls();
    //}}GENERIC 3
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
