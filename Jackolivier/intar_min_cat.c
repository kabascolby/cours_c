#include "intarray.h"

void intarray_debug(intarray *T)
{
    int i;
    i = 0;
    while(i < T->len)
        printf("%d ", T->data[i++]);
}

void intarray_create(intarray *T, int len)
{ 
    T->len = len;
    T->data = malloc(sizeof (int) * len);
    T->data[0] = 7;   
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
        while(i + j < A->len - 1)
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
void intarray_concat(intarray *A, intarray *B, intarray **c)
{
    
    int i;
    int j;
    i = -1;
   (*c) = (intarray *)malloc(sizeof(intarray));
   bzero((*c), sizeof(intarray));
   (*c)->len = A->len + B->len;
   (*c)->data = (int *)malloc(sizeof(int) * (*c)->len);
    bzero((intarray *)(*c)->data, sizeof(int) * (*c)->len);
    
    while(++i < intarray_length(A))
        intarray_set((*c), i, A->data[i]);
     j = -1;
    while(++j < B->len)
        intarray_set((*c), i++, B->data[j]);
}

int intarray_min(intarray *M)
{
    int m;
    int i;

    i = 0;
    m = intarray_get(M, 0);
    while (++i < intarray_length(M))
    {
        if (m > intarray_get(M, i))
            m = M->data[i];
    }
    return (m);
}

int main(void)
{
    intarray T;
    bzero(&T, sizeof(intarray));
    intarray_create(&T, 10);
    
    intarray N;
    intarray_create(&N, 5);
    bzero(N.data, sizeof(int) * N.len);
    int i;

    i = 0;
    while(i++ < T.len)
        T.data[i] = i * 5;
    intarray_debug(&T);
    intarray_set(&T, 0, 19);
    printf("\n%d",intarray_get(&T, 3));
    printf("\nLe minimun est: %d\n",intarray_min(&T));
    intarray_debug(&N);
    printf("\n");
    intarray *c;
    intarray_concat(&T, &N, &c);
    intarray_debug(c);
    printf("\n%d\n",intarray_min(c));
    printf("\n");
    printf("\n%d",intarray_get(c, 3));
    intarray_destroy(&T);
    intarray_destroy(&N);
    intarray_destroy(c);
}