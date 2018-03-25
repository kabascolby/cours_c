#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int *a;
    int j = 0;
    int y = 0;
    int neg = 0;

    j = (end - start);
    if (j < 0)
    {
        j *= -1;
        neg = 1;
    }
    j++;
    a = (int *)malloc(sizeof(int) * j);
    if (neg == 1)
        while (j >= y)
        {
            a[y] = end;
            end++;
            y++;
        }
    else if (neg == 0)
        while (j >= y)
        {
            a[y] = end;
            end--;
            y++;
        }
    return (a);
}