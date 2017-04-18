#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
int  factorielle (n)
{
    
    if (n <= 12 && n >= 0)
    {
        int a;
        int i;
        a = 1;
        for (i=1; i <= n; i++)
        {
            a *= i;

        }
        printf("%d\n", a);  
        return a;
    }
    else
        {
            printf("la factorielle doit etre suprieure ou egale a 12\n");
            return (0);
        }
}
int main(int argc, char *argv[])
{
    factorielle(4);
    return(0);
}