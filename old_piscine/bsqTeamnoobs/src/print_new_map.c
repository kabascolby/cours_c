/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_new_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 13:35:32 by bpierce           #+#    #+#             */
/*   Updated: 2017/04/26 19:12:55 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/bsq.h"

void	printer(char *map, int line_len)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (map[i])
	{
		if (i == (line_len * j))
		{
			ft_putchar('\n');
			j++;
		}
		ft_putchar(map[i]);
		i++;
	}
}

void	print_new_map(char *map, t_best mybox, int line_len, char full_char)
{
	int		k;
	int		l;
	char	*map2;

	k = 0;
	l = 0;
	map2 = &map[mybox.best_cell];
	while (k < mybox.best_size)
	{
		while (l < mybox.best_size)
		{
			map2[l] = full_char;
			l++;
		}
		map2 = &map2[line_len];
		l = 0;
		k++;
	}
	printer(map, line_len);
}
