#include <stdio.h>
#include "map.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M)
{
    (*M).Count = Null;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Null */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsMapEmpty(Map M)
{
    return (M.Count == Null);
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Null */

boolean IsMapFull(Map M)
{
    return (M.Count == MaxEl);
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k)
{
    if (!IsMember(M, k))
    {
        return Undefined;
    }
    else
    {
        int i;
        i = 0;
        while (M.Elements[i].Key != k)
        {
            i++;
        }
        return M.Elements[i].Value;
    }
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insert(Map *M, keytype k, valuetype v)
{
    if (IsMapEmpty(*M))
    {
        (*M).Count = 1;
        (*M).Elements[0].Key = k;
        (*M).Elements[0].Value = v;
    }
    else
    {
        if (!IsMember(*M, k))
        {
            (*M).Elements[(*M).Count].Key = k;
            (*M).Elements[(*M).Count].Value = v;
            (*M).Count++;
        }
    }
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void Delete(Map *M, keytype k)
{
    if (IsMember(*M, k))
    {
        int i;
        i = 0;
        while ((*M).Elements[i].Key != k)
        {
            i++;
        }
        for (i; i < (*M).Count - 1; i++)
        {
            (*M).Elements[i] = (*M).Elements[i + 1];
        }
        (*M).Count--;
    }
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMember(Map M, keytype k)
{
    int i;
    i = 0;
    boolean found;
    found = false;
    while (i < M.Count && !found)
    {
        if (str_comp(M.Elements[i].Key,k))
        {
            found = true;
        }
        i++;
    }
    return found;
}
/* Mengembalikan true jika k adalah member dari M */

void SortMapValueDesc(Map *M)
{
    int i, j;
    i = 1;
    infotype temp;
    for (i; i < (*M).Count; i++)
    {
        temp = (*M).Elements[i];
        j = i - 1;
        while (j >= 0 && (*M).Elements[j].Value < temp.Value)
        {
            (*M).Elements[j + 1] = (*M).Elements[j];
            j = j - 1;
        }
        (*M).Elements[j + 1] = temp;
    }
}
/* Mengurutkan Value dari Map terurut mengecil */