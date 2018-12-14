#pragma once
class Node
{
private:
	int x, y;//��ǥ
	Node *parent;
	char c;//��¶� ǥ�õ� ��
	char dirs;//����
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

