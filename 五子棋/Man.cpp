#include "Man.h"

void Man::init(Chess* chess)
{
	this->chess = chess;
	/*bool flag = true;
	this->chess->setPlayerFlag(flag);*/
}

void Man::go()
{
	ExMessage msg;
	ChessPos pos;
	while (1)
	{
		if (peekmessage(&msg, EX_MOUSE));
		{
			if (msg.message == WM_LBUTTONDOWN && chess->clickBoard(msg.x, msg.y, &pos))
			{
				break;
			}
		}
	}
	chess->chessDown(&pos, BLACK_CHESS);
}
