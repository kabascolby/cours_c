#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_countword(char *str)
{
    int len;
    len = 0;
    while(*str)
    {
        while(*str && *str < 33)
            str++;
        while(*str && *str > 32)
            str++;
        len++;
        while(*str && *str < 33)
            str++;
    }
    return (len);
}

int ft_lenoneword(char *str)
{
    int len;
    len = 0;
    while(str[len] &&  str[len] > 32)
        len++;
    printf("%d", len);
    return (len);
}

char **ft_split_whitespaces(char *str)
{
    char **tab;
    int i;
    int j;
    
    i = 0;
    if (!(tab = (char **)malloc(sizeof(char*) * ft_countword(str) + 1)))
        return (0);
    while(*str)
    {
        while(*str && *str < 33)
            str++;
            j = 0;
        if(*str && *str > 32)
        {
            tab[i] = (char *)malloc(sizeof(char *) * ft_lenoneword(&(*str) + 1));
            while(*str && *str > 32)
                tab[i][j++] = *str++;
        }
        
        tab[i][j] = '\0';
        i++;
    }
    tab[i] = NULL;
    return(tab);
}
void ft_print_words_tables(char **tab)
{
   // tab = ft_splitwhitespaces(tab);
    int i;
    int j;

    i = 0;
    while(tab[i])
    {
        j = 0;
        while(tab[i][j])
            ft_putchar(tab[i][j++]);
        ft_putchar('\n');
        i++;   
    }
}

int main()
{
    char *s = "Lamine kba";
    ft_print_words_tables(ft_split_whitespaces(s));
    return (0);
}

