#include <stdio.h>
#include "validator.h"

boolean validasi(char command[]) {
    // misalkan nerima command
    // ada list of command/kumpulan command2
    // nah inputan command

    boolean same = false;

    if (command == "START" || command == "LOAD " || command == "SAVE" || command == "CREATEGAME" || command == "LISTGAME"|| command == "DELETEGAME"|| command == "QUEUEGAME" || command == "PLAYGAME" ||command == "SKIPGAME" || command == "QUIT" || command == "HELP") {
        same = true;
    } else {
        same = false;
        printf("Command tidak dikenali, silahkan masukkan command yang valid.");
        scanf("ENTER COMMAND: %c", &command); 

    }
    return same;
}