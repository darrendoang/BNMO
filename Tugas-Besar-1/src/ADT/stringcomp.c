#include <stdio.h>
#include "stringcomp.h"
#include "boolean.h"


int str_comp(char str1[], char str2[]){
    
    int i=0;

    while(str1[i] == str2[i]){
        if( str1[i] == '\0' || str2[i] == '\0' ) 
            break;
        i++;
    }

    if( str1[i] == '\0' &&  str2[i] == '\0' )    
        return true;    
    else    
        return false; 
}
