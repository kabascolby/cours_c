#include <stdio.h>
#include <stdlib.h>

void decoupeminute(int *heures, int *minutes);

int main()
{
    int H;
    int M;
    H = 0;
    M = 90;
    decoupeminute(&H, &M);

    printf("%d heures %d minutes", H, M);

    return 0;
}

void decoupeminute(int *heures, int *minutes)
{
    *heures = *minutes / 60;
    *minutes = *minutes % 60;
    //printf("%d heures %d minutes", *heures, *minutes);
}