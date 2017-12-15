#include <stdio.h>

int ft_recursive_power(int nb, int power)
{
	if (power == 1)
		return nb;
	else
		return(nb * ft_recursive_power(nb, power - 1));
}
int main(void)
{
	printf("%d\n",ft_recursive_power(8, 10));
	return 0;
}
