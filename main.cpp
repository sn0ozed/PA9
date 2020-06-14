// Completed Tasks
// Window Drawn
// Tetris Blocks Drawn
// Left, Right, Down, Up, and Spacebar events 
// Collision detection (edge of world, other blocks)
// Implement draw world with multiple blocks
// Timer to ensure blocks are always falling
// Block Rotation - uses collision detection

// Comments: All the auto functions and variables definedd outside the scope of main need to be defined in a class called TetrisGame


//test edit

#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

const int cell_size = 25;
const int widthCount = 10;
const int heightCount = 20;
int world[heightCount][widthCount] = {0};

const Color color_map[] = {
	Color::Green, Color::Blue, Color::Red, Color::Yellow,
	Color::White, Color::Magenta, Color::Cyan
};
// this array defines all of the shapes that we will use in the game
int tetrisBlock[7][4][4] = 
{
	1,0,0,0,
	1,0,0,0,
	1,0,0,0,
	1,0,0,0,

	1,0,0,0,
	1,1,0,0,
	0,1,0,0,
	0,0,0,0,

	0,1,0,0,
	1,1,0,0,
	1,0,0,0,
	0,0,0,0,

	1,1,0,0,
	1,1,0,0,
	0,0,0,0,
	0,0,0,0,

	1,0,0,0,
	1,1,0,0,
	1,0,0,0,
	0,0,0,0,

	1,0,0,0,
	1,0,0,0,
	1,1,0,0,
	0,0,0,0,

	0,1,0,0,
	0,1,0,0,
	1,1,0,0,
	0,0,0,0,
};


int main(void)
{
	RenderWindow window(VideoMode(widthCount * cell_size, heightCount * cell_size), "TETRIS");  /// creates the game window with title
	RectangleShape cell(Vector2f(cell_size, cell_size));

	int blockShape; // the shape of the block
	int cx; // current x position of block
	int cy; //current y position of the block


	auto newBlock = [&]()
	{
		blockShape = rand() % 7, cx = widthCount / 2, cy = 0;
	};
	newBlock();
	

	auto checkBlock = [&]()
	{
		for (int y = 0; y < 4; y++)for (int x = 0; x < 4; x++)
		{
			if (tetrisBlock[blockShape][y][x] == 0) continue;
			if (x + cx < 0 || x + cx >= widthCount || y + cy >= heightCount) return false; // hit wall
			if (world[cy + y][cx + x]) return false; // collision with world blocks
				
		}
		return true;
	};

	auto clearLine = [&]()
	{
		int to = heightCount - 1;
		//from bottom line to top
		for (int from = heightCount - 1; from >= 0; from--)
		{
			int count = 0;
			for (int x = 0; x < widthCount; x++) if (world[from][x])count++;
			//if the current line is not full, copy it(survived line)
			if (count < widthCount)
			{
				for (int x = 0; x < widthCount; x++)world[to][x] = world[from][x];
				to--;
			}
			//otherwise clear the line
		}
	};

	auto fallDown = [&]()
	{
		cy++;
		if (checkBlock() == false) // hit bottom
		{
			cy--;
			for (int y = 0; y < 4; y++)for (int x = 0; x < 4;x++)
			{
				if (tetrisBlock[blockShape][y][x])
				{
					world[cy + y][cx + x] = blockShape + 1; // +! is for avoidin zero
				}

			//	clearLine();
				//start new block
				newBlock();
				return false;
			}

			return true;
		}
	};


	auto rotateBlock = [&]()
	{
		int len = 0; //check block size to make sure it can rotate
		for (int y = 0; y < 4; y++)for (int x = 0; x < 4; x++)
			if (tetrisBlock[blockShape][y][x]) len = max(max(x, y) + 1, len);

		int d[4][4] = { 0 };
		//rotate counter clockwise 90 degrees
		for (int y = 0; y < 4; y++)for (int x = 0; x < 4; x++)
			if (tetrisBlock[blockShape][y][x]) d[len - 1 - x][y] = 1;
		for (int y = 0; y < 4; y++)for (int x = 0; x < 4; x++)
			tetrisBlock[blockShape][y][x] = d[y][x];
	};

	Clock clock;
	while (window.isOpen())
	{
		static float prev = clock.getElapsedTime().asSeconds();
		if (clock.getElapsedTime().asSeconds() - prev >= 0.5)
		{
			prev = clock.getElapsedTime().asSeconds();
			fallDown();
		}
		Event tetris;
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
				}
				else if (tetris.key.code == Keyboard::Space)
				{
					while (fallDown() == true);
				}
			}
		}
		window.clear();

		auto drawWorld = [&]()
		{
			for (int y = 0; y < heightCount; y++)for (int x = 0; x < 4;x++)
				if (world[y][x])
				{
					cell.setFillColor(color_map[world[y][x] - 1]);
					cell.setPosition(Vector2f(x * cell_size, y * cell_size));
					window.draw(cell);
				}
		};
		drawWorld();

		
		//this function can use all the variables defined outside of the scope of main; like kind, cx, cy
		auto drawBlock = [&]()
		{
			cell.setFillColor(color_map[blockShape]);
			for (int y = 0; y < 4; y++)for (int x = 0; x < 4; x++)
				if (tetrisBlock[blockShape][y][x])
				{
					cell.setPosition(Vector2f(cx + x) * cell_size, (cy + y) * cell_size);
					window.draw(cell);
				}
		};


		drawBlock(); //calling the lambda function
		window.display();

	}
	return 0;
}