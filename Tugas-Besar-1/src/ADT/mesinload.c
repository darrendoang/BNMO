#include "../ADT/mesinload.h"
#include <stdio.h>
#include <stdlib.h>

void StartLOAD(char *filename)
{
    pita = fopen(filename, "r");
    ADVLOAD();
}

void IgnoreNewLine() {

    while (currentChar == MARK) {
        ADVLOAD();
    }
}

void ADVWORDLOAD() {
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
    // KAMUS LOKAL
    // ALGORITMA
    IgnoreNewLine();
    if (retval < 0) {
        EndWord = true;
    } else {
        CopyWordLOAD();
    }
}

void CopyWordLOAD() {
    int i = 0;
    while ((currentChar != MARK) && i < NMax && !EOP) {
        currentWord.TabWord[i] = currentChar; 
        ADVLOAD();
        i++;
    }
    currentWord.Length = i;
}

void ADVLOAD() {
	retval = fscanf(pita,"%c",&currentChar);
	EOP = (retval < 0);
	if (EOP) {
        fclose(pita);
 	}
}