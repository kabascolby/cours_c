#include <unistd.h>
#include <stdio.h>

char 	*ft_strncat(char *dest , char *src, size_t nb)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while(dest[i])
		i++;
	while(j < nb && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return(dest);
}