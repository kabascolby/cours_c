/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desicision.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:05:13 by lkaba             #+#    #+#             */
/*   Updated: 2018/04/30 14:32:13 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** adjusted coordinate
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
				sum += (b->fm[(y - b->h_y) + i][(x - b->h_x) + j]);
	}
	dprintf(b->fd, "sum = %d\n", sum);
	return (sum);
}

void bestfit(t_b *b)
{
	int16_t count[4];
	int16_t temp;
	int16_t i;
	int16_t j;
	int16_t k;
	int16_t l;

	//*init_count(count, 4, -1);
	b->sum = INT_MAX;
	count[0] = -1;
	while (++count[0] < b->h)
	{
		count[1] = -1;
		while (++count[1] < b->w)
		{
			if (b->fm[count[0]][count[1]] == -1)
			{
				dprintf(b->fd, "hello\n");
				temp = 0;
				count[2] = -1;
				while (++count[2] < b->p_h)
				{
					count[3] = -1;
					while (++count[3] < b->p_w)
					{
						if (b->piece[count[2]][count[3]] == '*')
						{	
							temp = sumpath(b, count[0], count[1]);
							if((b->sum > temp) && (temp))
							{
								b->sum = temp;
								i = count[0];
								j = count[1];
								k = count[2];
								l = count[3];
								dprintf(b->fd, "lowest sum = %d\n", b->sum);								
							}
						}
					}
				}
			}
		}
	}
	dprintf(b->fd, "\n y = %d , x = %d\n",((k - b->h_y) + i), ((l - b->h_x) + j));
	
	ft_putnbr((k - b->h_y) + i);
	ft_putchar(' ');
	ft_putnbr((l - b->h_x) + j);
	ft_putchar('\n');

	
							
	/* dprintf(b->fd, "b->sum = %d\n", b->sum);
	ft_putnbr_fd((coord[2] - b->h_x) + coord[0], b->fd);
	ft_putstr_fd(" ", b->fd);
	ft_putnbr_fd((coord[3] - b->h_y) + coord[1], b->fd);
	
	b->sum != -1 ? ft_putnbr((coord[2] + b->h_x) + coord[0]) : 0;
	ft_putchar(' ');
	b->sum != -1 ? ft_putnbr((coord[3] + b->h_y) + coord[1]) : 0;
	ft_putchar('\n'); */
}