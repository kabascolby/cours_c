/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sadasdad.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 09:11:07 by lamkaba2          #+#    #+#             */
/*   Updated: 2017/12/12 23:16:32 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SADASDAD_H
# define __SADASDAD_H

# include "ft_door.h"
# include <unistd.h>

# define TRUE	1
# define FALSE	0
# define OPEN	1
# define CLOSE	0
# define EXIT_SUCCESS	0

typedef	int		t_bool;
typedef	struct	s_door
{
	ft_bool state;
}				t_door;

#endif
