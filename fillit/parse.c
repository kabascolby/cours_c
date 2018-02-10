/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 02:28:42 by tadey             #+#    #+#             */
/*   Updated: 2018/02/01 11:38:13 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	t_tetris	*ft_new_link(void)
{
	int			i;
	int			j;
	t_tetris	*link;

	i = 0;
	if (!(link = (t_tetris *)malloc(sizeof(t_tetris))))
		return (NULL);
	link->name = '-';
	link->min_row = 4;
	link->min_col = 4;
	link->next = NULL;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			link->shape[i][j++] = '.';
		link->shape[i][j] = '\n';
		i++;
	}
	return (link);
}

static	void		ft_fill_link(t_tetris **link, char buff[], int i, int shift)
{
	int			x;
	t_tetris	*current;
	char		*alphabets;

	x = 0;
	alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	current = *link;
	current->name = alphabets[i];
	while (x < 20)
	{
		if (buff[shift + x] == '#')
		{
			if (x % 5 < current->min_col)
				current->min_col = x % 5;
			if (x / 5 < current->min_row)
				current->min_row = x / 5;
			current->shape[x / 5][x % 5] = '#';
		}
		x++;
	}
}

static	void		ft_add_link(t_tetris **alst, t_tetris **link)
{
	t_tetris	*current;
	t_tetris	*previous;

	if (!(*alst))
		*alst = *link;
	else
	{
		current = *alst;
		while (current != NULL)
		{
			previous = current;
			current = current->next;
		}
		previous->next = (*link);
	}
}

t_tetris			*ft_parse_tet(char buff[], int shift, int ret)
{
	int			i;
	t_tetris	*alst;
	t_tetris	*current;

	i = -1;
	alst = NULL;
	while (shift < ret)
	{
		if (!(current = ft_new_link()))
			return (ft_null_err());
		ft_fill_link(&current, buff, ++i, shift);
		ft_add_link(&alst, &current);
		shift += 21;
	}
	return (alst);
}
