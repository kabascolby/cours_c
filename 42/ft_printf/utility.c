/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:08:55 by lkaba             #+#    #+#             */
/*   Updated: 2018/04/02 19:52:38 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void ft_addnode(t_p *p, char *s1, size_t len)
{
    char    *tmp;

    t_pfnode *str;
    if ((s1 && len) || (!p->f.types.c && CE_2(p->f.type, 'c', 'C')))
    {
        str = (t_pfnode *)malloc(sizeof(t_pfnode));
        bzero(str, sizeof(t_pfnode));
        if (!p->f.types.c && CE_2(p->f.type, 'c', 'C'))
        {
            tmp = ft_strnew(len + 1);
            if (!p->f.min)
                ft_strncpy(tmp, s1, len);
            else
                ft_strncpy(&tmp[1], s1, len);
            ++len;
            free(s1);
            s1 = tmp;
        }
        str->s = s1;
        str->c = len;
        str->next = p->head;
        p->head = str;
    }
}

int ft_nodeprint(t_p *p)
{
    int cpt;
    t_pfnode *temp;
    ft_reverse(p);
    cpt = 0;
    while (p->head)
    {
        temp = p->head;
        //temp->c += (temp->s && p->f.types.c == 0 && p->f.type == 'c') ? 1 : 0;
        cpt += temp->c;
        write(1, temp->s, temp->c);
        p->head = p->head->next;
        free(temp->s);
        free(temp);
    }
    return (cpt);
}

void ft_reverse(t_p *p)
{
    t_pfnode *prev;
    t_pfnode *cur;
    t_pfnode *next;

    prev = NULL;
    cur = p->head;
    if(!cur->next)
        return ;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    p->head = prev;
}

char *ft_frsplitstr(char **s, int j, char *s2)
{
    int i;
    int k;

    k = 0;
    i = 0;
    char *str;
    if (!s2)
        return (*s);
    if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(*s) + ft_strlen(s2)) + 1)))
        return (0);
    while (i < j - 1)
        str[i++] = (*s)[k++];
    while (*s2)
        str[i++] = *(s2++);
    while ((*s)[k])
        str[i++] = (*s)[k++];
    str[i] = '\0';
    ft_strdel(s);
    free(*s);
    return (str);
}
char *ft_uitoabase(uintmax_t val, int base, int opt)
{
    static char buf[32] = "0";
    char set[32] = NUMBERSET;
    int i;
    int o;

    i = 30;
    o = 0;
    if (opt != 0)
        o = 16;
    if (val == 0)
        return (ft_strcpy(buf, "0\0"));
    while (val > 0 && i > 0)
    {
        buf[i] = set[(val % base) + o];
        val = val / base;
        --i;
    }
    return (buf + i + 1);
}