/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <laminekaba@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 13:17:29 by lkaba             #+#    #+#             */
/*   Updated: 2017/04/26 20:41:09 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/bsq.h"

int		get_first_line_length(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n')
		i++;
	if (i < 4)
		return (0);
	return (i);
}

int		check_first_chars(char *str)
{
	int		i;
	int		j;

	i = get_first_line_length(str);
	j = 0;
	if ((str[i - 1] == str[i - 2]) || \
			(str[i - 2] == str[i - 3]) || (str[i - 1] == str[i - 3]))
		return (0);
	else
	{
		while (j < i - 3)
		{
			if (str[j] < 48 || str[j] > 57)
				return (0);
			j++;
		}
	}
	return (1);
}
