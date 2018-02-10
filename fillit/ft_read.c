/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 04:55:21 by lkaba             #+#    #+#             */
/*   Updated: 2018/01/25 19:14:43 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris		*ft_null_err(void)
{
	ft_putendl("error");
	return (NULL);
}

int				ft_error(int n)
{
	if (n == 1)
		ft_putendl("error");
	if (n == 2)
		ft_putendl("Usage error: ./fillit sample");
	return (0);
}

static int		ft_check_file(char buff[], int shift)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if ((i % 5) < 4)
			if (buff[shift + i] != '.' && buff[shift + i] != '#')
				return (0);
		if ((i % 5) == 4 && buff[shift + i] != '\n')
			return (0);
		i++;
	}
	if (buff[shift + i] && buff[shift + i] != '\n')
		return (0);
	return (1);
}

static	int		ft_check_tetrimino(char buff[], int shift, int hash)
{
	int		i;
	int		neighbor;

	i = 0;
	neighbor = 0;
	while (i < 19)
	{
		if (buff[shift + i] == '#')
		{
			if (i + 1 < 19 && (i + 1) % 5 != 4 && buff[shift + i + 1] == '#')
				neighbor++;
			if (i - 1 >= 0 && (i - 1) % 5 != 4 && buff[shift + i - 1] == '#')
				neighbor++;
			if (i + 5 < 19 && buff[shift + i + 5] == '#')
				neighbor++;
			if (i - 5 >= 0 && buff[shift + i - 5] == '#')
				neighbor++;
			hash++;
		}
		i++;
	}
	if (hash != 4 || (neighbor != 6 && neighbor != 8))
		return (0);
	return (1);
}

int				ft_read(int fd, char buff[])
{
	int shift;
	int ret;

	shift = 0;
	ft_strclr(buff);
	ret = read(fd, buff, BUFF_SIZE);
	if (ret <= 0)
		return (ft_error(1));
	while (shift < ret)
	{
		if (!ft_check_file(buff, shift))
			return (ft_error(1));
		if (!ft_check_tetrimino(buff, shift, 0))
			return (ft_error(1));
		shift += 21;
	}
	if (shift == ret)
		return (ft_error(1));
	return (ret);
}
