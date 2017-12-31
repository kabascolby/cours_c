char 	*ft_strcpy(char *dest, const char *src)
{
	int 	i;

	i = 0;
	while (src[i])
		*dest++ = src[i++];
	dest[i] = '\0';
	return (dest);
}

