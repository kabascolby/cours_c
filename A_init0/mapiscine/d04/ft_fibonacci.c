#include <stdio.h>

int  ft_fibonacci(int index)
{
	int f1;
	int f2;
	int f;
	int i;
	
	if (index <= 1)
		return index;
	f1 = 0;
	f2 = 1;
	i = 2;
	while(i <= index)
	{
		f= f2 + f1;
		f1 = f2;
		f2 = f;
		i++;
	}

	return f;
}

int main(void)
{
	printf("%d\n", ft_fibonacci(10));
	return 0;
}
