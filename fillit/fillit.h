
#ifdef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>

#define BUFF_SIZE 524

int				ft_read(int fd, char buff[]);
tris			*ft_parme_tetriminos(char buff[], int shift, int ret);
int				ft_solve(t_tetris **alst, t_board *b);
int				ft_nothing_to_read(void);
int				ft_bad_size(void);
int				ft_bad_format_file(void);
int				ft_bad_format_tetriminos(void);

#endif
