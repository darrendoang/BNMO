#include "console.h"

void STARTGAME()
{
    Array game;
    MakeEmpty(&game);
    LOAD(&game, "../data/config.txt");
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.");
}

void LOAD(Array *game, char *filename) {    
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
        *(namagame + currentWord.Length) = '\0'; //penanda akhir string
        game->TI[i] = namagame;
    }

    
}

void SAVE();

int compare(char *str1, char *str2) {
  while (*str1 && *str1 == *str2) {
    str1++;
    str2++;
  }
  return *str1 - *str2;
}
void CREATEGAME(char* game[20],char new[20]){
    int num = 0,found=0,sum=0;
    while (game[num] != "-999"){
        num+=1;
    }
    for (int i=0;i<num;i++){
        if(compare(game[i],new)==0){
            found=1;
        }
    }
    if (found==1){
        printf("Nama game sudah ada!\n");
    } else{
        game[num] = new;
        game[num+1] = "-999";
    }
}

void LISTGAME(char* game[20]){
    int no = 0;
    while(game[no] != "-999"){
        printf("%d. %s\n",no+1,game[no]);
        no++;
    }
}

void DELETEGAME(char* game[20],int del){
    int num = 0;
    while (game[num] != "-999"){
        num+=1;
    }
    if(del-1>=num){
        printf("Tidak ada game dengan posisi tersebut\n");
    } else if(del<=5 && del>=1){
        printf("Game gagal dihapus!\n");
    }
    else {
        for(int i = del-1;i<num+1;i++){
            game[i] = game[i+1];
        }
        printf("Game berhasil dihapus\n");
    }
}

void QUEUEGAME();

void PLAYGAME();

void SKIPGAME();

void QUIT();

void HELP();

int main()
{
    Array a;
    MakeEmpty(&a);
    LOAD(&a, "../data/config.txt");

    printf("Neff: %d\n", a.Neff);
    int i;
    for(i = 0; i < a.Neff; i++)
    printf("%s\n", a.TI[i]);

    return 0;
}