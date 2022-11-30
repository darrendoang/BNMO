/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackttower_H
#define stackttower_H

#include "boolean.h"

#define Nill -1
#define MaxElmnts 100
/* Nill adalah stack dengan elemen kosong . */

typedef int stackinfotype;
typedef int address; /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct
{
    stackinfotype T[MaxElmnts]; /* tabel penyimpan elemen */
    address TOP;            /* alamat TOP: elemen puncak */
} HanoiStack;
/* Definisi stack S kosong : S.TOP = Nill */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxElmnts-1] */
/* Jika S adalah Stack maka akses elemen : */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(HanoiStack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElmnts */
/* jadi indeksnya antara 0.. MaxElmnts */
/* Ciri stack kosong : TOP bernilai Nill */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty(HanoiStack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsStackFull(HanoiStack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(HanoiStack *S, stackinfotype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(HanoiStack *S, stackinfotype *X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
boolean IsCloneStack(HanoiStack S1, HanoiStack S2);
/* Mengirimkan true jika stack yang dibandingkan sama*/

int top_val(HanoiStack S);
#endif