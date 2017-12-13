/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/08 18:11:56 by jpucelle          #+#    #+#             */
/*   Updated: 2017/12/12 21:28:53 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_iterative_factorial(int nb)
{
	int	i;
	int	f;

	if (nb >= 2)
	{
		i = 0;
		f = nb;
		while (++i < nb)
			f = f * (nb - i);
		return (f);
	}
	else
		return (1);
}

int main(void)
{
	printf("%d\n", ft_iterative_factorial(12));
	return 0;
}