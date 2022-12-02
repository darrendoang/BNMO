#include "map.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Map test;
    CreateEmptyMap(&test);

    if (IsEmpty(test)){
        printf("Array kosong\n");
    }
    else if (IsFull(test)){
        printf("Array penuh\n");
    }

    printf("Mengisi map ...");
    int i;
    for (i = 0; i < 50; i++){
        Push(&test, i, i * 2);
        printf("Value dari key %d adalah %d", i, Value(test, i));
    }
    
    if (IsMember(test, 10)){
        printf("Elemen yang memiliki key 10 adalah member dari map test\n");
    }

    int j;
    for (j = 0; j < 50; j++){
        Pop(&test, j);
        printf("Elemen dengan key %d dihapus\n", j);
    }

}