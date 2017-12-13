/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 17:21:39 by lamkaba2          #+#    #+#             */
/*   Updated: 2017/12/12 23:16:33 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(void)
{
	char number;

	number = '9';
	while (number >= '0')
	{
		write(1, &number, 1);
		number--;
	}
	write(1, "\n", 1);
	return (0);
}
