#include <stdio.h>
#include <string.h>

int  ft_strcmp(char *s1, char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return((unsigned char)*s1 - (unsigned char)*s2);
}

int ft_strlen(const char *s)
{
    int count;

    count = 0;
    while (s[count])
        count++;
    return(count);
}

char *ft_strcat(char *dest, char *src)
{
    int i;

    i = 0;
    while (dest[i])
        i++;
    while(src[i])
    {
        dest[i++] = *src;
        src++;
    }
    dest[i] = '\0';
    return (dest);
}

char		*ft_strstr(char *str, char *to_find)
{
	char	*a;
	char	*b;

	b = to_find;
	if (!*b)
		return (str);
	while (*str)
	{
		if (*str == *b)
		{
			a = str;
			while (*a == *b || *b == '\0')
			{
				if (*b == '\0')
					return (str);
				a++;
				b++;
			}
			b = to_find;
		}
		str++;
	}
	return (0);
}

int main()
{
    // char string1[] = "Jerry";
    // char string2[] = "Ferry";
    // char string3[30];
    // char *string4 = "lamine";
    char str[] = "dtWikipedia est tout";
    char sub[] = "wikipedia";
    
    char *verite;

    verite = ft_strstr(str, sub);

    printf("%s\n", verite);
    printf("%s", verite);
    //char i, j;
    //i = ft_strupcase(string1);
    //j = ft_strupcase(string2
    //char k[] = "sAlut, comment;  e8t  u vas ? 42mots quarante-deux cinquante+et+un";
    //printf("%s", ft_strcapitalize(k));
    //printf("\n%s", ft_strlowcase(k));
    // printf("%s\n %d", ft_strcat(string3, ft_strcat(string2, string1)), ft_strlen(string1));
    // printf("%s", ft_strstr(str, sub));
    
   // printf("%d", ft_strcmp(string1, string2));
    return (0);
}
/*
#include <unistd.h>

int		ft_verif_char(char *str, char c, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_inter(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i])
	{
		if (ft_verif_char(s1, s1[i], i) == 1)
		{
			j = 0;
			while (s2[j])
			{
				if (s2[j] == s1[i])
				{
					write(1, &s1[i], 1);
					break ;
				}
				j++;
			}
		}
		i++;
	}
}
*/