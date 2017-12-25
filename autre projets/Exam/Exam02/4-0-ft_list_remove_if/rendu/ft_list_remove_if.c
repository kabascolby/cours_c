/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 18:58:43 by lkaba             #+#    #+#             */
/*   Updated: 2017/12/25 14:26:40 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *list;
	t_list *parent;
	t_list *tmp;

	list = *begin_list;
	parent = 0;
	tmp = 0;
	while (list)
	{
		tmp = list;
		if ((*cmp)(data_ref, list->data) == 0)
		{
			if (parent)
				parent->next = list->next;
			else
				*begin_list = list->next;
			free(list);	
		}
		else
		{
			parent = list;
		}
		list = tmp->next;
	}
}
