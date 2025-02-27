#include <stdio.h>
#include <conio.h>
#include <windows.h>

int g_iplayerx = 1;
int g_iplayery = 1;
int g_iScore = 0;

void SetColor(WORD fore, WORD back)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	WORD attribute;
	attribute = (back & 0x0f) << 4 | (fore & 0x0f);
	SetConsoleTextAttribute(hConsole, attribute);

	/** predefined flags
		FOREGROUND_BLUE
		FOREGROUND_GREEN
		FOREGROUND_RED
		FOREGROUND_INTENSITY
		BACKGROUND_BLUE
		BACKGROUND_GREEN
		BACKGROUND_RED
		BACKGROUND_INTENSITY
		*/
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void GotoXy(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}//GotoXy()

void DrawPlayer(int x, int y)
{
	GotoXy(x, y);
	printf("P");
}

void DrawScore()
{
	GotoXy(11, 0);
	SetColor(15, 0);
	printf("Score : %i", g_iScore);
}

struct KBoard
{
private:
	int _beginx;
	int _beginy;
	const static int g_numRows = 10;
	const static int g_numCols = 10;
	int _board[g_numRows][g_numCols];
	int _boardLayer2[g_numRows][g_numCols];

	void _DrawBoard(int board[g_numRows][g_numCols], int layer)
	{
		for (int r = 0; r < g_numRows; ++r) {
			for (int c = 0; c < g_numCols; ++c) {
				GotoXy(c+_beginx, r+_beginy);
				if (board[r][c] == 0 && layer == 1)
					printf(".");
				else if (board[r][c] == 1)
					printf("#");
				else if (board[r][c] == 2)
					printf("N");
				else if (board[r][c] == 3)
					printf("O");
			}
		}
	}

public:
	void Initialize()
	{
		int board[g_numRows][g_numCols] = {
			{1,0,1,1,1,1,1,1,1,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,3,3,3,3,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,1,1,1,1,1,1,1,1,1},
		};
		int boardLayer2[g_numRows][g_numCols] = {
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,2,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,2,2,2,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
		};
		memcpy(_board, board, sizeof(board));
		memcpy(_boardLayer2, boardLayer2, sizeof(board));
	}

	void SetPos(int x, int y)
	{
		_beginx = x;
		_beginy = y;
	}

	void DrawBoard()
	{
		SetColor(15, 0);
		_DrawBoard(_board, 1);
		SetColor(13, 7);
		_DrawBoard(_boardLayer2, 2);
		SetColor(FOREGROUND_GREEN, 0);
	}

	void Update(int tx, int ty)
	{
		if (_boardLayer2[ty][tx] == 2)
		{
			int xoffset = tx - g_iplayerx;
			int yoffset = ty - g_iplayery;
			int xnew = tx + xoffset;
			int ynew = ty + yoffset;
			if ((_board[ynew][xnew] == 0 || _board[ynew][xnew] == 3)
				&& _boardLayer2[ynew][xnew] == 0)
			{
				_boardLayer2[ty][tx] = 0;
				_boardLayer2[ynew][xnew] = 2;
                if (_board[ynew][xnew] == 3 && _board[ty][tx] == 0)
                    g_iScore += 1;
                else if (_board[ynew][xnew] == 0 && _board[ty][tx] == 3)
                    g_iScore -= 1;
            }
		}
	}

	bool IsMovable(int tx, int ty)
	{
		return (_board[ty][tx] == 0 || _board[ty][tx] == 3) && _boardLayer2[ty][tx] == 0;
	}
};

void main()
{
	ShowConsoleCursor(false);

	KBoard board;
	board.Initialize();
	board.SetPos(10, 5);
	bool isScoreModified = true;

	while (true) {
		// draw scene
		board.DrawBoard();
		DrawPlayer(g_iplayerx, g_iplayery);
		DrawScore();

		int tx = g_iplayerx;
		int ty = g_iplayery;

		// get key input
		int ch = _getch();
		// update player position
		if (ch == 'a')
			tx = g_iplayerx - 1;
		else if (ch == 'd')
			tx = g_iplayerx + 1;
		else if (ch == 'w')
			ty = g_iplayery - 1;
		else if (ch == 's')
			ty = g_iplayery + 1;
		else if (ch == 27)
			break;

		board.Update( tx, ty );

		if( board.IsMovable(tx,ty)) {
			g_iplayerx = tx;
			g_iplayery = ty;
		}
	}
}
