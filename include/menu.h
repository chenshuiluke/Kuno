#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <string.h>
#define MENU_HEIGHT 5
#define MENU_WIDTH 80
#define MESSAGE_MENU_WIDTH 20
#define UNIT_INFO_WIDTH 20
#define PLAYER_INFO_WIDTH 20
extern int currentMessageLine;
extern int currentUnitInfoLine;
extern int currentPlayerInfoLine;
char messages[MENU_HEIGHT][MESSAGE_MENU_WIDTH+1];
char unitInfo[MENU_HEIGHT][UNIT_INFO_WIDTH+1];
char playerInfo[MENU_HEIGHT][PLAYER_INFO_WIDTH+1];

void printToMessages(char *);
void printUnitInfo(char *);
void printPlayerInfo(char *);
void addPadding(char *,  int);
void initializeMenu();
#endif

