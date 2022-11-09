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

void SalinWord(Word kata1, Word *kata2){
    kata2->Length = kata1.Length;
    for (int i = 0; i < kata1.Length; i++){
        kata2->TabWord[i] = kata1.TabWord[i];
    }
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

int StrToInt_input(char *str, int length)
{
    int i;
    int res;
    res = 0;
    for (i = 0; i < length; i++)
    {
        res = res * 10 + (str[i] - '0');
    }
    return res;
}

int str_len(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

char *KataPertama(char *str)
{
    int i = 0;
    char *katapertama = (char *)malloc(50 * sizeof(char));
    while (str[i] != ' ')
    {
        *(katapertama + i) = str[i];
        i++;
    }
    *(katapertama + i) = '\0';

    return katapertama;
}
/*
   mengembalikan kata pertama untuk string
*/

char *KataKedua(char *str)
{
    int i = 0;
    int idx = 0;
    char *katakedua = (char *)malloc(50 * sizeof(char));
    while (str[i] != ' ')
    {
        i++;
    }
    i++;
    while (str[i] != '\0')
    {
        *(katakedua + idx) = str[i];
        idx++;
        i++;
    }

    *(katakedua + idx) = '\0';
    return katakedua;
}

int blank_count(char *strg)
{
    int i, count;
    count = 0;
    for (i = 0; i < str_len(strg); i++)
    {
        if (strg[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

int str_comp(char str1[], char str2[]){
    
    int i=0;

    while(str1[i] == str2[i]){
        if( str1[i] == '\0' || str2[i] == '\0' ) 
            break;
        i++;
    }

    if( str1[i] == '\0' &&  str2[i] == '\0' )    
        return true;    
    else    
        return false; 
}

char *filetodir(char *file)
{
    char dir[8] = "../data/";
    char *dir_result = (char *)malloc(100 * sizeof(char));
    int i=0;
    while(i<8)
    {
        dir_result[i] = dir[i];
        i++;
    }
    int idx= 0;
    while(file[idx] != '\0')
    {
        dir_result[i] = file[idx];
        i++;
        idx++;
    }
    dir_result[i] ='\0';
    return dir_result;
}