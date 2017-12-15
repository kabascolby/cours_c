/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/21 16:08:13 by lamkaba2          #+#    #+#             */
/*   Updated: 2017/12/13 22:31:59 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "ft_print.h"
# include "ft_string.h"
# include "ft_list.h"
# include "ft_square.h"

char	*jp_ltos(int len, t_list *list);
char	*jp_read_standard(void);
char	*jp_openfile(char *filename);
void	jp_check(char *str);

#endif
