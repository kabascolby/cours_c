#ifndef _FT_STOCK_PAR_H
# define _FT_STOCK_PAR_H
# include <unistd.h>

typedef struct s_stock_par
{
    int size_param; char *str;
    char *copy;
    char **tab;
}           t_stock_par;

void ft_show_tab(struct s_stock_par *par);
void ft_putstr(char *str);
#endif