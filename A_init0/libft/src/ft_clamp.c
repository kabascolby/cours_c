/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:09:59 by lkaba             #+#    #+#             */
/*   Updated: 2017/11/22 16:09:59 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_clamp(double i, double a, double b)
{
	if (i < a)
		i = a;
	if (i > b)
		i = b;
	return (i);
}