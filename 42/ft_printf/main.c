/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:15:49 by lkaba             #+#    #+#             */
/*   Updated: 2018/03/27 03:18:37 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int main()
{
	char  n;
    //ft_printf("hello %s % -8d%s\n", "kaba", 123, "lamine");
    //ft_printf("hello %s %10%%-8stest\n","kaba", "lamine");
    ft_printf("ws1%-12.3S ws2\n", L"whidestring");
    printf("ws1%-12.3S ws2\n", L"whidestring");
    //ft_printf("wc%lc\n", 'c');
    //printf("wc%C\n", 'k');
    //ft_printf("hello %s %10%%-8stest\n","kaba", "lamine");
    //printf("hello %s %10%%-8stest\n","kaba", "lamine");
    //ft_printf("hello %s % 8.9d%s\n", "kaba", 123, "lamine");
    //printf("hello %s % 8.9d%s\n", "kaba", 123, "lamine");
    //printf("hello %s % 8.9d%s\n", "kaba", 123, "lamine");
    
    return 0;
}
