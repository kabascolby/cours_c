#include <unistd.h>

int ft_putchar(char c)
{
    write(1, &c, 1);
    return(0);
}

void asci()
{
    unsigned char kaba;
    kaba = 0;

    while (kaba <= 127)
    {
        ft_putchar(kaba);
        kaba++;
    }
}

int main()
{
    asci();
    ft_putchar('\n');
    return(0);
}