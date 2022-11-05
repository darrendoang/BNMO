#include "playgame.h"
#include "queuegame.h"

void PLAYGAME(Queue *antriangame)
{
    ElType val;
    printf("Berikut adalah daftar Game-mu\n");

    if (isEmpty(*antriangame)){
        printf("Daftar game kosong.");
        QUEUEGAME();
    }
    else{
        int i,x=0;
        for (i=(*antriangame).idxHead; i< length(*antriangame); i++){
            printf("%d. %s\n", x+1, (*antriangame).buffer[i]);
            x++;
        }
    }
    printf("\n");

    char *play = (*antriangame).buffer[(antriangame).idxHead];
    if (str_comp(play, "RNG")){
        printf("Loading RNG . . . \n");
        dequeue(antriangame,&val);
        RNG();
    }
    else if (str_comp(play, "DINER DASH")){
        printf("Loading DINER DASH . . . \n");
        dequeue(antriangame,&val);
        dinner_dash();

    }
    else{
        printf("Game %s masih dalam maintenance, belum dapat dimainkan.\n",play);
        printf("Silahkan pilih game lain.\n");
    }
}

