# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tadey <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 22:31:44 by tadey             #+#    #+#              #
#    Updated: 2018/02/05 22:22:20 by lkaba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRC = $(wildcard *.c)
OFILES = $(patsubst %.c, %.o, $(SRC))
all: $(NAME)

$(NAME): $(OFILES)
	@echo $(OFILES)
	@ar rc $@ $(OFILES)
	@ranlib $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c $<

clean:
	@rm -f $(SRC:.c=.o)

fclean: clean
	@rm -f $(NAME)

re: fclean all
