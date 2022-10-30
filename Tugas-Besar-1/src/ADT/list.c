#include "list.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
List MakeList(){
    List temp;
    IdxType i;
    for (i=0;i<MaxEl;i++){
        temp.A[i] = Mark;
    }
    return temp;
} //
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty(List L){
    return (L.A[0] == Mark);
}
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

/* *** Menghasilkan sebuah elemen *** */
ElType Get(List L, IdxType i){
    return L.A[i];
}
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void Set(List *L, IdxType i, ElType v){
    L->A[i] = v; //
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length(List L){
    IdxType idx = 0;
    while ((L.A[idx]!=Mark)&&(idx<MaxEl)){
        idx++;
    }
    return idx;
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Selektor INDEKS *** */
IdxType FirstIdx(List L){
    IdxType idx = 0;
    while (L.A[idx] == Mark){
        idx++;
    }
    return idx;
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType LastIdx(List L){
    return (Length(L)-1);
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (List L, IdxType i){
    return ((i>=FirstIdx(L)) && (i<MaxEl));
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/

boolean IsIdxEff (List L, IdxType i){
    return ((i>=FirstIdx(L)) && (i<=LastIdx(L)));
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

/* ********** Operasi-operasi ********** */
boolean Search(List L, ElType X){
    boolean find = false;
    IdxType i = FirstIdx(L);
    while ((i<=LastIdx(L))&&(!find)){
        if (L.A[i]==X){
            find = true;
        }else{
        i++;
        }
    }
    return find;
}
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

void InsertFirst(List *L, ElType X){
    L->A[0] = X;
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */

void InsertAt(List *L, ElType X, IdxType i){
    IdxType j;
    j = Length(*L);
	while(j>i){
		L->A[j] = L->A[j-1];
		j--;
    }
    L -> A[i] = X;
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

void InsertLast(List *L, ElType X){
    L -> A[Length(*L)] = X;
}

void DeleteFirst(List *L){
    IdxType i,j;
    i = 0;
    j = LastIdx(*L);
	while(i<j){
		L->A[i] = L->A[i+1];
		i++;
    }
    L -> A[j] = Mark;
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

void DeleteAt(List *L, IdxType i){
    IdxType j;
    j = LastIdx(*L);
	while(i<j){
		L->A[i] = L->A[i+1];
		i++;
    }
    L -> A[j] = Mark;
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */

void DeleteLast(List *L){
    L -> A[Length(*L)] = Mark;
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */

List Concat(List L1, List L2){
    List temp;
    temp = MakeList();
    IdxType i,j,k;
    for (i=0; i<=LastIdx(L1);i++){
        Set(&temp, i, L1.A[i]);
    }
    k = LastIdx(L1) + 1;
    for (j=0; i<=LastIdx(L2);j++){
        Set(&temp, k, L2.A[j]);
        k++;
    }
    return temp;
}
/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */