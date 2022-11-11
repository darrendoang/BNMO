IF2111 - Algoritma dan Struktur Data
Kelompok 04
Kelas 02


Anggota:
Muhammad Rafi Haidar / 18221134;
Priscilla Auleader Napitupulu / 18221098;
Laurensia Audrey Pramashinta / 1822114;
Darren / 18221050;
Razan Aditya Putra / 18221132;


Deskripsi:
Program BNMO merupakan program permainan berbasis command-line interface yang dibuat menggunakan bahasa C. BNMO mempunyai beberapa fitur utama, yaitu memainkan game, menambahkan game, menghapus game, dan mengurutkan game yang akan dimainkan. Awalnya pengguna akan masuk ke dalam main menu dan dari situ dapat memasukkan command dengan cara mengetiknya untuk menggunakan fitur-fitur BNMO.

Instruksi:
Program bisa langsung dijalankan dengan mengeksekusi BNMO.exe atau dengan menjalankan langkah di bawah ini

Step 1: Masuk ke directory bin

Step 2: Ketik mingw32-make driver di terminal

Step 3: Ketik  ./driver di terminal untuk menjalankan program

Step 4: Ketik mingw32-make clean di terminal untuk menghapus driver.exe(Membersihkan file)


Berikut merupakan list command yang dapat di-input saat program meminta anda memasukkan command:

START                 Membaca file konfigurasi default yang berisi list game yang dapat dimainkan;
LOAD                  Membaca save file yang berisi list game yang dapat dimainkan, histori dan scoreboard game;
SAVE                  Merepresentasikan nama file yang akan disimpan pada disk;
CREATE GAME           Menambahkan game baru pada daftar game;
LIST GAME             Menampilkan daftar game yang disediakan oleh sistem;
DELETE GAME           Menghapus sebuah game dari daftar game;
QUEUE GAME            Mendaftarkan permainan kedalam list; 
PLAY GAME             Memainkan sebuah permainan; 
SKIPGAME              Melewatkan permainan sebanyak n; 
QUIT                  Keluar dari Program; 
HELP                  Menampilkan daftar perintah; 


KHUSUS UNTUK FUNGSI LOAD
Input:
LOAD ../data/<nama file>


contoh:
LOAD ../data/savefile.txt