#ifndef WORLD_H
#define WORLD_H
	#include <string.h>
	#include <stdio.h>
	#define WORLD_WIDTH 80
	#define WORLD_HEIGHT 20
	#define FLAT_LAND '-'
	char world[WORLD_HEIGHT][WORLD_WIDTH+1]; //Space for null terminator
	void initializeWorld();
	void printWorld();
#endif

