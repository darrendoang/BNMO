# Tugas Besar 1 ── BNMO
## IF2111 Algoritma dan Struktur Data STI

> Program membantu Indra dan Doni untuk memprogram 
> robot video game console kesayangan mereka

Dibuat oleh Kelompok 04 K02

-Muhammad Rafi Haidar / 18221134
-Priscilla Auleader Napitupulu / 18221098
-Laurensia Audrey Pramashinta / 1822114
-Darren / 18221050
-Razan Aditya Putra / 18221132


## Deskripsi Singkat Laporan
BNMO (dibaca: Binomo) adalah sebuah robot video game console yang dimiliki oleh Indra dan Doni. Dua bulan yang lalu, ia mengalami kerusakan dan telah berhasil diperbaiki. Sayangnya, setelah diperbaiki ia justru mendapatkan lebih banyak bug dalam sistemnya. Oleh karena itu, Indra dan Doni mencari programmer lain yang lebih handal untuk ulang memprogram robot video game console kesayangannya. Buatlah sebuah permainan berbasis CLI (command-line interface). Sistem ini dibuat dalam bahasa C dengan menggunakan struktur data yang sudah kalian pelajari di mata kuliah ini. 

## Cara Kompilasi Program
Step 1: Masuk ke directory bin
Step 2: Ketik mingw32-make driver di terminal
Step 3: Ketik  ./driver di terminal untuk menjalankan program
Step 4: Ketik mingw32-make clean di terminal untuk menghapus driver.exe(Membersihkan file)


## Struktur Program

.
│
├── README.md
├── main.c				# main program
├── data
│   ├─── bnmo.txt 			# file berisi banner yang akan dibaca sebagai welcome page
│   ├─── config.txt			# file konfigurasi awal yang akan dibaca pada START
│   ├─── drivermesinkata.txt		# file yang akan dibaca pada driver mesin kata
│   ├─── save1.txt			# file yang disimpan oleh user 1
│   └─── save2.txt			# file yang disimpan oleh user 2
│ 
├── source
│   ├─── boolean.h
│   ├─── ADT				# folder berisikan main
│   │      ├─── array
│   │      │       ├─── arraydin.h
│   │      │       ├─── araydin.c
│   │      │       └─── driver_arraydin.c
│   │      │
│   │      ├─── map
│   │      │       ├─── map.h
│   │      │       ├─── map.c
│   │      │       └─── driver_map.c
│   │      │
│   │      ├─── mesinkarakter
│   │      │       ├─── mesinkarakter.h
│   │      │       ├─── mesinkarakter.c
│   │      │       └─── driver_mesinkar.c
│   │      │
│   │      ├─── mesinkata
│   │      │       ├─── mesinkata.h
│   │      │       ├─── mesinkata.c
│   │      │       └─── driver_mesinkar.c
│   │      │
│   │      ├─── queue
│   │      │       ├─── queue.h
│   │      │       ├─── queue.c
│   │      │       └─── driver_queue.c
│   │      │
│   │      ├─── queuedinerdash
│   │      │       ├─── queue.h
│   │      │       ├─── queue.c
│   │      │       └─── driver_queue.c
│   │      │
│   │      └─── stack
│   │              ├─── stack.h
│   │              ├─── stack.c
│   │              └─── driver_stack.c
│   │
│   └─── command
│          ├─── console.h
│          └─── console.c
│
│
└── docs 
     ├─── 
     ├───
     └───
