/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:15:37 by lkaba             #+#    #+#             */
/*   Updated: 2018/03/17 19:54:24 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_parse1(char *s, t_args *flags)
{		//printf("im here 1\n");
	int length;
	printf("%s\n", s);
	ft_bzero(flags, sizeof(t_args));
    ((*s == '%' && *(s + 1) == '%' ) ? ((s = (s + 2)),s2 = s, ft_addnode("%", 1, &head)): NULL);
	while (*s)
	{		
		flags->hash = *s == '#' ? 1 : flags->hash;
		flags->min = *s == '-' ? 1 : flags->min;
		flags->plus = *s == '+' ? 1 : flags->plus;
		flags->zero = *s == '0' ? 1 : flags->zero;
		flags->space = *s == ' ' ? 1 : flags->space;

		if (!CE_5(*s, '#', '-', '+', ' ', '0'))
			break ;
		s++;
	}
	flags->space = (flags->plus) ? 0 : flags->space;
	if (flags->plus)
		flags->space = 0;
	return(ft_parse2(s, flags));
}
char *ft_parse2(char *s, t_args *flags)
{
	printf("im in 2\n");
	while(*s)
	{		
		if (ft_isdigit(*s))
			while(ft_isdigit(*s))
				flags->field_w = (10 * flags->field_w) + NUM(*(s++));
		/* else if (*s == '*')
		{
			length = va_arg(*argp, int);
			*++fmt;
			if (length < 0)
			{
				ladjust = !ladjust;
				length = -length;
			}
		} */
		else if (*s == '.')
		{
			s++;
			flags->prec = 1;
			if (ft_isdigit(*s))
				while(ft_isdigit(*s))
					flags->precis =(10 * flags->precis) + NUM(*(s++));;
		}
		else
			break ;
		s++;

	}
	ft_struct_check(flags);
	return(ft_parse3(s, flags));
}

char *ft_parse3(char *s, t_args *flags)
	{
		enum l;
		
			if (*(s + 1) == 'h' || *s = 'h')
			{
				flags->length = l.h;
				s++;
				if(*s++ == 'h')
					flags->length = l.hh;
			}
			else if (*(s + 1) == 'l' || *s =='l')
			{
				flags->length = l.l;
				s++;
				if(*s++ == 'l')
					flags->length = l.ll;
			}
			else if (*s == 'j')
			{
				flags->length = l.j;
				s++;
			}
			else if (*s =='z')
			{
				flags->length = l.z;
				s++;
			}
			return(ft_parse4(*s, flags));
	}

	char *ft_parse4(char *s, t_args *flags)
	{
		if(*s)

	}
