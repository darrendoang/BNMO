#include<stdio.h>
#include<stdlib.h>
#include "mesinkaraktersnake.h"

char currentCharSnake;
boolean EOPsnake;
boolean finish;

static FILE *pitaSnake;
static int retvalSnake;

void STARTsnake() 
/* Mesin siap dioperasikan. pitaSnake disiapkan untuk dibaca.
   Karakter pertama yang ada pada pitaSnake posisinya adalah pada jendela.
   pitaSnake baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentCharSnake adalah karakter pertama pada pitaSnake
          Jika currentCharSnake != MARKS maka EOPsnake akan padam (false)
          Jika currentCharSnake = MARKS maka EOPsnake akan menyala (true) */
{
    pitaSnake = stdin ;
    advTerminal() ;
}

void ADVsnake() 
/* pitaSnake dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentCharSnake, currentCharSnake != MARKS
   F.S. : currentCharSnake adalah karakter berikutnya dari currentCharSnake yang lama,
          currentCharSnake mungkin = MARKS
          Jika  currentCharSnake = MARKS maka EOPsnake akan menyala (true) */
{
    retvalSnake = fscanf(pitaSnake,"%c", &currentCharSnake);
    EOPsnake = (currentCharSnake == MARKS);
    if (EOPsnake) {
        fclose(pitaSnake);
    }
}

char GetCCsnake() 
/* Mengirimkan currentCharSnake */
{
    return currentCharSnake ;
}

boolean IsEOPsnake() 
/* Mengirimkan true jika currentCharSnake = MARKS */
{
    return (currentCharSnake == MARKS) ;
}

void startFromFile(char *str)
/* Mesin siap dioperasikan. pitaSnake disiapkan untuk dibaca.
   Karakter pertama yang ada pada pitaSnake posisinya adalah pada jendela.
   pitaSnake baca diambil dari sebuah file yang berasal dari parameter input berupa string nama file.
   I.S. : sembarang
   F.S. : currentCharSnake adalah karakter pertama pada pitaSnake
          Jika currentCharSnake != MARKS maka EOPsnake akan padam (false)
          Jika currentCharSnake = MARKS maka EOPsnake akan menyala (true) 
          finish bernilai salah karena belum mencapai akhir dari file */
{
       finish = false;
       pitaSnake = fopen(str, "r");
    
       advFile();
}

void advTerminal()
/* I.S. : Karakter pada jendela = currentCharSnake, currentCharSnake != ENTER
   F.S. : currentCharSnake adalah karakter berikutnya dari currentCharSnake yang lama,
          currentCharSnake mungkin = ENTER
          Jika  currentCharSnake = ENTER maka EOPsnake akan menyala (true) */
{
       retvalSnake = fscanf(pitaSnake,"%c", &currentCharSnake);
       EOPsnake = (currentCharSnake == ENTER);
}

void advFile()
/* pitaSnake dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentCharSnake, currentCharSnake != MARKS
   F.S. : currentCharSnake adalah karakter berikutnya dari currentCharSnake yang lama,
          proses akan berenti bila sudah mencapai kondisi EOF atau End Of File yang akan
          menyala ketika sudah terjadi error atau tidak bisa melakukan pembacaan kembali
          finish bernilai TRUE yang bemakna file sudah selesai dibaca */ 
{
    retvalSnake = fscanf(pitaSnake,"%c", &currentCharSnake);
    if(retvalSnake == EOF) {
        fclose(pitaSnake);
        finish = true;
    }
}