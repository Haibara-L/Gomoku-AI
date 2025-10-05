#include "AI.h"

void AI::init(Chess* chess)
{
	this->chess = chess;
	/*bool flag = false;*/
	/*this->chess->setPlayerFlag(flag);*/
	srand((unsigned int)time(NULL));
	for (int i = 0; i < chess->getBoardGrade(); i++)
	{
		vector<int>v;
		for (int j = 0; j < chess->getBoardGrade(); j++)
		{
			v.push_back(0);
		}
		chessMapScore.push_back(v);
	}
}
void AI::go()
{
	ChessPos pos = think();
	Sleep(1000);
	chess->chessDown(&pos, WHITE_CHESS);
}

ChessPos AI::think()
{
	addScore();
	vector<ChessPos> idealPos;
	int size = chess->getBoardGrade();
	int maxScore=0;
	ChessPos pos;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (chessMapScore[i][j] > maxScore)
			{
				maxScore = chessMapScore[i][j];
				idealPos.clear();
				pos.row = i;
				pos.col = j;
				idealPos.push_back(pos);
			}
			else if (chessMapScore[i][j] == maxScore)
			{
				pos.row = i;
				pos.col = j;
				idealPos.push_back(pos);
			}
		}
	}
	if (idealPos.empty())
	{
		pos.row = size / 2;
		pos.col = size / 2;
		return pos;
	}
	int index = rand() % idealPos.size();
	return idealPos[index];
}

void AI::addScore()
{
	int size = chess->getBoardGrade();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			chessMapScore[i][j] = 0;
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (chess->getChessType(i, j) == 0)
			{
				for (int dx = -1; dx <= 1; dx++)
				{
					for (int dy = -1; dy <= 0; dy++)
					{
						int manNum = 0;
						int botNum = 0;
						int emptyNum = 0;
						if (dx != 1 && dy == 0)
						{
							continue;
						}
						for (int k = 1; k <= 4; k++)
						{
							int x = i + k * dx;
							int y = j + k * dy;
							if (x >= 0 && x < size && y >= 0 && y < size)
							{
								if (chess->getChessType(x, y) == 1)
								{
									manNum++;
								}
								else if (chess->getChessType(x, y) == 0)
								{
									emptyNum++;
									break;
								}
								else
								{
									break;
								}
							}
						}
						for (int k = 1; k <= 4; k++)
						{
							int x = i - k * dx;
							int y = j - k * dy;
							if (x >= 0 && x < size && y >= 0 && y < size)
							{
								if (chess->getChessType(x, y) == 1)
								{
									manNum++;
								}
								else if (chess->getChessType(x, y) == 0)
								{
									emptyNum++;
									break;
								}
								else
								{
									break;
								}
							}
						}
						switch (manNum)
						{
						case 1:
							chessMapScore[i][j] += 10;
							break;
						case 2:
							if (emptyNum == 2)
							{
								chessMapScore[i][j] += 40;
							}
							else if (emptyNum == 1)
							{
								chessMapScore[i][j] += 30;
							}
							break;
						case 3:
							if (emptyNum == 2)
							{
								chessMapScore[i][j] += 1000;
							}
							else if (emptyNum == 1)
							{
								chessMapScore[i][j] += 60;
							}
							break;
						case 4:
							chessMapScore[i][j] += 20000;
							break;
						default:
							break;
						}
						manNum = 0;
						botNum = 0;
						emptyNum = 0;
						for (int k = 1; k <= 4; k++)
						{
							int x = i + k * dx;
							int y = j + k * dy;
							if (x >= 0 && x < size && y >= 0 && y < size)
							{
								if (chess->getChessType(x, y) == -1)
								{
									botNum++;
								}
								else if (chess->getChessType(x, y) == 0)
								{
									emptyNum++;
									break;
								}
								else
								{
									break;
								}
							}
						}
						for (int k = 1; k <= 4; k++)
						{
							int x = i - k * dx;
							int y = j - k * dy;
							if (x >= 0 && x < size && y >= 0 && y < size)
							{
								if (chess->getChessType(x, y) == -1)
								{
									botNum++;
								}
								else if (chess->getChessType(x, y) == 0)
								{
									emptyNum++;
									break;
								}
								else
								{
									break;
								}
							}
						}
						switch (botNum)
						{
						case 0:
							chessMapScore[i][j] += 5;
							break;
						case 1:
							chessMapScore[i][j] += 10;
							break;
						case 2:
							if (emptyNum == 2)
							{
								chessMapScore[i][j] += 50;
							}
							else if (emptyNum == 1)
							{
								chessMapScore[i][j] += 25;
							}
							break;
						case 3:
							if (emptyNum == 2)
							{
								chessMapScore[i][j] += 10000;
							}
							else if (emptyNum == 1)
							{
								chessMapScore[i][j] += 55;
							}
							break;
						case 4:
							chessMapScore[i][j] += 30000;
							break;
						default:
							break;
						}
					}
				}
			}
		}
	}
}

