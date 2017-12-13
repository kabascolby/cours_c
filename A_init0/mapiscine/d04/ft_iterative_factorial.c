#include <stdio.h>

/*int ft_iterative_factorial(int nb)
{
	int i;
	int facto;

	if (nb > 0 && nb < 13)
	{
		facto = nb;
		i = 0;
		while (++i < nb)
			facto = facto * (nb -i);
		return facto;
	}
	else
		return(nb == 0 ? 1 : 0);
}

 Deuxieme methode plus longue mais un peu plus detaille*/
 int 	ft_iterative_factorial(int nb)
 {
 	int i;
	int facto;

	if	(nb > 0 && nb < 13) 
	{
		facto = 1;
		i = 1;
		while(i <= nb)
		{
			facto = facto * i;
			i++;
		}
		return (facto);
	}
	else
	return(nb == 0 ? 1 : 0);
 }

int main(void)
{
	printf("%d\n", ft_iterative_factorial(3));
	return (0);
}
