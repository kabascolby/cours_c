#include <unistd.h>

int			ft_strcmp(char *s1, char *s2, char *s3, char *s4)
{
	unsigned char	s1_value;
	unsigned char	s2_value;
    unsigned char	s3_value;
	unsigned char	s4_value;
	int				i;

	i = 0;
	while (((s1[i] == s2[i]) && (s1[i] == s3[i]) && (s1[i] == s4[i])) && (s1[i] != 0))
		i++;
	s1_value = s1[i];
	s2_value = s2[i];
    s3_value = s3[i];
    s4_value = s4[i];
	return (s1_value - s2_value - s3_value -s4_value );
}


void	print_rs(char *str, int col, int row)
{
	ft_putchar('[');
	ft_putstr(str);
	ft_putstr("] [");
	ft_putnbr(col);
	ft_putstr("] [");
	ft_putnbr(row);
	ft_putchar(']');

}