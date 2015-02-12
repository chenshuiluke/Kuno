#include <stdio.h>
#include "world.h"
int main()
{
	setvbuf(stdin, NULL, _IONBF,0);
	initializeWorld();	
	printWorld();
	world[WORLD_HEIGHT][WORLD_WIDTH]='\0';
	getInput();
	return 0;
}
