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
   

    // Inisiasi input
    char *input;
    char *command;
    char *arg;

    // Meminta input
    
    
    
    // Loop utama
    // (str_comp(command.TabWord, quit))||(str_comp(command.TabWord, help))
    boolean load = false;
    boolean over = false;
    while (!load){
        printf("ENTER COMMAND: ");
        input = READINPUT();

        if (blank_count(input) == 0)
        {
            if (str_comp(input , "START"))
            {
                STARTGAME(&game);
                load = true;
            }

            else if (str_comp(input, "HELP"))
            {
                HELP();
            }
        
        }
        else if(blank_count(input) == 1)
        {
            command = KataPertama(input);
            arg = KataKedua(input);

             if (str_comp(command , "LOAD"))
            {
                if (str_comp(arg, "savefile.txt"))
                {
                    LOAD(&game, "../data/savefile.txt");
                    if (game.Neff < 0)
                    {
                        printf("Load gagal\n");
                    }
                    else
                    {
                    printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
                    load = true;
                    }
                }

                else if (str_comp(arg, "config.txt"))
                {
                    LOAD(&game, "../data/config.txt");
                    if (game.Neff < 0)
                    {
                        printf("Load gagal\n");
                    }
                    else
                    {
                    printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
                    load = true;
                    }
                }
                else
                {
                    printf("Load gagal\n");
                }


            }
            else{
                printf("Perintah yang dapat digunakan hanya START, LOAD, atau HELP\n");
            }
        }

        else 
        {
            printf("Perintah yang dapat digunakan hanya START, LOAD, atau HELP\n");
        }


        while(load && !over)
        {
            printf("ENTER COMMAND: ");
            input = READINPUT();

            if(blank_count(input) > 1)
            {
                printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
            }
            else
            {

                if (str_comp(input, "CREATE GAME")){
                    CREATEGAME(&game);
                }
                else if (str_comp(input, "LIST GAME")){
                    LISTGAME(&game);
                }
                else if (str_comp(input, "DELETE GAME")){
                    DELETEGAME(&game, &antrian);
                }
                else if (str_comp(input, "QUEUE GAME")){
                    QUEUEGAME(&antrian, game);
                }
                else if (str_comp(input, "PLAY GAME")){
                    PLAYGAME(&antrian, game);
                }
               
                else if (str_comp(input, "QUIT")){
                    over =true;
                }
                else if (str_comp(input, "HELP")){
                    HELP();
                }
                else if(blank_count(input)== 1)
                {
                    command = KataPertama(input);
                    arg = KataKedua(input);
                    if(str_comp(command , "SAVE"))
                    {
                        SAVE(game, arg);
                    }
                    else if (str_comp(command, "SKIPGAME"))
                    {
                    // SKIPGAME();
                    }
                    else{
                        printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
                    }
                }
                else{
                    printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
                }
            }
        }

        // Apabila belum keluar dari game

    }
    if(over )
    {
        printf("Anda keluar dari game BNMO.\n");
        printf("Bye bye ...\n");

    }
    return 0;
}