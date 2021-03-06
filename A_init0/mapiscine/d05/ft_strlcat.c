int ft_strlen(char *str)
{
    int i;
    i = 0;
    while(str[i])
    {
        i++;
    }
    return (i);
}
unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	i = 0;
	j = 0;

	while(i < size && dest[i])
		i++;
	while((i + j + 1) < size && src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < size)
		dest[i + j] = '\0';
	return (i + ft_strlen(src));

}