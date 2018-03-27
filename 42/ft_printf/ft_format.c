#include "ft_printf.h"

/*
	** if the flag zero is on then the field width is replaced by zero
	** '0' is ignnored when '-' is present;
	** the space depends also to the minus sign
	** space is ignnored when '+' is on
*/
void ft_field_width(t_p *p)
{
	format_conversion(p);
	p->f.prec ? ft_precision(p) : 0;
	if (CE_5(p->f.type, 'd', 'i', '%', 's', 'S'))
	{
		int pos;
		char fw;
		char f[p->f.field_w ? p->f.field_w + 1 : 1];
		p->f.space ? p->f.str = ft_frsplitstr(&p->f.str, 1, " ") : 0;
		p->f.plus ? p->f.str = ft_frsplitstr(&p->f.str, 1 , "+") : 0;
		p->f.len = ft_strlen(p->f.str);
		p->f.field_w = (p->f.field_w < p->f.len) ? 0 : p->f.field_w - p->f.len;
		f[p->f.field_w] = '\0';
		fw = p->f.zero ? '0' : ' ';
		ft_memset((char *)f, fw, p->f.field_w);
		pos = p->f.min ? p->f.len + 1 : 1 + p->f.plus + p->f.space;
		printf("position: %d, strlen: %d\n", pos, p->f.len);
		p->f.str = ft_frsplitstr(&p->f.str, pos, f);		
	}

}
