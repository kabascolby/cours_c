/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:12:22 by lkaba             #+#    #+#             */
/*   Updated: 2017/12/12 22:58:11 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "stdio.h"
int		ft_countwords(char *str, char sep)
{
	int result;
	int i;

	i = 0;
	result = 0;
	while (str[i] && str[i] == sep)
	{	
		i++;		
		printf("i1 = %d\n", i);
	}
	printf("i avant la boucle2 %d\n", i);
	while (str[i])
	{
		printf("i au debut de la boucle2 %d\n", i);
		while (str[i] && str[i] != sep)
			{
				i++;
				printf("i2 = %d\n", i);
			}
		result++;
		printf("result = %d \n", result);
		while (str[i] && str[i] == sep)
			i++;
	}
	return (result);
}
int main(void)
{
	printf("%d", ft_countwords("   lamine kaba  Marietou", ' '));
	return 0;
}