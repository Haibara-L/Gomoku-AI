#include "AI.h"

void AI::init(Chess* chess)
{
	this->chess = chess;
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

}

void AI::addScore(vector<vector<int>> v)
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
			int manNum = 0;
			int botNum = 0;
			int emptyNum = 0;
			if (chess->getChessType(i, j) != 0)
			{

			}
		}
	}
}
