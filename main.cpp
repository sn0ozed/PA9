#include "Game_Window.h"

int main()
{
	srand(time(0));

	Game_Window game;

	game.gameLoop();

	return 0;
}