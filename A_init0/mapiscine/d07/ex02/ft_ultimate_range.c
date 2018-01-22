/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 10:33:14 by lkaba             #+#    #+#             */
/*   Updated: 2018/01/18 10:33:18 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (!(*range = (int*)malloc(sizeof(int) * (max - min))))
		return (0);
	i = -1;
	while (min < max)
		(*range)[++i] = min++;
	return (i + 1);
}
