//#include <stdio.h>

int		ft_djamal(int i, int j, int k)
{
	if (i >= j && i >= k)
	{
		if (j >= k)
			return (j);
		else
			return (k);
	}
	if (j >= i && j >= k)
	{
		if (i >= k)
			return (i);
		else
			return (k);
	}
	if (k >= j && k >= i)
	{
		if (j >= i)
			return (j);
		else
			return (i);
	}
	return(i);
}

// int		main(void)
// {
// 	printf("%d\n", ft_djamal(1, 3, 1));
// 	return(0);
// }