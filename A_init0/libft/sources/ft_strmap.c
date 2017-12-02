/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:06:03 by lkaba             #+#    #+#             */
/*   Updated: 2017/11/22 16:06:03 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"


// char	*ft_strmap(const char *s, char (*f)(char))
// {
// 	char			*new;
// 	unsigned int	i;

// 	i = 0;
// 	new = ft_strnew(ft_strlen(s));
// 	if (new == NULL)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		new[i] = (*f)(s[i]);
// 		i++;
// 	}
// 	return (new);
// }

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*fresh;

	if (!s || !f)
		return (NULL);
	fresh = ft_strnew(ft_strlen(s));
	i = 0;
	while (s[i])
	{
		fresh[i] = (*f)(s[i]);
		i++;
	}
	return (fresh);
}
