#ifndef _CONSOLETETRISUTIL_H
#define _CONSOLETETRISUTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define BOARD_SIZE_ROW      20
#define BOARD_SIZE_COL      12
#define MAX_BLOCK_SIZE      6

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif


extern HANDLE g_hConsole;


void InitializeConsole();
void FinalizeConsole();
/// @param  x is the column, y is the row. The origin (0,0) is top-left.
void SetCursorPosition(int x, int y);


struct KPoint
{
    int x;
    int y;
};//KPoint


/// @brief  represent a block in the Tetris game.
/// @desc   A block is consisted of several stones.
struct KBlock
{
    KPoint  m_aBlockPosition[MAX_BLOCK_SIZE];   ///< stone positions(local space)
    int     m_iNumStone;    ///< number of stones.
    KPoint  m_worldPos;     ///< World position of the Block

    /// @brief  get world position of a stone.
    KPoint GetPos(int iStone_) const
    {
        KPoint p;
        p.x = m_aBlockPosition[iStone_].x + m_worldPos.x;
        p.y = m_aBlockPosition[iStone_].y + m_worldPos.y;
        return p;
    }//GetPos()

    void CopyFrom(const KBlock& rhs_)
    {
        memcpy(this, &rhs_, sizeof(KBlock));
    }//CopyFrom()
};//struct KBlock


#endif // _CONSOLETETRISUTIL_H