#include "world.h"
#include "menu.h"
void initializeWorld()
{
	int counter = 0;
	for(counter = 0; counter < WORLD_HEIGHT; counter++)
	{
		int counter2 = 0;
		for(counter2 = 0; counter2 < WORLD_WIDTH; counter2++)
		{
			world[counter][counter2].type = FLAT_LAND;
			world[counter][counter2].movementCost = 1;
			world[counter][counter2].defense = 10;
		}
	}
}
void printWorld(player currentPlayer)
{
	int counter = 0;
	for(counter = 0; counter < WORLD_HEIGHT; counter++)
	{
		int counter1=0;
		for(counter1 = 0; counter1 < WORLD_WIDTH-1; counter1++)
		{
			if(counter == currentPlayer.cursorYPos && counter1 == currentPlayer.cursorXPos)
			{
				printf("@");
			}
			else
			{
				printf("%c", world[counter][counter1].type);
			}
		}
		puts("");
	}
}
void getInput(player * currentPlayer)
{
	wipe();
	printPlayerInfo(currentPlayer->playerName);//player.playerName
	char stringInfo[10];
	memset(stringInfo, '\0', 9);
	sprintf(stringInfo,"%d", currentPlayer->gold);
	printPlayerInfo(stringInfo);
	printWorld(*currentPlayer);
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
					if(currentPlayer->cursorYPos > 0)
					{
						printToMessages("Move up");
						currentPlayer->cursorYPos--;
						numProcessed++;	
					}
					else
					{
						printToMessages("You can't move any further up.");
					}
				break;
				case MOVE_DOWN:
					if(currentPlayer->cursorYPos<WORLD_HEIGHT-1)
					{
						printToMessages("Move down");
						currentPlayer->cursorYPos++;
						numProcessed++;
					}
					else
					{
						printToMessages("You can't move any further down.");
					}
				break;
				case MOVE_LEFT:
					if(currentPlayer->cursorXPos > 0)
					{
						printToMessages("Move left");
						currentPlayer->cursorXPos--;
						numProcessed++;
					}
					else
					{
						printToMessages("You can't move further to the left.");
					}
				break;
				case MOVE_RIGHT:
					if(currentPlayer->cursorXPos < WORLD_WIDTH-1) 
					{	
						printToMessages("Move right");
						currentPlayer->cursorXPos++;
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
	printPlayerInfo(currentPlayer->playerName);
	memset(stringInfo, '\0', 9);
	sprintf(stringInfo,"%d", currentPlayer->gold);
	printPlayerInfo(stringInfo);
	wipe();
	printWorld(*currentPlayer);
	releaseBuffer();		
	char c;
	printf("Press the enter key to continue...\n");
	scanf("%c", &c);
}

