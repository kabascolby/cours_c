#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int	*ret;
	int i;

	i = 0;
	ret = (int*)malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		ret[i] = min;
		min++;
		i++;
	}
	*range = ret;
	return (i);
}
