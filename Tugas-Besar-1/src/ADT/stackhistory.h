/* File : stackhistory.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackhistory_H
#define stackhistory_H

#include "boolean.h"

#define Nils -1
#define MaxElmt 100
/* Nils adalah stack dengan elemen kosong . */

typedef char *infotypeHistory;
typedef int address; /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct
{
    infotypeHistory T[MaxElmt]; /* tabel penyimpan elemen */
    address TOPHISTORY;            /* alamat TOP: elemen puncak */
} HistoryStack;
/* Definisi stack S kosong : S.TOP = Nils */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxElmt-1] */
/* Jika S adalah Stack maka akses elemen : */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define TopHistory(SH) (SH).TOPHISTORY
#define InfoTopHistory(SH) (SH).T[(SH).TOPHISTORY]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackHistory(HistoryStack *SH);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElmt */
/* jadi indeksnya antara 0.. MaxElmt */
/* Ciri stack kosong : TOP bernilai Nils */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */

boolean IsStackHistoryEmpty(HistoryStack SH);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsStackHistoryFull(HistoryStack SH);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushHistory(HistoryStack *SH, infotypeHistory X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopHistory(HistoryStack *SH, infotypeHistory *X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void PrintStackHistory(HistoryStack *SH, int n);
/* Menulis seluruh elemen Stack S ke layar */
/* I.S. S mungkin kosong */
/* F.S. Jika S tidak kosong, maka akan print nilai Stack*/

int countStackHistory(HistoryStack SH);
/* Mengembalikan banyaknya/jumlah alamat dalam HistoryStack SH ke layar */
/* I.S. SH mungkin kosong */
/* F.S. Jika SH tidak kosong, semua elemen HistoryStack diprint */
#endif