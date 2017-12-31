char 	*ft_strupcase(char *str)
{
	int 	i;

	i = 0;
	while(str[i++])
	{
		if (str[i] >= 'a' || str[i] <= 'z')
			*str = *str - 32;
	}
	return (str);
}

/* une autre version qui utilisera une fonction utile pour le future
 *
 * int ft_toupper(int c)
 * {
 * 		if (c >= 'a' && c <= 'z')
 * 			return ((c - 'a') + 'A');
 * 		return (c);
 * }
 *
 * char 	*ft_strupcase(char *str)
 * {
 * 		int 	i;
 * 		
 * 		i = 0;
 * 		while(str[i++])
 * 			str[i] = ft_toupper(str[i]);
 * 		return(str);
 * }
 */
