#pragma once
#include <iostream>
#include "Field.h"
#define BOARD_LENGHT 3
#define BOARD_WIDTH 3
//skalowanie warunk�w zwyci�stwa
class Board
{
private:
	Field field[9];
	int indicator_position = 5;
	char whom_turn = 'X'; //przenie� do metody
public:
	Board();
	void save_possition();
	void load_possition();
	void screen_refresh();
	void board_edge();
	void game_move();
	void start();
	void x_won_communicat();
	void o_won_communicat();
	void who_won();
	void reset();
};

