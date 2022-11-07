#include "ddash1.h"

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

void enqueue(orderQueue *q){
    srand(time(NULL)); 
    if (isEmpty(*q)){
        IDX_TAIL(*q) = 0;
        IDX_HEAD(*q) = 0;
        TAIL(*q).number = IDX_TAIL(*q);
        TAIL(*q).time = (((rand()+rand())%5)+1);
        TAIL(*q).duration = (((rand()+rand())%5)+1);
        TAIL(*q).price = ((1000*((rand()*(IDX_TAIL(*q)+1))%50))+1000); 
        TAIL(*q).cook = false;
        TAIL(*q).serve = false;
    }
    else{
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
        TAIL(*q).number = IDX_TAIL(*q);
        TAIL(*q).time = (((rand()+rand())%5)+1);
        TAIL(*q).duration = (((rand()+rand())%5)+1);
        TAIL(*q).price = ((1000*((rand()*(IDX_TAIL(*q)+1))%50))+1000); 
        TAIL(*q).cook = false;
        TAIL(*q).serve = false;
    }
}

void dequeue(orderQueue *q, int *saldo){
    if (IDX_HEAD(*q) == IDX_TAIL(*q)){
        *saldo += HEAD(*q).price;
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else if ((IDX_HEAD(*q) >= 0) && (IDX_HEAD(*q) < CAPACITY-1) && (IDX_HEAD(*q) != IDX_TAIL(*q)))   {
        *saldo += HEAD(*q).price;
        IDX_HEAD(*q)++;
    }
    else if ((IDX_HEAD(*q) == CAPACITY - 1) && (IDX_HEAD(*q) != IDX_TAIL(*q)))  {
        *saldo += HEAD(*q).price;
        IDX_HEAD(*q) = 0;
    }
}

void dinner_dash(){
    // Queue dan Array
    orderQueue incoming;
    int cook[100];
    int serve[100];

    CreateQueue(&incoming);

    for (int k = 0; k < 100; k++){
        cook[k] = -1;
        serve[k] = -1;
    }

    // Saldo
    int saldo = 0;

    // Pesanan
    int torder = 2;
    int backlog = 3;
    int tserve = 0;
    enqueue(&incoming);
    enqueue(&incoming);
    enqueue(&incoming);

    // Command
    char input1[10];
    char input2[10];

    // Menang atau Kalah 
    boolean over = false;
    boolean win = false;

    // Initial output
    printf("Selamat Datang di Diner Dash!\n\n");
    printf("SALDO: %d\n\n", saldo);
    printf("Daftar Pesanan\nMakanan | Durasi memasak | Ketahanan | Harga\n----------------------------------------------\n");
    for (int i = IDX_HEAD(incoming); i <= IDX_TAIL(incoming); i++){
        if ((incoming.buffer[i].cook==false)&&(incoming.buffer[i].serve==false)){
            printf("M%d      | %d      | %d      | %d\n", incoming.buffer[i].number, incoming.buffer[i].time, incoming.buffer[i].duration, incoming.buffer[i].price);
        }
    }
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
            int val = 0;   // ID pesanan
            if ((input1[0] == 'C')&&(input1[1] == 'O')&&(input1[2] == 'O')&&(input1[3] == 'K')&&(input2[0]=='M')){   // COOK M...
                // Mencari val
                val += input2[1] - '0';
                if (input2[2] != '\0'){
                    val *= 10;
                    val += input2[2] - '0';
                }

                // Mengecek apakah pesanan ada
                if (val<=torder){
                    // Mengecek apakah pesanan sedang/sudah dimasak
                    if ((incoming.buffer[val].cook == false)&&(incoming.buffer[val].serve == false)){  
                        incoming.buffer[val].cook = true;   // Memasukkan ke array
                        printf("Berhasil memasak M%d\n", val);   // Pesan berhasil
                        backlog--;
                        valid = true;   // Keluar dari loop input
                    }
                    else {  
                        printf("M%d sudah dimasak\n", val);   // Pesan gagal
                    }
                }
                else{
                    printf("Tidak ada pesanan M%d\n", val);   // Pesan gagal
                }
            }
            else if ((input1[0] == 'S')&&(input1[1] == 'E')&&(input1[2] == 'R')&&(input1[3] == 'V')&&(input1[4] == 'E')&&(input2[0]=='M')){   //SERVE M...
                // Mencari val
                val += input2[1] - '0';
                if (input2[2] != '\0'){
                    val *= 10;
                    val += input2[2] - '0';
                }

                // Mengecek apakah pesanan sebelumnya sudah dimasak
                if ((val == IDX_HEAD(incoming)) && (incoming.buffer[val].serve == true)){   // Pesanan paling depan dan belum basi
                    dequeue(&incoming, &saldo);
                    tserve++;
                    printf("Berhasil mengantar M%d\n", val);   // Pesan berhasil;
                    if (tserve == 15){   // Kondisi menang
                        over = true;
                        win = true;
                    }
                    valid = true;   // Keluar dari loop input
                }
                else if ((val>IDX_HEAD(incoming))){   
                    printf("M%d belum dapat disajikan karena M%d belum selesai\n", val, val-1);   // Pesan gagal
                }
                else if (val<IDX_HEAD(incoming)){  
                    printf("M%d sudah disajikan\n", val);   // Pesan gagal
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
        for (int k = IDX_HEAD(incoming); k <= IDX_TAIL(incoming); k++){
            if (incoming.buffer[k].cook == true){
                cook[k]++;
                if ((incoming.buffer[k].time - cook[k]) == 0){
                    incoming.buffer[k].cook = false;
                    incoming.buffer[k].serve = true;
                    cook[k] = -1;
                    printf("Makanan M%d telah selesai dimasak\n", k);
                }
            }
        }

        // Proses membusuk
        for (int k = IDX_HEAD(incoming); k <= IDX_TAIL(incoming); k++){
            if (incoming.buffer[k].serve == true){
                serve[k]++;
                if ((incoming.buffer[k].duration - serve[k]) == 0){
                    incoming.buffer[k].serve = false;
                    serve[k] = -1;
                    backlog++;
                    printf("Makanan M%d telah membusuk\n", k);
                }
            }
        }

        // Memulai putaran baru
        enqueue(&incoming);
        torder++;
        backlog++;
        if (backlog>7){
            over = true;
        }

        if (!over){
            // Output
            printf("==========================================================\n\n");
            printf("SALDO: %d\n\n", saldo);
            printf("Daftar Pesanan\nMakanan | Durasi memasak | Ketahanan | Harga\n----------------------------------------------\n");
            for (int i = IDX_HEAD(incoming); i <= IDX_TAIL(incoming); i++){
                if ((incoming.buffer[i].cook==false)&&(incoming.buffer[i].serve==false)){
                    printf("M%d      | %d      | %d      | %d\n", incoming.buffer[i].number, incoming.buffer[i].time, incoming.buffer[i].duration, incoming.buffer[i].price);
                }
            }
            printf("Daftar Makanan yang sedang dimasak\nMakanan | Sisa durasi memasak\n------------------------------\n");
            for (int i = IDX_HEAD(incoming); i <= IDX_TAIL(incoming); i++){
                if (incoming.buffer[i].cook==true){
                    printf("M%d      | %d\n", incoming.buffer[i].number, incoming.buffer[i].time - cook[i]);
                }
            }
            printf("\n");
            printf("Daftar Makanan yang dapat disajikan\nMakanan | Sisa ketahanan makanan\n------------------------------\n");
            for (int i = IDX_HEAD(incoming); i <= IDX_TAIL(incoming); i++){
                if (incoming.buffer[i].serve==true){
                    printf("M%d      | %d\n", incoming.buffer[i].number, incoming.buffer[i].duration - serve[i]);
                }
            }
            printf("\n\n");

            // Input
            printf("MASUKKAN COMMAND: ");
            scanf("%s %s", input1, input2);
            printf("\n\n");
        }
        else{
            if (win){
                printf("Kamu menang uwu\n");
                system("pause");
            }else{
                printf("Kamu kalah :<\n");
                system("pause");
            }
        }
    }
}

int main(){
    /*
    srand(time(NULL));   
    int r = rand();
    int s = rand();
    printf("%d %d\n", (1000*(r%15))+1000, s);
    
    char input1[10];
    char input2[10];

    scanf("%s %s", input1, input2);
    printf("\n");
    printf("%c\n", input2[0]);
    printf("%c\n", input2[1]);
    printf("%c\n", input2[2]);
    if (input2[2] == '\0'){

        printf("delta\n");
    }
    int val = 0;
    val += input2[1] - '0';
        if (input2[2] != '\0'){
            val += input2[2] - '0';
        }
    printf("%d\n", val);
    system("pause");
    */
    dinner_dash();
    
    return 0;
}