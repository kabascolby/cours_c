/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 08:33:00 by lkaba             #+#    #+#             */
/*   Updated: 2018/01/13 05:59:27 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int ft_remalloc(char **save)
{
    char *tmp;

    if (!(tmp = ft_strnew(ft_strlen(*save))))
        return (0);
    ft_strcpy(tmp, *save);
    *save = NULL;
    if (!(*save = ft_strnew(ft_strlen(tmp) + BUFF_SIZE)))
        return (0);
    ft_strcpy(*save, tmp);
    return (1);
}

int fill_line(int j, char **save, char **line)
{
    int i;
    int j;

    j = 0;
    i = 0;
    if (j != 0 || ft_strlen((*save)) != 0)
    {
        while ((*save)[i] != '\n')
        {
            (*line)[i] = (*save)[i];
            i++;
        }
        (*line)[i++] = '\0';

        if ((*save)[0] == '\n')
        {
            while ((*save)[i])
                (*save)[j++] = (*save)[i++];
            (*save)[j] = '\0';
            return (2);
        }
        while ((*save)[i])
            (*save)[j++] = (*save)[i++];
        (*save)[j] = '\0';
    }
    return (1);
}

int get_next_line(int fd, char **line)
{
    int l;
    static char *save;

    if (fd < 0 || (!save && !(save = ft_strnew(BUFF_SIZE))))
        return (-1);

    if (!(*line = (char *)malloc(sizeof(char) * BUFF_SIZE)))
        return (-1);

    while ((l = read(fd, *line, BUFF_SIZE)) > 0)
    {
        if (!(ft_remalloc(&save)))
            return (-1);
        ft_strncat(save, *line, BUFF_SIZE);
        if (ft_memchr(*line, '\n', BUFF_SIZE))
            break;
    }
    if ((fill_line(l, &save, &(*line))) == 2)
        return (1);
    if (ft_memcmp((*line), save, ft_strlen(*line)) == 0)
    {
        if (!(*line = ft_strdup("")))
            return (1);
        return (0);
    }
    return (1);
}
