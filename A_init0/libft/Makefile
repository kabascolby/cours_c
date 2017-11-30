# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 13:27:47 by lkaba             #+#    #+#              #
#    Updated: 2017/11/30 14:08:16 by lkaba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include libft.mk

SRC_DIR	= ./sources
INC_DIR	= ./includes
OBJ_DIR	= ./obj

RAW_SRC	:= $(shell find $(SRC_DIR) -type f | grep -E "\.c$$")
RAW_DIRS:= $(shell find $(SRC_DIR) -type d -mindepth 1)
SRCDIRS = $(RAW_DIRS:./src/%=%)
SRC		= $(RAW_SRC:./src/%=%)
OBJ		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -pedantic -std=c99

all: $(OBJ_DIR) $(FT_NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(addprefix $(OBJ_DIR)/,$(SRCDIRS))

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(FT_INC) -o $@ -c $<

$(FT_NAME): $(OBJ)
	ar rc $(FT_NAME) $(OBJ)
	ranlib $(FT_NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(FT_NAME)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory
