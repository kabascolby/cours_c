char *ft_strncpy(char *dest, char *src, unsigned int n)
{
    int i;

    i = 0;
    while (n > 0 && *src)
    {
        dest[i] = *src++;
        i++;
        n--;
    }
    dest[i] = '\0';
    return(dest);
}