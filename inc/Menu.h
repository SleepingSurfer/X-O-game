#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>


class menu
{
private:
    enum menu_option
    {
        nowa_gra = 0,
        wczytaj_zapis = 1,
        sterowanie = 2,
        twórcy = 3

    };
    char LCK;
    int current_option = 1;
    std::string option[4] = {"nowa gra","wczytaj zapis","sterowanie","twórcy"};
public:
    menu();
    void button_clicked();
    void display_menu();
}