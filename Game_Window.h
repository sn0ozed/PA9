/*******************************************************************************************
* Programmer: Barnwell, Padgett, Terry, Ye													*
* Class: CptS 122, Summer, 2020; Lab Section 1												*
* Programming Assignment: PA 6																*
* Date: June 17, 2020																		*
* Description: This program runs a graphic application of the video game Tetris	with added  *
*colored blocks, point system, 1 and 2 player game modes, and demonstrates class inheritance*
*and polymorphism.																			*
********************************************************************************************/

#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

//included header files
#include "Game_Logic.h"
#include "Main_Menu.h"

//class inherited from Game_Logic and Main_Menu class
class Game_Window : public Game_Logic, Main_Menu
{
private:

	//private variables of the Game_Window Class

	//game window
	RenderWindow window;
	//cell that makes up blocks and grid for game
	RectangleShape cell;
	//music for the game
	Music music;
	//text for displaying points, game over, and player
	Text points1, points2, game_over, player1, player2;
	//font used in the game
	Font font;
	//clock varible to help run the game
	Clock clock;
	//event varible for tetrisS
	Event tetris;

public:
	//public functions of Game_Window class

	//initial constuctor for the game window, that also starts the construction
	//of both Game_logic and Main_Menu class
	Game_Window() : Game_Logic(), Main_Menu()
	{
	}

	//Function for keeping track of tick speed and regulating along with fall speed of blocks
	void tick(int player);
	void tick();
	//Function for getting user input during the game
	void input(int player);
	void input();
	//polymorphic function of getPoints found in Game_Logic to aquire specific points for a player
	virtual int getPoints(int);
	//drawWorld draws the grid layout for the tetris blocks to move on and get stored in place if landed
	void drawWorld(int);
	//drawBlock draws the teris blocks as they move through the game grid
	void drawBlock(int);
	//drawPoints displays the player points and player on the screen
	void drawPoints(int);
	//specialized drawWorld for 2 player
	void drawWorld(int, int, int);
	//specialized drawBlock for 2 player
	void drawBlock(int, int, int);
	//game loop for a 1 person game play
	void onePlayerGame();
	//game loop for a 2 player game play
	void twoPlayerGame();

	//main game loop that runs the entire game
	void gameLoop();

};


#endif