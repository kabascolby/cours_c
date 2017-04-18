#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("char : %d octets\n", sizeof(char));
    printf("int : %d octets\n", sizeof(int));
    printf("long : %d octets\n", sizeof(long));
    printf("double : %d octets\n", sizeof(double));
    printf("float : %d float\n", sizeof(float));
    return 0;
}