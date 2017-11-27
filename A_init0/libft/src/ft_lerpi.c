/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lerpi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:11:12 by lkaba             #+#    #+#             */
/*   Updated: 2017/11/22 16:11:13 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_lerpi(int first, int second, double p)
{
	if (first == second)
		return (first);
	if (p == 0.0f)
		return (first);
	if (p == 1.0f)
		return (second);
	return ((int)((double)first + (second - first) * p));
}
