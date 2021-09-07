#include "../inc/Board.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
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
	for (int i = Board::boardSize; i > 0; i--)
	{
		for (int y = Board::boardSize; y > 0; y--)
		{
			std::cout << "===";
		}
		std::cout << std::endl;
		for (int s = Board::boardSize; s > 0; s--)
		{

			std::cout << "|" << Board::possibleMove[k];
			k++;
		}
		std::cout << std::endl;
	}
}

void reset()
{
	Board::possibleMove[9] = { 90,90,90,90,90,90,90,90,90 };
	Board::player_two_points = 0;
}