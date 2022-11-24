#include "console.h"

void STARTGAME(Array *game)
{
    LOAD(game, "../data/config.txt");
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}

void LOAD(Array *game, char *filename) {    
    StartLOAD(filename);
    int n = currentChar - '0'; //mengambil nilai line pertama dalam file yaitu jumlah game lalu diubah ke int
    game->Neff = n; // jumlah game di assign ke game->Neff
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
void CREATEGAME(Array* game){
    printf("Masukkan nama game yang akan ditambahkan: ");
    char *new;
    new = READINPUT();
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

void DELETEGAME(Array* game , Queue *antriangame){
    LISTGAME(game);
    printf("Masukkan nomor game yang akan dihapus: ");
    char *del_num_input;
    del_num_input = READINPUT();
    int del_num;
    del_num = StrToInt_input(del_num_input , str_len(del_num_input));
    boolean flag;
    flag = false;
    int x;
    x = (*antriangame).idxHead;
    char *gamename;
    while ((x < (*antriangame).idxHead + length(*antriangame)) && !flag)
    {
        if (str_comp(game->TI[del_num - 1], (*antriangame).buffer[x]))
        {
            flag = true;
        }
        x++;
    }

    if(del_num <=6 || del_num > game->Neff || flag)
    {
        printf("Game gagal dihapus!\n");
    }
    else
    {
        for(int i=del_num-1 ; i < game->Neff ; i++)
        {
            game->TI[i] = game->TI[i+1];
        }
        game->Neff --;
        printf("Game berhasil dihapus\n");
    }
}

void QUEUEGAME(Queue *antriangame, Array gamelist)

{
    int gamenumber;
    printf("Berikut adalah daftar antrian game-mu\n");

    if (isEmpty(*antriangame)){
        printf("Tidak ada game dalam daftar antrian \n");
    }
    else{
        int i,x=0;
        for (i=(*antriangame).idxHead; i< length(*antriangame) +(*antriangame).idxHead ; i++){
            printf("%d. %s\n", x+1, (*antriangame).buffer[i]);
            x++;
        }
    }
    printf("\n");

    LISTGAME(&gamelist);
    printf("\n");
    printf("Nomor Game yang mau ditambahkan ke antrian:");
    char *gamenumber_input;
    gamenumber_input = READINPUT();
    gamenumber = StrToInt_input(gamenumber_input, str_len(gamenumber_input));
    if (gamenumber > gamelist.Neff){
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
    }
    else{
        enqueue(antriangame, gamelist.TI[gamenumber - 1]);
        printf("Game berhasil ditambahkan kedalam daftar antrian.\n");
    }

}

void PLAYGAME(Queue *antriangame , Array gamelist)
{
    ElType val;
    printf("Berikut adalah daftar Game-mu\n");

    if (isEmpty(*antriangame)){
        printf("Daftar game kosong.\n");
        QUEUEGAME(antriangame, gamelist);
    }
    else{
        int i,x=0;
        for (i=(*antriangame).idxHead; i< length(*antriangame) +(*antriangame).idxHead ; i++){
            printf("%d. %s\n", x+1, (*antriangame).buffer[i]);
            x++;
        }
    }
    printf("\n");

    char *play = antriangame->buffer[antriangame->idxHead];
    if (str_comp(play, "RNG")){
        printf("Loading RNG . . . \n");
        dequeue(antriangame,val);
        RNG();
    }
    else if (str_comp(play, "Diner DASH")){
        printf("Loading DINER DASH . . . \n");
        dequeue(antriangame,val);
        diner_dash();
    }

    else if (str_comp(play, "TIC TAC TOE")){
        printf("Loading TIC TAC TOE . . . \n");
        dequeue(antriangame,val);
        tictactoe();
    }

    else if (str_comp(play, "RISEWOMAN")){
        printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n",play);
        printf("Silahkan pilih game lain.\n");
        dequeue(antriangame,val);
    }

    else if (str_comp(play, "EIFFEL TOWER")){
        printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n",play);
        printf("Silahkan pilih game lain.\n");
        dequeue(antriangame,val);
    }

    else if (str_comp(play, "DINOSAUR IN EARTH")){
        printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n",play);
        printf("Silahkan pilih game lain.\n");
        dequeue(antriangame,val);
    }
    else{
            srand(time(0));
            printf("Loading %s . . . \n", play);
            printf("GAME OVER\n");
            printf("SKOR AKHIR: %d\n", rand()%10000);
            dequeue(antriangame,val);
    }
}

void SKIPGAME(Queue *queuegame, int input , Array gamelist)
{
    char *temp;
    printf("Berikut adalah daftar Game-mu: \n");
    if (!isEmpty(*queuegame))
    {
        int list = 0;
        for (int i = queuegame->idxHead; i < (queuegame->idxHead + length(*queuegame)); i++)
        {
            printf("%d. %s\n", list + 1, queuegame->buffer[i]);
            list++;
        }
    }
    else
    {
        printf("Tidak ada game dalam antrian\n");
    }
    printf("\n");

    for (int i = 0; i < input; i++)
    {
        if (!isEmpty(*queuegame))
        {
            dequeue(queuegame, temp);
        }
    }

    if (!isEmpty(*queuegame))
    {
        PLAYGAME(queuegame, gamelist);
    }
    else
    {
        printf("Tidak ada permainan di dalam daftar Game-mu.\n");
    }
}


void QUIT();

void HELP (){
    printf(
        "COMMANDS :\n"
        " START                 Membaca file konfigurasi default yang berisi list game yang dapat dimainkan\n"
        " LOAD                  Membaca save file yang berisi list game yang dapat dimainkan, histori dan scoreboard game\n"
        " SAVE                  Merepresentasikan nama file yang akan disimpan pada disk\n"
        " CREATE GAME           Menambahkan game baru pada daftar game \n"
        " LIST GAME             Menampilkan daftar game yang disediakan oleh sistem \n"
        " DELETE GAME           Menghapus sebuah game dari daftar game \n"
        " QUEUE GAME            Mendaftarkan permainan kedalam list \n"
        " PLAY GAME             Memainkan sebuah permainan \n"
        " SKIPGAME <n>          Melewatkan permainan sebanyak n \n"
        " QUIT                  Keluar dari Program \n"
        " HELP                  Menampilkan daftar perintah \n"
    );
}

// int main()
// {
//     Array a;
//     MakeEmpty(&a);
//     Queue q;
//     CreateQueue(&q);
//     LOAD(&a, "../data/config.txt");

//       int i = 0;
//         for (i; i < length(q); i++){
//             printf("%d. %s\n", i+1, q.buffer[i]);
//         }
//     CREATEGAME(&a);
//     QUEUEGAME(&q , a);
//     DELETEGAME(&a , &q);
//     SAVE(a , "../data/config.txt" );
//     return 0;
// }