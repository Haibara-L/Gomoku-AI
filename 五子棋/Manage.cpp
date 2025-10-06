#pragma comment(lib, "Winmm.lib")
#include<iostream>
#include<Windows.h>
#include<mmsystem.h>
using namespace std;
#include"ChessGame.h"

int main()
{
	Man man;
	AI ai;
	Chess chess(13,44,43,67.4);
	ChessGame game(&chess, &man, &ai);
	mciSendString("open audio/����.mp3 alias audio_chess", 0, 0, 0);
	mciSendString("open audio/ʤ��.mp3 alias audio_win", 0, 0, 0);
	mciSendString("open audio/ʧ��.mp3 alias audio_lose", 0, 0, 0);
	game.play();



	return 0;
}