#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
    float l;
    float L;
    printf ("Saisissez la longeur ");
    scanf ("%f", &L);
    while ( L < 0)
    {
        printf ("saisissez un nombre strictement positif ");
        scanf("%f", &L);
    
    }

    printf("Saisissez la largeur ");
    scanf("%f", &l);
    while ( l < 0)
    {
        printf ("saisissez un nombre strictement positif ");
        scanf("%f", &l);
    }

    printf("le perimetre est %f m\n", 2*l+2*L);

    printf("la surface est de %f m2\n", L*l);
    return(0);
}
