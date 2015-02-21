#ifndef PLAYER_H
#define PLAYER_H
#include <yaml.h>
#include "utilities.h"
#include <stdio.h>
char playerName[21];
typedef struct user
{
	char playerName[21];
	int numberOfUnits;
	int gold;
}player;
void getPlayerName();
#endif
