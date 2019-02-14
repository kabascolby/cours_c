#include "queue.h"

/*
**queue Init
*/

t_queue *init(t_queue *q)
{
	q = (t_queue *)malloc(sizeof(t_queue));
	q->front = NULL;
	q->front = NULL;
	return(q);
}

/*
**Enqueue
*/

void enqueue(t_queue *q, void *n)
{
	t_node *tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	tmp->data = n;
	tmp->next = NULL;
	//brandon
	/* if (!q->front)
		q->front = tmp;
	else
		q->rear->next = tmp;
	q->rear = tmp; */
	if(is_empty(q))
	{
		q->rear = tmp;
		q->front = tmp;
		return ;
	}
	q->rear->next = tmp;
	q->rear = tmp;
}

/*
**Dequeue
*/

void	*dequeue(t_queue *q)
{
	t_node *tmp;
	void *tp_data;

	tmp = q->front;
	if(is_empty(q))
		return(NULL);
	// // Brendan ---
	// q->front = q->front->next;
	// q->rear = !q->front ? NULL : q->rear;
	// free(tmp);
	// return (tp_data);
	if(q->front == q->rear)
	{
		q->front = NULL;
		q->rear = NULL;
	}
	else
		q->front = q->front->next;
	tp_data = tmp->data;
	free(tmp);
	return (tp_data);

}

/*
**front
*/

void	*peek(t_queue *q)
{
		return(q->front ? q->front->data : NULL);
}

/*
**is_empty
*/

int is_empty(t_queue *q)
{
	return(q->front == NULL);
}
