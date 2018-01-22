#include <stdio.h>
#include <stdlib.h>

int		ft_ultimate_range(int **r, int min, int max)
{
	int		i;

	if (min >= max && !(*r = NULL))
		return (0);
	if (!(r[0] = (int *)malloc(sizeof(int) * (max - min))))
		return (0);
	i = -1;
	while (min < max)
		(*r)[++i] = min++;
	return (i + 1);
}

int		main(int argc, char **argv)
{
	int		*t;
	int		i;

	printf("%d\n", ft_ultimate_range(&t, atoi(argv[1]), atoi(argv[2])));
	i = -1;
	while (++i < atoi(argv[2]) - atoi(argv[1]))
		printf("%d ", t[i]);
	return (1);
}
