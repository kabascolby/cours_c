#include <stdio.h>

int 	ft_recursive_factorial(int nb)
{
	if( nb > 0 && nb < 13)
		return (nb  * ft_recursive_factorial(nb - 1));
	return (nb == 0 ? 1 : 0);
}

int main(void)
{
	printf("%d\n", ft_recursive_factorial(11));
	return 0;
}
