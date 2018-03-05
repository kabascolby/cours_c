#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
    int i;
    struct s_node *next;
}               t_node;

#endif