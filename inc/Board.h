#pragma once
#include <iostream>
int boardSize = 3;
char possibleMove[9] = { 90,90,90,90,90,90,90,90,90 };
int boardStatusSaved[9] = { 1,2,3,4,5,6,7,8,9 };
int playerOnePoints;
int playerTwoPoints;
void screenRefresh();
void boardVisuals();
void Board(int boardSize)
