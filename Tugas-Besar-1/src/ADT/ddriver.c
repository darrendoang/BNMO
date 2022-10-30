#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));   
    int r = rand();
    int s = rand();
    printf("%d %d", (1000*(r%15))+1000, s);
    
    char input1[10];
    char input2[10];

    scanf("%s %s", input1, input2);
    printf("%c", input2[0]);
    printf("%c", input2[1]);
    printf("%c", input2[2]);
    if (input2[2] == '\0'){
        printf("delta");
    }
    system("pause");
    return 0;
}