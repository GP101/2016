// ConsoleOmok.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <windows.h>
#include <conio.h>

#define BOARD_WIDTH     21
#define BOARD_HEIGHT    21

#define EMPTY_STONE     0
#define BLACK_STONE     1
#define WHITE_STONE     2
#define BORDER          (BLACK_STONE | WHITE_STONE)
#define ESCAPE          27
#define MAX_ROW         19
#define MAX_COL         19

typedef int BOARD[BOARD_HEIGHT][BOARD_WIDTH];

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

struct Position
{
    int row;
    int col;
};//struct Position

BOARD       g_board;
int         g_keyState[KEY_MAX];
HANDLE      g_console = INVALID_HANDLE_VALUE;
Position    g_cursor = { 10, 10 };
int         g_turn = BLACK_STONE;

void ClearBoard(BOARD board)
{
    memset(board, 0, sizeof(BOARD));
    for (int row = 0; row < BOARD_HEIGHT; ++row)
    {
        board[row][0] = BORDER;
        board[row][20] = BORDER;
    }
    for (int col = 0; col < BOARD_WIDTH; ++col)
    {
        board[0][col] = BORDER;
        board[20][col] = BORDER;
    }
}//ClearBoard()

void DrawBoard(BOARD board)
{
    const char* stone[4] = { ". ", "[]", "()", "##" };
    for (int row = 0; row < BOARD_HEIGHT; ++row)
    {
        for (int col = 0; col < BOARD_WIDTH; ++col)
        {
            const int value = board[row][col];
            printf("%s", stone[value]);
        }
        printf("\r\n");
    }
}//DrawBoard()

void PutStone(BOARD board, int row, int col, int stone)
{
    board[row][col] = stone;
}//PutStone()

int GetStone(BOARD board, int row, int col)
{
    return board[row][col];
}//GetStone()

void ClearKeyState()
{
    memset(g_keyState, 0, sizeof(g_keyState));
}//ClearKeyState()

int IsKeyPressed(KeyboardId keyId)
{
    return g_keyState[keyId];
}//IsKeyPressed()

void UpdateKeyState()
{
    int ch = 0;
    ClearKeyState();
    ch = getch();
    if (ch == 32)
    {
        g_keyState[KEY_SPACE] = 1;
    }
    else if (ch == 27)
    {
        g_keyState[KEY_ESCAPE] = 1;
    }
    else if (ch == 0)
    {
        ch = getch();
        //printf( "%i\r\n", ch );
        switch (ch)
        {
        case 72:
            g_keyState[KEY_UP] = 1;
            break;
        case 75:
            g_keyState[KEY_LEFT] = 1;
            break;
        case 77:
            g_keyState[KEY_RIGHT] = 1;
            break;
        case 80:
            g_keyState[KEY_DOWN] = 1;
            break;
        }//switch
    }//if
}//UpdateKeyState()

void SetCursor(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(g_console, c);
}//SetCursor()

void DrawCursor(int row, int col)
{
    SetCursor(col * 2, row);
}//DrawCursor()

void UpdateCursor()
{
    if (IsKeyPressed(KEY_LEFT))
        g_cursor.col -= 1;
    else if (IsKeyPressed(KEY_RIGHT))
        g_cursor.col += 1;
    else if (IsKeyPressed(KEY_UP))
        g_cursor.row -= 1;
    else if (IsKeyPressed(KEY_DOWN))
        g_cursor.row += 1;

    if (g_cursor.row < 1)
        g_cursor.row = 1;
    if (g_cursor.row >= MAX_ROW)
        g_cursor.row = MAX_ROW;
    if (g_cursor.col < 1)
        g_cursor.col = 1;
    if (g_cursor.col >= MAX_COL)
        g_cursor.col = MAX_COL;
}//UpdateCursor()

void UpdateStone()
{
    if (IsKeyPressed(KEY_SPACE))
    {
        const int prevStone = GetStone(g_board, g_cursor.row, g_cursor.col);
        if (prevStone == 0)
        {
            PutStone(g_board, g_cursor.row, g_cursor.col, g_turn);
            if (g_turn == BLACK_STONE)
                g_turn = WHITE_STONE;
            else if (g_turn == WHITE_STONE)
                g_turn = BLACK_STONE;
        }
    }//if
}//UpdateStone()

int IsFiveStone(BOARD board, int row, int col, int rOffset, int cOffset )
{
    const int firstStone = GetStone(board, row, col);
    int stoneCounter = 1;
    int r = row;
    int c = col;
    for (int counter = 1; counter <= 4; ++counter )
    {
        r += rOffset;
        c += cOffset;
        const int stone = GetStone(board, r, c);
        if (stone == firstStone)
        {
            stoneCounter += 1;
        }//if
    }//for

    if (stoneCounter == 5)
    {
        return firstStone;
    }//if

    return EMPTY_STONE;
}//IsFiveStone()

int IsHorizontalFive(BOARD board, int row, int col)
{
    return IsFiveStone(board, row, col, 0, 1);
}//IsHorizontalFive()

int IsVerticalFive(BOARD board, int row, int col)
{
    return IsFiveStone(board, row, col, 1, 0);
}//IsVerticalFive()

int IsDiagonalFive(BOARD board, int row, int col)
{
    return IsFiveStone(board, row, col, 1, 1);
}//IsDiagonalFive()

int IsBackDiagonalFive(BOARD board, int row, int col)
{
    return IsFiveStone(board, row, col, -1, 1);
}//IsBackDiagonalFive()

int Find5Stone(BOARD board)
{
    for (int row = 1; row <= MAX_ROW - 4; ++row)
    {
        for (int col = 1; col <= MAX_ROW - 4; ++col)
        {
            const int isHorizontalFive = IsHorizontalFive(board, row, col);
            const int isVerticalFive = IsVerticalFive(board, row, col);
            if (isHorizontalFive != EMPTY_STONE || isVerticalFive != EMPTY_STONE)
            {
                return 1;
            }//if

            const int isDiagonalFive = IsDiagonalFive(board, row, col);
            if (isDiagonalFive != EMPTY_STONE)
            {
                return 1;
            }//if
        }
    }

    for (int row = 5; row <= MAX_ROW; ++row)
    {
        for (int col = 1; col <= MAX_ROW - 4; ++col)
        {
            const int isDiagonalFive = IsBackDiagonalFive(board, row, col);
            if (isDiagonalFive != EMPTY_STONE)
            {
                return 1;
            }//if
        }
    }
    return 0;
}

int main()
{
    g_console = GetStdHandle(STD_OUTPUT_HANDLE);
    ClearBoard(g_board);
    //PutStone(g_board, 5, 5, WHITE_STONE);
    //PutStone(g_board, 5, 6, BLACK_STONE);
    //PutStone(g_board, 6, 6, BLACK_STONE);

    ClearKeyState();

    while (IsKeyPressed(KEY_ESCAPE) == 0)
    {
        UpdateKeyState();
        UpdateCursor();
        UpdateStone();

        SetCursor(0, 0);
        DrawBoard(g_board);

        DrawCursor(g_cursor.row, g_cursor.col);

        const int isFiveStone = Find5Stone(g_board);
        if (isFiveStone == 1)
        {
            SetCursor(0, 21);
            printf("GameOver\r\n");
            break;
        }//if

        Sleep(50);
    }//while

    return 0;
}//main()

