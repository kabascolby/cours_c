#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
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

int ft_array_count(int* T, int len, int n)
{
    int i;
    int a;

    i = 0;
    a = 0;

    while(i < len)
    {
        if(T[i] == n)
        {
            a++;
        }
        i++;
    }
    return a;
}
int main()
{
    int count;
    int T[8];
    T[0] = 1; T[1] = 9; T[2] = 1; T[3] = 4; T[4] = 8; T[5] = 9; T[6] = 1; T[7] = 6;
    count = ft_array_count(T, 8, 1);
    ft_putnbr(count);
    return 0;
}