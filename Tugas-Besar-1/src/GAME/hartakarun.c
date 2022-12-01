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
    char jalur;

    while(!isOneElmt(x)){
        char jalur;

        while (!validInput){

            printf("Pilih jalur yang ingin diambil ('L'/'R') : ");
            scanf(" %c",&jalur);
            
            if (jalur == 'L'){
                printf("Jalur kiri telah dipilih.\n");
                hasil += ROOT(LEFT(x));
                x=LEFT(x);
                validInput = true;  
            }

            else if (jalur == 'R'){
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
    int jumlah;

    //input jumlah daun
    printf("Banyak peti harta karun yang dapat digali : \n");
    scanf("%d", &jumlah);

    //jumlah daun harus lebih dari 0
    if(jumlah <= 0){
        printf("Masukkan minimal 1 peti harta karun !\n");
        return 0;
    }


    int temp = jumlah;
    while(temp%2 == 0){
        temp /= 2;
    }
    if(temp != 1){
        printf("Jumlah masukan tidak sesuai \n");
        return 0;
    }

    int lim = (jumlah*2)-1;
    BinTree ar[lim];
    for(int i = 0; i < jumlah;i++){
        int x;
        printf("Masukkan jumlah koin di dalam peti  : \n");
        scanf("%d", &x);
        BinTree t = NewTree(x, NULL, NULL);
        ar[i] = t;
    }
    int j = 0;
    while(jumlah < lim){
        BinTree l, r;
        BinTree t;
        l = ar[j];
        r = ar[j+1];
        t = NewTree((ROOT(l) * ROOT(r)), l, r);
        ar[jumlah] = t;
        j += 2;
        jumlah++;
    }
    BinTree p = ar[lim-1];
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