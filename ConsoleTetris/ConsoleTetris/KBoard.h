#ifndef _KBOARD_H
#define _KBOARD_H

#include "ConsoleTetrisUtil.h"


typedef char BOARD_CELL_TYPE;


class KBoard
{
public:
    static bool IsValidBoardPos(const KPoint worldPos_)
    {
        if (worldPos_.y >= 0 && worldPos_.y < BOARD_SIZE_ROW
            && worldPos_.x >= 0 && worldPos_.x < BOARD_SIZE_COL)
        {
            return true;
        }//if

        return false;
    }//IsValidBoardPos()

public:
    void Initialize();

    void CopyFrom(const KBoard& rhs_);

    /// @brief  get cell value of the given World point from the 'm_aCurBoard[]'
    bool GetBoardCellValue(OUT char* pCellValue_, const KPoint worldPos_) const;

    bool IsRowRemovableOnBoard(int iRow_) const;

    // @post 'aRows_' is sorted in descending order.
    bool GetRemovableRowFromBoard(OUT int* piNumOfRows_, int aRows_[]) const;

    void RemoveRowFromBoard(int iRow_);

    // @pre we assumes 'aRemoveRows' is sorted in descending order.
    void RemoveRowsFromBoard(int iNumOfRows, int aRemoveRows[]);

    void LocateBlock(const KBlock& block_);

    /// @brief  check whether this Block can be located on the m_aCurBoard[] or not.
    bool CanLocateBlock(const KBlock& block_) const;

    /// @brief  draw Board on the console Window.
    void DrawBoard() const;

private:
    BOARD_CELL_TYPE     m_aBoard[BOARD_SIZE_ROW][BOARD_SIZE_COL]; // Working board used in current frame.
};//class KBoard

#endif // _KBOARD_H
