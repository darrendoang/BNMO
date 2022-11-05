#include <stdio.h>
#include <stdlib.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START()    {
    pita = stdin;
    ADV();
}

void ADV()  {
    retval = fscanf(pita, "%c", &currentChar);
    // eop = IsEOP();
    // if (eop)    {
    //     fclose(pita);
    // }
}


char GetCC()    {
    return currentChar;
}

boolean IsEOP()   {
    return (currentChar == MARK);
}