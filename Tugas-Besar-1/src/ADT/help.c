#include "help.h"

void HELP (){
    printf(
        "COMMANDs :\n"
        " START                 Membaca file konfigurasi default yang berisi list game yang dapat dimainkan\n"
        " LOAD                  Membaca save file yang berisi list game yang dapat dimainkan, histori dan scoreboard game\n"
        " SAVE                  Merepresentasikan nama file yang akan disimpan pada disk\n"
        " CREATEGAME            Menambahkan game baru pada daftar game \n"
        " LISTGAME              Menampilkan daftar game yang disediakan oleh sistem \n"
        " DELETEGAME            Menghapus sebuah game dari daftar game \n"
        " QUEUEGAME             Mendaftarkan permainan kedalam list \n"
        " PLAYGAME              Memainkan sebuah permainan \n"
        " SKIPGAME              Melewatkan permainan sebanyak n \n"
        " QUIT                  Keluar dari Program \n"
        " HELP                  Menampilkan daftar perintah \n"
    );
}