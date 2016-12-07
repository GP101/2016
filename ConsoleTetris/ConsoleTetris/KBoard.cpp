#include "KBoard.h"


void KBoard::Initialize()
{
    ::memset((char*)m_aBoard, 0, BOARD_SIZE_ROW * BOARD_SIZE_COL * sizeof(BOARD_CELL_TYPE));
}//KBoard::Initialize()


void KBoard::CopyFrom(const KBoard& rhs_)
{
    memcpy(m_aBoard, rhs_.m_aBoard, sizeof(m_aBoard));
}//KBoard::CopyFrom()


/// @brief  get cell value of the given World point from the 'm_aCurBoard[]'
bool KBoard::GetBoardCellValue(OUT char* pCellValue_, const KPoint worldPos_) const
{
    if (IsValidBoardPos(worldPos_) == true)
    {
        // set [out] parameter
        *pCellValue_ = m_aBoard[worldPos_.y][worldPos_.x];
        return true;
    }//if
    return false;
}//KBoard::GetBoardCellValue()


bool KBoard::IsRowRemovableOnBoard(int iRow_) const
{
    int iCellCount = 0;
    for (int iCol = 0; iCol < BOARD_SIZE_COL; ++iCol)
    {
        char cellValue = 0;
        KPoint point;
        point.x = iCol;
        point.y = iRow_;
        const bool bIsCellValue = GetBoardCellValue(OUT &cellValue, point);
        if (bIsCellValue == false)
        {
            return false;
        }
        if (cellValue != 0)
            iCellCount += 1;
    }//for
    return iCellCount == BOARD_SIZE_COL;
}//KBoard::IsRowRemovableOnBoard()


// @post 'aRows_' is sorted in descending order.
bool KBoard::GetRemovableRowFromBoard(OUT int* piNumOfRows_, int aRows_[]) const
{
    int iNumOfRows = 0;
    for (int iRow = BOARD_SIZE_ROW - 1; iRow >= 0; --iRow)
    {
        if (IsRowRemovableOnBoard(iRow) == true)
        {
            aRows_[iNumOfRows] = iRow;
            iNumOfRows += 1;
        }//if
    }//for

    if (iNumOfRows >= 1)
    {
        *piNumOfRows_ = iNumOfRows;
        return true;
    }//if

    return false;
}//KBoard::GetRemovableRowFromBoard()


void KBoard::RemoveRowFromBoard(int iRow_)
{
    int iSource = iRow_ - 1;
    int iDest = iRow_;
    //const int iNumMovingRows = iSource + 1;
    while (iSource >= 0)
    {
        memmove(m_aBoard[iDest], m_aBoard[iSource], sizeof(m_aBoard[0]));
        iDest = iSource;
        iSource -= 1;
    }
}//KBoard::RemoveRowFromBoard()


// @pre we assumes 'aRemoveRows' is sorted in descending order.
void KBoard::RemoveRowsFromBoard(int iNumOfRows, int aRemoveRows[])
{
    //printf("Removable Rows are %i\r\n", iNumOfRows);
    for (int iRow = 0; iRow < iNumOfRows; ++iRow)
    {
        RemoveRowFromBoard(aRemoveRows[iRow]);
        // remained rows must increased by one
        for (int i = iRow + 1; i < iNumOfRows; ++i)
        {
            aRemoveRows[i] += 1;
        }//for
    }//for
}//KBoard::RemoveRowsFromBoard()


void KBoard::LocateBlock(const KBlock& block_)
{
    for (int iStone = 0; iStone < block_.m_iNumStone; ++iStone)
    {
        // transform local coordinate to global coordinate
        const KPoint worldPos = block_.GetPos(iStone);
        // draw a block on the board
        const bool isValid = IsValidBoardPos(worldPos);
        if (isValid == true)
        {
            m_aBoard[worldPos.y][worldPos.x] = '#';
        }//if
    }//for
}//KBoard::LocateBlock()


/// @brief  check whether this Block can be located on the m_aCurBoard[] or not.
bool KBoard::CanLocateBlock(const KBlock& block_) const
{
    for (int iStone = 0; iStone < block_.m_iNumStone; ++iStone)
    {
        const KPoint worldPos = block_.GetPos(iStone);
        char cellValue = 0;
        const bool bIsGetValue = GetBoardCellValue(OUT &cellValue, worldPos);
        if (bIsGetValue == false || cellValue != 0)
            return false;
    }//for
    return true;
}//KBoard::CanLocateBlock()


/// @brief  draw Board on the console Window.
void KBoard::DrawBoard() const
{
    for (int y = 0; y < BOARD_SIZE_ROW; ++y)
    {
        for (int x = 0; x < BOARD_SIZE_COL; ++x)
        {
            SetCursorPosition(x, y);
            printf("%c", m_aBoard[y][x]);
        }//for
    }//for
}//KBoard::DrawBoard()
