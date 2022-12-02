#include "charmachine.h"
#include <stdio.h>

char currentCharS;
boolean EOPS;

static FILE * pita;
static int retval;

void STARTS() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentCharS adalah karakter pertama pada pita
          Jika currentCharS != MARK maka EOPS akan padam (false)
          Jika currentCharS = MARK maka EOPS akan menyala (true) */

	/* Algoritma */
	pita = stdin;
	ADVS();
}

void ADVS() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentCharS, currentCharS != MARK
   F.S. : currentCharS adalah karakter berikutnya dari currentCharS yang lama, 
          currentCharS mungkin = MARK
		      Jika  currentCharS = MARK maka EOPS akan menyala (true) */

	/* Algoritma */
	retval = fscanf(pita,"%c",&currentCharS);
   EOPS = (currentCharS == NEWLINE);
}

char GetCCS(){
    return currentCharS;
}
/* Mengirimkan currentCharS */

boolean IsEOPSS(){
   return EOPS;
}
/* Mengirimkan true jika currentCharS = MARK */
