#include "mesinkarakter.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    // Menerima input
    START();
    
    // Mencetak input ke layar
    while (!IsEOP(currentChar)){
        printf("%c", currentChar);
    }
    printf("\n");

    // Tes prosedur READINPUT
    char *input = READINPUT();
    printf("%s\n", input);
    
    return 0;
}