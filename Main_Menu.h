#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Main_Menu
{
protected:
	int menu_sel;
	enum Cursor{FIRST};
	RenderWindow window;
	RectangleShape option[3];
	Event menu;
	Texture background;
	Sprite S1;
	Font font;
	Text singlePlayer, multiPlayer, exit;

public:
	Main_Menu()
	{
		menu_sel = 0;
		window.create(VideoMode(900, 700), "TETRIS");
		font.loadFromFile("VT323-Regular.ttf");
		background.loadFromFile("Tetris Background.jpg");
		S1.setTexture(background);

		S1.setScale(Vector2f(.24, .325));

		singlePlayer.setFont(font);
		multiPlayer.setFont(font);
		exit.setFont(font);

		singlePlayer.setString("Single Player");
		multiPlayer.setString("Two Player");
		exit.setString("Exit Game");

		singlePlayer.setCharacterSize(25);
		multiPlayer.setCharacterSize(25);
		exit.setCharacterSize(25);

		singlePlayer.setFillColor(Color::Black);
		multiPlayer.setFillColor(Color::Black);
		exit.setFillColor(Color::Black);
		
		singlePlayer.setPosition(Vector2f(370, 440));
		multiPlayer.setPosition(Vector2f(385, 490));
		exit.setPosition(Vector2f(390, 540));
		
		for (int i = 0; i < 3; i++)
		{
			option[i].setSize(Vector2f(180, 40));
			option[i].setPosition(350, i * 50 + 440);
		}
	}

	int menuLoop();


};


#endif