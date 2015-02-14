#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <string.h>
#define MENU_HEIGHT 5
#define MENU_WIDTH 80

extern int currentPrintingLine;
char menu[MENU_HEIGHT][MENU_WIDTH+1];

void printToMenu(char *);


#endif

