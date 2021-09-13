#include "../inc/Board.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
void Board::screen_refresh()
{
	Sleep(1000);
	system("CLS");

}

void Board::board_visuals()
{

}

void Board::board()
{
	int actuall = 4;
	int k = 0;
	for (int i = BOARD_SIZE; i > 0; i--)
	{
		for (int y = BOARD_SIZE; y > 0; y--)
		{
			std::cout << "===";
		}
		std::cout << std::endl;
		for (int s = BOARD_SIZE; s > 0; s--)
		{

			//std::cout << "|" << Board::field[k];
			k++;
		}
		std::cout << std::endl;
	}
}

void Board::reset()
{
	Board::player_two_points = 0;
}

void Board:: game_move()
{
	Board::LCK = _getch();
	if (Board::LCK == 'w')//przesuwa wybrane pole w górê
	{
		if (indicator_position != 7 && indicator_position != 8 && indicator_position != 9)
		{ }
	}
	else if (Board::LCK == 's')//przesuwa wybrane pole w dó³
	{
		if (indicator_position != 7 && indicator_position != 8 && indicator_position != 9)
		{ }
	}
	else if (Board::LCK == 'a')//przesuwa wybrane pole w levo
	{
		if (indicator_position != 7 && indicator_position != 8 && indicator_position != 9)
		{ }
	}
	else if (Board::LCK == 'd')//przesuwa wybrane pole w prawo
	{
		if (indicator_position != 7 && indicator_position != 8 && indicator_position != 9)
		{

		}
	}
	else if (Board::LCK == '\n') //Enter zatwierdza wybór opcji
	{

	}
	else;
}
Board::Board()
{

}