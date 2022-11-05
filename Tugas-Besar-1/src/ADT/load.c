/* File load.c */
#include "../ADT/array.h"
#include "../ADT/mesinkarakter.h"
#include "../ADT/mesinkata.h"
#include "load.h"
#include <stdio.h>
#include <stdlib.h>


static FILE *pita;
static int retval;


void load(Array *game, char *filename) {    
    StartLOAD(filename);
    int n = currentChar - '0'; //mengambil nilai line pertama dalam file yaitu jumlah game lalu diubah ke int
    game->Neff = n; // jumlah game di assign ke game->Neff
    ADVLOAD();
    for (int i = 0; i < n; i++) {
        ADVWORDLOAD();
        char *namagame;
        namagame = (char *)malloc(currentWord.Length * sizeof(char));
        for(int j = 0; j < currentWord.Length; j++)
        {
            *(namagame + j) = currentWord.TabWord[j];
        }
        *(namagame + currentWord.Length) = '\0';
        game->TI[i] = namagame;
    }
}


int main()
{
    Array game;
    MakeEmpty(&game);
    load(&game, "../data/config.txt");
    printf("%d\n", game.Neff);
    printf("%s\n", game.TI[0]);


    return 0;

}