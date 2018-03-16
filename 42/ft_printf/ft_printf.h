/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:15:44 by lkaba             #+#    #+#             */
/*   Updated: 2018/03/15 18:45:03 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h> // REMOVE LATER NOT ALLOWED

# define NUM(c) ((c) - '0')
# define CE_(a, b) ((a) == (b))
# define CE_2(a, b, c) (CE_(a, b) || CE_(a, c))
# define CE_3(a, b, c, d) (CE_(a, b) || CE_(a, c) || CE_(a, d))
# define CE_4(a, b, c, d, e) (CE_2(a, b, c) || CE_2(a, d, e))
# define CE_5(a, b, c, d, e, f) (CE_3(a, b, c, d) || CE_2(a, e, f))

typedef struct s_pfnode
{
    int             c;
    char            *s;
    struct s_pfnode *next;
}               t_pfnode;

typedef struct s_args
{
	u_int8_t min:1;
	u_int8_t plus:1;
	u_int8_t space:1;
	u_int8_t hash:1;
	u_int8_t zero:1;
	u_int8_t start:1;
	u_int8_t prec:1;
	unsigned int field_w;
	unsigned int precis;
	u_int32_t length;
	char convers;
}				t_args;

enum length{h = 1, hh, l, ll, j, z};
void ft_addnode(char *s1, int len, t_pfnode **head);
int ft_printf(char *s, ...);
int ft_nodeprint(t_pfnode **l_head);
void ft_reverse(t_pfnode **h);
char *ft_parse1(char *s, t_args *flags);
char *ft_parse2(char *s, t_args *flags);
char *ft_struct_check(t_args *flags);

#endif