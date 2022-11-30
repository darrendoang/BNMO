#include "hman.h"

char kata[10][50] = {"KUCING", "RUBAH", "ANJING", "INSTITUT", "BANDUNG", "TEKNOLOGI", "TUGAS", "ALGORITMA", "STRUKTUR", "DATA"};
boolean guess[50];

void hman(int *user_score){
    int temp_score;
    int tries = 10;
    int score = 0;
    int current, count;
    int i, j, k, l, m;
    boolean win, found, prev;
    char * input;
    char history[30];

    srand(time(0));

    while (tries != 0){
        // Reset history dan guessD
        
        count = 0;
        for (i = 0; i < 30; i++){
            guess[i] = false;
            history[i] = '*';
        }

        // Memilih kata
        current = rand() % 10;

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
            }
            else{
                if (((input[0]>=65) && (input[0]<=90)) || ((input[0]>=97) && (input[0]<=122))){
                    // Mengecek apakah input sudah pernah dimasukkan
                    prev = false; 
                    j = 0;
                    while ((!prev) && (history[j] != '*')){
                        if ((input[0] == history[j]) || ((input[0] + 32) == history[j])){
                            prev = true;
                        }
                        j++;
                    }

                    if (prev){          // Input sudah pernah dimasukkan
                        tries--;
                    }
                    else{
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
                            if ((input[0] == kata[current][l]) || (input[0]-32 == kata[current][l])){
                                found = true;
                            } 
                            l++;
                        }

                        if (found)
                        {
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
                            tries--;
                        }

                    }
                }
                else{           // Input bukan alfabet
                    tries--;
                }
            }
            printf("\n");
        }
        if (win){
            score += str_len(kata[current]);
        }
    }
    printf("SKOR AKHIR: %d\n", score * 1000);
    *user_score = score * 1000;
}