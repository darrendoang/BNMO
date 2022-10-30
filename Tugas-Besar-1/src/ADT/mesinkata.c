# include "mesinkata.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks() {
    while (currentChar == BLANK) {
        ADV();
    }
}

void STARTWORD()    {
    START();
    IgnoreBlanks();
    if (currentChar == MARK)    {
        EndWord = true;
    }
    else    {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD()  {
    IgnoreBlanks();
    if (currentChar == MARK)    {
        EndWord = true;
    }
    else    {
        CopyWord();
    }
}

void CopyWord() {
    int i;
    i = 0;  
    while ((currentChar != MARK) && (currentChar != BLANK ) && (i <= NMax-1)) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }

    if (i > NMax-1) {
        while(currentChar != BLANK) {
            ADV();
        }
    }
    currentWord.Length = i;
}