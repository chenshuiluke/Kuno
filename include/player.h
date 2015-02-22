#ifndef PLAYER_H
#define PLAYER_H
#include <yaml.h>
#include "utilities.h"
#include <stdio.h>
char playerName[21];

//Defines player types

#define HUMAN 'h'
#define COMPUTER 'c'
#define NETWORK_PLAYER 'n'
typedef struct user
{
	char playerName[21];
	int numberOfUnits;
	int gold;
	char type;
	int cursorXPos;
	int cursorYPos;
	
}player;
void getPlayerName();
#endif
