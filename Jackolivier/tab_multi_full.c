#include<stdio.h>
#include<stdlib.h>


/*int main(int argc, char *argv[])
{
    int i, j ;
    for (i = 0; i < 11; i++)
    {
        for (j = 0; j < 11; j++)
        { 
            if ( i* j < 10)
            {
                printf("%d  ", i*j);
            }
            else if( i* j < 100)
            {
                printf("%d ", i*j);
            }
            else
            printf("%d", i * j);
        }
    printf("\n");
    }
    return EXIT_SUCCESS;
}*/

// pour voir les lignes i et les colones j

int main(int argc, char *argv[])
{
    int i, j ;
    for (i = 1; i < 5; i++)
    {
        for (j = 1; j < 5; j++)
        { 
            
            printf("(%d, %d) | ", i, j);
        }
    printf("\n");
    }
    return EXIT_SUCCESS;
}