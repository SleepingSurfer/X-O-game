#include "../inc/Field.h"
Field::Field()
{
	this->is_choosen = false;
	this->X_or_O = '8';

}
void Field::change_filed_owner()
{

}

char Field::field_content()
{
	return X_or_O;
}
