#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    infotype element;

    Stack test;
    CreateEmpty(&test);

    if (isEmpty(test)){
        printf("Stack kosong\n");
    }
    else if (isFull(test)){
        printf("Stack penuh\n");
    }

    // Mengisi stack
    printf("Mengisi stack ...");
    int i;
    for (i = 0; i < 50; i++){
        Push(&test, i);
    }

    // Mengosongkan setengah stack
    int j;
    for (j = 0; j < 50; j++){
        Pop(&test, &element);
        printf("Elemen ke-%d %s\n", j, element);
    }
}