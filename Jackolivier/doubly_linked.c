#include "doubly_linked.h"

t_node *create_node(int x)
{ 
    t_node *temp;
    temp = (t_node *)malloc(sizeof(t_node));
    temp->data = x;
    temp->prev = NULL;
    temp->next = NULL;
    return (temp);
}

void insert_at_head(int x, t_node **head)
{
    t_node *temp;

    temp = create_node(x);
    if(!*head)
    {
        *head = temp;
        return;
    }
    (*head)->prev = temp;
    temp->next = *head;
    *head = temp;
}

void print_link(t_node *head)
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

void reverse_link(t_node *head)
{
    t_node *temp;

    temp = head;
    while(temp->next)
        temp = temp->next;
    while(temp)
    {
        printf("% d", temp->data);
        temp = temp->prev;
    }
}

int main()
{
    t_node *head;

    head = NULL;    
    insert_at_head(5, &head);
    insert_at_head(78, &head);
    insert_at_head(1000, &head);
    insert_at_head(10, &head);
    print_link(head);
    reverse_link(head);
    
    return (0);
}