#include "towerofhanoi.h"

int optimal_moves(int x)
{
    if (x == 1)
    {
        return 1;
    }
    else
    {
        return 2 * optimal_moves(x - 1) + 1;
    }
}


void print_spaces(int x)
{
    for (int i = 0; i < x; i++)
    {
        printf(" ");
    }
}

void print_disks(int x)
{
    for (int i = 0; i < x; i++)
    {
        printf("*");
    }
}

void print_tower(int x, HanoiStack A, HanoiStack B, HanoiStack C)
{
    for (int i = 1; i <= x; i++)
    {
        int valA = A.T[x-i];
        int valB = B.T[x-i];
        int valC = C.T[x-i];
        if (valA != 0)
        {
            print_spaces(x - valA);
            print_disks(valA * 2 - 1);
            print_spaces(x - valA);
        }
        else
        {
            print_spaces(x - valA-1);
            printf("|");
            if (x % 4 != 0) print_spaces(x - valA);
            else print_spaces(x - (valA) - 1);
        }
        printf("\t");
        if (x % 4 == 0) printf("\t");
        if ((valB) != 0)
        {
            print_spaces(x - (valB)+1);
            print_disks((valB) * 2 - 1);
            print_spaces(x - (valB));
        }
        else
        {
            print_spaces(x - (valB));
            printf("|");
            print_spaces(x - (valB));
        }
        printf("\t");
        if ((valC) != 0)
        {
            print_spaces(x - (valC) + 1);
            print_disks((valC) * 2 - 1);
            print_spaces(x - (valC));
        }
        else
        {
            print_spaces(x - (valC));
            printf("|");
            print_spaces(x - (valC));
        }
        printf("\n");
    }
    print_spaces(x-1);
    printf("A");
    print_spaces(x);
    printf("\t");
    print_spaces(x);
    printf("B");
    print_spaces(x);
    printf("\t");
    print_spaces(x);
    printf("C");
    print_spaces(x);
    printf("\n\n");
}

void towerofhanoi()
{
    HanoiStack A, B, C, temp;
    int source, destination, valA, valB, valC;
    int score, n;
    int count = 0;
    CreateEmptyStack(&A);
    CreateEmptyStack(&B);
    CreateEmptyStack(&C);
    CreateEmptyStack(&temp);
    printf("SELAMAT DATANG DI TOWER OF HANOI\n");
    printf("Masukan jumlah disk: ");

    char *piringan;
    piringan = READINPUT();
    n = StrToInt_input(piringan, str_len(piringan));
    
    printf("\n");
    printf("\n");

    for (int i = n; i > 0; i--)
    {
        Push(&A, i);
        Push(&temp, i);
    }
    
    while(!IsCloneStack(C, temp))
    {
        print_tower(n, A, B, C);
        printf("TOWER ASAL: ");
        char *tower_asal;
        tower_asal = READINPUT();
        if (tower_asal[0] == 'A')
        {
            source =  1;
        }
        else if (tower_asal[0] == 'B')
        {
            source =  2;
        }
        else if (tower_asal[0] == 'C')
        {
            source =  3;
        }
        
        printf("TOWER TUJUAN: ");
        char * tower_tujuan;
        tower_tujuan = READINPUT();
        if (tower_tujuan[0] == 'A')
        {
            destination = 1;
        }
        else if (tower_tujuan[0] == 'B')
        {
            destination = 2;
        }
        else if (tower_tujuan[0] == 'C')
        {
            destination = 3;
        }
        printf("\n\n");
        int valA = top_val(A);
        int valB = top_val(B);
        int valC = top_val(C);
        if (source == 1 && valA != 0)
        {
            if (destination == 2)
            {
                if (valB == 0 || valA < valB)
                {
                    Pop(&A, &source);
                    Push(&B, source);
                    count++;
                }
                else printf("Tidak bisa dipindahkan\n");
            }
            else if (destination == 3)
            {
                if (valC == 0 || valA < valC)
                {
                    Pop(&A, &source);
                    Push(&C, source);
                    count++;
                }
                else printf("Tidak bisa dipindahkan\n");
            }
            else printf("Masukkan tidak valid\n");
        }
        else if (source == 2 && valB != 0)
        {
            if (destination == 1)
            {
                if (valA == 0 || valB < valA)
                {
                    Pop(&B, &source);
                    Push(&A, source);
                    count++;
                }
                else printf("Tidak bisa dipindahkan\n");
            }
            else if (destination == 3)
            {
                if (valC == 0 || valB < valC)
                {
                    Pop(&B, &source);
                    Push(&C, source);
                    count++;
                }
                else printf("Tidak bisa dipindahkan\n");
            }
            else printf("Masukkan tidak valid\n");
        }
        else if (source == 3 && valC != 0)
        {
            if (destination == 1)
            {
                if (valA == 0 || valC < valA)
                {
                    Pop(&C, &source);
                    Push(&A, source);
                    count++;
                }
                else printf("Tidak bisa dipindahkan\n");
            }
            else if (destination == 2)
            {
                if (valB == 0 || valC < valB)
                {
                    Pop(&C, &source);
                    Push(&B, source);
                    count++;
                }
                else printf("Tidak bisa dipindahkan\n");
            }
            else printf("Masukkan tidak valid\n");
        }
        else printf("Masukkan tidak valid\n");
    }
    print_tower(n, A, B, C);
    score = ((optimal_moves(n) / count) * 10 );
    printf("Kamu berhasil!\n");
    printf("\n");
    printf("Score didapatkan: %d\n", score);
    
}

int main()
{
    // printf("%d" , optimal_moves(5));
    towerofhanoi();
    return 0;
}