/*****  #include <unistd.h>

void ft_putchar (char c)
{
    write (1, &c, 1);
}

void ft_chaine()
{
    char* a; 
    a = "hello world ! \n";
    int i;
    i = 0;
    while (i <= 13)
    {
        ft_putchar(*(a+i));
        ft_putchar(' ');
        i++;
    }

}

int main()
{
    ft_chaine();
    return(0);
}

Deuxieme version */

#include <unistd.h>

int ft_putchar (char c)
{
    write (1, &c, 1);
    return(0);
}

void ft_chaine()
{
    char* a; 
    a = "hello girls and boys in a world ! \n";
    int i;
    i = 0;
    while (*(a + i) != 0)
    {
        ft_putchar(*(a+i));
       // ft_putchar(' ');
        i++;
    }

}

int main()
{
    ft_chaine();
    return(0);
}