#include <unistd.h>

char  *ft_lowercase(char *str)
{
    int i;
    i = 0;
    while(str[i])
     {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
     }
      return(str);
}

void ft_capitalize(char *str)
{
    int i;
    char c;
    int first;

    first = 1;
    i = 0;
    ft_lowercase(str);
    while (str[i])
    {
        c = str[i];
        if(c >= 'a' && c <= 'z')
        {
            if(first == 1)
            c -= 32;
            first = 0;
        }
        else if(c >= '0' && c <= '9')
            first = 0;
        else
            first = 1;
        write(1, &c, 1);
        i++;
    }
}
int main(int argc, char **argv)
{
    if(argc > 1)
        ft_capitalize(argv[1]);
    write(1, "\n", 1);
    return(0);
}