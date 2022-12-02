#include "set.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Set test1, test2, temp;
    CreateEmpty(&test1);
    CreateEmpty(&test2);

    if ((IsEmpty(test1))&&(IsEmpty(test2))){
        printf("Array kosong\n");
    }
    else if ((IsFull(test1))&&(IsFull(test2))){
        printf("Array penuh\n");
    }

    int i;
    for (i = 0; i < 50; i++){
        Insert(&test1, i);
        Insert(&test2, i);
    }

    if (IsMember(test1, 10)){
        printf("Elemen yang memiliki nilai 10 adalah member dari map test\n");
    }

    int j;
    for (j = 0; j < 25; j++){
        Delete(&test1, j);
    }

    temp = SetUnion(test1, test2);
    temp = SetIntersection(test1, test2);
    temp = SetSymmetricDifference(test1, test2);
    temp = SetSubtract(test1, test2);
}