/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desicision.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:05:13 by lkaba             #+#    #+#             */
/*   Updated: 2018/05/05 20:25:46 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** adjusted coordinate
*/
int8_t index_fail(t_b *b, int16_t x, int16_t y)
{
	return (y < 0 || y > b->w -1 || x < 0 || x > b->h -1);
}
uint16_t	sumpath(t_b *b)
{
	int16_t		i;
	int16_t		j;
	int16_t		sum;
	int16_t		first;
	int16_t		second;
	int8_t		count;	

	sum = 0;
	i = -1;
	count = 0;
	//dprintf(b->fd, "-\n");
	while (++i < b->p_h)
	{
		j = -1;
		while (++j < b->p_w)
		{
			if (b->piece[i][j] == '*')
			{
				first = b->cur_i + (i - b->p_hi) + (b->p_hi - b->cur_pi);
				second = b->cur_j + (j - b->p_hj) + (b->p_hj - b->cur_pj);
				//dprintf(b->fd, "f: %5d  s: %5d\n", first, second);
				if (index_fail(b, first, second))
					return (INT16_MAX);
				if (b->fm[first][second] == -2)
					return (INT16_MAX);
				if (b->fm[first][second] == -1)
				{
					count++;
					if (count > 1)
						return (INT16_MAX);
				}
				sum += b->fm[b->cur_i + (i - b->p_hi) + (b->p_hi - b->cur_pi)][b->cur_j + (j - b->p_hj) + (b->p_hj - b->cur_pj)];
				////dprintf(b->fd, "sum = %d | (i = %d, j = %d)\nfmi: %d, fmj: %d\n", sum, (i - b->p_hi) , (j - b->p_hj), b->fm_i, b->fm_j);		
			}
		}
	}
	////dprintf(b->fd, "--------\n");
	return (count == 1 ? sum : INT16_MAX);
}

uint16_t	bestpos_piece(t_b *b)
{	
	int16_t		i;
	int16_t		j;
	int16_t		sum;
	int16_t		temp;

	sum = INT16_MAX;
	temp = 0;
	i = -1;
	//dprintf(b->fd, "CHOOSING BEST SUM\n");
	while (++i < b->p_h)
	{
		j = -1;
		while (++j < b->p_w)
		{
			if (b->piece[i][j] == '*')
			{
				b->cur_pi = i;
				b->cur_pj = j;
				temp = sumpath(b);
				if (temp < sum)
				{
					sum = temp;
					b->k = i;
					b->l = j;
					//dprintf(b->fd, "--> new k & l: %d, %d\n", b->k, b->l);
					////dprintf(b->fd, "(coord_i = %d, coord_j = %d)\n", i, j);
				}
			}
		}
	}
	//dprintf(b->fd, "/SUM\n\n");
	return (sum);
}

void	bestpos_fm(t_b *b)
{
	int16_t	i;
	int16_t	j;
	int16_t	temp;

	reset_value(b);
	temp = 0;
	
	i = -1;
	while (++i < b->h)
	{
		j = -1;
		while (++j < b->w)
		{
			//dprintf(b->fd, "Finding best for i: %d,j: %d\n", i, j);
			if (b->fm[i][j] == -1)
			{
				b->cur_i = i;
				b->cur_j = j;
				//dprintf(b->fd, "Finding best for i: %d,j: %d\n", i, j);
				temp = bestpos_piece(b);
				if (temp < b->sum)
				{
					b->sum = temp;
					b->fm_i = i;
					b->fm_j = j;
					b->best_k = b->k;
					b->best_l = b->l;
					//dprintf(b->fd, "NEW lowest sum = %d\nFMI: %d, FMJ: %d\nbk: %d, bl: %d\n\n", b->sum, b->fm_i, b->fm_j, b->k, b->l);
				}
			}
		}
	}
	//dprintf(b->fd, "(head_i = %d, head_j = %d)\n", b->p_hi, b->p_hj);
	//dprintf(b->fd, "piece location (i = %d, j = %d)\n---------------------------------------------------------------------------\n", b->fm_i - b->best_k, b->fm_j - b->best_l);
	//b->sum != INT16_MAX ? ft_putnbr(b->fm_i - b->k) : write(1, "0", 1);
	b->sum != INT16_MAX ? ft_putnbr(b->fm_i - b->best_k) : write(1, "0", 1);
	write(1, " ", 1);
	//b->sum != INT16_MAX ? ft_putnbr(b->fm_j - b->l) : write(1, "0", 1);
	b->sum != INT16_MAX ? ft_putnbr(b->fm_j - b->best_l): write(1, "0", 1);
	write(1, "\n", 1);
}
void reset_value(t_b *b)
{
	b->fm_i = 0;
	b->fm_j = 0;
	b->k = 0;
	b->l = 0;
	b->best_k = 0;
	b->best_l = 0;
	b->sum = INT16_MAX;
}