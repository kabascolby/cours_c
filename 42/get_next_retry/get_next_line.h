/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 08:37:39 by lkaba             #+#    #+#             */
/*   Updated: 2018/01/26 19:45:16 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 1

int	get_next_line(int fd, char **line);

#endif
