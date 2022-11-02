#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
    int i , score= 10;
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X\n");
    srand(time(0));
    int r= rand();
    int flag = 0;
    
    while (flag == 0 && score > 0)
    {
        printf("Tebakan: ");
        scanf("%d" , &i);
        if (i > r)
        {
            printf("Lebih kecil\n");
            score = score -1;
        }
        else if (i < r)
        {
            printf("Lebih besar\n");
            score = score -1;
        }
        else
        {
            flag = 1;
        }
        
        
    }
    if (flag==1 && score > 0)
    {
        printf("Ya, X adalah %i" , r);
    }
    else if(score == 0)
    {
        printf("Kesempatan menebak Anda habis.");
    }

    return 0;
}