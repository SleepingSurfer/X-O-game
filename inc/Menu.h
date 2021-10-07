#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
#include "Game.h"


class Menu
{
    
private:
    enum menu_option_t
    {
        NOWA_GRA = 0,
        WCZYTAJ_ZAPIS = 1,
        STEROWANIE = 2,
        CREDITS = 3

    };
    int current_option = 2;
    std::string option[4] = {"nowa gra","wczytaj zapis","sterowanie","tworcy"};
    std::string alt_option[3] = { "zapisz gre","wczytaj zapis","zresetuj plansze"};
public:
   Menu();
   void controlls();
   int button_clicked();
   void display_menu();
   void screen_refresh();
   int start();

};