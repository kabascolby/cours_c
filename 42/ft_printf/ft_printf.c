/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:15:32 by lkaba             #+#    #+#             */
/*   Updated: 2018/03/16 04:31:45 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
    
void ft_addnode(char *s1, int len, t_pfnode **head)
{
    t_pfnode *str;
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
    while(temp != NULL)
    {
        cpt += temp->c;
        printf("%s", temp->s);
        temp = temp->next;
    }
    return(cpt);
}

int ft_printf(char *s, ...)
{
    int i;
    i = 0;
    t_pfnode     *head;
    head = NULL;
    t_args flags;

    char *s2;
    s2 = s;
    while (*s)
    {
        ((*s == '%' && *(s + 1) == '%' ) ? ((s = (s + 2)),s2 = s, ft_addnode("%", 1, &head)): NULL);
        if(*s != '%')
            i++;
        if (!ft_strlen(s) || *s == '%')
        {
            if (*s == '%')
            {
                s++;
                s = ft_parse1(s, &flags);
            } 
            ft_addnode(s2, i, &head);
            i = 1;
            s2 = s;
            
        }
        s++;
    }
    return(ft_nodeprint(&head));
}