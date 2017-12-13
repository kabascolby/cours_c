/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 00:37:31 by lamkaba2          #+#    #+#             */
/*   Updated: 2017/12/12 23:16:33 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/eval.h"

t_btree		*btree_create_node(void *value)
{
	t_btree	*tree;

	tree = (t_btree*)malloc(sizeof(t_btree));
	if (tree)
	{
		tree->left = 0;
		tree->right = 0;
		tree->value = value;
	}
	return (tree);
}
