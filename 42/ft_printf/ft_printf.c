/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:15:32 by lkaba             #+#    #+#             */
/*   Updated: 2018/03/20 08:26:23 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_addnode(char *s1, int len, t_pfnode **head)
{
    t_pfnode *str;
    if (len == 0)
        return;
    str = (t_pfnode *)malloc(sizeof(t_pfnode));
    bzero(str, sizeof(t_pfnode));
    str->s = ft_strnew(len);
    ft_strncpy(str->s, s1, len);
    str->c = len;
    str->next = *head;
    *head = str;
}

int ft_nodeprint(t_pfnode **l_head)
{
    int cpt;
    t_pfnode *temp;
    ft_reverse(l_head);
    temp = *l_head;
    cpt = 0;
    while (temp != NULL)
    {
        cpt += temp->c;
        printf("%s", temp->s);
        temp = temp->next;
    }
    return (cpt);
}

int ft_printf(char *s, ...)
{
    int i;
    i = 0;
    t_pfnode *head;
    head = NULL;
    t_args flags;
    char *s2;
    char *s3;
    s3 = s2 = s; 
    va_list ap;
    va_start(ap, s);
    while (*s && !(i = 0))
    {
        while (s[i] && s[i] != '%')
            ++i;
        ft_addnode(s2, i, &head);
        if (s[i] == '%')
        {
            s = ft_parse1(s + i + 1, &flags);
            s2 = s;
            ft_conversion(s3, &ap, &flags, &head);
            //free(flags.str);
        }
        else
            s = s + i;
    }
    va_end(ap);
    return (ft_nodeprint(&head));
}