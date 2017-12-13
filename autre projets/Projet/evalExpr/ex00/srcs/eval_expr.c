/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 22:16:31 by lamkaba2          #+#    #+#             */
/*   Updated: 2017/12/12 23:16:33 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/eval.h"

int		eval_expr(char *str)
{
	t_btree		*root;
	int			resultat;

	resultat = 0;
	str = ft_trim_space(str);
	root = btree_create_node(str);
	parse(root);
	resultat = calculate_parse(root);
	return (resultat);
}
