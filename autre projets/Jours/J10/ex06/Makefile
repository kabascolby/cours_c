# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/15 20:02:56 by lamkaba2          #+#    #+#              #
#    Updated: 2017/12/12 23:16:33 by lkaba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./srcs/ft_op.c ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_atoi.c ./srcs/ft_putnbr.c 
OBJECT = ./ft_op.o ./ft_putchar.o ./ft_putstr.o ./ft_atoi.o ./ft_putnbr.o

FLAGS = -Wall -Wextra -Werror

all:
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) -o do-op main.c $(SRC)

clean:
	/bin/rm -f $(OBJECT)
