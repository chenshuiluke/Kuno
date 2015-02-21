#include "world.h"
int numOfPlayers;

player allPlayers[10];
player humanPlayers[10];
player computerPlayers[10];

int numHumanPlayers;
int numCompPlayers;
int numOfPlayers;
void initializeEverything();
void nullInitializePlayers(player[]);
void createMainPlayer();
void createOtherHumanPlayers();
void createComputerPlayers();
void createAllPlayerArray();
void printAllPlayers();
void startGame();
