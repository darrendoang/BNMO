#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "../ADT/charmachine.h"
#include "../ADT/wordmachine.h"
#include "../ADT/listdp.h"
#include "../ADT/arrayMap.h"
#include "../ADT/boolean.h"

int  GetInf(addressLDP P){
    if(P == NULL){
        return UndefLDP;
    }
    else{
        return Info(P);
    }
}
boolean SearchPoint(List L,int X,int Y){
    addressLDP S = First(L);
    boolean found = true;
    while (S != NilLDP && found){
        if (Absis(S) == X && Ordinat(S) == Y){
            found = false;
        }
        S = Next(S);
    }
    return found;
}

addressLDP SearchAP(List L,int i,int j){
    addressLDP P = First(L);
    boolean found = false;
    while(P != NilLDP && !found){
        if (Absis(P)==i && Ordinat(P)==j){
            found = true;
        }
        else{
            P = Next(P);
        }
    }
    if (found){
        return P; 
    }
    else{
        return NilLDP;
    }
}



void createSnake(List *L){
    CreateEmptyLDP(L);
    srand(time(NULL));
    addressLDP P1 = AlokasiLDPEkor(72);
    addressLDP P2 = AlokasiLDPEkor(1);
    addressLDP P3 = AlokasiLDPEkor(2);

    Absis(P1)=rand()%5;
    Ordinat(P1)=rand()%5;
    
    if (Absis(P1) == 0){
        if (Ordinat(P1) == 0){
            Absis(P2) = Absis(P1);
            Absis(P3) = Absis(P1);
            Ordinat(P2) = Ordinat(P1)+1;
            Ordinat(P3) = Ordinat(P1)+2;
        }
        else{
            Absis(P2) = Absis(P1);
            Absis(P3) = Absis(P1);
            if (Ordinat(P1) == 1){
                Ordinat(P2) = Ordinat(P1)+1;
                Ordinat(P3) = Ordinat(P1)+2;
            }
            else{
                Ordinat(P2) = Ordinat(P1)-1;
                Ordinat(P3) = Ordinat(P1)-2;
            }
        }
    }
    else{
        if(Ordinat(P1) == 0){
            if(Absis(P1) == 1){
                Absis(P2) = Absis(P1)-1;
                Absis(P3) = Absis(P1)-1;
                Ordinat(P2) = Ordinat(P1);
                Ordinat(P3) = Ordinat(P1)+1;
            }
            else{
                Absis(P2) = Absis(P1)-1;
                Absis(P3) = Absis(P1)-2;
                Ordinat(P2) = Ordinat(P1);
                Ordinat(P3) = Ordinat(P1);
            }
        }
        else{
            Absis(P2) = Absis(P1)-1;
            Ordinat(P2) = Ordinat(P1);
            if (Absis(P2) == 0){
                Absis(P3) = Absis(P2);
                Ordinat(P3) = Ordinat(P2)-1;
            }
            else{
                Absis(P3) = Absis(P2)-1;
                Ordinat(P3) = Ordinat(P2);
            }
        }
    }
    InsertLastLDP(L,P1);
    InsertLastLDP(L,P2);
    InsertLastLDP(L,P3);
}

void move (List *L, char* input){
    char* atas="w";
    char* kiri="a";
    char* bawah="s";
    char* kanan="d";
    addressLDP P=Last(*L);
    POINT temp;
    if (IsStrEq(input,atas)){
        temp=(*Prev(P)).posisi;
        while (Prev(P)!=NilLDP){
            (*P).posisi=temp;
            P=(P)->prev;
            if (Prev(P)!=NilLDP){
                temp=(*Prev(P)).posisi;
            }
        }
    }else if(IsStrEq(input,bawah)){
        temp=(*Prev(P)).posisi;
        while (Prev(P)!=NilLDP){
            (*P).posisi=temp;
            P = (P)->prev;
            if (Prev(P)!=NilLDP){
                temp=(*Prev(P)).posisi;
            }
        }
    }else if(IsStrEq(input,kanan)){
        temp=(*Prev(P)).posisi;
        while (Prev(P)!=NilLDP){
            (*P).posisi=temp;
            P = (P)->prev;
            if (Prev(P)!=NilLDP){
                temp=(*Prev(P)).posisi;
            }
        }
    }else if(IsStrEq(input,kiri)){
        temp=(*Prev(P)).posisi;
        while (Prev(P)!=NilLDP){
            (*P).posisi=temp;
            P = (P)->prev;
            if (Prev(P)!=NilLDP){
                temp=(*Prev(P)).posisi;
            }
        }
    }
    addressLDP a =First(*L);
    if (IsStrEq(input,kiri)){
        if (Absis(a) == 0){   
            Absis(a) = 4;
        }
        else{
            Absis(a) -= 1;
        }   
    }else if(IsStrEq(input,kanan)){
        if (Absis(a) == 4){   
            Absis(a) = 0;
        }
        else{
            Absis(a) += 1;
        }
    }else if(IsStrEq(input,atas)){
        if (Ordinat(a) == 0){   
            Ordinat(a) = 4;
        }
        else{
            Ordinat(a) -= 1;
        } 
    }else if(IsStrEq(input,bawah)){
        if (Ordinat(a)== 4){   
            Ordinat(a) = 0;
        }
        else{
            Ordinat(a) += 1;
        }
    }
}  

void createMeteor(POINT *meteor,POINT food){
    srand(time(NULL));

    int a = rand() % 5;
    int b = rand() % 5;
    boolean found;
    found = false;
    int idx=0;
    while (!found){
        if (a==food.x && b==food.y){
            if (idx % 3 == 1){
                a= (a-1) %5;
                b= (b+1) %5;
            }
            else if(idx % 3 == 0){
                a = (a+1) %5;
                b = (b-1) %5;
            }
            else{
                a = (a+1) %5;
                b = (b+1) %5;
            }
        }
        else{
            found=true;
            meteor->x = a;
            meteor->y = b;
        }
    
        if (a < 0 || b < 0){
            a = rand() % 5;
            b = rand() % 5;
        }
        idx++;
    }
}


void createObstacle(List L, POINT* obstacle){
    srand(time(NULL));

    int a = rand() % 5;
    int b = rand() % 5;

    boolean found;
    found = false;

    int i = 0;

    while (!found){
        if (SearchPoint(L,a,b)){ 
            found=true;
            obstacle->x=a;
            obstacle->y=b;
        }
        else
        {
        if (i % 3 == 1){
            a= (a - 1) % 4;
            b= (b + 1 ) % 4;
        }
        else if(i % 3 == 0){
            a=(a + 1) % 4;
            b=(b - 1) % 4;
        }
        else{
            a=(a + 1) % 4;
            b=(b + 1) % 4;
        }
        if (a < 0 || b < 0){
            a = rand() % 4;
            b = rand() % 4;
        }
        i++;
        }
    }
}

void createFood(POINT *food,List L, POINT obstacle){
    srand(time(NULL));

    int a = rand() % 5;
    int b = rand() % 5;

    boolean found;
    found = false;

    int i=0;

    while (!found){
        if (SearchPoint(L,a,b) && a != obstacle.x && b != obstacle.y){
            found = true;
            (*food).x=a;
            (*food).y=b;
        }
        else
        {
        if (i % 3 == 1){
            a= (a-1) % 5;
            b= (b+1) % 5;
        }
        else if(i % 3==0){
            a=(a+1)%5;
            b=(b-1)%5;
        }
        else{
            a=(a+1)%5;
            b=(b+1)%5;
        }
        }
        if (a < 0 || b < 0){
            a = rand() % 5;
            b = rand() % 5;
        }
        i++;
    }
}

boolean checkFoodEaten(List *L, POINT food){
    return((*First(*L))).posisi.x == food.x && ((*First(*L)).posisi.y== food.y);
}
boolean areaMeteor(List L, char* input, POINT meteor){
    addressLDP P = First(L);
    char* up="w";
    char* left="a";
    char* down="s";
    char* right="d";
    int a = Absis(P);
    int b = Ordinat(P);
    boolean met = (a == meteor.x && meteor.y == (b - 1) % 5);
    boolean e = (b == meteor.y && meteor.x == (a - 1) % 5);
    boolean o = (b == meteor.y && meteor.x == (a + 1) % 5);
    boolean r = (a == meteor.x && meteor.y == (b + 1) % 5);
    if(IsStrEq(input,up)){
        return met;
    }
    else if(IsStrEq(input,left)){
        return e;
    }
    else if(IsStrEq(input,right)){
        return o;
    }
    else if(IsStrEq(input,down)){
        return r;
    }
}
void hit(List *L,POINT food,POINT meteor){
    addressLDP a;
    a = First(*L);
    addressLDP b;
    b = Last(*L);
    boolean found;
    found = false;

    while(a != NilLDP && !found){
        if (Absis(a) == meteor.x && Ordinat(b) == meteor.y){
            found = true;    
        }
        a = Next(a);
    }

    if (found){
        if (a == NilLDP){
            DelLastLDP(L,&b);
         }
        else if(a == Next(First(*L))){
            DelLastLDP(L,&b);
            DelFirstLDP(L,&b);
        }
        else{
            while (b != Prev(a)){
                b->info= Prev(b)->info;
                b = Prev(b);
            }
            DelBeforeLDP(L,&b,a);
            printf("Anda terkena meteor!\n");
        }
    }
    else{
        printf("Anda beruntung tidak terkena meteor! Silahkan lanjutkan permainan\n");
    }
}

boolean endCond(List L,POINT meteor, POINT obstacle){
    addressLDP a;
    a = First(L);
    boolean found=false;
    a = Next(a);

    while (!found && a != NilLDP){
        if (Absis(a) == Absis(First(L)) && Ordinat(a) == Ordinat(First(L))){
            found=true;
        }
        a = Next(a);
    }
    if (!found){
        addressLDP check = First(L);
        if((check->info != 'H')){
            printf("Kepala snake terkena meteor !\n");
            Info(First(L))+= 2;
            return true;
        }
        else if(Absis(First(L)) == obstacle.x && Ordinat(First(L)) == obstacle.y){
            printf("Kepala snake menabrak obstacle\n");
            return true;
        }
        else if( GetInf(SearchAP(L,Absis(First(L))+1,Ordinat(First(L)))) < 25 &&  GetInf(SearchAP(L,Absis(First(L))-1,Ordinat(First(L)))) < 25 &&  GetInf(SearchAP(L,Absis(First(L)),Ordinat(First(L))-1)) < 25 &&  GetInf(SearchAP(L,Absis(First(L)),Ordinat(First(L))+1)) < 25){
            printf("Anda tidak bisa bergerak kemanapun\n");
            return true;
        }
        else{
            return false;
        }
    }
    else{
        printf("Kepala snake menabrak badan!\n");
        return found;
    }
}

void printMap(List L,POINT food, POINT meteor,POINT obstacle){
    
    int i,j;
    for (i = 0 ; i < 11 ; i++){
        for (j = 0 ; j < 11 ;j++){
            if (i % 2 == 0 && j % 2 == 0){
                printf("%c",46);
            }
            else if (i % 2 == 0){
                printf("%c%c%c",196,196,196);
            }
            else if(j % 2 == 0){
                printf("%c",179);
            }
            else if(food.x==((j+1)/2)-1 && food.y==((i+1)/2)-1){
                printf(" o ");
            }
            else if(meteor.x==((j+1)/2)-1 && meteor.y==((i+1)/2)-1){
                printf(" M ");
            }
            else if(obstacle.x==((j+1)/2)-1 && obstacle.y==((i+1)/2)-1){
                printf(" # ");
            }
            else if(SearchAP(L,((j+1)/2)-1,((i+1)/2)-1)){
                if (Info(SearchAP(L,((j+1)/2)-1,((i+1)/2)-1)) == 72){
                    printf(" %c ",Info(SearchAP(L,((j+1)/2)-1,((i+1)/2)-1)));
                }
                else{
                    if (Info(SearchAP(L,((j+1)/2)-1,((i+1)/2)-1))<=9){
                        printf(" %d ",Info(SearchAP(L,((j+1)/2)-1,((i+1)/2)-1)));
                    }
                    else{
                        printf("%d ",Info(SearchAP(L,((j+1)/2)-1,((i+1)/2)-1)));
                    }
                }
            }
            else{
                printf("   ");
            }
        }
        printf("\n");
    }
}

// void som(TabMap *arrmapsb){
void som(TabMap *arrmapsb, int score){
    List L;
    ElmtList ekorbaru;
    char* input;
    POINT obstacle,food,meteor;
    boolean kena = false;
    int turn = 1;
    char*jwbn;

    food.x = UndefLDP;
    food.y = UndefLDP;
    meteor.x = UndefLDP;
    meteor.y = UndefLDP;

    char* mv = "w";
    char* rg = "a";
    char* dw = "s";
    char* lf = "d";
    char* satu = "1";
    char* dua = "2";
        srand(time(NULL));
        printf("Selamat datang di snake on meteor!\n");
        printf("\n");
        printf("Mengenerate peta,snake dan makanan...\n");
        printf("\n");
        printf("Berhasil digenerate!\n");
        printf("\n");
        printf("__________________________________________\n");
        printf("\n");
        createSnake(&L);
        printf("Berikut merupakan peta permainan!\n");
        
        
        createObstacle(L,&obstacle);
        createFood(&food,L,obstacle);
        printMap(L,food,meteor,obstacle);

        while(!kena){
            printf("Turn %d:\n",turn);
            printf("Silahkan masukkan command anda: ");
            input = scaninput();
            if (IsStrEq(input,mv) || IsStrEq(input,rg) || IsStrEq(input,dw) || IsStrEq(input,lf)){
                addressLDP cek = First(L);
                if(IsStrEq(input,lf) &&  GetInf(SearchAP(L,Absis(cek)+1,Ordinat(cek))) < 25){
                    printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
                }            
                else if(IsStrEq(input,rg) &&  GetInf(SearchAP(L,Absis(cek)-1,Ordinat(cek))) < 25){
                    printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
                }
                else if(IsStrEq(input,mv) &&  GetInf(SearchAP(L,Absis(cek),Ordinat(cek)-1)) < 25){
                    printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
                }
                else if(IsStrEq(input,dw) &&  GetInf(SearchAP(L,Absis(cek),Ordinat(cek)+1)) < 25){
                    printf("Anda tidak dapat bergerak ke tubuh anda sendiri\n");
                }                        
                else if(!areaMeteor(L,input,meteor)){
                    move(&L,input);
                    if (checkFoodEaten(&L,food)){
                        addressLDP ekortemp = Last(L);
                        if( GetInf(SearchAP(L,Absis(ekortemp)+1,Ordinat(ekortemp))) < 25 &&  GetInf(SearchAP(L,Absis(ekortemp)-1,Ordinat(ekortemp))) < 25 &&  GetInf(SearchAP(L,Absis(ekortemp),Ordinat(ekortemp)-1)) < 25 &&  GetInf(SearchAP(L,Absis(ekortemp),Ordinat(ekortemp)+1)) < 25){
                            printf("Ekor tidak bisa spawn\n");
                            score = Info(Last(L)) * 2;
                            printf("Score : %d\n",score);
                            kena = true;
                        }
                        else{
                            ekorbaru=*(Last(L));
                            addressLDP alamatekor= AlokasiLDPEkor(((int)Info(Last(L))) + 1);
                            
                            Absis(alamatekor)= ekorbaru.posisi.x;
                            Ordinat(alamatekor)= ekorbaru.posisi.y;
                            InsertLastLDP(&L,alamatekor);
                            createFood(&food,L,obstacle);
                        }     
                    }
                    createMeteor(&meteor,food);
                    printMap(L,food,meteor,obstacle);
                    hit(&L,food,meteor);

                    if(!endCond(L,meteor,obstacle)){
                        turn++;
                    }
                    else if(Info(Last(L)) == 23){
                        int sekor = 46;
                        printf("Score : %d\n",score);
                        kena = true;
                    }
                    else{
                        score = Info(Last(L)) * 2;
                        printf("Score : %d\n",score);
                        kena = true;
                    }                
                }
                else if(areaMeteor(L,input,meteor)){
                    printf("Meteor masih panas! Anda belum dapat ke titik tersebut.\n");
                }
            } 
            else{
                printf("Silahkan memasukkan command yang valid!\n");
            }   
        }
}