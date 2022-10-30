#include "ddash.h"

void CreateQueue(orderQueue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(orderQueue q){
    return ((IDX_HEAD(q) == IDX_UNDEF) || (IDX_TAIL(q) == IDX_UNDEF));
}

int length(orderQueue q){
    if (isEmpty(q)){
        return 0;
    }
    else if ((IDX_HEAD(q) <= IDX_TAIL(q)) && (!isEmpty(q))){
        return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
    }
    else if ((IDX_HEAD(q) > IDX_TAIL(q)) && (!isEmpty(q))) {
        return (CAPACITY + IDX_TAIL(q) - IDX_HEAD(q) + 1);
    }
}

void enqueue(orderQueue *q, int num){
    srand(time(NULL)); 
    if (isEmpty(*q)){
        IDX_TAIL(*q) = 0;
        IDX_HEAD(*q) = 0;
        TAIL(*q).number = num;
        TAIL(*q).time = ((rand()%5)+1);
        TAIL(*q).duration = ((rand()%5)+1);
        TAIL(*q).price = ((1000*(rand()%50))+1000); 
    }
    else{
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
        TAIL(*q).number = num;
        TAIL(*q).time = ((rand()%5)+1);
        TAIL(*q).duration = ((rand()%5)+1);
        TAIL(*q).price = ((1000*(rand()%50))+1000); 
    }
}

void dequeue(orderQueue *q, int *num, int *time, int *duration, int *price){
    if (IDX_HEAD(*q) == IDX_TAIL(*q)){
        *num = TAIL(*q).number;
        *time = TAIL(*q).time;
        *duration = TAIL(*q).duration;
        *price = TAIL(*q).price;
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else if ((IDX_HEAD(*q) >= 0) && (IDX_HEAD(*q) < CAPACITY-1) && (IDX_HEAD(*q) != IDX_TAIL(*q)))   {
        *num = TAIL(*q).number;
        *time = TAIL(*q).time;
        *duration = TAIL(*q).duration;
        *price = TAIL(*q).price;
        IDX_HEAD(*q)++;
    }
    else if ((IDX_HEAD(*q) == CAPACITY - 1) && (IDX_HEAD(*q) != IDX_TAIL(*q)))  {
        *num = TAIL(*q).number;
        *time = TAIL(*q).time;
        *duration = TAIL(*q).duration;
        *price = TAIL(*q).price;
        IDX_HEAD(*q) = 0;
    }
}

void printQueue(orderQueue q){
    for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++){
        printf("M%d      | %d              | %d         | %d\n", q.buffer[i].number, q.buffer[i].time, q.buffer[i].duration, q.buffer[i].price);
    }
}

void dinner_dash(){
    // Array
    orderQueue incoming;
    orderQueue cooking;
    orderQueue finished;

    // Saldo
    int saldo = 0;

    // Pesanan
    int total = 0;
    for(int j = total; j < 3; j++){
        enqueue(&incoming, total);
        total++;
    }

    // Command
    char input1[10];
    char input2[10];

    // Menang atau Kalah 
    boolean over = false;
    boolean win = false;

    // Initial output
    printf("Selamat Datang di Diner Dash!\n\n");
    printf("SALDO: %d\n\n", saldo);
    printf("Daftar Pesanan\nMakanan | Durasi memasak | Ketahanan | Harga\n----------------------------------------------");
    printQueue(incoming);
    printf("Daftar Makanan yang sedang dimasak\nMakanan | Sisa durasi memasak\n------------------------------\n        |\n");
    printf("Daftar Makanan yang dapat disajikan\nMakanan | Sisa ketahanan makanan\n------------------------------\n        |\n");

    printf("MASUKKAN COMMAND: ");
    scanf("%s %s", input1, input2);
    printf("\n\n");

    while(!over){
        // Menunggu input benar
        boolean valid = false;
        while (!valid){
            if ((input1[0] == 'C')&&(input1[1] == 'O')&&(input1[2] == 'O')&&(input1[3] == 'K')&&(input2[0]=='M')){

            }
            else if ((input1[0] == 'S')&&(input1[1] == 'E')&&(input1[2] == 'R')&&(input1[3] == 'V')&&(input1[4] == 'E')&&(input2[0]=='M')){

            }
            if (!valid){
                printf("MASUKKAN COMMAND: ");
                scanf("%s %s", input1, input2);
                printf("\n\n");
            }
        }
    }
}
