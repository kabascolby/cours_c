#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int k;
    k= 26 ;
    int* p;
    p = &k;

    printf("%d\n", *p);             //exemple pour les int
    printf("%d\n", k);
    *p = 20000000;
    printf("%d\n",k);
    printf("%d", *p);
     return(0);
}

/*{
    char lam;
    lam = 'k';
    char* kab;
    kab = &lam;  
                                               //exemple sur les carracteres;
    printf("%c\n",*kab);
    printf("%c\n",lam);
    *kab = 'Z';
    printf("%c %c\n", lam, *kab);
    return(0);
}*/