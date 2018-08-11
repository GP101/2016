#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   PSTR szCmdLine, int iCmdShow)
{
    static char szAppName[] = "HelloWin";
    HWND        hwnd;
    MSG         msg;
    WNDCLASSEX  wndclass;

    wndclass.cbSize         = sizeof( wndclass );
    wndclass.style          = CS_HREDRAW|CS_VREDRAW;
    wndclass.lpfnWndProc    = DefWindowProc;
    wndclass.cbClsExtra     = 0;
    wndclass.cbWndExtra     = 0;
    wndclass.hInstance      = hInstance;
    wndclass.hIcon          = LoadIcon( NULL,IDI_APPLICATION );
    wndclass.hCursor        = LoadCursor( NULL,IDC_ARROW );
    wndclass.hbrBackground  = (HBRUSH)GetStockObject( WHITE_BRUSH );
    wndclass.lpszMenuName   = NULL;
    wndclass.lpszClassName  = szAppName;
    wndclass.hIconSm        = LoadIcon( NULL, IDI_APPLICATION );

    RegisterClassEx( &wndclass );

    hwnd = CreateWindow( szAppName,     // window class name
        "The Hello Program",            // window caption
        WS_OVERLAPPEDWINDOW,            // window style
        CW_USEDEFAULT,                  // initial x position
        CW_USEDEFAULT,                  // initial y position
        CW_USEDEFAULT,                  // initial x size
        CW_USEDEFAULT,                  // initial y size
        NULL,                           // parent window handle
        NULL,                           // window menu handle
        hInstance,                      // program instance handle
        NULL);                          // creation parameters

    ShowWindow( hwnd, iCmdShow );

    while ( GetMessage(&msg,NULL,0,0) )
    {
        DispatchMessage( &msg );
    }//while

    return 0;
}//WinMain()
