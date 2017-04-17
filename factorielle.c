#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
int  factorielle (n)
{
    int a;
    int i;
    a = 1;

    if (n <= 12 && n > 0)
    {
        for (i=1; i <= n; i++)
        {
            a *= i;

        }
        printf("%d\n", a);  
        return a;
    }
    else
        {
            printf("la factorielle doit etre suprieure ou egale a 12");
            return (0);
        }
}
int main(int argc, char *argv[])
{
    factorielle(12);
    return(0);
}