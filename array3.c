#include <stdlib.h>
#include <stdio.h>
#define RC printf("\n")

int     factorielle (m)
{
    if(m <= 12 && m >= 0)
    {
        int a;
        int i;

        a = 1;
        i = 1;
        while ( i <= m)
        {
            a *= i;
            printf("%d: ", a);
            RC;
            i++;
        }
        printf("%d: ", a);
        RC;
        return a;
    }
    else
        {
            printf("le nombre doit etre de 0 à 12");
            return(0);
        }
}

void array_display(int* T, int len)
{
    int i;
    
    i = 0;
    while( i < len)
    {
        printf("%d |", T[i]);
        i++;
    }
}

int main(int argc, char *argv[])
{
    int n;
    int* T;

    int i;
    i = 0;
    printf("entrer la longeur du tableau (1..12)");
    scanf("%d", &n);
    
    while(( n < 1) || (n > 13))
    {
        printf("la longeur du tableau doit etre de 1 a 13");
        scanf("%d", &n);
    }
    T = malloc(n * 4);
    while (i > n)
    {
        T[i] = factorielle(i);
        i++;
    }
    array_display(T, n);
    free(T);
    return (0);
}