#include <stdio.h>
#include <stdlib.h>
#define RC printf("\n")

int                                            factorielle(m)
{
    if((m <= 12) || (m >= 0))
    {
        int i;
        int a;

        a = 1;
        i = 1;
        while(i <= m)
        {
            a *= i;
            i++;
        }
        return a;
    }
    else
    {
        printf("entrer une valeur entre 0 et 12");
        return 0;
    }
}
void print_array(int *T, int len)
{
    int i;
    i = 0;
    while( i < len)
    {
        printf("%d |",T[i]);
        i++;
    }
}
int main(int argc, char * argv[])
{
    int n;
    int i;
    int* A;

    i = 0;
    printf("Entrer le mombre de cases du Tableau: ");
    scanf("%d", &n);
    RC;
    while ((n < 1 ) || (n > 12 ))
    {
        printf("le nombre doit etre de 0 a 12: ");
        scanf("%d", &n);
        RC;
    }

    A = malloc(n * 4);
    while(i < n)
    {
        A[i] = factorielle(i);
        i++;
    }
    print_array(A, n);
    RC;
    free(A);
    return (0);
}