#include <stdlib.h>
#include <stdio.h>
#define RC printf("\n")

int main(int argc, char *argv[])
{
    int T[11];
    int i;
    i=0;
    while (i < 11)
    {
        printf("saiissez le nnombre %d: ", i+1);
        scanf("%d", &T[i]);
        ++i;
        RC;
    }
    i=0;
    while (i < 11)
    {
        printf("| %d ", T[i]);
        ++i;
    }
    RC;

    i=0;
    while (i < 11)
    {
        printf("| %d ", T[i]);
        ++i;
    }
    RC;

    return(0);
}