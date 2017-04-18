#include <stdio.h>
#include <stdlib.h>
#define RC printf("\n")

int  factorielle (m)
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
        T[i]= factorielle(i);
        printf("%d |", T[i]);
        i++;
    }
}

int main(int argc, char *argv[])
{
    int T[13];
    print_array(T, 13);
    return (0);
}