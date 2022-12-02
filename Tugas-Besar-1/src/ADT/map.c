#include <stdio.h>
#include "map.h"
#include "wordmachine.h"
#include "charmachine.h"

void CreateEmptyMap(Map *M) {
    (*M).Count = 0;
}

boolean IsEmptyMap(Map M) {
    return (M.Count == 0);
}

boolean IsFullMap(Map M) {
    return (M.Count == 10);
}

valuetype Value(Map M, keytype k) {
    int i;
    boolean found;

    i = 0;
    found = false;

    while (i < M.Count && !found) {
        if (M.Elements[i].Key == k) {
            found = true;
        } else {
            i++;
        }
    }

    if (found) {
        return (M.Elements[i].Value) ;
    } 
    else {
        return (Undefined) ;
    }
}

void Insert(Map *M, keytype k, valuetype v) {
    if (!IsMember((*M), k)) {
        (*M).Elements[(*M).Count].Key = k;
        (*M).Elements[(*M).Count].Value = v;
        (*M).Count++;
    }

}

void Delete(Map *M, keytype k) {
    int i;
    boolean found;

    i = 0;
    found = false;

    while (i < (*M).Count && !found) {
        if ((*M).Elements[i].Key == k) {
            found = true;
            while (i < (*M).Count - 1) {
                (*M).Elements[i] = (*M).Elements[i + 1];
                i++;
            }
            (*M).Count--;
        } 
        else {
            i++;
        }
    }
}

boolean IsMember(Map M, keytype k) {
    int i;
    boolean found;

    i = 0;
    found = false;

    while (i < M.Count && !found) {
        if (M.Elements[i].Key == k) {
            found = true;
        } 
        else {
            i++;
        }
    }

    return found;
}

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

/* ********** Operator Dasar Map ********* */
valuetype ValueMap(Map M, keytype k){
    if(IsMemberMap(M,k)){
        int i = 0;
        while(!IsStrEq(M.Elements[i].Key,k)){
            i++;
        }
        return(M.Elements[i].Value);
    }
    else{
        return(Undefined);
    }
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertMap(Map *M, keytype k, valuetype v){
    if(IsEmptyMap(*M)){
        (*M).Elements[0].Key = k;
        (*M).Elements[0].Value = v;
        (*M).Count = 1;
    }
    else{
        if(!IsMemberMap((*M),k)){
            int i = 0;
            while(i != ((*M).Count)){
                i++;
            }
            (*M).Elements[i].Key = k;
            (*M).Elements[i].Value = v;
            (*M).Count++;
        }
    }
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(Map *M, keytype k){
    if(IsMemberMap((*M),k)){
        int i = 0;
        while(i != ((*M).Count-1) && (*M).Elements[i].Key != k){
            i++;
        }
        int idxtemp;
        idxtemp = i;
        for(idxtemp ; idxtemp <= (*M).Count-1 ; idxtemp++){
            (*M).Elements[idxtemp] = (*M).Elements[idxtemp+1];
        }
        (*M).Elements[(*M).Count-1].Key = '\0';
        (*M).Elements[(*M).Count-1].Value = Undefined;
        (*M).Count--;
    }
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMap(Map M, keytype k){
	int i;
	i = 0;
	boolean ada;
	ada = false;
	while (i < M.Count && ada == false)
	{
		if (IsStrEq(M.Elements[i].Key,k))
		{
			ada = true;
		}
		i++;
	}
	return ada;
}
/* Mengembalikan true jika k adalah member dari M */

int IMAX (Map *map){
    int imax;
    imax = 0;
    for (int i = 1 ; i<map->Count ; i++){
        if (map->Elements[i].Value > map->Elements[imax].Value){
            imax = i;
        }
    }
    return imax;
}

int lenmax (Map *map){
    int lenmax;
    lenmax = 0;
    for (int i = 0 ; i<map->Count;i++){
        if(LengthStr(map->Elements[i].Key)>lenmax){
            lenmax = LengthStr(map->Elements[i].Key);
        }
    }
    return lenmax;
}

Map CopyMap (Map *map){
    Map temp;
    CreateEmptyMap(&temp);
    for (int i = 0;i<map->Count;i++){
        InsertMap(&temp,map->Elements[i].Key,map->Elements[i].Value);
    }
    return temp;
}

char* numToString(int val){
    if(val==0){
        return "0";
    }
    else{
         static char buf[32] = {0};
        int i = 30;
        for(; val && i ; --i, val /= 10)
            buf[i] = "0123456789abcdef"[val % 10];
        return &buf[i+1];
    }
}