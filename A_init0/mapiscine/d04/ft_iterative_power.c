#include <stdio.h>


int 	ft_iterative_power(int nb,int  power)
{
	int i;
	i = 0;
	if (power == 1)
		return nb;
	else
	{
		while(++i < power)
			nb = nb * (nb*i);
	}
	return nb;
}

int main(void)
{
	printf("%d\n", ft_iterative_power(5, 2));
	return 0;
}
