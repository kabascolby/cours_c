/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 09:53:41 by lamkaba2          #+#    #+#             */
/*   Updated: 2017/12/12 23:16:32 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	ft_strlen(char *str)
{
	int nb;

	nb = 0;
	while (str[nb] != '\0')
	{
		nb++;
	}
	return (nb);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		taille_src;
	int		i;

	i = 0;
	taille_src = ft_strlen(src);
	str = (char*)malloc(sizeof(*str) * (taille_src + 1));
	while (i < taille_src)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
