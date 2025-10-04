#include<iostream>
using namespace std;
#include"ChessGame.h"

int main()
{
	Man man;
	AI ai;
	Chess chess(13,44,43,67.4);
	ChessGame game(&chess, &man, &ai);
	game.play();



	return 0;
}