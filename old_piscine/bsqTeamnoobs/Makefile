# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpierce <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/25 10:21:00 by bpierce           #+#    #+#              #
#    Updated: 2017/04/26 20:43:55 by bpierce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

C_FILES = main info cell_setter algor_the_mighty new_map print_new_map \
		  check_chars1 check_chars2 check_chars3
C_LOC = ./src/
C_PRE = $(addprefix $(C_LOC), $(C_FILES))
C_SRC = $(addsuffix .c, $(C_PRE))

H_SRC = -I/inc/bsq.h

GCC = gcc -Wall -Wextra -Werror -o

LIB = -L. -lft

all: $(NAME)

$(NAME):
	cd mylib && make
	gcc -Wall -Wextra -Werror $(H_SRC) $(C_SRC) $(LIB) -o $(NAME)

clean:
	cd mylib && make clean

fclean: clean
	cd mylib && make fclean
	/bin/rm -f $(NAME)

re: fclean all
