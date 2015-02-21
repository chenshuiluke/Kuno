#ifndef WORLD_H
#define WORLD_H
	#include <string.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include "menu.h"
	
	//World dimensions
	#define WORLD_WIDTH 80
	#define WORLD_HEIGHT 10
	
	//World block types
	#define FLAT_LAND '-'
	
	//Instructions
	#define MOVE_UP 'w'
	#define MOVE_DOWN 's'
	#define MOVE_RIGHT 'd'
	#define MOVE_LEFT 'a'
	#ifndef WIN32
	#define COMMAND "clear" //Clears a linux console screen
	#else
	#define COMMAND "cls" //Clears a windows console screen
	#endif
	 
	#define wipe() system( COMMAND )	
	int cursorXPos;
	int cursorYPos;
	

	typedef struct land
	{
		char type;
		int movementCost;
		int defense;
	}tile;
	tile world[WORLD_HEIGHT][WORLD_WIDTH+1]; //Space for null terminator
	void initializeWorld();
	void printWorld();
	void getInput();
	void printHelp();
#endif
