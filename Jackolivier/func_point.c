#include <stdio.h>

int ft_sum(int a, int b)
{
    return(a + b);
}
void af(void)
{
    printf("lamine kaba");
}
void ft_aff(void (*f)(void))
{
    f();
}

int main(void)
{
    int c;
    int (*p)(int, int);
    p = ft_sum;
    c =  p(7, 3);
    printf("%d\n", c);
    void (*k)(void);
    k = &af;
    ft_aff(k);
    ft_aff(af);
    return 0;
}