/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 02:15:49 by lamkaba2          #+#    #+#             */
/*   Updated: 2017/12/12 23:16:32 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_rot42(char *str)
{
	int		i;
	int		y;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		y = 0;
		while (y < 16)
		{
			c = str[i];
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			{
				if (str[i] == 'z')
					str[i] = 'a';
				else if (str[i] == 'Z')
					str[i] = 'A';
				else
					str[i]++;
			}
			y++;
		}
		i++;
	}
	return (str);
}
