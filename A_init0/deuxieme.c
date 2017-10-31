#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/* int main()
{
    int toto;
    int tata;
    char titi;

    toto = 5;
    tata = 7;
    titi = 'A';

    printf("%d %d %c", toto, tata, titi);
    return 0;
} */

void ft_putchar(char c)
{
    write(1, &c, 1);
}
int ft_putstr(char *str)
{
    while(*str)
    {
        write(1, &(*str), 1);
        str++;
    }
    return 0;
}

void ft_putnbr(int n)
{
    if ((n >= 0) && (n < 10))
    ft_putchar(n + '0');

    else if(n == -2147483648)
    {
        ft_putstr("-2147483648");
        return;
    }
    else if (n < 0)
    {
        write(1, "-", 1);
        ft_putnbr(n * (-1));
    }
    else
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
   
}
int main()
{
    int toto;
    int tata;
    char titi;

    toto = 5;
    tata = 8;
    titi = 'A';
    ft_putnbr(toto);
    ft_putchar(' ');
    ft_putnbr(tata);
    ft_putchar(titi);
    return 0;
}