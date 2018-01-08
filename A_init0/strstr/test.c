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

char *ft_strstr(char *str, char *to_find)
{
    int i;
    int j;
    int k;
    char *str2;

    if (ft_strlen(str) >= ft_strlen(to_find))
    {
       str2 = str;
           i = 0;
            k = 0;
          j = 0;
          l = 0;
        while(str[i])
        {
           while(tofind[j] == str[i])
            {
                 if(tofind[j] == str[i])
                    k++;
                j++;
            }
            l = j;          
            i++;
            
        }
    }  
    
    if(j != ft_strlen(to_find))
        return("(nulll)");
    else
        return(str);
}

int main()
{
    // char string1[] = "Jerry";
    // char string2[] = "Ferry";
    // char string3[30];
    // char *string4 = "lamine";
    char str[] = "Wikipedia est tout";
    char sub[] = "fWikipedia";
    char *verite;

    verite = ft_strstr(str, sub);

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