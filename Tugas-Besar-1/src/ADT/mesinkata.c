#include "mesinkata.h"
#include <stdlib.h>

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

char *READINPUT()
{
    START();
    CopyWord();
    int i;
    char *strinput;
    strinput = (char *)malloc(sizeof(char) * 100);
    for (int i = 0; i < currentWord.Length; i++)
    {
        *(strinput +i) = currentWord.TabWord[i];
    }
    *(strinput + currentWord.Length) = '\0';
    return strinput;
    
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

int StrToInt (char * str)
{
    int i=0 , output=0;
    for (int i = 0; i < currentWord.Length; i++)
    {
        output = output * 10 + (str[i] - '0');
    }
    return output;
}