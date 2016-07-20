#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#pragma comment(lib,"winmm.lib")

#define BOARD_SIZE_ROW      20
#define BOARD_SIZE_COL      20
#define MAX_BLOCK_SIZE      6
#ifndef IN
#define IN
#endif
#ifndef OUT
#define OUT
#endif

HANDLE                  g_hConsole = INVALID_HANDLE_VALUE;
CONSOLE_CURSOR_INFO     g_oldConsoleCursorInfo;
bool                    g_bIsExitGameLoop = false;
char                    g_aBoard[ BOARD_SIZE_ROW ][ BOARD_SIZE_COL ];
char                    g_aRrevBoard[ BOARD_SIZE_ROW ][ BOARD_SIZE_COL ];

enum EKeys {
    KEY_NULL = 0,
    KEY_LEFT = 'a',
    KEY_RIGHT = 'd',
    KEY_ESC = 27,
};//enum EKeys

struct KPoint {
    int x;
    int y;
};//KPoint

struct KBlock {
    KPoint  m_aBlockPosition[ MAX_BLOCK_SIZE ];
    int     m_iNumBlock;
};//struct KBlock

void DrawBlockOnBoard( const KBlock* this_, int xBoard_, int yBoard_ ) {
    for( int iBlock = 0; iBlock < this_->m_iNumBlock; ++iBlock ) {
        // transform local coordinate to global coordinate
        const int xGlobal = this_->m_aBlockPosition[ iBlock ].x + xBoard_;
        const int yGlobal = this_->m_aBlockPosition[ iBlock ].y + yBoard_;
        // draw a block on the board
        g_aBoard[ yGlobal ][ xGlobal ] = '#';
    }//for
}//DrawBlockOnBoard()

KPoint      g_currentBlockPos = { 0, 0 };
KBlock      g_curBlock;

// x is the column, y is the row. The origin (0,0) is top-left.
void SetCursorPosition( int x, int y ) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition( g_hConsole, coord );
}//SetCursorPosition()

void DrawBoard() {
    for( int y = 0; y != BOARD_SIZE_COL; ++y ) {
        for( int x = 0; x != BOARD_SIZE_ROW; ++x ) {
            if( g_aBoard[ y ][ x ] == g_aRrevBoard[ y ][ x ] ) {
                continue;
            }//if
            SetCursorPosition( x, y );
            printf( "%c", g_aBoard[ y ][ x ] );
        }//for
    }//for
    ::memcpy( (char*)g_aRrevBoard, (char const*)g_aBoard, BOARD_SIZE_ROW * BOARD_SIZE_COL );
}//DrawBoard()

void Initialize() {
    ::memset( (char*)g_aBoard, 0, BOARD_SIZE_ROW * BOARD_SIZE_COL );
    ::memset( (char*)g_aRrevBoard, 0, BOARD_SIZE_ROW * BOARD_SIZE_COL );

    // Get the Win32 handle representing standard output.
    // This generally only has to be done once, so we make it static.
    g_hConsole = GetStdHandle( STD_OUTPUT_HANDLE );

    // test initialize a current block
    {
        g_curBlock.m_aBlockPosition[ 0 ].x = 0;
        g_curBlock.m_aBlockPosition[ 0 ].y = 0;
        g_curBlock.m_aBlockPosition[ 1 ].x = 1;
        g_curBlock.m_aBlockPosition[ 1 ].y = 0;
        g_curBlock.m_aBlockPosition[ 2 ].x = 0;
        g_curBlock.m_aBlockPosition[ 2 ].y = 1;
        g_curBlock.m_aBlockPosition[ 3 ].x = 0;
        g_curBlock.m_aBlockPosition[ 3 ].y = 2;
        g_curBlock.m_iNumBlock = 4;
    }

    // save console cursor info.
    //
    ::GetConsoleCursorInfo( g_hConsole, &g_oldConsoleCursorInfo );
    CONSOLE_CURSOR_INFO consoleCursorInfo;
    consoleCursorInfo = g_oldConsoleCursorInfo;
    consoleCursorInfo.bVisible = false;
    ::SetConsoleCursorInfo( g_hConsole, &consoleCursorInfo );
}//Initialize()

void Finalize() {
    // restore console cursor info.
    ::SetConsoleCursorInfo( g_hConsole, &g_oldConsoleCursorInfo );
}//Finalize()

void OnUpdate( float fElapsedTime_ ) {
    // process user keyboard inputs
    int ch = 0;
    if( _kbhit() ) {
        ch = _getch();
        if( ch == KEY_ESC ) {
            g_bIsExitGameLoop = true;
        }
        else if( ch == KEY_LEFT ) {
            g_currentBlockPos.x -= 1;
        } else if( ch == KEY_RIGHT ) {
            g_currentBlockPos.x += 1;
        }//if.. else if..
    }//if

    // clear game world(board)
    ::memset( (char*)g_aBoard, 0, BOARD_SIZE_ROW * BOARD_SIZE_COL );
    // draw game object
    DrawBlockOnBoard( IN &g_curBlock, g_currentBlockPos.x, g_currentBlockPos.y );
}//OnUpdate()

void OnDraw( float fElapsedTime_ ) {
    DrawBoard();
}//OnDraw()

void main() {
    Initialize();

    DWORD dwCurrTime = 0L;
    DWORD dwPrevTime = 0L;
    dwCurrTime = timeGetTime();
    dwPrevTime = dwCurrTime;

    // game loop
    while( g_bIsExitGameLoop == false ) {
        DWORD dwElapsedTime = 0L;
        float fElapsedTimeInSecond = 0.f;

        // calculate inter-frame elapsed time
        {
            dwPrevTime = dwCurrTime;
            dwCurrTime = timeGetTime();
            dwElapsedTime = dwCurrTime - dwPrevTime;
            fElapsedTimeInSecond = dwElapsedTime / 1000.f;
            Sleep( 10 );
        }

        // emulate conventional game loop
        OnUpdate( fElapsedTimeInSecond );
        OnDraw( fElapsedTimeInSecond );
    }//while

    Finalize();
}//main()
