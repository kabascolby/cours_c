#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	return(*str++ ? ft_strlen(str) + 1 : 0);
}
char	*ft_concat_params(int argc, char **argv)
{
	char *str;
	int i;
	int len;
	int j;
	int k;
	//int len2;
	if (argc < 2 && !argv)
		return (NULL);
	len = 0;
	i = 0;
	while(++i < argc)
		len += ft_strlen(argv[i]);
	printf("len: %i\n", len);
	if(!(str = (char *)malloc(sizeof(char) * len + argc + 1)))
				return (NULL);
	len = 0;
	i = 0;
	j = 0;

	while(++i < argc)
	{
		k = 0;
		//len2 = ft_strlen(argv[i]);
		while(argv[i][k])
		{
			str[j] = argv[i][k];
			k++;
			j++;
		}
		str[j++]  = '\n';
		//len += len2;
	}
	str[j] = '\0';

	return (str);
}	
		
int main(int argc, char **argv)
{
    printf("%s", ft_concat_params(argc, argv));
    return 0;
}
