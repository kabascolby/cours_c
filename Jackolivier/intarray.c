#include <stdlib.h>
#include <stdio.h>

typedef struct _intarray
{
    int* data;
    int len;
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

int main(void)
{
    intarray T = intarray_create(20);

    int i;

    i = 0;
    while(i++ < intarray_length(&T))
        T.data[i] = i * 5;
    intarray_debug(&T);
    intarray_set(&T, 3, 19);
    printf("\n%d",intarray_get(&T, 3));
    intarray_destroy(&T);
}