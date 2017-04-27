#include "../inc/bsq.h"

int ft_len(char *str)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (str[i] != '\n')
        i++;

    while(str[j] != '\n')
        j++;
    return(j);
}
char *ft_adress(char *str)
{
    int i;
    int j;

    i = 0;
    j = 0;

    while(str[i] =! 0)
        i++;
    str = &str[i + 1];
    
    while(str[j] =! 0)
        j = j++;
    str = &str[j + 1];

    return(str);
}

int ft_strlencp(char *str)
{
    int l;
    int i;
    int len;
    int n;

    n = ft_atoi(str);
    
    len = ft_len(str);
    str = ft_adress(str);
    i = 0;
    l = 0;
    while ( i <= n - 2)
    {
        while(str[l] != '\n')
            l++;
        if(l != j)
            return(0);
        i++;
        str = &str[l + 1];
        l = 0;
        
    }
    return(1);
}

