
/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions: 
--------------------------------------------------------------------------------

Reproduisez à l'identique le comportement de la fonction strcpy (man strcpy).

Votre fonction devra être prototypée de la façon suivante :

char    *ft_strcpy(char *s1, char *s2);
*/

#include <unistd.h>
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

char *ft_strcpy(char *dest, char *src);

int main(void)
{
	char dest[100];
	char src[40];
	ft_strcpy(src, "Je test cette merde");
	ft_strcpy(dest, src);
	printf("%s\n", dest);
	return (0);
}
