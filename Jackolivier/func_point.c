#include <stdio.h>
# define ABS(x) ((x < 0) ? -(x) : (x))

int ft_sum(int a, int b)
{
    return(a + b);
}
void af(void)
{
    printf("lamine kaba\n");
}
void ft_aff(char *s)
{
    printf("hello %s\n", s);
}

void b(void (*ptr)(void))
{
    ptr();
}

int sumptr(int (*a)(int, int))
{
    return(a(5, 8));
}

int compare(int a, int b)
{
    return(a > b ? 1 : -1);
}
int abscmp(int a, int b)
{
    return(ABS(a) > ABS(b) ? 1 : -1);
}
void ft_sort(int *t, int len, int (*cmp)(int a, int b))
{
    int i;
    int j;
    int temp;
    i = -1;
    temp = 0;
    while(++i < len)
    {
        j = -1;
        while(++j < len - 1)
        {
            if((*cmp)(t[j], t[j + 1]) > 0)
            {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
}

int (*ptr_return(int n))(int, int)
{
    printf("Got parameter %d", n);
    int (*p)(int, int);
    p = ft_sum;
    return(p);
}
// addition
void addition(int a, int b)
{
    printf("addition = %d\n", a + b);
}
//soustraction
void soustraction(int a, int b)
{
    printf("soustraction = %d\n", a - b);
}
//multiplication
void multiplication(int a, int b)
{
    printf("multiplication = %d\n", a * b);
}
//division
void division(int a, int b)   
{
    if(a)
        printf("division = %d\n", a / b);
}

int main(void)
{
    int t[6] = {-78, 1, 8, -9, 10, 3};
    int i;
    int (*p)(int, int);
    void (*ptr)(char *c);
    void (*ptr2)(void);
    int (*cmp)(int a, int b);
    void (*ft_op[])(int a , int b) = {addition, soustraction, multiplication, division};
    p = ft_sum;
    ft_op[2](3, 6);
    printf("%d\n", p(5, 5));
    printf("sumptr = %d\n", sumptr(p));
    printf("ptr_return = %d\n", ptr_return(5)(7, 18));
    ptr = ft_aff;
    ptr("lamine");
    ptr2 = &af;
    b(ptr2);
    ptr2();
    cmp = abscmp;
    ft_sort(t, 6, cmp);
    for(i = 0; i < 6; i++)
        printf("| %d", t[i]);
    return 0;
}