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
void getInput()
{
	printf("Please enter the sequence of instructions you want to execute.\n");
	printf("You can enter up to five(5) instructions, excluding the spaces.\n");
	printf("Enter only 'h' if you want detailed help:\n");
	char temp[11];
	memset(temp, '\0', 10);
	fgets(temp,10, stdin);
	
	if(!strcmp(temp,"h") || temp[0] == 'h')
	{
//		printHelp();
	}
	else
	{
		char * instructions = strtok(temp, " ");
		while(instructions != NULL)
		{
			switch(instructions[0])
			{
				case MOVE_UP:
					puts("Move up");
				break;
				case MOVE_DOWN:
					puts("Move down");
				break;
				case MOVE_LEFT:
					puts("Move left");
				break;
				case MOVE_RIGHT:
					puts("Move right");
				break;
				default:
					puts("Unknown command.");
				break;
			}
			instructions = strtok(NULL, " ");
		}
	}
	
}
