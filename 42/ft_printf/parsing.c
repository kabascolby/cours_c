/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:15:37 by lkaba             #+#    #+#             */
/*   Updated: 2018/03/20 07:00:02 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_parse1(char *s, t_args *flags)
{
	int length;
	ft_bzero(flags, sizeof(t_args));
	while (*s)
	{
		flags->hash = *s == '#' ? 1 : flags->hash;
		flags->min = *s == '-' ? 1 : flags->min;
		flags->plus = *s == '+' ? 1 : flags->plus;
		flags->zero = *s == '0' ? 1 : flags->zero;
		flags->space = *s == ' ' ? 1 : flags->space;

		if (!CE_5(*s, '#', '-', '+', ' ', '0'))
			break;
		s++;
	}
	flags->space = (flags->plus) ? 0 : flags->space;
	if (flags->plus)
		flags->space = 0;
	return (ft_parse2(s, flags));
}
char *ft_parse2(char *s, t_args *flags)
{
	while (*s)
	{
		if (ft_isdigit(*s))
			while (ft_isdigit(*s))
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
				while (ft_isdigit(*s))
					flags->precis = (10 * flags->precis) + NUM(*(s++));
			if(flags->precis < 1)
				flags->precis = 0;
		}
		else
			break;
		//s++;
	}
	return (ft_parse3(s, flags));
}

char *ft_parse3(char *s, t_args *flags)
{
	int k;

	k = 1;
	((*s == 'h') && (*(s + 1) != 'h')) ? flags->length = H : 1;
	((*s == 'l') && (*(s + 1) != 'l')) ? flags->length = L : k;
	(*s == 'j') ? flags->length = J : k;
	(*s == 'z') ? flags->length = Z : k;
	if ((*s == 'h') && *(s + 1) == 'h')
	{
		flags->length = HH;
		s++;
	}
	if ((*s == 'l') && *(s + 1) == 'l')
	{
		flags->length = LL;
		s++;
	}
	if (CE_4(*s, 'h', 'l', 'j', 'z'))
		s++;
	return (ft_parse4(s, flags));
}

char *ft_parse4(char *s, t_args *flags)
{
	if (CE_5(*s, 's', 'S', 'p', 'd', 'D') || CE_5(*s, 'i', 'o', 'O', 'u', 'U') || CE_5(*s, 'x', 'X', 'c', 'C', '%'))
	{
		//char str[]="s, S, p, d, D, i, o, O, u, U, x, X, c, C, %";
		flags->type = *s == 's' ? 's' : flags->type;
		flags->type = *s == 'S' ? 'S' : flags->type;
		flags->type = *s == 'p' ? 'p' : flags->type;
		flags->type = *s == 'd' ? 'd' : flags->type;
		flags->type = *s == 'D' ? 'D' : flags->type;
		flags->type = *s == 'i' ? 'i' : flags->type;
		flags->type = *s == 'o' ? 'o' : flags->type;
		flags->type = *s == 'O' ? 'O' : flags->type;
		flags->type = *s == 'u' ? 'u' : flags->type;
		flags->type = *s == 'U' ? 'U' : flags->type;
		flags->type = *s == 'x' ? 'x' : flags->type;
		flags->type = *s == 'X' ? 'X' : flags->type;
		flags->type = *s == 'c' ? 'c' : flags->type;
		flags->type = *s == 'C' ? 'C' : flags->type;
		flags->type = *s == '%' ? '%' : flags->type;
		s++;
	}
	/* if(flags->type)
		return(ft_conversion(flags)); */
	ft_struct_check(flags);
	return (s);
}
