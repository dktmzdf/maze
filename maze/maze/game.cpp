#include"game.h"
using namespace std;

constexpr auto MapY = 34;
constexpr auto MapX = 112;

char tempMap[MapY * MapX]; // �� �ӽ������� �迭  

char map1[MapY][MapX] = { // Ʃ�丮���  
	// ���� ���ڴ� �� �迭ũ�⿡ ���߾� 112��  
	{"1111111111111111111111111111111111111111111111111111111"}, // ���� ���̿� ���߾� 34��   
	{"1000000010000000000000001000000000001000000000000000001"},
	{"1000000010000000000000001011111111101000000000000000001"}, // 0 : �� ���� 
	{"1000100010000000000000001010000000001000000000000000001"}, // 1 : �� 
	{"1000100010000000000000001010111111111000000000000000001"}, // k : ���� 
	{"1000100010000000000000001010111111111000000000000000001"}, // l : ��� �� 
	{"1000100011111100000000001010000000001000000000000000001"}, // q : Ż�ⱸ  
	{"1000100000000100000000001011111111101000000000000000001"},
	{"1000100010000100000000001010000000001000000000000000001"},
	{"10001000100k0100000000001010111111111000000000001111111"},
	{"1000100010000100000000001010000000001000000000001000001"},
	{"10s010001111111111111111101111111110111111111111100q001"},
	{"10001000l0000000000000000010000000000000000000000000001"},
	{"1111111111111111111111111111111111111111111111111111111"}
};

char map2[MapY][MapX] = { // �����  
	// ���� ���ڴ� �� �迭ũ�⿡ ���߾� MapY��  
	{"1111111111111111111111111111111111111111111111111111111"}, // ���� ���̿� ���߾� MapX��   
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
char map3[MapY][MapX] = { // �����
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




void titleDraw()//���� �׸���
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
	cout << "                    [���۹�]\n\n";
	cout << "                  �̵� : W, A, S, D\n";
	cout << "                ���� : �� �� �� �� ��\n\n";
	cout << "       ��ó : http://codevkr.tistory.com/16?category=699626\n\n";
	cout << "     �� �� �� �� �� ��  �� �� ��  �� �� ȭ �� �� ��  �� �� �� �� ��\n\n";
	while (1)
		if (keyControl() == SUBMIT) break;
}




int keyControl()
{
	char temp = getch();//getch �Լ��� �Է��� Ű�� �ƽ�Ű �ڵ带 
						//���;��� �ٷ� �Էµ�


	//�Է��� Ű�� �ǹ��ִ� ������ �ٲپ� ��������
	if (temp == 'w' || temp == 'W') return UP;
	else if (temp == 'a' || temp == 'A') return LEFT;
	else if (temp == 's' || temp == 'S') return DOWN;
	else if (temp == 'd' || temp == 'D') return RIGHT;
	else if (temp == ' ') return SUBMIT;
}

int menuDraw()
{
	int x = 52;
	int y = 24;//-2�� ������ > ����ϱ� ����
	gotoxy(x - 2, y);
	cout << "> ���ӽ��� ";
	gotoxy(x, y + 1);
	cout << "��������";
	gotoxy(x, y + 2);
	cout << " ���� ";
	while (1)//���� ���� ����
	{
		int n = keyControl();
		switch (n)
		{
		case UP:
			if (y > 24) {//y�� 12���� MapX������ �����̰� ��
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << ">";

			}
			break;
		case DOWN:
			if (y < 26) {//y�� 12���� MapX������ �����̰� ��
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";

			}
			break;
		case SUBMIT:
			return y - 24;//���ڸ� ��ȯ�Ͽ� �����Ŵ
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
	cout << "> Ʃ �� �� ��";
	gotoxy(x, y + 1);
	cout << "�� �� 1 ";
	gotoxy(x, y + 2);
	cout << "�� �� 2 ";
	gotoxy(x, y + 3);
	cout << "�� �� 3 ";
	gotoxy(x, y + 4);
	cout << "�� �� �� ";
	gotoxy(x, y + 5);
	cout << "�� �� ";
	while (1) 
	{
		int n = keyControl();
		switch (n)
		{
		case UP:
			if (y > 12) {//y�� 12���� 18������ �����̰� ��
				
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << ">";

			}
			break;
		case DOWN:
			if (y < 18) {//y�� 12���� 18������ �����̰� ��
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";

			}
			break;
		case SUBMIT:
			return y - 12;//���ڸ� ��ȯ�Ͽ� �����Ŵ
		default:
			break;
		}
	}

}

void drawMap(int *x, int *y)
{
	system("cls");
	int w, h;//���� ����

	for (h = 0; h < MapY; h++) //���α��̱���
	{
		char temp;
		for (w = 0; w < MapX; w++) //���� ���̱���
		{

			 temp = tempMap[h * MapX + w];
			 switch (temp)
			 {
			 case '0'://�����
				 setColor(black, black);
				 cout << " ";
				 break;
			 case '1'://��
				 setColor(white, white);
				 cout << "#";
				 break;
			 case 's'://�÷��̾�
				 setColor(cyan, black);
				 *x = w;
				 *y = h;
				 cout << "@";
				 break;
			 case 'q'://������
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
	cout << "��ġ : " << *x << ", " <<  *y;

	setColor(yellow, black);
	gotoxy(34,36);
	cout << "���� : "  <<*key<< "��";
}

void gLoop(int mapCode)
{
	int x, y;
	int key = 0;
	int playing = 1;//1 �̸� ������ 0�̸� ���� ����

	//mapcode�� ������ �ʰ���
	for(int i =0; i < sizeof(tempMap) / sizeof(*tempMap); i++) tempMap[i] = ' ';
	if (mapCode == 0)inputMap(tempMap, map1);
	else if(mapCode == 1)inputMap(tempMap, map2);
	else if (mapCode == 2)inputMap(tempMap, map3);
	else if (mapCode == 3)inputMap(tempMap, map4);
	else if (mapCode == 4)PMG();
	

	drawMap(&x, &y);// �� �����Ĥ� ���

	//���� ����
	while (playing != 0 && playing != 3)
	{
		drawUI(&x, &y, &key);
		switch (keyControl())
		{
		case UP:
			move(&x, &y, 0, -1, &key, &playing);//y�� -1�ؼ� �������ΰ�
			break;
		case DOWN:
			move(&x, &y, 0, 1, &key, &playing);////y�� +1�ؼ� �Ʒ������ΰ�
			break;
		case LEFT:
			move(&x, &y, -1, 0, &key, &playing);//x�� -1�ؼ� �������ΰ�
			break;
		case RIGHT:
			move(&x, &y, 1, 0, &key, &playing);//x�� +1�ؼ� ���������ΰ�
			break;
		case SUBMIT:
			playing = 3;//�����̽��� ������ ����
		
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
	setColor(white, black);//�� �⺻��
	switch (mapObject)
	{
	case 'k':
		*key += 1;//Ű ���� ����
		tempMap[(*y + _y) * MapX + _x] = '0';//�ʿ� �ִ� Ű�� ������
		gotoxy(*x + _x, *y + _y);
		cout << " ";
		break;
	case 'q'://������
		*playing = 0;
	case '0'://������̱� ������ �̵���
		gotoxy(*x, *y);
		cout << " ";

		setColor(cyan, black);
		gotoxy(*x + _x, *y + _y);
		cout << "@";

		*x += _x;
		*y += _y;
		break;
	case '1'://��
		break;
	
	
	case 'l':
		if (*key >= 1) {
			*key -= 1;//Ű �Ѱ��� ���
			tempMap[(*y + _y) * MapX + _x] = '0';//���� �������Ƿ� ���� ����
			setColor(white, black);//�� �⺻��
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
	
	//< 1�ܰ�. �õ� ����
	random_device rn;
	mt19937_64 rnd(rn());

	//< 2�ܰ�. ���� ���� ( ���� )
	uniform_int_distribution<int> rangeX(51, MapX-1);
	int x, y;
	x = rangeX(rnd);
	uniform_int_distribution<int> rangeY(7, MapY-1);
	y = rangeY(rnd);

	//�����Ҷ� Ȧ���� �ƴϸ� ������ �ȵ�
	if (x % 2 == 0) x++;
	if (y % 2 == 0) y++;

	Maze maze(x, y);

	maze.SetMazeUp();//�� ����
	maze.generator(tempMap, MapX);//tempMap�� �� �ֱ�
	tempMap[((y-3) * MapX) + x-2] = 'q';//Ż�ⱸ �ֱ�

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