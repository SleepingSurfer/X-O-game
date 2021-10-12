#pragma once
#include <string>
class Ingame_menu
{
private:
    enum menu_option_t
    {
        RESET = 0,
        WCZYTAJ_ZAPIS = 1,
        ZAPISZ_GRE = 2,
        STEROWANIE = 3

    };
    int current_option = 2;
    std::string option[4] = { "reset","wczytaj zapis","zapisz gre","sterowanie" };
public:
    Ingame_menu();
    int button_clicked();
    void display_menu();
    void screen_refresh();
    int start();
    void controlls();
};