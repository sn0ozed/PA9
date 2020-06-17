#include "Game_Logic.h"


void Game_Logic::newBlock()
{
	blockShape = rand() % 7, cx = widthCount / 2, cy = 0;
	point_num++;
	dur -= .001;
}

void Game_Logic::newBlock(int player)
{
	if (player == 1)
	{
		blockShape = rand() % 7, cx = widthCount / 2, cy = 0;
		point_num++;
		dur -= .001;
	}
	else {
		blockShapForClient = rand() % 7, cxForClient = widthCount / 2, cyForClient = 0;
		point_num_client++;
		durForClient -= .001;
	}
}
bool Game_Logic::checkBlock(int player)
{
	if (player == 1)
	{
		for (int y = 0; y < 4; y++)for (int x = 0; x < 4; x++)
		{
			if (tetrisBlock[blockShape][y][x] == 0) continue;
			if (x + cx < 0 || x + cx >= widthCount || y + cy >= heightCount) return false; // hit wall
			if (world[cy + y][cx + x]) return false; // collision with world blocks
		}
		return true;
	}
	else
	{
		for (int y = 0; y < 4; y++)for (int x = 0; x < 4; x++)
		{
			if (tetrisBlock[blockShapForClient][y][x] == 0) continue;
			if (x + cxForClient < 0 || x + cxForClient >= widthCount || y + cyForClient >= heightCount) return false; // hit wall
			if (worldForClient[cyForClient + y][cxForClient + x]) return false; // collision with world blocks
		}
		return true;
	}

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

void Game_Logic::clearLine(int player)
{
	int to = heightCount - 1;
	//from bottom line to top
	for (int from = heightCount - 1; from >= 0; from--)
	{
		int count = 0;
		for (int x = 0; x < widthCount; x++) if (worldForClient[from][x])count++;
		//if the current line is not full, copy it(survived line)
		if (count < widthCount)
		{
			for (int x = 0; x < widthCount; x++)worldForClient[to][x] = worldForClient[from][x];
			to--;

			if (cyForClient == 0)
				GameOverForClient = 1;
		}
		//otherwise clear the line
	}
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
bool Game_Logic::fallDown(int player)
{
	if (player == 1)
	{
		cy++;
		if (checkBlock(player) == false) // hit bottom
		{
			cy--;
			for (int y = 0; y < 4; y++)for (int x = 0; x < 4; x++)
				if (tetrisBlock[blockShape][y][x])
				{
					world[cy + y][cx + x] = blockShape + 1; // +! is for avoidin zero
				}

			clearLine();
			//start new block
			newBlock(player);
			return false;
		}
		return true;
	}
	else {
		cyForClient++;
		if (checkBlock(player) == false) // hit bottom
		{
			cyForClient--;
			for (int y = 0; y < 4; y++)for (int x = 0; x < 4; x++)
				if (tetrisBlock[blockShapForClient][y][x])
				{
					worldForClient[cyForClient + y][cxForClient + x] = blockShapForClient + 1; // +! is for avoidin zero
				}

			clearLine(player);
			//start new block
			newBlock(player);
			return false;
		}
		return true;
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


void Game_Logic::rotateBlock(int player)
{
	int len = 0; //check block size to make sure it can rotate
	for (int y = 0; y < 4; y++)for (int x = 0; x < 4; x++)
		if (tetrisBlock[blockShapForClient][y][x]) len = max(max(x, y) + 1, len);

	int d[4][4] = { 0 };
	//rotate counter clockwise 90 degrees
	for (int y = 0; y < 4; y++)for (int x = 0; x < 4; x++)
		if (tetrisBlock[blockShapForClient][y][x]) d[len - 1 - x][y] = 1;
	for (int y = 0; y < 4; y++)for (int x = 0; x < 4; x++)
		tetrisBlock[blockShapForClient][y][x] = d[y][x];
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