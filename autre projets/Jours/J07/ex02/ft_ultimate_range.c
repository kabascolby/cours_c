/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 10:15:06 by lamkaba2          #+#    #+#             */
/*   Updated: 2018/01/17 23:26:53 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int	*ret;
	int i;

	i = 0;
	ret = (int*)malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		ret[i] = min;
		min++;
		i++;
	}
	*range = ret;
	return (i);
}

int main(void)
{
	int *tab;
	int **tab1;
	tab1 = &tab;	
	printf("%d, %p",ft_ultimate_range(tab1, 30, 20), tab);
	return 0;
}