#include <stdio.h>

/*int match(char *s1, char *s2);

int main()
{
    return 0;
}*/

int nmatch(char *s1, char *s2)
{
    if(*s2 == '*' && *s1 != '\0')
        return (nmatch(s1 + 1, s2) || nmatch(s1, s2 + 1));
    if(*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
        return (nmatch(s1 + 1, s2 + 1 ));
    if(*s1 == *s2 && *s1 == '\0' && *s2 == '\0')
        return (1);
    if(*s2 == '*' && *s1 == '\0')
        return (match(s1, s2 + 1));
    return (0);
}
 
 
int main()
{
    char *s1;
    char *s2;
    s1 = "hello";
    s2 = "h*l*";
    printf("%d\n", match(s1, s2));
}