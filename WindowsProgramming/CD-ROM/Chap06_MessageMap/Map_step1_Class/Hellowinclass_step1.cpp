#include <windows.h>

//Forward declaration------------------------------------------------
LRESULT CALLBACK WndProc(HWND hwnd,UINT iMsg,WPARAM wParam,
                         LPARAM lParam);

//Class definition---------------------------------------------------
class CApp {
    static char szAppName[];
    HWND        hwnd;
    MSG         msg;
    WNDCLASSEX  wndclass;

public:
    void InitInstance(HINSTANCE hInstance, PSTR szCmdLine, 
                      int iCmdShow);
    void Run();
    WPARAM ExitInstance();

    // message handler
    void OnCreate();
    void OnDraw();
    void OnDestroy();
};//class CApp

void CApp::InitInstance(HINSTANCE hInstance,PSTR szCmdLine,
                        int iCmdShow) {
    wndclass.cbSize         = sizeof(wndclass);
    wndclass.style          = CS_HREDRAW|CS_VREDRAW;
    wndclass.lpfnWndProc    = WndProc;
    wndclass.cbClsExtra     = 0;
    wndclass.cbWndExtra     = 0;
    wndclass.hInstance      = hInstance;
    wndclass.hIcon          = LoadIcon(NULL,IDI_APPLICATION);
    wndclass.hCursor        = LoadCursor(NULL,IDC_ARROW);
    wndclass.hbrBackground  = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName   = NULL;
    wndclass.lpszClassName  = szAppName;
    wndclass.hIconSm        = LoadIcon(NULL,IDI_APPLICATION);

    RegisterClassEx(&wndclass);

    hwnd=CreateWindow(szAppName,    //window class name
        "The Hello Program",        //window caption
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
}//CApp::InitInstance

void CApp::Run() {
    while (GetMessage(&msg,NULL,0,0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }//while
}//CApp::Run

WPARAM CApp::ExitInstance() {
    return msg.wParam;
}//CApp::ExitInstance

char CApp::szAppName[]="HelloWin";

//Event handler------------------------------------------------------
void CApp::OnCreate() {
}//CApp::OnCreate

void CApp::OnDraw() {
    HDC         hdc;
    PAINTSTRUCT ps;
    RECT        rect;

    hdc=BeginPaint(hwnd,&ps);
    GetClientRect(hwnd,&rect);
    DrawText(hdc,"Hello, Windows!",-1,&rect,
        DT_SINGLELINE|DT_CENTER|DT_VCENTER);
    EndPaint(hwnd,&ps);
}//CApp::OnDraw

void CApp::OnDestroy() {
    PostQuitMessage(0);
}//CApp::OnDestroy

//Global object------------------------------------------------------
CApp app;

//Window procedure---------------------------------------------------
LRESULT CALLBACK WndProc(HWND hwnd,UINT iMsg,WPARAM wParam,
                         LPARAM lParam) {
    switch (iMsg) {
    case WM_CREATE:
        app.OnCreate();    
        return 0;
    case WM_PAINT:
        app.OnDraw();
        return 0;
    case WM_DESTROY:
        app.OnDestroy();
        return 0;
    }//switch
    return DefWindowProc(hwnd,iMsg,wParam,lParam);
}//WndProc

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,
                   PSTR szCmdLine,int iCmdShow) {
    app.InitInstance(hInstance,szCmdLine,iCmdShow);
    app.Run();
    return app.ExitInstance();
}//WinMain