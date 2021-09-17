#pragma once
#include <iostream>
#include "Field.h"
#define BOARD_SIZE 3
class Board
{
private:
	Field field[9];
	int indicator_position = 5;
	char LCK = ' '; // last clicked key
	char whom_turn = 'X'; // nie wiem dlaczego ale funkcja nie widzi go z prywatnych do poprawy
public:
	Board();
	void save_possition();
	void screen_refresh();
	void board_edge();
	void game_move();
	void start();
	void reset();
};

