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

//game tick that controls block fall and state of the game
void Game_Window::tick(int player)
{
	
	if (player == 1) //if player 1
	{
		static float prev = clock.getElapsedTime().asSeconds();
		if (clock.getElapsedTime().asSeconds() - prev >= dur)   //check for duration to update game
		{
			prev = clock.getElapsedTime().asSeconds();
			fallDown(player);
		}
	}
	else //if player 2
	{
		static float prev = clock.getElapsedTime().asSeconds();
		if (clock.getElapsedTime().asSeconds() - prev >= durForClient) //chack for duration to update game
		{
			prev = clock.getElapsedTime().asSeconds();
			fallDown(player);
		}
	}
}

//regular tick for controlling game
void Game_Window::tick()
{
	static float prev = clock.getElapsedTime().asSeconds();
	if (clock.getElapsedTime().asSeconds() - prev >= dur) //updates when game duration is met
	{
		prev = clock.getElapsedTime().asSeconds();
		fallDown();
	}
}

// 2 player game input
void Game_Window::input(int player)
{
	if (player == 1)
	{
		while (window.pollEvent(tetris))
		{
			if (tetris.type == Event::Closed) //close game
				window.close();
			if (tetris.type == Event::KeyPressed) // Moving the falling blocks left and right and down using the keyboard
			{
				if (tetris.key.code == Keyboard::Left) //move left
				{
					cx--;
					if (checkBlock(1) == false) cx++;
				}
				else if (tetris.key.code == Keyboard::Right) //move right
				{
					cx++;
					if (checkBlock(1) == false) cx--;
				}
				else if (tetris.key.code == Keyboard::Down) //fall down faster
				{
					fallDown(1);
				}
				else if (tetris.key.code == Keyboard::Up) // rotate if up is pressed
				{
					rotateBlock();
					if (checkBlock(1) == false)
					{
						rotateBlock(), rotateBlock(), rotateBlock();
					}
				}
				else if (tetris.key.code == Keyboard::Space) //drop block to bottom 
				{
					while (fallDown(1) == true);
				}
			}
		}
	}
	else {
		while (window.pollEvent(tetris))
		{
			if (tetris.type == Event::Closed) //close game
				window.close();
			if (tetris.type == Event::KeyPressed) // Moving the falling blocks left and right and down using the keyboard
			{
				if (tetris.key.code == Keyboard::Left) //move left
				{
					cx--;
					if (checkBlock(1) == false) cx++;
				}
				if (tetris.key.code == Keyboard::Right) //move right
				{
					cx++;
					if (checkBlock(1) == false) cx--;
				}
				if (tetris.key.code == Keyboard::Down) //drop block faster
				{
					fallDown(1);
				}
				if (tetris.key.code == Keyboard::Up) //rotate block
				{
					rotateBlock();
					if (checkBlock(1) == false)
					{
						rotateBlock(), rotateBlock(), rotateBlock();
					}
				}
				if (tetris.key.code == Keyboard::Space) //drop block to bottom
				{
					while (fallDown(1) == true);
				}
				if (tetris.key.code == Keyboard::A) //mov block to the left
				{
					cxForClient--;
					if (checkBlock(2) == false) cxForClient++;
				}
				if (tetris.key.code == Keyboard::D) //move block to the right
				{
					cxForClient++;
					if (checkBlock(2) == false) cxForClient--;
				}
				if (tetris.key.code == Keyboard::S) //move block down faster
				{
					fallDown(2);
				}
				if (tetris.key.code == Keyboard::W) //rotate block
				{
					rotateBlock(2);
					if (checkBlock(2) == false)
					{
						rotateBlock(2), rotateBlock(2), rotateBlock(2);
					}
				}
				if (tetris.key.code == Keyboard::Q) //drop block at the bottom
				{
					while (fallDown(2) == true);
				}
			}
		}
	}

}

//standard one person input
void Game_Window::input()
{
	while (window.pollEvent(tetris))
	{
		if (tetris.type == Event::Closed) window.close(); //close window
		if (tetris.type == Event::KeyPressed) // Moving the falling blocks left and right and down using th ekeyboard
		{
			if (tetris.key.code == Keyboard::Left) //move block to the left
			{
				cx--;
				if (checkBlock() == false) cx++;
			}
			else if (tetris.key.code == Keyboard::Right) //move block to the right
			{
				cx++;
				if (checkBlock() == false) cx--;
			}
			else if (tetris.key.code == Keyboard::Down) //move block down faster
			{
				fallDown();
			}
			else if (tetris.key.code == Keyboard::Up) //rotate block
			{
				rotateBlock();
				if (checkBlock() == false)
				{
					rotateBlock(), rotateBlock(), rotateBlock();
				}
			}
			else if (tetris.key.code == Keyboard::Space) //drop block all the way down
			{
				while (fallDown() == true);
			}
		}
	}
}

//get points for a specific player
int Game_Window::getPoints(int player)
{
	int answer = 0;

	switch (player)
	{
	case 1:
		answer = point_num;
		break;
	case 2:
		answer = point_num_client;
		break;
	}

	return answer;
}

//two player draw world
void Game_Window::drawWorld(int player, int moveX, int moveY)
{
	if (player == 1) //if player 1
	{
		for (int y = 0; y < heightCount; y++)
		{
			for (int x = 0; x < widthCount; x++)
			{
				if (world[y][x] >= 0)
				{
					cell.setFillColor(color_map[world[y][x] - 1]);
					cell.setOutlineColor(Color::Black);
					cell.setOutlineThickness(.9);
					cell.setPosition(Vector2f(x * cell_size, y * cell_size));
					cell.move(moveX, moveY);
					window.draw(cell);
				}
			}
		}
	}
	else //if player 2
	{
		for (int y = 0; y < heightCount; y++)
		{
			for (int x = 0; x < widthCount; x++)
			{
				if (world[y][x] >= 0)
				{
					cell.setFillColor(color_map[worldForClient[y][x] - 1]);
					cell.setOutlineColor(Color::Black);
					cell.setOutlineThickness(.9);
					cell.setPosition(Vector2f(x * cell_size, y * cell_size));
					cell.move(moveX, moveY);
					window.draw(cell);
				}
			}
		}
	}

}

//standard drawWorld
void Game_Window::drawWorld(int num)
{
	switch (num)
	{
	case 1: //if player 1
		for (int y = 0; y < heightCount; y++)
		{
			for (int x = 0; x < widthCount; x++)
			{
				if (world[y][x] >= 0)
				{
					cell.setFillColor(color_map[world[y][x] - 1]);
					cell.setOutlineColor(Color::Black);
					cell.setOutlineThickness(.9);
					cell.setPosition(Vector2f(x * cell_size, y * cell_size));
					cell.move(28, 121);
					window.draw(cell);
				}
			}
		}
		break;
	case 2: //this didn't get implemented for player 2
		for (int y = 0; y < heightCount; y++)
		{
			for (int x = 0; x < widthCount; x++)
			{
				if (world[y][x] >= 0)
				{
					cell.setFillColor(color_map[world[y][x] - 1]);
					cell.setOutlineColor(Color::Black);
					cell.setOutlineThickness(.9);
					cell.setPosition(Vector2f(x * cell_size, y * cell_size));
					cell.move(28, 121);
					window.draw(cell);
				}
			}
		}
		break;
	}

}

//draw block for 2 players
void Game_Window::drawBlock(int player, int moveX, int moveY)
{
	int curBlockShape, curcx, curcy;
	if (player == 1) //if player 1
	{
		curBlockShape = blockShape;
		curcx = cx;
		curcy = cy;

	}
	else //else player 2
	{
		curBlockShape = blockShapForClient;
		curcx = cxForClient;
		curcy = cyForClient;
	}
	cell.setFillColor(color_map[curBlockShape]);
	for (int y = 0; y < 4; y++) //draw the block
	{
		for (int x = 0; x < 4; x++)
		{
			if (tetrisBlock[curBlockShape][y][x])
			{
				cell.setPosition(Vector2f((curcx + x) * cell_size, (curcy + y) * cell_size));
				cell.setOutlineColor(Color::Black);
				cell.setOutlineThickness(1);
				cell.move(moveX, moveY);
				window.draw(cell);
			}
		}
	}


}

//standard drawblock
void Game_Window::drawBlock(int num)
{
	switch (num)
	{
	case 1: //if player 1 draw block
		cell.setFillColor(color_map[blockShape]);
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				if (tetrisBlock[blockShape][y][x])
				{
					cell.setPosition(Vector2f((cx + x) * cell_size, (cy + y) * cell_size));
					cell.setOutlineColor(Color::Black);
					cell.setOutlineThickness(1);
					cell.move(28, 121);
					window.draw(cell);
				}
			}
		}
		break;
	case 2: //never got implemented if player 2 draw block
		cell.setFillColor(color_map[blockShape]);
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				if (tetrisBlock[blockShapForClient][y][x])
				{
					cell.setPosition(Vector2f((cxForClient + x) * cell_size, (cyForClient + y) * cell_size));
					cell.setOutlineColor(Color::Black);
					cell.setOutlineThickness(1);
					cell.move(28, 121);
					window.draw(cell);
				}
			}
		}
		break;
	}

}

//draw points unerversal for up to 2 players
void Game_Window::drawPoints(int num)
{
	switch (num)
	{
	case 1://if player 1 draw their points and player
		points1.setString(to_string(getPoints(1)));
		points1.setCharacterSize(50);
		points1.setFillColor(Color::Red);
		points1.setPosition(Vector2f(300, 40));

		player1.setString("Player 1    Score: ");
		player1.setCharacterSize(40);
		player1.setFillColor(Color::Blue);
		player1.setPosition(Vector2f(10, 45));

		window.draw(points1);
		window.draw(player1);
		break;
	case 2: //if player 2 draw points and player
		points2.setString(to_string(getPoints(2)));
		points2.setCharacterSize(50);
		points2.setFillColor(Color::Red);
		points2.setPosition(Vector2f(300 + 300 + 150, 40));

		player2.setString("Player 2    Score: ");
		player2.setCharacterSize(40);
		player2.setFillColor(Color::Blue);
		player2.setPosition(Vector2f(10 + 300 + 150, 45));

		window.draw(points2);
		window.draw(player2);
		break;
	}

}

//one player game loop for a 1 person game
void Game_Window::onePlayerGame()
{
	//create the window
	window.create(VideoMode(900, 700), "TETRIS");
	cell.setSize(Vector2f(cell_size, cell_size));
	
	//set up the files for music, font, and text
	music.openFromFile("Korobeiniki.ogg");
	music.play();
	music.setLoop(true);

	font.loadFromFile("VT323-Regular.ttf");
	points1.setFont(font);
	game_over.setFont(font);
	player1.setFont(font);

	//open window and while it is open
	while (window.isOpen())
	{
		if (GameOver == 0) //if game is not over
		{
			tick(); //run tick
			input(); //get inputs

			window.clear(Color::White); //clear the screen white

			drawWorld(1); //draw the world
			drawBlock(1); //draw the tetris blocks
			drawPoints(1); //draw the points

			window.display(); //display the window
		}
		else if (GameOver == 1) //if game is over
		{
			input(); //get inputs

			window.clear(Color::White); //clear screen

			drawPoints(1); //draw the points
			drawWorld(1); //draw the world

			game_over.setString("Game Over"); //display game over
			game_over.setCharacterSize(40);
			game_over.setFillColor(Color::Red);
			game_over.setPosition(Vector2f(80, 630));

			window.draw(game_over); //draw gameover

			window.display(); //display window
		}
	}
}

//two player game loop for two people
void Game_Window::twoPlayerGame()
{
	//create window
	window.create(VideoMode(900, 700), "TETRIS");
	cell.setSize(Vector2f(cell_size, cell_size));

	//set up music, font, and text
	music.openFromFile("Korobeiniki.ogg");
	music.play();
	music.setLoop(true);

	font.loadFromFile("VT323-Regular.ttf");
	points1.setFont(font);
	game_over.setFont(font);
	player1.setFont(font);

	points2.setFont(font);
	player2.setFont(font);

	//open window and while window is open
	while (window.isOpen())
	{
		if (GameOver == 0 && GameOverForClient == 0) //if game is not over for both players
		{
			tick(1); //run tick for player 1
			input(2); //get inputs for both players
			tick(2); //run tick for player 2

			window.clear(Color::White); //clear the window white

			drawWorld(1); //draw world for player 1
			drawBlock(1); //draw blocks for player 1
			drawPoints(1); //draw points for player 1
			//show player 2
			drawWorld(2, 28 + cell_size * 10 + 200, 121); //draw world for player 2
			drawBlock(2, 28 + cell_size * 10 + 200, 121); //draw blocks for player 2
			drawPoints(2); //draw points for player 2
			window.display(); //display window
		}
		else if (GameOver == 1 || GameOverForClient == 1) //if game is over for either player
		{
			input(2); //get both player input

			window.clear(Color::White); //clear screen white

			//draw points and world for both players
			drawPoints(1); 
			drawWorld(1);

			drawWorld(2, 28 + cell_size * 10 + 200, 121);
			drawPoints(2);

			//Game over set up for text
			game_over.setString("Game Over");
			game_over.setCharacterSize(40);
			game_over.setFillColor(Color::Red);
			if (GameOver == 1) //player 1 gameover
			{
				game_over.setPosition(Vector2f(80, 630));
			}
			else if (GameOverForClient == 1) //player 2 gameover
			{
				game_over.setPosition(Vector2f(80 + 300 + 150, 630));
			}

			window.draw(game_over); //draw gameover

			window.display(); //display window
		}
	}
}


//main game loop running everything
void Game_Window::gameLoop()
{
	int selection;

	selection = menuLoop(); //selection from game menu

	switch (selection)
	{
	case 1:
		onePlayerGame(); //one player game
		break;
	case 2:
		twoPlayerGame(); //two player game
		break;
	case 3:		//exit game
		break; 
	}
}
