#include "ft_printf.h"

void ft_field_width(t_p *p)
{
    format_conversion(p);
    if (CE_2(p->f.type, 'd', 'i'))
    {
        u_int8_t pos;
        char fw;
        char f[p->f.field_w = p->f.field_w > p->f.len? ((p->f.field_w - p->f.len ) - 1) : 0];

        fw = p->f.zero ? '0' : ' ';
        pos = p->f.min ? (ft_strlen(p->f.str) + 1 + p->f.precis) : 1;
        pos = p->f.min ? pos + 1 : pos;
        printf("position: %d\n", pos);
        p->f.prec ? ft_precision(p) : 0;
        p->f.len = ft_strlen(p->f.str);        
        /** if the flag zero is on then the width if fill by zero else by space who's depend also to the minus sign **/
        //p->f.field_w = p->f.field_w > p->f.len? (p->f.field_w - p->f.len) : 0;
    
        f[p->f.field_w = (p->f.min && p->f.prec)? (p->f.field_w - 2) : p->f.field_w] = '\0'; /** if the plus is on I add \0 at the f_w -2**/
        ft_memset((char *)f, fw, p->f.field_w);
        //f[p->f.field_w - 1] = p->f.plus &&  p->f.field_w ? '+' : fw;
        p->f.str = ft_frsplitstr(&p->f.str, pos, f);
    }
        (p->f.space || p->f.plus) && p->f.types.im ? flags_space_sign(p) : 0;
         p->f.zero && (p->f.types.im || p->f.types.um) ? flags_zero(p) : 0;
}

void flags_space_sign(t_p *p)
{
   
   // printf("pos: %d, p_len: %d\n", pos, ft_strlen(p->f.str));
    p->f.space ? p->f.str = ft_frsplitstr(&p->f.str, 1, " ") : 0;
    p->f.plus ? p->f.str = ft_frsplitstr(&p->f.str, 1 , "+") : 0;
    
}

void flags_zero(t_p *p)
{
    
}
