#pragma once
#include<iostream>
#include"Chess.h"
#include"AI.h"
#include"Man.h"
using namespace std;

class ChessGame
{
public:
	ChessGame(Chess* chess, Man* man, AI* ai);
	void play();
private:
	Chess* chess;
	Man* man;
	AI* ai;

};

