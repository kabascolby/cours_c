/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_intit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:07:49 by lkaba             #+#    #+#             */
/*   Updated: 2018/05/12 16:24:46 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	board_set(t_b *b)
{
	int16_t	i;

	if (b->toggle == 0)
		return ;
	get_next_line(0, &b->buff);
	ft_strdel(&b->buff);
	get_next_line(0, &b->buff);
	ft_strdel(&b->buff);
	i = -1;
	while (++i < b->h)
	{
		get_next_line(0, &b->buff);
		free(MAP[i] - 4);
		MAP[i] = b->buff + 4;
	}
}

/*
** ft_position give a negative 2 of all the position of my enemie
** negative one to all my position. And zero to all other position.
** In that way I can calculateall the possibility I have to reach my enemie.
*/

void	ft_position(t_b *b)
{
	int16_t	i;
	int16_t	j;
	int16_t	k;

	i = -1;
	while (++i < b->h)
	{
		j = -1;
		while (++j < b->w)
		{
			MAP[i][j] = MAP[i][j] == '.' ? 0 : MAP[i][j];
			if (CE_2(MAP[i][j], 'X', 'O'))
			{
				MAP[i][j] == 'O' && b->p == 1 ? MAP[i][j] = -1 : 0;
				MAP[i][j] == 'O' && b->p == 2 ? MAP[i][j] = -2 : 0;
				MAP[i][j] == 'X' && b->p == 1 ? MAP[i][j] = -2 : 0;
				MAP[i][j] == 'X' && b->p == 2 ? MAP[i][j] = -1 : 0;
			}
		}
	}
	fill_board(b, 0, -2, 1);
	k = 0;
	while (++k < b->w)
		fill_board(b, 0, k, k + 1);
}

void	fill_board(t_b *b, int16_t l, int16_t n, int16_t m)
{
	int16_t	i;
	int16_t	j;

	i = -1;
	while (++i < b->h)
	{
		j = -1;
		while (++j < b->w)
			if (MAP[i][j] == n)
			{
				(j + 1 < b->w) && (MAP[i][j + 1] == l) ? MAP[i][j + 1] = m : 0;
				(j - 1 >= 0) && (MAP[i][j - 1] == l) ? MAP[i][j - 1] = m : 0;
				((i + 1 < b->h) && (MAP[i + 1][j] == l)) ?
					MAP[i + 1][j] = m : 0;
				((i - 1 >= 0) && (MAP[i - 1][j] == l)) ? MAP[i - 1][j] = m : 0;
				((i + 1 < b->h) && (j - 1 >= 0) && (MAP[i + 1][j - 1] == l)) ?
					MAP[i + 1][j - 1] = m : 0;
				((i - 1 >= 0) && (j + 1 < b->w) && (MAP[i - 1][j + 1] == l)) ?
					MAP[i - 1][j + 1] = m : 0;
				((i + 1 < b->h) && (j + 1 < b->w) && (MAP[i + 1][j + 1] == l)) ?
					MAP[i + 1][j + 1] = m : 0;
				((i - 1 >= 0) && (j - 1 >= 0) && (MAP[i - 1][j - 1] == l)) ?
					MAP[i - 1][j - 1] = m : 0;
			}
	}
}

void	reset_value(t_b *b)
{
	b->fm_i = 0;
	b->fm_j = 0;
	b->k = 0;
	b->l = 0;
	b->best_k = 0;
	b->best_l = 0;
	b->sum = INT16_MAX;
}

int8_t	index_fail(t_b *b, int16_t x, int16_t y)
{
	return (y < 0 || y > b->w - 1 || x < 0 || x > b->h - 1);
}
