#pragma once
#include"main.h"
#include"Maze.h"
class PSG//procedure stage generator
{
	enum Directs
	{
		NORTH, SOUTH, WEST, EAST
	};
private:
	char* Map;
	char* check;
	
	void BFS();
	PSG();
public:
	
	PSG(int x, int y, char * Map);
	~PSG();
	void PMG(int x, int y, char * Map);
};

