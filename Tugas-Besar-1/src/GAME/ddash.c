#include "ddash.h"

void CreateQueueD(orderQueue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmptyD(orderQueue q){
    return ((IDX_HEAD(q) == IDX_UNDEF) || (IDX_TAIL(q) == IDX_UNDEF));
}

void enqueueD(orderQueue *q){
    srand(time(NULL)); 
    if (isEmptyD(*q)){
        IDX_TAIL(*q) = 0;
        IDX_HEAD(*q) = 0;
        TAIL(*q).number = IDX_TAIL(*q);
        TAIL(*q).time = (((rand()*(IDX_TAIL(*q)+1))%5)+1);
        TAIL(*q).duration = (((rand()*(IDX_TAIL(*q)+1))%5)+1);
        TAIL(*q).price = ((1000*((rand()*(IDX_TAIL(*q)+1))%50))+1000); 
        TAIL(*q).cook = false;
        TAIL(*q).serve = false;
    }
    else{
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
        TAIL(*q).number = IDX_TAIL(*q);
        TAIL(*q).time = (((rand()*(IDX_TAIL(*q)+1))%5)+1);
        TAIL(*q).duration = (((rand()*(IDX_TAIL(*q)+1))%5)+1);
        TAIL(*q).price = ((1000*((rand()*(IDX_TAIL(*q)+1))%50))+1000); 
        TAIL(*q).cook = false;
        TAIL(*q).serve = false;
    }
}

void dequeueD(orderQueue *q, int *saldo){
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

void diner_dash(){
    // Queue dan Array
    orderQueue incoming;
    arrayCook cook;
    arrayCook serve;
    cook.Neff = 100;
    serve.Neff = 100;

    CreateQueueD(&incoming);

    for (int k = 0; k < 100; k++){
        cook.TI[k] = -1;
        serve.TI[k] = -1;
    }

    // Saldo
    int saldo = 0;

    // Pesanan
    int torder = 2;
    int backlog = 3;
    int tserve = 0;
    enqueueD(&incoming);
    enqueueD(&incoming);
    enqueueD(&incoming);

    // Command
    char *input;

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
    printf("\n");
    printf("Daftar Makanan yang sedang dimasak\nMakanan | Sisa durasi memasak\n------------------------------\n        |\n");
    printf("\n");
    printf("Daftar Makanan yang dapat disajikan\nMakanan | Sisa ketahanan makanan\n------------------------------\n        |\n");
    printf("\n\n");

    // Initial input
    printf("MASUKKAN COMMAND: ");
    input = READINPUT();
    printf("\n\n");

    // Main loop
    while(!over){
        // Menunggu input benar
        boolean valid = false;
        while (!valid){
            int val = 0;   // ID pesanan
            if ((input[0] == 'C')&&(input[1] == 'O')&&(input[2] == 'O')&&(input[3] == 'K')&&(input[4] == ' ')&&(input[5]=='M')){   // COOK M...
                // Mencari val
                val += input[6] - '0';
                if (input[7] != '\0'){
                    val *= 10;
                    val += input[7] - '0';
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
                        printf("M%d sudah dimasak\n\n", val);   // Pesan gagal
                    }
                }
                else{
                    printf("Tidak ada pesanan M%d\n\n", val);   // Pesan gagal
                }
            }
            else if ((input[0] == 'S')&&(input[1] == 'E')&&(input[2] == 'R')&&(input[3] == 'V')&&(input[4] == 'E')&&(input[5] == ' ')&&(input[6]=='M')){   //SERVE M...
                // Mencari val
                val += input[7] - '0';
                if (input[8] != '\0'){
                    val *= 10;
                    val += input[8] - '0';
                }

                // Mengecek apakah pesanan sebelumnya sudah dimasak
                if ((val == IDX_HEAD(incoming)) && (incoming.buffer[val].serve == true)){   // Pesanan paling depan dan belum basi
                    dequeueD(&incoming, &saldo);
                    tserve++;
                    printf("Berhasil mengantar M%d\n", val);   // Pesan berhasil;
                    if (tserve == 15){   // Kondisi menang
                        over = true;
                        win = true;
                    }
                    valid = true;   // Keluar dari loop input
                }
                else if ((val>IDX_HEAD(incoming))){   
                    printf("M%d belum dapat disajikan karena M%d belum selesai\n\n", val, val-1);   // Pesan gagal
                }
                else if ((val==IDX_HEAD(incoming)) && (incoming.buffer[val].serve == false)){   
                    printf("M%d belum selesai dimasak\n\n", val);   // Pesan gagal
                }
                else if (val<IDX_HEAD(incoming)){  
                    printf("M%d sudah disajikan\n\n", val);   // Pesan gagal
                }
            }
            else if ((input[0] == 'S')&&(input[1] == 'K')&&(input[2] == 'I')&&(input[3] == 'P')&&(input[4] == '\0')){
                valid = true;
            }

            // Apabila input salah
            if (!valid){
                printf("Command invalid, mohon masukkan command COOK M.., SERVE M.., atau SKIP\n\n");
                printf("MASUKKAN COMMAND: ");
                input = READINPUT();
                printf("\n\n");
            }
        }

        // Proses memasak
        for (int k = IDX_HEAD(incoming); k <= IDX_TAIL(incoming); k++){
            if (incoming.buffer[k].cook == true){
                cook.TI[k]++;
                if ((incoming.buffer[k].time - cook.TI[k]) == 0){
                    incoming.buffer[k].cook = false;
                    incoming.buffer[k].serve = true;
                    cook.TI[k] = -1;
                    printf("Makanan M%d telah selesai dimasak\n", k);
                }
            }
        }

        // Proses membusuk
        for (int k = IDX_HEAD(incoming); k <= IDX_TAIL(incoming); k++){
            if (incoming.buffer[k].serve == true){
                serve.TI[k]++;
                if ((incoming.buffer[k].duration - serve.TI[k]) == 0){
                    incoming.buffer[k].serve = false;
                    serve.TI[k] = -1;
                    backlog++;
                    printf("Makanan M%d telah membusuk\n", k);
                }
            }
        }

        // Memulai putaran baru
        enqueueD(&incoming);
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
            printf("\n");
            printf("Daftar Makanan yang sedang dimasak\nMakanan | Sisa durasi memasak\n------------------------------\n");
            for (int i = IDX_HEAD(incoming); i <= IDX_TAIL(incoming); i++){
                if (incoming.buffer[i].cook==true){
                    printf("M%d      | %d\n", incoming.buffer[i].number, incoming.buffer[i].time - cook.TI[i]);
                }
            }
            printf("\n");
            printf("Daftar Makanan yang dapat disajikan\nMakanan | Sisa ketahanan makanan\n------------------------------\n");
            for (int i = IDX_HEAD(incoming); i <= IDX_TAIL(incoming); i++){
                if (incoming.buffer[i].serve==true){
                    printf("M%d      | %d\n", incoming.buffer[i].number, incoming.buffer[i].duration - serve.TI[i]);
                }
            }
            printf("\n\n");

            // Input
            printf("MASUKKAN COMMAND: ");
            input = READINPUT();
            printf("\n\n");
        }
        else{
            if (win){
                printf("Kamu menang ^w^\n");
            }else{
                printf("Kamu kalah :<\n");
            }
            printf("\nSKOR AKHIR: %d\n", saldo);
        }
    }
}