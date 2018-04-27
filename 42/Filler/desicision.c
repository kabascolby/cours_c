/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desicision.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:05:13 by lkaba             #+#    #+#             */
/*   Updated: 2018/04/26 19:26:59 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** adjusted cordinat
*/
int16_t sumpath(t_b *b, int i, int j)
{
	int sum;
	int16_t x;
	int16_t y;
	y = -1;
	sum = 0;
	while (++y < b->p_h)
	{
		x = -1;
		while (++x < b->p_w)
			if (b->piece[y][x] == '*')
			{
				dprintf(b->fd, "%d | %d, %d | %d\n", b->h_x, i, b->h_y, j);
				sum += b->fm[(y - b->h_y) + i][(x - b->h_x) + j];
			}
	}
	return (sum);
}
void init_coord(int16_t coord[4])
{
	int i = -1;
	while (++i < 4)
		coord[i] = 0;
}
int compare_sums(int16_t temp, int16_t sum, int16_t coord[4], uint16_t count[4])
{
	if (temp < sum)
	{
		coord[0] = count[0];
		coord[1] = count[1];
		coord[2] = count[2];
		coord[3] = count[3];
		return temp;
	}
	return sum;
}
void bestfit(t_b *b)
{
	uint16_t count[4];
	int16_t temp;
	int16_t coord[4];

	init_coord(coord);
	count[0] = -1;
	b->sum = -1;
	while (++count[0] < b->h)
	{
		count[1] = -1;
		while (++count[1] < b->w)
		{
			if (b->fm[count[0]][count[1]] == -1)
			{
				count[2] = -1;
				while (++count[2] < b->p_h)
				{
					count[3] = -1;
					while (++count[3] < b->p_w)
						if (b->piece[count[2]][count[3]] == '*')
						{
							temp = sumpath(b, count[0], count[1]);
							dprintf(b->fd, "temp = %d\n", temp);
							if (b->sum > 0)
								b->sum = compare_sums(temp, b->sum, coord, count);
							else
							{
								coord[0] = count[0];
								coord[1] = count[1];
								coord[2] = count[2];
								coord[3] = count[3];
								b->sum = temp;
							}
						}
				}
			}
		}
	}
	dprintf(b->fd, "b->sum = %d\n", b->sum);
	//dprintf(b->fd, "coord1 = %d\n", (coord[2] + b->h_x) + coord[0]);
	//dprintf(b->fd, "coord2 = %d\n", (coord[3] + b->h_y) + coord[1]);
	ft_putnbr_fd(b->fd, (coord[2] - b->h_x) + coord[0]);
	ft_putstr_fd(" ", b->fd);
	
	ft_putnbr_fd(b->fd, (coord[3] - b->h_y) + coord[1]);
	b->sum != -1 ? ft_putnbr((coord[2] + b->h_x) + coord[0]) : 0;
	ft_putchar(' ');
	b->sum != -1 ? ft_putnbr((coord[3] + b->h_y) + coord[1]) : 0;
	ft_putchar('\n');
}