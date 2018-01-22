/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 19:00:19 by lkaba             #+#    #+#             */
/*   Updated: 2018/01/17 19:00:33 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*tab;
	int		len;

	len = ft_strlen(str);
	if (!len)
		return (0);
	else
	{
		tab = (char *)malloc((*str) * len) + 1;
		tab = str;
	}
	return (tab);
}
