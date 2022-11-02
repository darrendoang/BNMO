#include <stdio.h>
#include <stdlib.h>
#include "mesinkarakter.h"

char cc;
boolean eop;

static FILE *pita;
static int retval;

void START()    {
    pita = stdin;
    ADV();
}

void ADV()  {
    retval = fscanf(pita, "%c", &cc);
    eop = IsEOP();
    if (eop)    {
        fclose(pita);
    }
}


char GetCC()    {
    return cc;
}

boolean IsEOP()   {
    return (cc == MARK);
}