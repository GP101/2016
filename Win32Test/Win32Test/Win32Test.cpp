#include "stdafx.h"
#include <windows.h>
#include <cmath>

POINT g_center;
int g_pixelPerUnit = 10;

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam,
    LPARAM lParam);
void OnPaint(HDC hdc);
void DrawFunction(HDC hdc, double(*MyFunction)(double x)
    , double begin, double end, COLORREF c, double step);
    void OnSize(HWND hwnd);
void Transform(double* x, double* y);
void DrawLine(HDC hdc, double x1, double y1, double x2, double y2, COLORREF c);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR szCmdLine, int iCmdShow)
{
    static WCHAR szAppName[] = L"HelloWin";
    HWND        hwnd;
    WNDCLASSEX  wndclass;

    wndclass.cbSize = sizeof(wndclass);
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;
    wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    RegisterClassEx(&wndclass);

    hwnd = CreateWindow(szAppName,     // window class name
        L"The Hello Program",            // window caption
        WS_OVERLAPPEDWINDOW,            // window style
        CW_USEDEFAULT,                  // initial x position
        CW_USEDEFAULT,                  // initial y position
        CW_USEDEFAULT,                  // initial x size
        CW_USEDEFAULT,                  // initial y size
        NULL,                           // parent window handle
        NULL,                           // window menu handle
        hInstance,                      // program instance handle
        NULL);                          // creation parameters

    OnSize(hwnd);
    ShowWindow(hwnd, iCmdShow); // (1)

    MSG         msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        DispatchMessage(&msg);
    }//while

    return 0;
}//WinMain()

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam,
    LPARAM lParam) // (1)
{
    switch (iMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        OnPaint(hdc);
        EndPaint(hwnd, &ps);
    }
    case WM_SIZE:
        OnSize(hwnd);
    }
    return DefWindowProc(hwnd, iMsg, wParam, lParam); // (2)
}

double Square(double x)
{
    return x * x;
}

double SqureRoot(double x)
{
    //return std::sqrt(x);
    return std::pow(x, 1/2.0);
}

//double(*CALLBACK)(double x)

void DrawFunction(HDC hdc,
    double (*MyFunction)(double x),
    double begin, double end, COLORREF c, double step = 0.5)
{
    double prevx = begin;
    double prevy = MyFunction(prevx);

    for (double x = begin; x <= end; x += step)
    {
        double y = MyFunction(x);
        DrawLine(hdc, prevx, prevy, x, y, c);
        prevx = x;
        prevy = y;
    }//for
}

void OnPaint(HDC hdc)
{
    DrawLine(hdc, -100, 0, +100, 0, RGB(255, 0, 0));
    DrawLine(hdc, 0, -100, 0, +100, RGB(0, 255, 0));
    // draw function Square( f(x) = x^2 ) from -10 to 10 for x
    DrawFunction(hdc, Square, -20, 20, RGB(0, 0, 255));
    DrawFunction(hdc, SqureRoot, 0, 40, RGB(255, 0, 255));
}

void DrawLine(HDC hdc, double x1, double y1, double x2, double y2, COLORREF c)
{
    HPEN hPen;
    HPEN hPrevPen;
    hPen = CreatePen(PS_SOLID, 0, c);
    hPrevPen = (HPEN)SelectObject(hdc, hPen);

    Transform(&x1, &y1);
    MoveToEx(hdc, x1, y1, NULL);
    Transform(&x2, &y2);
    LineTo(hdc, x2, y2);

    SelectObject(hdc, hPrevPen);
    DeleteObject(hPen);
}

void OnSize(HWND hwnd)
{
    RECT clientRect;
    ::GetClientRect(hwnd, &clientRect);
    const int width = clientRect.right - clientRect.left + 1;
    const int height = clientRect.bottom - clientRect.top + 1;
    g_center.x = width / 2;
    g_center.y = height / 2;
    g_pixelPerUnit = 10;
}

void Transform(double* x, double* y)
{
    *x = g_center.x + (*x) * g_pixelPerUnit;
    *y = g_center.y + -(*y) * g_pixelPerUnit;
}
