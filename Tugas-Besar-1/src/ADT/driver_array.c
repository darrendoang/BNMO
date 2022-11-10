#include "array.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    // Membuat array kosong
    Array test, test_copy;
    MakeEmpty(&test);

    // Melihat jumlah maksimum elemen di array
    printf("Maksimum jumlah elemen: %d\n", MaxNbEl(test));

    // Melihat jumlah elemen di array
    printf("Jumlah elemen: %d\n", NbElmt(test));

    // Melihat apakah array empty atau full
    if (IsEmpty(test)){
        printf("Array kosong\n");
    }
    else if (IsFull(test)){
        printf("Array penuh\n");
    }

    // Mengisi array
    printf("Mengisi array ...");
    int i;
    for (i = 0; i < 100; i++){
        SetEl(&test, i, i*2);
    }
    SetNeff(&test, i);

    // Melihat apakah array empty atau full
    if (IsEmpty(test)){
        printf("Array kosong\n");
    }
    else if (IsFull(test)){
        printf("Array penuh\n");
    }

    // Melihat jumlah elemen di array
    printf("Jumlah elemen: %d\n", NbElmt(test));

    // Menulis isi array
    TulisIsi(test);

    // Mencari nilai dan indeks pertama serta terakhir array
    printf("Nilai indeks pertama array adalah %d\n", GetElmt(test, GetFirstIdx(test)));
    printf("Nilai indeks terakhir array adalah %d\n", GetElmt(test, GetLastIdx(test)));

    // Mencari nilai dan indeks maksimum serta minimum array
    printf("Nilai maksimum adalah %d dengan indeks %d\n", ValMax(test), IdxMaxTab(test));
    printf("Nilai minimum adalah %d dengan indeks %d\n", ValMin(test), IdxMinTab(test));

    // Mengecek validitas indeks
    printf("Apakah indeks nomor 50 valid: ");
    if (IsIdxValid(test, 50)){ // Ya
        printf("Ya\n");
    }
    else{
        printf("Tidak\n");
    }
    printf("Apakah indeks nomor 150 valid: "); // Tidak
    if (IsIdxValid(test, 150)){
        printf("Ya\n");
    }
    else{
        printf("Tidak\n");
    }

    // Mengecek apakah indeks efektif
    printf("Apakah indeks nomor 99 efektif: "); // Ya
    if (IsIdxEff(test, 99)){
        printf("Ya\n");
    }
    else{
        printf("Tidak\n");
    }

    // Menyalin array
    printf("Menyalin array test ke test_copy...");
    SetTab(test, &test_copy);
    TulisIsi(test_copy);

    return 0;
}