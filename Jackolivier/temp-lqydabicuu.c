#include <stdio.h>
#include <stdlib.h>
#define RC printf("\n")

int     factorielle (m)
{
    
    if (m <= 12 && m >= 0)
    {
        int a;
        int i;
        a = 1;
        i = 1;
        while(i <= m)
        {
            a *= i;
            i++;

        }
       // printf("%d\n", a);  
        return a;
    }
    else
        {
            printf("la factorielle doit etre suprieure ou egale a 12\n");
            return (0);
        }
}

void print_array(int* T, int len)
{
    int i;
    
    i = 0;
    while(i < len)
    {
        printf("%d |", T[i]);
        i++;
    }
}

int main(int argc, char *argv[])
{
    int* T;
    int i;
    int n;
    i = 0;
    printf("Combien de cases voulez vous dans votre tableau: ");
    scanf("%d", &n);
    RC;
    while((n < 1) || (n > 12))
    {
        printf("Entrez une valeur entre 1 et 12: ");
        scanf("%d", &n);
        RC;
    }
    T = malloc(n * 4);
    while (i < n)
    {
        T[i]= factorielle(i);
        i++;
    }

    print_array(T, n);
    RC;
    free(T);
    return (0);
}