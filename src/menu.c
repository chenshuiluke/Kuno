#include "menu.h"
int currentMessageLine = 0;
int currentPlayerInfoLine = 0;
int currentUnitInfoLine = 0;
void initializeMenu()
{
	int counter = 0;
	for(counter = 0; counter < MENU_HEIGHT; counter++)
	{
		memset(messages[counter], '\0', MENU_WIDTH);
		memset(playerInfo[counter], '\0', PLAYER_INFO_WIDTH);
		memset(unitInfo[counter], '\0', UNIT_INFO_WIDTH);
	}
		printToMessages("N/A");
		printToMessages("N/A");
		printToMessages("N/A");
		printToMessages("N/A");
		printToMessages("N/A");

		printUnitInfo("N/A");
		printUnitInfo("N/A");
		printUnitInfo("N/A");
		printUnitInfo("N/A");
		printUnitInfo("N/A");

		printPlayerInfo("N/A");
		printPlayerInfo("N/A");
		printPlayerInfo("N/A");
		printPlayerInfo("N/A");
		printPlayerInfo("N/A");
}
void printToMessages(char * string)
{
	if(strlen(string) > MESSAGE_MENU_WIDTH-1)
	{
		puts("Line too large to print message");
	}
	else
	{
		if(currentMessageLine >= MENU_HEIGHT)
		{
			currentMessageLine = 0;
			strcpy(messages[currentMessageLine], string);
			addPadding(messages[currentMessageLine], MESSAGE_MENU_WIDTH);
		}
		else
		{
			strcpy(messages[currentMessageLine], string);
			addPadding(messages[currentMessageLine], MESSAGE_MENU_WIDTH);
		}
	}
	currentMessageLine++;
}
void printUnitInfo(char * string)
{
	if(strlen(string) > UNIT_INFO_WIDTH-1)
	{
		puts("Line too large to print unit info");
	}
	else
	{
		if(currentUnitInfoLine >= MENU_HEIGHT)
		{
			currentUnitInfoLine = 0;
			strcpy(unitInfo[currentUnitInfoLine], string);
			addPadding(unitInfo[currentUnitInfoLine], UNIT_INFO_WIDTH);
		}
		else
		{
			strcpy(unitInfo[currentUnitInfoLine], string);
			addPadding(unitInfo[currentUnitInfoLine], UNIT_INFO_WIDTH);
		}
	}
	currentUnitInfoLine++;
}
void printPlayerInfo(char * string)
{
	if(strlen(string) > PLAYER_INFO_WIDTH-1)
	{
		puts("Line too large to print player info");
	}
	else
	{
		if(currentPlayerInfoLine >= MENU_HEIGHT)
		{
			currentPlayerInfoLine = 0;
			strcpy(playerInfo[currentPlayerInfoLine], string);
			addPadding(playerInfo[currentPlayerInfoLine], PLAYER_INFO_WIDTH);
		}
		else
		{
			strcpy(playerInfo[currentPlayerInfoLine], string);
			addPadding(playerInfo[currentPlayerInfoLine], PLAYER_INFO_WIDTH);
		}
	}
	currentPlayerInfoLine++;
}
void releaseBuffer()
{
	int counter = 0;
	printf("MESSAGES            UNIT INFO           PLAYER INFO\n");
	for(counter = 0; counter < MENU_HEIGHT; counter++)
	{
		if(messages[counter][0] != '\0')
			printf("%s", messages[counter]);
		if(unitInfo[counter][0] != '\0')
			printf("%s", unitInfo[counter]);
		if(playerInfo[counter][0] != '\0')
			printf("%s", playerInfo[counter]);
		puts("");
	}	
	currentMessageLine=0;
	currentUnitInfoLine = 0;
	currentPlayerInfoLine = 0;
}
void addPadding(char * stringToPad,  int maxWidth)
{
	int difference = maxWidth - strlen(stringToPad);
	if(difference > 0)
	{
		int counter = 0;
		int currentPos = strlen(stringToPad);
		for(counter = 0; counter < difference && currentPos < maxWidth; counter++)
		{
			stringToPad[currentPos] = '-';
			currentPos++;
		}
	}
}
