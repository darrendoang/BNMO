#include "hman.h"

char kata[3][50] = {"GEEK", "GEEKS", "GEEKFOR"};
boolean guess[50];

void hman(){
    int tries = 10;
    int score = 0;
    int current, count;
    int i, j, k, l, m;
    boolean win, found, prev;
    char * input;
    char history[30];

    while (tries != 0){
        // Reset history dan guess
        count = 0;
        for (i = 0; i < 30; i++){
            guess[i] = false;
            history[i] = '*';
        }

        // Memilih kata
        current = 1;

        // Reset win
        win = false;

        // Loop
        while ((!win) && (tries != 0)){
            printf("Tebakan sebelumnya: ");
            m = 0;
            while (history[m] != '*'){
                printf("%c", history[m]);
                m++;
            }
            printf("\nKata: ");
            for (int j = 0; j < str_len(kata[current]); j++){
                if (guess[j]){
                    printf("%c ", kata[current][j]);
                }
                else{
                    printf("_ ");
                }
            }
            printf("\nKesempatan: %d\n", tries);
            printf("Masukkan tebakan: ");
            input = READINPUT();

            // Case handling

            if (input[1] != '\0'){          // Input lebih atau kurang dari 1 karakter
                tries--;
                printf("E >1\n");
            }
            else{
                printf("S =1\n");
                if (((input[0]>=65) && (input[0]<=90)) || ((input[0]>=97) && (input[0]<=122))){
                    printf("S =ALPHA\n");
                    // Mengecek apakah input sudah pernah dimasukkan
                    prev = false; 
                    j = 0;
                    printf("%s\n", history);
                    while ((!prev) && (history[j] != '*')){
                        printf("LOOP\n");
                        printf("%c %c\n", input[0], history[j]);
                        if ((input[0] == history[j]) || ((input[0] + 32) == history[j])){
                            printf("FIND\n");
                            prev = true;
                        }
                        j++;
                    }

                    if (prev){          // Input sudah pernah dimasukkan
                        tries--;
                        printf("E =PREV\n");
                    }
                    else{
                        printf("S !=PREV\n");
                        if (input[0] < 97){
                            history[j] = input[0]+32;
                        }
                        else{
                            history[j] = input[0];
                        }

                        found = false;
                        l = 0;
                        while ((l < str_len(kata[current]))&&(!found))
                        {
                            printf("S\n");
                            if ((input[0] == kata[current][l]) || (input[0]-32 == kata[current][l])){
                                found = true;
                                printf("FOUND\n");
                            } 
                            l++;
                        }

                        if (found)
                        {
                            printf("S =FOUND\n");
                            for (k = 0; k < str_len(kata[current]); k++){
                                if ((input[0] == kata[current][k]) || (input[0]-32 == kata[current][k])){
                                    count++;
                                    guess[k] = true;
                                }
                            }

                            if (count == str_len(kata[current])){
                                win = true;
                            }
                        }
                        else
                        {
                            printf("S !=FOUND\n");
                            tries--;
                        }

                    }
                }
                else{           // Input bukan alfabet
                    printf("S !=ALPHA\n");
                    tries--;
                }
            }
        }
        if (win){
            score += str_len(kata[current]);
        }
    }
}