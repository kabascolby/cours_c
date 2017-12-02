/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:06:10 by lkaba             #+#    #+#             */
/*   Updated: 2017/11/22 16:06:11 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stlib.h>

// char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
// {
// 	char			*new;
// 	unsigned int	i;

// 	i = 0;
// 	new = ft_strnew(ft_strlen(s));
// 	if (new == NULL)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		new[i] = (*f)(i, s[i]);
// 		i++;
// 	}
// 	return (new);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fresh;

	if (!s || !f)
		return (NULL);
	fresh = ft_strnew(ft_strlen(s));
	i = 0;
	while (s[i])
	{
		fresh[i] = (*f)(i, s[i]);
		i++;
	}
	return (fresh);
