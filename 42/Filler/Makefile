# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/02 02:27:45 by tadey             #+#    #+#              #
#    Updated: 2018/04/09 14:41:33 by lkaba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lkaba.filler
FLAGS = -Wall -Wextra -Werror
FILES = $(wildcard *.c)
OFILES = $(patsubst %.c, %.o, $(FILES))
LIBFT = libft.a

all: $(NAME)


$(NAME): $(LIBFT) $(OFILES)
	@gcc $(FLAGS) $(OFILES) libft/$(LIBFT) -o $@

$(LIBFT):
	@make -C libft

%.o: %.c
	gcc $(FLAGS) -c $<

clean:
	@/bin/rm -f $(FILES:.c=.o)
	@make clean -C libft

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft

re: fclean all
