#include "linked_list.h"

void ft_insert(t_node **l_head, int n)
{
    t_node *temp;
    temp = (t_node *)malloc(sizeof(t_node));
    temp->i = n;
    temp->next = *l_head;
    *l_head = temp;
}

void ft_print(t_node **l_head)
{
    t_node *temp;
    temp = *l_head;

    while(temp != NULL)
    {
        printf("%d ", temp->i);
        temp = temp->next;
    }
}
void ft_add(t_node **head, int n, int pos)
{
    int j;
    j = 0;
    t_node *temp1;
    t_node *temp2;
    if(*head == NULL || pos == 1)
    {
        ft_insert(head, n);
        return ;
    }
    temp1 = (t_node *)malloc(sizeof(t_node));
    temp1->i = n;
    temp1->next = 0;
    temp2 = *head;
    while(j++ < pos - 2)
        temp2 = temp2->next;
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void ft_del(t_node **l_head, int pos)
{
    t_node *temp1;
    t_node *temp2;
    
    temp1 = *l_head;
    if(pos == 1)
    {
        
        *l_head = temp1->

    }
}
int main()
{
    int n;
    int i;
    int j;
    
    i = 0;
    t_node *head;
    head = NULL;
    ft_add(&head, 9, 1);
    ft_insert(&head, 5);
    ft_insert(&head, 8);
    ft_add(&head, 7, 4);
    ft_del(&head, 1);
    
    ft_print(&head);
    printf("\n");
    return(0);
}