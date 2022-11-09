#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"
#include "queue.h"
#include "quit.h"

void QUIT(Queue *Q){
    while (!IsEmpty(*Q)){
        ElType val;
        dequeue(Q,&val);
    }
    printf ("Anda keluar dari game BNMO. \n");
    printf ("Bye bye ...");
}