/*******************************************************************************************
* Programmer: Barnwell, Padgett, Terry, Ye													*
* Class: CptS 122, Summer, 2020; Lab Section 1												*
* Programming Assignment: PA 6																*
* Date: June 17, 2020																		*
* Description: This program runs a graphic application of the video game Tetris	with added  *
*colored blocks, point system, 1 and 2 player game modes, and demonstrates class inheritance*
*and polymorphism.																			*
********************************************************************************************/

//included header file
#include "Game_Window.h"

//main loop of the game
int main()
{
	//set a random seed at the start of the program
	srand(time(0));

	//initialize the game
	Game_Window game;

	//game loop that runs the game mechanics
	game.gameLoop();

	//end of the program
	return 0;
}