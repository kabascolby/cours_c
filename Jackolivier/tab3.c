#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
    int i;
    int n;
    int* T;
    ft_putstr("inserer le nombre d'element de votre tableau \n");
    scanf("%d", &n);
    while((n < 1) || (n >13))
    {
        ft_putstr("Saisissez une valeur entre 1 et 13 \n");
        scanf("%d", &n);
    }
    T = malloc(n * 4);
    ft_arraydebug(T, n);
    free (T);
    return 0;
}
