#include "wordmachine.h"
#include <stdio.h>
#include <stdlib.h>

boolean endWord;
Worde currentWordee;
static FILE * pita;
static int retval;

void IgnoreBlankss(){
	while (currentCharS == BLANK || currentCharS == NEWLINE)
   {
		ADVS();
	}
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentCharS sembarang 
   F.S. : currentCharS ? BLANK atau currentCharS = MARK */

/* PITA STDIN */

void STARTWORDS(){
	STARTS();
	IgnoreBlankss();
	CopyWordS();
}
/* I.S. : currentCharS sembarang 
   F.S. : endWord = true, dan currentCharS = MARK; 
          atau endWord = false, currentWordee adalah kata yang sudah diakuisisi,
          currentCharS karakter pertama sesudah karakter terakhir kata */

void ADVWORDS(){
   CopyWordS();
}
/* I.S. : currentCharS adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWordee adalah kata terakhir yang sudah diakuisisi, 
          currentCharS adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentCharS = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure CopyWordS */

void CopyWordS(){
	IgnoreBlankss();
	currentWordee.length = 0;
	while((currentCharS != BLANK) && (currentCharS != NEWLINE)){
      if (currentWordee.length < CAPACITY){
		currentWordee.contents[currentWordee.length++] = currentCharS;
		ADVS();
      }
      else{
         break;
      }
		
	}
}
/* Mengakuisisi kata, menyimpan dalam currentWordee
   I.S. : currentCharS adalah karakter pertama dari kata
   F.S. : currentWordee berisi kata yang sudah diakuisisi; 
          currentCharS = BLANK atau currentCharS = MARK; 
          currentCharS adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */

void IgnoreBlankssDin()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentCharS sembarang
       F.S. : currentCharS ≠ BLANK atau currentCharS = MARK */
    while (currentCharS == BLANK)
    {
        ADVS();
    }
}

void STARTWORDSDin()
{
    /* I.S. : currentCharS sembarang
       F.S. : endWord = true, dan currentCharS = MARK;
              atau endWord = false, currentWordee adalah kata yang sudah diakuisisi,
              currentCharS karakter pertama sesudah karakter terakhir kata */
    STARTS();
    IgnoreBlankssDin();
    if (currentCharS == NEWLINE)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWordSDin();
    }
}

void ADVWORDSDin()
{
    /* I.S. : currentCharS adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWordee adalah kata terakhir yang sudah diakuisisi,
              currentCharS adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentCharS = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWordS */
    IgnoreBlankssDin();
    if (currentCharS == NEWLINE)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWordSDin();
        IgnoreBlankssDin();
    }
}

void CopyWordSDin()
{
    /* Mengakuisisi kata, menyimpan dalam currentWordee
       I.S. : currentCharS adalah karakter pertama dari kata
       F.S. : currentWordee berisi kata yang sudah diakuisisi;
              currentCharS = BLANK atau currentCharS = MARK;
              currentCharS adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    currentWordee.length = 0;
    while (currentCharS != BLANK && currentCharS != NEWLINE)
    {
        if (currentWordee.length < CAPACITY)
        {
            currentWordee.contents[currentWordee.length++] = currentCharS;
            ADVS();
        }
        else
            break;
    }
}
void STARTLOAD(char *filename){
   pita = fopen(filename,"r");
   ADVLOADS();
}

void ADVLOADS(){
   retval = fscanf(pita,"%c",&currentCharS);
   EOPS = (retval<0);
   if (EOPS){
      fclose(pita);
   }
}

void ADVWORDSLOAD(){
   IgnoreNewLineS();
   if (retval < 0){
      endWord = true;
   }
   else{
      CopyWordSLoad();
   }
}

void CopyWordSLoad(){
   int i = 0;
   while ((currentCharS != NEWLINE) && i < CAPACITY && !EOPS){
      currentWordee.contents[i] = currentCharS;
      ADVLOADS();
      i++;
   }
   currentWordee.length = i;
}

void IgnoreNewLineS(){
   while (currentCharS == NEWLINE){
      ADVLOADS();
   }
}

char* scaninput(){
   pita = stdin;
   char* string;
   int a;
   int i = 0;
   string = (char*) malloc(101 * sizeof(char));

   while (a = fgetc(pita))
   {
      if (a == '\n')
      {
         break;
      }
      *(string + i) = (char)a;
      i++;
   }
   *(string + i) = '\0';
   return string;
}

char* firstword(char* input){
   int i =0;
   char* output;
   output = (char*) malloc(101 * sizeof(char));

   while(input[i] != BLANK && input[i] != '\0'){
      output[i] = input[i];
      i++;
   }
   output[i] = '\0';

   return(output);
}

char* secondword(char* input){
   char* output2;
   output2 = (char*) malloc(101 * sizeof(char));

   int k = 0;
   while(input[k] != BLANK){
      k++;
   }

   int idx = k+1;

   int idxout = 0;
   while(input[idx] != BLANK && input[idx] != '\0'){
      output2[idxout] = input[idx];
      idx++;
      idxout++;
   }
   output2[idxout] = '\0';

   return(output2);
}

boolean IsStrEq(char string1[], char string2[]){
   // Menghasilkan true jika string1 sama dengan string2 yang dibandingkan
   int i = 0;
   if(LengthStr(string1) == LengthStr(string2)){
      while(i < LengthStr(string1)){
         if(string1[i] != string2[i]){
            return false;
         }
      i++;
      }
      return true;
   }
   return false;
}

char *scanword(Worde Word)
{
    char *str;
    str = malloc(Word.length * sizeof(char));
    int i = 0;
    while (i < Word.length)
    {
        *(str + i) = Word.contents[i];
        i++;
    }
    str[i] = '\0';
    return str;
}

int ScanNum(Worde word){
   // Menghasilkan integer dari sebuah kata
   int result = 0;
   int i = 0;
   while( i < word.length){
      result *= 10;
      result += (int) (word.contents[i] - '0');
      i++;
   }
   return result;
}

boolean IsWordStr(Worde word, char string[]){
   // Menghasilkan true jika string pada kata sama dengan string yang dibandingkan
   int i = 0;
   if(word.length == LengthStr(string)){
      while(i < word.length){
         if(word.contents[i] != string[i]){
            return false;
         }
      i++;
      }
      return true;
   }
   return false;
}

int LengthStr(char string[]){
   // Menghitung panjang dari suatu string
   int i = 0;
   while (string[i] != '\0'){
      i++;
   }
   return i;
}

char* concatstringbaru(char* namafilenya){
   char* str1 = (char*) malloc(101 * sizeof(char));
   char* str2= (char*) malloc(101 * sizeof(char));
   str1= "../data/";
   str2= namafilenya;
   char* str3 = (char*) malloc(101 * sizeof(char));
   int i = 0, j = 0;
   while (str1[i] != '\0') {
      str3[j] = str1[i];
      i++;
      j++;
   }
   i = 0;
   while (str2[i] != '\0') {
      str3[j] = str2[i];
      i++;
      j++;
   }
   str3[j] = '\0';
   return str3;       
}
