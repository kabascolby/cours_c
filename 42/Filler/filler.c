/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 11:49:24 by lkaba             #+#    #+#             */
/*   Updated: 2018/04/11 18:16:19 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_writefd(char *buff, t_b *b)
{
	free(buff);
	b->fd = open("file.txt", O_RDWR|O_CREAT|O_APPEND, 0755);		
	/* write(b->fd, buff, ft_strlen(buff));
	write(b->fd, "\n", 1); */
}

void	ft_parse1(char *buff, t_b *b)
{

	ft_writefd(buff, b);
	b->p = ft_strstr(buff, "p1") ? 1 : b->p;
	b->p = ft_strstr(buff, "p2") ? 2 : b->p;
	get_next_line(0, &buff);
	ft_writefd(buff, b);
	buff +=	8;
	b->h = ft_atoi(buff);
	b->w = ft_atoi(ft_strchr(buff, ' '));
	dprintf(b->fd,"\nplayer:%lu |buff: %swidth: %lu |height: %lu\n", b->p, buff, b->w, b->h);
	get_next_line(0, &buff);
	board_set(buff, b);
	ft_position(b);
}

int				main()
{
	//char s[] = "........";
	char		*buff;
	static		t_b b;
	ft_bzero(&b, sizeof(t_b));
	unlink("file.txt"); //delete it later
	if (get_next_line(0, &buff) < 0)
		return (0);
	ft_parse1(buff, &b);
	close(b.fd);
	return(0);
}
