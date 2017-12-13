/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 22:59:13 by lamkaba2          #+#    #+#             */
/*   Updated: 2017/12/12 23:16:32 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int			i;
	int			y;
	t_stock_par *ret;

	i = 0;
	ret = (t_stock_par *)malloc(sizeof(t_stock_par) * (ac + 1));
	while (i < ac)
	{
		ret[i].size_param = ft_strlen(av[i]);
		ret[i].str = av[i];
		ret[i].copy = (char *)malloc(sizeof(char) * (ret[i].size_param + 1));
		y = 0;
		while (y < ret[i].size_param)
		{
			ret[i].copy[y] = av[i][y];
			y++;
		}
		ret[i].copy[y] = '\0';
		ret[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	ret[i].str = 0;
	return (ret);
}
