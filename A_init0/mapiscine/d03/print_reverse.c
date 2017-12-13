#include <unistd.h>
#include <stdio.h>

/*reecriture de la fonction apres comprehwnsion totale*/
int ft_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}

int ft_strlen(char *str)
{
	int size;
	
	size = 0;
	while(str[size])
		size++;
	return (size);
}
char *ft_strrev(char *str)
{
	char 	tmp;
	int 	i;
	int 	size;

	i = 0;
	size = ft_strlen(str);
	while( i < size)
	{
		tmp = str[i];
		str[i] = str[size - 1];
		str[size - 1] = tmp;
		size --;
		i++;
	}
	return (str);
}
/*
char		*ft_strrev(char *str)
{
	int		i;
	int		l;
	int	t;

	l = 0;
	while (str[l] != '\0')
		l++;
	i = -1;
	while (++i < --l)
	{
		t = str[i];
		str[i] = str[l];
		str[l] = t;
	}
	return (str);
}*/

int main (int argc, char **argv)
{
	if (argc == 2)
		printf("%s\n", ft_strrev(argv[1]));
	else
		//ft_putchar('\n');
	return (0);
} 

/*int		main(void)
{
	char str1[] = "Hello";
	char *str2 = "Hello";

	str[0] = 'A';
	str[1] = 'b';

	str1[0] = 'A';
	str2[0] = 'A';
	

	str2 = str1;
	str1 = str2;

	str = "Helo";
	str = "Ali";
	str[0] = ''
	char str[] = "lamine";

	//printf("%s \n", str);

	//ret = ft_strrev(str)
	
	//printf("%s \n", str);
	printf("%s \n", ft_strrev(str));
	return (0);
}*/
