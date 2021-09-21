#include "../inc/Game.h"
Game::Game()
{
}
void Game::reset_board()
{
	game_board.reset();
}

void Game::reset_game()
{
	player_one_points = 0;
	player_two_points = 0;
	game_board.reset();
}

void Game::print_board()
{
	game_board.start();
}

void Game::load_game()
{
	game_board.load_possition();
	game_board.start();
}
