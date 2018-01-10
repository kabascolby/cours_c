#include <stdlib.h>
#include <ft_ultimator.h>

void	ft_destroy(char ***factory)
{
	int i;
	int y;

	i = 0;
	while (factory[i] != 0)
	{
		y = 0;
		while (factory[i][y] != 0)
		{
			free(factory[i][y]);
			y++;
		}
		free(factory[i]);
		i++;
	}
	free(factory);
}
