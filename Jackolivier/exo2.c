#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putstr(char *str)
{
    int i;

    i = 0;
    while(*str)
    {
        ft_putchar(*str);
        str++;
    }
}

void ft_putnbr(int n)
{
    if((n >= 0) && (n < 10))
        ft_putchar(n + '0');
    else if(n < 0)
    {
        ft_putchar('-');
        ft_putnbr(n * (-1));
    }
    else if(n == -2147483648)
    {
        ft_putstr("-2147483648");
        return;
    }
    else
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
}
int ft_arrayfind(int *T, int len, int n)
{
    int i;

    i = 0;
    while( i < len)
    {
        if(T[i] == n)
            return 1;
        i++;
    }
    return 0;
}

int main()
{
    int T[6];
    int n;
    int a;
    
    T[0] = -1, T[1]= 2, T[2] = 4, T[3] = -3, T[4] = 8, T[5] = 9;
    
    ft_putstr("quel entier chercher vous dans le tableau: \n");
    scanf("%d", &n);
    a = ft_arrayfind(T, 5, n);
    ft_putnbr(a);
    ft_putchar('\n');    
    return 0;
}