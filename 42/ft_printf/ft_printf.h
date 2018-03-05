#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_pfnode
{
    char            *s;
    struct s_pfnode *next;
}               t_pfnode;

typedef struct s_printf
{
    int         c;
    t_pfnode    *head;  
}              t_p;
#endif

typedef struct s_args
{
    int min;
    int plus;
    int space;
    int hash;
    int zero;
    int 

    int width

}               t_args;