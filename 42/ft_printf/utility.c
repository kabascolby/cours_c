/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:08:55 by lkaba             #+#    #+#             */
/*   Updated: 2018/03/24 02:01:04 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* reverse a linked list */
void ft_addnode(char *s1, int len, t_pfnode **head)
{
    t_pfnode *str;

    if (s1 && len)
    {
        str = (t_pfnode *)malloc(sizeof(t_pfnode));
        bzero(str, sizeof(t_pfnode));
        str->s = ft_strnew(len);
        ft_strncpy(str->s, s1, len);
        str->c = len;
        str->next = *head;
        *head = str;
    }
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
void ft_reverse(t_pfnode **h)
{
  t_pfnode *prev;
  t_pfnode *cur;
  t_pfnode *next;

  prev = NULL;
  cur = *h;
     while(cur != NULL)
  {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  *h = prev;
}

char *ft_frsplitstr(char **s, int j, char *s2)
{
    int  i;
    int k;
  
    
    k = 0;
    i = 0;
    char *str;
    if(!s2)
        return(*s);
     if(!(str = (char *)malloc(sizeof(char) * (ft_strlen(*s) + ft_strlen(s2)) + 1)))
        return(0);
    while(i < j -1)
        str[i++] = (*s)[k++];
    printf("%c\n", (*s)[k]);
        
    while(*s2)
        str[i++] = *(s2++);
    while((*s)[k])
        str[i++] = (*s)[k++];
    str[i] = '\0';
    ft_strdel(s);
    //free(*s);
    return(str);
}

void ft_struct_check(t_args *flags)
{
    printf("plus: %d\n", flags->plus);
    printf("min: %d\n", flags->min);
    printf("space: %d\n", flags->space);
    printf("hash: %d\n", flags->hash);
    printf("zero: %d\n", flags->zero);
    printf("prec: %d\n", flags->prec);
    printf("precis: %d\n", flags->precis);
    printf("field_w: %d\n", flags->field_w);
    printf("length: %d\n", flags->length);
    printf("type: %c\n", flags->type);
}