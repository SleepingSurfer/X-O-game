#include "../inc/Board.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <string>
#define ENTER 13
#define SYMBOL 219
#define ESC 27
void Board::screen_refresh() // przeneiœ do klasy gra to samo w klasie menu
{
	Sleep(100);
	system("CLS");

}

void Board::board_edge()
{
	std::string padding = "  ";
	char symbol = SYMBOL;
	int border = BOARD_WIDTH;
	for (int i = 0; i  < BOARD_WIDTH; i++) // przerób dla tablicy 2 wymiarowej
	{
		std::cout << padding;
		if (border != 0)
		{
			std::cout << "=";
			
		}
		for (int y = 0; y < BOARD_WIDTH; y++)
		{
			std::cout<< "==";
		}
		std::cout << std::endl;
		std::cout << padding;
		if (border != 0)
		{
			std::cout << "|";
		}
		for (int s = 0; s < BOARD_LENGHT; s++)
		{
			if (indicator_position_y == i && indicator_position_x == s && cycle == 1)
				std::cout <<symbol << "|";
			else
			{
				std::cout << field[i][s].field_value() << "|";
			}
	
		}
		std::cout << std::endl;
		border--;
	}
}


char Board:: game_move(char znak, char clicked_key) // przenieœ do Klasy game, niech zwraca pozycje kursora
{
	char whom_turn = znak; //przenieœ do metody
	char LCK = clicked_key;
	if (LCK == 'w')//przesuwa wybrane pole w górê
	{
		if (indicator_position_y != 0)//popraw
		{
			indicator_position_y = indicator_position_y - 1;
		}
	}
	else if (LCK == 's')//przesuwa wybrane pole w dó³
	{
		if (indicator_position_y != (BOARD_LENGHT-1))
		{ 
			indicator_position_y = indicator_position_y + 1;
		}
	}
	else if (LCK == 'a')//przesuwa wybrane pole w levo
	{
		if (indicator_position_x != 0)
		{
			indicator_position_x = indicator_position_x - 1;
		}
	}
	else if (LCK == 'd')//przesuwa wybrane pole w prawo
	{
		if (indicator_position_x != (BOARD_WIDTH - 1))
		{
			indicator_position_x = indicator_position_x + 1;
		}
	}
	else if (LCK == ESC)
	{
		int chfunction = igmenu.start();
		if (chfunction == 1)
		{
			std::cout << "Czy chcesz zresetowac plansze? <<ENTER>>" << std::endl;
			Sleep(1000); //Daje czas na przeczytanie
			LCK = _getch();
			if (LCK == ENTER)// Enter potwierdza
			{
				reset();
			}
		}
		else if (chfunction == 2)
		{
			std::cout << "Czy chcesz wczytac plansze? <<ENTER>>" << std::endl;
			Sleep(1000); //Daje czas na przeczytanie
			LCK = _getch();
			if (LCK == ENTER)// Enter potwierdza
			{
				load_possition();
			}
		}
		else if (chfunction == 3)
		{
			std::cout << "Czy chcesz zapisac plansze? <<ENTER>>" << std::endl;
			Sleep(1000); //Daje czas na przeczytanie
			LCK = _getch();
			if (LCK == ENTER)// Enter potwierdza
			{
				save_possition();
			}
		}
	}
	else if (LCK == ENTER) //Enter zatwierdza wybór opcji
	{
		if(whom_turn == 'X' && field[indicator_position_y][indicator_position_x].is_choosen_function())
		{
			field[indicator_position_y][indicator_position_x].change_filed_owner(whom_turn);
			whom_turn = 'O';
			field[indicator_position_y][indicator_position_x].choose();
			
		}
		else if (whom_turn == 'O' && field[indicator_position_y][indicator_position_x].is_choosen_function())
		{
			field[indicator_position_y][indicator_position_x].change_filed_owner(whom_turn);
			whom_turn = 'X';
			field[indicator_position_y][indicator_position_x].choose();
		}
	}
	return whom_turn;
}
void Board::start()
{
	char whom_turn = 'X'; //przenieœ do metody
	screen_refresh();
	while(1)
	{ 
		char clicked_key = 'P';
		while(clicked_key == 'P')
		{
			board_edge();
			char decoy = 'n';
			if (_kbhit() != 0)
			{
				decoy = _getch();
			}
			if (decoy == 'w' || decoy == 's' || decoy == 'a' || decoy == 'd' || decoy == ENTER || decoy == ESC)
				clicked_key = decoy;
			cycle_tick();
			whom_turn = game_move(whom_turn, clicked_key);
			whom_turn = who_won(whom_turn);
			screen_refresh();
		}
	}

}

void Board::x_won_communicat()
{
	system("CLS");
	std::cout << "Gracz o znaku X wygral" << std::endl;
	std::cout << "!!!Gratulacje!!!" << std::endl;
	Sleep(5000);
	reset();
}

void Board::o_won_communicat()
{
	system("CLS");
	std::cout << "Gracz o znaku O wygral" << std::endl;
	std::cout << "!!!Gratulacje!!!" << std::endl;
	Sleep(5000);
	reset();

}
char Board::who_won(char znak)//git jest
{
	bool someone_won = false;
	int sval = 0; // tymczasowe
	int fval = 0;
	for (fval; fval == BOARD_WIDTH-3; fval++)
	{
		for (sval; sval == BOARD_LENGHT-3; sval++)
		{
			if (field[fval][sval].field_value() == field[fval][sval + 1].field_value() && field[fval][sval + 1].field_value() == field[fval][sval + 2].field_value())//poziomo poprawiona musi byæ tak bo potrójny warunek nie dzia³a
			{
				if (field[fval][sval].field_value() == 'X') //do 
				{
					x_won_communicat();
					someone_won = true;
				}
				else if (field[fval][sval].field_value() == 'O')
				{
					o_won_communicat();
					someone_won = true;
				}
			}
			else if (field[fval][sval].field_value() == field[fval + 1][sval].field_value() && field[fval + 1][sval].field_value() == field[fval + 2][sval].field_value())//pionowo
			{
				if (field[fval][sval].field_value() == 'X') //do 
				{
					x_won_communicat();
					someone_won = true;
				}
				else if (field[fval][sval].field_value() == 'O')
				{
					o_won_communicat();
					someone_won = true;
				}
			}
		}
	}
		if (field[0][0].field_value() == field[1][ 1].field_value() && field[1][1].field_value() == field[2][2].field_value())//przek¹tne
		{
			if (field[1][1].field_value() == 'X') //do 
			{
				x_won_communicat();
				someone_won = true;
			}
			else if (field[1][1].field_value() == 'O')
			{
				o_won_communicat();
				someone_won = true;
			}
		}
			else if (field[2][0].field_value() == field[1][1].field_value() && field[1][1].field_value() == field[0][2].field_value())//przek¹tne
		{

			if (field[1][1].field_value() == 'X') //do 
			{
				x_won_communicat();
				someone_won = true;
			}
			else if (field[1][1].field_value() == 'O')
			{
				o_won_communicat();
				someone_won = true;
			}
		}
	if (someone_won)
		return 'X'; //resetowanie znaku na X po wygranej
	else
		return znak; //tu nie resetuje
}
void Board::reset()
{
	for (int i = 0; i < BOARD_LENGHT; i++)
	{
		for (int j = 0; j < BOARD_WIDTH; j++)
		{
			field[i][j].reset();
		}
	}
}

void Board::save_possition()//przenieœ do klasy game
{
	std::ofstream save;
	save.open("game_save.txt");
	for (int i = 0; i < BOARD_LENGHT; i++)
	{
		for (int j = 0; j < BOARD_WIDTH; j++)
		{
			save << field[i][j].field_value();
		}
	}
}

void Board::load_possition()//przenieœ do klasy game
{
	std::ifstream load_save;
	std::string buf;
	char buffor[BOARD_LENGHT][BOARD_WIDTH];
	load_save.open("game_save.txt");
	load_save >> buf;
	for (int i = 0; i < BOARD_LENGHT; i++)
	{
		int y = 0;
		for (int j = 0; j < BOARD_WIDTH; j++)
		{
			buffor[i][j] = buf[y];
			y++;
		}
	}
	for (int i = 0; i < BOARD_LENGHT; i++)
	{
		for (int j = 0; j < BOARD_WIDTH; j++)
		{
			field[i][j].change_filed_owner(buffor[i][j]);
		}
	}

}

Board::Board()
{

}

void Board::cycle_tick()
{
	Sleep(50);
	if (cycle <= 1)
	{
		cycle++;
	}
	else
		cycle = 0;

}