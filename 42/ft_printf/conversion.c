#include "ft_printf.h"

void ft_conversion(char *s, va_list *ap, t_args *flags, t_pfnode **head)
{
    flags->str = va_arg(*ap, char *);
    ft_addnode(flags->str, ft_strlen(flags->str), head);
    //printf("varg :%s\n",va_arg(*ap, char *));
}