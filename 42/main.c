/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:15:49 by lkaba             #+#    #+#             */
/*   Updated: 2018/04/03 19:42:09 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <stdio.h>
#include <limits.h>

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

int main()
{
    unsigned long l;
    //unsigned short sh = USHRT_MAX;
    printf("\n%d", ft_printf("%#p", 0));
  // printf("\n%d", ft_printf("%3c", 0));
    return 0;
}
