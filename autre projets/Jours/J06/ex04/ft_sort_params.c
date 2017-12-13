/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 02:08:30 by lamkaba2          #+#    #+#             */
/*   Updated: 2017/12/12 23:16:32 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_sort_ascii(char **val, int nb)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < (nb - 1))
	{
		j = 0;
		while (val[i][j] == val[i + 1][j])
			j++;
		if (val[i][j] > val[i + 1][j])
		{
			tmp = val[i];
			val[i] = val[i + 1];
			val[i + 1] = tmp;
			i = 0;
		}
		i++;
	}
}

void	ft_print(char **val, int nb)
{
	int i;
	int y;

	if (nb > 1)
	{
		i = 1;
		while (i < nb)
		{
			y = 0;
			while (val[i][y] != '\0')
			{
				ft_putchar(val[i][y]);
				y++;
			}
			ft_putchar('\n');
			i++;
		}
	}
}

int		main(int argc, char **argv)
{
	ft_sort_ascii(argv, argc);
	ft_print(argv, argc);
	return (0);
}
