#include <stdio.h>
#include <stdlib.h>
#include "skipgame.h"
#include "queue.h"
#include "mesinkata.h"
 
void SKIPGAME(Queue *antriangame, int n){
   Word temp;
   int i = 0;
 
   if (isEmpty(*antriangame)){
       printf("Tidak ada permainan di dalam daftar game-mu \n");
   } else if (n > length (*antriangame)){
       for (i = 0; i < length (*antriangame) ;i++){
           dequeue (antriangame, &temp);
       }
       printf("Tidak ada lagi permainan di dalam daftar game-mu \n");
   } else {
       for (i=0; i<n; i++){
           dequeue (antriangame, &temp);
       }
       playGame (*antriangame);
 
   }
}
 
// Melewatkan permainan sebanyak n yang terdapat pada antrian game pribadi
 
/* I.S
1. Queue game mungkin kosong,
2. Game telah dijalankan,
3. Jumlah queue game mungkin lebih banyak dari daftar game yang tersedia */
 
/* F.S
1. Jika queue game antrian pribadi pemain kosong maka akan menampilkan pesan "Tidak ada permainan di dalam daftar game-mu"
2. Jika jumlah n melebihi jumlah permainan yang ada di daftar antrian permainan, menampilkan pesan "Tidak ada lagi permainan di daftar game-mu
3. Jika jumlah n kurang dari jumlah permainan yang ada daftar antrian permainan, akan dimainkan game dengan queue teratas saat ini setelah
n game dilewatkan */
 
 
 

