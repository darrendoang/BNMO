#include <stdio.h>
#include <stdlib.h>

int main(){
    static FILE *pita;
    static int retval;
    char currentChar;
    char nama[3];
    printf("Input: ");
    /*
    fgets(nama, 3, stdin);
    
    int j = 0;
    char i = nama[];
    while (i != '\0'){
        printf("%c", i);
        j++;
        char i = nama[1];
    }
    */
    /*
    printf("%c", nama[0]);
    printf("%c", nama[1]);
    printf("%c", nama[2]);
    if (nama[0]=='\n'){
        printf("   0ntadah!   ");
    }
    if (nama[1]=='\n'){
        printf("   1ntadah!   ");
    }
    if (nama[2]=='\n'){
        printf("   2ntadah!   ");
    }
    if (nama[0]=='\0'){
        printf("   0otadah!   ");
    }
    if (nama[1]=='\0'){
        printf("   1otadah!   ");
    }
    if (nama[2]=='\0'){
        printf("   2otadah!   ");
    }
    system("pause");
    */
    pita = stdin;
    retval = fscanf(pita, "%c", &currentChar);
    printf("%c", currentChar);
    retval = fscanf(pita, "%c", &currentChar);
    printf("%c", currentChar);
    retval = fscanf(pita, "%c", &currentChar);
    printf("%c", currentChar);

    system("pause");
    return 0;
}