FILES = ft_countwords.c\
		ft_putstr.c\
		ft_strrchr.c\
		ft_strcmp.c\
		ft_strlcat.c\
		ft_memcpy.c\
		ft_lstat.c\
		ft_memmove.c\
		ft_min.c\
		ft_strsplit.c\
		ft_strncpy.c\
		ft_lstmap.c\
		ft_lstadd.c\
		ft_striter.c\
		ft_strstr.c\
		ft_isdigit.c\
		ft_putnbr.c\
		ft_lstremove.c\
		ft_iswhitespace.c\
		ft_memccpy.c\
		ft_max.c\
		ft_strdel.c\
		ft_memchr.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_putstr_fd.c\
		ft_lstiter.c\
		ft_lstrev.c\
		ft_toupper.c\
		ft_lstdelone.c\
		ft_strcpy.c\
		ft_strdup.c\
		ft_lstnew.c\
		ft_putnbr_fd.c\
		ft_striteri.c\
		ft_putendl_fd.c\
		ft_strmap.c\
		ft_memdel.c\
		ft_strnstr.c\
		ft_putchar.c\
		ft_isascii.c\
		ft_strlen.c\
		ft_strnew.c\
		ft_strsub.c\
		ft_putendl.c\
		ft_memalloc.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_itoa.c\
		ft_memcmp.c\
		ft_strequ.c\
		ft_strtrim.c\
		ft_putchar_fd.c\
		ft_memset.c\
		ft_isalpha.c\
		ft_strcat.c\
		ft_tolower.c\
		ft_strnequ.c\
		ft_strjoin.c\
		ft_atoi.c\
		ft_ilerp.c\
		ft_strclr.c\
		ft_lstcount.c\
		ft_isprint.c\
		ft_strmapi.c\
		ft_lstdel.c\
		ft_abs.c\
		ft_strchr.c\
		get_next_line.c\
		ft_print_words_tables.c\
		ft_debug.c

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

$(NAME):
	@gcc -c $(FILES) $(FLAGS)
	@ar rc $(NAME) $(FILES:.c=.o)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@/bin/rm -f $(FILES:.c=.o)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
