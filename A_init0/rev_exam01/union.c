#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

char	*ft_charcat(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	str[i++] = c;
	str[i] = '\0';
	return (str);
}
		
int		ft_strcarchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	ft_union(char *s1, char *s2)
{
	char	match[500];

	while (*s1)
	{
		if (!(ft_strcarchr(match, *s1)))
			ft_charcat(match, *s1);
		s1++;
	}
	
	while (*s2)
	{
		if(!(ft_strcarchr(match, *s2)))
			ft_charcat(match, *s2);
		s2++;
	}
	ft_putstr(match);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}

/* char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
} */