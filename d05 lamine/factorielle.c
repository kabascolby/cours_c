#include <stdlib.h>
#include <stdio.h>

void  factorielle (n)
{
    int a;
    int i;
    a = 1;

    for (i=1; i <= n; i++)
    {
        a *= i;

    }
    printf("%d\n", a);
    //return a;
}
int main(int argc, char *argv[])
{
    factorielle(5);
    return(0);
}