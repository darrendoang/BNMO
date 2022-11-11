IF2111 - Algoritma dan Struktur Data
Kelompok 04
Kelas 02

Anggota:
Muhammad Rafi Haidar / 18221134
Priscilla Auleader Napitupulu / 18221098
Laurensia Audrey Pramashinta / 1822114
Darren / 18221050
Razan Aditya Putra / 18221132

Deskripsi:
Program BNMO merupakan program permainan berbasis command-line interface yang dibuat menggunakan bahasa C. BNMO mempunyai beberapa fitur utama, yaitu memainkan game, menambahkan game, menghapus game, dan mengurutkan game yang akan dimainkan. Awalnya pengguna akan masuk ke dalam main menu dan dari situ dapat memasukkan command dengan cara mengetiknya untuk menggunakan fitur-fitur BNMO.

Instruksi:
Program bisa langsung dijalankan dengan mengeksekusi BNMO.exe di direktori src atau driver.exe di direktori bin

Program dapat di kompilasi dengan cara menjalankan MAKEFILE di direktori ../bin dan menjalankan driver.exe

atau dengan menjalankan command: 

gcc console.c main.c GAME/ddash.c GAME/tictactoe.c GAME/rng.c ADT/array.c ADT/mesinkarakter.c ADT/mesinkata.c ADT/mesinload.c ADT/queue.c -o BNMO

di direktori ../src dan menjalankan BNMO.exe

berikut merupakan list command yang dapat di-input saat program meminta anda memasukkan command:

START                 Membaca file konfigurasi default yang berisi list game yang dapat dimainkan
LOAD                  Membaca save file yang berisi list game yang dapat dimainkan, histori dan scoreboard game
SAVE                  Merepresentasikan nama file yang akan disimpan pada disk
CREATE GAME           Menambahkan game baru pada daftar game 
LIST GAME             Menampilkan daftar game yang disediakan oleh sistem 
DELETE GAME           Menghapus sebuah game dari daftar game 
QUEUE GAME            Mendaftarkan permainan kedalam list 
PLAY GAME             Memainkan sebuah permainan 
SKIPGAME              Melewatkan permainan sebanyak n 
QUIT                  Keluar dari Program 
HELP                  Menampilkan daftar perintah 

KHUSUS UNTUK FUNGSI LOAD:
Input:
LOAD ../data/<nama file>

contoh:
LOAD ../data/savefile.txt