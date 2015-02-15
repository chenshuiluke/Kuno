#include <stdio.h>
#include "world.h"
int main()
{
	initializeWorld();	
	initializeMenu();
	printWorld();
	getInput();
	return 0;
}
