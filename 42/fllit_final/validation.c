/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 12:37:35 by lkaba             #+#    #+#             */
/*   Updated: 2018/02/03 17:28:13 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*t_tetris		*ft_null_err(void)
{
	ft_putendl("error");
	return (NULL);
}

*/
int		ft_error(int n)
{
	if (n == 1)
		ft_putendl("error");
	if (n == 2)
		ft_putendl("Usage error: ./fillit sample");
	return (0);
}
//int ft_neighboardcheck(char *buf)

void *validation_fail(t_piece *p)
{
	free(p);
	return (NULL);
}

t_piece *validate_piece(t_piece *p, int fd)
{
	char *b;
	int 	i;

	i 	= 	0;
   while(GNL(fd,  	
	return (NULL);
	return (p);
}

t_piece *ft_boardcheck(t_piece *p, int fd)
{
	char *l

	if (p == NULL)
		p = ft_memalloc(sizeof(t_piece));
	if (!(p = validate_piece(p, fd)))
		return (validation_fail(p));
	if (GNL(fd, &l) = 1)
	{
		if (ft_strlen(l) == 0)
		{
			if (!(p->next = ft_boardcheck(p->next, fd)))
				return (validation_fail(p));
		}
		return (validation_fail(p));
	}
	return (p);
}
