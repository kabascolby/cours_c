#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_putstr(char *str)
{
    while(*str)
    {
        ft_putchar(*str);
        str++;
    }
    return 0;
}

void ft_putnbr(int n)
{
    if ((n >= 0) &&  (n < 10))
        ft_putchar(n + '0');
    else if(n == -2147483648)
    {
        ft_putstr("-2147483648");
        return;
    }
    else if (n < 0)
    {
        ft_putchar('-');
        ft_putnbr(n);
    }
    else
    {
        ft_putnbr(n /10);
        ft_putnbr(n % 10);
    }
}

int ft_facto(int m)
{

    int i;
    int a;

    i = 1;
    a = 1;
    while(i <= m)
    {
        a *=i;
        i++;
    }

    return a;
}

void ft_arraydebug(int *T, int len)
{
    int i;

    ft_putstr("******** la liste des entiers du tableau **********\n");
    ft_putstr("----------------------------------------------------\n \n");
    i = 0;
    while( i < len)
    {
        T[i] = ft_facto(i);
        ft_putnbr(T[i]);
        ft_putstr("| ");
        i++;
    }
}

int main()
{
    int T[11];
    int i;
    ft_arraydebug(T, 12);
    return 0;
}
