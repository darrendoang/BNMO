#ifndef DDASH_H
#define DDASH_H

#include "../ADT/boolean.h"
#include "../ADT/mesinkarakter.h"
#include "../ADT/mesinkata.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define IDX_UNDEF -1
#define CAPACITY 100
#define Nil -999

typedef struct {
	int number;
	int time;
	int duration;
    int price;
	boolean cook;
	boolean serve;
} order;

typedef struct {
	order buffer[CAPACITY]; 
	int idxHead;
	int idxTail;
} orderQueue;

typedef struct
	{
		int TI [100]; /* memori tempat penyimpan elemen (container) */
		int Neff; /* banyaknya elemen efektif */
	} arrayCook;

#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]

boolean isEmptyD(orderQueue q);

void CreateQueueD(orderQueue *q);

void enqueueD(orderQueue *q);

void dequeueD(orderQueue *q, int *saldo);

int diner_dash();

#endif