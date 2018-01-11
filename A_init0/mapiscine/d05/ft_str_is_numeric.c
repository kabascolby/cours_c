int ft_isdigit(int c)
{
	return(c >= '0' && c <= '9');
}

int ft_str_is_numeric(char *str)
{
    while(*str)
    {
        if(!ft_isdigit(*str++))
            return(0);
    }
    return(1);
}