#pragma once
#include<iostream>
#include<vector>
#include"Chess.h"
#include<ctime>
using namespace std;
class AI
{
public:
	void init(Chess* chess);
	void go();
	ChessPos think();
	
private:
	vector<vector<int>> chessMapScore;
	Chess* chess;
	void addScore();
};

