#ifndef QUEUEGAME_H
#define QUEUEGAME_H

#include "list.h"
#include "queue.h"

void QUEUEGAME(Queue *q, List gamelist);
/*
I.S.: Antrian game terdefinisi, antrian tidak mungkin penuh, antrian mungkin kosong.
F.S.: Program akan menambahkan antrian game sesuai nomor daftar game yang tersedia,
      apabila masukan nomor game tidak valid, program akan menampilkan pesan error.
*/

#endif