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

void dequeue(orderQueue *q, order *ord){
    if (IDX_HEAD(*q) == IDX_TAIL(*q)){
        ord->number = HEAD(*q).number;
        ord->time = HEAD(*q).time;
        ord->duration = HEAD(*q).duration;
        ord->price = HEAD(*q).price;
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else if ((IDX_HEAD(*q) >= 0) && (IDX_HEAD(*q) < CAPACITY-1) && (IDX_HEAD(*q) != IDX_TAIL(*q)))   {
        ord->number = HEAD(*q).number;
        ord->time = HEAD(*q).time;
        ord->duration = HEAD(*q).duration;
        ord->price = HEAD(*q).price;
        IDX_HEAD(*q)++;
    }
    else if ((IDX_HEAD(*q) == CAPACITY - 1) && (IDX_HEAD(*q) != IDX_TAIL(*q)))  {
        ord->number = HEAD(*q).number;
        ord->time = HEAD(*q).time;
        ord->duration = HEAD(*q).duration;
        ord->price = HEAD(*q).price;
        IDX_HEAD(*q) = 0;
    }
}

void printQueue(orderQueue q){
    for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++){
        printf("M%d      | %d              | %d         | %d\n", q.buffer[i].number, q.buffer[i].time, q.buffer[i].duration, q.buffer[i].price);
    }
}

void dinner_dash(){
    // Queue dan Array
    orderQueue incoming;
    order cooking[100];
    order finished[100];

    for (int k = 0; k < 100; k++){
        cooking[k].number = Nil;
        cooking[k].time = Nil;
        cooking[k].duration = Nil;
        cooking[k].price = Nil;
        finished[k].number = Nil;
        finished[k].time = Nil;
        finished[k].duration = Nil;
        finished[k].price = Nil;
    }

    // Saldo
    int saldo = 0;

    // Pesanan
    int torder = 0;
    int tcook = 0;
    int tserve = 0;
    for(int j = torder; j < 3; j++){
        enqueue(&incoming, torder);
        torder++;
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

    // Initial input
    printf("MASUKKAN COMMAND: ");
    scanf("%s %s", input1, input2);
    printf("\n\n");

    // Main loop
    while(!over){
        // Menunggu input benar
        boolean valid = false;
        while (!valid){
            int val = 0;
            if ((input1[0] == 'C')&&(input1[1] == 'O')&&(input1[2] == 'O')&&(input1[3] == 'K')&&(input2[0]=='M')){   // COOK M...
                // Mencari val
                val += input2[1] - '0';
                if (input2[2] != '\0'){
                    val += input2[2] - '0';
                }

                // Mengecek apakah pesanan sebelumnya sudah dimasak
                if (val==tcook){  
                    order tempOrder;
                    dequeue(&incoming, &tempOrder);

                    // Memasukkan ke array
                    cooking[val].number = tempOrder.number;
                    cooking[val].time = tempOrder.time;
                    cooking[val].duration = tempOrder.duration;
                    cooking[val].price = tempOrder.price;

                    printf("Berhasil memasak M%d\n", val);
                    tcook++;
                    valid = true;  
                }
                else if (val>tcook){   
                    printf("M%d belum dapat dimasak karena M%d belum diambil\n", val, val-1);
                }
                else if (val<tcook){  
                    printf("M%d sudah dimasak\n", val);
                }
            }
            else if ((input1[0] == 'S')&&(input1[1] == 'E')&&(input1[2] == 'R')&&(input1[3] == 'V')&&(input1[4] == 'E')&&(input2[0]=='M')){   //SERVE M...
                // Mencari val
                val += input2[1] - '0';
                if (input2[2] != '\0'){
                    val += input2[2] - '0';
                }

                // Mengecek apakah pesanan sebelumnya sudah dimasak
                if ((val==tserve)&&(finished[val].duration>0)){  
                    finished[val].duration = 0;
                    printf("Berhasil mengantar M%d\n", val);
                    saldo += finished[val].price;
                    tserve++;
                    valid = true;  
                }
                else if (val>tserve){   
                    printf("M%d belum dapat disajikan karena M%d belum selesai\n", val, val-1);
                }
                else if (val<tcook){  
                    printf("M%d sudah disajikan\n", val);
                }
            }

            // Apabila input salah
            if (!valid){
                printf("MASUKKAN COMMAND: ");
                scanf("%s %s", input1, input2);
                printf("\n\n");
            }
        }

    // Proses memasak
    for (int k = 0; k < tcook; k++){
        if ((cooking[k].time>0)&&(cooking[k].number!=Nil)){
            cooking[k].time--;
            if (cooking[k].time==0){
                printf("Makanan M%d telah selesai dimasak\n", cooking[k].number);
            }
        }
    }
    // Memindahkan masakan yang telah selesai
    for (int k = 0; k < tcook; k++){
        if ((cooking[k].time==0)&&(finished[k].number==Nil)){
            finished[k].number = cooking[k].number;
            finished[k].time = cooking[k].time;
            finished[k].duration = cooking[k].duration+1;
            finished[k].price = cooking[k].price;
        }
    }
    // Proses membusuk
    for (int k = 0; k < 100; k++){
        if ((finished[k].duration>0)&&(finished[k].number!=Nil)){
            finished[k].duration--;
            if (finished[k].duration==0){
                printf("Makanan M%d telah membusuk\n", finished[k].number);
            }
        }
    }

    // Memulai putaran baru
    enqueue(&incoming, torder);
    torder++;

    // Output
    printf("==========================================================\n\n");
    printf("SALDO: %d\n\n", saldo);
    printf("Daftar Pesanan\nMakanan | Durasi memasak | Ketahanan | Harga\n----------------------------------------------");
    printQueue(incoming);
    printf("Daftar Makanan yang sedang dimasak\nMakanan | Sisa durasi memasak\n------------------------------\n");
    for (int i = 0; i < tcook; i++){
        if ((cooking[i].number!=Nil)&&(cooking[i].time>0)){
            printf("M%d      | %d\n", cooking[i].number, cooking[i].time);
        }
    }
    printf("\n");
    printf("Daftar Makanan yang dapat disajikan\nMakanan | Sisa ketahanan makanan\n------------------------------\n");
    for (int i = 0; i < 100; i++){
        if ((finished[i].number!=Nil)&&(finished[i].duration>0)){
            printf("M%d      | %d\n", cooking[i].number, cooking[i].duration);
        }
    }
    printf("\n\n");

    // Meminta command
    printf("MASUKKAN COMMAND: ");
    scanf("%s %s", input1, input2);
    printf("\n\n");
    }
}
