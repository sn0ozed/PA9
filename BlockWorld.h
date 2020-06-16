#ifndef BLOCKWORLD_H
#define BLOCKWORLD_H

#include "Points.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include<sstream>

using namespace std;
using namespace sf;

class BlockWorld : public Points
{
private:

	int cSize;
	int width;
	int height;
	RenderWindow window;
	RectangleShape cell;
	

public:

	int world[20][10] = { 0 };
	int block[7][4][4] =
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

	const Color map[7] = {Color::Green, Color::Blue, Color::Red, Color::Yellow, Color::White, Color::Magenta, Color::Cyan};

	int blockType; // block kind
	int currentX; // current x position of block
	int currentY; // current y poisiton of block
	
	

	BlockWorld()
	{		
		currentX = 0;
		currentY = 0;
		cSize = 40;
		height = 20;
		width = 10;
		RenderWindow window(VideoMode(width * cSize, height * cSize), "TETRIS");
		RectangleShape cell(Vector2f(cSize, cSize));
	}

	

	int getWidth()
	{
		return width;
	};
	int getHeight()
	{
		return height;
	};
	int getCellSize()
	{
		return cSize;
	}
	

	virtual void newBlock();
	virtual bool checkBlock();
	virtual void clearLine();
	virtual bool fallDown();
	virtual void rotate();
	virtual void drawBlock();
	virtual void drawWorld();
	
	virtual void playGame();
};
#endif // !BLOCKWORLD_H
