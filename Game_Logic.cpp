#include "Game_Logic.h"


void Game_Logic::newBlock()
{
	blockShape = rand() % 7, cx = widthCount / 2, cy = 0;
	point_num++;
	dur -= .001;
}

bool Game_Logic::checkBlock()
{
	for (int y = 0; y < 4; y++)for (int x = 0; x < 4; x++)
	{
		if (tetrisBlock[blockShape][y][x] == 0) continue;
		if (x + cx < 0 || x + cx >= widthCount || y + cy >= heightCount) return false; // hit wall
		if (world[cy + y][cx + x]) return false; // collision with world blocks
	}
	return true;
}

void Game_Logic::clearLine()
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

			if (cy == 0)
				GameOver = 1;
		}
		//otherwise clear the line
	}
}

bool Game_Logic::fallDown()
{
	cy++;
	if (checkBlock() == false) // hit bottom
	{
		cy--;
		for (int y = 0; y < 4; y++)for (int x = 0; x < 4; x++)
			if (tetrisBlock[blockShape][y][x])
			{
				world[cy + y][cx + x] = blockShape + 1; // +! is for avoidin zero
			}

		clearLine();
		//start new block
		newBlock();
		return false;
	}
	return true;
}

void Game_Logic::rotateBlock()
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
}

int Game_Logic::getPoints()
{
	return point_num;
}