/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algor_the_mighty.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 09:46:56 by bpierce           #+#    #+#             */
/*   Updated: 2017/04/26 19:03:25 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/bsq.h"

int		size_is_okay(t_cells *cells, t_best mb, int line_len, int num_of_lines)
{
	if (cells[mb.c_cell].x + (mb.c_size - 1) >= line_len)
		return (2);
	else if (cells[mb.c_cell].y + (mb.c_size - 1) >= num_of_lines)
		return (3);
	return (1);
}

int		box_checker(t_cells *cells, int c_cell, int c_size, int line_len)
{
	int		i;
	int		j;
	t_cells	*cells2;

	i = 0;
	j = 0;
	cells2 = &cells[c_cell];
	while (i < c_size)
	{
		while (j < c_size)
		{
			if (cells2[j].empty_val == 1)
				return (0);
			j++;
		}
		cells2 = &cells2[line_len];
		i++;
		j = 0;
	}
	return (1);
}

int		to_next_line(int c_cell, int line_len)
{
	int		temp;

	temp = line_len;
	while (line_len < c_cell)
		line_len += temp;
	return (line_len);
}

t_best	algor(t_cells *cells, t_best mybox, int line_len, int num_of_lines)
{
	int		size_is_fine;

	while (mybox.c_cell < (line_len * num_of_lines))
	{
		if (box_checker(cells, mybox.c_cell, mybox.c_size, line_len) == 1)
		{
			size_is_fine = size_is_okay(cells, mybox, line_len, num_of_lines);
			if (size_is_fine == 1 && mybox.best_size < mybox.c_size)
			{
				mybox.best_cell = mybox.c_cell;
				mybox.best_size = mybox.c_size;
				mybox.c_size++;
			}
			else if (size_is_fine == 2)
				mybox.c_cell = to_next_line(mybox.c_cell, line_len);
			else if (size_is_fine == 3)
				return (mybox);
			else
				mybox.c_cell += 1;
		}
		else
			mybox.c_cell += 1;
	}
	return (mybox);
}
