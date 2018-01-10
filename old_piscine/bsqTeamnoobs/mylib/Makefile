# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpierce <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/25 10:27:14 by bpierce           #+#    #+#              #
#    Updated: 2017/04/25 13:12:04 by bpierce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

C_FIL = ft_putchar \
		ft_putstr \
		ft_putnbr \
		ft_atoi
C_LOC = ./src/
C_PRE = $(addprefix $(C_LOC), $(C_FIL))
C_SRC = $(addsuffix .c, $(C_PRE))


O_LOC = ./obj/
O_PRE = $(addprefix $(O_LOC), $(C_FIL))
O_SRC = $(addsuffix .o, $(O_PRE))


H_SRC = inc


all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror -I $(H_SRC) $(C_SRC)
	mv *.o $(O_LOC)
	ar rcs $(NAME) $(O_SRC)
	mv $(NAME) ../

clean:
	/bin/rm -f $(O_SRC)

fclean: clean
	/bin/rm -f ../$(NAME)

re: fclean all
