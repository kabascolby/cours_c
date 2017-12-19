#include <unistd.h>
#include <stdio.h>

int	ft_iswhitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
			|| c == '\r');
}

int 	ft_isdigit(int n)
{
	return (n >= '0' && n <= '9');
}

int 	ft_atoi(char *str)
{
	int 	total;
	char  neg;

	total = 0;

	while(ft_iswhitespace(*str))
		str++;

	neg = (*str == '-');
	if (*str == '-' || *str == '+')
		str++;

	while(ft_isdigit(*str))
	{
		total = total * 10 + (*str - 48);
		str++;
	}
	return (neg ? -total : total);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		printf("%d", ft_atoi(" 8974s "));
	else
		write(1, "\n", 1);
	return (0);
}
