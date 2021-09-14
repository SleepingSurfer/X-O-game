#pragma once
#include <iostream>
class Field
{
	bool is_choosen;
	char X_or_O;
public:
	Field();
	void change_filed_owner();
	char field_content();
};
