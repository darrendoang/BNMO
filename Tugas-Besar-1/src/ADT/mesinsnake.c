#include <stdio.h>
#include <stdlib.h>
#include "mesinsnake.h"

boolean EndWordSnake ;
Words currentWords ;
Words currentCommand;

void IgnoreBlanksSnake() 
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentCharSnake sembarang
   F.S. : currentCharSnake ≠ BLANK atau currentCharSnake = MARKS */
{
    while (currentCharSnake == BLANK || currentCharSnake == ENTER) {
        ADVsnake() ;
    }
}

void IgnoreDots() {
    while (currentCharSnake == BLANK || currentCharSnake == '.') {
        advTerminal() ;
    }
}

void startWFile(char * file)
/* */
{
    finish = false;
    startFromFile(file);
    copywFile();
}

void copywFile()
/* */
{
    int i = 0;
    while(currentCharSnake != ENTER && !finish) {
        if(i < Nmaxs) {
            currentWords.TabWord[i] = currentCharSnake;
            i++;
            advFile();
        }
    }
    if(i > Nmaxs) {
        currentWords.Length = Nmaxs;
    } else {
        currentWords.Length = i;
    }
}

void igBlankFile()
/* */
{
    while(currentCharSnake == BLANK) {
        advFile();
    }
}

void advNewlineFile()
{
    Words EMPTY = {"", 0};
    currentWords = EMPTY;
    if(currentCharSnake == ENTER){
        EndWordSnake = false;
        advFile();
        copywFile();
    }
}

void STARTWORDsnake()
/* I.S. : currentCharSnake sembarang
   F.S. : EndWordSnake = true, dan currentCharSnake = MARKS;
          atau EndWordSnake = false, currentWords adalah kata yang sudah diakuisisi,
          currentCharSnake karakter pertama sesudah karakter terakhir kata */
{
    STARTsnake();
    IgnoreBlanksSnake() ;
    if (currentCharSnake == MARKS) {
            EndWordSnake = true;
    } 
    else {
        EndWordSnake = false;
        ADVWORDsnake() ;
    }
}

void ADVWORDsnake() 
/* I.S. : currentCharSnake adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWords adalah kata terakhir yang sudah diakuisisi,
          currentCharSnake adalah karakter pertama dari kata berikutnya, mungkin MARKS
          Jika currentCharSnake = MARKS, EndWordSnake = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

{
    IgnoreBlanksSnake () ;
    if (currentCharSnake == MARKS && !EndWordSnake) {
        EndWordSnake = true ;
    }
    else {
        CopyWordsnake() ;
        IgnoreBlanksSnake();
    }
}

void CopyWordsnake() 
/* Mengakuisisi kata, menyimpan dalam currentWords
   I.S. : currentCharSnake adalah karakter pertama dari kata
   F.S. : currentWords berisi kata yang sudah diakuisisi;
          currentCharSnake = BLANK atau currentCharSnake = MARKS;
          currentCharSnake adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi Nmaxs, maka sisa kata "dipotong" */
{
    int i; 
    i = 0; 
    while ((currentCharSnake != MARKS) && (currentCharSnake != BLANK) && (currentCharSnake != ENTER)) {
        if (i < Nmaxs)
        {
            currentWords.TabWord[i] = currentCharSnake ;
            i++;
        }
        ADVsnake();
    }
    currentWords.Length = i;
}

void advNewline()
{
    Words EMPTY = {"", 0};
    currentWords = EMPTY;
    if(currentCharSnake == MARKS){
        EndWordSnake = false;
        ADVsnake();
        CopyWordsnake();
    }
}

Words concatWord(Words w1, Words w2)
{
    Words ans;
    ans.Length = w1.Length + w2.Length;
    int i;
    for(i = 0; i < w1.Length; i++){
        ans.TabWord[i] = w1.TabWord[i];
    }
    for(i = 0; i < w2.Length;i++){
        ans.TabWord[i+w1.Length] = w2.TabWord[i];
    }
    return ans;
}

boolean isWordEqual(Words a, Words b)
{
    if(a.Length != b.Length){
        return false;
    }
    else{
        int i = 0;
        boolean flag = true;
        while(i < a.Length && flag){
            if(a.TabWord[i] != b.TabWord[i]){
                flag = false;
            }
            i++;
        }
        return flag;
    }
}

void displayWord(Words w)
{
    int i;
    for(i = 0; i<w.Length;i++){
        printf("%c", w.TabWord[i]);
    }
    printf("\n");
}

void copyWordFromWord(Words w1, Words *w2)
{
    w2->Length = w1.Length;
    for(int i = 0; i < w1.Length; i++){
        w2->TabWord[i] = w1.TabWord[i];
    }
}

void STARTCOMMAND () {
    STARTsnake();
    IgnoreBlanksSnake();
    if (currentCharSnake == ENTER) {
        EndWordSnake = true;
    } else {
        EndWordSnake = false;
        ADVCOMMAND();
    }
}

void ADVCOMMAND () {
    IgnoreDots();
    if (currentCharSnake == ENTER && !EndWordSnake) {
        EndWordSnake = true;
    } else {
        CopyCommand();
        IgnoreDots();
    }
}

void CopyCommand () {
    int i;
    i = 0;
    while ((currentCharSnake != BLANK) && (currentCharSnake != ENTER)) {
        if (i < Nmaxs) {
            currentCommand.TabWord[i] = currentCharSnake;
            i++;
        }
        advTerminal();
    }
    currentCommand.Length = i;
}

void STARTGAMENAME () {
    STARTsnake();
    IgnoreDots();
    if (currentCharSnake == ENTER) {
        EndWordSnake = true;
    } else {
        EndWordSnake = false;
        ADVGAMENAME();
    }
}

void ADVGAMENAME () {
    IgnoreDots();
    if (currentCharSnake == ENTER && !EndWordSnake) {
        EndWordSnake = true;
    } else {
        CopyGameName();
        IgnoreDots();
    }
}

void CopyGameName () {
    int i;
    i = 0;
    while ((currentCharSnake != ENTER)) {
        if (i < Nmaxs) {
            currentCommand.TabWord[i] = currentCharSnake;
            i++;
        }
        advTerminal();
    }
    currentCommand.Length = i;
}

int stringLength(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

Words stringToWord(char *str)
{
    Words Words;
    int i;
    
    Words.Length = stringLength(str);
    for (i = 0; i < Words.Length; i++)
    {
        Words.TabWord[i] = str[i];
    }

    Words.TabWord[i] = '\0';

    return Words;
}

char* wordToString(Words Words)
{
    char *str = (char *)malloc(sizeof(char) * Words.Length);
    for (int i = 0; i < Words.Length; i++)
    {
        str[i] = Words.TabWord[i];
        if (i == Words.Length - 1)
        {
            str[i + 1] = '\0';
        }
    }
    return str;
}

int wordToInt(Words Words) {
    int num, i;
    
    num = 0;

    for (i = 0; i < Words.Length; i++)
    {
        num = num * 10 + (Words.TabWord[i] - '0');
    }
    return num;
}

Words intToWord(int n) {
    Words Words;
    int i, j, temp;
    
    i = 0;
    temp = n;

    while (temp != 0)
    {
        temp /= 10;
        i++;
    }

    Words.Length = i;

    for (j = i - 1; j >= 0; j--)
    {
        Words.TabWord[j] = (n % 10) + '0';
        n /= 10;
    }

    return Words;
}

int commandWord(Words w) {
    int i;

    i = 0;

    while (!EndWordSnake) {
        ADVCOMMAND();
        i++;
    }

    return i;
}

Words lowerWord (Words w) {
    Words lower;
    int i;

    lower.Length = w.Length;

    for (i = 0; i < w.Length; i++) {
        if (w.TabWord[i] >= 'A' && w.TabWord[i] <= 'Z') {
            lower.TabWord[i] = w.TabWord[i] + 32;
        } else {
            lower.TabWord[i] = w.TabWord[i];
        }
    }

    return lower;
}

Words upperWord (Words w) {
    Words upper;
    int i;

    upper.Length = w.Length;

    for (i = 0; i < w.Length; i++) {
        if (w.TabWord[i] >= 'a' && w.TabWord[i] <= 'z') {
            upper.TabWord[i] = w.TabWord[i] - 32;
        } else {
            upper.TabWord[i] = w.TabWord[i];
        }
    }

    return upper;
}

Words charToWord(char c) {
    Words Words;
    Words.Length = 1;
    Words.TabWord[0] = c;
    return Words;
}

char wordToChar(Words w) {
    return w.TabWord[0];
}