// ConsoleOmok.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define BOARD_WIDTH     21
#define BOARD_HEIGHT    21
#define BLACK_STONE     1
#define WHITE_STONE     2
#define BORDER          (BLACK_STONE | WHITE_STONE)

typedef int BOARD[ BOARD_HEIGHT ][ BOARD_WIDTH ];

BOARD g_board;

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

int main()
{
    ClearBoard( g_board );
    DrawBoard( g_board );
    
    return 0;
}

