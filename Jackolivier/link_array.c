#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

typedef struct _intarray
{
    int                 *data;
    int                 len;
    struct _intarray    *next;
} intarray;

void intarray_debug(intarray *T)
{
    int i;
    i = 0;
    while(i < T->len)
        printf("%d ", T->data[i++]);
}

intarray intarray_create(int len)
{
    intarray T;
    T.len = len;
    T.data = malloc(sizeof (int) * len);
    return(T);
}
void intarray_destroy(intarray *A)
{
    free(A->data);
    A->data = NULL;
}
int intarray_get(intarray *T, int i)
{
    if(i < 0 || i > T->len)
    {
        printf("\nIndice Invalide");
        return (0);
    }
    return(T->data[i]);
}
void intarray_set(intarray *T, int i, int n)
{
    if (i < 0 || i > T->len)
        printf("\nIndice Invalide");
    else
        T->data[i] = n;
}
int intarray_length(intarray *T)
{
    int len;
    len = T->len;
    return (len);
}
void intarray_sort(intarray *A)
{
    int i;
    int j;
    int temp;

    j = 0;
    while(j < A->len)
    {
        i = 0;
        while(i < A->len)
        {
            if(A->data[i] > A->data[i + 1])
            {
                temp = A->data[i];
                A->data[i] = A->data[i + 1];
                A->data[i] = A->data[i + 1];
                A->data[i + 1] = temp;
            }
            i++;
        }
        j++;
    }
}

intarray *new_node(int len)
{
    intarray *new;

    new = (intarray *)malloc(sizeof(intarray));
    bzero(new, sizeof(intarray));
    new->len = len;
    new->data = (int *)malloc(sizeof(int) * len);
    bzero(new->data, sizeof(int) * len);
    return (new);
}

void    print_data(intarray *head, int node_num)
{
    intarray *tmp;
    int         i;

    tmp = head;
    i = 1;
    while (i != node_num)
    {
        tmp = tmp->next;
        ++i;
    }
    i = 0;
    while (i < tmp->len)
    {
        printf("%d, ", tmp->data[i]);
        ++i;
    }
    printf("\n");
}

int main(void)
{
    intarray T = intarray_create(20);
    intarray *a;

    a = new_node(10);
    a->next = new_node(20);
    a->next->next = new_node(3000);
    a->next->next->next = new_node(1);
    int i;

    i = 0;
    while(i++ < intarray_length(&T))
        T.data[i] = i * 5;
    intarray_debug(&T);
    intarray_set(&T, 3, 19);
    printf("\n%d",intarray_get(&T, 3));
    intarray_destroy(&T);
    print_data(a, 3);
}