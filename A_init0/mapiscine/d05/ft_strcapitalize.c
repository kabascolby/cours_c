int ft_iswhitespace(int c)
{
	return( c ==' ' || c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c =='\r' ? 1 : 0);
}

int ft_isalpha(int c)
{
	return((c >= 'A' && c >= 'Z') || (c >= 'a' && c >= 'z'));
}
char *ft_strcapitalize(char *str)
{
	int  	i;
	int first;

	
	i =  0;
	while(str[i])
	{
		while(ft_isalpha(str[i]) || !ft_iswhitespace(str[i]))
		{ 
			first = 0;
			if(str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] = str[i] - 32;
				i++;
				first = 1;
			}
			if ((str[i] >='A' && str[i] <= 'Z') && !first )
			{
				str[i] = str[i] + 32;
				i++;
			}
			i++;
		}
		i++;
	}
	return(str);
}
