/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:07:12 by lkaba             #+#    #+#             */
/*   Updated: 2017/11/22 16:07:14 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(char *s, char c)
{
	int		words;

	while (*s && *s == c)
		++s;
	words = (*s) ? 1 : 0;
	while (*s)
	{
		if (*s == c && s[1] && s[1] != c)
			++words;
		++s;
	}
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	int		words;
	char	*start;
	char	**result;

	words = count_words((char *)s, c);
	if (!s || !c)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_words((char *)s, c) + 1));
	start = (char *)s;
	while (*s)
	{
		if (*s == c)
		{
			if (start != s)
				*(result++) = ft_strsub(start, 0, s - start);
			start = (char *)s + 1;
		}
		++s;
	}
	if (start != s)
		*(result++) = ft_strsub(start, 0, s - start);
	*result = NULL;
	return (result - words);
}
