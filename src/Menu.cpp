#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "../inc/Menu.h"
#include "../inc/Game.h"

void Menu::button_clicked()
{
	Game play_game; // chcia³em wskaznik przekazac do tej funkcji ale nie dalem rady
	char LCK = _getch();
	if (LCK == 's')//s zmienia aktualnie wybran¹ opcjê na t¹ powni¿ej
	{
		if (current_option >= 0 && current_option <3)
		{
			++current_option;
		}
	}
	else if (LCK == 'w')//w zmienia aktualnie wybran¹ opcjê na t¹ powy¿ej
	{
		if (current_option < 4 && current_option > 0)
		{
			--current_option;
		}
	}
	else if (LCK == 13) //Enter zatwierdza wybór opcji
	{
		switch (current_option)
		{
		case NOWA_GRA:
			play_game.print_board();
			break;
		case WCZYTAJ_ZAPIS:
			play_game.load_game();
			break;
		case STEROWANIE:
			std::cout << "sterowanie" << std::endl;
			controlls();
			break;

		case CREDITS:
			std::cout << "credit" << std::endl;
			break;
		}
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
		std::cout <<"--->"<< option[NOWA_GRA] << "<---"<< std::endl;
		std::cout <<"    "<< option[WCZYTAJ_ZAPIS] << "    " << std::endl;
		std::cout << "    " << option[STEROWANIE] << "    " << std::endl;
		std::cout << "    " << option[CREDITS] << "    " << std::endl;
		break;
	case WCZYTAJ_ZAPIS:
		std::cout << option[NOWA_GRA] << std::endl;
		std::cout <<"*"<< option[WCZYTAJ_ZAPIS] << std::endl;
		std::cout << option[STEROWANIE] << std::endl;
		std::cout << option[CREDITS] << std::endl;
		break;
	case STEROWANIE:
		std::cout << option[NOWA_GRA] << std::endl;
		std::cout << option[WCZYTAJ_ZAPIS] << std::endl;
		std::cout <<"*"<< option[STEROWANIE] << std::endl;
		std::cout << option[CREDITS] << std::endl;
		break;

	case CREDITS:
		std::cout << option[NOWA_GRA] << std::endl;
		std::cout << option[WCZYTAJ_ZAPIS] << std::endl;
		std::cout << option[STEROWANIE] << std::endl;
		std::cout << "*" << option[CREDITS] << std::endl;
		break;
	}
}
void Menu::screen_refresh()
{
	Sleep(100);
	system("CLS");

}
void Menu::start()
{
	while (1)
	{
		display_menu();
		button_clicked();
		screen_refresh();
	}
}

void Menu::controlls()
{
	system("CLS");
	std::cout << "Przycisk \"r\" pozwala zresetowac plansze" << std::endl;
	std::cout << "Przycisk \"c\" pozwala zapisac plansze" << std::endl;
	std::cout << "Przycisk \"l\" pozwala wczytac zapisana plansze" << std::endl;
	std::cout << "Przycisk \"Enter\" pozwala zresetowac plansze" << std::endl;
	std::cout << "Przyciski \"WASD\" pozwalaja sterowac wskaznikiem po planszy" << std::endl;
	Sleep(5000);
}

Menu::Menu()
{

}

