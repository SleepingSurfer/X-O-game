#pragma once
#include <iostream>
#define BOARD_SIZE 3
/*
class Field
{
	bool is_choosen;
	char X_or_O = ' ';
	Field();
	void change_filed_owner();
};
*/
class Board
{
private:
	//Field field[9];
	int indicator_position = 5;
	char LCK = ' '; // last clicked key
	char whom_turn = 'X'; // nie wiem dlaczego ale funkcja nie widzi go z prywatnych do poprawy
	int player_one_points = 0;
	int player_two_points = 0;
public:
	Board();
	void screen_refresh();
	void board_visuals();
	void board();
	void game_move();
	void reset();
};

