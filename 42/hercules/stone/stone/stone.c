#include <stdio.h>

void stone(int height)
{
    int i;
    int j;
    space = 4;
    int n;
    n = 0;
    for(i=0;i< height;i++)
    {
	    for(j=0;j< space;j++)
	    {
		    printf(" ");
	    }
	    for(j=0;j<=i;j++)
	    {
		    printf("%d ",i%11);
	    }
		
	    printf("\n");
    }
}

void stone(int height);
int main(int ac, char **ag)
{
    if (ac != 2)
        return (1);
    stone(atoi(ag[1]));
    return (0);
}