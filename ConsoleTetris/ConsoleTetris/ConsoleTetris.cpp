#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "ConsoleTetrisUtil.h"
#include "KBoard.h"

#pragma comment(lib,"winmm.lib")


bool g_bIsExitGameLoop = false;


enum EKeys
{
    KEY_NULL = 0,
    KEY_LEFT = 'a',
    KEY_RIGHT = 'd',
    KEY_ESC = 27,
};//enum EKeys


KBoard              g_visibleBoard;
KBoard              g_hiddenBoard;
KBlock              g_curBlock;
float               g_fCurBlockTimer = 0.f;
float               g_fCurBlockSpeed = 0.25f; ///< unit is seconds per a block


void GenerateNextBlock( OUT KBlock& block_ )
{
    block_.m_aBlockPosition[0].x = 0;
    block_.m_aBlockPosition[0].y = 0;
    block_.m_aBlockPosition[1].x = 1;
    block_.m_aBlockPosition[1].y = 0;
    block_.m_aBlockPosition[2].x = 0;
    block_.m_aBlockPosition[2].y = 1;
    block_.m_aBlockPosition[3].x = 0;
    block_.m_aBlockPosition[3].y = 2;
    block_.m_worldPos.x = 2;
    block_.m_worldPos.y = 2;
    block_.m_iNumStone = 4;
}//GenerateNextBlock()


/// @brief onetime initialization works here.
void Initialize()
{
    InitializeConsole();

    g_visibleBoard.Initialize();
    g_hiddenBoard.Initialize();

    // test initialize a current block
    GenerateNextBlock(g_curBlock);
}//Initialize()


/// @brief  onetime finalization works here.
void Finalize()
{
    FinalizeConsole();
}//Finalize()


/// @brief  update game data per a frame.
void OnUpdate(float fElapsedTime_)
{
    // save current block state.
    KBlock savedBlock;
    savedBlock.CopyFrom(g_curBlock);

    // process user keyboard inputs
    int ch = 0;
    if (_kbhit())
    {
        ch = _getch();
        if (ch == KEY_ESC)
        {
            g_bIsExitGameLoop = true;
        }
        else if (ch == KEY_LEFT)
        {
            g_curBlock.m_worldPos.x -= 1;
            if (g_hiddenBoard.CanLocateBlock(g_curBlock) == false)
            {
                // restore current Block.
                g_curBlock.CopyFrom(savedBlock);
            }//if
        }
        else if (ch == KEY_RIGHT)
        {
            g_curBlock.m_worldPos.x += 1;
            if (g_hiddenBoard.CanLocateBlock(g_curBlock) == false)
            {
                // restore current Block.
                g_curBlock.CopyFrom(savedBlock);
            }//if
        }//if.. else if..
    }//if

    g_fCurBlockTimer += fElapsedTime_;
    if (g_fCurBlockTimer >= g_fCurBlockSpeed)
    {
        g_fCurBlockTimer -= g_fCurBlockSpeed; // reset current block timer
        g_curBlock.m_worldPos.y += 1;

        // try to locate a block on the Board
        if (g_hiddenBoard.CanLocateBlock(g_curBlock) == false)
        {
            // restore current Block.
            g_curBlock.CopyFrom(savedBlock);
            // finally locate current Block.
            g_hiddenBoard.LocateBlock(g_curBlock);

            // check whether removing rows are possible or not.
            int iNumOfRows = 0;
            int aRemoveRows[BOARD_SIZE_ROW];
            bool bIsRemovableRow = g_hiddenBoard.GetRemovableRowFromBoard(OUT &iNumOfRows, aRemoveRows);
            if (bIsRemovableRow == true)
            {
                g_hiddenBoard.RemoveRowsFromBoard(iNumOfRows, aRemoveRows);
            }//if

            // test regenerate a next Block.
            GenerateNextBlock(g_curBlock);
        }//if
    }//if
}//OnUpdate()


void OnDraw(float fElapsedTime_)
{
    // prepare working Board with current(previous frame) board data.
    g_visibleBoard.CopyFrom(g_hiddenBoard);

    g_visibleBoard.LocateBlock(g_curBlock);

    g_visibleBoard.DrawBoard();
}//OnDraw()


void main()
{
    Initialize();

    DWORD dwCurrTime = 0L;
    DWORD dwPrevTime = 0L;
    dwCurrTime = timeGetTime();
    dwPrevTime = dwCurrTime;

    // game loop
    while (g_bIsExitGameLoop == false)
    {
        DWORD dwElapsedTime = 0L;
        float fElapsedTimeInSecond = 0.f;

        // calculate inter-frame elapsed time
        {
            dwPrevTime = dwCurrTime;
            dwCurrTime = timeGetTime();
            dwElapsedTime = dwCurrTime - dwPrevTime;
            fElapsedTimeInSecond = dwElapsedTime / 1000.f;
            Sleep(10);
        }

        // emulate conventional game loop
        OnUpdate(fElapsedTimeInSecond);
        OnDraw(fElapsedTimeInSecond);
    }//while

    Finalize();
}//main()
