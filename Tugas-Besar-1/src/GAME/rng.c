#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
    int i;
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X\n");
    srand(time(0));
    int r= rand();
    int flag = 0;
    while (flag == 0)
    {
        printf("Tebakan: ");
        scanf("%d" , &i);
        if (i > r)
        {
            printf("Lebih kecil\n");
        }
        else if (i < r)
        {
            printf("Lebih besar\n");
        }
        else
        {
            flag = 1;
        }
        
        
    }
    if (flag==1)
    {
        printf("Ya, X adalah %i" , r);
    }
    
    return 0;
}