#include <stdio.h>
#include "map.h"

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