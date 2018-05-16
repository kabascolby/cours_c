/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 11:49:24 by lkaba             #+#    #+#             */
/*   Updated: 2018/05/12 16:20:58 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		parse_board(t_b *b)
{
	int16_t	i;

	if (get_next_line(0, &b->buff) < 0)
		return (0);
	b->p = ft_strstr(b->buff, "p1") ? 1 : b->p;
	b->p = ft_strstr(b->buff, "p2") ? 2 : b->p;
	ft_strdel(&b->buff);
	get_next_line(0, &b->buff);
	b->h = ft_atoi(b->buff + 8);
	b->w = ft_atoi(ft_strchr(b->buff + 8, ' '));
	ft_strdel(&b->buff);
	get_next_line(0, &b->buff);
	ft_strdel(&b->buff);
	MAP = (char **)malloc(sizeof(char *) * b->h);
	i = -1;
	while (++i < b->h)
	{
		get_next_line(0, &b->buff);
		MAP[i] = b->buff + 4;
	}
	return (1);
}

/*
** to reduce the map size by excluding all the '.',
** I have to get the adjusted coordinate of the map
** I save the position of the first '*';
*/

void	parse_pieces(t_b *b)
{
	int16_t	i;

	get_next_line(0, &b->buff);
	b->p_h = ft_atoi(b->buff + 6);
	b->p_w = ft_atoi(ft_strchr(b->buff + 6, ' '));
	ft_strdel(&b->buff);
	b->toggle ? free(b->piece) : 0;
	b->piece = (char **)malloc(sizeof(char *) * b->p_h);
	i = -1;
	while (++i < b->p_h)
	{
		get_next_line(0, &b->buff);
		b->piece[i] = ft_strdup(b->buff);
		ft_strdel(&b->buff);
	}
	parse_pieces2(b);
}

void	parse_pieces2(t_b *b)
{
	int16_t	i;
	int16_t	j;

	b->toggle = 1;
	i = -1;
	while (++i < b->p_h)
	{
		j = -1;
		while (++j < b->p_w)
		{
			if (b->piece[i][j] == '*')
			{
				H_I = i;
				H_J = j;
				break ;
			}
		}
		if (b->piece[i][j] == '*')
			break ;
	}
}

int		main(void)
{
	t_b	b;

	ft_bzero(&b, sizeof(t_b));
	if (!(parse_board(&b)))
		return (0);
	while (1)
	{
		board_set(&b);
		ft_position(&b);
		parse_pieces(&b);
		bestpos_map(&b);
		b.sum != INT16_MAX ? ft_putnbr(b.fm_i - b.best_k) : write(1, "0", 1);
		write(1, " ", 1);
		b.sum != INT16_MAX ? ft_putnbr(b.fm_j - b.best_l) : write(1, "0", 1);
		write(1, "\n", 1);
		if (b.sum == INT16_MAX)
			break ;
	}
	close(b.fd);
	return (0);
}
