#include "console.h"

void STARTGAME(Array *game , TabMap *scoreboard)
{
    StartLOAD("../data/config.txt");
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
    Map ScoreB;
    int k;
    for (k = 0; k < game->Neff; k++)
    {
        CreateEmptyMap(&ScoreB);
        SetElArrayMap(scoreboard, k, ScoreB);
    }
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}

void LOAD(Array *game, HistoryStack *gamehistory , TabMap *scoreboard,  char *filename) {   
    int i , j, idx; 
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
        // Membaca HISTORY GAME
    ADVWORDLOAD();
    i = StrToInt(currentWord.TabWord); 
   
    for (j = 0; j < i; j++)
    {
      ADVWORDLOAD();
      char *namagame;
      namagame = (char *)malloc(currentWord.Length * sizeof(char));
      for (idx = 0; idx < currentWord.Length; idx++)
      {
        *(namagame + idx) = currentWord.TabWord[idx];
      }
      *(namagame + currentWord.Length) = '\0';
      PushHistory(gamehistory, namagame);
    }

    // Membaca semua scoreboard dari list game
    Map ScoreB;
    int banyaksb;
    for (banyaksb = 0; banyaksb < (*game).Neff; banyaksb++)
    {
      CreateEmptyMap(&ScoreB);
      ADVWORDLOAD();
      i = StrToInt(currentWord.TabWord);
      ScoreB.Count = i;
      for (j = 0; j < ScoreB.Count; j++)
      {
        ADVWORDLOAD();
        char *namagame;
        namagame = (char *)malloc(currentWord.Length * sizeof(char));
        for (idx = 0; idx < currentWord.Length; idx++)
        {
          *(namagame + idx) = currentWord.TabWord[idx];
        }
        *(namagame + currentWord.Length) = '\0';
        ScoreB.Elements[j].Key = KataPertama(namagame);
        ScoreB.Elements[j].Value = StrToInt_input(KataKedua(namagame), str_len(KataKedua(namagame)));
      }
      SortMapValueDesc(&ScoreB);
      SetElArrayMap(scoreboard, banyaksb, ScoreB);
    }
 
  
  
}

void SAVE(Array game, HistoryStack gamehistory, TabMap scoreboard, char *file)
{
    FILE *pita;
    char *filename = (char *)malloc(50 * sizeof(char));
    filename = filetodir(file);
    pita = fopen(filename, "w+");
    char *game_num = (char *)malloc(5 * sizeof(char));
    int i;

    //save daftar game
    sprintf(game_num, "%d", game.Neff);
    fprintf(pita, "%s\n", game_num);
    for (i = 0; i < NbElmt(game); i++)
    {
        fprintf(pita, "%s\n", game.TI[i]);
    }
    //save gamehistory
    sprintf(game_num, "%d", gamehistory.TOPHISTORY + 1);
    fprintf(pita, "%s\n", game_num);
    for (i = 0; i <= gamehistory.TOPHISTORY; i++)
    {
        fprintf(pita, "%s\n", gamehistory.T[i]);
    }

    //save scoreboard
    int j;
    for (j = 0; j < scoreboard.NeffArrayMap - 1; j++)
    {
        sprintf(game_num, "%d", scoreboard.TIMap[j].Count);
        fprintf(pita, "%s\n", game_num);
        for (i = 0; i < scoreboard.TIMap[j].Count; i++)
        {
            fprintf(pita, "%s %d\n", scoreboard.TIMap[j].Elements[i].Key, scoreboard.TIMap[j].Elements[i].Value);
        }
    }
    sprintf(game_num, "%d", scoreboard.TIMap[j].Count);
    if (scoreboard.TIMap[j].Count == 0)
    {
        fprintf(pita, "%s", game_num);
    }
    else if (scoreboard.TIMap[j].Count == 1)
    {
        fprintf(pita, "%s\n", game_num);
        fprintf(pita, "%s %d", scoreboard.TIMap[j].Elements[0].Key, scoreboard.TIMap[j].Elements[0].Value);
    }
    else
    {
        fprintf(pita, "%s\n", game_num);
        for (i = 0; i < scoreboard.TIMap[j].Count - 1; i++)
        {
            fprintf(pita, "%s %d\n", scoreboard.TIMap[j].Elements[i].Key, scoreboard.TIMap[j].Elements[i].Value);
        }
        fprintf(pita, "%s %d", scoreboard.TIMap[j].Elements[i].Key, scoreboard.TIMap[j].Elements[i].Value);
    }

    fclose(pita);
    printf("Save file berhasil disimpan.\n");
    free(filename);
    free(game_num);
}

int compare(char *str1, char *str2) {
  while (*str1 && *str1 == *str2) {
    str1++;
    str2++;
  }
  return *str1 - *str2;
}
void CREATEGAME(Array* game , TabMap *scoreboard){
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
        Map scoreB;
        CreateEmptyMap(&scoreB);
        SetElArrayMap(scoreboard, scoreboard->NeffArrayMap, scoreB);
        printf("Game berhasil ditambahkan.\n\n");
    }
}

void LISTGAME(Array *game){
    int i;
    for(i = 0; i < game->Neff; i++){
    printf("%d. %s\n",i+1, game->TI[i]);
    }
}

void DELETEGAME(Array* game , Queue *antriangame , TabMap *scoreboard){
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
        DeleteAt(scoreboard, del_num -1);
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

void PLAYGAME(Queue *antriangame , Array gamelist , TabMap *scoreboard , HistoryStack *gamehistory)
{
    ElType val;
    int score;
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
        score = RNG();
    }
    else if (str_comp(play, "Diner DASH")){
        printf("Loading DINER DASH . . . \n");
        dequeue(antriangame,val);
        score = diner_dash();
    }

    else if (str_comp(play, "TIC TAC TOE")){
        printf("Loading TIC TAC TOE . . . \n");
        dequeue(antriangame,val);
        score = tictactoe();
    }

    else if (str_comp(play, "TOWER OF HANOI")){
        printf("Loading TOWER OF HANOI . . . \n");
        dequeue(antriangame,val);
        score = towerofhanoi();
    }

    // else if (str_comp(play, "RISEWOMAN")){
    //     printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n",play);
    //     printf("Silahkan pilih game lain.\n");
    //     dequeue(antriangame,val);
    // }

    // else if (str_comp(play, "EIFFEL TOWER")){
    //     printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n",play);
    //     printf("Silahkan pilih game lain.\n");
    //     dequeue(antriangame,val);
    // }

    // else if (str_comp(play, "DINOSAUR IN EARTH")){
    //     printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n",play);
    //     printf("Silahkan pilih game lain.\n");
    //     dequeue(antriangame,val);
    // }
    else{
            srand(time(0));
            score = rand()%100;
            printf("Loading %s . . . \n", play);
            printf("GAME OVER\n");
            printf("SKOR AKHIR: %d\n", score);
            dequeue(antriangame,val);
    }
    char *nama;
    printf("Nama : ");
    nama = STARTINPUT();
    int idxgame = 0;
    while (!compare_strings(gamelist.TI[idxgame], play))
    {
        idxgame++;
    };
    while (IsMember((*scoreboard).TIMap[idxgame], nama))
    {
        printf("Nama sudah ada, silahkan memakai nama lain!\n\n");
        printf("Nama : ");
        nama = STARTINPUT();
    }
    Insert(&(*scoreboard).TIMap[idxgame], nama, score);
    SortMapValueDesc(&(*scoreboard).TIMap[idxgame]);
    printf("Skor berhasil disimpan ke dalam scoreboard.\n\n");
    PushHistory(gamehistory, play);
}

void SKIPGAME(Queue *queuegame, int input , Array gamelist, TabMap *scoreboard , HistoryStack *gamehistory)
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
        PLAYGAME(queuegame, gamelist , scoreboard ,gamehistory);
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
//     Array a ;
//     HistoryStack gamehistory;
//     TabMap scoreboard;
//     MakeEmpty(&a);
//     CreateEmptyStackHistory(&gamehistory);
//     MakeEmptyArrayMap(&scoreboard);
//     Queue q;
//     CreateQueue(&q);
//     LOAD(&a, &gamehistory , &scoreboard, "../data/savefile.txt");
//     int i;
//     for(i = 0; i < a.Neff; i++){
//     printf("%d. %s\n",i+1, a.TI[i]);
//     }
//     printf("\n\n\n\n");

//     PrintStackHistory(&gamehistory , 5);

    
//     return 0;
// }