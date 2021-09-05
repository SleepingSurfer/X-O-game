#include "Board.h"

void screenRefresh()
{
	Sleep(1000);
	system("CLS");

}

void boardVisuals()
{

}

void Board(int BoardSize)
{
	int actuall = 4;
	int k = 0;
	for (int i = boardSize; i > 0; i--)
	{
		for (int y = boardSize; y > 0; y--)
		{
			std::cout << "===";
		}
		std::cout << std::endl;
		for (int s = boardSize; s > 0; s--)
		{

			std::cout << "|" << possibleMove[k];
			k++;
		}
		std::cout << std::endl;
	}
}