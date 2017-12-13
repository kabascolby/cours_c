/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 12:06:15 by lamkaba2          #+#    #+#             */
/*   Updated: 2017/12/12 23:16:32 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_unmatch(int *tab, int length)
{
	int i;
	int count;
	int j;

	i = 0;
	while (i < length)
	{
		j = 0;
		count = 0;
		while (tab[j] < length)
		{
			if (tab[j] == tab[i])
				count++;
			j++;
		}
		if (count % 2)
			return (tab[i]);
		i++;
	}
	return (0);
}
