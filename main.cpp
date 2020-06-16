//1. Create Game Window using SFML 
//2. Draw a cell
//3. Draw Tetris blocks 
//4. move left, right and down 
//5. Collisiton detection, Draw World, Timer, Next block
//6. block rotation 
//7. Space bar and line clear
// NEED TO:
// add audio library
// create networking PvP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "BlockWorld.h"
using namespace std;
using namespace sf;


int main(void)
{


	BlockWorld World;
	
	World.playGame();


	
	return 0;
}