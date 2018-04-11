/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:15:49 by lkaba             #+#    #+#             */
/*   Updated: 2018/04/06 17:10:18 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
    unsigned long l;
    //unsigned short sh = USHRT_MAX;
    printf("\n%d", ft_printf("{%30S}", L"我是一只猫。"));
  // printf("\n%d", ft_printf("%3c", 0));
    return 0;
}
