#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("table de Multiplication par 5");

    int i;
    for (i = 0; i < 11; i++)
    {
        printf("5 * %d = %d\n", i , i*5);

    }

    return (0);
}