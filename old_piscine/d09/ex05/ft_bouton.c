int		ft_bouton(int i, int j, int k)
{
	if ((i >= j && i <= k) || (i <= j && i >= k))
		return (i);
	if ((j >= i && j <= k) || (j <= i && j >= k))
		return (j);
	if ((k >= j && k <= i) || (k <= j && k >= i))
		return (k);
	return (0);
}
