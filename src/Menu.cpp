#include <stdlib.h>
#include <conio.h>
#include "../inc/Menu.h"

void buttom_clicked()
{
	menu::LCK = _getch();
	if (menu::LCK == 'w')//w zmienia aktualnie wybran¹ opcjê na t¹ powy¿ej
	{
		if (menu::current_option > 1)
			menu::curent_option++;
	}
	else if (menu::LCK == 's')//s zmienia aktualnie wybran¹ opcjê na t¹ poni¿ej
	{
		if (menu::current_option < 4)
			menu::curent_option--;
	}
	else if (menu::LCK == '\n') //Enter zatwierdza wybór opcji
	{

	}
	else;
}
void display_menu()
{
	switch (menu::current_option)
	{
	case menu::menu_option::nowa_gra:
		std::cout << menu::option[menu::menu_option::nowa_gra];
			break;
	case menu::menu_option::wczytaj_zapis:
		std::cout << menu::option[menu::menu_option::wczytaj_zapis];
		break;
	case menu::menu_option::sterowanie:
		std::cout << menu::option[menu::menu_option::sterowanie];
		break;

	case menu::menu_option::twórcy:
		std::cout << menu::option[menu::menu_option::twórcy];
		break;

}