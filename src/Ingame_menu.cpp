#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "../inc/Ingame_menu.h"
#include "../inc/Game.h"
int Ingame_menu::button_clicked()
{
	char LCK = _getch();
	if (LCK == 's')//s zmienia aktualnie wybran¹ opcjê na t¹ powni¿ej
	{
		if (current_option >= 0 && current_option < 3)
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
		case RESET:
			return 1;
			break;
		case WCZYTAJ_ZAPIS:
			return 2;
			break;
		case ZAPISZ_GRE:
			return 3;
			break;

		case STEROWANIE:
			std::cout << "sterowanie" << std::endl;
			controlls();
			break;
		}
	}
	else
	{
		return 0;
	}
}
void Ingame_menu::display_menu()
{
	system("cls");
	switch (current_option)
	{
	case RESET:
		std::cout << "----->" << option[RESET] << "<-----" << std::endl;
		std::cout << "  " << option[WCZYTAJ_ZAPIS] << "  " << std::endl;
		std::cout << "   " << option[ZAPISZ_GRE] << "   " << std::endl;
		std::cout << "   " << option[STEROWANIE] << "   " << std::endl;
		break;
	case WCZYTAJ_ZAPIS:
		std::cout << "      " << option[RESET] << "      " << std::endl;
		std::cout << "->" << option[WCZYTAJ_ZAPIS] << "<-" << std::endl;
		std::cout << "   " << option[ZAPISZ_GRE] << "   " << std::endl;
		std::cout << "   " << option[STEROWANIE] << "   " << std::endl;
		break;
	case ZAPISZ_GRE:
		std::cout << "      " << option[RESET] << "      " << std::endl;
		std::cout << "  " << option[WCZYTAJ_ZAPIS] << "  " << std::endl;
		std::cout << "-->" << option[ZAPISZ_GRE] << "<---" << std::endl;
		std::cout << "   " << option[STEROWANIE] << "   " << std::endl;
		break;

	case STEROWANIE:
		std::cout << "      " << option[RESET] << "      " << std::endl;
		std::cout << "  " << option[WCZYTAJ_ZAPIS] << "  " << std::endl;
		std::cout << "   " << option[ZAPISZ_GRE] << "  " << std::endl;
		std::cout << "-->" << option[STEROWANIE] << "<---" << std::endl;
		break;
	}
}
void Ingame_menu::screen_refresh()
{
	Sleep(100);
	system("CLS");

}
int Ingame_menu::start()
{
	int option = 0;
	while (1)
	{
		display_menu();
		option = button_clicked();
		screen_refresh();
		if (option == 1 || option == 2 || option == 3)
		{
			return option;
		}
	}
}
void Ingame_menu::controlls()
{
	system("CLS");
	std::cout << "Przycisk \"Enter\" pozwala zresetowac plansze" << std::endl;
	std::cout << "Przyciski \"WASD\" pozwalaja sterowac wskaznikiem po planszy" << std::endl;
	Sleep(5000);
}
Ingame_menu::Ingame_menu()
{
}
