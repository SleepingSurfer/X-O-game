#pragma once
#include <iostream>
#include "Field.h"
#define BOARD_LENGHT 3
#define BOARD_WIDTH 3
//skalowanie warunków zwyciêstwa
class Board
{
private:
	Field field[9];
	int indicator_position = 5;
public:
	Board();
	void save_possition();
	void load_possition();
	void screen_refresh();
	void board_edge();
	char game_move(char znak);
	void start();
	void x_won_communicat();
	void o_won_communicat();
	char who_won(char znak);
	void reset();
};

