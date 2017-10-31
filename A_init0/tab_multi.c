#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int ft_putstr(char *str)
{
	while(*str)
	{
		ft_putchar(*str);
		str++;
	}
	return 0;
}

void ft_putnbr(int n)
{
	if ((n >= 0) && (n < 10))
			ft_putchar(n + '0');
	else if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * (-1));
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int main()
	{
        int i, j;
        i = 1;
        
        while ( i < 11)
        {
            j = 1;
            while(j < 11)
            {
                ft_putnbr(j * i);
                if( (i * j) < 10)
                    ft_putstr("  ");
                else if( (i * j) < 100)
                    ft_putstr(" ");
                j++;
            }
            ft_putchar('\n');
            i++;
        }
        
		return 0;
	}