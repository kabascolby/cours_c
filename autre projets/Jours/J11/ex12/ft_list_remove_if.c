/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 06:03:12 by lamkaba2          #+#    #+#             */
/*   Updated: 2017/12/12 23:16:32 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *list_ptr;
	t_list *list_parent;
	t_list *tmp;

	list_ptr = *begin_list;
	list_parent = 0;
	while (list_ptr != 0)
	{
		tmp = list_ptr;
		if ((*cmp)(list_ptr->data, data_ref) == 0)
		{
			if (list_parent != 0)
				list_parent->next = list_ptr->next;
			free(list_ptr);
		}
		list_parent = list_ptr;
		list_ptr = tmp->next;
	}
}
