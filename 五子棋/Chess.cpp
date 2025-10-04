#include "Chess.h"

Chess::Chess(int boardsize, float marginX, float marginY, float chesssize)
{
	this->boardSize = boardsize;
	this->chessSize = chesssize;
	this->margin_x = marginX;
	this->margin_y = marginY;
	this->playerFlag = BLACK;
	for (int i = 0; i < boardSize; i++)
	{
		vector<int> v;
		for (int j = 0; j < boardSize; j++)
		{
			v.push_back(0);
		}
		chessMap.push_back(v);
	}
}

void Chess::initBoard()
{
	initgraph(897, 895);
	loadimage(0, "image/board13.png",897,895);
	loadimage(&imageBlackChess, "image/black.png", chessSize, chessSize);
	loadimage(&imageWhiteChess, "image/white.png", chessSize, chessSize);
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < chessMap[i].size(); j++)
		{
			chessMap[i][j] = 0;
		}
	}
	playerFlag = true;

}

void Chess::chessDown(ChessPos* pos, chessType type)
{
}

bool Chess::clickBoard(int x, int y, ChessPos* pos)
{
	return false;
}

int Chess::getBoardGrade()
{
	return 0;
}

bool Chess::gameIsOver()
{
	return false;
}

int Chess::getChessType(int row, int column)
{
	return 0;
}

int Chess::getChessTyep(ChessPos* pos)
{
	return 0;
}

