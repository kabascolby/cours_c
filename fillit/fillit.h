/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 02:28:04 by tadey             #+#    #+#             */
/*   Updated: 2018/01/25 06:34:32 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include "libft/libft.h"

/*
**	define
*/

# define BUFF_SIZE 524

/*
**	structs
*/

typedef	struct	s_tetris
{
	char				name;
	char				shape[5][5];
	char				min_row;
	char				min_col;
	struct s_tetris		*next;
}				t_tetris;

typedef struct	s_board
{
	char	map[104][104];
	int		size;
}				t_board;

/*
**	reading inputs (read.c)
*/

int				ft_read(int fd, char buff[]);

/*
**	parsing tetriminos (parse.c)
*/

t_tetris		*ft_parse_tet(char buff[], int shift, int ret);

/*
**	(solution.c) solving
*/

int				solution(t_tetris **alst, t_board *b);

/*
** Mes erreurs afficher
*/

int				ft_error(int n);
t_tetris		*ft_null_err(void);

#endif
