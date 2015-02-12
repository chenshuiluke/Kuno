#ifndef WORLD_H
#define WORLD_H
	#include <string.h>
	#include <stdio.h>
	
	//World dimensions
	#define WORLD_WIDTH 80
	#define WORLD_HEIGHT 20
	
	//World block types
	#define FLAT_LAND '-'
	
	//Instructions
	#define MOVE_UP 'w'
	#define MOVE_DOWN 's'
	#define MOVE_RIGHT 'd'
	#define MOVE_LEFT 'a'
	
	char world[WORLD_HEIGHT][WORLD_WIDTH+1]; //Space for null terminator
	void initializeWorld();
	void printWorld();
	void getInput();
	void printHelp();
#endif
