#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	*ret;
	int count;
	int i;

	if (min >= max)
	{
		ret = 0;
		return (ret);
	}
	else
	{
		count = max - min;
		ret = (int*)malloc(sizeof(*ret) * count);
		i = 0;
		while (min < max)
		{
			ret[i] = min;
			min++;
			i++;
		}
	}
	return (ret);
}
