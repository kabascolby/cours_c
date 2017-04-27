/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <laminekaba@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 23:24:10 by lkaba             #+#    #+#             */
/*   Updated: 2017/04/26 21:33:23 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/bsq.h"

char	*get_address(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	str = &str[i + 1];
	return (str);
}

int		check_line_accuracy(char *str)
{
	t_counter	fucknorm;
	int			nlines;
	int			llen;

	nlines = ft_atoi(str);
	llen = line_len(str);
	str = get_address(str);
	fucknorm.i = 0;
	fucknorm.j = 0;
	while (str[fucknorm.i] != '\0')
	{
		if (str[fucknorm.i] == '\n')
		{
			fucknorm.j++;
			if (fucknorm.i != llen)
				return (0);
			str = &str[fucknorm.i + 1];
			fucknorm.i = 0;
		}
		else
			fucknorm.i++;
	}
	if (fucknorm.j != nlines)
		return (0);
	return (1);
}
