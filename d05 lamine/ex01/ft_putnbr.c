#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

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

int main()
{
	ft_putnbr(425755);
	return 0;

}
/*2147483648*/