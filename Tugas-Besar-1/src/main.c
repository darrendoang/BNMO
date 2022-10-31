#include "console.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
    printf("Selamat datang di BNMO ^w^\n");
    printf("ENTER COMMAND: ");
    char input[100];
    char command[100];
    char argument[100];
    /*
    for (int k = 0; k < 100; k++){
        input[k] = ' ';
        command[k] = ' ';
        argument[k] = ' ';
    }
    */
    fgets(input, 100, stdin);

    boolean valid = false;
    while (!valid){
        // Read command
        int i;
        while ((input[i]!=' ')&&(input[i]!='\0')){
            command[i] = input[i];
            i++;
        }
        if (input[i]==' '){
            while (input[i]!='\0'){
            argument[i] = input[i];
            i++;
            }
        }
    }
    
    return 0;
}