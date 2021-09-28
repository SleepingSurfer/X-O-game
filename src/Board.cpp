#include "../inc/Board.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <string>
#define ENTER 13
void Board::screen_refresh() // przeneiœ do klasy gra to samo w klasie menu
{
	Sleep(100);
	system("CLS");

}

void Board::board_edge()
{
	int actuall = 4;
	int k = 0;
	for (int i = BOARD_WIDTH; i > 0; i--) // przerób dla tablicy 2 wymiarowej
	{
		for (int y = BOARD_WIDTH; y > 0; y--)
		{
			std::cout << "==";
		}
		std::cout << std::endl;
		for (int s = BOARD_LENGHT; s > 0; s--)
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


char Board:: game_move(char znak) // przenieœ do Klasy game, niech zwraca pozycje kursora
{
	char whom_turn = znak; //przenieœ do metody
	char LCK = _getch();
	if (LCK == 'w')//przesuwa wybrane pole w górê
	{
		if (indicator_position != 0 && indicator_position != 1 && indicator_position != 2)//popraw
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
	else if (LCK == 'l') //save
	{
		std::cout << "Czy chcesz wczytac plansze?" << std::endl;
		Sleep(1000); //Daje czas na przeczytanie
		LCK = _getch();
		if (LCK == ENTER)// Enter potwierdza
		{
			load_possition();
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
	return whom_turn;
}
void Board::start()
{
	char whom_turn = 'X'; //przenieœ do metody
	screen_refresh();
	while(1)
	{ 
		board_edge();
		whom_turn = game_move(whom_turn);
		whom_turn = who_won(whom_turn);
		screen_refresh();
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
	if (field[0].field_value() == field[1].field_value() && field[1].field_value() == field[2].field_value())//poziomo poprawiona musi byæ tak bo potrójny warunek nie dzia³a
	{
		if (field[0].field_value() == 'X') //do 
		{
			x_won_communicat();
			someone_won = true;
		}
		else if (field[0].field_value() == 'O')
		{
			o_won_communicat();
			someone_won = true;
		}
	}
	else if (field[3].field_value() == field[4].field_value() && field[4].field_value() == field[5].field_value())//poziomo
	{
		if (field[3].field_value() == 'X') //do 
		{
			x_won_communicat();
			someone_won = true;
		}
		else if (field[3].field_value() == 'O')
		{
			o_won_communicat();
			someone_won = true;
		}
	}
	else if (field[6].field_value() == field[7].field_value() && field[7].field_value() == field[8].field_value())//poziomo
	{
		if (field[6].field_value() == 'X') //do 
		{
			x_won_communicat();
			someone_won = true;
		}
		else if (field[6].field_value() == 'O')
		{
			o_won_communicat();
			someone_won = true;
		}
	}
	else if (field[0].field_value() == field[3].field_value() && field[3].field_value() == field[6].field_value())//pionowo
	{
		if (field[0].field_value() == 'X') //do 
		{
			x_won_communicat();
			someone_won = true;
		}
		else if (field[0].field_value() == 'O')
		{
			o_won_communicat();
			someone_won = true;
		}
	}
	else if (field[1].field_value() == field[4].field_value() && field[4].field_value() == field[7].field_value())//pionowo
	{
		if (field[1].field_value() == 'X') //do 
		{
			x_won_communicat();
			someone_won = true;
		}
		else if (field[1].field_value() == 'O')
		{
			o_won_communicat();
			someone_won = true;
		}
	}
	else if (field[2].field_value() == field[5].field_value() && field[5].field_value() == field[8].field_value())//pionowo
	{
		if (field[2].field_value() == 'X') //do 
		{
			x_won_communicat();
			someone_won = true;
		}
		else if (field[2].field_value() == 'O')
		{
			o_won_communicat();
			someone_won = true;
		}
	}
	else if (field[0].field_value() == field[4].field_value() && field[4].field_value() == field[8].field_value())//przek¹tne
	{
		if (field[0].field_value() == 'X') //do 
		{
			x_won_communicat();
			someone_won = true;
		}
		else if (field[0].field_value() == 'O')
		{
			o_won_communicat();
			someone_won = true;
		}
	}
	else if (field[6].field_value() == field[4].field_value() && field[4].field_value() ==  field[2].field_value())//przek¹tne
	{

		if (field[6].field_value() == 'X') //do 
		{
			x_won_communicat();
			someone_won = true;
		}
		else if (field[6].field_value() == 'O')
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
	for (int i = 0; i < 9; i++)
	{
		field[i].reset();
	}
}

void Board::save_possition()//przenieœ do klasy game
{
	std::ofstream save;
	save.open("game_save.txt");
	for (int i = 0; i < 9; i++)
	{
		save << field[i].field_value();
	}
}

void Board::load_possition()//przenieœ do klasy game
{
	std::ifstream load_save;
	std::string buffor;
	load_save.open("game_save.txt");
	load_save >> buffor;
	for (int i = 0; i < 9; i++)
	{
	field[i].change_filed_owner(buffor[i]);
	}

}

Board::Board()
{

}
