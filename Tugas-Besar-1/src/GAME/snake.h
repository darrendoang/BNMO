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

int  GetInf(addressLDP P);

boolean SearchPoint(List L,int X,int Y);

addressLDP SearchAP(List L,int i,int j);

void createSnake(List *L);

void move (List *L, char* input);

void createMeteor(POINT *meteor,POINT food);

void createObstacle(List L, POINT* obstacle);

void createFood(POINT *food,List L, POINT obstacle);

boolean checkFoodEaten(List *L, POINT food);

void hit(List *L,POINT food,POINT meteor);

boolean endCond(List L,POINT meteor, POINT obstacle);

void printMap(List L,POINT food, POINT meteor,POINT obstacle);

void som(TabMap *arrmapsb, int *score);

#endif