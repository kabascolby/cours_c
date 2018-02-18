#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _intarray
{
    int* data;
    int len;
} intarray;

void intarray_debug(intarray *T)
{
    //int i;
    //i = 0;
    for (int i = 0; i < T->len; i++)
        printf("%d ", T->data[i]);
}

void intarray_create(intarray *New, int len)
{
    puts("here\n");
   
    New->len = len;
    New->data = (int*)malloc(sizeof (int) * len);
    bzero((New)->data, sizeof(int) * New->len);
   puts("created\n");
}
void intarray_destroy(intarray *A)
{
//    free(A->data);
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

int intarray_min(intarray *M)
{
    int m;
    int i;

    i = 1;
    m = M->data[0];
    while (i < intarray_length(M))
    {
        if (m > intarray_get(M, i))
            m = M->data[i];
        i++;
    }
    return (m);
}

int main(void)
{
    intarray *T;
    //bzero(T, sizeof(intarray));
    //T = (intarray*)malloc(sizeof(intarray));
    intarray_create(T, 20);

   intarray *N;
  N = (intarray*)malloc(sizeof(intarray));
  intarray_create(N, 5);
    //bzero(N.data, N.len);
    

  
    int i = 0;
    while(i++ < T->len)
      T->data[i] = i * 5;
  //  i = 0;
  //  while(i++ < N->len)
      //  N->data[i] = i * 5;
    
   intarray_debug(T);
  //intarray_set(T, 0, 19);
  // printf("\n%d",intarray_get(T, 3));
  // printf("\n%d\n",intarray_min(T));
   //intarray_destroy(T);
  // intarray_debug(N);
}