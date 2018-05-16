/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:05:13 by lkaba             #+#    #+#             */
/*   Updated: 2018/05/12 16:32:54 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** adjusted coordinate
*/

uint16_t		sumpath(t_b *b)
{
	int16_t		total;
	int16_t		first;
	int16_t		second;
	int8_t		count;

	total = 0;
	b->d_i = -1;
	count = 0;
	while (++b->d_i < b->p_h && (b->d_j = -1))
		while (++b->d_j < b->p_w)
			if (b->piece[b->d_i][b->d_j] == '*')
			{
				first = b->cur_i + (b->d_i - H_I) + (H_I - b->cur_pi);
				second = b->cur_j + (b->d_j - H_J) + (H_J - b->cur_pj);
				if (index_fail(b, first, second) || b->fm[first][second] == -2)
					return (INT16_MAX);
				if (b->fm[first][second] == -1)
				{
					if (count++ > 1)
						return (INT16_MAX);
				}
				total += MAP[b->cur_i + (b->d_i - H_I) + (H_I - b->cur_pi)]
				[b->cur_j + (b->d_j - H_J) + (H_J - b->cur_pj)];
			}
	return (count == 1 ? total : INT16_MAX);
}

uint16_t		best_piece(t_b *b)
{
	int16_t		i;
	int16_t		j;
	int16_t		total;
	int16_t		temp;

	total = INT16_MAX;
	temp = 0;
	i = -1;
	while (++i < b->p_h && (j = -1))
		while (++j < b->p_w)
			if (b->piece[i][j] == '*')
			{
				b->cur_pi = i;
				b->cur_pj = j;
				temp = sumpath(b);
				if (temp < total)
				{
					total = temp;
					b->k = i;
					b->l = j;
				}
			}
	return (total);
}

uint16_t		best_piece2(t_b *b)
{
	int16_t		i;
	int16_t		j;
	int16_t		total;
	int16_t		temp;

	total = INT16_MAX;
	temp = 0;
	i = b->p_h;
	while (--i >= 0 && (j = b->p_w))
		while (--j >= 0)
			if (b->piece[i][j] == '*')
			{
				b->cur_pi = i;
				b->cur_pj = j;
				temp = sumpath(b);
				if (temp < total)
				{
					total = temp;
					b->k = i;
					b->l = j;
				}
			}
	return (total);
}

void			bestpos_map(t_b *b)
{
	int16_t		i;
	int16_t		j;
	int16_t		temp;

	temp = 0;
	i = -1;
	reset_value(b);
	while (++i < b->h && (j = -1))
		while (++j < b->w)
			if (b->fm[i][j] == -1)
			{
				b->cur_i = i;
				b->cur_j = j;
				temp = (b->p == 2 && b->h == 15) ?
					best_piece2(b) : best_piece(b);
				if (temp < b->sum)
				{
					b->sum = temp;
					b->fm_i = i;
					b->fm_j = j;
					b->best_k = b->k;
					b->best_l = b->l;
				}
			}
}
