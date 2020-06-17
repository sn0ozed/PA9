#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;


class Game_Logic
{
protected:
	static const int cell_size = 25;
	static const int widthCount = 10;
	static const int heightCount = 20;
	int world[heightCount][widthCount] = { 0 };
	int worldForClient[heightCount][widthCount] = { 0 };

	const Color color_map[8] = {
	Color::Green, Color::Blue, Color::Red, Color::Yellow,
	Color(250, 150, 100), Color::Magenta, Color::Cyan
	};

	int blockShape; // the shape of the block
	int cx; // current x position of block
	int cy; //current y position of the block
	int point_num; //curretn number of points
	int GameOver;
	float dur; //duration for block to fall

	//attribute for player2
	int blockShapForClient;
	int cxForClient;
	int cyForClient;
	int point_num_client;
	int GameOverForClient;
	float durForClient;

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

public:

	//Constructor
	Game_Logic()
	{
		newBlock();
		newBlock(2);
		point_num = 0;
		point_num_client = 0;
		GameOver = 0;
		GameOverForClient = 0;
		dur = 0.5;
		durForClient = 0.5;
	}

	Game_Logic(int block_shape, int x_pos, int y_pos, int points, int dura)
	{
		blockShape = block_shape;
		cx = x_pos;
		cy = y_pos;
		point_num = points;
		dur = dura;
	}

	//memeber functions

	void newBlock();
	void newBlock(int player);
	bool checkBlock(int player);
	bool checkBlock();
	void clearLine(int player);
	void clearLine();
	bool fallDown(int player);
	bool fallDown();
	
	void rotateBlock(int player);

	void rotateBlock();

	virtual int getPoints();


};

#endif