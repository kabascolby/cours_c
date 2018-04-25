/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 11:49:24 by lkaba             #+#    #+#             */
/*   Updated: 2018/04/23 18:04:50 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_writefd(char *buff, t_b *b)
{
	free(buff);
	b->fd = open("file.txt", O_RDWR|O_CREAT|O_APPEND, 0755);
}

void	parse1(char *buff, t_b *b)
{
	uint16_t i;

	ft_writefd(buff, b);
	b->p = ft_strstr(buff, "p1") ? 1 : b->p;
	b->p = ft_strstr(buff, "p2") ? 2 : b->p;
	get_next_line(0, &buff);
	buff +=	8;
	b->h = ft_atoi(buff);
	b->w = ft_atoi(ft_strchr(buff, ' '));
	dprintf(b->fd,"\nplayer:%hhd |buff: %swidth: %hd |height: %hd\n", b->p, buff, b->w, b->h); // delete it later
	get_next_line(0, &buff);
	b->fm = (char **)malloc(sizeof(char *) * b->h);
	i = -1;
	while (++i < b->h)
		b->fm[i] = ft_strnew(b->w);
	board_set(buff, b);
	parse2(buff, b);	
	ft_position(b);
}
void	parse2(char *buff, t_b *b)
{
	uint16_t i;

	get_next_line(0, &buff);
	buff +=	6;
	b->p_h = ft_atoi(buff);
	b->p_w = ft_atoi(ft_strchr(buff, ' '));
	dprintf(b->fd,"buff:%s width: %hd |height: %hd\n", buff, b->p_w, b->p_h); // delete it later
	b->piece = (char **)malloc(sizeof(char *) * b->p_h);
	i = -1;
	while (++i < b->p_h)
		b->piece[i] = ft_strnew(b->p_w);
	i = -1;
	while(++i < b->p_h)
	{
		get_next_line(0, &buff);
		ft_strcpy(b->piece[i], buff);
		free(buff);
	}
	/* i = -1;
	while(++i < b->p_h) //delete Later
		dprintf(b->fd,"%s\n", b->piece[i]); */
}

int				main()
{
	char		*buff;
	t_b			b;
	ft_bzero(&b, sizeof(t_b));
	unlink("file.txt"); //delete it later
	if (get_next_line(0, &buff) < 0)
		return (0);
	parse1(buff, &b);
	close(b.fd);
	return(0);
}
