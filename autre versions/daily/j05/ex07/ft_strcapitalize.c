/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 20:01:07 by lamkaba2          #+#    #+#             */
/*   Updated: 2017/12/13 22:31:59 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*jp_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	jp_strlowcase(str);
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 'a' + 'A';
	while (str[i] != '\0')
	{
		if ((str[i] >= ' ' && str[i] <= '/') ||
			(str[i] >= ':' && str[i] <= '@'))
			if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
				str[i + 1] = str[i + 1] - 'a' + 'A';
		i++;
	}
	return (str);
}
