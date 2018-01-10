/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 12:42:47 by bpierce           #+#    #+#             */
/*   Updated: 2017/04/26 21:25:33 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/bsq.h"

char	full_char(char *s)
{
	int i;

	i = 0;
	while (s[i] >= 48 && s[i] <= 57)
		i++;
	s += i;
	return (s[2]);
}

char	obstacle_char(char *s)
{
	int i;

	i = 0;
	while (s[i] >= 48 && s[i] <= 57)
		i++;
	s += i;
	return (s[1]);
}

char	empty_char(char *s)
{
	int i;

	i = 0;
	while (s[i] >= 48 && s[i] <= 57)
		i++;
	s += i;
	return (s[0]);
}

int		num_of_lines(char *s)
{
	return (ft_atoi(s));
}

int		line_len(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\n')
		i++;
	s = &s[i + 1];
	i = 0;
	while (s[i] != '\n')
		i++;
	return (i);
}
