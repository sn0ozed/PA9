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

void Game_Window::drawWorld()
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
				cell.move(28, 121);
				window.draw(cell);
			}
		}
	}
}

void Game_Window::drawBlock()
{
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
}

void Game_Window::drawPoints()
{
	points.setString(to_string(point_num));
	points.setCharacterSize(50);
	points.setFillColor(Color::Red);
	points.setPosition(Vector2f(300, 40));

	player.setString("Player 1    Score: ");
	player.setCharacterSize(40);
	player.setFillColor(Color::Blue);
	player.setPosition(Vector2f(10, 45));

	window.draw(points);
	window.draw(player);
}
