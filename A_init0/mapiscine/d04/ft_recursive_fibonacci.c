#include <stdio.h>

int ft_recursive_fibonaci(int index)
{
	if (index <= 1)
		return index;
	else
		return(ft_recursive_fibonaci(index - 1) + ft_recursive_fibonaci(index - 2)); 
}

int main(void)
{
	printf("%d\n", ft_recursive_fibonaci(10));
	return 0;
}
