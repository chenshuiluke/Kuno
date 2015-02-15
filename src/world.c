#include "world.h"
#include "menu.h"
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
	printToMessages("Enter commands");
	releaseBuffer();
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
		int numProcessed = 0;
		for(counter = 0; counter < strlen(instructions)&&numProcessed < 5; counter++)
		{
				
			switch(instructions[counter])
			{
				case MOVE_UP:
					if(cursorYPos > 0)
					{
						printToMessages("Move up");
						cursorYPos--;
						numProcessed++;	
					}
					else
					{
						printToMessages("You can't move any further up.");
					}
				break;
				case MOVE_DOWN:
					if(cursorYPos<WORLD_HEIGHT-1)
					{
						printToMessages("Move down");
						cursorYPos++;
						numProcessed++;
					}
					else
					{
						printToMessages("You can't move any further down.");
					}
				break;
				case MOVE_LEFT:
					if(cursorXPos > 0)
					{
						printToMessages("Move left");
						cursorXPos--;
						numProcessed++;
					}
					else
					{
						printToMessages("You can't move further to the left.");
					}
				break;
				case MOVE_RIGHT:
					if(cursorXPos < WORLD_WIDTH-1) 
					{	
						printToMessages("Move right");
						cursorXPos++;
						numProcessed++;	
					}
					else
					{
						printToMessages("You can't move further to the right.");
					}
				break;
				case ' ':
			
				break;
				case '\n':
				break;
				default:
					printToMessages("Unknown command.");
				break;
			}
		}
	}
	wipe();
	printWorld();
	releaseBuffer();		
}

