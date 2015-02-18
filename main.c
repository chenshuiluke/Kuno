
#include <stdio.h>
#include "world.h"
int main()
{
	initializeWorld();	
	initializeMenu();
	getPlayerName();
	printWorld();
	getInput();
	return 0;
}
