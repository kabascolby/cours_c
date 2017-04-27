/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 12:31:05 by bpierce           #+#    #+#             */
/*   Updated: 2017/04/26 22:38:17 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define BUF_SIZE 3000000
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../mylib/inc/mylib.h"

typedef struct	s_best
{
	int			best_cell;
	int			best_size;
	int			c_cell;
	int			c_size;
}				t_best;

typedef struct	s_cells
{
	int			x;
	int			y;
	int			empty_val;
}				t_cells;

typedef struct	s_saveme
{
	int			i;
	int			j;
}				t_counter;

int				num_of_lines(char *s);

int				line_len(char *s);

char			empty_char(char *s);

char			obstacle_char(char *s);

char			full_char(char *s);

char			*new_map(char *s, int num_of_lines);

t_cells			*create_array(char *s, char *map, \
				int line_len, int num_of_lines);

int				x_pos(int index, int width);

int				y_pos(int index, int width);

t_best			algor(t_cells *cells, t_best mybox, \
				int line_len, int num_of_lines);

void			print_new_map(char *map, t_best mybox, \
				int line_len, char full_char);

int				check_valid_chars(char *str);

int				check_num_of_lines(char *str);

int				check_for_one_empty(char *str);

int				check_line_accuracy(char *str);

int				check_first_chars(char *str);
#endif
