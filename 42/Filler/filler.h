/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 10:54:03 by lkaba             #+#    #+#             */
/*   Updated: 2018/05/12 16:32:42 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <ctype.h>
# include <limits.h>
# define NUM(c) ((c) - '0')
# define CE_(a, b) ((a) == (b))
# define CE_2(a, b, c) (CE_(a, b) || CE_(a, c))
# define MAP b->fm
# define H_I b->p_hi
# define H_J b->p_hj

typedef	struct	s_board
{
	uint16_t	w;
	uint16_t	h;
	uint8_t		p;
	uint16_t	p_w;
	uint16_t	p_h;
	int			fd;
	char		*buff;
	int8_t		p_hi;
	int8_t		p_hj;
	int			p_x;
	int			p_y;
	int16_t		sum;
	int16_t		fm_i;
	int16_t		fm_j;
	int16_t		cur_i;
	int16_t		cur_j;
	int16_t		cur_pi;
	int16_t		cur_pj;
	int16_t		best_k;
	int16_t		best_l;
	int16_t		d_i;
	int16_t		d_j;
	int16_t		k;
	int16_t		l;
	int8_t		toggle;
	char		**fm;
	char		**piece;
}				t_b;

int				parse_board(t_b *b);
void			parse_pieces(t_b *b);
void			parse_pieces2(t_b *b);
void			board_set(t_b *b);
void			ft_position(t_b *b);
void			ft_printboard(t_b *b);
void			fill_board(t_b *b, int16_t l, int16_t n, int16_t m);
void			ft_closefd(int *fd);
void			bestpos_map(t_b *b);
uint16_t		best_piece(t_b *b);
uint16_t		sumpath(t_b *b);
int8_t			index_fail(t_b *b, int16_t x, int16_t y);
void			reset_value(t_b *b);
#endif
