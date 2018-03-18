/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:08:55 by lkaba             #+#    #+#             */
/*   Updated: 2018/03/16 06:14:09 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* reverse a linked list */
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
    
    //return("fin");
}