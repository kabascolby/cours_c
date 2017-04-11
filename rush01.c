/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 21:45:01 by lkaba             #+#    #+#             */
/*   Updated: 2017/04/09 18:16:22 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	line2(int ix, int x)
{
	if (ix == 1 || ix == x)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	line3(int ix, int x)
{
	if (ix == 1)
		ft_putchar('\\');
	else if (ix == x)
		ft_putchar('/');
	else
		ft_putchar('*');
}

void	line1(int ix, int x)
{
	if (ix == 1)
		ft_putchar('/');
	else if (ix == x)
		ft_putchar('\\');
	else
		ft_putchar('*');
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
