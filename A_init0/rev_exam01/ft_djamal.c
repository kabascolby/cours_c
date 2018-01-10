/*#include <unistd.h>
#include <stdio.h>

void ft_swap(int *a, int *b)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
    
}

int main()
{
    int *a = 2015;
    int *b = 42;
    ft_swap(*a, *b);

   printf("a :%d, b: %d", a, b);

    return 0;
}*/

#include <stdio.h>

int		ft_djamal(int i, int j, int k)
{
    if(i >=j && i >= k)
    {
        if(j >= k)
            return(j);
        else
            return(k);
    }

    if(j >=i && j >= k)
    {
        if(i >= k)
            return(i);
        else
            return(k);
    }

    if(k >=i && k >= j)
    {
        if(j >= i)
            return(j);
        else
            return(i);
    }
    return(i);
}

int		main(void)
{
	printf("%d\n", ft_djamal(20, 7, 78));
	return(0);
}