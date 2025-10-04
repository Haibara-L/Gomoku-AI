#pragma once
#include<iostream>
#include<vector>
#include"Chess.h"
using namespace std;
class AI
{
public:
	void init(Chess* chess);
	void go();
	
private:
	vector<vector<int>> chessMapScore;
	Chess* chess;
	void addScore(vector<vector<int>> v);
};

