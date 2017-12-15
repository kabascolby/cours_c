/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/22 12:37:30 by lamkaba2          #+#    #+#             */
/*   Updated: 2017/12/13 22:31:59 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JP_LIST_H
# define JP_LIST_H

# include <stdlib.h>
# include "ft_string.h"

typedef	struct		s_list
{
	struct s_list	*next;
	char			str[129];
}					t_list;

t_list				*jp_create_elem(char *str);
void				jp_list_push_back(t_list **begin_list, char *str);

#endif
