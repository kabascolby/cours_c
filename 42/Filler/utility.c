/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:07:49 by lkaba             #+#    #+#             */
/*   Updated: 2018/04/26 17:38:52 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void board_set(char *buff, t_b *b)
{
	uint16_t i;

	i = -1;
	while(++i < b->h)
	{
		get_next_line(0, &buff);
		ft_strcpy(b->fm[i], &(buff[4]));
		free(buff);
	}
	//ft_printboard(b);
}
/*
** ft_position give a negative 2 of all the position of my enemie
** negative one to all my position. And zero to all other position.
** In that way I can calculateall the possibility I have to reach my enemie.
*/
void ft_position(t_b *b)
{
    uint16_t i;
    uint16_t j;
	uint16_t k;
	//int n;
	//int m;
	//int l;

    i = -1;
	while (++i < b->h)
	{		j = -1;
		while(++j < b->w)
		{
			b->fm[i][j] = b->fm[i][j] == '.' ? 0 : b->fm[i][j];
			if(CE_2(b->fm[i][j], 'X', 'O'))
			{
				b->fm[i][j] == 'O' && b->p == 1 ? b->fm[i][j] = -1 : 0;
				b->fm[i][j] == 'O' && b->p == 2 ? b->fm[i][j] = -2 : 0;
				b->fm[i][j] == 'X' && b->p == 1 ? b->fm[i][j] = -2 : 0;
				b->fm[i][j] == 'X' && b->p == 2 ? b->fm[i][j] = -1 : 0;
			}	
		}
	}
	ft_printboard(b); //detete it later
	fill_board(b, 0 , -2,  1);
	k = 0;
	while(++k < b->w)
		fill_board(b, 0, k , k + 1);
	ft_printboard(b); //detete it later

	
}
void fill_board(t_b *b, int l, int n, int m)
{
	int16_t i;
	int16_t j;

	i = -1;
	while(++i < b->h)
	{
		j = -1;
		while(++j < b->w)
		{
			if(b->fm[i][j] == n)
            {
				(j + 1 < b->w) && (b->fm[i][j + 1] == l) ? b->fm[i][j + 1] = m : 0;
				(j - 1 >= 0) && (b->fm[i][j - 1] == l) ? b->fm[i][j - 1] = m : 0;
				((i + 1 < b->h) && (b->fm[i + 1][j] == l)) ? b->fm[i + 1][j] = m : 0;
				((i - 1 >= 0) && (b->fm[i - 1][j] == l)) ? b->fm[i - 1][j] = m : 0;
				((i + 1 < b->h) && (j - 1 >= 0) && (b->fm[i + 1][j - 1] == l)) ? b->fm[i + 1][j - 1] = m : 0;
				((i - 1 >= 0) && (j + 1 < b->w) && (b->fm[i - 1][j + 1] == l)) ? b->fm[i - 1][j + 1] = m : 0;	
				((i + 1 < b->h) && (j + 1 < b->w) && (b->fm[i + 1][j + 1] == l)) ? b->fm[i + 1][j + 1] = m : 0;
				((i - 1 >= 0) && (j - 1 >= 0) && (b->fm[i - 1][j - 1] == l)) ? b->fm[i - 1][j - 1] = m : 0;
			}
		}
	}
	//ft_printboard(b); //detete it later
}

/* void decision(t_b *b)
{
	uint16_t

} */

void ft_printboard(t_b *b)
{
	int i;
	int j;
	i = -1;
	dprintf(b->fd, "\n");	
	while(++i < b->h)
	{
		j = -1;
		while(++j < b->w)
		{
			if((b->fm[i][j] < 10) && (b->fm[i][j] >= 0))
				dprintf(b->fd, "  ");
			else
				dprintf(b->fd, " ");
			dprintf(b->fd, "%d", b->fm[i][j]);
		}
		dprintf(b->fd, "\n");
	}
}
