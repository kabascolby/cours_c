#ifndef QUEUE_H
# define QUEUE_H
# include <stdio.h>
# include <stdlib.h>


typedef struct s_node
{
	void *data;
	struct s_node *next;
}				t_node;

typedef struct s_queue
{
	t_node		*front;
	t_node		*rear;
}				t_queue;

t_queue	*init(t_queue *q);
void	enqueue(t_queue *q, void *n);
t_node	*dequeue(t_queue *q);
void	*peek(t_queue *q)
int		is_empty(t_queue *q);
#endif