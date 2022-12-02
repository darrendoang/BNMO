#include "../ADT/listdp.h"
#include <stdio.h>
#include <stdlib.h>
#include "../ADT/boolean.h"
#include "../ADT/mesinsnake.h"
#include "../ADT/mesinkaraktersnake.h"

void board(List snake, List food, List meteor, List obst);
/* menampilkan permainan snake on meteor */

void snakes(List * snake);
/* inisiasi awal snake yaitu terdiri dari H, 1, dan 2, dengan randomize letak awal */

void dfood(List * snake, List * food, List * hmeteor, List * obst);
/* meletakkan makanan pada game secara acak */

void dmeteor(List * food, List * obst, List * meteor);
/* meletakkan meteor pada game secara acak */

void makan(List * snake, List * food, List * obst, boolean * wwin);
/* bertambah panjangnya ekor snake setelah memakan sebuah food */

void belok(char x, List *s, List * hmeteor, List * obst, boolean * gagal, boolean * wwin);
/* pembelokan head yang diikuti badan - badan snake */

void hit(List * snake, List * meteor, location * temp);
/* snake terkena meteor dan badan akan terputus */

void obs(List * snake, List * food, List * obst);
/* meletakkan obst secara acak pada game */

int lengths(List snake);
/* panjang snake */

void snakeOnMeteor(int * score);
/* permainan Snake On Meteor */