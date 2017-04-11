#include <unistd.h>

int		ft_putchar(char c)

void	ft_putnbr(int nb)
{
	int	i;
	int	size;

	size = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	i = nb;
	while ((i /= 10) > 0)
		size *= 10;
	i = nb;
	while (size)
	{
		ft_putchar((char)((i / size)) + 48);
		i %= size;
		size /= 10;
	}
}