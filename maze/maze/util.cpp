#include"util.h"
using namespace std;

void init()//����
{
	system("mode con cols=112 lines=40 | title ��������");
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);//�ܼ� �ڵ� ������
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;//�����
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);//��ġ ����
}

void gotoxy(int x, int y)//�÷��̾� ��ġ �̵� �Լ�
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);//�ܼ� �ڵ� ������
	COORD pos;
	pos.X = x;//��ġ �� ����
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);//��ġ ����
}

void setColor(int forground, int background)//�� ����
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}
