/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <laminekaba@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 19:13:24 by lkaba             #+#    #+#             */
/*   Updated: 2017/04/18 19:13:28 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

NAME = ft_display_file

FILE = ./main.c
OBJECT = ./main.o
FLAGS = -Wall -Wextra -Werror

all: $(NAME)
	
$(NAME):
	gcc -c $(FILE)
	gcc $(FLAGS) -o $(NAME) $(OBJECT)

clean:
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)
