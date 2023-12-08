#include <graphics.h>
#include<iostream>
using namespace std;
int Size;//可以自由选择地图的size
char current = 'O';//O先手X后手
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
	case 2:Size = 600;
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

bool CheckWin(char c)//检测X或O是否获胜
{
	if (a[0][0] == c && a[0][1] == c && a[0][2] == c) return true;
	if (a[1][0] == c && a[1][1] == c && a[1][2] == c) return true;
	if (a[2][0] == c && a[2][1] == c && a[2][2] == c) return true;
	if (a[0][2] == c && a[1][2] == c && a[2][2] == c) return true;
	if (a[0][1] == c && a[1][1] == c && a[2][1] == c) return true;
	if (a[0][0] == c && a[1][0] == c && a[2][0] == c) return true;
	if (a[0][0] == c && a[1][1] == c && a[2][2] == c) return true;
	if (a[0][2] == c && a[1][1] == c && a[2][0] == c) return true;
	return false;

}
bool CheckDraw()//检测平局
{
	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
			if (a[i][j] == '-') return false;
	if (CheckWin(current) == false) return true;
}
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
void DrawPiece()//画棋子
{
	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
		{
			int x2 = j * Size/3 + Size/6;//当前棋盘格子中心的坐标
			int y2 = i * Size/3 + Size/6;
			if (a[i][j] == 'O')
			{
				circle(x2, y2, Size/6);//画O
			}
			else if (a[i][j] == 'X')
			{
				line(x2 - Size/6,y2 - Size/6, x2 + Size/6, y2 + Size/6);//画X
				line(x2 + Size/6, y2 - Size/6, x2 - Size/6, y2 + Size/6);

			}
		}
}

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
				int x1 = x / (Size/3);//除法向下取整，棋盘三等分
				int y1 = y / (Size/3);
				if (a[y1][x1] == '-')//注意是a（y，x），很容易搞错！！！
				{
					a[y1][x1] = current;//鼠标下子，先O后X
					if (current == 'O') current = 'X';
					else if (current == 'X') current = 'O';
				}
			}
		}

		if (CheckWin('X'))
		{
			End = true;
			//cout << "X玩家获胜" << endl;//弹出玩家获胜信息
			MessageBox(GetHWnd(), _T("X玩家获胜"), _T("游戏结束"), MB_OK);
		}//我们也可以使用easyx带的Messagebox函数，弹出对话框
		if (CheckWin('O'))
		{
			End = true;
			//cout << "O玩家获胜" << endl;
		}
		if (CheckDraw())
		{
			End = true;
			//cout << "平局" << endl;
		}
		cleardevice();
		DrawBoard();
		DrawPiece();
		FlushBatchDraw();
	}

	EndBatchDraw();
	return 0;
}