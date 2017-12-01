/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:05:36 by lkaba             #+#    #+#             */
/*   Updated: 2017/11/22 16:05:37 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_striter(char *c, void (*f)(char *))
{
    while (*c)
    {
        (*f)(c);
        c++;
    }
}
