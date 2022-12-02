#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "charmachine.h"
#include "wordmachine.h"
#include "listdp.h"
#include "arrayMap.h"
#include "boolean.h"

# ifndef SOM_H
# define SOM_H

int GetInfo(addressLDP P);

boolean SearchPoint(List L,int X,int Y);

addressLDP SearchAP(List L,int i,int j);

void createSnake(List *L);

void move (List *L, char* input);

void makeMeteor(POINT *meteor,POINT food);

void makeObstacle(List L, POINT* obstacle);

void makeFood(POINT *food,List L, POINT obstacle);

boolean foodEaten(List *L, POINT food);

void kenaMeteor(List *L,POINT food,POINT meteor);

boolean endGame(List L,POINT meteor, POINT obstacle);

void printMap(List L,POINT food, POINT meteor,POINT obstacle);

void som(TabMap *arrmapsb, int *score);

#endif