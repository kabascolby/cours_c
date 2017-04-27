/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <laminekaba@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 23:46:34 by lkaba             #+#    #+#             */
/*   Updated: 2017/04/26 20:44:27 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/bsq.h"

int		check_for_one_empty(char *str)
{
	int		i;
	int		j;
	char	empty;

	i = 0;
	j = 0;
	empty = empty_char(str);
	while (str[i] != '\n')
		i++;
	str = &str[i + 1];
	while (str[j] != 0)
	{
		if (str[j] == empty)
			return (1);
		j++;
	}
	return (0);
}

int		check_num_of_lines(char *str)
{
	int	i;
	int	n;
	int	j;

	i = 0;
	j = 0;
	n = ft_atoi(str);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			j++;
		i++;
	}
	if (j == n + 1)
		return (1);
	return (0);
}

int		check_valid_chars(char *str)
{
	int		i;
	char	empty;
	char	obst;

	i = 0;
	empty = empty_char(str);
	obst = obstacle_char(str);
	while (str[i] != '\n')
		i++;
	i++;
	while (str[i] != '\0')
	{
		if (str[i] != empty && str[i] != obst && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
