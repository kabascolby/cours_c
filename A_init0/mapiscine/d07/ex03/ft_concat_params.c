/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:23:30 by lkaba             #+#    #+#             */
/*   Updated: 2018/01/18 16:24:02 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	return (*str++ ? ft_strlen(str) + 1 : 0);
}

char	*ft_strcat(char *src, char *dest)
{
	int 	i;
	
	i = 0;
	while (dest[i])
		i++;
	while (*src)
		dest[i++] = *src++;
	dest[i] = '\n';
	dest[i + 1] = '\0';
	return (dest);
}

char	*ft_concat_params(int argc, char **argv)
{
	int 	i;
	int 	len;
	char 	*str;

	if (argc < 2 || !argv)
		return (NULL);
	len = 0;
	i = argc;
	while (i > 1)
		len = len + ft_strlen(argv[i-- - 1]) + 1;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (0);
	*str = '\0';
	 i = 1;
	 while (i < argc)
		 str = ft_strcat(argv[i++], str);
	 return (str);
}
