/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 08:33:00 by lkaba             #+#    #+#             */
/*   Updated: 2018/01/25 18:37:34 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

int	ft_remalloc(char **save)
{
	char	*tmp;

	tmp = *save;
	//*save = NULL;
	if (!(*save = ft_strnew(ft_strlen(tmp) + BUFF_SIZE)))
		return (0);
	ft_strcpy(*save, tmp);
	(*save)[ft_strlen(tmp) + BUFF_SIZE] = '\0';
	free(tmp);
	return (1);
}

int	fill_line(int j, char **save, char **line)
{
	// j = length read
	// save = saved message buffer
	int i;
	int k;

	k = 0;
	i = 0;
	// while we read stuff, OR we have saved buffer
	if (j != 0 || ft_strlen((*save)) != 0)
	{
		// Find length up to EOF or NEWLINE
		while(((*save)[i] != '\0') && ((*save)[i] != '\n'))
			i++;
		// if index i == NEWLINE
		if ((*save)[i] == '\n')
		{
			// Allocate new memory for output buffer
			*line = (char *)malloc(sizeof(char) * i);
			// Write into the buffer the length up to EOF/NEWLINE
			ft_strncpy(*line, *save, i);
			(*line)[i] = '\0';
		} else if ((*save)[i] == '\0') {
			// *line = NULL;
			return 1;
		}
		// if data is past this NEWLINE/END
		if((*save)[i++])
			while ((*save)[i])
				(*save)[k++] = (*save)[i++];
		(*save)[k] = '\0';
		return (2);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			l;
	static char	*save[5000];
	char		buf[BUFF_SIZE + 1];

	if (fd < 0/* || (!save && !(save = ft_strnew(BUFF_SIZE))) */)
		return (-1);
	
	while ((l = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!(ft_remalloc(&save[fd])))
			return (-1);
		ft_strncat(save[fd], buf, BUFF_SIZE);
		if (ft_memchr(buf, '\n', BUFF_SIZE))
			break ;
	}
	if ((fill_line(l, &save[fd], line)) == 2)
		return (1);
	else
		return 0;
	// else if (ft_memcmp((*line), &save[fd], ft_strlen(*line)) == 0)
	// {
	// 	if (*line == NULL)
	// 		return (0);
	// }
	// return (1);
}