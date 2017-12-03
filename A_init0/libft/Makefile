
#FILES = ft_putstr.c \
		ft_putchar.c

FILES = *.c

SRC_DIR	= ./sources
INC_DIR	= ./includes
OBJ_DIR	= ./obj
NAME = libft.a

SRC		= $(addprefix $(SRC_DIR)/, $(FILES))
OBJ		= $(addprefix $(OBJ_DIR)/,$(FILES:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME) #$(OBJ_DIR) $(NAME)

#$(OBJ_DIR):
#	mkdir -p $(OBJ_DIR)

#$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
#	$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME): #$(OBJ)
	mkdir $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $(SRC)
	mv *.o $(OBJ_DIR)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all