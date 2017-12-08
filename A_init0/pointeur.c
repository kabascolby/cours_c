#include <unistd.h>

void    ft_putaddr_fd(void **str, int fd)
{
    long int            div;
    char                temp;
    unsigned long int   n;

    n = (unsigned long int)str;
    div = 16;
    write(fd, "0x", 2);
    while (n / div >= 16)
        div *= 16;
    while (div > 0)
    {
        temp = '0' + n / div;
        if (temp > '9')
        {
            temp += 39;
            write(fd, &temp, 1);
        }
        else
            write(fd, &temp, 1);
        n %= div;
        div /= 16;
    }
}

void    ft_putaddr(void *str)
{
    ft_putaddr_fd(str, 1);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	while(*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void ft_putnbr(int n)
{
	if ((n >= 0) && (n < 10))
		ft_putchar(n + '0');
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n *(-1));
	}
	else if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void ft_ultimate_ft(int *********nbr)
{
   	*********nbr = 42;
}

int main(void)
{
	int 	n;
	int 	*ptr;
	int 	***ptr2;
	int 	***ptr3;
	int 	****ptr4;
	int 	*****ptr5;
	int 	******ptr6;
	int 	*******ptr7;
	int 	********ptr8;
	int 	*********ptr9;
	
	ptr = &n;
	ptr2 = &ptr;
	ptr3 = &ptr2;
	ptr4 = &ptr3;
	ptr5 = &ptr4;
	ptr6 = &ptr5;
	ptr7 = &ptr6;
	ptr8 = &ptr7;
	ptr9 = &ptr8;
	n = 56;

	ft_ultimate_ft(ptr);



	ft_putnbr(n);

	/*int tab[10];
	int tab2[10];
	int *ptr[2];
	ptr[0] = tab;
	ptr[1] = tab2;
	
	*(*ptr + 3) = 8;
	ft_putnbr(tab[3]);
	ft_putchar('\n');
//	ft_putnbr(tab[3]);*/
	A
	return (0);
}
