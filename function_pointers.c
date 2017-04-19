#include <unistd.h>

typedef void (*funptr)(char);

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int     main()
{
    funptr      f;
   // void (*f)(char);
    f = &ft_putchar;
    f('z');
    return (0);
}