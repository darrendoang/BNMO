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

void SAVE(Array game , char * filename){
    FILE* pita;
    char data_path[100] = "../data/";
    int i = 8;
    while(*filename!='\0'){
      data_path[i] = *filename;
      i++;
      *filename++;
    }
    pita=fopen(data_path,"w");

    fprintf(pita,"%c\n",(char)(game.Neff+48));

    for(int i=0;i<NbElmt(game)-1;i++){
        fprintf(pita,"%s\n",game.TI[i]);
    }
    fprintf(pita,"%s",game.TI[NbElmt(game)-1]);

    fclose(pita);
    printf("Save file berhasil disimpan.\n");
}

int compare(char *str1, char *str2) {
  while (*str1 && *str1 == *str2) {
    str1++;
    str2++;
  }
  return *str1 - *str2;
}
void CREATEGAME(Array* game,char new[]){
    int found=0,num=game->Neff;
    for (int i=0;i<num;i++){
        if(compare(game->TI[i],new)==0){
            found=1;
        }
    }
    if (found==1){
        printf("Nama game sudah ada!\n");
    } else{
        game->TI[num] = new;
        game->Neff ++;
    }
}

void LISTGAME(Array *game){
    int i;
    for(i = 0; i < game->Neff; i++){
    printf("%d. %s\n",i+1, game->TI[i]);
    }
}

void DELETEGAME(Array* game,int del){
    if(del-1>=game->Neff){
        printf("Tidak ada game dengan posisi tersebut\n");
    } else if(del<=5 && del>=1){
        printf("Game gagal dihapus!\n");
    }
    else {
        for(int i = del-1;i<game->Neff+1;i++){
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

// int main()
// {
//     Array a;
//     MakeEmpty(&a);
//     LOAD(&a, "../data/config.txt");
//     printf("Neff: %d\n", a.Neff);
//     LISTGAME(&a);
//     DELETEGAME(&a,2);
//     printf("Neff: %d\n", a.Neff);
//     LISTGAME(&a);
//     SAVE(a , "../data/config.txt" );
//     return 0;
// }