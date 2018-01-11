#include <unistd.h>
#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

int ft_strncmp(char *s1, char *s2, unsigned int n);
char 	*ft_strncat(char *dest , char *src, size_t nb);
char *ft_strncpy(char *dest, char *src, unsigned int n);
int ft_isdigit(int c);
unsigned int ft_strlcat(char *dest, char *src, unsigned int size);
//char *ft_strcapitalize(char *str);
int ft_str_is_numeric(char *str);
int main(void)
{
    char k[45] = "Lamine";
    char L[30];
    char Capital[70] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
    //ft_strncpy(Capital, ft_capitalize(), 30);
    printf("strncmp: %d\n",strncmp("lamine","labine",3));
    char src[50], dest[50];
    char M[16] = "Mohamed";

    printf("%s\n", ft_strncpy(L,"kaba", 8));
    printf("%d\n",ft_str_is_numeric("29345"));
    //printf("%s\n",ft_strcapitalize(Capital));
    printf("%s\n",ft_strncat(M, k, 7));
    printf("%d\n",ft_strlcat(M, k, 7));
    printf("%d\n",strlcat(M, k, 7));

   return (0);
}