#include "PSG.h"
using namespace std;


void PSG::BFS()
{
}

PSG::PSG()
{
}
PSG::PSG(int MaxMapX, int MaxMapY,char *Map)
{
	
	PMG(MaxMapX, MaxMapY,this->Map);

}

PSG::~PSG()
{
}

void PSG::PMG(int MaxMapX, int MaxMapY, char *Map)//procedure maze generator
{

	//< 1�ܰ�. �õ� ����
	random_device rn;
	mt19937_64 rnd(rn());

	//< 2�ܰ�. ���� ���� ( ���� )
	uniform_int_distribution<int> rangeX(51, MaxMapX - 1);
	int MazeX, MazeY;
	MazeX = rangeX(rnd);
	uniform_int_distribution<int> rangeY(7, MaxMapY - 1);
	MazeY = rangeY(rnd);

	//�����Ҷ� Ȧ���� �ƴϸ� ������ �ȵ�
	if (MazeX % 2 == 0) MazeX++;
	if (MazeY % 2 == 0) MazeY++;


	Maze maze(MazeX, MazeY);
	maze.SetMazeUp();
	maze.generator(Map, MaxMapX);
}