char	*ft_rot42(char *str)
{
	int		i;
	int		y;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		y = 0;
		while (y < 16)
		{
			c = str[i];
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			{
				if (str[i] == 'z')
					str[i] = 'a';
				else if (str[i] == 'Z')
					str[i] = 'A';
				else
					str[i]++;
			}
			y++;
		}
		i++;
	}
	return (str);
}
