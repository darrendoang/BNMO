#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define IDX_UNDEF -1
#define CAPACITY 100

typedef struct {
	int number;
	int time;
	int duration;
    int price;
} order;

typedef struct {
	order buffer[CAPACITY]; 
	int idxHead;
	int idxTail;
} orderQueue;

#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]

void CreateQueue(orderQueue *q);

boolean isEmpty(Queue q);

int length(orderQueue q);

void enqueue(orderQueue *q, order val);

void dequeue(orderQueue *q, order *val);

void dinnner_dash();