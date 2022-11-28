#ifndef TOWEROFHANOI_H
#define TOWEROFHANOI_H

#include <stdio.h>
#include <stdlib.h>
#include "../ADT/stackhanoi.h"
#include "../ADT/mesinkarakter.h"
#include "../ADT/mesinkata.h"

int optimal_moves();
void print_spaces(int x);
void print_disks(int x);
void print_tower(int x, HanoiStack A, HanoiStack B, HanoiStack C);
int towerofhanoi();
#endif