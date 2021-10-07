#pragma once
#include <iostream>
#include "Field.h"
#define BOARD_LENGHT 3
#define BOARD_WIDTH 3
//skalowanie warunków zwyciêstwa
class Board
{
private:
	Field field[BOARD_LENGHT][BOARD_WIDTH];
	int indicator_position_y = 1;
	int indicator_position_x = 1;
	int cycle = 0;
public:
	Board();
	void cycle_tick();
	void save_possition();
	void load_possition();
	void screen_refresh();
	void board_edge();
	char game_move(char znak, char clicked_key);
	void start();
	void x_won_communicat();
	void o_won_communicat();
	char who_won(char znak);
	void reset();
};

