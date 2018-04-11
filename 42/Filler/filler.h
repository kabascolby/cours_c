/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 10:54:03 by lkaba             #+#    #+#             */
/*   Updated: 2018/04/10 20:40:52 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ssize_t	m_x;
	ssize_t	m_y;
	ssize_t	e_x;
	ssize_t	e_y;
}			t_board;

typedef struct	s_f
{
	t_board	p;
}				t_f;

void ft_writefd(char *buff, ssize_t *fd);
int ft_parse1(t_f *f);
void ft_closefd(int *fd);
#endif