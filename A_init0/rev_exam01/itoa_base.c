#include <stdlib.h>
#include <stdio.h>

char            *ft_itoa_base(int nbr, int base)
{
    char        *str;
    int         len;
    //int         nb;
   // int         i;
    char        tab[17] = "0123456789abcdef";
    long        k;
    k = nbr;
    k = (k < 0 ? -(k) : k);
      len = 0;
    while(k > 0)
    {
      k = k/base;
      len++;
    }
    len = (nbr < 0 ? len + 2 : len + 1);
    str = (char *)malloc(sizeof(char) * len);
    if(base == 10 && nbr < 0)
      str[0] = '-';
    str[--len] = '\0';
    k = nbr;
    k = (k < 0 ? -(k) : k);
    while (k > 0)
    {
        str[--len] = tab[k % base];
        k /= base;
    }
    return (str);
}

int main()
{
  printf("%s\n", ft_itoa_base(-2147483648, 10));
  printf("%s\n", ft_itoa_base(1546, 2));
}