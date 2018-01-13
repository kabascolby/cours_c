#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    return(*str ? ft_strlen(str++) + 1 : 0);
}

void ft_putstr(char *str)
{
    while(*str && str)
        write(1, str++, 1);
}

void wdmatch(char *s1, char *s2)
{
    char *b;
    b = s1;

    while(*s2)
    {
        if (*s2 == *s1)
            s1++;
        s2++;
    }

    if (!*s1)
        ft_putstr(b);
}

int main(int argc, char **argv)
{
    if(argc == 3)
        wdmatch(argv[1], argv[2]);
    ft_putstr("\n");
    return(0);
}