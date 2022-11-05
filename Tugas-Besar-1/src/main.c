#include "console.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
    // Initial output
    printf("Selamat datang di BNMO ^w^\n");
    printf("ENTER COMMAND: ");

    // Inisiasi input
    Word command;
    Word arg;

    // Command
    char start[] = "START";
    char load[] = "LOAD";
    char save[] = "SAVE";
    char create[] = "CREATEGAME";
    char list[] = "LISTGAME";
    char delete[] = "DELETEGAME";
    char queue[] = "QUEUEGAME";
    char play[] = "PLAYGAME";
    char skip[] = "SKIPGAME";
    char quit[] = "QUIT";
    char help[] = "HELP"; 


    // Meminta input
    STARTWORD();   
    SalinWord(currentWord, &command);
    ADVWORD();
    if (!EndWord){
        SalinWord(currentWord, &arg);
    }

    // Validasi input
    boolean valid = false;
    while (!valid){
        if ((str_comp(command.TabWord, start))||(str_comp(command.TabWord, load))||(str_comp(command.TabWord, save))||(str_comp(command.TabWord, create))||(str_comp(command.TabWord, list))||(str_comp(command.TabWord, delete))||(str_comp(command.TabWord, queue))||(str_comp(command.TabWord, play))||(str_comp(command.TabWord, skip))||(str_comp(command.TabWord, quit))||(str_comp(command.TabWord, help))){
            valid = true;
        }
        else{
            printf("error\n");
        }
    }
    
    // Loop utama
    // (str_comp(command.TabWord, quit))||(str_comp(command.TabWord, help))
    boolean over = false;
    while (!over){
        if (str_comp(command.TabWord, start)){
            START();
        }
        else if (str_comp(command.TabWord, load)){

        }
        else if (str_comp(command.TabWord, save)){

        }
        else if (str_comp(command.TabWord, create)){

        }
        else if (str_comp(command.TabWord, list)){
           
        }
        else if (str_comp(command.TabWord, delete)){
    
        }
        else if (str_comp(command.TabWord, play)){
      
        }
        else if (str_comp(command.TabWord, skip)){
      
        }
        else if (str_comp(command.TabWord, quit)){
      
        }
        else if (str_comp(command.TabWord, help)){
            QUIT();
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

            // Validasi
            boolean valid = false;
            while (!valid){
                // Read command
                if ((str_comp(command.TabWord, start))||(str_comp(command.TabWord, load))||(str_comp(command.TabWord, save))||(str_comp(command.TabWord, create))||(str_comp(command.TabWord, list))||(str_comp(command.TabWord, delete))||(str_comp(command.TabWord, queue))||(str_comp(command.TabWord, play))||(str_comp(command.TabWord, skip))||(str_comp(command.TabWord, quit))||(str_comp(command.TabWord, help))){
                    valid = true;
                }
                else{
                    printf("error\n");
                }
            }    
        }
    }
    return 0;
}