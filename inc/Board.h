#pragma once
#include <iostream>
#include "Field.h"
#include "Ingame_menu.h"
#define BOARD_LENGHT 4
#define BOARD_WIDTH 12
//skalowanie warunk?w zwyci?stwa
class Board
{
private:
	Ingame_menu igmenu;
	Field field[BOARD_LENGHT][BOARD_WIDTH];
	int indicator_position_y = 4;
	int indicator_position_x = 4;
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

