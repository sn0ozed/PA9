#include "Game_Window.h"


void Game_Window::tick()
{
	static float prev = clock.getElapsedTime().asSeconds();
	if (clock.getElapsedTime().asSeconds() - prev >= dur)
	{
		prev = clock.getElapsedTime().asSeconds();
		fallDown();
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
		break;
	case 3:
		break;
	}
}