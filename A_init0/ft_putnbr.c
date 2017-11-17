#include <unistd.h>

void ft_putchar(char c);
void ft_putstr(char *str);

void ft_putnbr(int n)
{
    if ((n >= 0) && (n < 10))
        ft_putchar(n + '0');
    else if (n < 0)
    {
        ft_putchar('-');
        ft_putnbr(n *(-1));
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