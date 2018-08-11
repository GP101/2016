#include <windows.h>

//Forward declaration------------------------------------------------
LRESULT CALLBACK WndProc(HWND hwnd,UINT iMsg,WPARAM wParam,
                         LPARAM lParam);

//Class CObject------------------------------------------------------
class CObject {
protected:
    static char szAppName[];
    HWND        hwnd;
    MSG         msg;
    WNDCLASSEX  wndclass;

public:
    void InitInstance(HINSTANCE hInstance,PSTR szCmdLine,
                      int iCmdShow);
    void Run();
    WPARAM ExitInstance();

    // message handler
    virtual void OnCreate()      = 0;
    virtual void OnDraw()        = 0;
    virtual void OnDestroy()     = 0;
    virtual void OnLButtonDown() = 0;
};//class CObject

void CObject::InitInstance(HINSTANCE hInstance,PSTR szCmdLine,
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

//----------------------------------------------------------------
// pointer declaration for upcase(subtype principle)
CObject* pCObject; 

//class CView--------------------------------------------------------
class CView : public CObject {
public:
    // override all message handler
    void OnCreate();
    void OnDraw();
    void OnDestroy();
    void OnLButtonDown();
};//class CView

//CView Event handler------------------------------------------------
void CView::OnCreate() {
}//CView::OnCreate

void CView::OnDraw() {
    HDC         hdc;
    PAINTSTRUCT ps;
    RECT        rect;

    hdc=BeginPaint(hwnd,&ps);
    GetClientRect(hwnd,&rect);
    DrawText(hdc,"Hello, Windows!",-1,&rect,
        DT_SINGLELINE|DT_CENTER|DT_VCENTER);
    EndPaint(hwnd,&ps);
}//CView::OnDraw

void CView::OnDestroy() {
    PostQuitMessage(0);
}//CView::OnDestroy

void CView::OnLButtonDown() {
    MessageBox(NULL,"MESSAGE","TITLE",MB_ICONEXCLAMATION|MB_OK);
}//CView::OnLButtonDown

//Global object------------------------------------------------------
CView app;

//Window procedure---------------------------------------------------
LRESULT CALLBACK WndProc(HWND hwnd,UINT iMsg,WPARAM wParam,
                         LPARAM lParam) {
    switch (iMsg) {
    case WM_CREATE:
        pCObject->OnCreate();    
        return 0;
    case WM_PAINT:
        pCObject->OnDraw();
        return 0;
    case WM_DESTROY:
        pCObject->OnDestroy();
        return 0;
    case WM_LBUTTONDOWN:
        pCObject->OnLButtonDown();
        return 0;
    }//switch
    return DefWindowProc(hwnd,iMsg,wParam,lParam);
}//WndProc

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,
                   PSTR szCmdLine,int iCmdShow) {
    pCObject = &app;
    pCObject->InitInstance(hInstance,szCmdLine,iCmdShow);
    pCObject->Run();
    return pCObject->ExitInstance();
}//WinMain