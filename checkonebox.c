#include "../inc/bsq.h"

int ft_checkempty(char *str)
{
    int i;
    int j;
    char empty;

    i = 0;
    j = 0;
    empty = empty_char(str);

    while(str[i] != '\n' )
        i++;
    str = &str[i + 1];
    while (str[j] != 0)
    {
        if( str[j] == empty)
            return(1);
        j++;
    }
    return(0);        
}

int ft_linebreak(char *str)
{
    int i;
    int n;
    int j;

    i = 0;
    j = 0
    n = ft_atoi(str);

    while (str[i] != '\0')
    {
        if(str[i] == '\n')
            j++;
        i++;
    }
    if(j == n + 1)
        return(1);
    return(0);
}

int ft_checkcontain(char *str)
{
    int i;
    char empty;
    char obst;

    i = 0;
    empty = empty_char(str);
    obst = obstacle(str);
    
    while(str[i] != '\0')
    {
        if(srt[i] != empty && str[i] != obst && str[i] != '\n')
            return(0);
        i++;
    } 
    return(1);
}