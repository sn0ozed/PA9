#ifndef MAIN_MENU_H //start if
#define MAIN_MENU_H

//Includes
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>


//using namespace decs
using namespace sf;
using namespace std;

//Main_Menu class
class Main_Menu
{
protected: 
	int menu_sel; //user selection
	enum Cursor { FIRST }; //enumerator 
	RenderWindow window; //render tetris game window
	RectangleShape option[3]; //render block shape
	Event menu; // menu apperance
	Texture background; //2d image render for surface
	Sprite S1; //moveable object 
	Font font;// needed to render text in window
	Text singlePlayer, multiPlayer, exit; // text dispaly for user options
	string host_ad, client_ad; //host or client 
	unsigned short port; //port access

public:
	Main_Menu()
	{
		menu_sel = 0; //user select to zero
		font.loadFromFile("VT323-Regular.ttf"); //load text from file
		background.loadFromFile("Tetris Background.jpg"); //load tetris background image from file
		S1.setTexture(background); // set tetris background as window texture

		S1.setScale(Vector2f(.24, .325)); //entity transformer

		singlePlayer.setFont(font); //font from file to single player
		multiPlayer.setFont(font); //font from file to multiplayer
		exit.setFont(font); //from from file to exit

		singlePlayer.setString("Single Player"); //display exit font in window
		multiPlayer.setString("Two Player"); //display two player font in window
		exit.setString("Exit Game"); //display exit game in window

		singlePlayer.setCharacterSize(25); //set text size to 25 for singleplayer
		multiPlayer.setCharacterSize(25); // set text tize to 25 for multiplayer
		exit.setCharacterSize(25); //set text size to 25 for exit

		singlePlayer.setFillColor(Color::Black); // color fill for singleplayer "button" region
		multiPlayer.setFillColor(Color::Black); // color fill black for multiplayer "button region
		exit.setFillColor(Color::Black); // color fill black for exit "button" region

		singlePlayer.setPosition(Vector2f(370, 440)); //set singleplayer block at position (370, 440) in window
		multiPlayer.setPosition(Vector2f(385, 490)); //set multiplayer block at position (385, 490) in window
		exit.setPosition(Vector2f(390, 540)); //set exit block at position (390, 540) in window

		for (int i = 0; i < 3; i++) //loop for positioning
		{
			option[i].setSize(Vector2f(180, 40));
			option[i].setPosition(350, i * 50 + 440);
		}
	}

	//function calls for menu
	int twoPlayerMenu();
	void hostMenu();
	void joinMenu();
	int MainMenu();
	int menuLoop();




};

#endif //end if

