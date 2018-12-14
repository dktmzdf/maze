#include "Maze.h"
using namespace std;

Maze::Maze()
{
}
Maze::Maze(int width, int height)
{
	this->width = width;
	this->height = height;
	this->goalflag = 0;
	init();
}

Maze::~Maze()
{
	delete[] nodes;
}

int Maze::init()
{
	int i, j;
	Node *n;

	//Allocate memory for maze
	nodes = new Node[width * height]();
	if (nodes == nullptr) return 1;

	//Setup crucial nodes
	for (i = 0; i < width; i++)
	{
		for (j = 0; j < height; j++)
		{
			
			n = &nodes[i + j * width];
			
			if (i * j % 2)
			{
				n->SetX(i);
				n->SetY(j);
				n->SetDirs(15); //Assume that all directions can be explored (4 youngest bits set)
				n->SetC('0');
			}
			else n->SetC('1'); //Add walls between nodes
		}
	}

}

Node * Maze::link(Node * n)
{
	//Connects node to random neighbor (if possible) and returns
	//address of next node that should be visited

	int x, y;
	

	char dir;
	Node *dest =nullptr;

	//< 1단계. 시드 설정
	random_device rn;
	mt19937_64 rnd(rn());

	//< 2단계. 분포 설정 ( 정수 )
	uniform_int_distribution<int> range(0, 4);

	//< 3단계. 값 추출
	


	//Nothing can be done if null pointer is given - return
	if (n == nullptr) return nullptr;

	//While there are directions still unexplored
	
	while (n->GetDirs())
	{
	
		//Randomly pick one direction
		dir = (1 << range(rnd));
		//If it has already been explored - try again
		if (~(n->GetDirs()) & dir) continue;

		//Mark direction as explored
		n->SetDirs(n->GetDirs() & ~dir) ;

		//Depending on chosen direction
		
		switch (dir)
		{
			//Check if it's possible to go right
		case 1:
			
			if (n->GetX() + 2 < width)
			{
				x = n->GetX() + 2;
				y = n->GetY();
			}
			else continue;
			break;

			//Check if it's possible to go down
		case 2:
			if (n->GetY() + 2 < height)
			{
				x = n->GetX();
				y = n->GetY() + 2;
			}
			else continue;
			break;

			//Check if it's possible to go left	
		case 4:
			if (n->GetX() - 2 >= 0)
			{
				x = n->GetX() - 2;
				y = n->GetY();
			}
			else continue;
			break;

			//Check if it's possible to go up
		case 8:
			if (n->GetY() - 2 >= 0)
			{
				x = n->GetX();
				y = n->GetY() - 2;
			}
			else continue;
			break;
		}

		//Get destination node into pointer (makes things a tiny bit faster)
		dest = &nodes[x + y * width];
		

		//Make sure that destination node is not a wall
		if (dest->GetC() == '0')
		{
			

			
			//If destination is a linked node already - abort
			if (dest->GetParent() != nullptr) continue;

			//Otherwise, adopt node
			dest->SetParent(n);

			//Remove wall between nodes
			nodes[n->GetX() + (x - n->GetX()) / 2 + (n->GetY() + (y - n->GetY()) / 2) * width].SetC('0');

			//Return address of the child node
			return dest;
		}
	}
	
	
	//If nothing more can be done here - return parent's address
	return n->GetParent();
	
}

Node* Maze::GetNodes(int count)
{
	//if (count == 0) return this->nodes;
	//else if(count > 0) return this->nodes[count]
	return nodes;
}

void Maze::generator(char *arr, int MapX)
{
	int i, j;
	
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			arr[i * MapX + j] = nodes[j + i * width].GetC();
			
		}
		
	}
	
}

void Maze::print()
{
	int i, j;

	//Outputs maze to terminal - nothing special
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			std::cout << nodes[j + i * width].GetC();
		}
		cout << "\n";
	}
}

void Maze::SetMazeUp()
{
	start = &nodes[1 + width];
	start->SetParent(start);
	last = start;
	
	//Connect nodes until start node is reached and can't be left
	while ((last = this->link(last)) != start);
	start->SetC('s');//player setting
	
}

