/*
Assignment name  : search_and_replace
Expected files   : search_and_replace.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Écrire un programme search_and_replace qui prend 3 arguments, le premier est
une chaîne dans laquelle on veut remplacer une lettre (2ème argument) par une
autre (3ème argument).

Si le nombre d'arguments n'est pas 3, affiche juste un newline.

Si le deuxième argument n'est pas contenu dans la chaîne, alors le programme ne
change rien à la chaîne et l'affiche telle quelle suivie d'un newline.

Exemples:
$>./search_and_replace "Papache est un sabre" "a" "o"
Popoche est un sobre
$>./search_and_replace "zaz" "art" "zul" | cat -e
$
$>./search_and_replace "zaz" "r" "u" | cat -e
zaz$
$>./search_and_replace "jacob" "a" "b" "c" "e" | cat -e
$
$>./search_and_replace "ZoZ eT Dovid oiME le METol." "o" "a" | cat -e
ZaZ eT David aiME le METal.$
$>./search_and_replace "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e" | cat -e
eNcOre Un ExEmPle Pas Facile a Ecrire $
*/

#include <unistd.h>

void ft_putchar (char c)
{
	write(1, &c, 1);
}

void ft_replace(char *d, char b, char a)
{
	int i;

	i = 0;
	while (d[i] != 0)
	{
		if( d[i] == b)
			ft_putchar(b);
		if (d[i] == a)
			ft_putchar(d[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		if(!(argv[3][1] != 0 || argv[2][1] != 0))
			ft_replace(argv[1], argv[2][0], arg[3][0]);
	}
	ft_putchar('\n');
	return(0);
}