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
    char *input;
    char *command;
    char *arg;

    // Meminta input
    input = READINPUT();
    command = KataPertama(input);
    arg = KataKedua(input);
    
    // Loop utama
    // (str_comp(command.TabWord, quit))||(str_comp(command.TabWord, help))
    boolean over = false;
    while (!over){
        if (str_comp(command, "START")){
            STARTGAME(&game);
        }
        else if (str_comp(command, "LOAD")){
            LOAD(&game, arg);
        }
        else if (str_comp(command, "SAVE")){
            SAVE(game, arg);
        }
        else if (str_comp(command, "CREATEGAME")){
            CREATEGAME(&game);
        }
        else if (str_comp(command, "LISTGAME")){
            LISTGAME(&game);
        }
        else if (str_comp(command, "DELETEGAME")){
            DELETEGAME(&game, antrian);
        }
        else if (str_comp(command, "QUEUEGAME")){
            QUEUEGAME(&antrian, game);
        }
        else if (str_comp(command, "PLAYGAME")){
            PLAYGAME(&antrian, game);
        }
        else if (str_comp(command, "SKIPGAME")){
            SKIPGAME();
        }
        else if (str_comp(command, "QUIT")){
            QUIT();
        }
        else if (str_comp(command, "HELP")){
            HELP();
        }
        else{
            printf("input error\n");
        }

        // Apabila belum keluar dari game
        if (!over){
            // Meminta input
            input = READINPUT();
            command = KataPertama(input);
            arg = KataKedua(input);
        }
    }
    return 0;
}