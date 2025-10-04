#include "ChessGame.h"

ChessGame::ChessGame(Chess* chess, Man* man, AI* ai)
{
	this->chess = chess;
	this->ai = ai;
	this->man = man;
	this->ai->init(chess);
	this->man->init(chess);
}

void ChessGame::play()
{
	chess->initBoard();
	while (1)
	{
		man->go();
		if (chess->gameIsOver())
		{
			chess->initBoard();
			continue;
		}
		ai->go();
		if (chess->gameIsOver())
		{
			chess->initBoard();
			continue;
		}
	}
}
