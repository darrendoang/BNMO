#include "console.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
    // Variabel global
    Array game;
    Queue antrian;
    MakeEmpty(&game);
    CreateQueue(&antrian);
    

    // Initial output
    printf("Selamat datang di BNMO ^w^\n");
    printf("ENTER COMMAND: ");

    // Inisiasi input
    Word command;
    Word arg;

    // Meminta input
    STARTWORD();   
    SalinWord(currentWord, &command);
    ADVWORD();
    if (!EndWord){
        SalinWord(currentWord, &arg);
    }
    
    // Loop utama
    // (str_comp(command.TabWord, quit))||(str_comp(command.TabWord, help))
    boolean over = false;
    while (!over){
        if (str_comp(command.TabWord, "START")){
            STARTGAME(&game);
        }
        else if (str_comp(command.TabWord, "LOAD")){
            LOAD(&game, arg.TabWord);
        }
        else if (str_comp(command.TabWord, "SAVE")){
            SAVE(game, arg.TabWord);
        }
        else if (str_comp(command.TabWord, "CREATEGAME")){
            CREATEGAME(&game);
        }
        else if (str_comp(command.TabWord, "LISTGAME")){
            LISTGAME(&game);
        }
        else if (str_comp(command.TabWord, "DELETEGAME")){
            DELETEGAME(&game);
        }
        else if (str_comp(command.TabWord, "QUEUEGAME")){
            QUEUEGAME(&antrian, game);
        }
        else if (str_comp(command.TabWord, "PLAYGAME")){
            PLAYGAME(&antrian, game);
        }
        else if (str_comp(command.TabWord, "SKIPGAME")){
            SKIPGAME();
        }
        else if (str_comp(command.TabWord, "QUIT")){
            QUIT();
        }
        else if (str_comp(command.TabWord, "HELP")){
            HELP();
        }
        else{
            printf("error\n");
        }

        // Apabila belum keluar dari game
        if (!over){
            // Meminta input
            STARTWORD();   
            SalinWord(currentWord, &command);
            ADVWORD();
            if (!EndWord){
                SalinWord(currentWord, &arg);
            } 
        }
    }
    return 0;
}