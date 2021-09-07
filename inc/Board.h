#pragma once
#include <iostream>
class Board
{
private:
	int boardSize = 3;
	int player_one_points;
	int player_two_points;
	char possibleMove[9] = { 90,90,90,90,90,90,90,90,90 };
	int playerOnePoints;
	int playerTwoPoints;
public:
	Board();
	void screen_refresh();
	void board_visuals();
	void board(int boardSize);
	void reset();
};

