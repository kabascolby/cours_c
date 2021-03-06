/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 21:44:03 by lamkaba2          #+#    #+#             */
/*   Updated: 2017/12/12 23:16:33 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/eval.h"

int		calculate(int a, char *op, int b)
{
	if (op[0] == '+')
		return (a + b);
	if (op[0] == '-')
		return (a - b);
	if (op[0] == '*')
		return (a * b);
	if (op[0] == '/')
		return (a / b);
	if (op[0] == '%')
		return (a % b);
	return (0);
}

int		calculate_parse(t_btree *node)
{
	int a;
	int b;
	int res;

	if (node)
	{
		if (ft_str_is_numeric(node->value))
			return (atoi(node->value));
		else
		{
			a = calculate_parse(node->left);
			b = calculate_parse(node->right);
			res = calculate(a, node->value, b);
			return (res);
		}
	}
	return (0);
}
