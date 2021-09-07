#include <stdlib.h>
#include <conio.h>
#include "../inc/Menu.h"
void buttom_clicked()
{
	menu_element::LCK = _getch();
	if (menu_element::LCK == 'w')
	{
		if (menu_element::current_option > 1)
			menu_element::curent_option++;
	}
	else if (menu_element::LCK == 's')
	{
		if (menu_element::current_option < 4)
			menu_element::curent_option--;
	}
	else if (menu_element::LCK == '\n')
	{

	}
	else;
}
void display_menu()
{
	switch (menu_element::current_option)
	{
	case 1:
		std::cout << "|||" << menu_element::option_one << std::endl;
		std::cout << menu_element::option_two << std::endl;
		std::cout << menu_element::option_three << std::endl;
		std::cout << menu_element::option_four << std::endl;
	case 2:
		std::cout << menu_element::option_one << std::endl;
		std::cout << "|||" << menu_element::option_two << std::endl;
		std::cout << menu_element::option_three << std::endl;
		std::cout << menu_element::option_four << std::endl;
	case 3:
		std::cout << menu_element::option_one << std::endl;
		std::cout << menu_element::option_two << std::endl;
		std::cout << "|||" << menu_element::option_three << std::endl;
		std::cout << menu_element::option_four << std::endl;
	case 4:
		std::cout << menu_element::option_one << std::endl;
		std::cout << menu_element::option_two << std::endl;
		std::cout << menu_element::option_three << std::endl;
		std::cout << "|||" << menu_element::option_four << std::endl;
	}

}