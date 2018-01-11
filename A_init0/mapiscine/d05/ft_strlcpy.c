int ft_strlen(char *str);

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    unsigned i;

    while (*src && (i + 1 < size))
    {
        dest[i++] = *src;
    }
    dest[i] = '\0';
    return (i + ft_strlen(src));
}
