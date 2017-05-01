/*Écrire un programme qui prend une chaîne de caractères en paramètre, et qui
affiche cette chaîne avec exactement trois espaces entre chaque mot, sans
espaces ou tabulations ni au début ni à la fin de la chaîne, suivie d'un '\n'.

On appelle "mot" une portion de chaîne de caractères délimitée soit par des
espaces et/ou des tabulations, soit par le début / fin de la chaîne.

Si le nombre de paramètres transmis est différent de 1, ou s'il n'y a aucun mot
à afficher, le programme affiche '\n'.

Exemple:

$> ./expand_str "vous   voyez   c'est   facile   d'afficher   la   meme   chose" | cat -e
vous   voyez   c'est   facile   d'afficher   la   meme   chose$
$> ./expand_str " seulement          la c'est      plus dur " | cat -e
seulement   la   c'est   plus   dur$
$> ./expand_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./expand_str "" | cat -e
$
$>*/
#include <unistd.h>

char	*ft_trim(char *a)
{
	int j;

	while (a[0] <= 32 && a[0] >= 1)
	{
		j = 1;
		while (a[j] != '\0')
		{
			a[j - 1] = a[j];
			j++;
		}
		a[j - 1] = '\0';
	}
	return (a);
}

void	ft_print(char *a)
{
	int i;
	int space;

	space = 0;
	i = 0;
	while (a[i] != '\0')
	{
		if (a[i] <= 32 && a[i] >= 1)
		{
			space = 1;
		}
		else
		{
			if (space)
			{
				space = 0;
				write(1, "   ", 3);
			}.0
			write(1, &a[i], 1);
			space = 0;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2 && argv[1][0] != 0)
	{
		ft_print(ft_strim(argv[1]));
	}
	write(1,"\n", 1)
	return 0;
}