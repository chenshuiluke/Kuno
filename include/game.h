#include "world.h"
#define BUY_UNIT 'b'
extern int numOfPlayers;

player allPlayers[10];
player humanPlayers[10];
player computerPlayers[10];

int numHumanPlayers;
int numCompPlayers;
void initializeEverything();
void nullInitializePlayers(player[]);
void createMainPlayer();
void createOtherHumanPlayers();
void createComputerPlayers();
void createAllPlayerArray();
void printAllPlayers();
void startGame();
