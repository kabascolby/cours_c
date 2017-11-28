	int		ft_atoi(char *str)
{
	int		negative;
	int		value;

	negative = 0;
	value = 0;
	while ((*str == ' ') || (*str == '\t') || (*str == '\n')
		|| (*str == '\v') || (*str == '\f') || (*str == '\r'))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		negative = 1;
		str++;
	}
	while ((*str <= '9') && (*str >= '0'))
	{
		value = (value * 10) - (*str - '0');
		str++;
	}
	if (!negative)
		value = -value;
	return (value);
}

#include <stdio.h>

int main()
{
	int i;

	i = ft_atoi("-0");
	printf("%d", i);
	return 0;
}