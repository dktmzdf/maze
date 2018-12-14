#include "Node.h"


Node::Node()
{
	
	this->parent = nullptr;
}


Node::~Node()
{
}

void Node::SetParent(Node *parent)
{
	this->parent = parent;
}

void Node::SetX(int x)
{
	this->x = x;
}

void Node::SetY(int y)
{
	this->y = y;
}

void Node::SetDirs(char dirs)
{
	this->dirs = dirs;
}

void Node::SetC(char c)
{
	this->c = c;
}

int Node::GetX()
{
	return this->x;
}

int Node::GetY()
{
	return this->y;
}

char Node::GetC()
{
	return this->c;
}

char Node::GetDirs()
{
	return this->dirs;
}

Node * Node::GetParent()
{
	return this->parent;
}
