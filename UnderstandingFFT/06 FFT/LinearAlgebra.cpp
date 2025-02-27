// LinearAlgebra.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "LinearAlgebra.h"
//_20180519_jintaeks
#include "KVectorUtil.h"
#include <MMSystem.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
#include <complex>
#include <valarray>

#pragma comment(lib,"winmm.lib")

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
// _20180519_jintaeks
HWND    g_hwnd = NULL;
HDC     g_hdc = 0;
HBITMAP g_hBitmap = 0;
RECT    g_clientRect;

const double SAMPLING_STEP = 1 / 40.0; // 40 sampling per second
const int BIN_SIZE = 100; // # of samples
using ComplexArray = std::valarray<std::complex<double> >;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void                Initialize();
void                Finalize();
void                OnSize();
void                OnPaint();
void                OnIdle(float fElapsedTime_);
void                dft(ComplexArray& x);
void                fft(ComplexArray& x);
void                ifft( ComplexArray& x );

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LINEARALGEBRA, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LINEARALGEBRA));

    Initialize();

    DWORD dwOldTime = ::timeGetTime();

    MSG msg;

    // Main message loop:
    while (true)
    {
        ::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);
        const DWORD dwNewTime = ::timeGetTime();
        const BOOL bIsTranslateMessage = TranslateAccelerator(msg.hwnd, hAccelTable, &msg);
        if (!bIsTranslateMessage)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }//if

        OnIdle(float(dwNewTime - dwOldTime) / 1000.f);
        Sleep(10);

        dwOldTime = dwNewTime;

        if (msg.message == WM_QUIT)
        {
            break;
        }//if
    }//while

    Finalize();

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LINEARALGEBRA));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LINEARALGEBRA);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   // _20180519_jintaeks
   g_hwnd = hWnd;
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}


//_20180519_jintaeks
void OnPaint(HDC hdc)
{
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            // _20180519_jintaeks
            OnPaint( hdc );
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_SIZE:
        OnSize();
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

void Initialize()
{
}//Initialize()

void Finalize()
{
    if (g_hdc != 0) {
        DeleteDC(g_hdc);
        g_hdc = 0;
    }//if
    if (g_hBitmap != 0) {
        DeleteObject(g_hBitmap);
        g_hBitmap = 0;
    }//if
}//Finalize()

void OnSize()
{
    Finalize();

    ::GetClientRect(g_hwnd, &g_clientRect);
    const int iWidth = g_clientRect.right - g_clientRect.left + 1;
    const int iHeight = g_clientRect.bottom - g_clientRect.top + 1;

    KVector2 origin;
    origin.x = iWidth / 2.0f;
    origin.y = iHeight / 2.0f;
    KVectorUtil::g_screenCoordinate.SetInfo(KVector2(40, 0), KVector2(0, -40), origin);

    HDC hdc = ::GetDC(g_hwnd);
    g_hdc = CreateCompatibleDC(hdc);
    g_hBitmap = CreateCompatibleBitmap(hdc, iWidth, iHeight);
    SelectObject(g_hdc, g_hBitmap);
}//OnSize()

double SignalFunction(double t)
{
    // A = 0.5, frequency fc = 3Hz and phase ϕ = π / 6 radians(or 30∘)
    //0.5 * cos(2.0 * M_PI * 3.0 * t + M_PI / 6.0)
    //return 0.5 * cos(2.0 * M_PI * 3.0 * t + M_PI / 6.0);

    //return cos( 2.0 * M_PI * 4 * t ) + 1.5 * cos( 2.0 * M_PI * 8 * t + M_PI / 4.0 ) + 2.0 * cos( 2.0 * M_PI * 10 * t + M_PI / 4.0 );
    //return cos( 2.0 * M_PI * 4 * t ) + 1.5 * cos( 2.0 * M_PI * 8 * t + M_PI / 4.0 );
    return cos(2.0 * M_PI * 4 * t);
}

void DrawInputSignal()
{
    double oldY = SignalFunction(0);
    double oldX = 0;
    double x = 0;
    for(int i = 1; i < BIN_SIZE; ++i)
    {
        x += SAMPLING_STEP;
        double y = SignalFunction(x);
        KVectorUtil::DrawLine(g_hdc, KVector2(oldX, oldY), KVector2((double)x, (double)y), 2, PS_SOLID, RGB(0, 0, 0));
        oldX = x;
        oldY = y;
    }
}

void OnRender( HDC hdc, float fElapsedTime_ )
{
    KBasis2     basis2;
    basis2.SetInfo( KVector2( 4.0, 0.0 ), KVector2( 0.0, 4.0 ) );
    KVectorUtil::SetBasis2( basis2 );

    KVectorUtil::DrawGrid( hdc, 20, 20 );
    KVectorUtil::DrawAxis( hdc, 20, 20 );

    DrawInputSignal( );

    {
        //KScreenCoordinate oldCoord = KVectorUtil::g_screenCoordinate;
        //KScreenCoordinate newCoord = oldCoord;
        //newCoord.origin.y += 200;
        //KVectorUtil::SetScreenCoordinate( newCoord );

        std::complex<double> test[BIN_SIZE];
        // fill test signal data
        double x = 0;
        double y;
        for(int i = 0; i < BIN_SIZE; ++i)
        {
            test[i] = std::complex<double>( SignalFunction( x ) );
            x += SAMPLING_STEP;
        }
        ComplexArray data( test, BIN_SIZE );

        // forward fft
        //fft(data);
        dft(data);

        const double N_SAMPLES = BIN_SIZE / 2;
        double re = data[0].real();
        double im = data[0].imag();
        double amplitude = sqrt(re*re + im*im) / N_SAMPLES;
        double oldX = 0;
        double oldY = amplitude;
        x = oldX;
        y = oldY;
        for(int i = 1; i < BIN_SIZE; ++i)
        {
            x += SAMPLING_STEP;
            re = data[i].real();
            im = data[i].imag();
            amplitude = sqrt(re*re + im*im) / N_SAMPLES;
            y = amplitude;

            //std::cout << data[i] << std::endl;
            KVectorUtil::DrawLine(g_hdc, KVector2(oldX, oldY), KVector2((double)x, (double)y), 2, PS_SOLID, RGB(255, 0, 0));

            // display Hz for every 10 steps
            if(i % 10 == 0 && i < BIN_SIZE/2) {
                KVectorUtil::DrawLine( g_hdc, KVector2( (double)x, (double)1 ), KVector2( (double)x, (double)0 ), 1, PS_DOT, RGB( 255, 0, 255 ) );
                KVector2 screenPos = KVectorUtil::GetScreenPoint( KVector2( x, 0.0 ) );
                char buffer[80];
                double ratio = (double)i / double(BIN_SIZE);
                sprintf_s( buffer, "%gHz", ratio / SAMPLING_STEP );
                ::TextOutA( hdc, (int)screenPos.x, (int)screenPos.y, buffer, strlen( buffer ) );
            }
            if( i == BIN_SIZE / 2 ) {
                KVectorUtil::DrawLine( g_hdc, KVector2( (double)x, (double)10 ), KVector2( (double)x, (double)0 ), 1, PS_DOT, RGB( 255, 0, 255 ) );
            }

            oldX = x;
            oldY = y;
        }
    }
}

void OnIdle(float fElapsedTime_)
{
    const int iWidth = g_clientRect.right - g_clientRect.left + 1;
    const int iHeight = g_clientRect.bottom - g_clientRect.top + 1;

    HDC hdc = ::GetDC(g_hwnd);

    HBRUSH brush;
    brush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(g_hdc, brush);
    Rectangle(g_hdc, 0, 0, iWidth, iHeight);

    {
        OnRender(g_hdc, fElapsedTime_);
    }

    BitBlt(hdc, 0, 0, iWidth, iHeight, g_hdc, 0, 0, SRCCOPY);
    DeleteObject(brush);

    ::ReleaseDC(g_hwnd, hdc);
}//OnIdle()

void dft(ComplexArray& x)
{
    const size_t N = x.size();

    ComplexArray xresult(N);

    for (size_t k = 0; k < N; ++k)
    {
        xresult[k] = 0;
        for (size_t n = 0; n < N; ++n)
        {
            std::complex<double> e = std::polar(1.0, -2 * M_PI * k * (double)n / (double)N);
            xresult[k] += x[n] * e;
        }
    }
    x = xresult;
}

// Cooley-Tukey FFT (in-place, divide-and-conquer)
// Higher memory requirements and redundancy although more intuitive
void fft( ComplexArray& x )
{
    const size_t N = x.size();
    if (N <= 1) return;

    // divide
    ComplexArray even = x[std::slice( 0, N / 2, 2 )];
    ComplexArray  odd = x[std::slice( 1, N / 2, 2 )];

    // conquer
    fft(even);
    fft(odd);

    // combine
    for (size_t k = 0; k < N / 2; ++k)
    {
        std::complex<double> t = std::polar( 1.0, -2 * M_PI * k / N );
        x[k] = even[k] + t * odd[k];
        x[k + N / 2] = even[k] - t * odd[k];
    }
}

// inverse fft (in-place)
void ifft( ComplexArray& x )
{
    // conjugate the complex numbers
    x = x.apply(std::conj);

    // forward fft
    fft(x);

    // conjugate the complex numbers again
    x = x.apply(std::conj);

    // scale the numbers
    x /= x.size();
}
