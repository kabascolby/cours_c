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
    else if(n == 4)
    {
        ft_putstr("le nombre");
        return;
    }
    else if(n < 0)
    {
        ft_putchar('-');
        ft_putnbr(n);
    }
    else
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
}

int main()
{
    int T[11];
    int i;

    i = 0;
    while(i < 11)
    {
        ft_putstr("Inserer l'element du tableau\n");
        scanf("%d", &T[i]);
        i++;
    }
    i = 0;
    while(i < 11)
    {
        ft_putnbr(T[i]);
        ft_putstr("| ");
        i++;
    }
    ft_putchar('\n');
    return 0;
}
