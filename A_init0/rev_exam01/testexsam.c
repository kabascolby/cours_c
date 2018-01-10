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

int ft_atoi(char *str)
{
    int i;
    int total;
    int nb;
    total = str[0] - '0';
    i = 1;
    while(str[i])
    {
        total *= 10;
        nb = str[i] - '0';
        total += nb;
        i++;
    }
    return(total);
}

void tab_mul(char *str)
{
    int i;
    int nb;
    nb = ft_atoi(str);
    i = 1;
    while(i < 10)
    {
        ft_putnbr(i);
        write(1, " x ", 3);
        ft_putnbr(nb);
        write(1, " = ", 3);
        ft_putnbr(nb * i);
        write(1, "\n", 1);
        i++;
    }
}
int main(int argc, char **argv)
{
    if(argc > 1)
        tab_mul(argv[1]);
    write(1, "\n", 1);
    return 0;
}