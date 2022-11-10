#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    char * element;

    // Membuat queue kosong
    Queue test;
    CreateQueue(&test);

    // Melihat apakah array empty atau full
    if (isEmpty(test)){
        printf("Queue kosong\n");
    }
    else if (isFull(test)){
        printf("Queue penuh\n");
    }

    // Mengisi queue
    printf("Mengisi queue ...");
    int i;
    for (i = 0; i < 50; i++){
        enqueue(&test, "Hello world!");
    }

    // Panjang queue
    printf("Panjang queue: %d\n", length(test));

    // Menulis isi queue
    displayQueue(test);

    // Mengosongkan setengah queue
    int j;
    for (j = 0; j < 50; j++){
        dequeue(&test, element);
        printf("Elemen ke-%d %s\n", j, element);
    }

    return 0;
}