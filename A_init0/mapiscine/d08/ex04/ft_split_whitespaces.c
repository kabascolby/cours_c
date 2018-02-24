#include "ft_stock_par.h"

int ft_iswhitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

int ft_countword(char *str)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while(str[i])
    {
        while (ft_iswhitespace(str[i]))
            str++;
        while((str[i]) && !ft_iswhitespace(str[i]))
            i++;
        len++;
        while (ft_iswhitespace(str[i]))
            i++;
    }
    return (len);
}

/* int ft_lenword(char *str)
{
    int len;
    len = 0;

    while(!ft_iswhitespace(*str))
    {
        len++;
        str++;
    }
    return (len);
} */

int ft_lenword(char *str)
{
    if (!*str)
        return (0);
    return (!ft_iswhitespace(*str++) ? ft_lenword(str) + 1 : 0 );
}

char **ft_split_whitespaces(char *str)
{ 
    char **tab;
    int i;
    int j;

    if (!str)
        return(NULL);

    if(!(tab = (char **)malloc(sizeof (char *) * ft_countword(str)+ 1)))
        return (NULL);
        i = 0;
    while(*str)
    {
       while(*str && ft_iswhitespace(*str))
        str++;
            
        if(*str && !ft_iswhitespace(*str))
        {
            if(!(tab[i] = (char *)malloc(sizeof (char) * ft_lenword(str))))
                return (0);
                j = 0;
            while(*str && !ft_iswhitespace(*str))
                tab[i][j++] = *str++;
            tab[i][j] = '\0';
            i++;
        }
    }
    tab[i] = NULL;
    return(tab);
}
