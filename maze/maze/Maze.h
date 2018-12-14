#pragma once
#include"Node.h"
#include<iostream>
#include<random>
class Maze
{
private:
	int goalflag;
	int width;
	int height;
	Node * nodes;
	Node *start, *last;
	Maze();
public:
	Maze(int, int);
	
	~Maze();
	int init();
	Node *link(Node *n);
	Node* GetNodes(int);
	void generator(char *, int MapX);
	void print();
	void SetMazeUp();
};

