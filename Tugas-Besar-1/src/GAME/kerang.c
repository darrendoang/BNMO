#include "kerang.h"

void kerang_ajaib(){
    srand(time(0));
    int ans = rand()%2;
    printf("Apa pertanyaanmu?\n");
    char *input = READINPUT();
    if (ans == 0){
        printf("\nYA\n\n");
    }else{
        printf("\nTIDAK\n\n");
    }
}