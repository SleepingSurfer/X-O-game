#include "Board.h"
#include "X-O Game Project.cpp"

void screen_refresh()
{
	Sleep(1000);
	system("CLS");

}

void board_visuals()
{

}

void board(int BoardSize)
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

void reset()
{
	possibleMove[9] = { 90,90,90,90,90,90,90,90,90 };
	player_two_points = 0;
}