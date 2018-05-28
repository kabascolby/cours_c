#include "linked_list3.h"

void add_node(int n, t_node **head)
{
	t_node *temp;
	temp = (t_node *)malloc(sizeof(t_node));
	temp->next = *head;
	temp->data = n;
	*head = temp;
}

void print_node(t_node *head)
{
	t_node *temp;
	temp = head;
	while(temp)
	{
		printf("% d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void reverse_print(t_node *head)
{

	if(head == NULL)
	{
		printf("\n");
		return ;
	}
	reverse_print(head->next);	
	printf("% d", head->data);
}
void insert_node(int n, int pos, t_node **head)
{
	t_node *temp;
	t_node *temp1;
	int i;

	if(pos == 1)
	{
		add_node(n, head);
		return;
	}
	temp = (t_node *)malloc(sizeof(t_node));
	temp->next = NULL;
	temp->data = n;
	temp1 = *head;
	i = 0;
	while (i++ < pos - 2)
		temp1 = temp1->next;
	temp->next = temp1->next;
	temp1->next = temp;
}

void delete_node(int pos, t_node **head)
{
	t_node *temp;
	t_node *temp1;
	int i;

	temp = *head;
	i = 0;
	if(pos == 1)
	{
		*head = temp->next;
		free(temp);
		return ;
	}
	while(i++ < pos - 2)
		temp = temp->next;
	temp1 = temp->next;
	temp->next = temp1->next;
	free(temp1);
}

void iterrative_link(t_node **head)
{
	t_node *prev;
	t_node *cur;
	t_node *next;

	prev = NULL;
	cur = *head;
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*head = prev;
}
void print_recursive(t_node *head)
{
	if(!head)
	{
		printf("\n");
		return ;
	}
	printf("% d", head->data);
	print_recursive(head->next);
}
void recursive_link(t_node **H)
{
	t_node *temp;
	temp = *H;
	if(temp->next == NULL)
		return;
	recursive_link(&temp->next);
	temp->next->next = *H;
	temp->next = NULL;
}

int main()
{
	t_node *head;
	head = NULL;
	add_node(8, &head);
	add_node(18, &head);
	add_node(14, &head);
	add_node(11, &head);
	print_node(head);
	//reverse_print(head);
	insert_node(223, 5, &head);
	reverse_print(head);
	delete_node(1, &head);
	reverse_print(head);
	printf("\n");
	print_recursive(head);
	iterrative_link(&head);
	print_recursive(head);
	recursive_link(&head);
	print_node(head);	
	return (0);
}