# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/19 06:02:38 by lamkaba2          #+#    #+#              #
#    Updated: 2017/12/12 23:16:33 by lkaba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr
FLAG = -Wall -Werror -Wextra
FILES = srcs/calculate.c srcs/eval_expr.c srcs/eval_to_btree.c srcs/node.c srcs/str_func.c srcs/btree_create_node.c

all: $(NAME)

$(NAME):
	gcc $(FLAG) -o $(NAME) main.c $(FILES)

clean:
	/bin/rm -f eval_expr

fclean: clean

re: fclean all
