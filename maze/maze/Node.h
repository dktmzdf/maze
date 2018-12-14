#pragma once
class Node
{
private:
	int x, y;//좌표
	Node *parent;
	char c;//출력때 표시될 값
	char dirs;//방향
public:
	Node();
	~Node();
	void SetParent(Node *);
	void SetX(int);
	void SetY(int);
	void SetDirs(char);
	void SetC(char);
	int GetX();
	int GetY();
	char GetC();
	char GetDirs();
	Node* GetParent();
};

