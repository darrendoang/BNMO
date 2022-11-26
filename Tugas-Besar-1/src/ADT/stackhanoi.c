#include <stdio.h>
#include "stackhanoi.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stackhanoi *S)
{
    Top(*S) = Nil;
    for(int i = 0; i < MaxEl; i++)
    {
        (*S).T[i] = 0;
    }
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty(Stackhanoi S)
{
    return (Top(S) == Nil);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsStackFull(Stackhanoi S)
{
    return (Top(S) == MaxEl - 1);
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stackhanoi *S, stackinfotype X)
{
    Top(*S) += 1;
    InfoTop(*S) = X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stackhanoi *S, stackinfotype *X)
{
    *X = InfoTop(*S);
    InfoTop(*S) = 0;
    Top(*S) -= 1;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

boolean IsCloneStack(Stackhanoi S1, Stackhanoi S2)
{
    if (IsStackEmpty(S1) && IsStackEmpty(S2))
    {
        return true;
    }
    else if (IsStackEmpty(S1) || IsStackEmpty(S2))
    {
        return false;
    }
    else
    {
        stackinfotype X1, X2;
        Pop(&S1, &X1);
        Pop(&S2, &X2);
        if (X1 != X2)
        {
            return false;
        }
        else
        {
            return IsCloneStack(S1, S2);
        }
    }
}

int top_val(Stackhanoi S) {
    if (IsStackEmpty(S)) {
        return 0;
    } else {
        return InfoTop(S);
    }
}