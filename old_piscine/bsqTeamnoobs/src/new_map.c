/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 21:59:36 by bpierce           #+#    #+#             */
/*   Updated: 2017/04/26 19:09:53 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/bsq.h"

char	*new_map(char *s, int num_of_lines)
{
	int		i;
	int		j;
	char	*newarray;

	i = 0;
	j = 0;
	while (s[i] != '\n')
		i++;
	s = &s[i + 1];
	i = 0;
	while (s[i] != '\n')
		i++;
	newarray = (char *)malloc(sizeof(char) * ((i * num_of_lines) + 1));
	i = 0;
	while (s[i])
	{
		if (s[i] != '\n')
		{
			newarray[j] = s[i];
			j++;
		}
		i++;
	}
	return (newarray);
}
