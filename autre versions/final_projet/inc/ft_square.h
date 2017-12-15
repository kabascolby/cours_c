/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/23 23:38:22 by lamkaba2          #+#    #+#             */
/*   Updated: 2017/12/13 22:31:59 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JP_SQUARE_H
# define JP_SQUARE_H

# include <stdlib.h>
# include "ft_print.h"

typedef struct	s_bsq
{
	char	*map;
	int		columns;
	int		position;
	int		size;
}				t_bsq;

typedef struct	s_obj
{
	char	empty;
	char	obstacle;
	char	wall;
}				t_obj;

int		calc_columns(char *str);
int		calc_size(t_bsq a, t_obj b, int k, int l);
char	*draw_square(t_bsq a, t_obj b);
char	*calc_square(t_bsq a, t_obj b);
int		bsq(char *map);

#endif
