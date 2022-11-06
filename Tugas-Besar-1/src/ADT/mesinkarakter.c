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

char *READINPUT()
{
    pita = stdin;
    char *stringinput;
    int c;
    int i = 0;
    stringinput = (char *)malloc(101 * sizeof(char));
    while (c = fgetc(pita))
    {
        if (c == EOF || c == '\n' || c == '\r')
        {
            break;
        }
        *(stringinput + i) = (char)c;
        i++;
    }
    *(stringinput + i) = '\0';
    return stringinput;
}
