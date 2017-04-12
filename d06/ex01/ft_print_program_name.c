void	ft_putchar(char c);

int		main(int argc, char *argv[])
{
	int i;

	if (argc > 0)
	{
		i = 0;
		while (argv[0][i] != '\0')
		{
			ft_putchar(argv[0][i]);
			i++;
		}
	}
	return (0);
}
