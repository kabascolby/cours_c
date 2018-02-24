#ifndef __FT_STOCK_PAR_H_
# define __FT_STOCK_PAR_H_
# include <stdlib.h>
# include <unistd.h>


typedef struct s_stock_par 
{
    int size_param;
    char *str;
    char *copy;
    char **tab;
}            t_stock_par;

struct s_stock_par *ft_param_to_tab(int ac, char **av);
void	ft_show_tab(struct s_stock_par *par);
int ft_iswhitespace(char c);
int ft_countword(char *str);
int ft_lenword(char *str);
char **ft_split_whitespaces(char *str);
#endif
