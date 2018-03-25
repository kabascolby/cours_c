/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 04:13:13 by lkaba             #+#    #+#             */
/*   Updated: 2018/03/24 17:21:00 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_conversion(t_p *p)
{
	/* if (CE_5(*s, 's', 'S', 'p', 'd', 'D') || CE_5(*s, 'i', 'o', 'O', 'u', 'U') || CE_5(*s, 'x', 'X', 'c', 'C', '%')) */
	/* d, i o, u, x, X n */
	if (((p->f.type == 's') && (p->f.length == L)) || ((p->f.type == 'S') && (!p->f.type)))
		p->f.types.ws = (wchar_t *)va_arg(p->ap, wchar_t *);
	else if (((p->f.type == 'c') && (p->f.length == L)) || ((p->f.type == 'C') && (!p->f.type)))
		p->f.types.wc = (wchar_t)va_arg(p->ap, wchar_t);
	else if (p->f.type == 's')
	{
		p->f.str = (char *)va_arg(p->ap, char *);
		p->f.str = !(p->f.str) ? strdup("(null)") : p->f.str;
	}
	else if (CE_2(p->f.type, 'd', 'i'))
		p->f.types.im = (intmax_t)va_arg(p->ap, intmax_t);		
	else if((CE_5(p->f.type, 'o', 'u', 'x', 'O', 'U')) || (p->f.type == 'X')) // cheker le cas ou on donne les flags X et x
			p->f.types.um = (uintmax_t)va_arg(p->ap, uintmax_t);
	else if(p->f.type == '%')
			p->f.str = "%";
	else if(p->f.type == 'c')
		p->f.types.c = (char)va_arg(p->ap, char *);
	else
		return ;
	ft_field_width(p);
}

void format_conversion(t_p *p)
{	
	if(CE_2(p->f.type, 'd', 'i'))
	{
		p->f.sign = p->f.types.im < 0 ? '-' : p->f.sign;
		p->f.plus = p->f.sign ? 0 : p->f.plus;
		p->f.str = ft_itoa(p->f.types.im);
		p->f.len = ft_strlen(p->f.str);
	}
}

void ft_precision(t_p *p)
{
	char f[p->f.precis ? p->f.precis + 1 : 1];

	if (CE_2(p->f.type, 'd', 'i') && p->f.precis)
	{
		p->f.zero = 0;
		p->f.precis = (p->f.precis < p->f.len) ? 0 : p->f.precis - p->f.len;
		f[p->f.precis] = '\0';
		ft_memset((char *)f, '0', p->f.precis);
		p->f.str = ft_frsplitstr(&p->f.str, 1, f);
	}
}
