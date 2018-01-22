/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 19:31:28 by lkaba             #+#    #+#             */
/*   Updated: 2018/01/17 21:07:34 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int len;
	int i;
	int *tab;

	if (min >= max)
		return (0);
	else
	{
		i = 0;
		len = max - min - 1;
		tab = (int *)malloc((*tab) * len);
		while (min < max)
		{
			tab[i] = min;
			min++;
			i++;
		}
	}
	return (tab);
}
