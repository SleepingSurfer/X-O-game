#include "../inc/Game.h"
Game::Game()
{
}
void Game::reset()
{
	player_one_points = 0;
	player_two_points = 0;
}

void Game::print_board()
{
	game_board.start();
}
