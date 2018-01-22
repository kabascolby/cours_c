int		is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0) // or alternatively (!(n % 2))
		n /= 2;
	return ((n == 1) ? 1 : 0); // equivalent to : if (n == 1) return 1; else return (0);
}

/* int		is_power_of_2(unsigned int n)
{
    return (n > 0 && !(n & (n - 1)));
} */