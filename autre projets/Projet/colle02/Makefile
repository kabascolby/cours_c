# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/19 06:02:38 by lamkaba2          #+#    #+#              #
#    Updated: 2017/12/12 23:16:32 by lkaba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2
FLAG = -Wall -Werror -Wextra
FILES = srcs/colle00.c srcs/ft_atoi.c srcs/ft_put.c srcs/ft_str_is_numeric.c srcs/ft_strcmp.c srcs/generate_colle00.c

all: $(NAME)

$(NAME):
	gcc $(FLAG) -o colle-2 colle_2.c $(FILES)

clean:
	/bin/rm -f colle-2

fclean: clean

re: fclean all
