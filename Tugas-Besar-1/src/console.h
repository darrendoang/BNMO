#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "ADT/array.h"
#include "ADT/mesinkarakter.h"
#include "ADT/mesinkata.h"
#include "ADT/mesinload.h"
#include "ADT/queue.h"
#include "GAME/rng.h"
#include "GAME/ddash.h"
#include "GAME/tictactoe.h"


void STARTGAME(Array *game);

void LOAD(Array *game, char *filename);

void SAVE(Array game , char * filename);

void CREATEGAME(Array* game);

void LISTGAME(Array *game);

void DELETEGAME(Array* game , Queue *antriangame);

void QUEUEGAME(Queue *antriangame, Array gamelist);

void PLAYGAME(Queue *antriangame , Array gamelist);

void SKIPGAME(Queue *queuegame, int input , Array gamelist);

void QUIT();

void HELP();