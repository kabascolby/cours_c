/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/04 15:25:13 by lamkaba2          #+#    #+#             */
/*   Updated: 2017/12/13 22:31:59 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);
void	jp_putchar(char x, char y, char z);

void	ft_print_comb2(void)
{
	char n;
	char i;
	char a;
	char e;
	
	n = '0';
	while (n <= '9')
	{
		i = n + 1;
		while (i <= '8')
		{
			a = i + 1;
			jp_putchar(n, i, ' ');
			while (a <= '9')
			{
				e = a + 1;
				while (e <= '9')
				{
					jp_putchar(a, e, ',');
					e++;
				}
				a++;
			}
			i++;
		}
		n++;
	}
}

void jp_putchar(char x, char y, char z)
{
	ft_putchar(x);
	ft_putchar(y);
	ft_putchar(z);
}
