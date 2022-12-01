/* File: mesinkaraktersnake.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_SNAKE_H_
#define __MESIN_KAR_SNAKE_H_

#include "boolean.h"

#define MARKS '.'
#define ENTER '\n'

/* State Mesin */
extern char currentCharSnake;
extern boolean EOPsnake;
extern boolean finish;

void STARTsnake();
/* Mesin siap dioperasikan. pitaSnake disiapkan untuk dibaca.
   Karakter pertama yang ada pada pitaSnake posisinya adalah pada jendela.
   pitaSnake baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentCharSnake adalah karakter pertama pada pitaSnake
          Jika currentCharSnake != MARKS maka EOPsnake akan padam (false)
          Jika currentCharSnake = MARKS maka EOPsnake akan menyala (true) */

void ADVsnake();
/* pitaSnake dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentCharSnake, currentCharSnake != MARKS
   F.S. : currentCharSnake adalah karakter berikutnya dari currentCharSnake yang lama,
          currentCharSnake mungkin = MARKS
          Jika  currentCharSnake = MARKS maka EOPsnake akan menyala (true) */

char GetCCsnake();
/* Mengirimkan currentCharSnake */

boolean IsEOPsnake();
/* Mengirimkan true jika currentCharSnake = MARKS */

void startFromFile(char *str);
/* Mesin siap dioperasikan. pitaSnake disiapkan untuk dibaca.
   Karakter pertama yang ada pada pitaSnake posisinya adalah pada jendela.
   pitaSnake baca diambil dari sebuah file yang berasal dari parameter input berupa string nama file.
   I.S. : sembarang
   F.S. : currentCharSnake adalah karakter pertama pada pitaSnake
          Jika currentCharSnake != MARKS maka EOPsnake akan padam (false)
          Jika currentCharSnake = MARKS maka EOPsnake akan menyala (true) 
          finish bernilai salah karena belum mencapai akhir dari file */

void advTerminal();
/* I.S. : Karakter pada jendela = currentCharSnake, currentCharSnake != ENTER
   F.S. : currentCharSnake adalah karakter berikutnya dari currentCharSnake yang lama,
          currentCharSnake mungkin = ENTER
          Jika  currentCharSnake = ENTER maka EOPsnake akan menyala (true) */

void advFile();
/* pitaSnake dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentCharSnake, currentCharSnake != MARKS
   F.S. : currentCharSnake adalah karakter berikutnya dari currentCharSnake yang lama,
          proses akan berenti bila sudah mencapai kondisi EOF atau End Of File yang akan
          menyala ketika sudah terjadi error atau tidak bisa melakukan pembacaan kembali
          finish bernilai TRUE yang bemakna file sudah selesai dibaca */ 

#endif