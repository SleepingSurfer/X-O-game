#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>


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
    char LCK;
    int current_option = 1;
    std::string option[4] = {"nowa gra","wczytaj zapis","sterowanie","tworcy"};
public:
   Menu();
  void button_clicked();
   void display_menu();
   void start();
};