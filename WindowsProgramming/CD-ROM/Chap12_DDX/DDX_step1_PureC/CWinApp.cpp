#include "CWinApp.h"

// destructor
CWinApp::~CWinApp()
{
    if ( m_pMainWnd != NULL )
    {
        delete m_pMainWnd;
        m_pMainWnd = NULL;
    }//if
}//CWinApp::~CWinApp()

void CWinApp::AddDocTemplate(CRuntimeClass* pRuntimeClass)
{
    m_pMainWnd = (CWnd*)pRuntimeClass->CreateObject();
    if ( m_pMainWnd == NULL )
        return;

    CREATESTRUCT    cs;

    m_pMainWnd->PreCreateWindow( cs );
    m_pMainWnd->m_hwnd = ::CreateWindow( szAppName,   //window class name
        "RTTI",                 //window caption
        WS_OVERLAPPEDWINDOW,    //window style
        CW_USEDEFAULT,          //initial x position
        CW_USEDEFAULT,          //initial y position
        CW_USEDEFAULT,          //initial x size
        CW_USEDEFAULT,          //initial y size
        NULL,                   //parent window handle
        NULL,                   //window menu handle
        m_hInstance,            //program instance handle
        NULL );                 //creation parameters
}//CWinApp::AddDocTemplate()

void CWinApp::InitInstance(HINSTANCE    hInstance,
                           PSTR         szCmdLine,
                           int          iCmdShow)
{
    WNDCLASSEX  wndclass;

    wndclass.cbSize         = sizeof(wndclass);
    wndclass.style          = CS_HREDRAW|CS_VREDRAW;
    wndclass.lpfnWndProc    = WndProc;
    wndclass.cbClsExtra     = 0;
    wndclass.cbWndExtra     = 0;
    wndclass.hInstance      = hInstance;
    wndclass.hIcon          = LoadIcon(NULL,IDI_APPLICATION);
    wndclass.hCursor        = LoadCursor(NULL,IDC_ARROW);
    wndclass.hbrBackground  = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName   = szAppName;
    wndclass.lpszClassName  = szAppName;
    wndclass.hIconSm        = LoadIcon(NULL,IDI_APPLICATION);

    ::RegisterClassEx(&wndclass);

    m_hInstance = hInstance;

    AddDocTemplate( RUNTIME_CLASS(CView) );    
    
    m_pMainWnd->ShowWindow( iCmdShow );
    m_pMainWnd->UpdateWindow();
}//CWinApp::InitInstance

void CWinApp::Run()
{
    MSG msg;
    int bFlag = TRUE;

    while ( TRUE )
    {
        if ( PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) )
        {
            if ( msg.message == WM_QUIT )
                break;

            TranslateMessage( &msg );
            DispatchMessage( &msg );
            bFlag = TRUE;
        }//if

        if ( bFlag )
            bFlag = OnIdle();
    }//while
}//CWinApp::Run()

WPARAM CWinApp::ExitInstance()
{
    return 0L;//msg.wParam;
}//CWinApp::ExitInstance

int CWinApp::OnIdle()
{
    return FALSE;
}//CWinApp::OnIdle()

char CWinApp::szAppName[] = "generic";

//Global object------------------------------------------------------
extern CWinApp app;

//Window procedure---------------------------------------------------
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    static CViewFunPointer  fpCViewGlobal = NULL;//pointer to a member function
    int                     i = 0;
    CView*                  p;

    while ( CView::messageMap[i].iMsg != 0 )
    {
        if ( iMsg == CView::messageMap[i].iMsg )
        {
            fpCViewGlobal = CView::messageMap[i].fp;
            p = static_cast<CView*>(app.m_pMainWnd);
            (p->*fpCViewGlobal)(wParam, lParam);

            return 0;
        }//if
        ++i;
    }//while

    return DefWindowProc(hwnd,iMsg,wParam,lParam);
}//WndProc()

int WINAPI WinMain(HINSTANCE    hInstance,
                   HINSTANCE    hPrevInstance,
                   PSTR         szCmdLine,
                   int          iCmdShow)
{
    app.InitInstance( hInstance, szCmdLine, iCmdShow );
    app.Run();

    return app.ExitInstance();
}//WinMain()
