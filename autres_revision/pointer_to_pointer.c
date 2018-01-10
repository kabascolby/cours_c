#include <stdio.h>
int main()
{
    int x;
    x = 5;
    int* p;
    p = &x;
    *p = 10;

    int** q;
    q = &p;
    int*** r;
    r = &q;

    printf("valeur de x %d\n", x);
    printf("%d\n", *p);
    printf("%d\n", p);
    printf("%d\n", *q);
    printf("%d\n", *(*q));
    printf("%d\n", *(*r));
    printf("%d\n", *(*(*r)));    
}