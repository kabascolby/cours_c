/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/09 19:48:22 by lamkaba2          #+#    #+#             */
/*   Updated: 2017/12/13 22:31:59 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strstr(char *str, char *to_find)
{
	char	*a;
	char	*b;

	b = to_find;
	if (*b == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*str == *b)
		{
			a = str;
			while (*a == *b || *b == '\0')
			{
				if (*b == '\0')
					return (str);
				a++;
				b++;
			}
			b = to_find;
		}
		str++;
	}
	return (0);
}
