#ifndef __FT_H_
# define __FT_H_
# include <unistd.h>
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_swap(int *a, int *b);
int		ft_strcmp(const char *s1, const char *s2);
int     ft_strlen(char *str);
char	*ft_concat_params(int argc, char **argv);
#endif

