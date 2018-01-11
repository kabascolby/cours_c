char *ft_strstr(char *str, char *to_find)
{
  char *a;
	char *b;

	if(!*to_find)
		return (str);
	b = to_find;
	while(*str)
	{
		if(*str == *b)
		{
			a = str;
			while(*a == *b || !*b)
			{
				if(!*b)
					return (str);
				a++;
				b++;
			}
			b = to_find;
		}
		str++;
	}
	return (str);
}