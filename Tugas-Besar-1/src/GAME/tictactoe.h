#ifndef TICTACTOE_H
#define TICTACTOE_H
#include "../ADT/mesinkarakter.h"
#include "../ADT/mesinkata.h"

void printBoard();
int checkFreeSpaces();
void resetboard();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char winner);
void tictactoe();

#endif