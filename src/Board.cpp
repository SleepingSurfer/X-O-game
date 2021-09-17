#include "../inc/Board.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
#define ENTER 13
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
			std::cout << "==";
		}
		std::cout << std::endl;
		for (int s = BOARD_SIZE; s > 0; s--)
		{
			if (indicator_position == k && field[indicator_position].is_choosen_function())
			std::cout <<"?"<<"|";
			else if(indicator_position == k && !field[indicator_position].is_choosen_function())
			std::cout << "!" << "|";
			else
			std::cout << field[k].field_value() << "|";
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
		if (indicator_position != 0 && indicator_position != 1 && indicator_position != 2)
		{
			indicator_position = indicator_position - 3;
		}
	}
	else if (LCK == 's')//przesuwa wybrane pole w dó³
	{
		if (indicator_position != 6 && indicator_position != 7 && indicator_position != 8)
		{ 
			indicator_position = indicator_position + 3;
		}
	}
	else if (LCK == 'a')//przesuwa wybrane pole w levo
	{
		if (indicator_position != 0 && indicator_position != 3 && indicator_position != 6)
		{
			indicator_position = indicator_position - 1;
		}
	}
	else if (LCK == 'd')//przesuwa wybrane pole w prawo
	{
		if (indicator_position != 2 && indicator_position != 5 && indicator_position != 8)
		{
			indicator_position = indicator_position + 1;
		}
	}
	else if (LCK == 'r') //reset
	{
		std::cout << "Czy chcesz zresetowac plansze?" << std::endl;
		Sleep(1000); //Daje czas na przeczytanie
		LCK = _getch();
		if (LCK == ENTER)// Enter potwierdza
		{
			reset();
		}
	}
	else if (LCK == 'c') //save
	{
		std::cout << "Czy chcesz zapisac plansze?" << std::endl;
		Sleep(1000); //Daje czas na przeczytanie
		LCK = _getch();
		if (LCK == ENTER)// Enter potwierdza
		{
			save_possition();
		}
	}
	else if (LCK == ENTER) //Enter zatwierdza wybór opcji
	{
		if(whom_turn == 'X' && field[indicator_position].is_choosen_function())
		{
			field[indicator_position].change_filed_owner(whom_turn);
			whom_turn = 'O';
			field[indicator_position].choose();
			
		}
		else if (whom_turn == 'O' && field[indicator_position].is_choosen_function())
		{
			field[indicator_position].change_filed_owner(whom_turn);
			whom_turn = 'X';
			field[indicator_position].choose();
		}
	}

}
void Board::start()
{
	screen_refresh();
	while(1)
	{ 
		board_edge();
		game_move();
		screen_refresh();
	}

}
void Board::reset()
{
	for (int i = 0; i < 9; i++)
	{
		field[i].reset();
	}
}

void Board::save_possition()
{
	std::ofstream save;
	save.open("game_save.txt");
	for (int i = 0; i < 9; i++)
	{
		save << field[i].field_value();
	}
}

Board::Board()
{

}
