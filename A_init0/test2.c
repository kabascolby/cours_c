#include <unistd.h>
#include <stdio.h>
//#include <string.h>

void ft_putstr(char *str)
{
  while(*str)
    write(1, &(*str++), 1);
}
void ft_putchar(char c)
{
  write(1, &c,1);
}

int ft_strlen(const char *s)
{
    int count;

    count = 0;
    while (s[count])
        count++;
    return(count);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		else if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

char *ft_strstr(const char *in, const char *str)
{
    char c;
    size_t len;
    char sc;

    c = *str++;
    if (!c)
        return (char *) in;	// Trivial empty string case

    len = ft_strlen(str);
    while (ft_strncmp(in, str, len) != 0)
    {        
        while (sc != c)
        {
            sc = *in++;
            if (!sc)
                return (char *) 0;
        }
    }

    return (char *) (in - 1);
}
void ft_putnbr(int n)
{
  if (n >= 0 && n <= 9)
    ft_putchar(n + '0');
  else if ( n < 0 )
  {
    ft_putchar('-');
    ft_putnbr(n * -1);
  }
  else if(n == -2147483648)
  {
    ft_putstr("-2147483648");
    return;
  }
  else
  {
    ft_putnbr(n / 10);
    ft_putnbr(n % 10);
  }
}



int main(void)
{
  int k;
  //ft_putstr("lamine kaba\n");
 // ft_putnbr(ft_strcmp("lamine", "akine"));
  const char haystack[] = "dtWikipedia est tout";
   const char needle[10] = "Wikipedia";
   char *ret;

   ret = ft_strstr(haystack, needle);

   printf("The substring is: %s\n", ret);
  
  return 0;
}