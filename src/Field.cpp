#include "../inc/Field.h"
Field::Field()
{
	this->is_choosen = false;
	this->X_or_O = 255; // dziwny znak nie wyswietla sie w konsoli zastêpuje ' ';

}
void Field::change_filed_owner(char player_sign)
{
	X_or_O = player_sign;
}

void Field::choose()
{
	is_choosen = true;
}

char Field::field_value()
{
	return X_or_O;
}

void Field::reset()
{
	X_or_O = ' ';
}

bool Field::is_choosen_function()
{
	if (is_choosen == false)
		return true;
	else 
		return false;
}