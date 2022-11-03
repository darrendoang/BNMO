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
        TAIL(*q).time = ((rand()%5)+1);
        TAIL(*q).duration = ((rand()%5)+1);
        TAIL(*q).price = ((1000*(rand()%50))+1000); 
    }
    else{
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
        TAIL(*q).number = IDX_TAIL(*q);
        TAIL(*q).time = ((rand()%5)+1);
        TAIL(*q).duration = ((rand()%5)+1);
        TAIL(*q).price = ((1000*(rand()%50))+1000); 
    }
}

void dequeue(orderQueue *q, int *saldo){
    if (IDX_HEAD(*q) == IDX_TAIL(*q)){
        *saldo = HEAD(*q).price;
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else if ((IDX_HEAD(*q) >= 0) && (IDX_HEAD(*q) < CAPACITY-1) && (IDX_HEAD(*q) != IDX_TAIL(*q)))   {
        *saldo = HEAD(*q).price;
        IDX_HEAD(*q)++;
    }
    else if ((IDX_HEAD(*q) == CAPACITY - 1) && (IDX_HEAD(*q) != IDX_TAIL(*q)))  {
        *saldo = HEAD(*q).price;
        IDX_HEAD(*q) = 0;
    }
}

void dinner_dash(){
    // Queue dan Array
    orderQueue incoming;
    boolean cook[100];
    boolean serve[100];
    boolean rot[100];

    CreateQueue(&incoming);

    for (int k = 0; k < 100; k++){
        cook[k] = false;
        serve[k] = false;
        rot[k] = false;
    }

    // Saldo
    int saldo = 0;

    // Pesanan
    int torder = 0;
    int tcook = 0;
    int tserve = 0;
    for(int j = 0; j < 3; j++){
        enqueue(&incoming);
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
    printf("Daftar Pesanan\nMakanan | Durasi memasak | Ketahanan | Harga\n----------------------------------------------\n");
    for (int i = IDX_HEAD(incoming); i <= IDX_TAIL(incoming); i++){
        if ((cook[i]==false)&&(serve[i]==false)&&(rot[i]==false)){
            printf("M%d      | %d\n", incoming.buffer[i].number, incoming.buffer[i].time);
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

                // Mengecek apakah pesanan sedang/sudah dimasak
                if ((cook[val]==false)&&(serve[val]==false)&&(rot[val]==false)){  
                    cook[val] = true;   // Memasukkan ke array
                    printf("Berhasil memasak M%d\n", val);   // Pesan berhasil
                    valid = true;   // Keluar dari loop input
                }
                else {  
                    printf("M%d sudah dimasak\n", val);   // Pesan gagal
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
                if ((val==IDX_HEAD(incoming))&&(cook[val]==false)&&(serve[val]==true)&&(rot[val]==false)){   // Pesanan paling depan dan belum basi
                    dequeue(&incoming, &saldo);
                    serve[val]=false;
                    tserve++;
                    printf("Berhasil mengantar M%d\n", val);   // Pesan berhasil;
                    if (tserve == 15){   // Kondisi menang
                        over = true;
                        win = true;
                    }
                    valid = true;   // Keluar dari loop input
                }
                else if (val>IDX_HEAD(incoming)){   
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
        if ((incoming.buffer[k].time>0)&&(cook[k]==true)){
            incoming.buffer[k].time--;
            if (incoming.buffer[k].time==0){
                cook[k]=false;
                serve[k]=true;
                incoming.buffer[k].duration++;
                printf("Makanan M%d telah selesai dimasak\n", k);
            }
        }
    }

    // Proses membusuk
    for (int k = IDX_HEAD(incoming); k <= IDX_TAIL(incoming); k++){
        if ((incoming.buffer[k].duration>0)&&(serve[k]==true)){
            incoming.buffer[k].duration--;
            if (incoming.buffer[k].duration==0){
                serve[k]=false;
                rot[k]=true;
                printf("Makanan M%d telah membusuk\n", k);
            }
        }
    }

    // Memulai putaran baru
    enqueue(&incoming);
    torder++;
    if (length(incoming)>7){
        over = true;
    }

    if (!over){
        // Output
        printf("==========================================================\n\n");
        printf("SALDO: %d\n\n", saldo);
        printf("Daftar Pesanan\nMakanan | Durasi memasak | Ketahanan | Harga\n----------------------------------------------\n");
        for (int i = IDX_HEAD(incoming); i <= IDX_TAIL(incoming); i++){
        if ((cook[i]==false)&&(serve[i]==false)&&(rot[i]==false)){
            printf("M%d      | %d\n", incoming.buffer[i].number, incoming.buffer[i].time);
        }
    }
        printf("Daftar Makanan yang sedang dimasak\nMakanan | Sisa durasi memasak\n------------------------------\n");
        for (int i = IDX_HEAD(incoming); i <= IDX_TAIL(incoming); i++){
            if ((cook[i]==true)){
                printf("M%d      | %d\n", incoming.buffer[i].number, incoming.buffer[i].time);
            }
        }
        printf("\n");
        printf("Daftar Makanan yang dapat disajikan\nMakanan | Sisa ketahanan makanan\n------------------------------\n");
        for (int i = IDX_HEAD(incoming); i <= IDX_TAIL(incoming); i++){
            if ((serve[i]==true)){
                printf("M%d      | %d\n", incoming.buffer[i].number, incoming.buffer[i].duration);
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
        }else{
            printf("Kamu kalah :<\n");
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