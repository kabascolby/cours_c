#include <unistd.h>

int		ft_verif_char(char *str, char c, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

/* void	ft_inter(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i])
	{
		if (ft_verif_char(s1, s1[i], i) == 1)
		{
			j = 0;
			while (s2[j])
			{
				if (s2[j] == s1[i])
				{
					write(1, &s1[i], 1);
					break ;
				}
				j++;
			}
		}
		i++;
	}
} */


void ft_inter(char *s1, char *s2)
{
	int i;
	int j;

	i = -1;
	j = -1;

	int tab[256] = {0};

	while(s1[++i])
	{
		 j = -1;
		while(s2[++j])
			if(!(tab[(int)s1[i]]) && s1[i] == s2[j])
			{
				write(1, &(s1[i]), 1);
				tab[(int)s1[i]] = 1;
			}		
	}

}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}