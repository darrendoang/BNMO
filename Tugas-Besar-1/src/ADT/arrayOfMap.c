/* Indeks yang digunakan [IdxMinArrayMap..IdxMaxArrayMap] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=0
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff - 1 */
#include <stdio.h>
#include "arrayOfMap.h"
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmptyArrayMap(TabMap *T)
{

    (*T).NeffArrayMap = 0;
}
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMaxArrayMap-IdxMinArrayMap+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtArrayMap(TabMap T)
{
    return (T.NeffArrayMap);
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbElArrayMap(TabMap T)
{
    return (IdxMaxArrayMap - IdxMinArrayMap + 1);
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxTypeArrayMap GetFirstIdxArrayMap(TabMap T)
{
    return IdxMinArrayMap;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
IdxTypeArrayMap GetLastIdxArrayMap(TabMap T)
{
    return (NbElmtArrayMap(T) - 1);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
ElTypeArrayMap GetElmtArrayMap(TabMap T, IdxTypeArrayMap i)
{
    return (T.TIMap[i]);
}
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTabArrayMap(TabMap Tin, TabMap *Tout)
{
    (*Tout).NeffArrayMap = Tin.NeffArrayMap;
    int i;
    for (i = IdxMinArrayMap; i <= IdxMaxArrayMap; i++)
    {
        (*Tout).TIMap[i] = Tin.TIMap[i];
    }
}
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
void SetElArrayMap(TabMap *T, IdxTypeArrayMap i, ElTypeArrayMap v)
{
    (*T).TIMap[i] = v;
    if (i == GetLastIdxArrayMap(*T) + 1)
    {
        (*T).NeffArrayMap++;
    }
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
void SetNeffArrayMap(TabMap *T, IdxTypeArrayMap N)
{
    (*T).NeffArrayMap = N;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidArrayMap(TabMap T, IdxTypeArrayMap i)
{
    return ((i >= IdxMinArrayMap) && (i <= IdxMaxArrayMap));
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEffArrayMap(TabMap T, IdxTypeArrayMap i)
{
    return ((i >= GetFirstIdxArrayMap(T)) && (i <= GetLastIdxArrayMap(T)));
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArrayMap(TabMap T)
{
    return (NbElmtArrayMap(T) == 0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFullArrayMap(TabMap T)
{
    return (NbElmtArrayMap(T) == MaxNbElArrayMap(T));
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

void InsertFirst(TabMap *T, ElTypeArrayMap v)
{
    int i;
    for (i = NbElmtArrayMap(*T); i > 0; i--)
    {
        (*T).TIMap[i] = (*T).TIMap[i - 1];
    }
    (*T).TIMap[0] = v;
    (*T).NeffArrayMap++;
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */

void InsertAt(TabMap *T, ElTypeArrayMap v, IdxTypeArrayMap i)
{
    int j;
    for (j = NbElmtArrayMap(*T); j > i; j--)
    {
        (*T).TIMap[j] = (*T).TIMap[j - 1];
    }
    (*T).TIMap[i] = v;
    (*T).NeffArrayMap++;
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

void InsertLast(TabMap *T, ElTypeArrayMap v)
{
    (*T).TIMap[NbElmtArrayMap(*T)] = v;
    (*T).NeffArrayMap++;
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

void DeleteFirst(TabMap *T)
{
    int i;
    for (i = 0; i < NbElmtArrayMap(*T); i++)
    {
        (*T).TIMap[i] = (*T).TIMap[i + 1];
    }
    (*T).NeffArrayMap--;
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

void DeleteAt(TabMap *T, IdxTypeArrayMap i)
{
    int j;
    for (j = i; j < NbElmtArrayMap(*T); j++)
    {
        (*T).TIMap[j] = (*T).TIMap[j + 1];
    }
    (*T).NeffArrayMap--;
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */

void DeleteLast(TabMap *T)
{
    (*T).NeffArrayMap--;
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */