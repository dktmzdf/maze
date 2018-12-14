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

	//< 1단계. 시드 설정
	random_device rn;
	mt19937_64 rnd(rn());

	//< 2단계. 분포 설정 ( 정수 )
	uniform_int_distribution<int> rangeX(51, MaxMapX - 1);
	int MazeX, MazeY;
	MazeX = rangeX(rnd);
	uniform_int_distribution<int> rangeY(7, MaxMapY - 1);
	MazeY = rangeY(rnd);

	//구현할때 홀수가 아니면 구현이 안됨
	if (MazeX % 2 == 0) MazeX++;
	if (MazeY % 2 == 0) MazeY++;


	Maze maze(MazeX, MazeY);
	maze.SetMazeUp();
	maze.generator(Map, MaxMapX);
}