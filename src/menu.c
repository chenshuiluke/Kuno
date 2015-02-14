#include "menu.h"
int currentPrintingLine = 0;

void initializeMenu()
{
	int counter = 0;
	for(counter = 0; counter < MENU_HEIGHT; counter++)
	{
		memset(menu[counter], '\0', MENU_WIDTH);
	}
}
void printToMenu(char * string)
{
	if(strlen(string) > MENU_WIDTH-1)
	{
		puts("Line too large to print in menu.");
	}
	else
	{
		strcpy(menu[currentPrintingLine], string);
	}
	currentPrintingLine++;
}
void releaseBuffer()
{
	int counter = 0;
	for(counter = 0; counter < MENU_HEIGHT; counter++)
	{
		printf("%s\n", menu[counter]);
	}	
	initializeMenu();
}