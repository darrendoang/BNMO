#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "ADT/array.h"
#include "ADT/mesinkarakter.h"
#include "ADT/mesinkata.h"
#include "ADT/mesinload.h"
#include "ADT/queue.h"
#include "ADT/map.h"
#include "ADT/arrayOfMap.h"
#include "ADT/stackhistory.h"
#include "GAME/rng.h"
#include "GAME/ddash.h"
#include "GAME/tictactoe.h"


void STARTGAME(Array *game , TabMap *scoreboard);

void LOAD(Array *game, HistoryStack *gamehistory , TabMap *scoreboard,  char *filename);

void SAVE(Array game, HistoryStack gamehistory, TabMap scoreboard, char *file);

void CREATEGAME(Array* game , TabMap *scoreboard);

void LISTGAME(Array *game);

void DELETEGAME(Array* game , Queue *antriangame , TabMap *scoreboard);

void QUEUEGAME(Queue *antriangame, Array gamelist);

void PLAYGAME(Queue *antriangame , Array gamelist);

void SKIPGAME(Queue *queuegame, int input , Array gamelist);

void QUIT();

void HELP();