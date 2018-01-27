/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 00:59:44 by lkaba             #+#    #+#             */
/*   Updated: 2018/01/27 02:13:59 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int main(int argc, char **argv)
{
	if (argc  !== 2)
		return (0);
	int l;
	if(!(l = open(argv[1], O_RDONLY) || *(argv[1]) || !argv[1])
			return (0);
	
	if(!(l = read(l, buff, BUFF_SIZE) || l == -1)
		return (0);

	return (0);
}
