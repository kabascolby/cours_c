/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 10:43:55 by bpierce           #+#    #+#             */
/*   Updated: 2017/04/25 13:10:44 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mylib.h"

int		ft_are_you_a_whitespace(char c)
{
	if ((c == ' ') || (c == '\t') || (c == '\n'))
		return (1);
	else if ((c == '\v') || (c == '\f') || (c == '\r'))
		return (1);
	else
		return (0);
}

int		ft_are_you_a_number_bitch(char c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
}

int		ft_atoi(char *str)
{
	int i;
	int sign;
	int total;

	i = 0;
	sign = 1;
	total = 0;
	while (ft_are_you_a_whitespace(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_are_you_a_number_bitch(str[i]) == 1)
	{
		total = (total * 10) + (str[i] - '0');
		i++;
	}
	return (sign * total);
}
