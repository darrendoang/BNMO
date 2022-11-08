#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "ADT/array.h"
#include "ADT/mesinkarakter.h"
#include "ADT/mesinkata.h"
#include "ADT/mesinload.h"
<<<<<<< Updated upstream
#include "ADT/queue.h"
#include "ADT/stringcomp.h"
#include "GAME/rng.h"
=======
#include "ADT/stringcomp.h"
#include "GAME/rng.h"
#include "ADT/queue.h"
>>>>>>> Stashed changes


void STARTGAME();

void LOAD(Array *game, char *filename);

void SAVE(Array game , char * filename);

void CREATEGAME(Array* game);

void LISTGAME(Array *game);

void DELETEGAME(Array* game , Queue *antriangame);

void QUEUEGAME(Queue *antriangame, Array gamelist);

void PLAYGAME(Queue *antriangame , Array gamelist);

void SKIPGAME();

void QUIT();

void HELP();