# **************************************************************************** #ME
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdidier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/23 06:11:12 by rdidier           #+#    #+#              #
#    Updated: 2015/09/24 10:48:38 by lamkaba2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	bsq

SOURCES	=	./src/main.c \
			./src/algo_bsq.c \
			./src/display.c \
			./src/grid.c \
			./src/struct_gestion.c \
			./src/bsq.c \
			./src/input.c \
			./src/read.c

OBJECTS	=	./main.o \
			./algo_bsq.o \
			./display.o \
			./grid.o \
			./struct_gestion.o \
			./bsq.o \
			./input.o \
			./read.o

FLAGS	=	-Werror -Wall -Wextra

HEADER	=	./header

$(NAME)		:	all

all			:
				gcc -c $(FLAGS) $(SOURCES) -I $(HEADER) 
				gcc -o $(NAME) $(FLAGS) $(OBJECTS)

clean		: 
				rm -rf $(OBJECTS)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean \
				all

boom		:	re \
				clean
				clear


