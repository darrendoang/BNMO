#include <stdio.h>
#include "queuegame.h"
#include "listgame.h"

void QUEUEGAME(Queue *antriangame, List gamelist)

{
    int gamenumber;
    printf("Berikut adalah daftar antrian game-mu\n");

    if (isEmpty(*antriangame)){
        printf("Tidak ada game dalam daftar antrian \n");
    }
    else{
        int i = 0;
        for (i; i < length(*antriangame); i++){
            printf("%d. %s\n", i+1, antriangame->buffer[i]);
        }
    }
    printf("\n");

    LISTGAME();
    printf("\n");
    
    scanf("Nomor Game yang mau ditambahkan ke antrian: %d\n", &gamenumber);
    if (gamenumber > length(gamelist)){
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
    }
    else{
        enqueue(antriangame, Get(gamelist, gamenumber));
        printf("Game berhasil ditambahkan kedalam daftar antrian.\n");
    }

}






