/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 10:54:03 by lkaba             #+#    #+#             */
/*   Updated: 2018/04/11 14:47:21 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** w	: map width, 	|h			: map_height| 	m_x		: my "x", 		|m_y : my "y",
** e_x	: enemie's "x", |e_enmie's 	: y,		|	p 		: player status,|
** fm	: full map,		|sm			: small map	|	
*/

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# define NUM(c) ((c) - '0')

typedef struct	s_board
{
	size_t	w;
	size_t	h;
	size_t	p;
	int fd;
	//size_t		
	int	m_x;
	int	m_y;
	int	e_x;
	int	e_y;
	char	**fm;
	char	**sm;
}			t_b;

typedef struct	s_f
{
	t_b		p;
}				t_f;

void	ft_writefd(char *buff, t_b *b);
void	ft_parse1(char *buff, t_b *b);
void	ft_closefd(int *fd);
#endif