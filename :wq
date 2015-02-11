#include "world.h"
void initializeWorld()
{
	int counter = 0;
	for(counter = 0; counter < WORLD_HEIGHT; counter++)
	{
		memset(world[counter], FLAT_LAND, WORLD_WIDTH-1);
		world[WORLD_HEIGHT][WORLD_WIDTH]='\0';
	}
}
void printWorld()
{
	int counter = 0;
	for(counter = 0; counter < WORLD_HEIGHT; counter++)
	{
		printf("%s\n", world[counter]);
	}
}
