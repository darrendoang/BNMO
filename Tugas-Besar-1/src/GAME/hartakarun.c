#include "hartakarun.h"

int peti(BinTree x)
{
    if (isOneElmt(x)){
        return ROOT(x);
    }
    else{
        int left;
        int right;
        if(!isTreeEmpty(x)){
            left = ROOT(x) + peti(LEFT(x));
            right = ROOT(x) + peti(RIGHT(x));

            if (left >= right){
                return left;
            }
            else if (right > left){
                return right;
            }

        }
    }
}

int PathChosen(BinTree x)
{
    boolean validInput = false;
    int hasil = ROOT(x);

    while(!isOneElmt(x)){
        while (!validInput){

            printf("Pilih jalur yang ingin diambil ('kiri'/'kanan') : ");
            char  *jalur ;
            jalur = READINPUT() ;
            
            if (jalur == "kiri" || jalur=="Kiri" || jalur=="KIRI"){
                printf("Jalur kiri telah dipilih.\n");
                hasil += ROOT(LEFT(x));
                x=LEFT(x);
                validInput = true;  
            }

            else if (jalur == "kanan" || jalur=="Kanan" || jalur=="KANAN"){
                printf("Jalur kanan telah dipilih.\n");
                hasil += ROOT(RIGHT(x));
                x=RIGHT(x);
                validInput = true;
            }

            else{
                printf("Masukkan invalid.\n");
            }

        }
        validInput = false;
    }
    return hasil;
}



BinTree TimesTwo()
{
    int n;

    //input jumlah daun
    printf("Banyak peti harta karun yang dapat digali : \n");
    char  *jumlah ;
    jumlah = READINPUT() ;
    n= StrToInt_input(jumlah , str_len(jumlah));


    //jumlah daun harus lebih dari 0
    if(n <= 0){
        printf("Masukkan minimal 1 peti harta karun !\n");
        return 0;
    }


    int temp = n;
    while(temp%2 == 0){
        temp /= 2;
    }
    if(temp != 1){
        printf("Jumlah masukan tidak sesuai \n");
        return 0;
    }

    int batas = (n*2)-1;
    BinTree ar[batas];
    for(int i = 0; i < n;i++){
        int x;
        printf("Masukkan jumlah koin di dalam peti  : \n");
        char  *koin ;
        koin = READINPUT() ;
        x= StrToInt_input(koin , str_len(koin));

        BinTree t = NewTree(x, NULL, NULL);
        ar[i] = t;
    }
    int j = 0;
    while(n < batas){
        BinTree left, right;
        BinTree t;
        left = ar[j];
        right = ar[j+1];
        t = NewTree((ROOT(left) * ROOT(right)), left, right);
        ar[n] = t;
        j += 2;
        n++;
    }
    BinTree p = ar[batas-1];
    return p;

}

int hartakarun(){

    int score;

    //Pembuatan tree 
    //Parent dari tree merupakan hasil perkalian kedua anak

    printf("\n --------------------------------\n");
    printf("\n|                                |\n");
    printf("\n|  CREATE YOUR OWN TREASURE MAP  |\n");
    printf("\n|                                |\n");
    printf("\n --------------------------------\n");
    printf("\n");

    BinTree x = TimesTwo();
    printf("\n Jalur untuk mendapatkan peti harta karun tujuan : \n");
    printTree(x, 2);
    printf("\n");

    if(PathChosen(x)==peti(x)){
        printf("\nJalur dengan harta karun terbanyak berhasil ditemukan.\n");
        printf("Anda menang !\n");
        score=100;
    }
    else{
        printf("\nJalur yang anda pilih salah.\n");
        printf("Anda kalah !\n");
        score=0;
    }

    return score;

}
