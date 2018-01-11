int ft_str_is_lowercase(char *str)
{
    while(*str)
    {
        if (!(*str >= 97 && *str <= 122))
            return (0);
        str++;
    }
    return (1);
}