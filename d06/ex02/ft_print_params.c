void	ft_putchar(char c);

int		main(int argc, char *argv[])
{
	int i;
	int y;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			y = 0;
			while (argv[i][y] != '\0')
			{
				ft_putchar(argv[i][y]);
				y++;
			}
			ft_putchar('\n');
			i++;
		}
	}
}
