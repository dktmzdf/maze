#include"game.h"
using namespace std;

constexpr auto MapY = 34;
constexpr auto MapX = 112;

char tempMap[MapY * MapX]; // 맵 임시저장할 배열  

char map1[MapY][MapX] = { // 튜토리얼맵  
	// 가로 숫자는 위 배열크기에 맞추어 112개  
	{"1111111111111111111111111111111111111111111111111111111"}, // 세로 길이에 맞추어 34줄   
	{"1000000010000000000000001000000000001000000000000000001"},
	{"1000000010000000000000001011111111101000000000000000001"}, // 0 : 빈 공간 
	{"1000100010000000000000001010000000001000000000000000001"}, // 1 : 벽 
	{"1000100010000000000000001010111111111000000000000000001"}, // k : 열쇠 
	{"1000100010000000000000001010111111111000000000000000001"}, // l : 잠긴 문 
	{"1000100011111100000000001010000000001000000000000000001"}, // q : 탈출구  
	{"1000100000000100000000001011111111101000000000000000001"},
	{"1000100010000100000000001010000000001000000000000000001"},
	{"10001000100k0100000000001010111111111000000000001111111"},
	{"1000100010000100000000001010000000001000000000001000001"},
	{"10s010001111111111111111101111111110111111111111100q001"},
	{"10001000l0000000000000000010000000000000000000000000001"},
	{"1111111111111111111111111111111111111111111111111111111"}
};

char map2[MapY][MapX] = { // 쉬운맵  
	// 가로 숫자는 위 배열크기에 맞추어 MapY개  
	{"1111111111111111111111111111111111111111111111111111111"}, // 세로 길이에 맞추어 MapX줄   
	{"100000100010001k000100000000001000100000100010100010001"},
	{"1000001010101011110101111101101010101110101010101000101"},
	{"1000101010001000k10101000101k01010101k10101000111111101"},
	{"1000100010111111110101010101111000100010101111100000001"},
	{"100011111l100000000101010100000001110110101000101011111"},
	{"1000100000101111111101010111011100000010001010001010001"},
	{"1000101111101000000001010000000111011010100010100010001"},
	{"10001010000010000001010110111100000000101010101010001l1"},
	{"10001010111010000001000000000101011110101010101011111l1"},
	{"100010101k001000000111101111000100001010101010001000001"},
	{"10s010101111111110110010100001011110100010111110100q001"},
	{"1000100000l000l0001000100011110000001010100000001000001"},
	{"1111111111111111111111111111111111111111111111111111111"}
};
char map3[MapY][MapX] = { // 쉬운맵
  {"11111111111111111111"},
  {"1s10l000110000010001"},
  {"101010100001l10101k1"},
  {"101l1k11111101110111"},
  {"10101111000100000001"},
  {"101001000111101111l1"},
  {"1010111101k010100101"},
  {"10100001011010101101"},
  {"10101100001010100001"},
  {"10111111101010101111"},
  {"1010000000101k100001"},
  {"101111011110111101l1"},
  {"101k1000000010111101"},
  {"101010111101101001q1"},
  {"10001010010100001111"},
  {"10101110110101101101"},
  {"10101000010000101001"},
  {"10111110111110101011"},
  {"10001000100010101011"},
  {"10100010001000100011"},
  {"11111111111111111111"}



};


char map4[MapY][MapX] = {
{"11111111111111111"},
{"1s100k10000111111"},
{"10l00110110001111"},
{"1k110000111000111"},
{"11101111k11l11001"},
{"11100001011011111"},
{"1k111011001011011"},
{"10111011101011011"},
{"10111000001011111"},
{"1010001101100ll01"},
{"10l01111000011101"},
{"1k1001111101111q1"},
{"11111111111111111"}
};




void titleDraw()//제목 그리기
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "                                    #####    ###    ###    #    ####   ##### \n";
	cout << "                                    #       #      #      # #   #   #  #     \n";
	cout << "                                    ####    ####   #     #####  ####   ####  \n";
	cout << "                                    #           #  #     #   #  #      #     \n";
	cout << "                                    #####   ####    ###  #   #  #      ##### \n";
}

void infoDraw()
{
	system("cls");
	cout << "\n\n\n\n";
	cout << "                    [조작법]\n\n";
	cout << "                  이동 : W, A, S, D\n";
	cout << "                선택 : 스 페 이 스 바\n\n";
	cout << "       출처 : http://codevkr.tistory.com/16?category=699626\n\n";
	cout << "     스 페 이 스 바 를  누 르 면  메 인 화 면 으 로  이 동 합 니 다\n\n";
	while (1)
		if (keyControl() == SUBMIT) break;
}




int keyControl()
{
	char temp = getch();//getch 함수는 입력한 키의 아스키 코드를 
						//엔터없이 바로 입력됨


	//입력한 키를 의미있는 값으로 바꾸어 리턴해줌
	if (temp == 'w' || temp == 'W') return UP;
	else if (temp == 'a' || temp == 'A') return LEFT;
	else if (temp == 's' || temp == 'S') return DOWN;
	else if (temp == 'd' || temp == 'D') return RIGHT;
	else if (temp == ' ') return SUBMIT;
}

int menuDraw()
{
	int x = 52;
	int y = 24;//-2한 이유는 > 출력하기 위해
	gotoxy(x - 2, y);
	cout << "> 게임시작 ";
	gotoxy(x, y + 1);
	cout << "게임정보";
	gotoxy(x, y + 2);
	cout << " 종료 ";
	while (1)//무한 루프 실행
	{
		int n = keyControl();
		switch (n)
		{
		case UP:
			if (y > 24) {//y는 12에서 MapX까지만 움직이게 함
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << ">";

			}
			break;
		case DOWN:
			if (y < 26) {//y는 12에서 MapX까지만 움직이게 함
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";

			}
			break;
		case SUBMIT:
			return y - 24;//숫자를 반환하여 진행시킴
		default:
			break;
		}
	}

}

int mapListDraw()
{
	int x = 52;
	int y = 12;
	system("cls");
	cout << "\n\n";
	gotoxy(x - 2, y);
	cout << "> 튜 토 리 얼";
	gotoxy(x, y + 1);
	cout << "미 로 1 ";
	gotoxy(x, y + 2);
	cout << "미 로 2 ";
	gotoxy(x, y + 3);
	cout << "미 로 3 ";
	gotoxy(x, y + 4);
	cout << "랜 덤 맵 ";
	gotoxy(x, y + 5);
	cout << "뒤 로 ";
	while (1) 
	{
		int n = keyControl();
		switch (n)
		{
		case UP:
			if (y > 12) {//y는 12에서 18까지만 움직이게 함
				
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << ">";

			}
			break;
		case DOWN:
			if (y < 18) {//y는 12에서 18까지만 움직이게 함
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";

			}
			break;
		case SUBMIT:
			return y - 12;//숫자를 반환하여 진행시킴
		default:
			break;
		}
	}

}

void drawMap(int *x, int *y)
{
	system("cls");
	int w, h;//가로 세로

	for (h = 0; h < MapY; h++) //세로길이까지
	{
		char temp;
		for (w = 0; w < MapX; w++) //가로 길이까지
		{

			 temp = tempMap[h * MapX + w];
			 switch (temp)
			 {
			 case '0'://빈공간
				 setColor(black, black);
				 cout << " ";
				 break;
			 case '1'://벽
				 setColor(white, white);
				 cout << "#";
				 break;
			 case 's'://플레이어
				 setColor(cyan, black);
				 *x = w;
				 *y = h;
				 cout << "@";
				 break;
			 case 'q'://목적지
				 setColor(lightgreen, black);
				 cout << "O";
				 break;
			 case 'k':
				 setColor(yellow, black);
				 cout << "K";
				 break;
			 case 'l':
				 setColor(brown, black);
				 cout << "+";
				 break;
			 default:
				 break;
			 }
		}
		cout << endl;
	}
	setColor(white, black);
	//Sleep(5000);



}

void drawUI(int *x, int *y, int *key)
{
	setColor(white, black);
	gotoxy(3, 36);
	cout << "위치 : " << *x << ", " <<  *y;

	setColor(yellow, black);
	gotoxy(34,36);
	cout << "열쇠 : "  <<*key<< "개";
}

void gLoop(int mapCode)
{
	int x, y;
	int key = 0;
	int playing = 1;//1 이면 게임중 0이면 게임 종료

	//mapcode의 값으로 맵결정
	for(int i =0; i < sizeof(tempMap) / sizeof(*tempMap); i++) tempMap[i] = ' ';
	if (mapCode == 0)inputMap(tempMap, map1);
	else if(mapCode == 1)inputMap(tempMap, map2);
	else if (mapCode == 2)inputMap(tempMap, map3);
	else if (mapCode == 3)inputMap(tempMap, map4);
	else if (mapCode == 4)PMG();
	

	drawMap(&x, &y);// 맵 성정후ㅠ 출력

	//게임 루프
	while (playing != 0 && playing != 3)
	{
		drawUI(&x, &y, &key);
		switch (keyControl())
		{
		case UP:
			move(&x, &y, 0, -1, &key, &playing);//y를 -1해서 위쪽으로감
			break;
		case DOWN:
			move(&x, &y, 0, 1, &key, &playing);////y를 +1해서 아래쪽으로감
			break;
		case LEFT:
			move(&x, &y, -1, 0, &key, &playing);//x를 -1해서 왼쪽으로감
			break;
		case RIGHT:
			move(&x, &y, 1, 0, &key, &playing);//x를 +1해서 오른쪽으로감
			break;
		case SUBMIT:
			playing = 3;//스페이스바 누르면 종료
		
		}
	}
	
	setColor(white, black);

	gotoxy(22,8);
	if (playing ==3 ) {
		cout << "Game Over";
	}
	else if (playing == 0)
	{
		cout << "Game Clear!";
	}
	Sleep(2000);

}

void move(int *x, int *y, int _x, int _y, int *key, int *playing)
{
	char mapObject = tempMap[(*y + _y) * MapX + *x + _x];
	setColor(white, black);//색 기본값
	switch (mapObject)
	{
	case 'k':
		*key += 1;//키 갯수 증가
		tempMap[(*y + _y) * MapX + _x] = '0';//맵에 있던 키가 지워짐
		gotoxy(*x + _x, *y + _y);
		cout << " ";
		break;
	case 'q'://목적지
		*playing = 0;
	case '0'://빈공간이기 때문에 이동함
		gotoxy(*x, *y);
		cout << " ";

		setColor(cyan, black);
		gotoxy(*x + _x, *y + _y);
		cout << "@";

		*x += _x;
		*y += _y;
		break;
	case '1'://벽
		break;
	
	
	case 'l':
		if (*key >= 1) {
			*key -= 1;//키 한개를 사용
			tempMap[(*y + _y) * MapX + _x] = '0';//문이 열렸으므로 문을 닫음
			setColor(white, black);//색 기본값
			gotoxy(*x + _x, *y + _y);

			cout << " ";
		}
		
		break;
	default:
		break;
	}
	
}


void PMG()
{
	
	//< 1단계. 시드 설정
	random_device rn;
	mt19937_64 rnd(rn());

	//< 2단계. 분포 설정 ( 정수 )
	uniform_int_distribution<int> rangeX(51, MapX-1);
	int x, y;
	x = rangeX(rnd);
	uniform_int_distribution<int> rangeY(7, MapY-1);
	y = rangeY(rnd);

	//구현할때 홀수가 아니면 구현이 안됨
	if (x % 2 == 0) x++;
	if (y % 2 == 0) y++;

	Maze maze(x, y);

	maze.SetMazeUp();//맵 세팅
	maze.generator(tempMap, MapX);//tempMap에 맵 넣기
	tempMap[((y-3) * MapX) + x-2] = 'q';//탈출구 넣기

}

void inputMap(char *Dest,char source[MapY][MapX])
{
	int i, j;

	for (i = 0; i < MapX; i++)
	{
		for (j = 0; j < MapY; j++)
		{
			Dest[j * MapX + i] = source[j][i];
		}
	}

}