/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:12:28 by lkaba             #+#    #+#             */
/*   Updated: 2017/11/22 16:12:29 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static void		strdel(void *str, size_t size)
{
	ft_memdel(&str);
	(void)size;
}

int				ft_getlines(int fd, t_list **lst)
{
	t_list	*ptr;
	char	*line;
	int		ret;

	while ((ret = get_next_line(fd, &line)))
	{
		ptr = ft_lstnew(line, ft_strlen(line) + 1);
		ft_strdel(&line);
		if (ptr == NULL)
		{
			ret = -1;
			break ;
		}
		ft_lstadd(lst, ptr);
	}
	if (ret == -1)
	{
		ft_lstdel(lst, strdel);
		return (0);
	}
	ft_lstrev(lst);
	return (1);
}
