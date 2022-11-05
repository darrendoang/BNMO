#include <stdio.h>
#include "stringcomp.h"

boolean str_comp(char str1[], char str2[]){
    
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

int main()
{
    char str1[50]; // declaration of char array
    char str2[50]; // declaration of char array

    printf("Enter the first string : ");
    scanf("%s", str1);
    printf("\nEnter the second string : ");
    scanf("%s", str2);
    
    int compare = str_comp(str1, str2); // calling compareTwoString() function.
    if (compare)
        printf("strings are equal");
    else
        printf("strings are not equal");
    return 0;
}
