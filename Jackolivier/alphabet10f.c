#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void alpha10()
{
    char kaba;
    
    int i;
    i = 0;
    kaba = 'A';
    while (kaba <= 'Z')
    {
        int i;
        i = 0;
        while (i < 11)
        {
            ft_putchar(kaba);
            i++;
        }
        ft_putchar('\n');
        kaba++;
    }
}

int main()
{
    alpha10();
    return(0);

}