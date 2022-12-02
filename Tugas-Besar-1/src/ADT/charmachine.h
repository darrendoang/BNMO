#ifndef CHAR_ENGINE_H
#define CHAR_ENGINE_H

#include "boolean.h"

#define NEWLINE '\n'
/* Char Engine State */
extern char currentCharS;
extern boolean EOPS;

void STARTS();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentCharS adalah karakter pertama pada pita
          Jika currentCharS != MARK maka EOPS akan padam (false)
          Jika currentCharS = MARK maka EOPS akan menyala (true) */

void ADVS();
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentCharS, currentCharS != MARK
   F.S. : currentCharS adalah karakter berikutnya dari currentCharS yang lama, 
          currentCharS mungkin = MARK
          Jika  currentCharS = MARK maka EOPS akan menyala (true) */

char GetCCS();
/* Mengirimkan currentCharS */

boolean IsEOPSS();
/* Mengirimkan true jika currentCharS = MARK */

#endif
