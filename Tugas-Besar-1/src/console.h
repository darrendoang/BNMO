#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "ADT/array.h"
#include "ADT/mesinkarakter.h"
#include "ADT/mesinkata.h"
#include "ADT/mesinload.h"
#include "ADT/queue.h"
#include "ADT/arrayOfMap.h"
#include "GAME/rng.h"
#include "GAME/ddash.h"
#include "GAME/tictactoe.h"
#include "ADT/map.h"



void STARTGAME(Array *game , Array *gamehistory , TabMap *scoreboard);

void LOAD(Array *game, Array *gamehistory, TabMap *scoreboard , char *filename) ;

void SAVE(Array game , char * filename);

void CREATEGAME(Array* game);

void LISTGAME(Array *game);

void DELETEGAME(Array* game , Queue *antriangame);

void QUEUEGAME(Queue *antriangame, Array gamelist);

void PLAYGAME(Queue *antriangame , Array gamelist);

void SKIPGAME(Queue *queuegame, int input , Array gamelist);

void QUIT();

void HELP();