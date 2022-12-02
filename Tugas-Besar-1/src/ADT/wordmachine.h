#ifndef WORD_ENGINE_H
#define WORD_ENGINE_H

# include "boolean.h"
# include "charmachine.h"
 
#define CAPACITY 100
#define BLANK ' '

typedef struct {
   char contents[CAPACITY]; /* container penyimpan kata, indeks yang dipakai [0..CAPACITY-1] */
   int length;
} Worde;

/* Word Engine State */
extern boolean endWord;
extern Worde currentWorde;

void IgnoreBlankss();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ? BLANK atau currentChar = NEWLINE */

void STARTWORDS();
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = NEWLINE; 
          atau endWord = false, currentWorde adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORDS();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWorde adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin NEWLINE
          Jika currentChar = NEWLINE, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure CopyWordS */

void CopyWordS();
/* Mengakuisisi kata, menyimpan dalam currentWorde
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWorde berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = NEWLINE; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */


void IgnoreBlankssDin();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ? BLANK atau currentChar = NEWLINE */

void STARTWORDSDin();
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = NEWLINE; 
          atau endWord = false, currentWorde adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORDSDin();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWorde adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin NEWLINE
          Jika currentChar = NEWLINE, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure CopyWordS */

void CopyWordSDin();
/* Mengakuisisi kata, menyimpan dalam currentWorde
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWorde berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = NEWLINE; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */

void STARTLOAD(char *filename);

void ADVLOADS();

void ADVWORDSLOAD();

void CopyWordSLoad();

void IgnoreNewLineS();

char* scaninput();

char* firstword(char* input);

char* secondword(char* input);

boolean IsStrEq(char string1[], char string2[]);

char *scanword(Worde Word);

int ScanNum(Worde word);
// Menghasilkan integer dari sebuah kata

boolean IsWordStr(Worde word, char string[]);
// Menghasilkan true jika string pada kata sama dengan string yang dibandingkan

int LengthStr(char string[]);
// Menghitung panjang dari suatu string

char* concatstringbaru(char* namafilenya);

#endif
