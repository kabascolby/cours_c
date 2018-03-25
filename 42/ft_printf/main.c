/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:15:49 by lkaba             #+#    #+#             */
/*   Updated: 2018/03/24 18:13:46 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int main()
{
	char  n;
    //printf("%s\n",ft_itoa(1001010));
    ft_printf("hello %s %-+8.5d%s\n", "kaba", 123, "lamine");
    printf("hello %s %-+8.5d%s\n", "kaba", 123, "lamine");
    //printf("% +15d\n", 1001010);
   // printf("Foo%ls", L"ljgss");
    //printf("%%%10%%10.3rud");
    //printf("%%%10%");
    //printf("%10%");
    //printf("%0 +020.177d\n", 100);
    //printf("%.30s\n", "abcdefg");
    //printf("%.30d\n", 1234567);
     //printf("%0o\n", 12789);
    /*printf("%x\n", 12789);
    printf("%-50dhello\n", 12789);
    printf("%+dhello\n",12789); */
	/* leaks
    while (1)
		n++; */
    return 0;
}
