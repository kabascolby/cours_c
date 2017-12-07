#include <unistd.h>
#include <stdio.h>

int ft_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}

char *ft_strrev(char *str)
{
    int i;
	int size;
	char tmp;

    i = 0;
	size = 0;
	while (str[size])
        size++;
	printf("1\n");
	while(i < size)
	{
		tmp = str[i];
		str[i] = str[size - 1];
		str[size - 1] = tmp;
		size--;
		i++;
	}
	return (str);
}

/* int main (int argc, char **argv)
{
	if (argc != 2)
		ft_putchar('\n');
	else
	{
		ft_strrev(argv[1]);
		ft_putchar('\n');
	}
	return (0);
} */

int		main(void)
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
}
