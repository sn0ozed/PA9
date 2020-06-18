#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

/*
Game logic is controling the game including display and control
*/
class Game_Logic
{
protected:
	static const int cell_size = 25; //the size of cell of block 
	static const int widthCount = 10;//there are 10 cells in the wide
	static const int heightCount = 20;// there are 20 cells in the height
	int world[heightCount][widthCount] = { 0 };//the whole map for the block position for player1
	int worldForClient[heightCount][widthCount] = { 0 };// hte whole map for the block position for player2

	//all colors of block
	const Color color_map[8] = {
	Color::Green, Color::Blue, Color::Red, Color::Yellow,
	Color(250, 150, 100), Color::Magenta, Color::Cyan
	};

	//attribute for player1
	int blockShape; // the shape of the block
	int cx; // current x position of block
	int cy; //current y position of the block
	int point_num; //curretn number of points
	int GameOver;//flag for game over 
	float dur; //duration for block to fall

	//attribute for player2
	int blockShapForClient;// the shape of the block
	int cxForClient;// current x position of block
	int cyForClient;//current y position of the block
	int point_num_client;//curretn number of points
	int GameOverForClient;//flag for game over 
	float durForClient;//duration for block to fall

	//all shapes of the block
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
		newBlock();//create first block for player1
		newBlock(2);//create first block for player2
		//init point num
		point_num = 0;
		point_num_client = 0;
		//init game over flag
		GameOver = 0;
		GameOverForClient = 0;
		//init duration of falling
		dur = 0.5;
		durForClient = 0.5;
	}
	//customer constructor
	Game_Logic(int block_shape, int x_pos, int y_pos, int points, int dura)
	{
		blockShape = block_shape;
		cx = x_pos;
		cy = y_pos;
		point_num = points;
		dur = dura;
	}

	//memeber functions

	//create new block
	void newBlock();
	//create new block with different player
	void newBlock(int player);
	//check block is fallen down or close to the bind with different player
	bool checkBlock(int player);
	//check block is fallen down or close to the bind
	bool checkBlock();
	//clear the line if the line created by block with different player
	void clearLine(int player);
	//clear the line if the line created by block 
	void clearLine();
	//fall down the bloack with different player
	bool fallDown(int player);
	//fall down the bloack 
	bool fallDown();
	//rotate the block with different player
	void rotateBlock(int player);
	//rotate the block
	void rotateBlock();
	//get the points of player1
	virtual int getPoints();


};

#endif