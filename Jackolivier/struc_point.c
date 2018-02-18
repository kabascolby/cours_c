#include <unistd.h>
#include <stdio.h>

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
    if((n >= 0) && (n < 10))
        ft_putchar(n + '0');
    else if(n < 0)
    {   
        ft_putchar('-');
        ft_putnbr(n * (-1));
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
 typedef struct _point
 {
     float x;
     float y;
 } point;

point point_create(float x, float y)
 {
     point P;
     P.x = x;
     P.y = y;
     return (P);
 }
 
 void point_display(point S)
 {
     printf("(%f ; %f)", S.x, S.y);
 }
 
 int main()
 {
     point A;
     A = point_create(2, 1);
     point_display(A);
     return (0);
 }