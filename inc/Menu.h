#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>


class menu_element
{
private:
    char LCK;
    int current_option = 1;
    std::string option_one;
    std::string option_two;
    std::string option_three;
    std::string option_four;
public:
    menu_element();
    void button_clicked();
    void display_menu();
}