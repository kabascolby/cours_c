#include <stdio.h>

int  ft_countword(char *str, char s)
{
	int i;
	int word;

	i = 0;
	word  = 0;
	while(str[i] && str[i] == s)
		i++;
	while (str[i])
	{
		while(str[i] && str[i] != s)
			i++;
		word++;
		while(str[i] && str[i] == s)
			i++;
	}
	return (word);	
}

int main(void)
{
	printf("%d\n", ft_countword("   lamine kaba  Marietou   Bah  ", ' '));
	return 0;
}
