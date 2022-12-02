#include <stdio.h>
#include "snake.h"
#include <math.h>
#include <time.h>

void board(List snake, List food, List meteor, List obst){
    int i =0;
    int j = 0;
    addresss p;

    for(i=0; i<5; i++){
        if(i == 0){
            printf("-------------------------------\n");
        }
        for(j = 0; j < 5; j++){
            if(j == 0){
                printf("|");
            }
            if(Searchlistdp(food, j, i) != Nilldp){
                p = Searchlistdp(food, j, i);
                if(stringLength(Infoldp(p)) > 1){
                    printf(" ");
                } else {
                    printf("  ");
                }
                printf("%s  |", Infoldp(p));
            } else if(Searchlistdp(snake, j, i) != Nilldp){
                p = Searchlistdp(snake, j, i);
                if(stringLength(Infoldp(p)) > 1){
                    printf(" ");
                } else {
                    printf("  ");
                }
                printf("%s  |", Infoldp(p));
                //p = Nextldp(p);    
            } else if(Searchlistdp(obst, j, i) != Nilldp){
                p = Searchlistdp(obst, j, i);
                if(stringLength(Infoldp(p)) > 1){
                    printf(" ");
                } else {
                    printf("  ");
                }
                printf("%s |", Infoldp(p)); 
            } else if(Searchlistdp(meteor, j, i) != Nilldp){
                p = Searchlistdp(meteor, j, i);
                if(stringLength(Infoldp(p)) > 1){
                    printf(" ");
                } else {
                    printf("  ");
                }
                printf("%s  |", Infoldp(p));
            } else {
                printf("     |");
            }
        }
        printf("\n");
        printf("-------------------------------\n");
    }

}

int ran()
{
    int a;
    a = (rand() % (5)) + 0;
    srand(time(NULL));
    return a;
}

void snakes(List * snake){
    addresss a;
    addresss tem;
    int i = 0, x=0, b, abs;

    abs = ran();
    b = ran();
    
    InsVLastlistdp(snake, "H", abs, b);
    a = Firstldp(*snake);
    while(i < 2){
        if(Posisix(a)-1 >= 0){
            InsVLastlistdp(snake, wordToString(intToWord(x+1)), (Posisix(a)-1) % 5, Posisiy(a));
        } else {
            InsVLastlistdp(snake, wordToString(intToWord(x+1)), (Posisix(a)-1 + 5), Posisiy(a));
        }
        tem = a;
        a = Nextldp(a);
        x++;
        i++;
    }
}

void dfood(List*snake, List* food, List * hmeteor, List * obst){
    int x;
    int y;

    x = ran();
    y = ran();

    if(!IsEmptylistdp(*obst)){
        if(!IsEmptylistdp(*hmeteor)){
            while(Searchlistdp((*snake), x, y) != Nilldp || Searchlistdp((*hmeteor), x, y) != Nilldp || Searchlistdp((*obst), x, y) != Nilldp){
                x = ran();
                y = ran();
            }
        } else {
            while(Searchlistdp((*snake), x, y) != Nilldp  || Searchlistdp((*obst), x, y) != Nilldp){
                x = ran();
                y = ran();
            }
        }
    } else {
        while(Searchlistdp((*snake), x, y) != Nilldp){
            x = ran();
            y = ran();
        }
    }
    InsVLastlistdp(food, "o", x, y);
}

void dmeteor(List* food, List* obst, List * meteor){
    int r;
    int s;

    r = ran();
    s = ran();

    while(Searchlistdp((*obst), r, s) != Nilldp || Searchlistdp((*food), r, s) != Nilldp){
        r = ran();
        s = ran();
    }
    InsVLastlistdp(meteor, "m", r, s);
}

void obs(List * snake, List * food, List * obst){
    int a;
    int b;

    a = ran();
    b = ran();
    while(Searchlistdp((*snake), a, b) != Nilldp || Searchlistdp((*food), a, b) != Nilldp){
        a = ran();
        b = ran();
    }
    InsVLastlistdp(obst, "(|)", a, b);    
}

void makan(List * snake, List * food, List * obst, boolean * wwin){
    elmntype tempInfoldp;
    int tempx, tempy;

    if((Posisix(Firstldp(*food)) == Posisix(Firstldp(*snake))) && (Posisiy(Firstldp(*food)) == Posisiy(Firstldp(*snake)))) {
        DelVLastlistdp(food, &tempInfoldp, &tempx, &tempy);

        if(Posisix(Lastldp(*snake)) != 0){
            if(Searchlistdp((*snake), Posisix(Lastldp(*snake))-1, Posisiy(Lastldp(*snake))) == Nilldp && Searchlistdp((*obst), Posisix(Lastldp(*snake))-1, Posisiy(Lastldp(*snake))) == Nilldp) {
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake))-1, Posisiy(Lastldp(*snake)));
            } else if(Posisiy(Lastldp(*snake)) != 0 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1) == Nilldp && Searchlistdp((*obst), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1);
            } else if(Posisiy(Lastldp(*snake)) == 0 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1 +5) == Nilldp && Searchlistdp((*obst), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1+5) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1 + 5);
            } else if(Posisiy(Lastldp(*snake)) != 4 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1) == Nilldp && Searchlistdp((*obst), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1);
            } else if(Posisiy(Lastldp(*snake)) == 4 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1 - 5) == Nilldp && Searchlistdp((*obst), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1 - 5) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1-5);
            } else if(Searchlistdp((*snake), (Posisix(Lastldp(*snake))+1)%5, Posisiy(Lastldp(*snake))) == Nilldp && Searchlistdp((*obst), (Posisix(Lastldp(*snake))+1)%5, Posisiy(Lastldp(*snake))) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), (Posisix(Lastldp(*snake)) + 1)%5, Posisiy(Lastldp(*snake)));
            }
        } else if(Posisix(Lastldp(*snake)) == 0){
            if(Searchlistdp((*snake), Posisix(Lastldp(*snake))-1 + 5, Posisiy(Lastldp(*snake))) == Nilldp && Searchlistdp((*obst), Posisix(Lastldp(*snake)) -1 + 5, Posisiy(Lastldp(*snake))) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake))-1 + 5, Posisiy(Lastldp(*snake)));
            } else if(Posisiy(Lastldp(*snake)) != 0 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1) == Nilldp && Searchlistdp((*obst), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1);
            } else if(Posisiy(Lastldp(*snake)) == 0 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1 + 5) == Nilldp && Searchlistdp((*obst), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1 + 5) == Nilldp){
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))-1 + 5);
            } else if(Posisiy(Lastldp(*snake)) != 4 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1) == Nilldp && Searchlistdp((*obst), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1) == Nilldp) {
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake)) + 1);
            } else if(Posisiy(Lastldp(*snake)) == 4 && Searchlistdp((*snake), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1 - 5) == Nilldp && Searchlistdp((*obst), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake))+1 - 5) == Nilldp) {
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), Posisix(Lastldp(*snake)), Posisiy(Lastldp(*snake)) + 1 - 5);
            } else if(Posisiy(Lastldp(*snake)) == 0 && Posisiy(Prevldp(Lastldp(*snake))) == Posisiy(Lastldp(*snake)) + 1 && Searchlistdp((*obst), (Posisix(Lastldp(*snake))+1) % 5, Posisiy(Lastldp(*snake))) == Nilldp) {
                InsVLastlistdp(snake, wordToString(intToWord(wordToInt(stringToWord(Infoldp(Lastldp(*snake)))) + 1)), (Posisix(Lastldp(*snake)) + 1) % 5, Posisiy(Lastldp(*snake)));
            }
        } else {
            printf("Ekor snake tidak dapat di-spawn ke arah manapun\n");
            *wwin = true;
        }
    }
}

void hit(List * snake, List * meteor, location * temp){
    addresss p;
    int tempx, tempy;

    if(Searchlistdp(*snake, Posisix(Firstldp(*meteor)), Posisiy(Firstldp(*meteor))) == Nilldp){
        if((*temp).x != -1){
            p = Searchlistdp(*snake, (*temp).x, (*temp).y);

            while(p != Nilldp){
                Infoldp(p) = wordToString(intToWord(wordToInt(stringToWord(Infoldp(p))) - 1));
                p = Nextldp(p);
            }
        }    
    }
}

int lengths(List snake){
    int count = 0;
    while (Firstldp(snake) != Nilldp) {
        count++;
        Firstldp(snake) = Nextldp(Firstldp(snake));
    }
    return count;
}

void belok(char x, List *s, List * hmeteor, List * obst, boolean * gagal, boolean * wwin){
    addresss p;
    addresss temp;
    int i = 0;
    int tempx, tempy;

    p = Lastldp(*s);
    printf("\n");

    if((x) == 'w'){
        if(Posisiy(Firstldp(*s)) != 0 && Searchlistdp((*hmeteor), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))-1) != Nilldp){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
            *gagal = true;
        } else if(Posisiy(Firstldp(*s)) == 0 && Searchlistdp((*hmeteor), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))-1 + 5) != Nilldp){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
            *gagal = true;
        } else if (Posisiy(Firstldp(*s)) != 0 && Searchlistdp((*obst), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))-1) != Nilldp) {
            printf("Anda menabrak obst :<\n");
            *gagal = true;
            *wwin = true;
        } else if (Posisiy(Firstldp(*s)) == 0 && Searchlistdp((*obst), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))-1 + 5) != Nilldp) {
            printf("Anda menabrak obst :<\n");
            *gagal = true;
            *wwin = true;
        } else if (Posisiy(Firstldp(*s)) != 0 && Searchlistdp((*s), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))-1) != Nilldp) {
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
            *gagal = true;
        } else if (Posisiy(Firstldp(*s)) == 0 && Searchlistdp((*s), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))-1 + 5 ) != Nilldp) {
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
            *gagal = true;
        } else {
            printf("Berhasil bergerak!\n");
            printf("Berikut merupakan peta permainan:\n");
            while(p != Firstldp(*s)){
                Posisi(p) = Posisi(Prevldp(p));
                p = Prevldp(p);
            }
            if(Posisiy(Firstldp(*s)) != 0){
                Posisiy(Firstldp(*s)) -= 1;
                *gagal = false;
            } else {
                Posisiy(Firstldp(*s)) = Posisiy(Firstldp(*s)) - 1 + 5;
                *gagal = false;
            }    
        }
    }
    else if ((x) == 's') {
        if (Posisiy(Firstldp(*s)) != 4 && Searchlistdp((*hmeteor), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))+1) != Nilldp){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
            *gagal = true;
        } else if (Posisiy(Firstldp(*s)) == 4 && Searchlistdp((*hmeteor), Posisix(Firstldp(*s)), (Posisiy(Firstldp(*s))+1)%5) != Nilldp){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
            *gagal = true;
        }
        else if (Posisiy(Firstldp(*s)) != 4 && Searchlistdp((*obst), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))+1) != Nilldp) {
            printf("Anda menabrak obst :<\n");
            *gagal = true;
            *wwin = true;
        } else if (Posisiy(Firstldp(*s)) == 4 && Searchlistdp((*obst), Posisix(Firstldp(*s)), (Posisiy(Firstldp(*s))+1)%5) != Nilldp) {
            printf("Anda menabrak obst :<\n");
            *gagal = true;
            *wwin = true;
        } else if(Posisiy(Firstldp(*s)) != 4 && Searchlistdp((*s), Posisix(Firstldp(*s)), Posisiy(Firstldp(*s))+1) != Nilldp){
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
            *gagal = true;
        } else if(Posisiy(Firstldp(*s)) == 4 && Searchlistdp((*s), Posisix(Firstldp(*s)), (Posisiy(Firstldp(*s))+1)%5) != Nilldp){
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
            *gagal = true;
        }
        else {        
            printf("Berhasil bergerak!\n");
            printf("Berikut merupakan peta permainan:\n");
            while(p != Firstldp(*s)){
                Posisi(p) = Posisi(Prevldp(p));
                p = Prevldp(p);
            }
            if(Posisiy(Firstldp(*s)) != 4){    
                Posisiy(Firstldp(*s)) += 1;
                *gagal = false;
            } else {
                Posisiy(Firstldp(*s)) = (Posisiy(Firstldp(*s)) + 1) % 5;
                *gagal = false;
            }    
        }
    }
    else if ((x) == 'a') {
        if (Posisix(Firstldp(*s)) != 0 && Searchlistdp((*hmeteor), Posisix(Firstldp(*s)) -1 , Posisiy(Firstldp(*s))) != Nilldp){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
            *gagal = true;
        } else if (Posisix(Firstldp(*s)) == 0 && Searchlistdp((*hmeteor), (Posisix(Firstldp(*s)) -1) + 5 , Posisiy(Firstldp(*s))) != Nilldp){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
            *gagal = true;
        }
        else if (Posisix(Firstldp(*s)) != 0 && Searchlistdp((*obst), Posisix(Firstldp(*s)) -1 , Posisiy(Firstldp(*s))) != Nilldp) {
            printf("Anda menabrak obst :<\n");
            *gagal = true;
            *wwin = true;
        } else if (Posisix(Firstldp(*s)) == 0 && Searchlistdp((*obst), Posisix(Firstldp(*s)) -1 + 5, Posisiy(Firstldp(*s))) != Nilldp) {
            printf("Anda menabrak obst :<\n");
            *gagal = true;
            *wwin = true;
        } else if(Posisix(Firstldp(*s)) != 0 && Searchlistdp((*s), Posisix(Firstldp(*s))-1, Posisiy(Firstldp(*s))) != Nilldp){
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
            *gagal = true;
        } else if(Posisix(Firstldp(*s)) == 0 && Searchlistdp((*s), Posisix(Firstldp(*s))-1 + 5, Posisiy(Firstldp(*s))) != Nilldp){
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
            *gagal = true;
        }
        else {
            printf("Berhasil bergerak!\n");
            printf("Berikut merupakan peta permainan:\n");
            while(p != Firstldp(*s)){
                Posisi(p) = Posisi(Prevldp(p));
                p = Prevldp(p);
            }
            if(Posisix(Firstldp(*s)) != 0){ 
                Posisix(Firstldp(*s)) -= 1;
                *gagal = false;
            } else {
                Posisix(Firstldp(*s)) = Posisix(Firstldp(*s)) - 1 + 5;
                *gagal = false;
            }
        }
    }
    else if ((x) == 'd') {
        if (Posisix(Firstldp(*s)) != 4 && Searchlistdp((*hmeteor), Posisix(Firstldp(*s)) + 1, Posisiy(Firstldp(*s))) != Nilldp){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
            *gagal = true;
        } else if (Posisix(Firstldp(*s)) == 4 && Searchlistdp((*hmeteor), (Posisix(Firstldp(*s)) + 1) % 5, Posisiy(Firstldp(*s))) != Nilldp){
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
            *gagal = true;
        }
        else if (Posisix(Firstldp(*s)) != 4 && Searchlistdp((*obst), Posisix(Firstldp(*s)) + 1, Posisiy(Firstldp(*s))) != Nilldp) {
            printf("Anda menabrak obst :<\n");
            *gagal = true;
            *wwin = true;
        }else if (Posisix(Firstldp(*s)) == 4 && Searchlistdp((*obst), (Posisix(Firstldp(*s)) + 1) %5, Posisiy(Firstldp(*s))) != Nilldp) {
            printf("Anda menabrak obst :<\n");
            *gagal = true;
            *wwin = true;
        } else if(Posisix(Firstldp(*s)) != 4 && Searchlistdp((*s), Posisix(Firstldp(*s))+1, Posisiy(Firstldp(*s))) != Nilldp){
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
            *gagal = true;
        } else if(Posisix(Firstldp(*s)) == 4 && Searchlistdp((*s), (Posisix(Firstldp(*s))+1)%5, Posisiy(Firstldp(*s))) != Nilldp){
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
            *gagal = true;
        }
        else {
            printf("Berhasil bergerak!\n");
            printf("Berikut merupakan peta permainan:\n");
            while(p != Firstldp(*s)){
                Posisi(p) = Posisi(Prevldp(p));
                p = Prevldp(p);
            }
            if(Posisix(Firstldp(*s)) != 4){    
                Posisix(Firstldp(*s)) += 1;
                *gagal = false;
            } else {
                Posisix(Firstldp(*s)) = (Posisix(Firstldp(*s)) + 1) %5;
                *gagal = false;
            }    
        }
    }
    else {
        printf("Arah tidak dikenali") ;
    }
}

void snakeOnMeteor(int * score){
    List snake;
    List food;
    List meteor;
    List hmeteor;
    List obst;
    
    char command;
    boolean validasicommand = false;
    boolean wwin = false;
    boolean donef = false;
    boolean gagal = false;
    boolean kenakepala = false;
    int test = 0;
    int turn = 1;
    //location hmeteor;

    CreateEmptylistdp(&food);
    CreateEmptylistdp(&snake);
    CreateEmptylistdp(&meteor);
    CreateEmptylistdp(&hmeteor);
    CreateEmptylistdp(&obst);
    snakes(&snake);

    printf("\n                 Selamat datang di snake on meteor!\n");
    printf(" .+:*+.+:*+.+:*+. P A N D U A N  S I N G K A T  G A M E .+*:+.+*:+.+*:+. \n");
    printf("o   : makanan yang harus dicapai agar snake bertambah panjang\n");
    printf("H   : Head dari snake yang akan diikuti oleh badannya (1, 2, dst.)\n");
    printf("M   : meteor yang akan muncul secara acak dan menyerang snake\n");
    printf("### : obst yang harus dihindari, apabila menabraknya snake akan mati\n\n");

    printf("\nMengenerate peta, snake dan makanan\n");
    printf("\nBerhasil digenerate!\n");

    printf("\n----------------------------------\n\n");

    dfood(&snake, &food, &hmeteor, &obst);
    donef = true;
    obs(&snake, &food, &obst);
    board(snake, food, meteor, obst);
    while (!wwin) {
        if(!donef){ // dfoodnya kalo belum di drop dan makanan sebelumnya belum di makan
            dfood(&snake, &food, &hmeteor, &obst);
            
            donef = true;
        }
        printf("\nTURN %d\n", turn);
        printf("Silahkan masukkan command anda: ") ;
        
        STARTCOMMAND();
        if(currentCommand.Length > 1 || commandWord(currentCommand) > 1){  
            printf("\n");                                                   
            printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
        } else{
            command = currentCommand.TabWord[0];
            if (command != 'a' && command != 'w' && command != 'd' && command != 's') {
                printf("\n");
                printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n\n") ;
            }
            else {
                validasicommand = true;
                belok(command, &snake, &hmeteor, &obst, &gagal, &wwin);
                
                if (!wwin) {
                    if(gagal == true ){
                        printf("Silahkan masukkan command lainnya\n");
                    } else {
                        elmntype tempInfoldp;
                        int tempx, tempy;

                        if(!IsEmptylistdp(meteor) && !gagal){
                            DelVLastlistdp(&meteor, &tempInfoldp, &tempx, &tempy);
                        }
                        if((Posisix(Firstldp(food)) == Posisix(Firstldp(snake))) && (Posisiy(Firstldp(food)) == Posisiy(Firstldp(snake))) && !gagal) {
                            makan(&snake, &food, &obst, &wwin);
                            donef = false;
                           
                        }
                        if(!donef){ // dfoodnya kalo belum di drop dan makanan sebelumnya belum di makan
                            dfood(&snake, &food, &hmeteor, &obst);
                            
                            donef = true;
                        }
                        
                        dmeteor(&food, &obst, &meteor);
                        
                        if(Searchlistdp(snake, Posisix(Firstldp(meteor)), Posisiy(Firstldp(meteor))) != Nilldp){
                            //kondisional search posisinya meteor sama kaya posisinya snakenya apa engga
                            if(Searchlistdp(snake, Posisix(Firstldp(meteor)), Posisiy(Firstldp(meteor))) == Firstldp(snake)){
                                elmntype temphead;
                                int headx;
                                int heady;
                                DelVFirstlistdp(&snake, &temphead, &headx, &heady);
                                wwin = true;
                                kenakepala = true;
                                board(snake, food, meteor, obst);
                                printf("Kepala snake terkena meteor :<\n");
                            } else {
                                elmntype tempbadan;
                                location postemp;
                                addresss p;

                                postemp.x = -1;
                                postemp.y = -1;
                                p = Searchlistdp(snake, Posisix(Firstldp(meteor)), Posisiy(Firstldp(meteor)));
                                if(Nextldp(p) != Nilldp){
                                    postemp = Posisi(Nextldp(p));
                                }
                                DelPlistdp(&snake, tempbadan, Posisix(Firstldp(meteor)), Posisiy(Firstldp(meteor)));
                                board(snake, food, meteor, obst);
                                hit(&snake, &meteor, &postemp);
                                printf("Anda terkena meteor\n");
                                printf("Berikut merupakan peta permainan sekarang:\n");
                                board(snake, food, meteor, obst);
                                printf("Silahkan lanjutkan permainan\n");
                                
                                InsVLastlistdp(&hmeteor, wordToString(intToWord(turn)), Posisix(Firstldp(meteor)), Posisiy(Firstldp(meteor)));
                            }
                        } else {
                
                            board(snake, food, meteor, obst);
                            printf("Anda beruntung tidak terkena meteor! ");
                            printf("Silahkan lanjutkan permainan\n");
                        }    
                        
                        turn++;
                        if(!IsEmptylistdp(hmeteor)){
                            if(wordToInt(stringToWord(Infoldp(Firstldp(hmeteor)))) + 2 == turn ){
                                elmntype temppanas;
                                int px, py;
                                DelVFirstlistdp(&hmeteor, &temppanas, &px, &py);
                            }
                        }
                    }
                }
            }
        } 
    }
    int length;
    length = lengths(snake);
    *score = length*2;
    
    printf("Game berakhir!\n");  
    printf("Skor: %d\n", *score);
}