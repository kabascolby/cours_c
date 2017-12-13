/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/07 10:22:54 by lamkaba2          #+#    #+#             */
/*   Updated: 2017/12/12 23:15:39 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int resultat;

	if (nb > 12 || nb < 0)
		return (0);
	resultat = 1;
	while (nb > 0)
	{
		resultat = resultat * nb;
		nb--;
	}
	return (resultat);
}
