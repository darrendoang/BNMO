#include <stdio.h>
#include "boolean.h"
#include "list.h"
#include "queue.h"

Queue queuegame;

void SKIPGAME(int input){
    int i = 0;

    displayQueue(queuegame);

    if (input > length(queuegame)) {
        for (i = 0; i < input; i++) {
            dequeue(&queuegame, &val);
            // playgame(input);
        }
    } else {
        printf("Tidak ada permainan lagi dalam daftar game-mu.");
    }
}