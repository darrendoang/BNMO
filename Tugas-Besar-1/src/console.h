#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "ADT/array.h"
#include "ADT/mesinkarakter.h"
#include "ADT/mesinkata.h"
#include "ADT/mesinload.h"
<<<<<<< HEAD
#include "ADT/stringcomp.h"
=======
#include "ADT/queue.h"
#include "ADT/stringcomp.h"
#include "GAME/rng.h"
>>>>>>> 9a2abde798f13df399829a526632fb6f0f8a6e4f


void STARTGAME();

void LOAD(Array *game, char *filename);

void SAVE(Array game , char * filename);

void CREATEGAME(Array* game);

void LISTGAME(Array *game);

void DELETEGAME(Array* game);

void QUEUEGAME(Queue *antriangame, Array gamelist);

void PLAYGAME(Queue *antriangame , Array gamelist);

void SKIPGAME();

void QUIT();

void HELP();