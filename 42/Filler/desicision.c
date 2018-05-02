/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desicision.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:05:13 by lkaba             #+#    #+#             */
/*   Updated: 2018/04/30 23:31:33 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** adjusted coordinate
*/

void bestpos_piece(t_b *b)
{
	int16_t i;
	int16_t j;
	int16_t sum;
	
	sum = 0;
	i = -1;
	while (++i < b->p_h)
	{
		j = -1;
		while (++j < b->p_w)
			if (b->piece[i][j] == '*')
			{
				b->k = i;
				b->l = j;
				sum += sumpath(b);
			}
	}
}
int16_t sumpath(t_b *b)
{
	int16_t i;
	int16_t j;
	int sum;
	
	i = -1;
	while(i < b->p_h)
	{
		j = -1;
		while(j < b->p_w)
		if (b->piece[i][j] == '*')
			{
			}
	}

	return (sum);
}

void bestpos_fm(t_b *b)
{
	uint16_t	i;
	uint16_t	j;
	int16_t		temp;
	b->sum = 14000;
	i = -1;
	while (++i < b->h)
	{
		j = -1;
		while (++j < b->w)
			if (b->fm[i][j] == -1)
			{
				temp = sumpath(b, i, j);
				if((b->sum > temp) && (temp))
				{
					b->sum = temp;
					b->i = i;
					b->j = j;
					dprintf(b->fd, "lowest sum = %d\n", b->sum);								
				}
			}
	}
						
	dprintf(b->fd, "\n y = %d , x = %d\n",((b->k - b->h_y) + b->i), ((b->l - b->h_x) + b->j));
	
	ft_putnbr((b->k - b->h_y) + b->i);
	ft_putchar(' ');
	ft_putnbr((b->l - b->h_x) + b->j);
	ft_putchar('\n');
}