#include "ft_stock_par.h"

void ft_putstr(char *str)
{
    while(*str)
        write(1, str++, 1);
}
void ft_show_tab(struct s_stock_par *par)
{
    int i;
    int j;
    i = 0;
    while(par[i].str)
    {
        ft_putnbr(par[i].size_param);
        ft_putstr("\n");
        ft_putstr(par[i].copy);
        ft_putstr("\n");
        
        j = 0;
        while(par[i].tab[j])
        {
            ft_putstr(par[i].tab[j]);
            ft_putstr("\n");
            j++;
        }
        i++;
    }
}