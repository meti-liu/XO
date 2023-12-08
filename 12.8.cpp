#include <graphics.h>
#include<iostream>
using namespace std;
int Size;//��������ѡ���ͼ��size
char current = 'O';//O����X����
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

bool CheckWin(char c)//���X��O�Ƿ��ʤ
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
bool CheckDraw()//���ƽ��
{
	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
			if (a[i][j] == '-') return false;
	if (CheckWin(current) == false) return true;
}
void DrawBoard()//������
{
	line(0, 0, 0, Size);//��ֱ��x1,y1,x2,y2
	line(Size/3, 0, Size / 3,Size);
	line(Size*2/3, 0, Size*2/3, Size);
	line(Size, 0, Size, Size);
	line(0, 0, Size, 0);
	line(0, Size / 3, Size, Size / 3);
	line(0, Size*2/3, Size, Size*2/3);
	line(0, Size, Size, Size);
}
void DrawPiece()//������
{
	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
		{
			int x2 = j * Size/3 + Size/6;//��ǰ���̸������ĵ�����
			int y2 = i * Size/3 + Size/6;
			if (a[i][j] == 'O')
			{
				circle(x2, y2, Size/6);//��O
			}
			else if (a[i][j] == 'X')
			{
				line(x2 - Size/6,y2 - Size/6, x2 + Size/6, y2 + Size/6);//��X
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

	BeginBatchDraw();//��Ⱦ����������

	while (!End)//û�н����źžͼ���ѭ��
	{

		while (peekmessage(&msg))
		{
			if (msg.message == WM_LBUTTONDOWN)//��¼����������
			{
				int x = msg.x;
				int y = msg.y;
				int x1 = x / (Size/3);//��������ȡ�����������ȷ�
				int y1 = y / (Size/3);
				if (a[y1][x1] == '-')//ע����a��y��x���������׸������
				{
					a[y1][x1] = current;//������ӣ���O��X
					if (current == 'O') current = 'X';
					else if (current == 'X') current = 'O';
				}
			}
		}

		if (CheckWin('X'))
		{
			End = true;
			//cout << "X��һ�ʤ" << endl;//������һ�ʤ��Ϣ
			MessageBox(GetHWnd(), _T("X��һ�ʤ"), _T("��Ϸ����"), MB_OK);
		}//����Ҳ����ʹ��easyx����Messagebox�����������Ի���
		if (CheckWin('O'))
		{
			End = true;
			//cout << "O��һ�ʤ" << endl;
		}
		if (CheckDraw())
		{
			End = true;
			//cout << "ƽ��" << endl;
		}
		cleardevice();
		DrawBoard();
		DrawPiece();
		FlushBatchDraw();
	}

	EndBatchDraw();
	return 0;
}