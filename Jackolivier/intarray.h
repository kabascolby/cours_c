#ifndef _INTARRAY_H
#define _INTARRAY_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct _intarray
{
    int* data;
    int len;
} intarray;

void intarray_debug(intarray *T);
void intarray_create(intarray *T, int len);
void intarray_destroy(intarray *A);
int intarray_get(intarray *T, int i);
void intarray_set(intarray *T, int i, int n);
int intarray_length(intarray *T);
int intarray_length(intarray *T);
void intarray_concat(intarray *A, intarray *B, intarray **c);
int intarray_min(intarray *M);
#endif