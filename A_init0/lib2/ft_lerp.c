/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lerp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:11:03 by lkaba             #+#    #+#             */
/*   Updated: 2017/11/22 16:11:04 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_lerp(double first, double second, double p)
{
	if (first == second)
		return (first);
	return (first + (second - first) * p);
}
