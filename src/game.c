#include "game.h"
int numOfPlayers = 0;
void initializeEverything()
{
	retry:
	numHumanPlayers = 0;
	numCompPlayers = 0;
	getPlayerName();
	createMainPlayer();
	createOtherHumanPlayers();
	createComputerPlayers();	
	if(numOfPlayers < 2)
	{
		wipe();
		puts("You didn't create enough players. Retry.");
		goto retry;
	}
	createAllPlayerArray();	
	printAllPlayers();
	initializeWorld();
	initializeMenu();
	startGame();
}
void createMainPlayer()
{
	strcpy(humanPlayers[0].playerName, playerName);
	humanPlayers[0].gold = 100;
	humanPlayers[0].numberOfUnits = 0;
	humanPlayers[0].type = HUMAN;
	numHumanPlayers++;
	numOfPlayers++;
}
void createOtherHumanPlayers()
{
	puts("The main human player has been created. Would you like to create more?[N/y]");
	char cont = 'N';
	scanf("%c",&cont);
	flush();
	
	while(tolower(cont) != 'n' && (numHumanPlayers + numCompPlayers) < 10)
	{
		char name[10];
		memset(name,'\0', 9);
		puts("Please enter the name.");
		scanf("%s", name);
		flush();
		strcpy(humanPlayers[numHumanPlayers].playerName, name);
		humanPlayers[numHumanPlayers].gold = 100;
		humanPlayers[numHumanPlayers].numberOfUnits = 0;
		humanPlayers[numHumanPlayers].type = HUMAN;
		numHumanPlayers++;
		numOfPlayers++;
		printf("Player %s has been created. Would you like to create another?[N/y]\n");
		cont = 'N';
		scanf("%c", &cont);
		flush();

	}
	
}
void createComputerPlayers()
{
	int numToCreate = 0;
	int count = 0;
	puts("How many computer players do you wanna make?");
	scanf("%d", &numToCreate);
	flush();
	for(count = 0; count < numToCreate && (numHumanPlayers + numCompPlayers)<10;count++)
	{
		memset(computerPlayers[numCompPlayers].playerName,'\0', 20);
		strcpy(computerPlayers[numCompPlayers].playerName,"AI");
		computerPlayers[numCompPlayers].gold = 100;
		computerPlayers[numCompPlayers].numberOfUnits = 0;
		computerPlayers[numCompPlayers].type = COMPUTER;
		numCompPlayers++;	
		numOfPlayers++;
		//puts("AI created!");
	}
}
void createAllPlayerArray()
{
	memcpy(allPlayers, humanPlayers, sizeof(player)*numHumanPlayers);
	memcpy(allPlayers+numHumanPlayers, computerPlayers, sizeof(player)*(numCompPlayers));	
}
void printAllPlayers()
{
	puts("Printing all players.");
	int counter = 0;
	printf("Number of Players:%d\n", numOfPlayers);
	for(counter = 0; counter <numOfPlayers; counter++)
		printf("%s %d %d\n", allPlayers[counter].playerName, allPlayers[counter].gold, allPlayers[counter].numberOfUnits);
}
void startGame()
{
	while(1)
	{
		int count = 0;
		for(count = 0; count < numOfPlayers; count++)
		{
			if(allPlayers[count].type == HUMAN)
			{
				getInput(allPlayers[count]);
				initializeMenu();
			}
			else
			{
				//computer does stuff...
			}
		}
	}
}
