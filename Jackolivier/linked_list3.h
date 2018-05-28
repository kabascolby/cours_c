#ifndef _LINKED_LIST_H_
# define _LINKED_LIST_H_
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int data;
	struct s_node *next;
}				t_node;
# endif