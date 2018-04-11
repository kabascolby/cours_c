/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 11:49:24 by lkaba             #+#    #+#             */
/*   Updated: 2018/04/10 21:15:51 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void	ft_writefd(char *buff, ssize_t *fd)
{
	write(*fd, buff, ft_strlen(buff));
	write(*fd, "\n", 1);
}


void	ft_parse1(char *buff, t_b *b)
{
	dprintf(2,"\n\n%lu\n %s\n\n", b->p, buff);
	b->p = ft_strstr(buff, "p1") ? 1 : b->p;
	b->p = ft_strstr(buff, "p2") ? 2 : b->p;
	dprintf(2,"\n\n%lu\n %s\n\n", b->p, buff);
	
}

int				main()
{
	char		*buff;
	ssize_t		fd;
	//t_f			f;
	static		t_b b;
	//ft_putstr_fd("[3 8]", 2);
	ft_bzero(&b, sizeof(t_b));
	unlink("file.txt"); //delete it later
	if (get_next_line(0, &buff) < 0)
		return (0);
	ft_parse1(buff, &b);
	fd = open("file.txt", O_RDWR|O_CREAT|O_APPEND, 0755);		
	ft_writefd(buff, &fd);
	get_next_line(0, &buff);
	ft_writefd(buff, &fd);
	close(fd);
	return(0);
}
