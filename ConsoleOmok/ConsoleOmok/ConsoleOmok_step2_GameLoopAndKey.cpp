// ConsoleOmok.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <windows.h>
#include <conio.h>

#define BOARD_WIDTH     21
#define BOARD_HEIGHT    21

#define BLACK_STONE     1
#define WHITE_STONE     2
#define BORDER          (BLACK_STONE | WHITE_STONE)
#define ESCAPE          27

typedef int BOARD[ BOARD_HEIGHT ][ BOARD_WIDTH ];

enum KeyboardId
{
    KEY_LEFT,
    KEY_RIGHT,
    KEY_UP,
    KEY_DOWN,
    KEY_SPACE,
    KEY_ESCAPE,
    KEY_MAX,
};//enum KeyboardId

BOARD   g_board;
int     g_keyState[ KEY_MAX ];

void ClearBoard( BOARD board )
{
    memset( board, 0, sizeof( BOARD ) );
    for( int row = 0; row < BOARD_HEIGHT; ++row )
    {
        board[ row ][ 0 ] = BORDER;
        board[ row ][ 20 ] = BORDER;
    }
    for( int col = 0; col < BOARD_WIDTH; ++col )
    {
        board[ 0 ][ col ] = BORDER;
        board[ 20 ][ col ] = BORDER;
    }
}//ClearBoard()

void DrawBoard( BOARD board )
{
    const char* stone[ 4 ] = { ". ", "[]", "()", "##" };
    for( int row = 0; row < BOARD_HEIGHT; ++row )
    {
        for( int col = 0; col < BOARD_WIDTH; ++col )
        {
            const int value = board[ row ][ col ];
            printf( "%s", stone[ value ] );
        }
        printf( "\r\n" );
    }
}//DrawBoard()

void PutStone( BOARD board, int row, int col, int stone )
{
    board[ row ][ col ] = stone;
}

void ClearKeyState()
{
    memset( g_keyState, 0, sizeof( g_keyState ) );
}//ClearKeyState()

int IsKeyPressed( KeyboardId keyId )
{
    return g_keyState[ keyId ];
}//IsKeyPressed()

void UpdateKeyState()
{
    int ch = 0;
    ClearKeyState();
    ch = getch();
    if( ch == 32 )
    {
        g_keyState[ KEY_SPACE ] = 1;
    }
    else if( ch == 27 )
    {
        g_keyState[ KEY_ESCAPE ] = 1;
    }
    else if( ch == 0 )
    {
        ch = getch();
        //printf( "%i\r\n", ch );
        switch( ch )
        {
        case 72:
            g_keyState[ KEY_UP ] = 1;
            break;
        case 75:
            g_keyState[ KEY_LEFT ] = 1;
            break;
        case 77:
            g_keyState[ KEY_RIGHT ] = 1;
            break;
        case 80:
            g_keyState[ KEY_DOWN ] = 1;
            break;
        }//switch
    }//if
}//UpdateKeyState()

int main()
{
    ClearBoard( g_board );
    PutStone( g_board, 5, 5, WHITE_STONE );
    PutStone( g_board, 5, 6, BLACK_STONE );
    PutStone( g_board, 6, 6, BLACK_STONE );

    ClearKeyState();

    while( IsKeyPressed( KEY_ESCAPE ) == 0 )
    {
        UpdateKeyState();
        DrawBoard( g_board );
        Sleep( 50 );
    }//while

    return 0;
}//main()

