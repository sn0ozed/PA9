#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include "Game_Logic.h"
#include "Main_Menu.h"

class Game_Window : public Game_Logic, Main_Menu
{
private:
	RenderWindow window;
	RectangleShape cell;
	Music music;
	Text points1, points2, game_over, player1, player2;
	Font font;
	Clock clock;
	Event tetris;

public:

	Game_Window() : Game_Logic(), Main_Menu()
	{
	}

	void tick(int player);

	void tick();
	void input(int player);
	void input();
	void drawWorld(int);
	void drawBlock(int);
	void drawPoints(int);
	void drawWorld(int, int, int);
	void drawBlock(int, int, int);
	void onePlayerGame();
	void twoPlayerGame();

	void gameLoop();

};


#endif