#include <unistd.h>

void	ft_putaddr_fd(void *str, int fd)
{
	long int			div;
	char				temp;
	unsigned long int	n;

	n = (unsigned long int)str;
	div = 16;
	write(fd, "0x", 2);
	while (n / div >= 16)
		div *= 16;
	while (div > 0)
	{
		temp = '0' + n / div;
		if (temp > '9')
		{
			temp += 39;
			write(fd, &temp, 1);
		}
		else
			write(fd, &temp, 1);
		n %= div;
		div /= 16;
	}
}

void	ft_putaddr(void *str)
{
	ft_putaddr_fd(str, 1);
}

int main(int argc, char *argv[])
{
	int b;
	int *add;

	b = 42;
	add = &b;
	ft_putaddr(add);
	write(1, "\n", 1);
	ft_putaddr();
	
	return 0;
}