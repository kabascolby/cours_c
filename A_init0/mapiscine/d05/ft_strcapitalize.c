int ft_isalpha(int c)
{
	return((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int ft_isdigit(int c)
{
	return(c >= '0'  && c <= '9');
}
char *ft_strcapitalize(char *str)
{
	int i;
	int space;
	char c;

	i = 0;
	while (str[i])
	{
		space = 1;
		if(i == 0)
			c = ';';
		else
			c = str[i - 1];
		if (ft_isalpha(c) || ft_isdigit(c))
			space = 0;
		if ((space == 1) && (str[i] >= 'a' && str[i] <= 'z'))
			str[i] = str[i] - 32;
		if ((space == 0) && (str[i] >= 'A' && str[i] <= 'Z'))
			str[i] = (str[i] - 'A') + 'a'; /*meme chose que str[i] + 32 */ 
		i++;
	}
	return (str);
}
