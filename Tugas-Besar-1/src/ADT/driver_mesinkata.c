#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>


int main(){

    // Tes katapertama katakedua
    printf("Masukkan dua buah kata!\n");
    char *testkata = READINPUT();
    char * first = KataPertama(testkata);
    char * second = KataKedua(testkata);
    printf("Kata pertama adalah %s\n" ,first);
    printf("Kata kedua adalah %s\n" ,second);

    // Tes Blank
    printf("Masukkan beberapa kata untuk mengetahui jumlah blank\n");
    char* testBlank = READINPUT();
    int blank = blank_count(testBlank);
    printf("Jumlah blank = %d\n" , blank);

    //Test Str TO INT
    printf("Masukkan nilai X dan Y untuk menghitung X + Y\n");
    printf("X : ");
    char* str_x = READINPUT();
    printf("Y : ");
    char* str_y = READINPUT();

    int x = StrToInt_input(str_x , str_len(str_x));

    int y = StrToInt_input(str_y , str_len(str_y));

    printf("Nilai X + Y = %d" , x+y);
    
    return 0;
}
