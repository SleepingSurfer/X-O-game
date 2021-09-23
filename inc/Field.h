#pragma once
#include <iostream>
class Field
{
	bool is_choosen;
	char X_or_O; // symbol 
public:
	Field();
	void choose();
	bool is_choosen_function();
	void change_filed_owner(char a);
	void reset();
	char field_value();
};
