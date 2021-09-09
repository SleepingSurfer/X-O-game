#pragma once
#include <iostream>
class Field
{
	bool is_choosen;
	char field_owner = ' ';
	field();
	void change_filed_owner();
};
class Board
{
private:
	Field x[9];
	int boardSize = 3; // nie wiem dlaczego ale funkcja nie widzi go z prywatnych do poprawy
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

