#include <unistd.h>
void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{

    while(*str)
    {
     //   write(1, &str[i], 1);
     ft_putchar(*str);
       str++;
    }
}

int main ()
{
    ft_putstr("kaba lamine");
    return (0);
}