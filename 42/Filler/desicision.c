/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desicision.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:05:13 by lkaba             #+#    #+#             */
/*   Updated: 2018/05/03 20:52:45 by lkaba            ###   ########.fr       */
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
	while (++i < b->p_h)
	{
		j = -1;
		while (++j < b->p_w)
			if (b->piece[i][j] == '*')
			{
				first = b->cur_i + (i - b->p_hi) + (b->p_hi - b->cur_pi);
				second = b->cur_j + (j - b->p_hj) + (b->p_hj - b->cur_pj);
				if (index_fail(b, first, second))
					return (INT16_MAX);
				if (b->fm[first][second] == -2)
					return (INT16_MAX);
				if (b->fm[first][second] == -1)
					if (!(count = count ^ 1))
						return (INT16_MAX);
				sum += b->fm[b->cur_i + (i - b->p_hi) + (b->p_hi - b->cur_pi)][b->cur_j + (j - b->p_hj) + (b->p_hj - b->cur_pj)];
				//dprintf(b->fd, "sum = %d | (i = %d, j = %d)\nfmi: %d, fmj: %d\n", sum, (i - b->p_hi) , (j - b->p_hj), b->fm_i, b->fm_j);		
			}
	}
	//dprintf(b->fd, "--------\n");
	return (sum);
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
	while (++i < b->p_h)
	{
		j = -1;
		while (++j < b->p_w)
			if (b->piece[i][j] == '*')
			{
				b->cur_pi = i;
				b->cur_pj = j;
				temp = sumpath(b);
				if ((sum > temp) && temp)
				{
					sum = temp;
					b->k = i;
					b->l = j;
					//dprintf(b->fd, "(coord_i = %d, coord_j = %d)\n", i, j);
					
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
	b->sum = INT16_MAX;
	i = -1;
	//write(1, "19 32\n", 6);
	while (++i < b->h)
	{
		//dprintf(b->fd, "%d\n", i);
		j = -1;
		while (++j < b->w)
			if (b->fm[i][j] == -1)
			{
				b->cur_i = i;
				b->cur_j = j;
				temp = bestpos_piece(b);
				if ((b->sum > temp) && (temp))
				{
					b->sum = temp;
					b->fm_i = i;
					b->fm_j = j;
					
					dprintf(b->fd, "lowest sum = %d\n(fm_i = %d, fm_j = %d)\n", b->sum, b->fm_i, b->fm_j);
					dprintf(b->fd, "(head_i = %d, head_j = %d)\n", b->p_hi, b->p_hj);
				}	
			}
			
	}
	//write(1, "19 32\n", 6);
	//printf("%d %d\n",19, 32);
	ft_putnbr(b->fm_i - b->k);
	write(1, " ", 1);
	ft_putnbr(b->fm_j - b->l);
	write(1, "\n", 1);
	//dprintf(b->fd, "\n y = %d , x = %d\n", (b->fm_i - b->k), (b->fm_j - b->l));

}