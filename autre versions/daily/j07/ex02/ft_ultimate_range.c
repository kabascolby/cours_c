/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/14 16:47:00 by lamkaba2          #+#    #+#             */
/*   Updated: 2018/01/17 22:39:57 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int **t;
	int m;
	int i;

	if (min >= max)
		return (0);
	m = max - min - 1;
	if ((t = (int **)malloc(sizeof(int*) * m)) == NULL)
		return (0);
	m++;
	i = 0;
	while (min < max)
		*t[i++] = min++;
	range = t;
	return (m);
}
int main(void)
{
	int tab;
	int **tab1;
	tab1 = &tab;	
	printf("%d",ft_ultimate_range(tab1, -5, 6));
	return 0;
}