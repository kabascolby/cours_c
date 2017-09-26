#include <unistd.h>

int ft_putchar (char c)
{
    write (1, &c, 1);
    return 0;
}
void ft_alphabet()
{
    char tutu;
    tutu = 65 ;
    while (tutu <= 'z')
    {
        ft_putchar(tutu);
        ft_putchar(' ');
        tutu = tutu + 1;
    }
}

    int main()
    {
        ft_alphabet();
        return (0);
    }
