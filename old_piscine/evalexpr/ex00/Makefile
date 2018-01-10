# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 13:11:12 by lkaba             #+#    #+#              #
#    Updated: 2017/11/30 13:11:14 by lkaba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC = gcc

NAME = eval_expr

SRC = print.c main.c string_manip.c str_int.c calcul.c lol.c

HEADER = header.h

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	/bin/rm -f main.o

fclean: clean
	/bin/rm -f $(NAME)
