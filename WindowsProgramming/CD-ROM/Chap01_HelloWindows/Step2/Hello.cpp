#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   PSTR szCmdLine, int iCmdShow)
{
    static char szAppName[] = "HelloWin";
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

    return 0;
}//WinMain()
