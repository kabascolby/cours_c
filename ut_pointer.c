#include <unistd.h>
#include <stdio.h>

void fct(int *a)
{
    *a = 12;
}

int main(void)
{
    int     a;
    a = 42;
    fct(&a);
    printf("%d\n", a);
    return(0);
}