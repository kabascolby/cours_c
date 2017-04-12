#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}


void ft_putstr(char *str)
{
    int i;
    i = 0;
    while (str[i] != 0 )
    {
        ft_putchar(str[i]);
        i++;
    }
}

void ft_swap_char(char *c1/*, char *c2*/)
{
    *c1= *c2 ;
}
int main()
{
    char str1[] = "hello";
    char *str2 = "kaba";
    ft_putstr(str1);
    ft_putchar('\n');
    ft_swap_char(str1, str2);
    ft_putstr(str1);
    ft_putchar('\n');
    return(0);     
}