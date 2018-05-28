// push
// pop
//top;
//is_empty;

#include <stdio.h>
#define MAX 10

int is_empty(int top)
{
  return(top == -1);  
}

void print_stack(int top, int *tab)
{
    int i;
    i = -1;
    if(is_empty(top))
    {
        printf("stack is empty");
        return ;
    }
    while(++i <= top)
        printf("% d", tab[i]);
    printf("\n");
}

void push(int n, int *top, int *tab)
{
    if(*top == MAX - 1)
    {
        printf("the array is full");
        return ;
    }
    *top = *top + 1;
    tab[*top] = n;
    print_stack(*top, tab); 
}

void print_top(int top, int *tab)
{
    printf("%d\n", tab[top]);
}

void pop(int *top, int *tab)
{
    *top = *top - 1;
    print_stack(*top, tab);
}

int main()
{
    int tab[MAX];
    int top = -1;
    push(20, &top, tab);
    push(250, &top, tab);
    push(40, &top, tab);
    push(70, &top, tab);
    print_top(top, tab);
    push(320, &top, tab);
    push(200, &top, tab);
    push(120, &top, tab);
    print_top(top, tab);
    pop(&top, tab);
    return (0);
}