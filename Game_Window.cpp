#include "Game_Window.h"

void Game_Window::tick(int player)
{
	if (player == 1)
	{
		static float prev = clock.getElapsedTime().asSeconds();
		if (clock.getElapsedTime().asSeconds() - prev >= dur)
		{
			prev = clock.getElapsedTime().asSeconds();
			fallDown(player);
		}
	}
	else 
	{
		static float prev = clock.getElapsedTime().asSeconds();
		if (clock.getElapsedTime().asSeconds() - prev >= durForClient)
		{
			prev = clock.getElapsedTime().asSeconds();
			fallDown(player);
		}
	}
}
void Game_Window::tick()
{
	static float prev = clock.getElapsedTime().asSeconds();
	if (clock.getElapsedTime().asSeconds() - prev >= dur)
	{
		prev = clock.getElapsedTime().asSeconds();
		fallDown();
	}
}
void Game_Window::input(int player)
{
	if (player == 1)
	{
		while (window.pollEvent(tetris))
		{
			if (tetris.type == Event::Closed) window.close();
			if (tetris.type == Event::KeyPressed) // Moving the falling blocks left and right and down using th ekeyboard
			{
				if (tetris.key.code == Keyboard::Left)
				{
					cx--;
					if (checkBlock(1) == false) cx++;
				}
				else if (tetris.key.code == Keyboard::Right)
				{
					cx++;
					if (checkBlock(1) == false) cx--;
				}
				else if (tetris.key.code == Keyboard::Down)
				{
					fallDown(1);
				}
				else if (tetris.key.code == Keyboard::Up)
				{
					rotateBlock();
					if (checkBlock(1) == false)
					{
						rotateBlock(), rotateBlock(), rotateBlock();
					}
				}
				else if (tetris.key.code == Keyboard::Space)
				{
					while (fallDown(1) == true);
				}
			}
		}
	}
	else {
		while (window.pollEvent(tetris))
		{
			if (tetris.type == Event::Closed) window.close();
			if (tetris.type == Event::KeyPressed) // Moving the falling blocks left and right and down using th ekeyboard
			{
				if (tetris.key.code == Keyboard::Left)
				{
					cx--;
					if (checkBlock(1) == false) cx++;
				}
				else if (tetris.key.code == Keyboard::Right)
				{
					cx++;
					if (checkBlock(1) == false) cx--;
				}
				else if (tetris.key.code == Keyboard::Down)
				{
					fallDown(1);
				}
				else if (tetris.key.code == Keyboard::Up)
				{
					rotateBlock();
					if (checkBlock(1) == false)
					{
						rotateBlock(), rotateBlock(), rotateBlock();
					}
				}
				else if (tetris.key.code == Keyboard::Space)
				{
					while (fallDown(1) == true);
				}
				else if (tetris.key.code == Keyboard::A)
				{
					cxForClient--;
					if (checkBlock(2) == false) cxForClient++;
				}
				else if (tetris.key.code == Keyboard::D)
				{
					cxForClient++;
					if (checkBlock(2) == false) cxForClient--;
				}
				else if (tetris.key.code == Keyboard::S)
				{
					fallDown(2);
				}
				else if (tetris.key.code == Keyboard::W)
				{
					rotateBlock(2);
					if (checkBlock(2) == false)
					{
						rotateBlock(2), rotateBlock(2), rotateBlock(2);
					}
				}
			}
		}
	}
	
}
void Game_Window::input()
{
	while (window.pollEvent(tetris))
	{
		if (tetris.type == Event::Closed) window.close();
		if (tetris.type == Event::KeyPressed) // Moving the falling blocks left and right and down using th ekeyboard
		{
			if (tetris.key.code == Keyboard::Left)
			{
				cx--;
				if (checkBlock() == false) cx++;
			}
			else if (tetris.key.code == Keyboard::Right)
			{
				cx++;
				if (checkBlock() == false) cx--;
			}
			else if (tetris.key.code == Keyboard::Down)
			{
				fallDown();
			}
			else if (tetris.key.code == Keyboard::Up)
			{
				rotateBlock();
				if (checkBlock() == false)
				{
					rotateBlock(), rotateBlock(), rotateBlock();
				}
			}
			else if (tetris.key.code == Keyboard::Space)
			{
				while (fallDown() == true);
			}
		}
	}
}
void Game_Window::drawWorld(int player,int moveX, int moveY)
{
	if (player == 1)
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
	else 
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

void Game_Window::drawWorld(int num)
{
	switch (num)
	{
	case 1:
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
	case 2:
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

void Game_Window::drawBlock(int player, int moveX,int moveY)
{
	int curBlockShape,curcx,curcy;
	if (player == 1)
	{
		curBlockShape = blockShape;
		curcx = cx;
		curcy = cy;

	}
	else
	{
		curBlockShape = blockShapForClient;
		curcx = cxForClient;
		curcy = cyForClient;
	}
	cell.setFillColor(color_map[curBlockShape]);
	for (int y = 0; y < 4; y++)
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

void Game_Window::drawBlock(int num)
{
	switch (num)
	{
	case 1:
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
	case 2:
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

void Game_Window::drawPoints(int num)
{
	switch (num)
	{
	case 1:
		points1.setString(to_string(point_num));
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
	case 2:
		points2.setString(to_string(point_num_client));
		points2.setCharacterSize(50);
		points2.setFillColor(Color::Red);
		points2.setPosition(Vector2f(300+300+150, 40));

		player2.setString("Player 2    Score: ");
		player2.setCharacterSize(40);
		player2.setFillColor(Color::Blue);
		player2.setPosition(Vector2f(10+300+150, 45));

		window.draw(points2);
		window.draw(player2);
		break;
	}

}

void Game_Window::onePlayerGame()
{
	window.create(VideoMode(900, 700), "TETRIS");
	cell.setSize(Vector2f(cell_size, cell_size));

	music.openFromFile("Korobeiniki.ogg");
	music.play();
	music.setLoop(true);

	font.loadFromFile("VT323-Regular.ttf");
	points1.setFont(font);
	game_over.setFont(font);
	player1.setFont(font);

	while (window.isOpen())
	{
		if (GameOver == 0)
		{
			tick();
			input();

			window.clear(Color::White);

			drawWorld(1);
			drawBlock(1);
			drawPoints(1);

			window.display();
		}
		else if (GameOver == 1)
		{
			input();

			window.clear(Color::White);

			drawPoints(1);
			drawWorld(1);

			game_over.setString("Game Over");
			game_over.setCharacterSize(40);
			game_over.setFillColor(Color::Red);
			game_over.setPosition(Vector2f(80, 630));

			window.draw(game_over);

			window.display();
		}
	}
}

void Game_Window::twoPlayerGame()
{
	window.create(VideoMode(900, 700), "TETRIS");
	cell.setSize(Vector2f(cell_size, cell_size));

	music.openFromFile("Korobeiniki.ogg");
	music.play();
	music.setLoop(true);

	font.loadFromFile("VT323-Regular.ttf");
	points1.setFont(font);
	game_over.setFont(font);
	player1.setFont(font);
	
	points2.setFont(font);
	player2.setFont(font);

	while (window.isOpen())
	{
		if (GameOver == 0 && GameOverForClient == 0)
		{
			tick(1);
			input(2);
			tick(2);
			
			window.clear(Color::White);
			drawWorld(1);
			drawBlock(1);
			drawPoints(1);
			//show player 2
			drawWorld(2,28 + cell_size * 10 + 200, 121);
			drawBlock(2, 28 + cell_size * 10 + 200, 121);
			drawPoints(2);
			window.display();
		}
		else if (GameOver == 1 || GameOverForClient == 1)
		{
			input(2);

			window.clear(Color::White);

			drawPoints(1);
			drawWorld(1);

			drawWorld(2, 28 + cell_size * 10 + 200, 121);
			drawPoints(2);

			game_over.setString("Game Over");
			game_over.setCharacterSize(40);
			game_over.setFillColor(Color::Red);
			if (GameOver == 1)
			{
				game_over.setPosition(Vector2f(80, 630));
			}
			else if(GameOverForClient == 1)
			{
				game_over.setPosition(Vector2f(80+300+150, 630));
			}

			window.draw(game_over);

			window.display();
		}
	}
}


void Game_Window::gameLoop()
{
	int selection;

	selection = menuLoop();

	switch (selection)
	{
	case 1:
		onePlayerGame();
		break;
	case 2:
		twoPlayerGame();
		break;
	case 3:
		break;
	}
}