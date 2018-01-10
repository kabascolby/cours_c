#include <unistd.h>

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

int main()
{
    int T[6];
    int i;
    
    T[0] = -1, T[1]= 2, T[2] = 4, T[3] = -3, T[4] = 8, T[5] = 9;
    i = 0;
    while ( i < 6)
    {
        if (T[i] >= 0)
        {
            ft_putnbr(T[i]);
            ft_putstr("");
        }
        i++;
    }
    return 0;
}