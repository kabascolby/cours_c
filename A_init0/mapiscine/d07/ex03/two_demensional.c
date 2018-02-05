#include <stdio.h>

int main(void)
{
    int p[4][2] =   { 
                    {1234, 56},
                    {1212, 33},
                    {1434, 80},
                    {1312, 78}
                    };
    //int (*q)[2];
    int *q;
    q = p;

    int i;
    int j;

    i = 0;
    j = 0;

    while (i < 4)
    {
        
        j = 0;
        while(j < 2)
        {
            printf("%d ",*(q + i + j * i));
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}