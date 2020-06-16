#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include "Game_Logic.h"

class Game_Window : public Game_Logic
{
private:
	RenderWindow window;
	RectangleShape cell;
	Music music;
	Text points, game_over, player;
	Font font;
	Clock clock;
	Event tetris;

public:
	
	Game_Window() : Game_Logic()
	{
		window.create(VideoMode(900, 700), "TETRIS");
		cell.setSize(Vector2f(cell_size, cell_size));
	}

	void tick();
	void input();
	void drawWorld();
	void drawBlock();
	void drawPoints();

	void gameLoop()
	{
		music.openFromFile("Korobeiniki.ogg");
		music.play();
		music.setLoop(true);

		font.loadFromFile("VT323-Regular.ttf");
		points.setFont(font);
		game_over.setFont(font);
		player.setFont(font);

		while (window.isOpen())
		{
			tick();
			input();

			window.clear(Color::White);

			drawWorld();
			drawBlock();
			drawPoints();

			/*if (cy == 0)
			{
				game_over.setString("Game Over");
				game_over.setCharacterSize(40);
				game_over.setFillColor(Color::Red);
				game_over.setPosition(Vector2f(10, 50));

				window.draw(game_over);
			}*/

			window.display();
		}
	}



};


#endif