#include <stdio.h>
#include <string.h>
#define Q_SIZE 10
typedef struct s_queue
{
	int data[Q_SIZE];
	uint16_t front;
	uint16_t rear;
}           t_queue;

//is_empty
int is_empty(t_queue *q)
{
	return(q->front == -1 && q->front == -1);
}

void print_queue(t_queue *q)
{
	int i;

	i = q->rear;
	if(is_empty(q))
		return ;
	i = q->front;
	while(i <= q->rear)
		printf("|% d", q->data[i++]);
	printf("\n");
}

//enqueue
void enqueue(t_queue *q, int n)
{
	if((q->rear + 1) % Q_SIZE == q->front)
		return ;
	if(is_empty(q))
	{
		q->rear = 0;
		q->front = 0;
	}
	else
		q->rear = (q->rear + 1) % Q_SIZE;
	q->data[q->rear] = n;
	print_queue(q);
}

//dequeue
int dequeue(t_queue *q)
{
	if(is_empty(q))
		return (0);
	if(q->front == q->rear)
	{
		q->rear = -1;
		q->front = -1;
	}
	else
		q->front = (q->front + 1) % Q_SIZE;
	return(0);
}

//front

int main(void)
{
	t_queue q;
	q.front = -1;
	q.rear = -1;
	
	enqueue(&q, 5);
	enqueue(&q, 15);
	enqueue(&q, 20);
	enqueue(&q, -8);
	enqueue(&q, 28);
	dequeue(&q);
	print_queue(&q);
	return(0);
}