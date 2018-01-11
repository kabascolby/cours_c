int ft_isalpha(int c)
{
	return((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int ft_str_is_alpha(char *str)
{
    while(*str))
    {
        if(!ft_isalpha(*str))
            return(0);
        str++;
    }
    return (1);
}