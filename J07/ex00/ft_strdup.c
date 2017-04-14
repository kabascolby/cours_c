#include <stdlib.h>

char	ft_strlen(char *str)
{
	int nb;

	nb = 0;
	while (str[nb] != '\0')
	{
		nb++;
	}
	return (nb);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		taille_src;
	int		i;

	i = 0;
	taille_src = ft_strlen(src);
	str = (char*)malloc(sizeof(*str) * (taille_src + 1));
	while (i < taille_src)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
