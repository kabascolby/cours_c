/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 21:45:01 by lkaba             #+#    #+#             */
/*   Updated: 2017/04/08 21:45:10 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	line2(int ix, int x)
{
	if (ix == 1 || ix == x)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	line3(int ix, int x)
{
	if (ix == 1 || ix == x)
		ft_putchar('C');
	else
		ft_putchar('B');
}

void	line1(int ix, int x)
{
	if (ix == 1 || ix == x)
		ft_putchar('A');
	else
		ft_putchar('B');
}

void	rush(int x, int y)
{
	int ix;
	int iy;

	iy = 1;
	while (iy <= y)
	{
		ix = 1;
		while (ix <= x)
		{
			if (iy == 1)
				line1(ix, x);
			else if (iy == y)
				line3(ix, x);
			else
				line2(ix, x);
			ix++;
		}
		ft_putchar('\n');
		iy++;
	}
}
