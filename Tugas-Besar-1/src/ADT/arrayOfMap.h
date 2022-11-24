#include "boolean.h"
#include "map.h"

#ifndef ARRAYMAP_H
#define ARRAYMAP_H

/* Kamus Umum */

#define IdxMaxArrayMap 99
#define IdxMinArrayMap 0
#define IdxUndefArrayMap -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxTypeArrayMap;
typedef Map ElTypeArrayMap;

typedef struct
{
    Map TIMap[IdxMaxArrayMap - IdxMinArrayMap + 1]; /* memori tempat penyimpan elemen (container) */
    int NeffArrayMap;                               /* banyaknya elemen efektif */
} TabMap;

/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah Tabstring, cara deklarasi dan akses: */
/* Deklarasi : T : Tabstring */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=0
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff-1 */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmptyArrayMap(TabMap *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtArrayMap(TabMap T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbElArrayMap(TabMap T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxTypeArrayMap GetFirstIdxArrayMap(TabMap T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
IdxTypeArrayMap GetLastIdxArrayMap(TabMap T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
ElTypeArrayMap GetElmtArrayMap(TabMap T, IdxTypeArrayMap i);
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTabArrayMap(TabMap Tin, TabMap *Tout);
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
void SetElArrayMap(TabMap *T, IdxTypeArrayMap i, ElTypeArrayMap v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
void SetNeffArrayMap(TabMap *T, IdxTypeArrayMap N);
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidArrayMap(TabMap T, IdxTypeArrayMap i);
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEffArrayMap(TabMap T, IdxTypeArrayMap i);
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArrayMap(TabMap T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFullArrayMap(TabMap T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

void InsertFirst(TabMap *T, ElTypeArrayMap v);
/* I.S. T terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama T. */

void InsertAt(TabMap *T, ElTypeArrayMap v, IdxTypeArrayMap i);
/* I.S. T terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di T. */
/* F.S. v disisipkan dalam T pada indeks ke-i (bukan menimpa elemen di i). */

void InsertLast(TabMap *T, ElTypeArrayMap v);
/* I.S. T terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir T. */

void DeleteFirst(TabMap *T);
/* I.S. T terdefinisi, tidak kosong. */
/* F.S. elemen pertama T dihapus dari T. */

void DeleteAt(TabMap *T, IdxTypeArrayMap i);
/* I.S. T terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen T pada indeks ke-i dihapus dari T. */

void DeleteLast(TabMap *T);
/* I.S. T terdefinisi, tidak kosong. */
/* F.S. elemen terakhir T dihapus dari T. */
#endif