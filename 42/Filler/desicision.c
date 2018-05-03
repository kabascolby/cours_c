/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desicision.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:05:13 by lkaba             #+#    #+#             */
/*   Updated: 2018/05/02 18:27:32 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** adjusted coordinate
*/

uint16_t	sumpath(t_b *b)
{
	int16_t		i;
	int16_t		j;
	uint16_t	sum;

	sum = 0;
	i = -1;
	while (++i < b->p_h)
	{
		j = -1;
		while (++j < b->p_w)
		{
			if (b->piece[i][j] == '*')
			{
				sum += b->fm[i - b->fm_i][j - b->fm_j];
				dprintf(b->fd, "sum = %d | (i = %d, j = %d)\n", sum, (i - b->fm_i),(j - b->fm_j));		
			}
		}
	}
	return (sum);
}

uint16_t	bestpos_piece(t_b *b)
{
	int16_t		i;
	int16_t		j;
	uint16_t	sum;
	uint16_t	temp;

	sum = 65535;
	temp = 0;
	i = -1;
	while (++i < b->p_h)
	{
		j = -1;
		while (++j < b->p_w)
			if (b->piece[i][j] == '*')
			{
				temp += sumpath(b);
				if ((sum > temp) && temp)
				{
					sum = temp;
					b->k = i;
					b->l = j;
				}
			}
	}
	return (sum);
}

void	bestpos_fm(t_b *b)
{
	int16_t	i;
	int16_t	j;
	int16_t	temp;
	temp = 0;
	b->sum = 65535;
	i = -1;
	while (++i < b->h)
	{
		j = -1;
		while (++j < b->w)
			if (b->fm[i][j] == -1)
			{
				temp = bestpos_piece(b);
				if ((b->sum > temp) && (temp))
				{
					b->sum = temp;
					b->fm_i = i;
					b->fm_j = j;
					
					dprintf(b->fd, "lowest sum = %d\n(fm_i = %d, fm_j = %d)\n", b->sum, b->fm_i, b->fm_j);
					dprintf(b->fd, "(head_i = %d, head_j = %d)\n", b->h_x, b->h_y);
				}
			}
	}
	// dprintf(b->fd, "\n y = %d , x = %d\n", ((b->k - b->h_y) + b->i), ((b->l - b->h_x) + b->j));

	// ft_putnbr((b->k - b->h_y) + b->i);
	// ft_putchar(' ');
	// ft_putnbr((b->l - b->h_x) + b->j);
	// ft_putchar('\n');
}