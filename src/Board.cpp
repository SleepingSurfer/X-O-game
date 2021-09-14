#include "../inc/Board.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
void Board::screen_refresh()
{
	Sleep(500);
	system("CLS");

}

void Board::board_edge()
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

			std::cout << "|" << Board::field[k].field_content();
			k++;
		}
		std::cout << std::endl;
	}
}


void Board:: game_move()
{
	char LCK = _getch();
	if (LCK == 'w')//przesuwa wybrane pole w górê
	{
		if (indicator_position != 1 && indicator_position != 2 && indicator_position != 3)
		{
			indicator_position = indicator_position - 3;
		}
	}
	else if (LCK == 's')//przesuwa wybrane pole w dó³
	{
		if (indicator_position != 7 && indicator_position != 8 && indicator_position != 9)
		{ 
			indicator_position = indicator_position + 3;
		}
	}
	else if (LCK == 'a')//przesuwa wybrane pole w levo
	{
		if (indicator_position != 1 && indicator_position != 4 && indicator_position != 7)
		{
			indicator_position = indicator_position - 1;
		}
	}
	else if (LCK == 'd')//przesuwa wybrane pole w prawo
	{
		if (indicator_position != 3 && indicator_position != 6 && indicator_position != 9)
		{
			indicator_position = indicator_position + 1;
		}
	}
	else if (LCK == '\n') //Enter zatwierdza wybór opcji
	{

	}
	else;
}
Board::Board()
{

}