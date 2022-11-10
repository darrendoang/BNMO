#include "mesinload.h"
#include <stdio.h>
#include <stdlib.h>

int main (){  
    char *filename = "../data/savefile.txt";
    StartLOAD(filename);
    int n = currentChar - '0'; 
    printf("%s" , n);
    ADVWORDLOAD();
    for (int i = 0; i < n; i++) {
        ADVWORDLOAD();
        char *namagame;
        namagame = (char *)malloc(currentWord.Length * sizeof(char));
        for(int j = 0; j < currentWord.Length; j++)
        {
            *(namagame + j) = currentWord.TabWord[j];
        }
        *(namagame + currentWord.Length) = '\0'; //penanda akhir string
        printf ("%s", namagame); 
    }
}