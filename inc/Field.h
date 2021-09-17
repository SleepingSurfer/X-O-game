#pragma once
#include <iostream>
class Field
{
	bool is_choosen;
	char X_or_O;
public:
	Field();
	void choose();
	bool is_choosen_function();
	void change_filed_owner(char a);
	char field_content();
};
