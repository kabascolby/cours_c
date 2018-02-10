/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 02:28:58 by tadey             #+#    #+#             */
/*   Updated: 2018/02/05 20:26:57 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		put(t_tetris *alst, t_board *board, int row, int col)
{
	int		i;
	int		x;
	int		y;

	i = 5 * alst->min_row + alst->min_col - 1;
	while (++i < 20)
		if (alst->shape[i / 5][i % 5] == '#')
		{
			x = (i / 5) - alst->min_row;
			y = (i % 5) - alst->min_col;
			board->map[row + x][col + y] = alst->name;
		}
}

static void		delete(t_tetris *alst, t_board *board, int row, int col)
{
	int		i;
	int		x;
	int		y;

	i = 5 * alst->min_row + alst->min_col - 1;
	while (++i < 20)
		if (alst->shape[i / 5][i % 5] == '#')
		{
			x = (i / 5) - alst->min_row;
			y = (i % 5) - alst->min_col;
			board->map[row + x][col + y] = '.';
		}
}

static	int		check(t_tetris *alst, t_board *board, int row, int col)
{
	int	i;
	int	x;
	int	y;

	i = 5 * alst->min_row + alst->min_col - 1;
	while (++i < 20)
	{
		if (alst->shape[i / 5][i % 5] == '#')
		{
			x = (i / 5) - alst->min_row;
			y = (i % 5) - alst->min_col;
			if (!(0 <= row + x && row + x < board->size))
				return (0);
			if (!(0 <= col + y && col + y < board->size))
				return (0);
			if (board->map[row + x][col + y] != '.')
				return (0);
		}
	}
	return (1);
}

static int		decide(t_tetris *alst, t_board *board)
{
	int		row;
	int		col;

	if (!alst)
		return (1);
	row = 0;
	while (row < board->size)
	{
		col = 0;
		while (col < board->size)
		{
			if (check(alst, board, row, col))
			{
				put(alst, board, row, col);
				if (decide(alst->next, board))
					return (1);
				else
					delete(alst, board, row, col);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int				solution(t_tetris **alst, t_board *board)
{
	while (!decide(*alst, board))
		(board->size)++;
	return (1);
}
