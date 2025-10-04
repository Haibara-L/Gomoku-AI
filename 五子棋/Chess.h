#pragma once
#include <iostream>
#include<vector>
#include<graphics.h>
using namespace std;

struct ChessPos
{
	int row;
	int col;
};
typedef enum
{
	WHITE_CHESS = -1,
	BLACK_CHESS=1
}chessType;
class Chess
{
public:
	Chess(int boardsize, float marginX, float marginY, float chessSize);
	void initBoard();
	void chessDown(ChessPos *pos,chessType type);
	bool clickBoard(int x, int y, ChessPos* pos);
	int getBoardGrade();
	bool gameIsOver();
	int getChessType(int row, int column);
	int getChessType(ChessPos* pos);


private:
	int boardSize;
	float margin_x;
	float margin_y;
	float chessSize;
	bool playerFlag;
	vector<vector<int>>chessMap;
	IMAGE imageWhiteChess;
	IMAGE imageBlackChess;
	void upgradeBoardIf(ChessPos* pos);
};

