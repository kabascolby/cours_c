#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int ft_putstr(char *str)
{
	while(*str)
	{
		ft_putchar(*str);
		str++;
	}
	return 0;
}

void ft_putnbr(int n)
{
	if ((n >= 0) && (n < 10))
			ft_putchar(n + '0');
	else if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * (-1));
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int main()
	{
		ft_putnbr(-2147483648);	
		return 0;
	}
/*2147483648*/


/*void	ft_putnbr(int nb)
{
	int	i;
	int	size;

	size = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if(nb == -2147483648)
	{
		ft_putstr("2147483648");
		return;
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

 void ft_putnbr(int nbr)
{

	int size;

	size = 1;
	{
		if(nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		if(nbr == -2147483648)
		{
			ft_putstr("2147483648");
			return;
		}

	while((nbr /=10) > 0)
		size *=10;
	}
		while (size)
		{
			ft_putchar((char)((nbr / size)) + 48);
			nbr %= size;
			size /= 10;
		}
	}
	
	FT_PUTNBR VERSION 2
*/