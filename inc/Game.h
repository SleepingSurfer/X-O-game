#pragma once
#include "Board.h"
#include "Menu.h"
class Game
{
private:
	Board game_board;
	int player_one_points = 0;
	int player_two_points = 0;
public:
	Game();
	void reset();
	void print_board();
};