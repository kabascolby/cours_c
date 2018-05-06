/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 11:49:24 by lkaba             #+#    #+#             */
/*   Updated: 2018/05/05 20:27:48 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		parse1(t_b *b)
{
	int16_t i;
	char *buff;

	b->fd = open("file.txt", O_RDWR|O_CREAT|O_APPEND, 0755); // Delete when done
	if (get_next_line(0, &buff) < 0)
		return (0);
	b->p = ft_strstr(buff, "p1") ? 1 : b->p;
	b->p = ft_strstr(buff, "p2") ? 2 : b->p;
	//ft_strdel(&buff);

	get_next_line(0, &buff);
	b->h = ft_atoi(buff + 8);
	b->w = ft_atoi(ft_strchr(buff + 8, ' '));
	//ft_strdel(&buff);

	get_next_line(0, &buff);
	//ft_strdel(&buff);
	b->fm = (char **)malloc(sizeof(char *) * b->h);
	i = -1;
	while(++i < b->h)
	{
		get_next_line(0, &buff);
		b->fm[i] = buff + 4;
	}
	return (1);
}
/*
	** to reduce the map size by excluding all the '.', I have to get the adjusted coordinate of the map
	**  I save the position of the first '*'; 
*/
void	parse2(t_b *b)
{
	int16_t i;
	int16_t j;
	char	*buff;

	get_next_line(0, &buff);
	dprintf(b->fd,"\n\n%s\n", buff);
	b->p_h = ft_atoi(buff + 6);
	b->p_w = ft_atoi(ft_strchr(buff + 6, ' '));
	//ft_strdel(&buff);
	//b->toggle ? free(b->piece) : 0;
	b->piece = (char **)malloc(sizeof(char *) * b->p_h);
	i = -1;
	while (++i < b->p_h)
	{
		//b->toggle ? 0 : 0;//ft_strdel(&b->piece[i]) : 0;
		get_next_line(0, &buff);
		b->piece[i] = ft_strdup(buff);
		//ft_strdel(&buff);
	}
	b->toggle = 1;
	i = -1;
	while (++i < b->p_h)
	{
		j = -1;
		while (++j < b->p_w)
		{
			if (b->piece[i][j] == '*')
			{
				b->p_hi = i;
				b->p_hj = j;
				break;
			}
		}
		if (b->piece[i][j] == '*')
				break;
	}
	i = -1;
	while (++i < b->p_h) //delete Later
		dprintf(b->fd,"%s\n", b->piece[i]);
	dprintf(b->fd,"---------------\n\n");

}

int				main()
{
	t_b		b;

	ft_bzero(&b, sizeof(t_b));
	unlink("file.txt"); //delete it later
	if (!(parse1(&b)))
		return (0);
	while (1)
	{
		board_set(&b);
		ft_position(&b);
		parse2(&b);
		bestpos_fm(&b);
		if(b.sum == INT16_MAX)
			break ;
	}
	close(b.fd);
	return(0);
}
