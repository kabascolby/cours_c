/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 10:45:47 by lamkaba2          #+#    #+#             */
/*   Updated: 2017/12/12 23:16:32 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_uns	read_file(char *file)
{
	int		fd;

	fd = open(file, O_DIRECTORY);
	if (fd >= 0)
		return (1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	if (prepare_read(&fd) == 1)
		return (1);
	return (0);
}

t_uns	read_stdin(void)
{
	int		fd;

	fd = 0;
	if (prepare_read(&fd))
		return (1);
	return (0);
}
