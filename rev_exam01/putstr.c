#include <unistd.h>
void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    int i;
    
    i = 0;
    while(str[i] != '\0')
    {
     //   write(1, &str[i], 1);
     ft_putchar(str[i]);
        i++;
    }
}

int main ()
{
    ft_putstr("kaba lamine");
    return (0);
}