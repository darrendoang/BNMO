#include "listdp.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    List test;
    addresss add1, add2;
    elmntype temp;
    int a,b;

    CreateEmptylistdp(&test);

    if (IsEmptylistdp(test)){
        printf("List kosong\n");
    }

    add1 = Alokasilistdp("test", 1, 1);

    Dealokasilistdp(add1);

    add2 = Searchlistdp(test, 0, 0);

    InsVFirstlistdp(&test, "test", 1, 1);
    InsVLastlistdp(&test, "test", 1, 1);
    DelVFirstlistdp(&test, &temp, a, b);
    DelVLastlistdp(&test, &temp, a, b);
    InsertFirstlistdp(&test, add1);
    InsertLastlistdp(&test, add1);
    InsertAfterlistdp(&test, add1, add1);
    InsertBeforelistdp(&test, add1, add1);
    DelFirstlistdp(&test, add2);
    DelLastlistdp(&test, add2);
    DelPlistdp(&test, "test", 1, 1);
    DelAfterlistdp(&test, add2, add1);
    DelBeforelistdp(&test, add2, add1);

    PrintForwardlistdp(test);
    PrintBackwardlistdp(test);

}