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