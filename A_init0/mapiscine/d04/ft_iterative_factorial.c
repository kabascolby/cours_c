#include <unistd.h>
#include <stdio.h>
int		ft_iterative_factorial(int nb)
{
	int i;
	int facto;

	if (nb > 0 && nb < 13)
	{
		facto = nb;
		i = 0;
		while(++i < nb)
			facto = facto * (nb - i);
		return (facto);
	}
	else
		return(nb == 0 ? 1 : 0);
}

int main(void)
{
	printf("%d\n", ft_iterative_factorial(3));
	return 0;
}

