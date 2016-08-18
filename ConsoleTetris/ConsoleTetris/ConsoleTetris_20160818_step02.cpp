#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#pragma comment(lib,"winmm.lib")

#define BOARD_SIZE_ROW      20
#define BOARD_SIZE_COL      12
#define MAX_BLOCK_SIZE      6
#ifndef IN
#define IN
#endif
#ifndef OUT
#define OUT
#endif

typedef char BOARD_CELL_TYPE;

HANDLE                  g_hConsole = INVALID_HANDLE_VALUE;
CONSOLE_CURSOR_INFO     g_oldConsoleCursorInfo;
bool                    g_bIsExitGameLoop = false;
BOARD_CELL_TYPE         g_aBoard[BOARD_SIZE_ROW][BOARD_SIZE_COL]; // Working board used in current frame.
BOARD_CELL_TYPE         g_aCurBoard[BOARD_SIZE_ROW][BOARD_SIZE_COL]; // Current Board state

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

/// @brief  check whether World board position is valid or not.
bool IsValidBoardPos(const KPoint worldPos_) {
    if (worldPos_.y >= 0 && worldPos_.y < BOARD_SIZE_ROW
        && worldPos_.x >= 0 && worldPos_.x < BOARD_SIZE_COL) {
        return true;
    }//if

    return false;
}//IsValidBoardPos()

/// @brief  get cell value of the given World point from the 'g_aCurBoard[]'
bool GetBoardCellValue( OUT char* pCellValue_, const KPoint worldPos_) {
    if (IsValidBoardPos(worldPos_) == true) {
        // set [out] parameter
        *pCellValue_ = g_aCurBoard[worldPos_.y][worldPos_.x];
        return true;
    }//if
    return false;
}//GetBoardCellValue()

bool IsRowRemovableOnBoard(int iRow_) {
    int iCellCount = 0;
    for (int iCol = 0; iCol < BOARD_SIZE_COL; ++iCol) {
        char cellValue = 0;
        KPoint point;
        point.x = iCol;
        point.y = iRow_;
        const bool bIsCellValue = GetBoardCellValue( OUT &cellValue, point );
        if (bIsCellValue == false) {
            return false;
        }
        if (cellValue != 0)
            iCellCount += 1;
    }//for
    return iCellCount == BOARD_SIZE_COL;
}//IsRowRemovableOnBoard()

bool GetRemovableRowFromBoard(int* piNumOfRows_, int aRows_[]) {
    int iNumOfRows = 0;
    for (int iRow = 0; iRow < BOARD_SIZE_ROW; ++iRow) {
        if (IsRowRemovableOnBoard(iRow) == true) {
            aRows_[iNumOfRows] = iRow;
            iNumOfRows += 1;
        }//if
    }//for

    if (iNumOfRows >= 1) {
        *piNumOfRows_ = iNumOfRows;
        return true;
    }//if

    return false;
}//GetRemovableRowFromBoard()

void RemoveRowFromBoard(int iNumOfRows, int aRemoveRows[]) {
    printf("Removable Rows are %i\r\n", iNumOfRows);
}//RemoveRowFromBoard()

/// @brief  represent a block in the Tetris game.
/// @desc   A block is consisted of several stones.
struct KBlock {
    KPoint  m_aBlockPosition[MAX_BLOCK_SIZE];   ///< stone poisitions
    int     m_iNumStone;    ///< number of stones.
    KPoint  m_worldPos;     ///< World poisition of the Block

    /// @brief  get world poisition of a stone.
    KPoint GetPos(int iStone_) const {
        KPoint p;
        p.x = m_aBlockPosition[iStone_].x + m_worldPos.x;
        p.y = m_aBlockPosition[iStone_].y + m_worldPos.y;
        return p;
    }//GetPos()

    /// @brief  draw a block on the give board
    /// @param  aBoard : [in,out] destination block
    void DrawBlockOnBoard( BOARD_CELL_TYPE aBoard[BOARD_SIZE_ROW][BOARD_SIZE_COL] ) {
        for (int iStone = 0; iStone < m_iNumStone; ++iStone) {
            // transform local coordinate to global coordinate
            KPoint worldPos = GetPos(iStone);
            // draw a block on the board
            if (worldPos.y >= 0 && worldPos.y < BOARD_SIZE_ROW
                && worldPos.x >= 0 && worldPos.x < BOARD_SIZE_COL) {
                aBoard[worldPos.y][worldPos.x] = '#';
            }//if
        }//for
    }//DrawBlockOnBoard()

    /// @brief  check whether this Block can be located on the g_aCurBoard[] or not.
    bool CanLocateOnBoard() const {
        for (int iStone = 0; iStone < m_iNumStone; ++iStone) {
            KPoint worldPos = GetPos(iStone);
            char cellValue = 0;
            const bool bIsGetValue = GetBoardCellValue( OUT &cellValue, worldPos );
            if (bIsGetValue == false || cellValue != 0)
                return false;
        }//for
        return true;
    }//CanLocateOnBoard()
};//struct KBlock

KBlock      g_curBlock;
float       g_fCurBlockTimer = 0.f;
float       g_fCurBlockSpeed = 0.5f; ///< unit is seconds per a block

/// @param  x is the column, y is the row. The origin (0,0) is top-left.
void SetCursorPosition(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(g_hConsole, coord);
}//SetCursorPosition()

/// @brief  draw g_aBoard into the console Window.
void DrawBoard( BOARD_CELL_TYPE aBoard[BOARD_SIZE_ROW][BOARD_SIZE_COL] ) {
    for (int y = 0; y < BOARD_SIZE_ROW; ++y) {
        for (int x = 0; x < BOARD_SIZE_COL; ++x) {
            SetCursorPosition(x, y);
            printf("%c", aBoard[y][x]);
        }//for
    }//for
}//DrawBoard()

/// @brief onetime initialization works here.
void Initialize() {
    ::memset((char*)g_aBoard, 0, BOARD_SIZE_ROW * BOARD_SIZE_COL * sizeof(BOARD_CELL_TYPE));
    ::memset((char*)g_aCurBoard, 0, BOARD_SIZE_ROW * BOARD_SIZE_COL* sizeof(BOARD_CELL_TYPE));

    // Get the Win32 handle representing standard output.
    // This generally only has to be done once, so we make it static.
    g_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // test initialize a current block
    {
        g_curBlock.m_aBlockPosition[0].x = 0;
        g_curBlock.m_aBlockPosition[0].y = 0;
        g_curBlock.m_aBlockPosition[1].x = 1;
        g_curBlock.m_aBlockPosition[1].y = 0;
        g_curBlock.m_aBlockPosition[2].x = 0;
        g_curBlock.m_aBlockPosition[2].y = 1;
        g_curBlock.m_aBlockPosition[3].x = 0;
        g_curBlock.m_aBlockPosition[3].y = 2;
        g_curBlock.m_worldPos.x = 2;
        g_curBlock.m_worldPos.y = 2;
        g_curBlock.m_iNumStone = 4;
    }

    // save console cursor info.
    //
    ::GetConsoleCursorInfo(g_hConsole, &g_oldConsoleCursorInfo);
    CONSOLE_CURSOR_INFO consoleCursorInfo;
    consoleCursorInfo = g_oldConsoleCursorInfo;
    consoleCursorInfo.bVisible = false;
    SetConsoleCursorInfo(g_hConsole, &consoleCursorInfo);
}//Initialize()

/// @brief  onetime finalization works here.
void Finalize() {
    // restore console cursor info.
    SetConsoleCursorInfo(g_hConsole, &g_oldConsoleCursorInfo);
}//Finalize()

/// @brief  update game data per a frame.
void OnUpdate(float fElapsedTime_) {
    // save current block state.
    KBlock savedCurBlock;
    memcpy( &savedCurBlock, &g_curBlock, sizeof(KBlock));

    // process user keyboard inputs
    int ch = 0;
    if (_kbhit()) {
        ch = _getch();
        if (ch == KEY_ESC) {
            g_bIsExitGameLoop = true;
        }
        else if (ch == KEY_LEFT) {
            g_curBlock.m_worldPos.x -= 1;
            if (g_curBlock.CanLocateOnBoard() == false) {
                // restore current Block.
                memcpy(&g_curBlock, &savedCurBlock, sizeof(KBlock));
            }//if
        }
        else if (ch == KEY_RIGHT) {
            g_curBlock.m_worldPos.x += 1;
            if (g_curBlock.CanLocateOnBoard() == false) {
                // restore current Block.
                memcpy(&g_curBlock, &savedCurBlock, sizeof(KBlock));
            }//if
        }//if.. else if..
    }//if

    g_fCurBlockTimer += fElapsedTime_;
    if (g_fCurBlockTimer >= g_fCurBlockSpeed) {
        g_fCurBlockTimer -= g_fCurBlockSpeed; // reset current block timer
        g_curBlock.m_worldPos.y += 1;

        // draw game object on the Board
        if (g_curBlock.CanLocateOnBoard() == false) {
            // restore current Block.
            memcpy(&g_curBlock, &savedCurBlock, sizeof(KBlock));
            // finally locate current Block.
            g_curBlock.DrawBlockOnBoard(g_aCurBoard);

            // check whether removing a row is possible or not.
            int iNumOfRows = 0;
            int aRemoveRows[BOARD_SIZE_ROW];
            bool bIsRemovableRow = GetRemovableRowFromBoard(OUT &iNumOfRows, aRemoveRows);
            if (bIsRemovableRow == true) {
                RemoveRowFromBoard(iNumOfRows, aRemoveRows);
            }//if

            // test regenerate a Block.
            g_curBlock.m_worldPos.y = 2;
        }//if
    }//if
}//OnUpdate()

void OnDraw(float fElapsedTime_) {
    // prepare working Board with current(previous frame) board data.
    memcpy(g_aBoard, g_aCurBoard, sizeof(g_aBoard));

    g_curBlock.DrawBlockOnBoard( g_aBoard );

    DrawBoard( g_aBoard );
}//OnDraw()

void main() {
    Initialize();

    DWORD dwCurrTime = 0L;
    DWORD dwPrevTime = 0L;
    dwCurrTime = timeGetTime();
    dwPrevTime = dwCurrTime;

    // game loop
    while (g_bIsExitGameLoop == false) {
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
        ::OnUpdate(fElapsedTimeInSecond);
        OnDraw(fElapsedTimeInSecond);
    }//while

    Finalize();
}//main()
