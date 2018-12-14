#include"util.h"
using namespace std;

void init()//설정
{
	system("mode con cols=112 lines=40 | title 게임제목");
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);//콘솔 핸들 가져옴
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;//숨기기
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);//위치 설정
}

void gotoxy(int x, int y)//플레이어 위치 이동 함수
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);//콘솔 핸들 가져옴
	COORD pos;
	pos.X = x;//위치 값 대입
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);//위치 설정
}

void setColor(int forground, int background)//색 설정
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}
