#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# define  GNL(x, y) get_next_line(x, y)
typedef struct s_piece
{
	char p[4][4];
	char c;
	struct s_piece *next;
} t_piece;

int		ft_error(int n);
#endif
