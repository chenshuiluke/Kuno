#include "world.h"
void initializeWorld()
{
	cursorXPos = 0;
	cursorYPos = 0;
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
		int counter1=0;
		for(counter1 = 0; counter1 < WORLD_WIDTH-1; counter1++)
		{
			if(counter == cursorYPos && counter1 == cursorXPos)
			{
				printf("@");
			}
			else
			{
				printf("%c", world[counter][counter1]);
			}
		}
		puts("");
	}
}
void getInput()
{
	printf("Please enter the sequence of instructions you want to execute.\n");
	printf("You can enter up to five(5) instructions, excluding the spaces.\n");
	printf("Enter only 'h' if you want detailed help:\n");
	char instructions[11];
	memset(instructions, '\0', 10);
	fgets(instructions,10, stdin);
	
	if(!strcmp(instructions,"h") || instructions[0] == 'h')
	{
//		printHelp();
	}
	else
	{
		int counter = 0;
		for(counter = 0; counter < strlen(instructions); counter++)
		{
			switch(instructions[counter])
			{
				case MOVE_UP:
					puts("Move up");
					if(cursorYPos > 0)
						cursorYPos--;
				break;
				case MOVE_DOWN:
					puts("Move down");
					if(cursorYPos<WORLD_HEIGHT-1)
					cursorYPos++;
				break;
				case MOVE_LEFT:
					puts("Move left");
					if(cursorXPos > 0)
						cursorXPos--;
				break;
				case MOVE_RIGHT:
					puts("Move right");
					if(cursorXPos < WORLD_WIDTH-1);
						cursorXPos++;
				break;
				default:
					puts("Unknown command.");
				break;
			}
		}
	}
	wipe();
	printWorld();
	
}
