/* File: mesinsnake.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINSNAKE_H__
#define __MESINSNAKE_H__

#include "boolean.h"
#include "mesinkaraktersnake.h"

#define Nmaxs 100
#define BLANK ' '

typedef struct
{
   char TabWord[Nmaxs]; /* container penyimpan kata, indeks yang dipakai [0..Nmaxs-1] */
   int Length;
} Words;

/* State Mesin Kata */
extern boolean EndWordSnake;
extern Words currentWords;
extern Words currentCommand;

void IgnoreBlanksSnake();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentCharSnake sembarang
   F.S. : currentCharSnake ≠ BLANK atau currentCharSnake = MARKS */

void STARTWORDsnake();
/* I.S. : currentCharSnake sembarang
   F.S. : EndWordSnake = true, dan currentCharSnake = MARKS;
          atau EndWordSnake = false, currentWords adalah kata yang sudah diakuisisi,
          currentCharSnake karakter pertama sesudah karakter terakhir kata */

void startWFile(char * file);
/* I.S. : currentCharSnake dalam file sembarang
   F.S. : Finish = true;
          atau Finish = false, currentWords adalah kata yang sudah diakuisisi,
          currentCharSnake karakter pertama sesudah karakter terakhir kata */

void copywFile();
/* I.S. : currentCharSnake sembarang
   F.S. : currentWords adalah kata yang sudah diakuisisi,
          currentCharSnake karakter pertama sesudah karakter terakhir kata */

void igBlankFile();
/* Mengabaikan satu atau beberapa BLANK pada file
   I.S. : currentCharSnake sembarang
   F.S. : currentCharSnake ≠ BLANK */

void advNewlineFile();
/* I.S. : currentCharSnake sembarang
   F.S. : currentWords adalah kata yang sudah diakuisisi,
          currentCharSnake karakter pertama sesudah karakter terakhir kata */

void ADVWORDsnake();
/* I.S. : currentCharSnake adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWords adalah kata terakhir yang sudah diakuisisi,
          currentCharSnake adalah karakter pertama dari kata berikutnya, mungkin MARKS
          Jika currentCharSnake = MARKS, EndWordSnake = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */


void CopyWordsnake();
/* Mengakuisisi kata, menyimpan dalam currentWords
   I.S. : currentCharSnake adalah karakter pertama dari kata
   F.S. : currentWords berisi kata yang sudah diakuisisi;
          currentCharSnake = BLANK atau currentCharSnake = MARKS;
          currentCharSnake adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi Nmaxs, maka sisa kata "dipotong" */

void advNewline();
/* Mengabaikan satu atau beberapa ENTER
   I.S. : currentCharSnake sembarang
   F.S. : currentCharSnake ≠ ENTER atau currentCharSnake = MARKS */

Words concatWord(Words w1, Words w2);
/* Menggabungkan dua kata menjadi satu kata */

boolean isWordEqual(Words a, Words b);
/* Mengembalikan true jika kata a dan b sama */

void displayWord(Words w);
/* Menampilkan kata w */

void copyWordFromWord(Words w1, Words *w2);
/* Menyalin kata w1 ke w2 */

void STARTCOMMAND ();
/* I.S. : currentCharSnake sembarang
   F.S. : EndWordSnake = true, dan currentCharSnake = MARKS;
          atau EndWordSnake = false, currentWords adalah kata yang sudah diakuisisi,
          currentCharSnake karakter pertama sesudah karakter terakhir kata */

void ADVCOMMAND ();
/* I.S. : currentCharSnake adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWords adalah kata terakhir yang sudah diakuisisi,
          currentCharSnake adalah karakter pertama dari kata berikutnya, mungkin MARKS
          Jika currentCharSnake = MARKS, EndWordSnake = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyCommand ();
/* Mengakuisisi kata, menyimpan dalam currentWords
   I.S. : currentCharSnake adalah karakter pertama dari kata
   F.S. : currentWords berisi kata yang sudah diakuisisi;
          currentCharSnake = BLANK atau currentCharSnake = MARKS;
          currentCharSnake adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi Nmaxs, maka sisa kata "dipotong" */

void STARTGAMENAME ();
/* I.S. : currentCharSnake sembarang
   F.S. : EndWordSnake = true, dan currentCharSnake = MARKS;
          atau EndWordSnake = false, currentWords adalah kata yang sudah diakuisisi,
          currentCharSnake karakter pertama sesudah karakter terakhir kata */

void ADVGAMENAME ();
/* I.S. : currentCharSnake adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWords adalah kata terakhir yang sudah diakuisisi,
          currentCharSnake adalah karakter pertama dari kata berikutnya, mungkin MARKS
          Jika currentCharSnake = MARKS, EndWordSnake = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyGameName ();
/* Mengakuisisi kata, menyimpan dalam currentWords
   I.S. : currentCharSnake adalah karakter pertama dari kata
   F.S. : currentWords berisi kata yang sudah diakuisisi;
          currentCharSnake = BLANK atau currentCharSnake = MARKS;
          currentCharSnake adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi Nmaxs, maka sisa kata "dipotong" */

void IgnoreDots ();
/* Mengabaikan satu atau beberapa titik
   I.S. : currentCharSnake sembarang
   F.S. : currentCharSnake ≠ BLANK atau currentCharSnake ≠ '.' */

int stringLength(char *str);
/* Mengembalikan panjang string */

Words stringToWord(char *str);
/* Mengubah string menjadi kata */

char* wordToString(Words w);
/* Mengubah kata menjadi string */

int wordToInt(Words w);
/* Mengubah kata menjadi integer */

Words intToWord(int n);
/* Mengubah integer menjadi kata */

int commandWord(Words w);
/* Mengembalikan jumlah kata pada command */

Words lowerWord(Words w);
/* Mengubah kata menjadi huruf kecil */

Words upperWord(Words w);
/* Mengubah kata menjadi huruf besar */

Words charToWord(char c);
/* Mengubah karakter menjadi kata */

char wordToChar(Words w);
/* Mengubah kata menjadi karakter */

#endif