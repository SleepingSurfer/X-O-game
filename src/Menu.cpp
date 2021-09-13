#include <stdlib.h>
#include <conio.h>
#include "../inc/Menu.h"


void Menu::button_clicked()
{
	LCK = _getch();
	if (LCK == 'w')//w zmienia aktualnie wybran¹ opcjê na t¹ powy¿ej
	{
		if (current_option > 1)
		{
			current_option++;
			display_menu();
		}
	}
	else if (LCK == 's')//s zmienia aktualnie wybran¹ opcjê na t¹ poni¿ej
	{
		if (current_option < 4)
		{
			current_option--;
			display_menu();
		}
	}
	else if (LCK == '\n') //Enter zatwierdza wybór opcji
	{

	}
	else
	{

	}
}
void Menu::display_menu()
{
	switch (current_option)
	{
	case NOWA_GRA:
		std::cout << option[NOWA_GRA];
		break;
	case WCZYTAJ_ZAPIS:
		std::cout << option[WCZYTAJ_ZAPIS];
		break;
	case STEROWANIE:
		std::cout << option[STEROWANIE];
		break;

	case CREDITS:
		std::cout << option[CREDITS];
		break;
	}
}
void Menu::start()
{

}
Menu::Menu()
{

}
