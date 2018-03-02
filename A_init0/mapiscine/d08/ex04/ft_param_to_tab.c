#include "ft_stock_par.h"

int ft_strlen(char *str)
{
    return(*str++ ? ft_strlen(str) + 1 : 0 );
}
char *ft_strdup(char *str)
{
    char *tab;
    tab = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
    int i;
    i = 0;
    while (*str)
        tab[i++] = *str++;
    tab[i] = '\0';
    return(tab);
}

struct s_stock_par *ft_param_to_tab(int ac, char **av)
{
    t_stock_par *T;
    T = (t_stock_par *)malloc(sizeof(t_stock_par) * (ac + 1));

    int i;
    
    i = -1;
    while (++i < ac)
    {
        T[i].size_param = ft_strlen(av[i]);
        T[i].str = av[i];
        T[i].copy = ft_strdup(av[i]);
        T[i].tab = ft_split_whitespaces(av[i]);
    }
    T[i].str = 0;
    return (T);
}