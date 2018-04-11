/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 10:54:03 by lkaba             #+#    #+#             */
/*   Updated: 2018/04/10 21:15:49 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** w : map width, h: map_height, m_x : my "x", m_y : my "y",
** e_x : enemie's "x", e_enmie's : y,
**
*/

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 520

typedef struct	s_board
{
	size_t	w;
	size_t	h;
	size_t	p;
	size_t	
	ssize_t	m_x;
	ssize_t	m_y;
	ssize_t	e_x;
	ssize_t	e_y;
	char	**fm;
	char	**sm;
}			t_board;

typedef struct	s_f
{
	t_board	p;
}				t_f;

void ft_writefd(char *buff, ssize_t *fd);
int ft_parse1(t_f *f);
void ft_closefd(int *fd);
#endif