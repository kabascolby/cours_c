#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	c;
	int		space;

	i = 0;
	while (str[i] != '\0')
	{
		space = 1;
		if (i == 0)
        {
			c = ';';
             printf("0 %d %c\n", i, str[i]);
        }
		else
        {
			c = str[i - 1];
            printf("1 %d %c\n", i, str[i]);
        }
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        {
			space = 0;
            printf("2 %d %c\n", i, str[i]);
        }
		if (c >= 48 && c <= 57)
        {
			space = 0;
            printf("3 %d %c\n", i, str[i]);
        }
		if (space == 1 && str[i] >= 97 && str[i] <= 122)
		{
            str[i] = str[i] - 32;
         printf("4 %d %c\n", i, str[i]);
        }
		if (space == 0 && str[i] >= 65 && str[i] <= 90)
		{
            str[i] = str[i] + 32;
            printf("5 %d %c\n", i, str[i]);
        }
		i++;
	}
	return (str);
}
int main()
{
    //char string1[] = "Jerry";
    //char string2[] = "Ferry";
    //char i, j;
    //i = ft_strupcase(string1);
    //j = ft_strupcase(string2)
    char k[] = ";sAlut, comment;  8tu vas ? 42mots quarante-deux cinquante+et+un";
    printf("%s", ft_strcapitalize(k));
    //printf("\n%s", ft_strlowcase(k));
    return (0);
}
