char *ft_strlowcase(char *str)
{
	int 	i;

	i  =  0;
	while(str[i++])
	{
		if (str[i] >= 'A' && str[i] >= 'Z'
				str[i] = str[i] + 32;
	}
	return (str);
}

/* une autre version qui utilisera une fonction utile pour le future
 *
 * int ft_tolower(int c)
 * {
 * 		if(c >= 'A' && c <= 'Z')
 * 			return((c - 'A') + 'a');
 * 		return(c);
 * }
 *
 * char *ft_strlowcase(char *str)
 * {
 * 		int 	i;
 *
 * 		i = 0;
 * 		while(str[i++])
 * 			str[i] = ft_tolower(str[i]);
 * 		return(str);
 * }
 */
