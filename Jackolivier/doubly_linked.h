#ifndef DOUBLY_LINKED
#define DOUBLY_LINKED
#include <stdio.h>
#include <stdlib.h>

typedef struct  s_node
{
    int data;
    struct s_node *next;
    struct s_node *prev;
}               t_node;

#endif