#include "Chess.h"

Chess::Chess(int boardsize, float marginX, float marginY, float chesssize)
{
	this->boardSize = boardsize;
	this->chessSize = chesssize;
	this->margin_x = marginX;
	this->margin_y = marginY;
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

void putimagePNG(int x, int y, IMAGE* picture) //xΪ����ͼƬ��X���꣬yΪY����
{
	// ������ʼ��
	DWORD* dst = GetImageBuffer();    // GetImageBuffer()���������ڻ�ȡ��ͼ�豸���Դ�ָ�룬EASYX�Դ�
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(picture); //��ȡpicture���Դ�ָ��
	int picture_width = picture->getwidth(); //��ȡpicture�Ŀ�ȣ�EASYX�Դ�
	int picture_height = picture->getheight(); //��ȡpicture�ĸ߶ȣ�EASYX�Դ�
	int graphWidth = getwidth();       //��ȡ��ͼ���Ŀ�ȣ�EASYX�Դ�
	int graphHeight = getheight();     //��ȡ��ͼ���ĸ߶ȣ�EASYX�Դ�
	int dstX = 0;    //���Դ������صĽǱ�

	// ʵ��͸����ͼ ��ʽ�� Cp=��p*FP+(1-��p)*BP �� ��Ҷ˹���������е���ɫ�ĸ��ʼ���
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width; //���Դ������صĽǱ�
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA��͸����
			int sr = ((src[srcX] & 0xff0000) >> 16); //��ȡRGB���R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + x) + (iy + y) * graphWidth; //���Դ������صĽǱ�
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //��ʽ�� Cp=��p*FP+(1-��p)*BP  �� ��p=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //��p=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //��p=sa/255 , FP=sb , BP=db
			}
		}
	}
}
void Chess::chessDown(ChessPos* pos, chessType type)
{
	float x = (pos->row) * chessSize + margin_x - chessSize / 2;
	float y = (pos->col) * chessSize + margin_y - chessSize / 2;
	if (type == BLACK_CHESS)
	{
		putimagePNG(x, y, &imageBlackChess);
	}
	else
	{
		putimagePNG(x, y, &imageWhiteChess);
	}
	upgradeBoardIf(pos);
}

bool Chess::clickBoard(int x, int y, ChessPos* pos)
{
	int crdx = (x - margin_x) / chessSize;
	int crdy = (y - margin_y) / chessSize;
	float lenx = margin_x + chessSize * crdx;
	float leny = margin_y + chessSize * crdy;
	float dis = 0.4 * chessSize;
	bool isLegal = false;
	do
	{
		if (sqrt((x - lenx) * (x - lenx) + (y - leny) * (y - leny)) < dis)
		{
			pos->row = crdx;
			pos->col = crdy;
			if (chessMap[crdx][crdy] == 0)
			{
				isLegal = true;
			}
			break;
		}
		if (sqrt((x - lenx-chessSize) * (x - lenx-chessSize) + (y - leny) * (y - leny)) < dis)
		{
			pos->row = crdx+1;
			pos->col = crdy;
			if (chessMap[crdx+1][crdy] == 0)
			{
				isLegal = true;
			}
			break;
		}
		if (sqrt((x - lenx) * (x - lenx) + (y - leny-chessSize) * (y - leny-chessSize)) < dis)
		{
			pos->row = crdx;
			pos->col = crdy+1;
			if (chessMap[crdx][crdy+1] == 0)
			{
				isLegal = true;
			}
			break;
		}
		if (sqrt((x - lenx-chessSize) * (x - lenx-chessSize) + (y - leny-chessSize) * (y - leny-chessSize)) < dis)
		{
			pos->row = crdx+1;
			pos->col = crdy+1;
			if (chessMap[crdx+1][crdy+1] == 0)
			{
				isLegal = true;
			}
			break;
		}
	} while (0);
	return isLegal;
}

int Chess::getBoardGrade()
{
	return boardSize;
}

bool Chess::gameIsOver()
{
	return false;
}

int Chess::getChessType(int row, int column)
{
	return chessMap[row][column];
}

int Chess::getChessType(ChessPos* pos)
{
	return chessMap[pos->row][pos->col];
}

//void Chess::setPlayerFlag(bool player)
//{
//	playerFlag = player;
//}

void Chess::upgradeBoardIf(ChessPos* pos)
{
	chessMap[pos->row][pos->col] = playerFlag?1:-1;
	playerFlag = !playerFlag;
}

