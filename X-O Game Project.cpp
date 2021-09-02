#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "Board.h"
//#include "Menu.h"
#define enter 10;
#define upKey 72;
#define downKey 80;
#define leftKey 75;
#define rightKey 77;
void screenRefresh();
void boardVisuals();
int main()
{
	//wymiary i zmienne.
	char LCK; //last clicked key;
	int boardSize = 3;
	char possibleMove[9] = {90,90,90,90,90,90,90,90,90};
	int boardStatusSaved[9] = { 1,2,3,4,5,6,7,8,9};
	int playerOnePoints;
	int playerTwoPoints;
	std::cout << "Witaj oto gra w O i X. \n";
	std::cout << "Aby zagrac nacisnij ENTER \n";
	//menuElement lista[4];

	while (1)
	{
		int actuall = 4;
		int k = 0;
		for (int i = boardSize; i > 0; i--)
		{
			for (int y = boardSize; y > 0; y--)
			{
				std::cout << "===";
			}
			std::cout << std::endl;
			for (int s = boardSize; s > 0; s--)
			{

				std::cout << "|" << possibleMove[k];
				k++;
			}
			std::cout << std::endl;
		}

		LCK = getchar(); 
		if (LCK == 119) //upKey
		{
			possibleMove[actuall - 3] = 89;
		}
		else if (LCK == 80) //downKey
		{
			possibleMove[actuall + 3] = 89;
		}
		else if (LCK == 75) //leftKey
		{
			possibleMove[actuall - 1] = 89;
		}
		else if (LCK == 77) //rightKey
		{
			possibleMove[actuall + 1] = 89;
		}
		else;

		screenRefresh();
	}
	//pętla do rysowania planszy

}
// wed�ug moich za�o�e� w tym pliku b�dzie znajdowa� si� menu
// wraz ze "szkieletem" projektu
// funkcja main b�dzie wywo�ywa� kolejne funkcje z innych plik�w
void screenRefresh()
{
	Sleep(1000);
	system("CLS");

}

void boardVisuals()
{

}