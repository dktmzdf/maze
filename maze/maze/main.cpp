#include"main.h"
using namespace std;

int main()
{
	
	init();
	
	while (1)
	{
		titleDraw();
		int menuCode = menuDraw();
		if (menuCode == 0)
		{
			//게임 시작
			int n = mapListDraw();
			if(n < 5)
			gLoop(n);
		}
		else if (menuCode == 1)
		{
			infoDraw();
		}
		else if (menuCode == 2)
			return 0;

		system("cls");
	}
	
	
	return 0;
}




