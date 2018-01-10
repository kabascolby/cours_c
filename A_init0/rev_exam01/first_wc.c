Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Écrire un programme qui prend une chaîne de caractères en paramètre, et qui
affiche le premier mot de cette chaîne, suivi d'un '\n'.

On appelle "mot" une portion de chaîne de caractères délimitée soit par des
espaces et/ou des tabulations, soit par le début / fin de la chaîne.

Si le nombre de paramètres transmis est différent de 1, ou s'il n'y a aucun mot
à afficher, le programme affiche '\n'.

Exemple:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>



#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
			i++;
		while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t'))
		{
			ft_putchar(av[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}