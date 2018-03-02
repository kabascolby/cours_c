#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct _intarray
{
    int i;
    struct _intarray *next;
} intarray;
void insert(intarray **head, int n);
void Print(intarray **head);
#endif