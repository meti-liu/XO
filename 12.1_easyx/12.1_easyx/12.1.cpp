#include <graphics.h>
#include<iostream>
using namespace std;
int Size;//可以自由选择地图的size

void mapsize()
{
	cout << "choose ur map size" << endl
		<< "1:small" << endl
		<< "2:medium" << endl
		<< "3:large" << endl;
	int k1;
	cin >> k1;
	switch (k1)
	{
	case 1:Size = 300;
		break;
	case 2:Size = 500;
		break;
	case 3:Size = 700;
		break;
	}
}
char a[3][3] =
{
	{'-','-','-'},
	{'-','-','-'},
	{'-','-','-'},

};

/*bool CheckWin(char c)//检测是否获胜
{

}
bool CheckDraw()//检测平局
{

}*/
void DrawBoard()//画棋盘
{
	line(0, 0, 0, Size);//画直线x1,y1,x2,y2
	line(Size/3, 0, Size / 3,Size);
	line(Size*2/3, 0, Size*2/3, Size);
	line(Size, 0, Size, Size);
	line(0, 0, Size, 0);
	line(0, Size / 3, Size, Size / 3);
	line(0, Size*2/3, Size, Size*2/3);
	line(0, Size, Size, Size);
}
/*void DrawPiece()//画棋子
{

}*/

int main()
{
	mapsize();
	initgraph(Size, Size);
	bool End = false;
	ExMessage msg;

	BeginBatchDraw();//渲染缓冲区三连

	while (!End)//没有结束信号就继续循环
	{

		while (peekmessage(&msg))
		{
			if (msg.message == WM_LBUTTONDOWN)//记录鼠标左键按下
			{
				int x = msg.x;
				int y = msg.y;
				int x1 = x / Size/3;
				int y1 = y / Size/3;
			}
		}

		/*if (CheckWin('X'))
		{
			//MessageBox()
			
		}*/


		cleardevice();
		//CheckWin();
		//CheckDraw();
		DrawBoard();
		//DrawPiece();
		FlushBatchDraw();
	}

	EndBatchDraw();
	return 0;
}