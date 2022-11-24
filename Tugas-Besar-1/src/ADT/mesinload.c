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