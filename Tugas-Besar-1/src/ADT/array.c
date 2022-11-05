/* File array.c */
#include "../ADT/array.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (Array *T) {
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
    // KAMUS LOKAL
    // ALGORITMA
    T->Neff = 0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (Array T) {
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
    // KAMUS LOKAL
    // ALGORITMA
    return T.Neff;
}

/* *** Daya tampung container *** */
int MaxNbEl (Array T) {
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    // KAMUS LOKAL
    // ALGORITMA
    return IdxMax - IdxMin + 1;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (Array T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
    // KAMUS LOKAL
    // ALGORITMA
    return IdxMin;
}

IdxType GetLastIdx (Array T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
    // KAMUS LOKAL
    // ALGORITMA
    return T.Neff;
}

/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (Array T, IdxType i) {
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
    // KAMUS LOKAL
    // ALGORITMA
    return T.TI[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (Array Tin, Array *Tout) {
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
    // KAMUS LOKAL
    // ALGORITMA
    MakeEmpty(Tout);
    for (int i = IdxMin; i <= Tin.Neff; i++) {
        Tout->TI[i] = Tin.TI[i];
    }
    Tout->Neff = Tin.Neff;
}

void SetEl (Array *T, IdxType i, ElType v) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
    // KAMUS LOKAL
    // ALGORITMA
    T->TI[i] = v;
    if (i > T->Neff) {
        T->Neff = i;
    }
}

void SetNeff (Array *T, IdxType N) {
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
    // KAMUS LOKAL
    // ALGORITMA
    T->Neff = N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (Array T, IdxType i) {
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
    // KAMUS LOKAL
    // ALGORITMA
    return (i >= IdxMin && i <= IdxMax);
}

boolean IsIdxEff (Array T, IdxType i) {
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
    // KAMUS LOKAL
    // ALGORITMA
    return (i >= IdxMin && i <= T.Neff);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (Array T) {
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    // KAMUS LOKAL
    // ALGORITMA
    return T.Neff == 0;
}

/* *** Test tabel penuh *** */
boolean IsFull (Array T) {
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    // KAMUS LOKAL
    // ALGORITMA
    return T.Neff == IdxMax;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (Array T) {
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
0:1
1:2
2:3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */
    // KAMUS LOKAL
    // ALGORITMA
    if (IsEmpty(T)) {
        printf("Tabel kosong\n");
    } else {
        for (int i = 0; i < T.Neff; i++) {
            printf("%d:%s\n", i, T.TI[i]);
        }
    }
}

/* ********** NILAI EKSTREM ********** */
ElType ValMax (Array T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
    // KAMUS LOKAL
    // ALGORITMA
    return T.TI[IdxMaxTab(T)];
}

ElType ValMin (Array T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
    // KAMUS LOKAL
    // ALGORITMA
    return T.TI[IdxMinTab(T)];
}

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (Array T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */
    // KAMUS LOKAL
    int indexmax = IdxMin;
    // ALGORITMA
    for (int i = IdxMin+1; i <= T.Neff; i++) {
        if (T.TI[i] > T.TI[indexmax]) {
            indexmax = i;
        }
    }
    return indexmax;
}

IdxType IdxMinTab (Array T) {
/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i */
/* dengan elemen ke-i nilai minimum pada tabel */
    // KAMUS LOKAL
    int indexmin = IdxMin;
    // ALGORITMA
    for (int i = IdxMin+1; i <= T.Neff; i++) {
        if (T.TI[i] < T.TI[indexmin]) {
            indexmin = i;
        }
    }
    return indexmin;
}