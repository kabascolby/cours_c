/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_setter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:19:38 by bpierce           #+#    #+#             */
/*   Updated: 2017/04/26 19:14:19 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/bsq.h"

int		x_pos(int index, int width)
{
	int i;
	int j;

	i = 0;
	j = 0;
	width -= 1;
	while (i < index)
	{
		if (j == width)
			j = -1;
		i++;
		j++;
	}
	return (j);
}

int		y_pos(int index, int width)
{
	int	i;
	int	j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	width -= 1;
	while (i < index)
	{
		if (j == width)
		{
			k += 1;
			j = 0;
		}
		i++;
		j++;
	}
	return (k);
}

t_cells	*create_array(char *s, char *map, int line_len, int num_of_lines)
{
	int		i;
	int		size;
	char	emptychar;
	t_cells	*cells;

	i = 0;
	emptychar = empty_char(s);
	size = line_len * num_of_lines;
	cells = malloc(sizeof(t_cells) * size);
	while (i < size)
	{
		cells[i].x = x_pos(i, line_len);
		cells[i].y = y_pos(i, line_len);
		if (map[i] == emptychar)
			cells[i].empty_val = 0;
		else
			cells[i].empty_val = 1;
		i++;
	}
	return (cells);
}
