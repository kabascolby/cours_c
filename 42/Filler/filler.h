/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 10:54:03 by lkaba             #+#    #+#             */
/*   Updated: 2018/04/26 17:08:39 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** w	: map width, 	|h			: map_height| 	m_x		: my "x", 		|m_y : my "y",
** e_x	: enemie's "x", |e_enmie's 	: y,		|	p 		: player status,|
** fm	: full map,		|sm			: small map	|	p_x		: print "x"		|p_y : print "y";
*/
#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h> //dellete later
# include <ctype.h>
# define NUM(c) ((c) - '0')
# define CE_(a, b) ((a) == (b))
# define CE_2(a, b, c) (CE_(a, b) || CE_(a, c))
# define CE_3(a, b, c, d) (CE_(a, b) || CE_(a, c) || CE_(a, d))

typedef struct	s_board
{
	uint16_t		w;
	uint16_t		h;
	uint8_t			p;
	uint16_t		p_w;
	uint16_t		p_h;
	int fd;
	//uint16_t		
	int	h_x;
	int	h_y;
	int	p_x;
	int	p_y;
	int sum;
	//uint64_t		c ='........';
	
	char		**fm;
	char		**piece;
}				t_b;

//*((uint64_t *)(adsf->fm[row] + 24)) != adf


typedef struct	s_f
{
	t_b		p;
}				t_f;

void	ft_writefd(char *buff, t_b *b);
void	parse1(char *buff, t_b *b);
void	parse2(char *buff, t_b *b);
void 	board_set(char *buff, t_b *b);
void 	ft_position(t_b *b);
void	ft_printboard(t_b *b);
void 	fill_board(t_b *b, int l, int n, int m);
//void	fill_board2(t_b *b);
void	ft_closefd(int *fd); //dellete it later
void bestfit(t_b *b);
#endif