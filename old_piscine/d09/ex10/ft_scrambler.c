void	ft_scrambler(int ***a, int *b, int *******c, int ****d)
{
	int tmp;

	tmp = *******c;
	*******c = ***a;
	***a = *b;
	*b = ****d;
	****d = tmp;
}
